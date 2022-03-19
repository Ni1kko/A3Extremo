class CfgPatches 
{
    class Extremo_Server_Functions
	{
        class authors_info
		{
			class author_0
			{
				name = "Nikko";
				uid = "76561199109931625";
				email = "Ni1kko@outlook.com";
				github = "github.com/Ni1kko";
			};
		};
        version = "1.0.72";
		requiredVersion=2.04;
		requiredAddons[] = {};
		units[] = {};
		weapons[] = {};
	};
};
 
class CfgFunctions 
{ 
    class Extremo
    {
        //--- Extremo Event Functions 
        class Event_Functions
        {
            file = "\Extremo_Server\functions\events"; 
            class event_playerConnected {};
            class event_playerDisconnected {};
            class event_handleDisconnect {};
            class event_mpKilled {};
        };

        class Server_Functions
        {
            file = "\Extremo_Server\functions\server"; 
            class server_init {};
        };
    };
};
