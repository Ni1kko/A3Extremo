#include "..\script_defines.hpp"

/*
	## EXTREMO
	## Nikko Renolds
*/

disableSerialization;

params [
	["_data",[],[[]]], 
	["_event","",[""]], 
	["_keypadInput",-1,[0,false,""]]
];

//--- Display
private _displayClass = "RscExtremo_LockScreen";
private _object = _data param [0,displayNull,[displayNull,controlNull]];
private _display = (if(typeName _object isEqualTo "CONTROL")then{ctrlParent _object}else{_object});
private _lockCode = "";

//--- Fail-safe
if(isNull _display)then{
	_display = uiNameSpace getVariable [_displayClass,_display];
};

//--- 
private _controls = [
	["controlsBackground","Background"],
	["controls","NumFake"],
	["controls","Num0"],
	["controls","Num1"],
	["controls","Num2"],
	["controls","Num3"],
	["controls","Num4"],
	["controls","Num5"],
	["controls","Num6"],
	["controls","Num7"],
	["controls","Num8"],
	["controls","Num9"],
	["controls","Confirm"],
	["controls","Cancel"],
	["controls","Screen"]
];

(_controls apply {_display displayCtrl getNumber(missionConfigFile >> _displayClass >> _x#0 >> _x#1 >> "idc")}) params [
	["_controlBackground",controlNull,[controlNull]],
	["_controlNumFake",controlNull,[controlNull]],
	["_controlNum0",controlNull,[controlNull]],
	["_controlNum1",controlNull,[controlNull]],
	["_controlNum2",controlNull,[controlNull]],
	["_controlNum3",controlNull,[controlNull]],
	["_controlNum4",controlNull,[controlNull]],
	["_controlNum5",controlNull,[controlNull]],
	["_controlNum6",controlNull,[controlNull]],
	["_controlNum7",controlNull,[controlNull]],
	["_controlNum8",controlNull,[controlNull]],
	["_controlNum9",controlNull,[controlNull]],
	["_controlConfirm",controlNull,[controlNull]],
	["_controlCancel",controlNull,[controlNull]],
	["_controlScreen",controlNull,[controlNull]]
];

//--
private _fnc_updateLockCode = {
	params [["_number",-1,[0]]];
	if(_number < 0 OR _number > 9)exitWith{ false };
	
	if(isNil "Extremo_inputCodeBlocked")then{Extremo_inputCodeBlocked = false};
	if(Extremo_inputCodeBlocked)exitWith{ false };

	if(isNil "Extremo_inputCode")then{Extremo_inputCode = ""};
	Extremo_inputCode = format["%1%2",Extremo_inputCode,_number];
	
	true
}; 

//--- Buttons are used with mouse and keyboard
private _fnc_updateScreen = {
	params [
		["_number",-1,[0]]
	];
	
	private _updated = [_number] call _fnc_updateLockCode;
	private _streamFriendly = profileNameSpace getVariable ["ExtremoStreamFriendlyUI", false];
	 
	if !_updated exitWith { false }; 
	ctrlSetFocus _controlNumFake;
	_controlScreen ctrlSetText (if _streamFriendly then {toString (toArray Extremo_inputCode apply {42})}else{Extremo_inputCode});
	_controlConfirm ctrlEnable (count Extremo_inputCode >= 4);
	_controlCancel ctrlEnable not(Extremo_cancelCodeBlocked);

	true
};

private _fnc_deleteButton = {
	params [	
		["_singleNum",true],
		["_override",false]
	];

	if(isNil "Extremo_inputCode")then{Extremo_inputCode = ""};
	if(isNil "Extremo_inputCodeAnim")then{Extremo_inputCodeAnim = ""};
	if(isNil "Extremo_inputCodeBlocked")then{Extremo_inputCodeBlocked = false};
	if(isNull _display OR (Extremo_inputCodeBlocked AND !_override))exitWith{false};

	if _override then {
		Extremo_inputCodeAnim = if(_singleNum AND count Extremo_inputCodeAnim >= 1)then{Extremo_inputCodeAnim select [0,(count Extremo_inputCodeAnim) -1]}else{""};
	}else{
		Extremo_inputCode = if(_singleNum AND count Extremo_inputCode >= 1)then{Extremo_inputCode select [0,(count Extremo_inputCode) -1]}else{""};
	};
	
	ctrlSetFocus _controlNumFake;
	_controlScreen ctrlSetText ([Extremo_inputCode,Extremo_inputCodeAnim] select _override);
	_controlConfirm ctrlEnable (count Extremo_inputCode >= 4);

	true
};

private _fnc_confirmAnim = compile (
	"
		private _display = uiNameSpace getVariable ['"+_displayClass+"',displayNull];
		("+str _controls+" apply {_display displayCtrl getNumber(missionConfigFile >> '"+_displayClass+"' >> _x#0 >> _x#1 >> 'idc')}) params [
			['_controlBackground',controlNull,[controlNull]],
			['_controlNumFake',controlNull,[controlNull]],
			['_controlNum0',controlNull,[controlNull]],
			['_controlNum1',controlNull,[controlNull]],
			['_controlNum2',controlNull,[controlNull]],
			['_controlNum3',controlNull,[controlNull]],
			['_controlNum4',controlNull,[controlNull]],
			['_controlNum5',controlNull,[controlNull]],
			['_controlNum6',controlNull,[controlNull]],
			['_controlNum7',controlNull,[controlNull]],
			['_controlNum8',controlNull,[controlNull]],
			['_controlNum9',controlNull,[controlNull]],
			['_controlConfirm',controlNull,[controlNull]],
			['_controlCancel',controlNull,[controlNull]],
			['_controlScreen',controlNull,[controlNull]]
		];
				
		Extremo_inputCodeBlocked = true;
		Extremo_inputCodeAnim = ctrlText _controlScreen;
		ctrlSetFocus _controlNumFake;

		waitUntil {
			uiSleep 0.45;
			if(not([true,true] call "+str _fnc_deleteButton+"))exitWith{true};
			if(count Extremo_inputCodeAnim isEqualTo 0)exitWith{true};
			false
		};

		uiSleep 0.20;	
		Extremo_inputCodeBlocked = false;
		_display closeDisplay 1;
	"
);

private _fnc_confirmButton = {
	if(isNil "Extremo_lockCode")then{[[_display],'onSetPin',""] call Extremo_fnc_gui_lockScreenEH;};
	if(isNil "Extremo_inputCode")then{Extremo_inputCode = ""};
	if(isNil "Extremo_inputCodeBlocked")then{Extremo_inputCodeBlocked = false};
	if(Extremo_inputCodeBlocked)exitWith{false};
	private _validCode = count Extremo_inputCode >= 4;
	private _correctCode = (_validCode AND Extremo_inputCode isEqualTo Extremo_lockCode);
	Extremo_inputCode = ["",Extremo_inputCode] select _correctCode;
	_controlScreen ctrlSetText toUpper([["Invalid Code",""] select _validCode,"Authorised"] select _correctCode);
	[] spawn _fnc_confirmAnim;
};

private _fnc_cancelButton = {
	if(isNil "Extremo_inputCodeBlocked")then{Extremo_inputCodeBlocked = false};
	if(isNil "Extremo_cancelCodeBlocked")then{Extremo_cancelCodeBlocked = false};
	if(Extremo_inputCodeBlocked || Extremo_cancelCodeBlocked)exitWith{false};
	Extremo_inputCode = "";
	_display closeDisplay 2;
};

//--- Handle  input
switch (typeName _keypadInput) do {
	case "BOOL": 
	{
		if(_event isEqualTo "onMouseButtonClick")then{ 
			_keypadInput = [-999,999] select _keypadInput;//(confirm\cancel)	
		};
	}; 
	case "STRING": 
	{
		if(_event isEqualTo "onSetPin")then{ 
			_lockCode = _keypadInput;
		};
	};
};
	
//--- Handle events
switch _event do {
	case "onLoad":
	{ 
		uiNameSpace setVariable [_displayClass,_display];
		Extremo_inputCode = "";
		_controlScreen ctrlSetText "ENTER LOCKCODE";
		_controlConfirm ctrlEnable false; 
		_controlCancel ctrlEnable not(Extremo_cancelCodeBlocked);
		ctrlSetFocus _controlNumFake;
	};
	case "onUnLoad":
	{  
		uiNameSpace setVariable [_displayClass,displayNull]; 
		Extremo_cancelCodeBlocked = false;
		[[_display],'onUnsetPin',""] call Extremo_fnc_gui_lockScreenEH;
	};
	case "onSetPin":
	{
		Extremo_lockCode = _lockCode;
	};
	case "onUnsetPin":
	{
		Extremo_inputCodeBlocked = false;
		Extremo_lockCode = nil;
	};
	case "onKeyUp":	
	{ 
		_data params [
			["_control",displayNull,[displayNull,controlNull]], 
			["_dik",0,[0]],
			["_shift",false,[false]],  
			["_ctrl",false,[false]], 
			["_alt",false,[false]]
		];

		private _stopPropagation = false;
		switch _dik do  
		{ 
			//Add (keyboard\numpad)
			case DIK_0; case DIK_NUMPAD0: { [0] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_1; case DIK_NUMPAD1: { [1] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_2; case DIK_NUMPAD2: { [2] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_3; case DIK_NUMPAD3: { [3] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_4; case DIK_NUMPAD4: { [4] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_5; case DIK_NUMPAD5: { [5] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_6; case DIK_NUMPAD6: { [6] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_7; case DIK_NUMPAD7: { [7] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_8; case DIK_NUMPAD8: { [8] call _fnc_updateScreen; _stopPropagation = true; };
			case DIK_9; case DIK_NUMPAD9: { [9] call _fnc_updateScreen; _stopPropagation = true; };
			//Delete
			case DIK_BACKSPACE:
			{
				[] call _fnc_deleteButton;
				_stopPropagation = true;	
			};
			//Confirm
			case DIK_RETURN; case DIK_NUMPADENTER:
			{
				[] call _fnc_confirmButton;
				_stopPropagation = true;
			};
			//Cancel
			case DIK_ESCAPE: 
			{  
				[] call _fnc_cancelButton;
				_stopPropagation = true; 
			}; 
		};
		_stopPropagation 
	};
	case "onMouseButtonClick":
	{ 
		_data params [
			["_control",displayNull,[displayNull,controlNull]], 
			["_dib",0,[0]], 
			["_xPos",0,[0]], 
			["_yPos",0,[0]],  
			["_shift",false,[false]],  
			["_ctrl",false,[false]], 
			["_alt",false,[false]]
		];

		private _mouseClickLeft = (_dib isEqualTo 0);
		private _mouseClickRight = (_dib isEqualTo 1);

		if _mouseClickLeft then
		{
			switch _keypadInput do 
			{
				//Numpad
				case 0;
				case 1;
				case 2;
				case 3;
				case 4;
				case 5;
				case 6;
				case 7;
				case 8;
				case 9:{[_keypadInput] call _fnc_updateScreen};
				//Confirm
				case 999:{[] call _fnc_confirmButton};
				//Cancel
				case -999;
				default {[] call _fnc_cancelButton};
			};
		}else{
			switch _keypadInput do 
			{
				//Confirm
				case 999:   {[false] call _fnc_deleteButton};
				//Cancel
				case -999: 	{[true] call _fnc_deleteButton};
			};
		};
	};
};