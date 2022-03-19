/*
	## EXTREMO Survival
	## Nikko Renolds

	_text = "%ProfileName% your steamid is: %SteamID% and steam name is %<U>SteamName%. Visit %Website%"; 
	["_text"] call Extremo_fnc_system_replacmentCallback; 
	_text
*/

params[
	["_variable","",[""]]
];

private _callbacks = [
	//--- System
	["%SplashTimer%", str(round((missionNamespace getVariable ["Extremo_var_splashTimer",diag_tickTime]) - diag_ticktime))],
	["%RespawnTimer%", str(round((missionNamespace getVariable ["Extremo_var_respawnTimer",diag_tickTime]) - diag_ticktime))],
	["%FrameworkVersion%", "Extremo v1.0"],
	["%Website%", "www.extremo.co.uk"],

	//--- player
	["%SteamID%", getPlayerUID player],
	["%SteamName%", profileNameSteam],
	["%ProfileName%", profileName]
];

private _string = call compile _variable;

{
	_x params[
		["_pattern",""],
		["_replacement",""]
	];

	if(toLower ("%<U>" + (_pattern select [1])) in toLower _string)then{
		_string = _string regexReplace ["<U>",""];
		_replacement = toUpper _replacement; 
	};
	if(toLower ("%<L>" + (_pattern select [1])) in toLower _string)then{
		_string = _string regexReplace ["<L>",""];
		_replacement = toLower _replacement; 
	};
	if(toLower ("%<C>" + (_pattern select [1])) in toLower _string)then{
		_string = _string regexReplace ["<C>",""];
		_replacement = toUpper (_replacement select [0,1]) + toLower (_replacement select [1]); 
	};
	if(toLower _pattern in toLower _string)then{ 
		_string = _string regexReplace [_pattern,_replacement];
	};
}forEach _callbacks;

call compile (_variable + " = '" + _string + "';")