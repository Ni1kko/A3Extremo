#include "..\script_defines.hpp"
/*
	## EXTREMO
	## Nikko Renolds
*/

disableSerialization;
params [
	["_object",displayNull,[displayNull,controlNull]],
	["_event","",[""]],
	["_data",[]]
];

private _displayClass = "RscExtremo_SpawnScreen";
private _display = displayNull;
private _config = missionConfigFile >> "CfgSpawn";
private _template = getText(_config >> "activeTemplate");
private _configTemplate = _config >> _template;
private _configWorld = _configTemplate >> worldName;
private _markers = getArray(_configWorld >> "zones");
private _protectedMarkers = getArray(_configWorld >> "protectedZones");

if(typeName _object isEqualTo "CONTROL")then{
	_display = ctrlParent _object;
}else{
	_display = _object;
};

if(isNull _display)then{
	_display = uiNameSpace getVariable [_displayClass,_display];
	[_display,["KeyDown"],true] call extremo_fnc_dik_initEventHandlers;
};

private _controls = [
	["controlsBackground","Background"],
	["controlsBackground","Header"],
	["controls","Info"],
	["controls","Selection"],
	["controls","Confirm"]
];

(
	_controls apply {_display displayCtrl getNumber(missionConfigFile >> _displayClass >> _x#0 >> _x#1 >> "idc")}
) params [
	["_controlBackground",controlNull,[controlNull]],
	["_controlHeader",controlNull,[controlNull]],
	["_controlInfo",controlNull,[controlNull]],
	["_controlSelection",controlNull,[controlNull]],
	["_controlConfirm",controlNull,[controlNull]]
];
	

//systemChat format [(if(count _data == 0)then{"%1: %2"}else{"%1: %2 (_data = %3)"}),_displayClass,_event,_data];

switch _event do {
	case "onLoad": 		   {uiNameSpace setVariable [_displayClass,_object]; extremo_var_dik_blockESC = true; setMousePosition [0.5,0.5]};
	case "onUnLoad": 	   {uiNameSpace setVariable [_displayClass,displayNull]; extremo_var_dik_blockESC = false;};
	case "onLBSelChanged": 
	{ 
		_data params [
			["_selection",-1]
		];
		
		if(_selection isEqualTo -1)exitWith{};

		private _markerName = _object lnbData [_selection,0];
		private _markerText = markerText _markerName;
		private _markerPosition = getMarkerPos [_markerName,true];
			
		//--- 
		_markerText = if(tolower(_markerText select [0,9]) == "spawnzone")then{_markerText select [10,(count _markerText) - 10]}else{""}; 
		if(_markerText isEqualTo "")then{
			_markerText = ([player] call Extremo_fnc_system_locationInfo) param [2,"the chosen location",[""]];
		};
		
		//--- Marker missing
		if(count _markerPosition isNotEqualTo 3)exitWith{
			[0,"ERROR",format["An error occured with spawn position (%1)",_markerText],true,true] call Extremo_fnc_gui_splashScreen;
			uiSleep 2;
			"extremoError" call BIS_fnc_endMission;
		};

		[0,"Current Spawn Zone",_markerText,true,true] call Extremo_fnc_gui_splashScreen;
	};
	case "onConfirmClick": 
	{  
		private _selection = lnbCurSelRow _controlSelection;
		private _markerName = _controlSelection lnbData [_selection,0];
		private _markerPrefix = tolower(_markerText select [0,9]);
		private _markerText = markerText _markerName;
		private _markerPosition = getMarkerPos _markerName;
		private _locationInfo = [_markerPosition] call Extremo_fnc_system_locationInfo;

		_locationInfo params [
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

		//--- Close menu
		_display closeDisplay IDC_OK;
		
		private _canSpawn = true;
		{
			if(_markerName isEqualTo (_x#0))exitWith{ 
				[0,"Protected Spawn","Password required",true,true] call Extremo_fnc_gui_splashScreen;
				_display = ([_x#1,true] call Extremo_fnc_gui_lockScreen) param [0,displayNull];
				waitUntil{isNull _display};
				 
				if (extremo_var_gui_inputLockCodeCorrect)then{
					[0,"Protected Spawn","Password accepted",true,true] call Extremo_fnc_gui_splashScreen; 
				}else{
					_canSpawn = false;
					[0,"Protected Spawn","Password mismatch",true,true] call Extremo_fnc_gui_splashScreen;	
				};

				uiSleep 3;
			};
		}forEach _protectedMarkers;

		//--- Reload menu
		if !(_canSpawn)exitWith{
			waitUntil Extremo_fnc_gui_spawnScreen;
		};
	
		//--- Spawn player at position
		[0,"SPAWNING","",true,true] call Extremo_fnc_gui_splashScreen;
		player setVariable ["ExtremoLastSpawnZone",[_markerName,_locationInfo],true];
		player setVariable ["ExtremoLastSpawnTime",systemTimeUTC,true];
		player allowDamage false;
		player setPosATL _markerPosition; 
		player setDir _dir;
		uiSleep 0.5;

		//--- Preloader
		waitUntil Extremo_fnc_player_preloader;
		extremo_var_gui_playerSpawned = compile str(true);
		player allowDamage true;

		//--- Use custom name
		if(_markerPrefix isEqualTo "spawnzone")then{
			_nearLocationNameOf = format["%1 of %2",_dirName,_markerText select [10,(count _markerText) - 10]];
		};

		//--- 
		[3,"Extremo", "Spawning at "+_nearLocationNameOf+" in %SplashTimer%"] call Extremo_fnc_gui_splashScreen;
	};
};