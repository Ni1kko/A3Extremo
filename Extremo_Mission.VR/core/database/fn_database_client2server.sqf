/*
	## EXTREMO Survival
	## Nikko Renolds
*/

if (!hasInterface) exitWith {};

private _table = [_this] call BIS_fnc_arrayShift;
private _action = [_this] call BIS_fnc_arrayShift;//not used client side

switch _table do 
{
	case "characters": 
	{
		params [
			["_BEGuid","",[""]],
			["_Class","",[""]],
			["_LastLoadout",[],[[]]],
			["_LastPosition",[],[[]]],
			["_Wallet",0,[0]]
		];
		missionNamespace setVariable ["extremo_var_playerclass", compileFinal str _Class];
		[0,"LOADED", "Your data has been loaded",true,true] spawn Extremo_fnc_system_splashScreen;
		[player,true,_LastLoadout,_LastPosition,_Wallet] spawn Extremo_fnc_player_login;
	};
	case "vehicles": 
	{
	 
	};
};
