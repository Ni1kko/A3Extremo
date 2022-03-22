/*
	## EXTREMO
	## Nikko Renolds
*/
params [
	["_BEGuid","",[""]]
];

BEGuid = compileFinal str _BEGuid;
extremo_var_dik_eventhandlers = [];

onPreloadFinished {
	onPreloadFinished { };

	[0,"LOADING","",true,true] spawn Extremo_fnc_gui_splashScreen;
	
	[]spawn {
		private _welcomeMessages = [missionConfigFile, "welcomeMessages", []] call BIS_fnc_returnConfigEntry;
		
		//--- Make sure player object is loaded before any requests
		[0,"LOADING","%Loading%",true,true] spawn Extremo_fnc_gui_splashScreen;
		uiSleep 1.5;
		waitUntil{!isNull player};

		//--- Register key handlers
		waitUntil {!isNull(findDisplay 46)};
		[0,"SETUP","Registering key handlers",true,true] spawn Extremo_fnc_gui_splashScreen;  
		if([findDisplay 46,["KeyDown","KeyUp"]] call extremo_fnc_dik_initEventHandlers)then{
			uiSleep 1.5;
			[0,"LOADING","%Loading%",true,true] spawn Extremo_fnc_gui_splashScreen;
		}else{
			[0,"ERROR","An error occured whilst registering key handlers",true,true] spawn Extremo_fnc_gui_splashScreen;
			uiSleep 2;
			"extremoError" call BIS_fnc_endMission;
		};

		//--- Make sure database is ready
		if(isNil "extdb_var_database_error")then{
			[0,"SETUP","Waiting for database to ready up",true,true] spawn Extremo_fnc_gui_splashScreen;
        	waitUntil {!isNil "extdb_var_database_error"};
			if(extdb_var_database_error)then{
				[0,"ERROR","An server-side error occured whilst loading database",true,true] spawn Extremo_fnc_gui_splashScreen;
				uiSleep 5;
				"extremoError" call BIS_fnc_endMission;
			}else{
				[0,"SETUP","Database loaded",true,true] spawn Extremo_fnc_gui_splashScreen;
				uiSleep 1.5;
			};
		};
		
		//--- Request server to handle player login 
		[0,"SETUP","Fetching your data",true,true] spawn Extremo_fnc_gui_splashScreen;  
		uiSleep 1.5;
		["characters", "load", player] remoteExec ["extremo_fnc_database_server2client", 2];
		waitUntil {player getVariable ["ExtremoDataLoaded",false]};


		//---
		while{true}do{
			uiSleep (3 * 60);

			if(count _welcomeMessages > 0)then{
				private _welcomeMessage = [_welcomeMessages] call BIS_fnc_arrayShift;
				["_welcomeMessage"] call Extremo_fnc_system_replacmentCallback; 
				systemChat _welcomeMessage;
			};

			if(!isNull(uiNamespace getVariable ["RscExtremo_SplashScreen",displayNull]))then{
				waitUntil{isNull(uiNamespace getVariable ["RscExtremo_SplashScreen",displayNull])};   
			};
			[0, ["Extremo",[1,0,0,0.25]],"",false,false] spawn Extremo_fnc_gui_splashScreen;
			uiSleep 50;
			[10, ["Extremo",[1,0,0,0.25]],"%Website%",false,false] spawn Extremo_fnc_gui_splashScreen;
		};
	};
};