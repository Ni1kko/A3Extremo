/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_player", objNull, [objNull]],
	["_selectionName", "", [""]],
	["_damage", 0, [0]],
	["_source", objNull, [objNull]],
	["_projectile", "", [""]],
	["_hitPartIndex", -1, [-1]],
	["_instigator", objNull, [objNull]]
];

private _handled = false;
private _vehicle = vehicle _source;
private _isVehicle = ((_vehicle isKindOf "Air" OR _vehicle isKindOf "Car" OR _vehicle isKindOf "Ship") AND _projectile isEqualTo "");

if (_player getVariable ["extremo_var_incapacitated", false]) exitWith {
	if (!(isNull _source) && {!(_source isEqualTo _player)}) then {
		Extremo_var_medical_healthState = 2;
		Extremo_var_medical_executer = _source;
	};
};

private _currentDamage = [
	_player getHit _selectionName,
	damage _player
] select (_selectionName isEqualTo "");

if (!isNull _source && {_source isNotEqualTo _player}) then 
{
	if !(_selectionName in ["","body", "head"]) exitWith {_currentDamage};

	//--- VDM
	if (_isVehicle AND count(getPlayerUID(driver(_vehicle))) isEqualTo 17) then 
	{
		private _playerName = name _player;
		private _playerUID = getPlayerUID _player;
		private _playerNET = netID _player;
		private _playerLocation = getPosATL _player;

		private _driver = driver _vehicle;
		private _driverName = name _driver;
		private _driverUID = getPlayerUID _driver;
		private _driverNET = netID _driver;
		
		private _vehicleCrew = ((crew _vehicle) - [_driver]) apply { 
			private _crewName = name _x;
			private _crewUID = getPlayerUID _x;
			private _crewNET = netID _x;
			[_crewNET,_crewName,_crewUID]
		};
		private _vehicleType = typeOf _vehicle;
		private _vehicleNET = netID _vehicle;
		private _vehiclePlate = getPlateNumber _vehicle;
		private _vehicleReports = _vehicle getVariable ["ExtremoIncidents",[]];
	 
		_vehicleReports pushBack [
			_vehicleNET, 
			_vehiclePlate,
			_vehicleType,
			_driverName,
			_driverUID,
			_driverNET,
			_vehicleCrew,
			_playerName,
			_playerUID,
			_playerNET,
			_playerLocation,
			format (["%1:%2"] + (systemTimeUTC select [3,3])),
			format (["%3/%2/%1"] + (systemTimeUTC select [0,3]))
		];
		
		_vehicle setVariable ["ExtremoIncidents", _vehicleReports, true];

		_playerUID = "2"; _driverUID = _playerUID;_driverName = "name";
	 
		private _message = parseText (if(_playerUID isNotEqualTo _driverUID)then { 
		 	format["
				<t color='#ff0000' size='1.5' align='center'>VDM Report</t>
				<br/>
				<br/>
				<t size='1' align='center'>You have just been ran over by: %1</t> 
			", _driverName];
		}else{
			"
				<t color='#ff0000' size='1.5' align='center'>VDM Report</t>
				<br/>
				<br/>
				<t size='1' align='center'>You have just been arma`d</t> 
			"
		});

		//hint _message;
		systemChat (((str(_message)regexReplace["\ ", "^"])splitString"^")joinString" ");
		 
		_damage = _currentDamage;
	}else{

	}
};

private _canDie = [_player,_selectionName,_damage,_source,_projectile,_hitPartIndex,_instigator] call extremo_fnc_medical_canDie;
private _execute = false;

if (_canDie) then {
	private _returnDamage = _currentDamage;
	if (_handled) exitWith {_returnDamage};

	if (diag_tickTime - ((_player getVariable ["extremo_var_lastHandledDMG", 0])) > .2) then {
		_player setVariable ["extremo_var_lastHandledDMG", diag_tickTime, true];

		if ((_player getVariable ["extremo_var_incapacitated", false]) AND (_player getVariable ["extremo_var_canExecute", false]) AND !(_projectile isEqualTo "") AND !(currentWeapon _source isEqualTo "")) then 
		{
			if (_source distance _player > 50) exitWith {_returnDamage};
			_returnDamage = _damage;
			_execute = true;
		} 
		else 
		{
			if (!(_player getVariable ["extremo_var_incapacitated", false])) then 
			{
				_player setVariable ["extremo_var_canExecute", false, true];
				[_source,_player] spawn extremo_fnc_medical_incapacitated;

				[_player] spawn {
					params ["_player"];
					sleep 2;
					_player setVariable ["extremo_var_canExecute", true, true];
				};
			};
		};
	};
	_currentDamage;
};

[_damage min 0.99, _damage] select _execute
