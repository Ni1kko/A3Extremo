params [
	["_title","",[""]],
	["_titleColor",[],[[1,1,1,1]]],
	["_subtitle","",[""]],
	["_background",false,[false]]
];

private _display = uiNamespace getVariable ["RscExtremo_SplashScreen",displayNull];
private _displayCtrlTitle = _display displayCtrl 1;
private _displayCtrlSubtitle = _display displayCtrl 2;

//--- Handle callbacks
["_title"] call Extremo_fnc_system_replacmentCallback; 
["_subtitle"] call Extremo_fnc_system_replacmentCallback; 

_displayCtrlTitle ctrlSetText toUpper _title;
_displayCtrlTitle ctrlSetTextColor _titleColor;
_displayCtrlSubtitle ctrlSetText _subtitle;

if (Extremo_var_splashTimer - diag_ticktime < 0 || isNull _display) then 
{
	removeMissionEventHandler ["EachFrame", Extremo_var_splashTimerEVH];
	
	if(!isNil "Extremo_var_splashKeydownEVH")then{ 
		_display displayRemoveEventHandler ["keyDown",Extremo_var_splashKeydownEVH];
		Extremo_var_splashKeydownEVH = nil;
	};

	if _background then{ 
		["RscExtremo_SplashScreenBlackoutLayer", "", "BLACK IN", 3] call Extremo_fnc_system_destroyLayer;
		["RscExtremo_SplashScreenNoiseLayer", "", "BLACK IN", 0.00001] call Extremo_fnc_system_destroyLayer; 
	};
	
	["RscExtremo_SplashScreenLayer", 2] call Extremo_fnc_system_destroyLayer;
	Extremo_var_splashTimer = nil;
	Extremo_var_splashTimerEVH = nil;
};