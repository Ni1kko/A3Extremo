

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

//--- extremo_fnc_vehicle_NeturalInit
if(isNil "extremo_fnc_vehicle_NeturalInit")then
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

