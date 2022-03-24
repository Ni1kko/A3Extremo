/*
	## EXTREMO Survival
	## Nikko Renolds
*/

private _serverVersion =  getText(configFile >> "CfgPatches" >> "Extremo_Server" >> "version");
Extremo_Server_version = compileFinal str _serverVersion;
extremo_var_rcon_passwordOK = false;
extremo_var_rcon_restartmode = 0;

with serverNamespace do { 
	if(isNil "extremo_var_vehicles")then{
		extremo_var_vehicles = [];
	};
};

format["ExtremoServer v%1 is loading...",_serverVersion] call Extremo_fnc_util_serverlog;

if !(getRemoteSensorsDisabled) then{
	disableRemoteSensors true;
};

//--- Database setup
if(call Extremo_fnc_database_initialize)then{

	//--- Broadcast vars
	{publicVariable _x}forEach [
		"Extremo_Server_version"
	];

	//--- Add Event Handlers
	Extremo_HandleDisconnect = addMissionEventHandler ["HandleDisconnect", Extremo_fnc_event_handleDisconnect,  []];

	[] spawn {
		while {true} do {
			{
				uiSleep 60;
				if (_x isKindOf "Air" || _x isKindOf "Car" || _x isKindOf "Ship") then {
					private _vehicleReports = _x getVariable ["ExtremoIncidents",[]];
					if(count _vehicleReports > 0)then{
						{
							_x params [
								["_vehicleNET","",[""]], 
								["_vehiclePlate","",[""]],
								["_vehicleType","",[""]], 
								["_driverName","",[""]],
								["_driverUID","",[""]],
								["_driverNET","",[""]],
								["_vehicleCrew",[],[[]]],
								["_playerName","",[""]],
								["_playerUID","",[""]],
								["_playerNET","",[""]],
								["_playerLocation",[],[[]]],
								["_time","",[""]],
								["_date","",[""]]
							];

							[format ["(%1|%2) Has ran over (%3|%4) with (%6) at %7 on the %8 <posATL = %5>", 
								_driverName, 
								_driverUID,
								_playerName, 
								_playerUID, 
								_playerLocation,
								_vehicleType, 
								_time, 
								_date
							]] call Extremo_fnc_util_serverlog;
						}forEach _vehicleReports;
						_x setVariable ["ExtremoIncidents", [], true];
					};
				};
			}forEach vehicles;
		};
	};

	[format ["Server is up and running! Version: %1", _serverVersion]] call Extremo_fnc_util_serverlog;
}else{
	[format ["Server is unable to load due to database related errors!", _serverVersion]] call Extremo_fnc_util_serverlog;
};

//--- Vehicles setup
[] spawn extremo_fnc_vehicles_initialize;

true