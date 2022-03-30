/*
	## EXTREMO
	## Nikko Renolds
*/

extremo_fnc_gui_tabletScreenSwitch = {
	params [
		['_screenSwitchClass','',['']],
		['_animType','ScrollRight',['']]
	];
};

extremo_fnc_gui_tabletScreenEH = {
	params [
		['_mode','',['']],
		['_params',[],[[]]]
	];
};

extremo_fnc_gui_tabletScreenLock = {
	params [
		['_mode','',['']],
		['_params',[],[[]]]
	];
};

//Apps
extremo_fnc_gui_tabletScreenGroupBanking = {};
extremo_fnc_gui_tabletScreenGroupContacts = {};
extremo_fnc_gui_tabletScreenGroupCrafting = {};
extremo_fnc_gui_tabletScreenGroupSync = {};
extremo_fnc_gui_tabletScreenGroupSettings = {};


private _displayClass = "RscExtremo_Tablet";
private _display = uinamespace getvariable [_displayClass,displayNull];

if(isNull _display)then{
	_display = createDialog [_displayClass,true];
}else{
	_display closeDisplay 2;  
};

true