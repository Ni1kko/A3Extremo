/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_character",player,[objNull]]
];

if(!canSuspend) exitWith {_this spawn Extremo_fnc_gui_spawnmenu; true};

private _markers = [missionConfigFile >> "CfgPlayer" >> "Extremo", "respawnMarkers", []] call BIS_fnc_returnConfigEntry;
if (isNull _character) exitWith {false};
if (count _markers <= 0) exitWith {
	[0,"ERROR","An error occured ('CfgPlayer' >> 'Extremo' >> 'respawnMarkers') is empty...",true,true] spawn Extremo_fnc_system_splashScreen;
	uiSleep 1.5;
	"extremoError" call BIS_fnc_endMission;
	false
};

private _markerName = selectRandom _markers;
private _markerPosition = getMarkerPos _markerName;
private _markerText = markerText _markerName;

//private _markerText = "Spawnzone (North Jackson)";
if(tolower(_markerText select [0,9]) == "spawnzone")then{
	_markerText = _markerText select [10,(count _markerText) - 10];
}else{
	_markerText = "";
}; 
if(_markerText isEqualTo "")then{
	//_markerText = player call BIS_fnc_locationDescription; 
	_markerText = ([player] call Extremo_fnc_system_locationInfo) param [2,"the chosen location",[""]];
};

_character setVariable ["ExtremoLastSpawnZone",_markerName];
_character setPosATL _markerPosition;

//--- Preloader
waitUntil {_newcharacter nearObjectsReady 2500};
waitUntil {50 preloadObject "SoldierW"};

[0,"SPAWNED","",true,true] spawn Extremo_fnc_system_splashScreen;
uiSleep 2.5;
[7,"SPAWNED", format ["You have spawned at %1",_markerText],false,false] spawn Extremo_fnc_system_splashScreen;

true