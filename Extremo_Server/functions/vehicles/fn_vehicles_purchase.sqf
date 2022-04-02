/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_player",objNull,[objNull]],
	["_className","",[""]],
	["_lockCode","",[""]]
];

if (count _Lockcode < 4) exitWith {
	"Purchase Failed, Not a valid pin!" remoteExec ["systemChat",owner _player];
};
if (_className isEqualTo "") exitWith {
	"Purchase Failed, system error!" remoteExec ["systemChat",owner _player];
};

private _position = [0,0,0];

if (_className isKindOf "Ship") then {
	//_position = [(getPosATL _playerObject), 100, 20] call Extremo_fnc_world_findWaterPosition; 
} else {
	_position = (getPos _player) findEmptyPosition [10, 250, _className]; 
};	

//
private _salesPrice = getNumber(configFile >> "CfgExtremoArsenal" >> _className >> "price");
private _quality = getNumber(configFile >> "CfgExtremoArsenal" >> _className >> "quality");
private _requiredRespect = getNumber(configFile >> "CfgTrading" >> "requiredRespect" >> format["Level%1",_quality]);
private _playerMoney = (_player getVariable ["ExtremoWallet", 0]);
private _playerRespect = (_player getVariable ["ExtremoScore", 0]);

if (_salesPrice > _playerMoney) exitWith {
	"Purchase Failed, Not enough poptabs!" remoteExec ["systemChat",owner _player];
};
if (_requiredRespect > _playerRespect) exitWith {
	"Purchase Failed, Not enough respect!" remoteExec ["systemChat",owner _player];
};

private _vehicle = [_className, _position, (random 360), true, _Lockcode] call Extremo_fnc_vehicles_createPersistentVehicle;

if(!isNull _vehicle)then{ 
	
	//Add it to db
	private _data = ["vehicles", "add", _player, _vehicle, _Lockcode] call extremo_fnc_database_server;

	if(count _data isEqualTo 0)exitWith{
		"Purchase Failed, Vin error!" remoteExec ["systemChat",owner _player];
	};

	//Charge them
	_player setVariable ["ExtremoWallet", (_playerMoney - _salesPrice), true];

	//update player db
	["characters", "update", _player] call extremo_fnc_database_server;
}else{
	"Purchase Failed, <null> vehicle!" remoteExec ["systemChat",owner _player];
};