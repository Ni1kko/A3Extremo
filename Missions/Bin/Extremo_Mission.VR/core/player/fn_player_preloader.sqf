/*
	## EXTREMO Survival
	## Nikko Renolds

	waitUntil Extremo_fnc_player_preloader;
*/

[0,"Preloader","%Loading%",true,true] call Extremo_fnc_gui_splashScreen;
uiSleep 1.2;

private _preloadDistance = 700;
private _preloadObjects = [];
private _nearestObjects = nearestTerrainObjects [player,[],_preloadDistance,true,true];

{
	switch (true) do 
	{
		case (_x isKindOf "Building"): {_preloadObjects pushBack _x};
	};
}forEach _nearestObjects;


{
	private _model = ((str _x) splitString ":") param [1,"error"];
	private _modelGrid = mapGridPosition _x;
	private _modelNet = netID _x;
	[0,"Preloader",format ["Grid: %1 | NetID: %3 | Model: %2",_modelGrid,_model,_modelNet],true,true] call Extremo_fnc_gui_splashScreen;
	waitUntil {_preloadDistance preloadObject _x AND {_x nearObjectsReady (_preloadDistance / 2)}};
}forEach _preloadObjects;

[0,"Preloader","%Loading%",true,true] call Extremo_fnc_gui_splashScreen;
waitUntil {player nearObjectsReady _preloadDistance};
uiSleep 5;

true