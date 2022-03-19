/*
	## EXTREMO
	## Nikko Renolds
*/

params [ 
	["_oldcharacter",player],
	["_deleteoldcharacter",false],
	["_LastLoadout",[]],
	["_LastPosition",[]],
	["_Wallet",nil]
];

Extremo_var_healthState = 0;
Extremo_var_executer = objNull;
setGroupIconsVisible [false, false];

//--- Close Briefing 
if(!isNull findDisplay 53)then{ 
	ctrlActivate (findDisplay 53 displayCtrl 1);
	findDisplay 53 closeDisplay 1;
};

//Get current group
private _group = group player;

//No group! we need a group to create unit so this check is a failsafe.
if(_group isEqualTo grpNull)then{_group = createGroup independent};

//
private _respawnPosition = [missionConfigFile >> "CfgRespawnTemplates" >> "Extremo", "respawnLocation", []] call BIS_fnc_returnConfigEntry;
private _class = call(missionNamespace getVariable ["extremo_var_playerclass", {"C_Man_casual_6_F"}]);
private _newcharacter = _group createUnit [_class, _respawnPosition, [], 0, "CAN_COLLIDE"]; 
private _resapwn = true;

//Reveal newbody to the oldbody
player reveal [_newcharacter, 4];

//
selectPlayer _newcharacter; 
setStaminaScheme "Normal";//"Normal", "FastDrain", "Exhausted" or "Default"
enableSentences false;
enableRadio false;
showSubtitles false;
showChat false;
0 fadeSound 0;

[0,"Loading", "Almost done",true,true] spawn Extremo_fnc_system_splashScreen;
uiSleep 3;

{ 
	//--- Disable parts of the AI behaviour
	_x disableAI "FSM";
	_x disableAI "MOVE";
	_x disableAI "AUTOTARGET";
	_x disableAI "TARGET";
	_x disableAI "CHECKVISIBLE";

	//--- Character Setup
	_x setVariable ["extremo_var_XM8Online", (profileNamespace getVariable ["ExtremoEnable8GNetwork", false]), true]; 
	_x setVariable ["extremo_var_incapacitated", false, true];
	_x setVariable ["BIS_noCoreConversations", true];
	_x disableConversation true;
	_x setSpeaker "NoVoice";
	_x enableFatigue true;
	_x enableStamina true;
	_x enableSimulation true;
	_x addRating 1e12; //Set our rating to a high value, this is for a ARMA engine thing.	
	_x playMove "";
	_x switchMove "";
	_x setUnconscious false;
	_x allowDamage true;
	_x setVariable ["ExtremoName", profileName, true];
	_x setVariable ["ExtremoUID", getPlayerUID _newcharacter, true];
}forEach [_newcharacter, _oldcharacter];

if(count _LastLoadout > 0)then{
	_newcharacter setUnitLoadout [_LastLoadout, false];
	_oldcharacter setUnitLoadout [[], false];
};

if(!isNil "_Wallet")then{ 
	_oldcharacter setVariable ["ExtremoWallet", 0, true];
}else{
	_Wallet = 0;
};

_newcharacter setVariable ["ExtremoWallet", _Wallet, true];

if(count _LastPosition isEqualTo 3)then{
	_newcharacter setPosATL _LastPosition;
	_resapwn = false;
}else{ 
	_newcharacter setPosATL _respawnPosition;
	["characters","update",_newcharacter] remoteExec ["extremo_fnc_database_server2client", 2];
};

if(_deleteoldcharacter)then{
	_oldcharacter remoteExec ["deleteVehicle", 2];
}else{
	_oldcharacter setDamage 1;
	[_oldcharacter, ["Hide Body", {(_this#0) remoteExec ["deleteVehicle", 2]}]] remoteExec ["addAction", -2];
	(missionNamespace getVariable["extremo_var_cleanupQueue",[]]) pushBackUnique netID _oldcharacter;
	publicVariableServer "extremo_var_cleanupQueue";
};

//--- Setup character events
{_newcharacter call compile ("_this addEventHandler ['"+_x+"', {_this call " + str(missionNamespace getVariable [format ["extremo_fnc_event_%1",tolower _x], {}]) + "}]; nil");}forEach[
	"Fired",
	"FiredNear",
	"Explosion",
	"Hit",
	"Put",
	"Take",
	"InventoryClosed", 
	"InventoryOpened", 
	"handleDamage"
];

//--- Spawn menu
if _resapwn then{
	[0,"Loading", "Preparing spawn options",true,true] spawn Extremo_fnc_system_splashScreen;
	uiSleep 3;
	[_newcharacter] spawn Extremo_fnc_gui_spawnmenu;
}else{
	[7,"SPAWNED", "You have spawned at your old location",false,false] spawn Extremo_fnc_system_splashScreen;
};

//--- Preloader
waitUntil {_newcharacter nearObjectsReady 2500};
waitUntil {50 preloadObject "SoldierW"};

//---  Force showing the chat. Sometimes Arma resets this
showChat true;
setGroupIconsVisible [true, true];

true