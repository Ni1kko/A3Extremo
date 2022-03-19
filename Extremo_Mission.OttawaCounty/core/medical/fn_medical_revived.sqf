/*
	## EXTREMO
	## Nikko Renolds

	
	[_target, _reviver, false] call extremo_fnc_medical_revived;
*/

if !(params [
	["_target", objNull, [objNull]],
	["_reviver", objNull, [objNull]],
	["_adminRevive", false, [false]]
]) exitWith {};

if (isNull _target || isNull _reviver) exitWith {};
if !(_target getVariable ["extremo_var_incapacitated", false]) exitWith {};

_target setVariable ["extremo_var_incapacitated", false, true];
_target setUnconscious false;
_target allowDamage true;

Extremo_var_healthState = 0;
Extremo_var_executer = objNull;

//-- destoy effects first
ppEffectDestroy Extremo_var_death_blurEffect;
ppEffectDestroy Extremo_var_death_colorEffect;

//-- Revived effects
[] remoteExecCall ["extremo_fnc_medical_createRevivedEffects", _target];

hint format [""];
if !(_adminRevive) then {
	[format ["%1 has been revived by %1", name _target, name _reviver]] remoteExecCall ["systemChat", -2, false];
};

_target playMove "UnconsciousOutProne";
_target switchMove "UnconsciousOutProne";