/*
	## EXTREMO
	## Nikko Renolds
*/

private _cfgMessages = missionConfigFile >> "CfgMessages";
private _template = getText(_cfgMessages >> "activeTemplate");
private _messages = getArray(_cfgMessages >> _template >> "messages");
private _delay = getNumber(_cfgMessages >> _template >> "delay");
private _enabled = getNumber(_cfgMessages >> _template >> "enabled") isEqualTo 1;
private _randomOrder = getNumber(_cfgMessages >> _template >> "randomOrder") isEqualTo 1;

//--- System disabled
if !_enabled exitWith {};

//--- Shuffle messages
if _randomOrder then {
	_messages = _messages call BIS_fnc_arrayShuffle
};

//---
while{true}do
{
	uiSleep (_delay * 60);
	waitUntil {player getVariable ["ExtremoDataLoaded",false]};

	if(count _messages > 0)then{
		private _welcomeMessage = [_messages] call BIS_fnc_arrayShift;
		["_welcomeMessage"] call Extremo_fnc_system_replacmentCallback; 
		systemChat _welcomeMessage;
	};
};

true