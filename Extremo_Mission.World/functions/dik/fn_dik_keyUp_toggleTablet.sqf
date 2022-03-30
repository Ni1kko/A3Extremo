/*
	## EXTREMO
	## Nikko Renolds
*/

//Apps
extremo_fnc_gui_tabletScreenGroupBanking = {
	hint str _this; //debug

	params [
		["_mode","",[""]],
		["_params",[],[[]]]
	];

	disableSerialization; 
	if (_mode isEqualTo "") exitWith {
		["extremo_fnc_gui_tabletScreenGroupBanking: <MODE> was passed empty. Function Terminated!"] call BIS_fnc_error;
	};

	switch (_mode) do 
	{
		case "onScreenShow" : 
		{
			_params params [
				["_screenBankingCtrl",controlNull,[controlNull]]
			];
		};
		case "onScreenHide" : 
		{
			_params params [
				["_screenBankingCtrl",controlNull,[controlNull]]
			];
		};
		case "onAccountChanged":
		{
			_params params [
				["_control", controlNull,[controlNull]],
				["_index",0,[0]]
			];
		};
		case "onTargetChanged":
		{
			_params params [
				["_control", controlNull,[controlNull]],
				["_index",0,[0]]
			];
		};
		case "onAmountChar":
		{
			_params params [
				["_editCtrl", controlNull,[controlNull]],
				["_keyCode",0,[0]]
			];
		};
		case "onSliderAmount":
		{
			_params params [
				["_sliderAmountCtrl",controlNull,[controlNull]],
				["_position",0,[0]]
			];
		};
		case "onConfirm":
		{
			_params params [
				["_control",controlNull,[controlNull]]
			];
		};
	};

};
extremo_fnc_gui_tabletScreenGroupCrafting = { 
	hint str _this; //debug
	params [
		["_mode","",[""]],
		["_params",[],[[]]]
	];

	disableSerialization; 
	if (_mode isEqualTo "") exitWith {
		["extremo_fnc_gui_tabletScreenGroupCrafting: <MODE> was passed empty. Function Terminated!"] call BIS_fnc_error;
	};

	switch (_mode) do {
		case "onScreenShow" : 
		{
			_params params [
				["_screenLockCtrl",controlNull,[controlNull]]
			];
		}; 
		case "onScreenHide" : 
		{
			_params params [
				["_screenLockCtrl",controlNull,[controlNull]]
			];
		}; 
		case "changeCategory" : 
		{
			_params params [
				["_categoryCtrl",controlNull,[controlNull]],
				["_selection",-1,[0]]
			];
		}; 
		case "changeItem" : 
		{
			_params params [
				["_itemCtrl",controlNull,[controlNull]],
				["_selection",-1,[0]]
			]; 
		};
	};
};
extremo_fnc_gui_tabletScreenGroupSync = { 
	hint str _this; //debug
	params [
		["_mode","",[""]],
		["_params",[],[[]]]
	];

	disableSerialization;
	if (_mode isEqualTo "")exitWith {["extremo_fnc_gui_tabletScreenGroupSync: <MODE> was passed <EMPTY>. Function Terminated!"] call BIS_fnc_error;};
	
	switch (_mode) do 
	{
		case "onScreenShow": 
		{
			_params params [
				["_control",controlNull,[controlNull]]
			];
		};
		case "onScreenHide": 
		{
			_params params [
				["_control",controlNull,[controlNull]]
			];
		};
		case "onSyncNow": 
		{ 
			_params params [
				["_buttonCtrl",controlNull,[controlNull]]
			];
		};
	};
};
extremo_fnc_gui_tabletScreenGroupContacts = { hint str _this; };
extremo_fnc_gui_tabletScreenGroupSettings = { hint str _this; };


private _displayClass = "RscExtremo_Tablet";
private _display = uinamespace getvariable [_displayClass,displayNull];

if(isNull _display)then{
	_display = createDialog [_displayClass,true];
}else{
	_display closeDisplay 2;  
};

true