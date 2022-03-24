/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_BEGuid","",[""]]
];

if(isFinal "extremo_var_player_beguid")exitWith{
	[0,"ERROR","An error occured (fn_client_init.sqf) ran twice"] call Extremo_fnc_gui_splashScreen;
	"extremoError" call BIS_fnc_endMission;
	false
};

extremo_var_dik_eventhandlers = [];						//--- Conatins array of added eventhandlers [['onKeyDown'123],[onKeyUp'345]]
extremo_var_dik_blockESC = false;				    	//--- DIK bock for `RscDisplayMission`
Extremo_var_event_mapEH = -1;							//--- ID of registered map event handler
Extremo_var_event_preloadFinishedEH = -1;				//--- ID of registered map event handler
extremo_var_gui_inputBusy = false;				    	//--- Cancel block for `input ui's` (don't use in other scripts)
extremo_var_gui_inputESCLock = false;					//--- DIK block for `input ui's` (don't use in other scripts)
extremo_var_gui_inputString = "";						//--- Text holder for `input ui's` (don't use in other scripts)
extremo_var_gui_inputStringAnim = "";					//--- See above ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
extremo_var_gui_inputLockCode = "";						//--- Contains last correctly entered password from `extremo_var_gui_inputString`
extremo_var_gui_inputLockCodeCorrect = false;			//--- Simlar to above but `true` if last password was correct
extremo_var_gui_playerSpawned = compile str(false);		//--- Has player spawned, `{true}` once confirm spawn (reset's on death in `fn_player_login.sqf`)	
Extremo_var_medical_healthState = 0;					//--- Current health state of player [0 = 'normal', 1 = 'bleeding', 2 = 'executed', 3 = 'suicide'] (reset's on death in `fn_player_login.sqf`)
Extremo_var_medical_executer = objNull;					//--- Contians object of the killer when the player is killed (reset's on death in `fn_player_login.sqf`)
extremo_var_player_beguid = compileFinal str(_BEGuid);  //--- Conatins players battleEye Guid

//--- Setup mission eventhandlers
Extremo_var_event_preloadFinishedEH = addMissionEventHandler ["PreloadFinished",{_thisArgs call extremo_fnc_event_preloadFinished},[_BEGuid]];
Extremo_var_event_mapEH = addMissionEventHandler ["Map", {_this call extremo_fnc_event_map}];

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
 