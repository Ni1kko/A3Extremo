/*
	## EXTREMO
	## Nikko Renolds
*/
params [
	["_BEGuid","",[""]]
];

BEGuid = compileFinal str _BEGuid;

onPreloadFinished {
	onPreloadFinished { };

	[0,"LOADING","",true,true] spawn Extremo_fnc_system_splashScreen;
	
	[]spawn {
		private _welcomeMessages = [missionConfigFile, "welcomeMessages", []] call BIS_fnc_returnConfigEntry;
		
		waitUntil{!isNull player};
		
		[
			0,
			"LOADING", 
			"Fetching your data",
			true,
			true
		] spawn Extremo_fnc_system_splashScreen; 
		
		["characters", "load", player] remoteExec ["extremo_fnc_database_server2client", 2];
		
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
			[0, ["Extremo",[1,0,0,0.25]],"",false,false] spawn Extremo_fnc_system_splashScreen;
			uiSleep 50;
			[10, ["Extremo",[1,0,0,0.25]],"%Website%",false,false] spawn Extremo_fnc_system_splashScreen;
		};
	};
};