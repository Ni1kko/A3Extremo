/*
	## EXTREMO
	## Nikko Renolds
*/

//--- SYSTEM
#define true 1
#define false 0
#define disabled -1

//--- UI (Fonts)
#define FONT_LIGHT    			"PuristaLight"
#define FONT_HEAVY    			"RobotoCondensed"
#define FONT_BOLD     			"RobotoCondensed"
#define FONT_ALT_LIGHT			"RobotoCondensed"
#define FONT_ALT_NORMAL 		"RobotoCondensed"
#define FONT_ALT_BOLD 			"RobotoCondensed"
#define FontM         			"Zeppelin32"

//--- UI (Colors)
#define COLOUR_MAINBACKGROUND           {0, 0, 0, 0.5}
#define COLOUR_HEADER                   {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "1"}
#define COLOUR_EMPTY                    {0, 0, 0, 0}
#define COLOUR_WHITE                    {1, 1, 1, 1}
#define COLOUR_PROGRESSBAR              {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "1"}
#define COLOUR_PROGRESSBAR_BACKGROUND   {"(profilenamespace getvariable ['IGUI_BCG_RGB_R',0])","(profilenamespace getvariable ['IGUI_BCG_RGB_G',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_B',1])","(profilenamespace getvariable ['IGUI_BCG_RGB_A',0.8])"}
#define COLOUR_AREABACKGROUND           {0.2,   0.2,   0.2,   1}
#define COLOUR_CONTENTTITLE             {0.05,  0.05,  0.05,  1}
#define COLOUR_CONTENTBACKGROUND        {0,     0,     0,     0.5}
#define COLOUR_INPUT                    {0,     0,     0,     0.4}
#define COLOUR_MAIN_PROFILENAMESPACE    {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.3843])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.7019])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.8862])", "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.7])"}
#define COLOUR_DEFAULTBUTTON            {0, 0, 0, 1}
#define COLOUR_DEFAULTBUTTONACTIVE      {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])", 1}
#define COLOUR_DEFAULTBUTTONDISABLED    {0, 0, 0, 0.5}
#define COLOUR_CONTENTBUTTON            {0, 0, 0, 1}
#define COLOUR_CONTENTBUTTONACTIVE      {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])", "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])", "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])", 1}
#define COLOUR_CONTENTBUTTONBLINK       {"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.77])","(profilenamespace getvariable ['GUI_BCG_RGB_G',0.51])","(profilenamespace getvariable ['GUI_BCG_RGB_B',0.08])",1}
#define COLOUR_CONTENTBUTTONDISABLED    {0, 0, 0, 0.5}

//--- UI (Sizes)
#define TEXT_SMALL            			"0.01 * safezoneH"
#define TEXT_SMALL1           			"0.015 * safezoneH"
#define TEXT_SMALL2           			"0.018 * safezoneH"
#define TEXT_NORMAL           			"0.02 * safezoneH"
#define TEXT_NORMAL1          			"0.025 * safezoneH"
#define TEXT_BIG              			"0.03 * safezoneH"
#define TEXT_VERYBIG          			"0.04 * safezoneH"
#define TEXT_SIZE_HEADER      			"0.020 * safezoneH"
#define TEXT_SIZE_SUBHEADER   			"0.018 * safezoneH"
#define TEXT_SIZE_TEXTBOX     			"0.0175 * safezoneH"
#define SIZE_BLOCK_HEADER 	   			 0.033 * safezoneH
#define SIZE_BLOCK_HEADER2 	   			 0.022 * safezoneH
#define TEXT_SIZE_CONTENTBUTTON       	 "0.018 * safezoneH"
#define SIZE_BLOCK_CONTENTBUTTON     	 "0.0198 * safezoneH"

//--- UI (Helpers)
#define GUI_GRID_X(GRID) 				(GRID * 0.0103125 + 0.29375) * safeZoneW + safeZoneX
#define GUI_GRID_Y(GRID) 				(GRID * 0.022 + 0.225) * safeZoneH + safeZoneY
#define GUI_GRID_W(GRID) 				(GRID * 0.0103125) * safeZoneW
#define GUI_GRID_H(GRID) 				(GRID * 0.022) * safeZoneH

//--- 	
#define SpawnIsland {6242.62,6495.94,0}