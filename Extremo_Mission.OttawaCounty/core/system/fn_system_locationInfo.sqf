/*
	## EXTREMO
	## Nikko Renolds

	([player] call Extremo_fnc_system_locationInfo) params [
		["_dirName",""],
		["_nearLocationName",""],
		["_nearLocationNameOf",""],
		["_nearLocation",locationNull],
		["_position",[]],
		["_dir",0],
		["_nearMapMarkers",[]],
		["_nearPlayers",[]],
		["_nearVehicles",[]]
	];
*/

private _position = param [0,player,[[],objNull]];

if(typeName _position isEqualTo "OBJECT")then{
	_position = position _position; 
};

private _position = player call BIS_fnc_position;
private _worldSize = worldSize / 2;
private _nearMapMarkers = (allMapMarkers apply {if (getMarkerPos _x distance2D _position <= 1000) then {_x}else{""}}) - [""];
private _nearPlayers = (allPlayers apply {if (_x distance2D _position <= 1000) then {_x}else{""}}) - [""];
private _nearVehicles = (vehicles apply {if(_x isKindOf "Air" || _x isKindOf "Car" || _x isKindOf "Ship")then{if (_x distance2D _position <= 1000) then {_x}else{""}}else{""}}) - [""];
private _nearLocations = (nearestLocations [[_worldSize, _worldSize],["NameVillage", "NameCity", "NameCityCapital", "NameLocal", "NameMarine", "Hill", "HandDrawnCamp"],sqrt (2 * _worldSize ^ 2),_position] apply {if(text _x isEqualTo "")then{""}else{[_x,text _x]}})- [""]; 
private _nearLocationInfo = [_nearLocations] call BIS_fnc_arrayShift;
private _nearLocation = [_nearLocationInfo] call BIS_fnc_arrayShift;
private _nearLocationName = format ["at grid %1", mapGridPosition _position];
private _nearLocationDirectionInfo = [_position] call Extremo_fnc_system_directionInfo;

if (!isNull _nearLocation) then {
	if (_position in _nearLocation) then {
		_nearLocationName = format ["near %1", text _nearLocation]
	}else{
		_nearLocationName = text _nearLocation;
		_nearLocationDirectionInfo = [locationPosition _nearLocation] call Extremo_fnc_system_directionInfo;
	};
};

[
	_nearLocationDirectionInfo#0,
	_nearLocationName,
	format["%1 of %2",_nearLocationDirectionInfo#0,_nearLocationName],
	_nearLocation,
	_position,
	_nearLocationDirectionInfo#1,
	_nearMapMarkers,
	_nearPlayers,
	_nearVehicles
]
