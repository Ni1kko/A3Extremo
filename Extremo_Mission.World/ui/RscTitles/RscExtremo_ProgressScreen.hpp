/*
	## EXTREMO
	## Nikko Renolds
*/

class RscExtremo_ProgressScreen 
{
	name = "RscExtremo_ProgressScreen";
	idd = 11;
	fadein = 1;
	duration = 99999999999;
	fadeout = 1;
	movingEnable = 0;
	onLoad="uiNamespace setVariable ['RscExtremo_ProgressScreen',_this select 0]";
	
	class controls {
		class actionTitle: RscStructuredText
		{
			idc = 3391;
			text = "<t align='center'>Loading...</t>";
			x = 0.360781 * safezoneW + safezoneX;
			y = 0.687 * safezoneH + safezoneY;
			w = 0.283594 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class progress: RscProgress
		{
			idc = 3390;
			x = 0.350469 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.304219 * safezoneW;
			h = 0.022 * safezoneH;
			colorFrame[] = {0, 0, 0, 0};
		};
		class progressTextBackground: RscStructuredText
		{
			idc = 3393;
			x = 0.350469 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.304219 * safezoneW;
			h = 0.022 * safezoneH;
			//colorBackground[] = {0, 0, 0, 0.3};
		};
		class actionTitleProgress: RscStructuredText
		{
			idc = 3392;
			text = "<t align='center'>100%</t>";
			x = 0.350469 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.304219 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class cancelInfo: RscStructuredText
		{
			idc = 1102;
			text = "<t align='center'>Press </t><t color='#C478DB' align='center'> [SPACE] </t><t align='center'> to cancel</t>";
			x = 0.360781 * safezoneW + safezoneX;
			y = 0.731 * safezoneH + safezoneY;
			w = 0.283594 * safezoneW;
			h = 0.022 * safezoneH;
		};
	};
};