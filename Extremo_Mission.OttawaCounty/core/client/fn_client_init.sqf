/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_BEGuid","",[""]]
];

private _kick = compile '[0,"ERROR",param [0,"An error occured"]] call Extremo_fnc_gui_splashScreen; uiSleep 4; "extremoError" call BIS_fnc_endMission; false';

3 fadeSound 0;
showChat false;
enableRadio false;
showSubtitles false;
enableSentences false;
setGroupIconsVisible [false, false];

//--- Ran twice... (client may be looping due to errors)
if !(isNil "Extremo_var_event_preloadFinishedEH") exitWith (_kick);

//--- Version check
waitUntil {!isNil "Extremo_var_system_versionOK"};
if !Extremo_var_system_versionOK exitWith {
	format["Expected mission version: %1", call Extremo_var_system_version] call _kick;
};

//--- Setup client for player
[0,"LOADING","%Loading%"] call Extremo_fnc_gui_splashScreen;
waitUntil extremo_fnc_client_initVariables;
waitUntil extremo_fnc_client_initEventhandlers;

//---
[] spawn {
	private _welcomeMessages = [missionConfigFile >> "CfgPlayer" >> "Extremo", "welcomeMessages", []] call BIS_fnc_returnConfigEntry;
	waitUntil {player getVariable ["ExtremoDataLoaded",false]}; 
	while{true}do{
		uiSleep (3 * 60);

		if(count _welcomeMessages > 0)then{
			private _welcomeMessage = [_welcomeMessages] call BIS_fnc_arrayShift;
			["_welcomeMessage"] call Extremo_fnc_system_replacmentCallback; 
			systemChat _welcomeMessage;
		};

		/*waitUntil{isNull(uiNamespace getVariable ["RscExtremo_SplashScreen",displayNull])};  
		[0, ["Extremo",[1,0,0,0.25]],"",false,false] call Extremo_fnc_gui_splashScreen;
		uiSleep 50;
		[10, ["Extremo",[1,0,0,0.25]],"%Website%",false,false] call Extremo_fnc_gui_splashScreen;*/
	};
};
 