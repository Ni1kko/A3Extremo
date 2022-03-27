/*
	## EXTREMO Survival
	## Nikko Renolds
*/

params[
	["_className","",[""]],
	["_classType","land",[""]],
	["_ownerSteamID","__SERVER__"],
	["_position",[]],
	["_fuel",0],
	["_lockCode",""],
	["_lockState",true],
	["_plate",""]
];

private _debug = true;
private _databaseVehicle = count _ownerSteamID isEqualTo 17;
 
//--- Handle random or database vehicle
if !(_databaseVehicle)then{
	private _positions = uiNamespace getVariable ["ExtremoVehicles_SpawnPositions",[]];
	private _defaultLockCodes = ["0000","1111","2222","3333","4444","5555","6666","7777","8888","9999","1234","2580","2468","7890"];
	private _defaultLockState = false;
	private _defaultFuel = random 1;
	private _defaultPlate = "Extremo";

	//No pos find one
	if(count _position isEqualTo 0 AND _ownerSteamID isEqualTo "__SERVER__")then
	{  
		_position = [];
		private _search = true;  
		while {_search} do 
		{ 
			_position = switch (toLower _classType) do {
				case "water": {[nil, ["ground"]] call BIS_fnc_randomPos};
				case "air";
				case "land";
				default {[nil, ["water"]] call BIS_fnc_randomPos};
			};

			_position set [2,0];

			if (count _position != 0 AND not(_position in _positions))exitWith{
				_search = false;
			};
		};
	};

	//update vehicle data vars
	_positions pushBackUnique _position;
	_lockCode = selectRandom _defaultLockCodes;
	_lockState = _defaultLockState;
	_fuel = _defaultFuel;
	_plate = _defaultPlate;

	//save positions
	uiNamespace setVariable ["ExtremoVehicles_SpawnPositions",_positions];
}; 

//---check pos
if(count _position < 2) exitWith {objNull};

//---create vehicle
private _vehicle = createVehicle [_className, _position, [], 150, "NONE"];

//--- wait for vehicle to create
if(isNull _vehicle)exitWith {objNull};

//--- get vehicles netID and add it to master vehicle array
private _netID = netId _vehicle;
with serverNamespace do {extremo_var_vehicles pushBackUnique _netID};

//--- create map markers
if (_debug AND not(_databaseVehicle)) then{
	private _markerName = format["ExtremoVehicle_DebugMarker_%1",(_netID splitString ":") joinString "_"];
	private _marker = createMarker [_markerName, getPosATL _vehicle];
	_marker setMarkerType "mil_marker";
	_marker setMarkerText _netID;
	_marker setMarkerColor "ColorRed";
};

//--- set vehicle data
_vehicle setVariable ["ExtremoOwner",_ownerSteamID,true];
_vehicle setVariable ["ExtremoLocked",_lockState,true];
_vehicle setVariable ["ExtremoLockCode",_lockCode,true];
_vehicle lock _lockState;
_vehicle setFuel _fuel;
_vehicle setPlateNumber _plate;

format["Spawned: %1 | owner: %2 | grid: %3 | netID: %4 | lockCode: %5", _className, _ownerSteamID, mapGridPosition _vehicle,_netID,_lockCode] call Extremo_fnc_system_log;

//--- return object
_vehicle