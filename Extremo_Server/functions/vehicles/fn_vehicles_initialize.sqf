/*
	## EXTREMO Survival
	## Nikko Renolds
*/


private _config = missionConfigFile >> "CfgSpawnVehicles";
private _unlockInSafeZonesAfterRestart = getNumber(_config >> "unlockInSafeZonesAfterRestart") isEqualTo 1;


//------------------------------------------------------------------------------------------
//--- Persistent Vehicles ------------------------------------------------------------------
//------------------------------------------------------------------------------------------

"Reading database records for persistent vehicles" call Extremo_fnc_database_systemlog; 
private _vehiclesDB = ["READ","vehicles",
	[
		["ID","BEGuid","Class","Lockcode","Position"],
		[
			["WorldName", ["DB","STRING", WorldName] call Extremo_fnc_database_parse],
			["Spawned", 1],	//only spawned vehicles
			["Dead", 0]		//no wrecks
		]
	]
]call Extremo_fnc_database_request;

if(_vehiclesDB isEqualTo ["DB:Read:Task-failure",false])then{
	_vehiclesDB = [];
};

private _persistentCount = 0;
{
	_x params [
		["_ID",-1,[0]],
		["_BEGuid","",[""]],
		["_Class","",[""]],
		["_Lockcode","",[""]],
		["_Position","[]",[""]]
	];

	//--- Parse Position's
	(["GAME","ARRAY", _Position] call Extremo_fnc_database_parse) params [
		["_posATL",[0,0,0]],
		["_vectorDir",[0,0,0]],
		["_vectorUp",[0,0,0]]
	];

	//--- Create Persistent Object
	private _vehicle = [_Class, _posATL, [_vectorDir, _vectorUp], true, _Lockcode] call Extremo_fnc_vehicles_createPersistentVehicle;
	
	//--- Load data for x vehicleID onto new persistent vehicle object
	private _vehicleInfo = ["vehicles","load", _ID, _vehicle] call extremo_fnc_database_server;

	//--- Data loaded okay? if not delete object
	if !(_vehicle in _vehicleInfo)then{
		deleteVehicle _vehicle;
	}else{
		_persistentCount = _persistentCount + 1;
	};
}forEach _vehiclesDB;



//------------------------------------------------------------------------------------------
//--- Non Persistent Vehicles --------------------------------------------------------------
//------------------------------------------------------------------------------------------

"Reading configs for non persistent" call Extremo_fnc_database_systemlog; 
private _gridSize = getNumber(_config >> "NonPersistent" >> "vehiclesGridSize");
private _gridVehicles = getNumber(_config >> "NonPersistent" >> "vehiclesGridAmount");
private _groundVehicles = getArray(_config >> "NonPersistent" >> "groundVehicles");
private _debugMarkers = getNumber(_config >> "NonPersistent" >> "vehiclesDebugMarkers") isEqualTo 1;
private _nonPersistentCount = 0; 
private _gridSizeOffset = _gridSize % 2;
for "_xSize" from 0 to worldSize step _gridSize do
{
	private _workingXSize = _xSize + _gridSizeOffset;
	for "_ySize" from 0 to worldSize step _gridSize do
	{
		private _workingYSize = _ySize + _gridSizeOffset;
		private _position = [_workingXSize,_workingYSize];
		private _spawned = 0;
		private _spawnedPositions = [];
		while {_spawned < _gridVehicles} do 
		{
			private _positionReal = [_position, 25, _gridSize, 5, 0 , 1 , 0 , _spawnedPositions] call BIS_fnc_findSafePos;
			if(count _positionReal isEqualTo 3)exitWith{};

			//--- 
			_spawnedPositions pushBack [[(_positionReal select 0) - 50, (_positionReal select 1) + 50],[(_positionReal select 0) + 50,(_positionReal select 1) - 50]];
			_positionReal pushBack 0;

			//--- Select a random vehicle classname
			private _vehicleClassName = selectRandom _groundVehicles;

			//--- Create Non-Persistent Object
			private _vehicle = [_vehicleClassName, _positionReal, random 360, true, true] call Extremo_fnc_vehicles_createNonPersistentVehicle;
			 
			//--- create map markers
			if _debugMarkers then{
				private _vehicleNetID = netId _vehicle;
				private _markerName = format["ExtremoVehicle_DebugMarker_%1",(_vehicleNetID splitString ":") joinString "_"];
				private _marker = createMarker [_markerName, getPosATL _vehicle];
				_marker setMarkerType "mil_marker";
				_marker setMarkerText _vehicleNetID;
				_marker setMarkerColor "ColorRed";
			};
			
			//--- 
			_spawned = _spawned + 1;
			_nonPersistentCount = _nonPersistentCount + 1;
		};
	};
};

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------


format["Spawned (%1) Persistent vehicles", _persistentCount] call Extremo_fnc_database_systemlog;
format["Spawned (%1) Non-Persistent vehicles", _nonPersistentCount] call Extremo_fnc_database_systemlog;


true