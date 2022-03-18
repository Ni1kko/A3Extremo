/*
	## EXTREMO
	## Nikko Renolds
*/

params [
	["_corpse",objNull,[objNull]], 
	["_killer",objNull,[objNull]],
	["_respawnType",0,[0]], 
	["_respawnDelay",0,[0]]
];

switch (missionNamespace getVariable ["Extremo_var_healthState",0]) do {
	case 0: 
	{  
		player setDamage 0.99;
		player setUnitLoadout [getUnitLoadout [_corpse, false], false];
		private _pos = getPosATL _corpse;

		//Start incapacitated system
		["respawned",player] spawn Extremo_fnc_incapacitated;

		[_corpse, false] remoteExec ["hideObjectGlobal", 2];
		player setPosATL _pos;
		{player setVariable [_x, _corpse getVariable _x]} forEach allVariables _corpse;
		_corpse remoteExec ["deleteVehicle", 2];
		
		//Bypass incapacitated system and skip to respawn timer
		/*
			[]spawn{
				waitUntil{Extremo_var_healthState isEqualTo 1};
				Extremo_var_healthState = 3;
			};
		*/
	};
	case 1: 
	{ 
		//Allows user to force respawn whilst incapacitated
		Extremo_var_healthState = 3;
	};
};

true