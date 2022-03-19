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
	
	[_message] call Extremo_fnc_util_serverlog;
};