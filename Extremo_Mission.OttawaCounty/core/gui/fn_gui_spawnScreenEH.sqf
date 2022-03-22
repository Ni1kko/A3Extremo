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

if(typeName _object isEqualTo "CONTROL")then{
	_display = ctrlParent _object;
}else{
	_display = _object;
};

if(isNull _display)then{
	_display = uiNameSpace getVariable [_displayClass,_display];
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
	case "onLoad": 		   {uiNameSpace setVariable [_displayClass,_object]};
	case "onUnLoad": 	   {uiNameSpace setVariable [_displayClass,displayNull]};
	case "onLBSelChanged": 
	{ 
		_data params [
			["_selection",-1]
		];

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
			[0,"ERROR",format["An error occured with spawn position (%1)",_markerText],true,true] spawn Extremo_fnc_gui_splashScreen;
			uiSleep 2;
			"extremoError" call BIS_fnc_endMission;
		};

		[0,"Current Spawn Zone",_markerText,true,true] spawn Extremo_fnc_gui_splashScreen;
	};
	case "onConfirmClick": 
	{  
		private _selection = lnbCurSelRow _controlSelection;
		private _markerName = _controlSelection lnbData [_selection,0];
		private _markerText = markerText _markerName;
		private _markerPosition = getMarkerPos _markerName;
		
		//-- Close menu
		_display closeDisplay IDC_OK;

		//---
		_markerText = if(tolower(_markerText select [0,9]) == "spawnzone")then{_markerText select [10,(count _markerText) - 10]}else{""}; 
		if(_markerText isEqualTo "")then{
			_markerText = ([player] call Extremo_fnc_system_locationInfo) param [2,"the chosen location",[""]];
		};
		
		extremo_var_testdata = [_display,_controlSelection,_selection,_markerName,_markerText,_markerPosition];
 
		//--- 
		player setVariable ["ExtremoLastSpawnZone",_markerName];
		player setPosATL _markerPosition;

		//--- Preloader
		waitUntil {2500 preloadObject typeName player};
		waitUntil {player nearObjectsReady 2500};

		[0,"SPAWNING","",true,true] spawn Extremo_fnc_gui_splashScreen;
		uiSleep 2.5;
		[7,"SPAWNED", format ["You have spawned at %1",_markerText],false,false] spawn Extremo_fnc_gui_splashScreen;
	};
};