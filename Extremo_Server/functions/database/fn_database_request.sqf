/*
	## EXTREMO
	## Nikko Renolds
*/
 
params [
	["_mode",""],
	["_table",""], 
	["_params",[]],
	["_single",false]
];

private _res = ["DB:Task-failure", false];

with serverNamespace do
{
	if(extremo_var_rcon_RestartMode > 0 OR extdb_var_database_error)exitWith{_res};

	private _qstring = "";

	//--- Build Query
	switch (_mode) do {
		case "CREATE": 
		{ 
			private _columns = [];
			private _values = [];
			{
				_columns pushBack (_x#0);
				_values pushBack (_x#1);
			} forEach _params; 
			_qstring = ("1:" + str(call extdb_var_database_key) + ":INSERT INTO " + _table + " (" + (_columns joinString ",") + ")VALUES(" + (_values joinString ",") + ")");
			_res = ["DB:Create:Task-completed",true];
			//"1:464:INSERT INTO players (name,aliases,playerid,cash,safe)VALUES(Nikko2,""[``test``]"",76561198276956558,0,10000)"
		};
		case "READ": 
		{
			private _columns = (_params#0) joinString ",";
			private _clauses = [];{_clauses pushBack (_x joinString "=")} forEach (_params#1);
			_qstring = ("2:" + str(call extdb_var_database_key) + ":SELECT " + _columns + " FROM " + _table);
			if(count _clauses > 0)then{_qstring = _qstring + (" WHERE " + (_clauses joinString " AND "));};
			//"2:464:SELECT name,cash,safe FROM players WHERE playerid=76561199109931625"
		};
		case "UPDATE": 
		{ 
			private _columns = [];{_columns pushBack (_x joinString "=")} forEach (_params#0);
			private _clauses = [];{_clauses pushBack (_x joinString "=")} forEach (_params#1);
			_qstring = ("1:" + str(call extdb_var_database_key) + ":UPDATE " + _table + " SET " + (_columns joinString ","));
			if(count _clauses > 0)then{_qstring = _qstring + (" WHERE " + (_clauses joinString " AND "));};
			_res = ["DB:Update:Task-completed",true];
			//"1:464:UPDATE players SET cash=500,safe=99999 WHERE playerid=76561199109931625"
		};
		case "DELETE": 
		{  
			private _clauses = [];{_clauses pushBack (_x joinString "=")} forEach (_params#0);
			_qstring = ("1:" + str(call extdb_var_database_key) + ":DELETE FROM " + _table);
			if(count _clauses > 0)then{_qstring = _qstring + (" WHERE " + (_clauses joinString " AND "));};
			_res = ["DB:Delete:Task-completed",true];
			//"1:464:DELETE FROM vehicles WHERE id=1"
		};
		case "CALL": 
		{  
			_qstring = ("1:" + str(call extdb_var_database_key) + ":CALL " + _table);
			_res = ["DB:Call:Task-completed",true];
			//"1:464:CALL deleteOldGangs"
		};
		default
		{
			_qstring = ("2:" + str(call extdb_var_database_key) + ":" + _mode);
		};
	};
 
    //--- Send querry to DLL (returns: sessionID for given key)
    private _keyResponse = ("extDB3" callExtension _qstring);
 
	//--- No Database Return... Task Completed
	if(_mode in ["UPDATE","CREATE","DELETE","CALL"])exitWith{_res};

	//--- Parse response
	if(not((parseSimpleArray _keyResponse) params [
		["_responseCode",0,[0]],
		["_sessionID","0",[""]]
	]))exitWith{
		"DLL KeyResponse parsing error" call Extremo_fnc_database_systemlog;
	}; 
	
	//--- Get query result
	private _receivingMsg = true;
	while{_receivingMsg} do
	{ 
		private _queryResult = "extDB3" callExtension ("4:" + _sessionID);
		private _msgReceived = _queryResult isEqualTo "[3]";
		private _multiPart = _queryResult isEqualTo "[5]";
		private _multiPartMsg = "";

		//--- DLL returned a Multi-Part Message 
		if _multiPart then 
		{
			//--- Get full message from DLL
			while{true} do {
				private _pipe = "extDB3" callExtension ("5:" + _sessionID);
				if(_pipe isEqualTo "") exitWith {_receivingMsg = false};
				_multiPartMsg = _multiPartMsg + _pipe;
			}; 
		} else {
			//--- Make sure the message is received
			if _msgReceived then {
				uisleep 0.25;
			} else {
				_receivingMsg = false;
			};
		};

		//--- Was a Multi-Part Message received?
		if(_multiPart AND count _multiPartMsg > 0)then{
			_res = _multiPartMsg;
		}else{ 
			_res = _queryResult;
		};
	};

	//--- Check response can be compiled
	if(typeName _res isNotEqualTo "STRING")exitWith{
		["DLL Response error: response isEqualTo (%1) Expected (STRING)",typeName _res] call Extremo_fnc_database_systemlog;
		_res = ["DB:Read:Task-failure"];
	};
	
	//--- Parse response
	if(not((parseSimpleArray _res) params [
		["_queryResponse",0,[0]],
		["_queryData",[]]
	]))exitWith{
		"DLL Response parsing error" call Extremo_fnc_database_systemlog;
	};

	//--- Bad Result
	if (_queryResponse isEqualTo 0) exitWith {
		_res = ["DB:Read:Task-failure"];
	};

	//--- Return single result?
	if (count _queryData >= 1 AND _single) then {
		_res = [_queryData] call BIS_fnc_arrayShift;
	}else{
		_res = _queryData;
	};
};

_res

/* 
	["CREATE", "players", 
		[//What
			["serverID", 		["DB","INT", (call extremo_var_serverID)] call Extremo_fnc_database_parse],
			["BEGuid", 			["DB","STRING", "092dd37cc6d0e2781ea42ee334debd28"] call Extremo_fnc_database_parse],
			["pid", 			["DB","STRING", "76561198276956558"] call Extremo_fnc_database_parse],
			["name", 			["DB","STRING", "nikko test"] call Extremo_fnc_database_parse],
			["cash", 			["DB","A2NET", 0] call Extremo_fnc_database_parse],
			["aliases", 		["DB","ARRAY", ["nikko test"]] call Extremo_fnc_database_parse],
			["cop_licenses", 	["DB","ARRAY", []] call Extremo_fnc_database_parse],
			["med_licenses", 	["DB","ARRAY", []] call Extremo_fnc_database_parse],
			["civ_licenses", 	["DB","ARRAY", []] call Extremo_fnc_database_parse],
			["civ_gear", 		["DB","ARRAY", []] call Extremo_fnc_database_parse],
			["cop_gear", 		["DB","ARRAY", []] call Extremo_fnc_database_parse],
			["med_gear", 		["DB","ARRAY", []] call Extremo_fnc_database_parse]
		]
	]call Extremo_fnc_database_request;

	["READ", "players", [
		[//What
			"serverID", "BEGuid", "pid", "name", "cash"
		],
		[//Where
			["BEGuid",str("092dd37cc6d0e2781ea42ee334debd28")]
		]
	],true]call Extremo_fnc_database_request;

	["UPDATE", "players", [
		[//What
			["cash",["DB","A2NET", 500] call Extremo_fnc_database_parse]
		],
		[//Where
			["BEGuid",str("092dd37cc6d0e2781ea42ee334debd28")]
		]
	]]call Extremo_fnc_database_request;
	
	["DELETE", "players", [
		[//Where
			["BEGuid",str("092dd37cc6d0e2781ea42ee334debd28")]
		]
	],true]call Extremo_fnc_database_request;

	["CALL", "deleteOldGangs"]call Extremo_fnc_database_request;

*/