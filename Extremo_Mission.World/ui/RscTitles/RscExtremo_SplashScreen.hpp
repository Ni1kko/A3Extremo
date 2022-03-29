/*
	## EXTREMO
	## Nikko Renolds
*/

class RscExtremo_SplashScreen 
{
	idd = 12;
	onLoad = "uiNameSpace setVariable ['RscExtremo_SplashScreen', _this select 0]";
	onUnLoad = "uiNameSpace setVariable ['RscExtremo_SplashScreen', displayNull]";
	duration = 10e10;
	class controls {
		class Title: RscStatic {
			idc            = 1;
			text           = "";
			x              = "safezoneX";
			y              = "0.881986 * safezoneH + safezoneY";
			w              = "safezoneW";
			h              = "0.0506 * safezoneH";
			font           = "RobotoCondensedBold";
			sizeEx         = "0.04 * safezoneH";
			style          = 0x01;
		};
		class Subtitle: Title {
			idc            = 2;
			y              = "0.911941 * safezoneH + safezoneY";
			h              = "0.0418 * safezoneH";
			font           = "RobotoCondensed";
			sizeEx         = "0.025 * safezoneH";
		};
	};
	class controlsBackground {};
};