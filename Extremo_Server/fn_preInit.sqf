/*
	## EXTREMO Survival
	## Nikko Renolds
*/

//--- Add Connection Event Handlers
Extremo_ClientConnected =    addMissionEventHandler ["PlayerConnected",      Extremo_fnc_event_playerConnected,    []];
Extremo_ClientDisconnected = addMissionEventHandler ["PlayerDisconnected",   Extremo_fnc_event_playerDisconnected, []];

//--- Init Beguid hashmap
ExtremoBeGuidHashmap = createHashMap;

//temp
Extremo_fnc_util_serverlog = { diag_log _this };
Extremo_fnc_rcon_kick = {
	params [ 
		["_ownerID",-999,[0]],
		["_message","",[""]]
	];

	if (_ownerID > 3) then {
		[_message,{
			[0,"ERROR",_this,true,true] spawn Extremo_fnc_system_splashScreen;
			uiSleep 1.5;
			"extremoError" call BIS_fnc_endMission;
		}] remoteExec ["spawn", _ownerID];	
	};
	

	[_message] call Extremo_fnc_util_serverlog;
};