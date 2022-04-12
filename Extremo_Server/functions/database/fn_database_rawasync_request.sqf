/*
    File: fn_database_rawasync_request.sqf
    Author: Ni1kko
    Description: Commits an asynchronous call to ExtDB3
    Parameters:
        0: STRING (Query to be ran)
        1: INTEGER (1 = ASYNC + not return for update/insert, 2 = ASYNC + return for query's)
        3: BOOL (True to return a single array, false to return multiple entries)
*/

params [ 
    ["_queryStmt","",[""]],
    ["_mode",0,[0]],
    ["_returnSingle",false,[false]] 
];

private _return = [];

if((serverNameSpace getvariable ["extremo_var_rcon_RestartMode", 0]) > 0 OR (serverNameSpace getvariable ["extdb_var_database_error", false]) OR isNil {serverNameSpace getvariable "extdb_var_database_key"})exitWith{_return};

with serverNamespace do 
{ 
    //--- Send querry to DLL (returns: sessionID for given key)
    private _keyResponse = parseSimpleArray("extDB3" callExtension format ["%1:%2:%3",_mode,call extdb_var_database_key,_queryStmt]);

    switch _mode do 
    {
        //--- Fire and forget (no return, used for inserting/deleting records)
        case 1: {true};
        //--- Return for query (returns, array of record(s))
        default
        { 
            //--- Parse response
            if(!(parseSimpleArray _keyResponse) params [
                ["_responseCode",0,[0]],
                ["_sessionID",0,[0]]
            ])exitWith{
                "DLL Response error" call Extremo_fnc_database_systemlog;
            }; 

            private _queryResult = "extDB3" callExtension format ["4:%1", _sessionID];
            private _msgReceived = {_this isEqualTo "[3]"};
            private _multiPart = _queryResult isEqualTo "[5]";

            //--- Make sure the message is received
            if (_queryResult call _msgReceived) then 
            {
                while {_queryResult call _msgReceived} do {
                    _queryResult = "extDB3" callExtension format ["4:%1", _sessionID];
                };
            };

            //--- extDB3 returned that result is Multi-Part Message
            if _multiPart then 
            {
                _queryResult = "";

                //--- Loop until we get the final message
                while {_multiPart} do
                {
                    private _pipe = "extDB3" callExtension format ["5:%1", _sessionID];
                        
                    if(_pipe isNotEqualTo "")then{
                        _queryResult = _queryResult + _pipe;
                    }else{
                        _multiPart = false;
                    };
                };
            };

            (call compile _queryResult) params [
                ["_queryResponse",0,[0]],
                ["_queryData",""],
            ];
 
            if (_queryResponse isEqualTo 0) exitWith {format ["extDB3: Protocol Error: %1", _queryData] call Extremo_fnc_database_systemlog; []};
            _return = _queryData;
        }; 
    };
};

//--- Return single array
if (count _return >= 1 AND _returnSingle) then {
    _return = [_return] call BIS_fnc_arrayShift;
};

_return;