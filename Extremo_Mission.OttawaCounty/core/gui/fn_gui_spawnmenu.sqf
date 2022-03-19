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
	diag_log "CfgPlayer >> Extremo >> respawnMarkers is empty... place a marker down in editor and put its varname in respawnMarkers";
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
[0,"SPAWNED","",true,true] spawn Extremo_fnc_system_splashScreen;
uiSleep 2.5;
[7,"SPAWNED", format ["You have spawned at %1",_markerText],false,false] spawn Extremo_fnc_system_splashScreen;

true