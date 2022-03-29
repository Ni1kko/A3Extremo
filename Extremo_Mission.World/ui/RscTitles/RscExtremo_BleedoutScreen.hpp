/*
	## EXTREMO
	## Nikko Renolds
*/

class RscExtremo_BleedoutScreen 
{
	idd = 10;
	fadein = 1;
	fadeout = 1;
	name = "RscExtremo_BleedoutScreen";
	onLoad = "uiNameSpace setVariable ['RscExtremo_BleedoutScreen', _this select 0]";
	onUnLoad = "uiNameSpace setVariable ['RscExtremo_BleedoutScreen', displayNull]";
	duration = 10e100;

	class controls 
	{
		class progressbar: RscProgress
		{
			idc = 1;
			x = GUI_GRID_X(7);
			y = GUI_GRID_Y(30.5);
			w = GUI_GRID_W(25.5);
			h = GUI_GRID_H(1.5);
			colorBackground[] = {0,0,0,0.5};
		};
		class title: RscStructuredText
		{
			idc = 2;
			x = GUI_GRID_X(5.5);
			y = GUI_GRID_Y(28.5);
			w = GUI_GRID_W(28.5);
			h = GUI_GRID_H(1.5);
		};
		class medic: RscStructuredText
		{
			idc = 3;
			x = GUI_GRID_X(42.5);
			y = GUI_GRID_Y(-10);
			w = GUI_GRID_W(25.5);
			h = GUI_GRID_H(1.5);
		};
	};

	class controlsBackground 
	{
		class background: IGUIBack
		{
			idc = -1;
			x = GUI_GRID_X(-28.5);
			y = GUI_GRID_Y(27);
			w = GUI_GRID_W(97);
			h = GUI_GRID_H(6.5);
			colorBackground[] = {0.3, 0.3, 0.3, 0.3};
		};
	};
};