/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_class","",["",objNull]],
	["_lockcode","",[""]],
	["_steamID","",[""]]
];

if(typeName _class isEqualTo "OBJECT")then{
	_class = typeOf _class;
};

private _vinClass = toArray (_class select [0,5]) joinString "";
private _vinLockcode = toArray _lockcode joinString "X";

private _vinUid = _steamID select [12,5];

for "_i" from 1 to 5 do {
	_vinUid = (selectrandom ("9876543210" splitString "")) + _vinUid;
};

format ["A3_%1_%2_%3",_vinClass,_vinUid,_vinLockcode];