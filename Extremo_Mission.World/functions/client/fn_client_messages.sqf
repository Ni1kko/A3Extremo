/*
	## EXTREMO
	## Nikko Renolds
*/

private _welcomeMessages = [missionConfigFile >> "CfgPlayer" >> "Extremo", "welcomeMessages", []] call BIS_fnc_returnConfigEntry;

while{true}do
{
	waitUntil {player getVariable ["ExtremoDataLoaded",false]};

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

true