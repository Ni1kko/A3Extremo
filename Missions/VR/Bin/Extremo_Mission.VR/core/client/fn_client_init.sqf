/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_BEGuid","",[""]]
];

(getText(configFile >> "CfgPatches" >> "Extremo_Mission" >> "frameworkVersion") call extremo_fnc_system_versionInfo)params[
	["_clientVersionFull",""],
	["_clientVersionShort",""],
	["_clientVerMajor",0],
	["_clientVerMinor",0],
	["_clientVerPatch","0"],
	["_clientPreReleaseFull",""], 
	["_clientPreReleaseShort",""],
	["_clientPreReleaseBuild",0],
	["_clientMeta",""]
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
waitUntil {!isNil "Extremo_var_system_versionOK" AND {!isNil "Extremo_var_system_versionInfo" AND {!isNil "extremo_fnc_system_versionInfo"}}};
if !Extremo_var_system_versionOK exitWith {
	((call Extremo_var_system_versionInfo) call extremo_fnc_system_versionInfo)params[
		["_serverVersionFull",""],
		["_serverVersionShort",""],
		["_serverVerMajor",0],
		["_serverVerMinor",0],
		["_serverVerPatch","0"],
		["_serverPreReleaseFull",""], 
		["_serverPreReleaseShort",""],
		["_serverPreReleaseBuild",0],
		["_serverMeta",""]
	];
	
	for "_i" from 0 to 5 do {
		[0,"ERROR", format["current version: %1 ", _clientVersionFull]] call Extremo_fnc_gui_splashScreen;
		for "_i" from 0 to 3 do {
			uiSleep 0.5;
			[0,"ERROR", format["expected version: %1 ", _serverVersionFull]] call Extremo_fnc_gui_splashScreen;
		}; 
	};
	
	format["expected version: %1 ", _serverVersionFull] call _kick;
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
 