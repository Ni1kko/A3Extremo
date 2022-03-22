params [
	["_title","",[""]],
	["_titleColor",[],[[1,1,1,1]]],
	["_subtitle","",[""]],
	["_background",false,[false]],
	["_keepOpen",false]
];

private _display = uiNamespace getVariable ["RscExtremo_SplashScreen",displayNull];
private _displayCtrlTitle = _display displayCtrl 1;
private _displayCtrlSubtitle = _display displayCtrl 2;
private _dynamicTextCallback = "%Loading%";

//--- Handle callbacks
["_title"] call Extremo_fnc_system_replacmentCallback; 
["_subtitle"] call Extremo_fnc_system_replacmentCallback;
["_dynamicTextCallback"] call Extremo_fnc_system_replacmentCallback;

//--- Get controls
_displayCtrlTitle ctrlSetText toUpper _title;
_displayCtrlTitle ctrlSetTextColor _titleColor;

//--- Setup dynamic subtitle
if(_subtitle isEqualTo _dynamicTextCallback)then{
	if(isNil "Extremo_var_splash_dynamicTextTimer")then{Extremo_var_splash_dynamicTextTimer = diag_tickTime + 1.5};
	if(isNil "Extremo_var_splash_dynamicText")then{Extremo_var_splash_dynamicText = 0};
	
	if (Extremo_var_splash_dynamicTextTimer - diag_ticktime < 0) then 
	{
		if(Extremo_var_splash_dynamicText > 3)then{
			Extremo_var_splash_dynamicText = 0;
		};

		_displayCtrlSubtitle ctrlSetText format[switch (Extremo_var_splash_dynamicText) do {
			case 3: {"%1..."};
			case 2: {"%1.."};
			case 1: {"%1."};
			default {"%1"};
		},"please wait"];

		Extremo_var_splash_dynamicText = Extremo_var_splash_dynamicText + 1;
		Extremo_var_splash_dynamicTextTimer = nil;
	};
}else{
	_displayCtrlSubtitle ctrlSetText _subtitle;
};

if (Extremo_var_splashTimer - diag_ticktime < 0 || isNull _display) then 
{
	removeMissionEventHandler ["EachFrame", Extremo_var_splashTimerEVH];
	
	if !(_keepOpen)then{ 
		if(!isNil "Extremo_var_splashKeydownEVH")then{ 
			_display displayRemoveEventHandler ["keyDown",Extremo_var_splashKeydownEVH];
			Extremo_var_splashKeydownEVH = nil;
		};

		if _background then{ 
			["RscExtremo_SplashScreenBlackoutLayer", "", "BLACK IN", 3] call Extremo_fnc_system_destroyLayer;
			["RscExtremo_SplashScreenNoiseLayer", "", "BLACK IN", 0.00001] call Extremo_fnc_system_destroyLayer; 
		};
		
		["RscExtremo_SplashScreenLayer", 2] call Extremo_fnc_system_destroyLayer;
	}else{
		_displayCtrlTitle ctrlSetText ""; 
		_displayCtrlSubtitle ctrlSetText ""; 
	};

	Extremo_var_splashTimer = nil;
	Extremo_var_splashTimerEVH = nil;
};
