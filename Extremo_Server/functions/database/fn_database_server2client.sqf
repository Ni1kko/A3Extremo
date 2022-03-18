/*
	## EXTREMO Survival
	## Nikko Renolds
*/

private _table = [_this] call BIS_fnc_arrayShift;
private _action = [_this] call BIS_fnc_arrayShift;
private _rexecID = remoteExecutedOwner;

if (true in [!isServer,!isRemoteExecuted,isRemoteExecutedJIP,_rexecID <= 3]) exitWith {};

switch _table do {
	case "characters": 
	{
		private _object = [_this] call BIS_fnc_arrayShift;
		if(typeName _object isEqualTo "OBJECT")then
		{
			private _steamID = getPlayerUID _object;
			private _name = name _object;
			private _uniqueVar = format["extdb_var_database_%1error",_steamID];
			private _attempts = missionNamespace getVariable [_uniqueVar,0];
			private _BEGuid = ExtremoBeGuidHashmap getOrDefault [_steamID,'BEGuid' callExtension ("get:"+_steamID)]; 
			private _BEGuidNotCached = not(_steamID in keys ExtremoBeGuidHashmap); 
			private _BEGuidNotCalculated = _BEGuid isEqualTo "";
			private _updates = [];
			private _whereClause = [
				["BEGuid",str _BEGuid]
			];

			if _BEGuidNotCalculated exitWith{[_rexecID,"Error calculating players BEGuid"] call Extremo_fnc_rcon_kick};
			if _BEGuidNotCached then {
				ExtremoBeGuidHashmap set [_steamID, _BEGuid];
				_whereClause pushBackUnique ["S64ID", ["DB","STRING", _steamID] call Extremo_fnc_database_parse];
			};

			switch _action do 
			{
				//["characters","load",player] remoteExec ["extremo_fnc_database_server2client", 2];
				case "load": 
				{ 
					private _respawnPosition = [missionConfigFile >> "CfgRespawnTemplates" >> "Extremo", "respawnLocation", []] call BIS_fnc_returnConfigEntry;
					private _classes = [missionConfigFile >> "CfgPlayer" >> "Extremo", "respawnUnits", ["C_Man_casual_6_F"]] call BIS_fnc_returnConfigEntry;
					private _startcash = [missionConfigFile >> "CfgPlayer" >> "Extremo", "startCash", 0] call BIS_fnc_returnConfigEntry;
					private _forbiddenPositions = [missionConfigFile >> "CfgPlayer" >> "Extremo", "forbiddenPositions", []] call BIS_fnc_returnConfigEntry;
					private _useLatestRecord = true;

					if(_attempts > 5) exitWith {
						[_rexecID, format["Warning unable to load database records for BEGuid: %1", _BEGuid]] call Extremo_fnc_rcon_kick;
					};

					format["Reading database records for BEGuid: %1", _BEGuid] call Extremo_fnc_database_systemlog;
					private _request = ["READ","characters",[["BEGuid","S64ID","LastKnownName","LastLoadout","LastPosition","Class","Wallet"],_whereClause]]call Extremo_fnc_database_request;

					//--- DB Down...
					if("DB:Task-failure" in _request)exitWith {
						[_rexecID, "Warning error occured with database"] call Extremo_fnc_rcon_kick;
					};

					//--- Bad.. fail safe
					if (typeName _request isNotEqualTo "ARRAY") exitWith {
						missionNamespace setVariable [_uniqueVar, (_attempts + 1), true];
						[_this,{_this remoteExec ["extremo_fnc_database_server2client", 2]}] remoteExec ['call', _rexecID];
					};

					//--- Check for insert 
					if (count _request isEqualTo 0) exitWith {
						missionNamespace setVariable [_uniqueVar, (_attempts + 1), true];

						format["Inserting database records for BEGuid: %1", _BEGuid] call Extremo_fnc_database_systemlog;

						["CREATE", "characters", 
							[//What
								["BEGuid", 			["DB","STRING", _BEGuid] call Extremo_fnc_database_parse],
								["S64ID", 			["DB","STRING", _steamID] call Extremo_fnc_database_parse],
								["LastKnownName", 	["DB","STRING", _name] call Extremo_fnc_database_parse],
								["Wallet", 			["DB","A2NET", _startcash] call Extremo_fnc_database_parse],
								["Class", 		    ["DB","STRING", selectRandom _classes] call Extremo_fnc_database_parse]
							]
						]call Extremo_fnc_database_request;

						[_this,{_this remoteExec ["extremo_fnc_database_server2client", 2]}] remoteExec ['call', _rexecID];
					};

					//--- 
					if(count _request > 1)then{
						format["Warning multiple database records for BEGuid: %1, using %2 record!", _BEGuid,["first","latest"] select _useLatestRecord] call Extremo_fnc_database_systemlog;
					};

					//--- Select database record
					_request = if(_useLatestRecord)then{_request call BIS_fnc_arrayPop}else{[_request] call BIS_fnc_arrayShift};

					//--- 
					if(_BEGuid isNotEqualTo ([_request] call BIS_fnc_arrayShift))exitWith{
						[_rexecID, format["Warning unable to load database records for BEGuid: %1", _BEGuid]] call Extremo_fnc_rcon_kick;
					};

					//--- 
					format["Loaded database records for BEGuid: %1", _BEGuid] call Extremo_fnc_database_systemlog;

					//--- Parse request values
					{_request set [_x#0,["GAME",_x#1, _request#(_x#0)] call Extremo_fnc_database_parse]}forEach [
						[1,"STRING"],	//Parse LastKnownName
						[2,"ARRAY"],	//Parse LastLoadout
						[3,"ARRAY"],	//Parse LastPosition
						[5,"A2NET"]		//Parse Wallet
					];

					//--- Parse values into local vars with defaults 
					if !(_request params [
						["_S64ID","",[""]],//0
						["_LastKnownName","",[""]],//1
						["_LastLoadout",[],[[]]],//2
						["_LastPosition",[],[[]]],//3
						["_Class","",[""]],//4
						["_Wallet",0,[0]]//5
					])exitWith{
						[_rexecID, format["Warning unable parse database record for BEGuid: %1", _BEGuid]] call Extremo_fnc_rcon_kick;
					};

					//--- Update name
					if(_name isNotEqualTo _LastKnownName)then{
						_LastKnownName = _name;
						_updates pushBackUnique ["LastKnownName",["DB","STRING", _LastKnownName] call Extremo_fnc_database_parse]; 
					};

					//--- Reset broken\forbidden positions
					if(count _LastPosition isEqualTo 3)then
					{
						if(_LastPosition isEqualTo [0,0,0])then{
							_LastPosition = nil;
						}else{
							_forbiddenPositions pushback [_respawnPosition,90];

							if(true in (_forbiddenPositions apply {_LastPosition distance2D (_x#0) <= (_x#1)}))then{
								_LastPosition = nil;
							};
						};
					}else{
						if(_LastPosition isNotEqualTo [])then{
							_LastPosition = nil;
						};
					};

					if(isNil "_LastPosition")then{
						_LastPosition = [];
						_updates pushBackUnique ["LastPosition",["DB","ARRAY", _LastPosition] call Extremo_fnc_database_parse];	
					};

					//--- Any changes?
					if(count _updates > 0)then{
						["UPDATE", "characters",[_updates,_whereClause]]call Extremo_fnc_database_request;
					};

					//--- Send result to client
					[_table,_action,_BEGuid,_Class,_LastLoadout,_LastPosition,_Wallet] remoteExec ["extremo_fnc_database_client2server",_rexecID];
				};
				//["characters","update",player,20000] remoteExec ["extremo_fnc_database_server2client", 2];
				case "update": 
				{	
					private _LastPosition = getPosATL _object;
					private _LastLoadout = getUnitLoadout _object;
					private _Wallet = _object getVariable ["ExtremoWallet", 0];

					//--- Parse data
					{
						if((typeName _x#1) isEqualTo _x#2)then{
							_updates pushBackUnique [_x#0,["DB",_x#3, _x#1] call Extremo_fnc_database_parse];
						};
					}forEach [
						["Wallet",_Wallet,"SCALAR","A2NET"],
						["LastPosition",_LastPosition,"ARRAY","ARRAY"],
						["LastLoadout",_LastLoadout,"ARRAY","ARRAY"]
					];

					["UPDATE", "characters",[_updates,_whereClause]]call Extremo_fnc_database_request;
				};
			};
		};
	};
	case "vehicles": 
	{
		switch _action do 
		{
			case "load": 
			{

			};
			case "update": 
			{

			};
		};
	};
};