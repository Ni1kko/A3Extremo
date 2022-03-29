/*
	## EXTREMO
	## Nikko Renolds
*/

class RscExtremo_LockScreen
{
	idd = 1100;
	movingEnabled = 0;
	enableSimulation = 1;
    
    //https://community.bistudio.com/wiki/User_Interface_Event_Handlers#onLoad
	onLoad="[_this,'onLoad'] call Extremo_fnc_gui_lockScreenEH";
	onUnload="[_this,'onUnload'] call Extremo_fnc_gui_lockScreenEH";
	onKeyUp="[_this,'onKeyUp'] call Extremo_fnc_gui_lockScreenEH";
	onKeyDown="[_this,'onKeyDown'] call Extremo_fnc_gui_lockScreenEH";
	class controlsBackground
	{
		class Background: RscPicture
		{
			text="ui\RscDisplays\Data\RscExtremo_LockScreen\images\background.paa";
			x="0.322396 * safezoneW + safezoneX";
			y="0.225 * safezoneH + safezoneY";
			w="0.355208 * safezoneW";
			h="0.55 * safezoneH";
		};
	};
	class controls
	{
		class NumFake: RscButton
		{
			idc=4013;
			x="1 * safezoneW + safezoneX";
			y="1 * safezoneH + safezoneY";
			w="0 * safezoneW";
			h="0 * safezoneH";
		};
		class Num0: RscButton
		{
			idc=4003;
			x="0.399167 * safezoneW + safezoneX";
			y="0.6694 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',0] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num1: RscButton
		{
			idc=4004;
			x="0.351042 * safezoneW + safezoneX";
			y="0.4494 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',1] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num2: RscButton
		{
			idc=4005;
			x="0.399167 * safezoneW + safezoneX";
			y="0.4494 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',2] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num3: RscButton
		{
			idc=4006;
			x="0.447291 * safezoneW + safezoneX";
			y="0.4494 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',3] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num4: RscButton
		{
			idc=4007;
			x="0.351042 * safezoneW + safezoneX";
			y="0.5242 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',4] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num5: RscButton
		{
			idc=4008;
			x="0.399167 * safezoneW + safezoneX";
			y="0.5242 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',5] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num6: RscButton
		{
			idc=4009;
			x="0.446145 * safezoneW + safezoneX";
			y="0.5242 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',6] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num7: RscButton
		{
			idc=4010;
			x="0.351042 * safezoneW + safezoneX";
			y="0.5968 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',7] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num8: RscButton
		{
			idc=4011;
			x="0.399167 * safezoneW + safezoneX";
			y="0.5968 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',8] call Extremo_fnc_gui_lockScreenEH";
		};
		class Num9: RscButton
		{
			idc=4012;
			x="0.446145 * safezoneW + safezoneX";
			y="0.5968 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',9] call Extremo_fnc_gui_lockScreenEH";
		};
		class Confirm: RscButton
		{
			idc=4000;
			x="0.351042 * safezoneW + safezoneX";
			y="0.6694 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			colorDisabled[]={1,1,1,0.40000001};
			onMouseButtonClick="[_this,'onMouseButtonClick',true] call Extremo_fnc_gui_lockScreenEH";
		};
		class Cancel: RscButton
		{
			idc=4002;
			x="0.446145 * safezoneW + safezoneX";
			y="0.6694 * safezoneH + safezoneY";
			w="0.0378126 * safezoneW";
			h="0.0572 * safezoneH";
			colorBackground[]={0.098039202,0.098039202,0.098039202,0};
			colorBackgroundActive[]={0.098039202,0.098039202,0.098039202,0.60000002};
            colorFocused[]= {0, 0, 0, 0};
			onMouseButtonClick="[_this,'onMouseButtonClick',false] call Extremo_fnc_gui_lockScreenEH";
		};
		class Screen: RscText
		{
			idc=4001;
			text="";
			colorText[]={0.070588201,0.133333,0.094117597,0.80000001};
			font="RobotoCondensed";
			style=2;
			x="0 * (0.025) + (0)";
			y="1.5 * (0.04) + (0)";
			w="40 * (0.025)";
			h="6 * (0.04)";
			sizeEx="2 * (0.04)";
			shadow=0;
		};
	};
};