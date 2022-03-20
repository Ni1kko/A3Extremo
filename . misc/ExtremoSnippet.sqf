

//--- Extremo_fnc_getVariable
if(isNil "Extremo_fnc_getVariable")then{
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

	Extremo_test = {};
	nul = ["Extremo_test"] call Extremo_fnc_callVariable;
};


//--- Extremo_fnc_getVariable
if(isNil "Extremo_fnc_getVariable")then{
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

	["Extremo_fnc_getConfigFunctions",[missionConfigFile]] call Extremo_fnc_callVariable;
};