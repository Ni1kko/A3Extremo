

//--- Extremo_fnc_getVariable
if(isNil "Extremo_fnc_getVariable")then
{
	Extremo_fnc_callVariable = compile "
		params [
			['_variable','test',['']],
			['_params',[]],
			['_default',{}]
		];

		private _namespace = currentNamespace;
		private _namespaces = [missionNamespace,uiNamespace,profileNamespace];

		if(isServer)then{
			_namespaces pushBack serverNamespace;
		};

		{
			private _tempnamespace = _namespaces#_forEachIndex; 
			if(!isNil {_tempnamespace getVariable _variable})exitWith{
				_namespace = _tempnamespace;
			};
		}forEach _namespaces;
		
		private _value = (_namespace getVariable [_variable,_default]);
		
		if(typeName _value isEqualTo 'CODE')then{
			_value = _params call _value;
		};

		_value
	";

	//Extremo_test = {};
	//["Extremo_test"] call Extremo_fnc_callVariable;
};

//--- Extremo_fnc_getConfigFunctions
if(isNil "Extremo_fnc_getConfigFunctions")then
{
	//--- every config function is loaded through this function
	Extremo_fnc_getConfigFunctions = {
		params[
			['_config1',configFile,[configFile]]
		];

		//return arrays 	
		private _fnclist = [];
		private _varlist = [];
 
		private _headerNoDebug = "
			private _fnc_scriptNameParent = if (isNil '_fnc_scriptName') then {'%1'} else {_fnc_scriptName};
			private _fnc_scriptName = '%1';
			scriptName _fnc_scriptName;
		";
		private _headerSaveScriptMap = "
			private _fnc_scriptMap = if (isNil '_fnc_scriptMap') then {[_fnc_scriptName]} else {_fnc_scriptMap + [_fnc_scriptName]};
		";
		private _headerLogScriptMap = "
			textLogFormat ['%1 : %2', _fnc_scriptMap joinString ' >> ', _this];
		";
		private _headerSystem = "
			private _fnc_scriptNameParent = if (isNil '_fnc_scriptName') then {'%1'} else {_fnc_scriptName};
			scriptName '%1';
		"; 
		private _headerDefault = switch (uinamespace getvariable ["bis_fnc_initFunctions_debugMode",0]) do {
			//--- 1 - Save script map (order of executed functions) to '_fnc_scriptMap' variable
			case 1: {_headerNoDebug + _headerSaveScriptMap};

			//--- 2 - Save script map and log it
			case 2: {_headerNoDebug + _headerSaveScriptMap + _headerLogScriptMap};

			//--- 0 - Debug mode off
			default {_headerNoDebug};
		};

		private _cfgFunctions = (_x >> "CfgFunctions");
		for "_a" from 0 to (count _cfgFunctions - 1) do 
		{
			private _currentTag = _cfgFunctions select _a; 
			if (isClass _currentTag) then
			{
				private _tag = configname _currentTag;
				if !(tolower _tag in ["missionfile","autocompile"])then{
					private _tagName = gettext (_currentTag >> "tag");
					if (_tagName == "") then {_tagName = configname _currentTag};
					private _itemPathTag = gettext (_currentTag >> "file");
					for "_b" from 0 to (count _currentTag - 1) do 
					{
						private _currentCategory = _currentTag select _b;
						if (isclass _currentCategory) then 
						{
							private _categoryName = configname _currentCategory;
							private _itemPathCat = gettext (_currentCategory >> "file");
							for "_c" from 0 to (count _currentCategory - 1) do
							{
								private _currentFunction = _currentCategory select _c;
								if (isclass _currentFunction) then 
								{
									//read function
									private _itemName = configname _currentFunction;
									private _itemPathItem = gettext (_currentFunction >> "file");
									private _itemExt = gettext (_currentFunction >> "ext");
									private _itemPreInit = getnumber (_currentFunction >> "preInit") == 1;
									private _itemPostInit = getnumber (_currentFunction >> "postInit")== 1;
									private _itemPreStart = getnumber (_currentFunction >> "preStart")== 1;
									private _itemRecompile = getnumber (_currentFunction >> "recompile") == 1;
									private _itemRandomize = getnumber (_currentFunction >> "randomize") == 1;
									private _itemCheatsEnabled = getnumber (_currentFunction >> "cheatsEnabled") == 1;
									private _itemClient = getnumber (_currentFunction >> "client") == 1;
									private _itemServer = getnumber (_currentFunction >> "server") == 1;
									private _itemHeaderType = getnumber (_currentFunction >> "headerType");
									private _itemPath = if (_itemPathItem != "") then {_itemPathItem} else {""};
									private _itemVar = FormatFunction(_tagName,_itemName);
									private _itemType = "server";

									//alter some crap
									if (!_itemClient AND !_itemServer)then{_itemServer=true};
									if (_itemClient)then{_itemType = "client"}else{_itemType = "server"};
									if (_itemExt == "") then {_itemExt = ".sqf"}else{_itemExt = tolower _itemExt};
									if (_itemPath == "") then {_itemPath = if (_itemPathCat != "") then {_itemPathCat + toLower(format["\%1",FilePrefix]) + _itemName + _itemExt} else {(if(_itemPathTag != "") then {_itemPathTag + toLower(format["\%1",FilePrefix]) + _itemName + _itemExt} else {""})};};
									if (_itemPath == "") then {_itemPath = _pathFile + "\" + _categoryName + toLower(format["\%1",FilePrefix]) + _itemName + _itemExt};
									
									//user override
									private _compileFinalScript = (_compileFinal AND !_itemRecompile);

									//fucntion data saved to master array
									private _functionData = [_itemVar,_itemPath,_itemType,_compileFinalScript,_itemExt,_itemHeaderType,_itemPreInit,_itemPostInit,_itemPreStart,_itemRandomize];

									//script or fsm?
									if(_itemExt isEqualTo ".fsm")then
									{
										//construct fsm expression
										_functionData set [1,format ["%1_fsm = _this execFSM '%2'; %1_fsm",_itemVar,_itemPath]];
									}else{
										private _header = switch (_itemHeaderType) do { 
											//--- No header (used in low-level functions, like 'fired' event handlers for every weapon)
											case -1: {""};
											//--- System functions' header (rewrite default header based on debug mode)
											case 1: {_headerSystem};
											//--- Full header
											default {_headerDefault};
										};
										
										_expression = if(_itemCheatsEnabled)then{""}else{(format [_header,_itemVar,"Log: [Functions]%1 | %2"] + preprocessfilelinenumbers _itemPath)};

										if(_itemRandomize)then{
											private _findVar = "grabVariables";
											if(_findVar in _expression)then{
												//Get all variables
												private _variables = [_findVar] call compile preprocessFile _expression;
												//Nil Return
												if(isNil "_variables")then{_variables = [];};
												//Not an array return
												if(typeName _variables != "ARRAY")then{_variables = [];};
												//add to master array
												{_varlist pushBackUnique _x}forEach _variables;
											};
										};

										//load file
										_functionData set [1,_expression]; 
									};

									//add to compile list
									_fnclist pushBackUnique _functionData;
								};
							};
						};
					};
				};
			};
		};

		//return
		[_fnclist,_varlist]
	};

	//["Extremo_fnc_getConfigFunctions",[missionConfigFile]] call Extremo_fnc_callVariable;
};

//--- Extremo_fnc_directionInfo
if(isNil "Extremo_fnc_directionInfo")then
{
	Extremo_fnc_directionInfo = {
		private _position = param [0,player,[[],objNull]];

		if(typeName _position isEqualTo "OBJECT")then{
			_position = position _position; 
		};
		private _position = player call BIS_fnc_position;
		private _worldSize = worldSize / 2;
		private _nearMapMarkers = (allMapMarkers apply {if (getMarkerPos _x distance2D _position <= 1000) then {_x}else{""}}) - [""];
		private _nearPlayers = (allPlayers apply {if (_x distance2D _position <= 1000) then {_x}else{""}}) - [""];
		private _nearVehicles = (vehicles apply {if(_x isKindOf "Air" || _x isKindOf "Car" || _x isKindOf "Ship")then{if (_x distance2D _position <= 1000) then {_x}else{""}}else{""}}) - [""];
		private _nearLocations = (nearestLocations [[_worldSize, _worldSize],["NameVillage", "NameCity", "NameCityCapital", "NameLocal", "NameMarine", "Hill", "HandDrawnCamp"],sqrt (2 * _worldSize ^ 2),_position] apply {if(text _x isEqualTo "")then{""}else{[_x,text _x]}})- [""]; 
		private _nearLocationInfo = [_nearLocations] call BIS_fnc_arrayShift;
		private _nearLocation = [_nearLocationInfo] call BIS_fnc_arrayShift;
		private _nearLocationName = format ["at grid %1", mapGridPosition _position];
		private _nearLocationDirectionInfo = [_position] call Extremo_fnc_directionInfo;

		if (!isNull _nearLocation) then {
			if (_position in _nearLocation) then {
				_nearLocationName = format ["near %1", text _nearLocation]
			}else{
				_nearLocationName = text _nearLocation;
				_nearLocationDirectionInfo = [locationPosition _nearLocation] call Extremo_fnc_directionInfo;
			};
		};

		[_nearLocationDirectionInfo#0,_nearLocationName,format["%1 of %2",_nearLocationDirectionInfo#0,_nearLocationName],_nearLocation,_position,_nearLocationDirectionInfo#1,_nearMapMarkers,_nearPlayers,_nearVehicles]
	};
 
	//["Extremo_fnc_directionInfo",[player]] call Extremo_fnc_callVariable;
	//["Extremo_fnc_directionInfo",[[0,0,0]]] call Extremo_fnc_callVariable;
};

//--- Extremo_fnc_locationInfo 
if(isNil "Extremo_fnc_locationInfo")then
{
	Extremo_fnc_locationInfo = {
		private _position = param [0,player,[[],objNull]];

		if(typeName _position isEqualTo "OBJECT")then{
			_position = position _position; 
		};
		private _position = player call BIS_fnc_position;
		private _worldSize = worldSize / 2;
		private _nearMapMarkers = (allMapMarkers apply {if (getMarkerPos _x distance2D _position <= 1000) then {_x}else{""}}) - [""];
		private _nearPlayers = (allPlayers apply {if (_x distance2D _position <= 1000) then {_x}else{""}}) - [""];
		private _nearVehicles = (vehicles apply {if(_x isKindOf "Air" || _x isKindOf "Car" || _x isKindOf "Ship")then{if (_x distance2D _position <= 1000) then {_x}else{""}}else{""}}) - [""];
		private _nearLocations = (nearestLocations [[_worldSize, _worldSize],["NameVillage", "NameCity", "NameCityCapital", "NameLocal", "NameMarine", "Hill", "HandDrawnCamp"],sqrt (2 * _worldSize ^ 2),_position] apply {if(text _x isEqualTo "")then{""}else{[_x,text _x]}})- [""]; 
		private _nearLocationInfo = [_nearLocations] call BIS_fnc_arrayShift;
		private _nearLocation = [_nearLocationInfo] call BIS_fnc_arrayShift;
		private _nearLocationName = format ["at grid %1", mapGridPosition _position];
		private _nearLocationDirectionInfo = [_position] call Extremo_fnc_directionInfo;

		if (!isNull _nearLocation) then {
			if (_position in _nearLocation) then {
				_nearLocationName = format ["near %1", text _nearLocation]
			}else{
				_nearLocationName = text _nearLocation;
				_nearLocationDirectionInfo = [locationPosition _nearLocation] call Extremo_fnc_directionInfo;
			};
		};

		[
			_nearLocationDirectionInfo#0,
			_nearLocationName,
			format["%1 of %2",_nearLocationDirectionInfo#0,_nearLocationName],
			_nearLocation,
			_position,
			_nearLocationDirectionInfo#1,
			_nearMapMarkers,
			_nearPlayers,
			_nearVehicles
		]
	};

	/*(["Extremo_fnc_locationInfo",[player]] call Extremo_fnc_callVariable) params [
		["_dirName",""],
		["_nearLocationName",""],
		["_nearLocationNameOf",""],
		["_nearLocation",locationNull],
		["_position",[]],
		["_dir",0],
		["_nearMapMarkers",[]],
		["_nearPlayers",[]],
		["_nearVehicles",[]]
	]*/
};

//--- Extremo_fnc_inArray
if(isNil "Extremo_fnc_inArray")then
{
	Extremo_fnc_inArray = {
		params [
			["_query",nil],
			["_array",[],[[]]]
		];
		private _return = "";
		private _found = false;

		if(isNil "_query") exitWith {_return};
		if (typeName _array isNotEqualTo "ARRAY") exitWith {debugLog "Log: [findNestedElement] Array (0) should be an Array!"; _return};

		private _searchArrayFunc = {
			private _array = _this select 0;
			private _query = _this select 1;
			private _find = _array find _query;

			if (_find != -1) exitWith {
				_return = format["%1#%2",_return,_find];
				_found = true;
			};

			[_array, _query] call _searchArrayChildrenFunc;
		};

		private _searchArrayChildrenFunc = {
			private _array = _this select 0;
			private _query = _this select 1;

			for "_i" from 0 to ((count _array) - 1) do {
				private _sub = _array select _i;
				
				if (typeName _sub isEqualTo "ARRAY" && !_found) then {
					_return = format["%1#%2",_return,_i];
					[_sub, _query] call _searchArrayFunc;
				};
			};

			if (!_found && _return != "") then {
				_return = _return select[0, (count _return)-2];
			};
		};

		[_array, _query] call _searchArrayFunc;

		_return
	};

	private _array = [
		[
			[
				[
					[
						[true, false, "test"]
					]
				]
			]
		]
	];

	private _arrayPos = ["test",_array] call Extremo_fnc_inArray;
	private _result = "";

	if(_arrayPos isNotEqualTo "")then{
		_result = call compile("_array" + _arrayPos)
	};

	_result
};

//--- Extremo_fnc_inArray2
if(isNil "Extremo_fnc_inArray2")then
{			
	Extremo_fnc_inArray2 = {
		params [
			["_query",nil],
			["_array",[],[[]]]
		];

		private _result = []; 
		private _tmp = [];
		private _arrayIndex = 0;

		private _fnc = { 
			{
				if (isNil "_x") then {
					if (isNil "_query") then {
						_tmp set [_arrayIndex, _forEachIndex];
						_result pushBack +_tmp;
					};
				} else {
					if (_x isEqualType []) then {
						_tmp set [_arrayIndex, _forEachIndex];
						_arrayIndex = _arrayIndex + 1;
						_x call _fnc;
						_tmp resize _arrayIndex;
						_arrayIndex = _arrayIndex - 1;
					} else {
						if (!isNil "_query") then {
							if (_x isEqualTo _query) then {
								_tmp set [_arrayIndex, _forEachIndex];
								_result pushBack +_tmp;
							};
						};
					};
				};
			} forEach _this;
		};

		_array call _fnc;

		(if(count _result > 0)then{_result apply {format["#%1",_x joinString "#"]}}else{""});
	};

	private _array = [
		[
			[
				"test",
				[
					[
						[true, false, "test",[
							[
								[
									[
										[
											[
												[
													[
														"test",["test","test"]
													]
												]
											]
										]
									]
								]
							]
						]]
					]
				]
			]
		]
	];

	private _arrayPos = ["test",_array] call Extremo_fnc_inArray2;
	private _results = [];

	if(_arrayPos isNotEqualTo "")then{
		{_results pushBack [call compile("_array" + _x),_x]}forEach _arrayPos;
	};

	_results //[["test","#0#0#0"],["test","#0#0#1#0#0#2"],["test","#0#0#1#0#0#3#0#0#0#0#0#0#0#0"],["test","#0#0#1#0#0#3#0#0#0#0#0#0#0#1#0"],["test","#0#0#1#0#0#3#0#0#0#0#0#0#0#1#1"]]
};

//--- Extremo_fnc_inArray3
if(isNil "Extremo_fnc_inArray3")then
{			
	Extremo_fnc_inArray3 = {
		params [
			["_query",nil],
			["_array",[],[[]]]
		];

		private _results = [];
		private _result = [_array,_query] call BIS_fnc_findAllNestedElements;

		_result = (if(count _result > 0)then{_result apply {format["#%1",_x joinString "#"]}}else{""});
		
		if(_result isNotEqualTo "")then{
			{_results pushBack [call compile("_array" + _x),_x]}forEach _result;
		};

		_results
	};

	private _array = [
		[
			"test",
			[
				[
					[
						[true, false, "test"]
					]
				]
			]
		]
	];

	["test",_array] call Extremo_fnc_inArray3;//[["test","#0#0"],["test","#0#1#0#0#0#2"]]
	
};

//--- Extremo_fnc_vehicle_NeturalInit
if(isNil "Extremo_fnc_vehicle_NeturalInit")then
{	
	if(hasInterface)then
	{ 
		extremo_fnc_vehicle_NeturalInit = { 
			//init config var
			Extremo_var_vehicleIsNetural = false;
			Extremo_var_gear = "D";

			//keyhandler
			(uiNamespace getVariable "RscDisplayMission") displayAddEventhandler ["KeyDown", {
				params ["_displayOrControl", "_key", "_shift", "_ctrl", "_alt"];

				if(_key isEqualTo 0x11)exitWith{
					Extremo_var_vehicleIsNetural = false;
					Extremo_var_gear = "D";
					false
				};

				if(_key isEqualTo 0x1F)exitWith{
					Extremo_var_vehicleIsNetural = false;
					Extremo_var_gear = "R";
					false
				};

				false
			}];
					
		};

		extremo_fnc_vehicleNeturalAction = {
			params ["_vehicle", "_caller", "_actionId", "_arguments"];
			Extremo_var_vehicleIsNetural = true;
			Extremo_var_gear = "N";
			hint "Netural Selected";
			_vehicle disableBrakes true;
			_vehicle spawn{
				waitUntil{!Extremo_var_vehicleIsNetural || isNull _this};
				if(isNull _this)exitWith{};
				hint format["%1 Selected", ["Drive","Reverse"] select (Extremo_var_gear isEqualTo "R")];
				_this disableBrakes false;
			}
		};
	};

	if(isServer)then
	{ 
		extremo_fnc_vehicle_Init = { 
			private _vehicle = "C_Offroad_01_F" createVehicle position player;	
			
			[_vehicle, ["Select netural", extremo_fnc_vehicleNeturalAction,nil, 0, false, false, "", "!Extremo_var_vehicleIsNetural AND (player isEqualTo driver(vehicle player))"]] remoteExec ["addAction",-2, "extremo_fnc_vehicle_NeturalActionJIP"];	

			[] remoteExec ["extremo_fnc_vehicle_NeturalInit",-2,"extremo_fnc_vehicle_NeturalInitJIP"];  
		};

		
		[] spawn extremo_fnc_vehicle_Init
	};
};

//--- Extremo_fnc_system_handleEncrypt
if(isNil "Extremo_fnc_system_handleEncrypt")then
{
	extremo_fnc_system_getKey = {
		params[["_index",0],["_key","",[""]]]; 
		((profileNamespace getVariable _key) select (_index % (count(profileNamespace getVariable _key))))
	};

	extremo_fnc_system_setKey = {
		params[["_key","",[""]]]; 
		profileNamespace setVariable [_key,toArray format["wym4%1n5sw",_key]];
		saveProfileNamespace;
	};

	extremo_fnc_system_delKey = {
		params[["_key","",[""]]]; 
		profileNamespace setVariable [_key,nil];
		saveProfileNamespace;
	};

	extremo_fnc_system_handleEncrypt = {
		params[
			["_key","",[""]],
			["_input","",[""]],
			["_encrypt",true]
		];

		private _ret = [];
	
		if _encrypt then{
			_input = toArray _input;
			[_key] call extremo_fnc_system_setKey;
		};

		switch (typeName _input) do {
			case "STRING": {for "_i" from 0 to (count toArray _input)-1 do {_ret pushBack ((toArray _input # _i) + ([_i,_key] call extremo_fnc_system_getKey))}};
			case "ARRAY":{for "_i" from 0 to (count _input)-1 do {_ret pushBack ((_input#_i) - ([_i,_key] call extremo_fnc_system_getKey))}};
		};

		toString _ret
	};

	["handleEncryptKey","5435",true] call extremo_fnc_system_handleEncrypt;
	["handleEncryptKey","ﾾﾻￆ",false] call extremo_fnc_system_handleEncrypt;
};

//--- 
if(isNil "Extremo_fnc_vehicles_init")then
{
	extremo_fnc_database_request = {[]};
	extremo_fnc_vehicles_create = {
		params[
			["_className","",[""]],
			["_classType","land",[""]],
			["_ownerSteamID","__SERVER__"],
			["_position",[]]
		];
		
		private _debug = true;
		private _databaseVehicle = not(_ownerSteamID in ["__SERVER__",""]);
		private _lockCode = "";
		private _lockState = true;
		private _fuel = 0;
		private _plate = "";

		//--- Handle random or database vehicle
		if !(_databaseVehicle)then{
			private _positions = uiNamespace getVariable ["ExtremoVehicles_SpawnPositions",[]];
			private _defaultLockCodes = ["0000","1111","2222","3333","4444","5555","6666","7777","8888","9999","1234","2580","2468","7890"];
			private _defaultLockState = false;
			private _defaultFuel = random 1;
			private _defaultPlate = "Extremo";

			//No pos find one
			if(count _position isEqualTo 0 AND _ownerSteamID isEqualTo "__SERVER__")then
			{  
				_position = [];
				private _search = true;  
				while {_search} do 
				{ 
					_position = switch (toLower _classType) do {
						case "water": {[nil, ["ground"]] call BIS_fnc_randomPos};
						case "air";
						case "land";
						default {[nil, ["water"]] call BIS_fnc_randomPos};
					};

					_position set [2,0];

					if (count _position != 0 AND not(_position in _positions))exitWith{
						_search = false;
					};
				};
			};

			//update vehicle data vars
			_positions pushBackUnique _position;
			_lockCode = selectRandom _defaultLockCodes;
			_lockState = _defaultLockState;
			_fuel = _defaultFuel;
			_plate = _defaultPlate;

			//save positions
			uiNamespace setVariable ["ExtremoVehicles_SpawnPositions",_positions];
		}; 

		//---check pos
		if(count _position < 2) exitWith {objNull};
		
		//---create vehicle
		private _vehicle = createVehicle [_className, _position, [], 150, "NONE"];
		
		//--- wait for vehicle to create
		if(isNull _vehicle)exitWith {objNull};

		//--- get vehicles netID and add it to master vehicle array
		private _netID = netId _vehicle;
		with serverNamespace do
		{ 
			if(isNil "extremo_var_vehicles")then{
				extremo_var_vehicles = [];
			};

			extremo_var_vehicles pushBackUnique _netID;
		};

		//--- create map markers
		if (_debug AND not(_databaseVehicle)) then{
			private _markerName = format["ExtremoVehicle_DebugMarker_%1",(_netID splitString ":") joinString "_"];
			private _marker = createMarker [_markerName, getPosATL _vehicle];
			_marker setMarkerType "mil_marker";
			_marker setMarkerText _netID;
			_marker setMarkerColor "ColorRed";
		};

		//--- set vehicle data
		_vehicle setVariable ["ExtremoOwner",_ownerSteamID,true];
		_vehicle setVariable ["ExtremoLocked",_lockState,true];
		_vehicle setVariable ["ExtremoLockCode",_lockCode,true];
		_vehicle lock _lockState;
		_vehicle setFuel _fuel;
		_vehicle setPlateNumber _plate;
		
		//--- return object
		_vehicle
	};
	extremo_fnc_vehicles_init = {

		//--- Get min vehicle config values
		private _minCars = 20;
		private _minHelis = 2;
		private _minPlanes = 1;
		private _minShips = 1;

		//--- Get max vehicle config values
		private _maxCars = 45;
		private _maxHelis = 10;
		private _maxPlanes = 5;
		private _maxShips = 5;

		//--- Get random values based of config values
		private _totalCars = round(random[_minCars, _maxCars - _minCars, _maxCars]);
		private _totalHelis = round(random[_minHelis, _maxHelis - _minHelis, _maxHelis]);
		private _totalPlanes = round(random[_minPlanes, _maxPlanes - _minPlanes, _maxPlanes]);
		private _totalShips = round(random[_minShips, _maxShips - _minShips, _maxShips]);
		
		//--- Get forbidden vehicles config array
		private _forbidden = [""];

		//--- Get all vehicles from config `CfgVehicles`
		private _vehicles = ("getNumber (_x >> 'scope') >= 2" configClasses (configFile >> "CfgVehicles"));
		
		//--- Get all vehicles from database `Vehicles`
		"Reading database records for all spawned vehicles" call Extremo_fnc_database_systemlog; 
		private _vehiclesDB = ["READ","vehicles",[
			["ID","BEGuid","ClassName","Spawned","Dead","Position","Fuel","Damage"],
			[
				["Spawned", 1],	//only spawned vehicles
				["Dead", 0]		//no wrecks
			]
		]]call Extremo_fnc_database_request;

		private _totalVehiclesDB = count _request; 
		format["Loaded (%1) database records for spawned vehicles", _totalVehiclesDB] call Extremo_fnc_database_systemlog;
		
		//--- Sort vehicle category's
		private _cars =  	((_vehicles apply {if(configName _x isKindof 'Car')then{configName _x}else{""}}) - _forbidden);
		private _carsDB = 	(_vehiclesDB apply {});
		private _helis =  	((_vehicles apply {if(configName _x isKindof 'Helicopter')then{configName _x}else{""}}) - _forbidden);
		private _helisDB = 	(_vehiclesDB apply {});
		private _planes =  	((_vehicles apply {if(configName _x isKindof 'Plane')then{configName _x}else{""}}) - _forbidden);
		private _planesDB = (_vehiclesDB apply {});
		private _ships =   	((_vehicles apply {if(configName _x isKindof 'Ship')then{configName _x}else{""}}) - _forbidden);
		private _shipsDB = 	(_vehiclesDB apply {});

		//--- Shuffle config vehicles further sort vehicle category's and choose total vehicles
		_cars = ((_cars - _helis - _planes - _ships) call BIS_fnc_arrayShuffle) select [0,_totalCars];
		_helis = ((_helis - _cars - _planes - _ships) call BIS_fnc_arrayShuffle) select [0,_totalHelis];
		_planes = ((_planes - _cars - _helis - _ships) call BIS_fnc_arrayShuffle) select [0,_totalPlanes];
		_ships = ((_ships - _cars - _helis - _planes) call BIS_fnc_arrayShuffle) select [0,_totalShips];

		//--- Spawn config vehicles
		{[_x,"land"] call extremo_fnc_vehicles_create; uiSleep 1;}forEach _cars;
		{[_x,"air"] call extremo_fnc_vehicles_create; uiSleep 1;}forEach _helis;
		{[_x,"air"] call extremo_fnc_vehicles_create; uiSleep 1;}forEach _planes;
		{[_x,"water"] call extremo_fnc_vehicles_create; uiSleep 1;}forEach _ships;

		//--- Spawn database vehicles
		{}forEach _carsDB;
		{}forEach _helisDB;
		{}forEach _planesDB;
		{}forEach _shipsDB;


	};
	
	//purge any exsiting
	{if("ExtremoVehicle_DebugMarker" in _x)then{deleteMarker _x;}}forEach allMapMarkers;
	{deleteVehicle objectFromNetId _x}forEach (serverNamespace getVariable ["extremo_var_vehicles",[]]);
	 
	with serverNamespace do { 
		if(isNil "extremo_var_vehicles")then{
			extremo_var_vehicles = [];
		};
	};

	[] spawn extremo_fnc_vehicles_init;
};

//--- Extremo_fnc_spawnNearObj
if(isNil "Extremo_fnc_spawnNearObj")then
{ 
	extremo_fnc_spawnNearObj = {
		params [
			["_player",player],
			["_target",selectRandom vehicles]
		];

		private _pos = getPosATL _target;
		_pos set [1,(_pos#1) + 7];
		if !("itemMap" in assignedItems player)then{
			_player addItem "itemMap";
			_player assignItem "itemMap";
		};
		
		private _godMode = not(isDamageAllowed _player);
		if !(_godMode)then{_player allowDamage false};
		_player setPosATL _pos;
		if !(_godMode)then{_player allowDamage true};

		[netID _player,netID _target,_pos]
	};

	[] call extremo_fnc_spawnNearObj
};

//--- Extremo_fnc_system_itemDetails
if(isNil "Extremo_fnc_system_itemDetails")then
{ 
	Extremo_fnc_system_itemDetails = { 
		private _item = param [0,"",[""]];

		if (_item == "") exitWith {[]};//fali safe

		private _cfg = switch (true) do {
			case (isClass (configFile >> "CfgMagazines" >> _item)) : {"CfgMagazines"};
			case (isClass (configFile >> "CfgWeapons" >> _item)) : {"CfgWeapons"};
			case (isClass (configFile >> "CfgVehicles" >> _item)) : {"CfgVehicles"};
			case (isClass (configFile >> "CfgGlasses" >> _item)) : {"CfgGlasses"};
			default {""};
		};

		if (_cfg == "") exitWith {[]};//fali safe
		if !(_cfg isEqualType "") exitWith {[]};//fali safe
		if !(isClass (configFile >> _cfg >> _item)) exitWith {[]};//fali safe

		private _config = configFile >> _cfg >> _item;
		private _displayName = getText (_config >> "displayName");
		private _picture = getText (_config >> "picture");
		private _desc = getText (_config >> "descriptionshort");

		private _bis_ItemType = [_item] call BIS_fnc_itemType;
		private _category = _bis_ItemType#0;
		private _type = _bis_ItemType#1;

		private _weight = switch (_category) do {
			case "Weapon" : {
				switch (_type) do {
					case "AssaultRifle"; 
					case "Shotgun"; 
					case "Rifle";
					case "SniperRifle" : {10};
					case "BombLauncher";
					case "Cannon";
					case "GrenadeLauncher";
					case "Launcher";
					case "Mortar";
					case "RocketLauncher" : {20};
					case "MachineGun";
					case "SubmachineGun" : {15};
					case "Handgun" : {5};
					default {5}; 
				};
			};
			case "Equipment" : {
				switch (_type) do {
					case "Glasses": {1};
					case "Headgear": {2};
					case "Vest";
					case "Uniform": {3};
					case "Backpack": {4};
					default {1};
				};
			};
			case "Magazine": {1};
			case "Item": {1};
			default {1};
		};

		private ["_magazines","_muzzles","_optics","_pointers","_bipods"];
		if (_cfg == "CfgWeapons") then {
			_muzzles = [_item, "muzzle"] call BIS_fnc_compatibleItems;
			_optics = [_item, "optic"] call BIS_fnc_compatibleItems;
			_pointers = [_item, "pointer"] call BIS_fnc_compatibleItems;
			_bipods = [_item, "bipod"] call BIS_fnc_compatibleItems;

			_magazines = getArray (_config >> "magazines");
			private _muzzlesCfg = getArray (_config >> "muzzles");
			if !(_muzzlesCfg isEqualTo []) then {
				private _base = inheritsFrom _config;
				private _tmp = [];
				{
					if !(_x == "this") then {
						_tmp = getArray (_base >> _x >> "magazines");
						{
							_magazines set[count _magazines, _x];
						} foreach (_tmp);
					};
				} foreach _muzzlesCfg;
			};
		} else {
			_magazines = [];
			_muzzles = [];
			_optics = [];
			_pointers = [];
			_bipods = [];
		};

		//return
		[_item,_displayName,_picture,_desc,_category,_type,_weight,_magazines,_muzzles,_optics,_pointers,_bipods];
	};

	(["itemMap"] call Extremo_fnc_system_itemDetails) params [
		["_item","",[""]],
		["_displayName","",[""]],
		["_picture","",[""]],
		["_desc","",[""]],
		["_category","",[""]],
		["_type","",[""]],
		["_weight",0,[0]],
		["_magazines",[],[[]]],
		["_muzzles",[],[[]]],
		["_optics",[],[[]]],
		["_pointers",[],[[]]],
		["_bipods",[],[[]]]
	]; 	
};