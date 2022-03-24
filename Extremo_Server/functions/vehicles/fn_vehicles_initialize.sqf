/*
	## EXTREMO Survival
	## Nikko Renolds
*/

//--- Get min vehicle config values
private _minCars = 20;
private _minHelis = 2;
private _minPlanes = 1;
private _minShips = 1;

//--- Get max vehicle config values
private _maxCars = 45;
private _maxHelis = 10;
private _maxPlanes = 5;
private _maxShips = 5;

//--- Get random values based of config values
private _totalCars = round(random[_minCars, _maxCars - _minCars, _maxCars]);
private _totalHelis = round(random[_minHelis, _maxHelis - _minHelis, _maxHelis]);
private _totalPlanes = round(random[_minPlanes, _maxPlanes - _minPlanes, _maxPlanes]);
private _totalShips = round(random[_minShips, _maxShips - _minShips, _maxShips]);

//--- Get forbidden vehicles config array
private _forbidden = [""];

//--- Get all vehicles from config `CfgVehicles`
"Reading configs for all vehicles" call Extremo_fnc_util_serverlog; 
private _vehicles = ("getNumber (_x >> 'scope') >= 2" configClasses (configFile >> "CfgVehicles"));
private _totalVehicles = count _vehicles; 
format["Loaded (%1) vehicle configs", _totalVehicles] call Extremo_fnc_util_serverlog;

//--- Get all vehicles from database `Vehicles`
"Reading database records for all spawned vehicles" call Extremo_fnc_database_systemlog; 
private _vehiclesDB = ["READ","vehicles",[
	["ID","BEGuid","Class","Spawned","Dead","Position","Fuel","Damage"],
	[
		["Spawned", 1],	//only spawned vehicles
		["Dead", 0]		//no wrecks
	]
]]call Extremo_fnc_database_request;

if(_vehiclesDB isEqualTo ["DB:Read:Task-failure",false])then{
	_vehiclesDB = [];
};

private _totalVehiclesDB = count _vehiclesDB; 
format["Loaded (%1) database records for spawned vehicles", _totalVehiclesDB] call Extremo_fnc_database_systemlog;

//--- Sort vehicle category's
private _cars =  	((_vehicles apply {if(configName _x isKindof 'Car')then{configName _x}else{""}}) - _forbidden);
private _carsDB = 	(_vehiclesDB apply {});
private _helis =  	((_vehicles apply {if(configName _x isKindof 'Helicopter')then{configName _x}else{""}}) - _forbidden);
private _helisDB = 	(_vehiclesDB apply {});
private _planes =  	((_vehicles apply {if(configName _x isKindof 'Plane')then{configName _x}else{""}}) - _forbidden);
private _planesDB = (_vehiclesDB apply {});
private _ships =   	((_vehicles apply {if(configName _x isKindof 'Ship')then{configName _x}else{""}}) - _forbidden);
private _shipsDB = 	(_vehiclesDB apply {});

//--- Shuffle config vehicles further sort vehicle category's and choose total vehicles
_cars = ((_cars - _helis - _planes - _ships) call BIS_fnc_arrayShuffle) select [0,_totalCars];
_helis = ((_helis - _cars - _planes - _ships) call BIS_fnc_arrayShuffle) select [0,_totalHelis];
_planes = ((_planes - _cars - _helis - _ships) call BIS_fnc_arrayShuffle) select [0,_totalPlanes];
_ships = ((_ships - _cars - _helis - _planes) call BIS_fnc_arrayShuffle) select [0,_totalShips];

//--- Spawn config vehicles
{[_x,"land"] call extremo_fnc_vehicles_create; uiSleep 1;}forEach _cars;
{[_x,"air"] call extremo_fnc_vehicles_create; uiSleep 1;}forEach _helis;
{[_x,"air"] call extremo_fnc_vehicles_create; uiSleep 1;}forEach _planes;
{[_x,"water"] call extremo_fnc_vehicles_create; uiSleep 1;}forEach _ships;

//--- Spawn database vehicles
{}forEach _carsDB;
{}forEach _helisDB;
{}forEach _planesDB;
{}forEach _shipsDB;

true