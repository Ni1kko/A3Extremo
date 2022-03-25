/*
	## EXTREMO
	## Nikko Renolds
*/

//--- Setup mission eventhandlers
Extremo_var_event_preloadFinishedEH = addMissionEventHandler ["PreloadFinished",{_thisArgs call extremo_fnc_event_preloadFinished},[_BEGuid]];
Extremo_var_event_mapEH = addMissionEventHandler ["Map", {_this call extremo_fnc_event_map}];

true