/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_character",objNull,[objNull]],
	["_deleteBody",false,[false]]
];

//-- Incase the prams are valid and the player disconnects/times out
//-- Player is not incapped
if (isNull _character) exitWith {};

//-- destoy effects first
if((missionNamespace getVariable ["Extremo_var_death_blurEffect",-1]) isNotEqualTo -1)then{
	ppEffectDestroy Extremo_var_death_blurEffect;
	Extremo_var_death_blurEffect = nil;
};
if((missionNamespace getVariable ["Extremo_var_death_colorEffect",-1]) isNotEqualTo -1)then{
	ppEffectDestroy Extremo_var_death_colorEffect;
	Extremo_var_death_colorEffect = nil;
};

[] call extremo_fnc_medical_destroyRevivedEffects;

[_character,_deleteBody] spawn Extremo_fnc_player_login;
 