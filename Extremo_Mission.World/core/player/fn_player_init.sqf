/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_BEGuid","",[""]]
];

if(isFinal "extremo_var_player_beguid")exitWith{
	[0,"ERROR","An error occured (fn_player_init.sqf) ran twice"] call Extremo_fnc_gui_splashScreen; uiSleep 5;
	"extremoError" call BIS_fnc_endMission;
	false
};

extremo_var_player_beguid = compileFinal str(_BEGuid);  //--- Conatins players battleEye Guid
waitUntil{!isNull player};	//--- Make sure player object is loaded before any requests
missionNamespace setVariable [format["extremo_var_player_%1_steamName",getPlayerUID player],profileNameSteam,true];

//--- Register key handlers
waitUntil {!isNull(uiNamespace getVariable ["RscDisplayMission",displayNull])};	 //--- Make sure display is loaded before any requests
[0,"SETUP","Registering key handlers"] call Extremo_fnc_gui_splashScreen; uiSleep round(random [1,2,5]);
if([uiNamespace getVariable "RscDisplayMission",["KeyDown","KeyUp"]] call extremo_fnc_dik_initEventHandlers)then{
	[0,"LOADING","%Loading%"] call Extremo_fnc_gui_splashScreen; uiSleep round(random [1,2,5]);
}else{
	[0,"ERROR","An error occured whilst registering key handlers"] call Extremo_fnc_gui_splashScreen; uiSleep 2;
	"extremoError" call BIS_fnc_endMission;
};
(uiNamespace getVariable "RscDisplayMission") displayAddEventHandler ["Unload",
{
	[0,"ERROR","An error occured whilst registering key handlers"] call Extremo_fnc_gui_splashScreen; 
}];

//--- Make sure database is ready
if(isNil "extdb_var_database_error")then{
	[0,"SETUP","Waiting for database to ready up"] call Extremo_fnc_gui_splashScreen;
	waitUntil {!isNil "extdb_var_database_error"};
	if(extdb_var_database_error)then{
		[0,"ERROR","An server-side error occured whilst loading database"] call Extremo_fnc_gui_splashScreen; uiSleep 5;
		"extremoError" call BIS_fnc_endMission;
	}else{
		[0,"SETUP","Database online"] call Extremo_fnc_gui_splashScreen; uiSleep 2;
	};
};

//--- Request server to handle player login 
[0,"SETUP","Requesting your data"] call Extremo_fnc_gui_splashScreen; uiSleep round(random [1,2,5]);
["characters", "load", player] remoteExec ["extremo_fnc_database_server", 2];
waitUntil {player getVariable ["ExtremoDataLoaded",false]};

true