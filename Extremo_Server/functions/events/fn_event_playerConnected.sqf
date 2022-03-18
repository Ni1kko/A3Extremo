/*
	## EXTREMO
	## Nikko Renolds
*/

params [
    ["_directPlayID",-100,[0]],		    // Number - is the unique DirectPlay ID. Quite useless as the number is too big for in-built string representation and gets rounded. It is also the same id used for user placed markers.
    ["_characterSteamID","",[""]],		// String - is getPlayerUID of the joining player. In Arma 3 it is also the same as Steam ID.
    ["_characterName","",[""]],		    // String - is profileName of the joining player.
    ["_characterDidJIP",false,[false]], // Boolean - is a flag that indicates whether or not the player joined after the mission has started (Joined In Progress). true when the player is JIP, otherwise false. (since Arma 3 v1.49)
    ["_characterOwnerID",-100,[0]],	    // Number - is owner id of the joining player. Can be used for kick or ban purposes or just for publicVariableClient. (since Arma 3 v1.49) 
    ["_directPlayIDStr","",[""]],		// String - same as _id but in string format, so could be exactly compared to user marker ids. (since Arma 3 v1.95) 
    ["_customArgs",[]] 		            // User-Defined - custom passed args (since Arma 3 v2.03) 
];
 
private _BEGuid = ExtremoBeGuidHashmap getOrDefault [_characterSteamID,'BEGuid' callExtension ("get:"+_characterSteamID)]; 
private _BEGuidNotCached = _characterSteamID in keys ExtremoBeGuidHashmap;

if(_BEGuid isEqualTo "")exitWith{
    //[_ownerID,"Error calculating players BEGuid"] call Extremo_fnc_rcon_kick;
};

if _BEGuidNotCached then{
    ExtremoBeGuidHashmap set [_characterSteamID, _BEGuid];
};

//--- Send to client
[_BEGuid, 
    {
        BEGuid = compileFinal str _this;
        onPreloadFinished {
            onPreloadFinished { };
            //startLoadingScreen ["Loading...", "RscExtremo_InitScreen"];
            //[player,true,_LastLoadout,_LastPosition,_Wallet] spawn Extremo_fnc_player_login;
            
            []spawn{
                    
                [0,"LOADING", "Fetching your data",true,true] spawn Extremo_fnc_system_splashScreen;
                uiSleep 2;
                ["characters","load",player] remoteExec ["extremo_fnc_database_server2client", 2];
                
                while{true}do{
                    uiSleep (3 * 60);
                    if(!isNull(uiNamespace getVariable ["RscExtremo_SplashScreen",displayNull]))then{
                        waitUntil{isNull(uiNamespace getVariable ["RscExtremo_SplashScreen",displayNull])};   
                    };
                    [0, ["Extremo",[1,0,0,0.25]],"",false,false] spawn Extremo_fnc_system_splashScreen;
                    uiSleep 50;
                    [10, ["Extremo",[1,0,0,0.25]],"%Website%",false,false] spawn Extremo_fnc_system_splashScreen;
                };
            };
        };
    }
] remoteExec ['call', _characterOwnerID];