/*
	## EXTREMO
	## Nikko Renolds
*/

disableSerialization;

params [
	["_displayTime",0,[0]],
	["_title","",["",[]]],
	["_subtitle","",[""]],
	["_background",true],
	["_blockEscapeKey",true]
];

private _titleColor = [
	0, //Red
	1, //Green
	0, //Blue
	1  //Alpha
];

if(typeName _title isEqualTo "ARRAY")then{
	_title params [
		["_text","",[""]],
		["_color",[],[_titleColor]]
	];
	_title = _text;
	_titleColor = _color;
};

private _display = compile 'uiNamespace getVariable ["RscExtremo_SplashScreen",displayNull]';
private _layer1 = ["RscExtremo_SplashScreenBlackoutLayer"] call BIS_fnc_rscLayer;
private _layer2 = ["RscExtremo_SplashScreenNoiseLayer"] call BIS_fnc_rscLayer;
private _layer3 = ["RscExtremo_SplashScreenLayer"] call BIS_fnc_rscLayer;

if(isNull(call _display))then
{
	//--Create background overlay
	if _background then{
		_layer1 cutText ["", "BLACK OUT", 0.00001];
		_layer2 cutRsc ["SPLASHNOISE", "PLAIN", 3];
	};

	//--Create overlay
	_layer3 cutRsc ["RscExtremo_SplashScreen", "PLAIN"];
}else{
	if(true in ([_layer1,_layer2] apply {_x in allActiveTitleEffects}) AND {!_background})then{
		[_layer1, "", "BLACK IN", 0.00001] call Extremo_fnc_system_destroyLayer;
		[_layer2, "", "BLACK IN", 0.00001] call Extremo_fnc_system_destroyLayer;
	};
};


if(isNil "Extremo_var_splashKeydownEVH")then{ 		
	if _blockEscapeKey then{ 
		Extremo_var_splashKeydownEVH = (call _display) displayAddEventhandler ["KeyDown", {(_this#1) isEqualTo 1}];
	};
}else{
	if !_blockEscapeKey then{ 
		(call _display) displayRemoveEventHandler ["keyDown",Extremo_var_splashKeydownEVH];
		Extremo_var_splashKeydownEVH = nil;
	};
};

if(_displayTime <= 0)then{
	if(!isNil "Extremo_var_splashTimerEVH")then{ 
		removeMissionEventHandler ["EachFrame", Extremo_var_splashTimerEVH];
		Extremo_var_splashTimerEVH = nil;
	};
	Extremo_var_splashTimer = diag_tickTime + 99999;
	[_title,_titleColor,_subtitle,false] call Extremo_fnc_system_splashScreenEH;
}else{
	Extremo_var_splashTimer = diag_tickTime + _displayTime;
	Extremo_var_splashTimerEVH = addMissionEventHandler [
		"EachFrame",
		{_thisArgs call Extremo_fnc_system_splashScreenEH},
		[_title,_titleColor,_subtitle,_background]
	];
};
