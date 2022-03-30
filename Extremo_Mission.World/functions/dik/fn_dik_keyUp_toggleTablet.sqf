/*
	## EXTREMO
	## Nikko Renolds
*/

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