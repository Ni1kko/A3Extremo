/*
	## EXTREMO Survival
	## Nikko & HappyFeet
*/

#define _ARMA_

//--- Patch
class CfgPatches
{
    class Extremo_Assets
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
			class author_1
			{
				name = "HappyFeet";
				uid = "76561198147157388";
				email = "Stephenallen1414@gmail.com";
				github = "github.com/Spodini";
			};
		};
		version = "1.0.72";
		requiredVersion=2.04;
		requiredAddons[]= {
			"a3_characters_f",
			"a3_characters_f_beta",
			"a3_characters_f_epa",
			"a3_characters_f_epb",
			"a3_characters_f_epc",
			"a3_characters_f_gamma",
			"a3_missions_f_oldman",
			"a3_characters_f_orange",
			"a3_characters_f_exp",
			"a3_characters_f_enoch",
			"a3_plants_f_bush",
			"a3_plants_f",
			"a3_data_f",
			"a3_weapons_f",
			"a3_weapons_f_beta",
			"a3_weapons_f_bootcamp",
			"a3_weapons_f_epa",
			"a3_weapons_f_epb",
			"a3_weapons_f_epc",
			"a3_weapons_f_gamma",
			"a3_rocks_f",
			"a3_anims_f",
			"a3_weapons_f_mark",
			"a3_weapons_f_exp",
			"a3_map_altis",
			"a3_map_stratis",
			"a3_map_enoch",
			"a3_map_malden",
			"a3_map_tanoabuka",
			"a3_map_altis_scenes",
			"a3_map_vr_scenes",
			"a3_map_stratis_scenes",
			"a3_ui_f",
			"a3_ui_f_aow",
			"a3_ui_f_bootcamp",
			"a3_ui_f_curator",
			"a3_ui_f_data",
			"a3_ui_f_enoch",
			"a3_ui_f_exp",
			"a3_ui_f_exp_a",
			"a3_ui_f_heli",
			"a3_ui_f_jets",
			"a3_ui_f_kart",
			"a3_ui_f_mark",
			"a3_ui_f_mp_mark",
			"a3_ui_f_oldman",
			"a3_ui_f_orange",
			"a3_ui_f_patrol",
			"a3_ui_f_tank",
			"a3_ui_f_tacops"/*,"a3_ui_f_contact"*/,
			"a3_3den",
			"a3_soft_f",
			"a3_cargoposes_f",
			"a3_functions_f",
			"a3_data_f_particleeffects"
		};
		units[] = {};
		weapons[]= {
			"arifle_MX_SW_F",
			"arifle_MX_SW_Black_F",
			"arifle_SPAR_02_blk_F",
			"arifle_SPAR_02_khk_F",
			"arifle_SPAR_02_snd_F",
			"MMG_01_hex_F",
			"MMG_01_tan_F",
			"MMG_02_camo_F",
			"MMG_02_black_F",
			"MMG_02_sand_F",
			"Throw"
		};
		magazines[]={};
		ammo[]={};
	};
};

//--- Addons
class CfgAddons
{
	class PreloadBanks { };
	class PreloadAddons
	{
		class Extremo_Expansion_Assets
		{
			list[]={ "A3_Map_Enoch", "A3_Map_Malden", "A3_Characters_F", "A3_Missions_F_Oldman", "A3_Characters_F_Orange", "A3_Characters_F_Exp", "A3_Characters_F_Enoch", "Extremo_Assets" };
		};
	};
};

//--- Abstracts
class Extremo_AbstractCraftingRecipe
{
	name = "";
	pictureItem = ""; 
	returnedItems[] = {};
	components[] = {};
	tools[] = {}; 
	requiredInteractionModelGroup = ""; 
	requiresOcean = 0; 
	requiresFire = 0; 
};
class ExtremoAbstractAction
{
	title = "";
	condition = "true";
	action = "";
	priority = 1.5;
	showWindow = false;
};

//--- Mod
class CfgMods
{
	class Mod_Base;
	class Extremo : Mod_Base
	{
		name="Extremo Survival Mod";
		author="Nikko";
		action="http://www.extremo.co.uk";
		dir="@ExtremoClient";
		logo="Extremo_Assets\texture\mod\logo.paa";
		logoOver="Extremo_Assets\texture\mod\logo.paa";
		logoSmall="Extremo_Assets\texture\mod\icon.paa";
		picture="Extremo_Assets\texture\mod\logo.paa";
		hidePicture=0;
		hideName=0;
		dlcColor[]={0.94,0.28999999,0.98000002,1};
		overview="Hardcore Survival Server";
		itemPrevNotifText="";
		class LoadingScreen
		{
			pictures[]={
				"Extremo_Assets\texture\loading\loading_axe_co.paa",
				"Extremo_Assets\texture\loading\loading_bigmomma_co.paa",
				"Extremo_Assets\texture\loading\loading_cement_co.paa",
				"Extremo_Assets\texture\loading\loading_cheathas_co.paa",
				"Extremo_Assets\texture\loading\loading_cockonut_co.paa",
				"Extremo_Assets\texture\loading\loading_codelock_co.paa",
				"Extremo_Assets\texture\loading\loading_concrete_mixer_co.paa",
				"Extremo_Assets\texture\loading\loading_dsnuts_co.paa",
				"Extremo_Assets\texture\loading\loading_emre_co.paa",
				"Extremo_Assets\texture\loading\loading_flag_co.paa",
				"Extremo_Assets\texture\loading\loading_foolbox_co.paa",
				"Extremo_Assets\texture\loading\loading_knife_co.paa",
				"Extremo_Assets\texture\loading\loading_laptop_co.paa",
				"Extremo_Assets\texture\loading\loading_metal_screws_co.paa",
				"Extremo_Assets\texture\loading\loading_moobar_co.paa",
				"Extremo_Assets\texture\loading\loading_pop_tabs_co.paa",
				"Extremo_Assets\texture\loading\loading_raisins_co.paa",
				"Extremo_Assets\texture\loading\loading_shovel_co.paa",
				"Extremo_Assets\texture\loading\loading_sledge_hammer_co.paa",
				"Extremo_Assets\texture\loading\loading_vishpirin_co.paa"
			};
			templateDefault = "<t>Your text here? Make a suggestion: </t><t color='#c72651'>www.extremo.co.uk/discord</t>";
			templates[]= { 
				{
					"9879821876, I'm sure you haven't read this number..",
					"maxicraft68"
				},
				{
					"[Insert funny loading screen joke here]",
					"polivilas"
				},
				{
					"A good bush for an ambush...",
					"Reaper7Strike"
				},
				{
					"Arma has stopped responding...",
					"Brett Nordin"
				},
				{
					"Attempting integer division by zero...",
					"eraser1"
				},
				{
					"Blowing up your vehicles...",
					"SomeRandomScorpion"
				},
				{
					"Constructing additional pylons...",
					"KrypTarch"
				},
				{
					"Deploying spike strips to bridges...",
					"dizzler"
				},
				{
					"Do you think it's going to load?",
					"[T.G] Razor"
				},
				{
					"Error Type Number, Not a Number, Expected Number, Number",
					"Grim"
				},
				{
					"Extremo_zombies.sqf failed to load",
					"Pustekuchen"
				},
				{
					"Hardening bushes...",
					"Gaina"
				},
				{
					"Hiding your backpack...",
					"Markkos"
				},
				{
					"Initializing 1000m-pistol-whipping AI...",
					"Major Mittens"
				},
				{
					"Initiating lag...",
					"Crazy Mike"
				},
				{
					"Injecting Backdoor Trojan...",
					"bambam"
				},
				{
					"Installing snapbuild...",
					"Mezo"
				},
				{
					"Kicked by BattlEye: Script Restriction #1337",
					"Mr Hanky"
				},
				{
					"Kurwa!",
					"Flosstradamus"
				},
				{
					"Learning how to Arma...",
					"ka0s"
				},
				{
					"Loading Bambi Slayers...",
					"GolovaRaoul"
				},
				{
					"Loading loading screen suggestions...",
					"ThatGuyYouKnow"
				},
				{
					"Loading next loading screen...",
					"Vodor"
				},
				{
					"Making another memory error",
					"SynysterDemon"
				},
				{
					"Mining Bitcoins to pay the server...",
					"XuluniX"
				},
				{
					"Point of No Return",
					"Commander Malc"
				},
				{
					"Prepare to rage quit...",
					"Spackler"
				},
				{
					"Releasing bugs back into their habitat...",
					"MadMoo"
				},
				{
					"Removing your workshop subscriptions...",
					"File_Delete"
				},
				{
					"Resetting your poptabs...",
					"Colonelfury"
				},
				{
					"Restarting for no reason...",
					"DarkWatcher"
				},
				{
					"Soon(TM)",
					"WolfkillArcadia"
				},
				{
					"Spawning inevitable death...",
					"KIMBOF1"
				},
				{
					"Spawning into crying corner...",
					"Magz"
				},
				{
					"WARNING: THIS GAME IS EARLY ACCESS ALPHA.",
					"BrainlessDude"
				},
				{
					"Wiping your virtual garage",
					"DB"
				},
				{
					"You have that read wrong",
					"Axl"
				},
				{
					"""What server does Frankie play on?""",
					"Shoritz"
				},
				{
					"Adding abusive admins",
					"Chris"
				},
				{
					"Attempting to utilize the GPU... Failed... Reverting to CPU...",
					"Tobias Solem"
				},
				{
					"Bad module error",
					"ComatoseBadger"
				},
				{
					"Booby trapping push bikes...",
					"HonestDave"
				},
				{
					"Can't answer the phone right now! I'm playing Arma!",
					"OG ThaGame"
				},
				{
					"Deploying Raiding Bandits...",
					"Zentarix"
				},
				{
					"Do you kno dawae?",
					"MonkeyNutz"
				},
				{
					"Don't ALT+TAB!",
					"Michaesine"
				},
				{
					"Emptying your locker...",
					"[KZ] Samfisher"
				},
				{
					"Error: Bambi Creation Timeout",
					"AdamKadmon"
				},
				{
					"Error: This game is no longer available",
					"Cooper"
				},
				{
					"Feeding horse for power...",
					"primedead"
				},
				{
					"Have you tried switching it off and on again?",
					"ExtremodVibe"
				},
				{
					"Headless client midlife crisis: Wants head back",
					"Antdooky"
				},
				{
					"Hey, WolfkillArcadia. Let me have a loading screen quote!",
					"Defent"
				},
				{
					"Hiding IEDs on the road...",
					"Aramet"
				},
				{
					"I got knife, let's steal... *dies at car*",
					"Reaper7Strike"
				},
				{
					"I have no problems on other servers",
					"James1st"
				},
				{
					"I should've read a tutorial...",
					"BushWuukie"
				},
				{
					"XM9 when?",
					"Ni1kko"
				}, 
				{
					"Loading Rage Quit Engine",
					"smokedog77"
				}, 
				{
					"Log in successful, informing raiders...",
					"Feary"
				},  
				{
					"Manufacturing wooden ammunition",
					"pticu"
				},
				{
					"No Keyboard Detected! Press F1 To Continue",
					"Captain_Bigzy"
				},
				{
					"Praying to the Loot God",
					"Twent"
				},
				{
					"Rooty Tooty, Point and Shooty!",
					"Demonic"
				},
				{
					"Server restart in 1 minute!",
					"Jarskie"
				},
				{
					"This is a Life server, right?",
					"FairyTale"
				},
				{
					"This is chaos",
					"AwezmTV"
				},
				{
					"This is not what I signed up for ",
					"UnknownWarrior"
				},
				{
					"This message intentionally left blank.",
					"Geekm0nkey"
				},
				{
					"This server is powered by a lemon and two electrodes.",
					"OMARCOMIN"
				},
				{
					"Trying to find the one safe spot",
					"pipin96"
				},
				{
					"Verify Integrity of Game Files...",
					"Helldog"
				},
				{
					"Your XM8 shut down unexpectedly. Please restart your PC.",
					"Przemek"
				},
				{
					"Throwing hand grenade at a rabbit...",
					"ass4assintim"
				},
				{
					"Milking the sheep",
					"Trap_God"
				},
				{
					"Just a fat little squirrel trying to get a nut",
					"chainsaw"
				},
				{
					"... Do not ping me with en random ... !!!",
					"Dwarden"
				},
				{
					"Stealing your Семечки",
					"Bambuz"
				},
				{
					"Randomizing PIN codes...",
					"Coldrice"
				},
				{
					"Installing OP Frying Pan",
					"Morty"
				},
				{
					"You need a little revive?",
					"Falinov"
				},
				{
					"Preparing to find THE way",
					"The Dude (chernaruski)"
				},
				{
					"Paying for WinRAR",
					"IPaidForWinRAR"
				}
			}; 
		}; 
	};

};

//--- Functions
class CfgFunctions 
{
	class A3
	{
		tag="BIS";
		project="arma3";
		class Ambient
		{
			file="Extremo_Assets\script\trashBin";
			class animalBehaviour{};
		};
		class Misc
		{
			delete progressLoadingScreen;
		};
		class BecauseArma
		{
			file="Extremo_Assets\script\trashBin";
			class progressLoadingScreen {};
		};
		class MP
		{
			file="Extremo_Assets\script\trashBin";
			class execFSM{};
			class execVM{};
			class execRemote{};
			class addScore{};
			class setRespawnDelay{};
			class onPlayerConnected{};
			class initPlayable{};
			class missionTimeLeft{};
			class MP{};
			class MPexec{};
			class initMultiplayer{};
			class call{};
			class spawn{};
			class deleteVehicleCrew{};
			class admin{};
		};
		class Scripts
		{
			file="Extremo_Assets\script";
			class rscHorizontalCompass{};
		};
	};
    class Extremo_Assets
    {
        class Client_Functions {
            file = "\Extremo_Assets"; 
            class preInit {preInit=1;};  
        };
    };
};

//--- Worlds
class CfgWorlds
{
	/*	
		## https://pmc.editing.wiki/doku.php?id=arma3:terrain:config.cpp
		## https://community.bistudio.com/wiki/Arma_3:_CfgWorlds_Config_Reference
	 	## https://community.bistudio.com/wiki/Arma_3:_Loading_Screens
	*/
	class CAWorld;
	class Altis: CAWorld
	{
		author = "Bohemia Interactive";
		description = "Altis Survival Map";
		pictureMap = "Extremo_Assets\texture\mod\logo.paa";
		pictureShot = "Extremo_Assets\texture\mod\logo.paa";
		previewVideo="Extremo_Assets\video\menu.ogv";
		loadingTexts[] = {"Hardcore Survival Server"};
		cutscenes[]= {"Altis_intro1"};
		worldName="\A3\map_Altis\Altis.wrp";
		newRoadsShape="\A3\Map_Altis\data\roads\roads.shp";
		startTime="12:00";
		startDate="1/1/2021";
		class AmbientA3
		{
			class Radius440_500
			{
				spawnInterval=99999;
				class Species
				{
					delete Kestrel_random_F;
					delete Rabbit_F;
					class Seagull
					{
						maxCircleCount="((sea * (1 - night)) + (2 * houses * sea)) * (1 - night)";
						maxWorldCount=20;
						cost=3;
						spawnCount=1;
						groupSpawnRadius=10;
						maxAlt=450;
						minAlt=-10;
					};
				};
			};
			class Radius40_60
			{
				spawnInterval=99999;
				class Species
				{
					delete CatShark_F;
					delete Mackerel_F;
					delete Mullet_F;
					delete Ornate_random_F;
					delete Salema_F;
					delete Snake_random_F;
					delete Tuna_F;
					delete Turtle_F;
				};
			};
			class Radius30_40
			{
				spawnInterval=99999;
				class Species
				{
					delete DragonFly;
					delete ButterFly_random;
					delete Cicada;
				};
			};
			class Radius15_20
			{
				areaSpawnRadius=15;
				areaMaxRadius=20;
				spawnCircleRadius=2;
				spawnInterval=2.8499999;
				class Species
				{
					class FxWindGrass1
					{
						maxCircleCount="2 * (1 - (WaterDepth interpolate [1,30,0,1])) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount=3;
						cost=1;
						spawnCount=3;
						groupSpawnRadius=2.5;
						maxAlt=30;
						minAlt=-5;
					};
					class FxWindGrass2
					{
						maxCircleCount="2 * (1 - (WaterDepth interpolate [1,30,0,1])) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount=3;
						cost=1;
						spawnCount=3;
						groupSpawnRadius=2.5;
						maxAlt=30;
						minAlt=-5;
					};
					class FxWindLeaf1
					{
						maxCircleCount="2 * (trees + 0.5) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount=3;
						cost=1;
						spawnCount=3;
						groupSpawnRadius=2.5;
						maxAlt=30;
						minAlt=-5;
					};
					class FxWindLeaf2
					{
						maxCircleCount="2 * (trees + 0.5) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount=3;
						cost=1;
						spawnCount=3;
						groupSpawnRadius=2.5;
						maxAlt=30;
						minAlt=-5;
					};
					class FxWindLeaf3
					{
						maxCircleCount="2 * (trees + 0.5) * (windy interpolate [0.1,0.25,0,1])";
						maxWorldCount=3;
						cost=1;
						spawnCount=3;
						groupSpawnRadius=2.5;
						maxAlt=30;
						minAlt=-5;
					};
					class FxWindPollen1
					{
						maxCircleCount="(3 * (1 - (WaterDepth interpolate [1,30,0,1]))) * (windy interpolate [0.05,0.15,0,1])";
						maxWorldCount=6;
						cost=1;
						spawnCount=1;
						groupSpawnRadius=1;
						maxAlt=30;
						minAlt=-5;
					};
					delete FxWindPaper1;
					delete FxWindPlastic1;
				};
			};
			class Radius6_10
			{
				spawnInterval=99999;
				class Species
				{
					delete HoneyBee;
					delete HouseFly;
					delete Mosquito;
				};
			};
		};
		class Names
		{
			class CityC_Kavala
			{
				name="";
				position[]={3620.3899,13092.82};
				type="CityCenter";
				demography="CIV";
				radiusA=200;
				radiusB=200;
				angle=0;
			};
			class Aggelochori
			{
				name="$STR_A3_Aggelochori0";
				position[]={3687.78,13776.09};
				type="NameVillage";
				demography="CIV";
				radiusA=400;
				radiusB=100;
				angle=0;
			};
			class Neri
			{
				name="$STR_A3_Neri0";
				position[]={4116.1099,11736.1};
				type="NameVillage";
				demography="CIV";
				radiusA=400;
				radiusB=170;
				angle=0;
			};
			class Panochori
			{
				name="$STR_A3_Panochori0";
				position[]={5033.3101,11245.22};
				type="NameVillage";
				demography="CIV";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class Zaros
			{
				name="$STR_A3_Zaros0";
				position[]={9091.8096,11961.87};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class Therisa
			{
				name="$STR_A3_Therisa0";
				position[]={10618.88,12237.26};
				type="NameVillage";
				demography="CIV";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class Katalaki
			{
				name="$STR_A3_Katalaki0";
				position[]={11701.06,13672.14};
				type="NameVillage";
				demography="CIV";
				radiusA=450;
				radiusB=200;
				angle=0;
			};
			class Neochori
			{
				name="$STR_A3_Neochori0";
				position[]={12501.97,14337.03};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Stavros
			{
				name="$STR_A3_Stavros0";
				position[]={12950.06,15041.63};
				type="NameVillage";
				demography="CIV";
				radiusA=400;
				radiusB=250;
				angle=0;
			};
			class Lakka
			{
				name="$STR_A3_Lakka0";
				position[]={12281.97,15732.27};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class Alikampos
			{
				name="$STR_A3_Alikampos0";
				position[]={11112.63,14573.65};
				type="NameVillage";
				demography="CIV";
				radiusA=450;
				radiusB=250;
				angle=0;
			};
			class AgiosDionysios
			{
				name="$STR_A3_AgiosDionysios0";
				position[]={9187.9502,15947.84};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class Kore
			{
				name="$STR_A3_Kore0";
				position[]={7062.4199,16472.119};
				type="NameCity";
				demography="CIV";
				radiusA=371.91;
				radiusB=447.25;
				angle=0;
			};
			class Negades
			{
				name="$STR_A3_Negades0";
				position[]={4885.98,16171.33};
				type="NameVillage";
				demography="CIV";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class AgiosKonstantinos
			{
				name="$STR_A3_AgiosKonstantinos0";
				position[]={3948.77,17277.85};
				type="NameVillage";
				demography="CIV";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class Topolia
			{
				name="$STR_A3_Topolia0";
				position[]={7375.8101,15429.51};
				type="NameVillage";
				demography="CIV";
				radiusA=400;
				radiusB=100;
				angle=0;
			};
			class Gravia
			{
				name="$STR_A3_Gravia0";
				position[]={14479.81,17614.301};
				type="NameCity";
				demography="CIV";
				radiusA=734.48999;
				radiusB=250;
				angle=0;
			};
			class Athira
			{
				name="$STR_A3_Athira0";
				position[]={13993,18709.381};
				type="NameCityCapital";
				demography="CIV";
				radiusA=500;
				radiusB=306.88;
				angle=0;
			};
			class Frini
			{
				name="$STR_A3_Frini0";
				position[]={14612.45,20786.711};
				type="NameCity";
				demography="CIV";
				radiusA=270.57999;
				radiusB=325.38;
				angle=0;
			};
			class Ifestiona
			{
				name="$STR_A3_Ifestiona0";
				position[]={12786.98,19679.311};
				type="NameVillage";
				demography="CIV";
				radiusA=500;
				radiusB=176.64;
				angle=0;
			};
			class Syrta
			{
				name="$STR_A3_Syrta0";
				position[]={8625.1299,18301.561};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Galati
			{
				name="$STR_A3_Galati0";
				position[]={10270.28,19036.01};
				type="NameVillage";
				demography="CIV";
				radiusA=629.96002;
				radiusB=250;
				angle=0;
			};
			class Koroni
			{
				name="$STR_A3_Koroni0";
				position[]={11786.73,18372.391};
				type="NameVillage";
				demography="CIV";
				radiusA=500;
				radiusB=329.01001;
				angle=0;
			};
			class Abdera
			{
				name="$STR_A3_Abdera0";
				position[]={9425.4199,20284.029};
				type="NameVillage";
				demography="CIV";
				radiusA=453.26999;
				radiusB=250;
				angle=0;
			};
			class Telos
			{
				name="$STR_A3_Telos0";
				position[]={16207.02,17296.711};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Anthrakia
			{
				name="$STR_A3_Anthrakia0";
				position[]={16584.26,16103.96};
				type="NameVillage";
				demography="CIV";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Kalithea
			{
				name="$STR_A3_Kalithea0";
				position[]={17826.51,18129.369};
				type="NameVillage";
				demography="CIV";
				radiusA=300;
				radiusB=120;
				angle=0;
			};
			class AgiosPetros
			{
				name="$STR_A3_AgiosPetros0";
				position[]={19339.42,17641.619};
				type="NameVillage";
				demography="CIV";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class Paros
			{
				name="$STR_A3_Paros0";
				position[]={20885.391,16958.76};
				type="NameCity";
				demography="CIV";
				radiusA=450;
				radiusB=180;
				angle=0;
			};
			class Kalochori
			{
				name="$STR_A3_Kalochori0";
				position[]={21351.58,16361.88};
				type="NameCity";
				demography="CIV";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class Sofia
			{
				name="$STR_A3_Sofia0";
				position[]={25680.529,21365.08};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Molos
			{
				name="$STR_A3_Molos0";
				position[]={26943.859,23170.68};
				type="NameCity";
				demography="CIV";
				radiusA=350;
				radiusB=200;
				angle=0;
			};
			class Ioannina
			{
				name="$STR_A3_Ioannina0";
				position[]={23199.68,19986.6};
				type="NameVillage";
				demography="CIV";
				radiusA=350;
				radiusB=120;
				angle=0;
			};
			class Delfinaki
			{
				name="$STR_A3_Delfinaki0";
				position[]={23908.6,20144.73};
				type="NameVillage";
				demography="CIV";
				radiusA=350;
				radiusB=140;
				angle=0;
			};
			class Nifi
			{
				name="$STR_A3_Nifi0";
				position[]={19473.33,15453.65};
				type="NameVillage";
				demography="CIV";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class Charkia
			{
				name="$STR_A3_Charkia0";
				position[]={18049.08,15264.07};
				type="NameCity";
				demography="CIV";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class Dorida
			{
				name="$STR_A3_Dorida0";
				position[]={19336.869,13252.28};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class Chalkeia
			{
				name="$STR_A3_Chalkeia0";
				position[]={20194.641,11660.69};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class Panagia
			{
				name="$STR_A3_Panagia0";
				position[]={20490.18,8907.1201};
				type="NameVillage";
				demography="CIV";
				radiusA=300;
				radiusB=110;
				angle=0;
			};
			class Feres
			{
				name="$STR_A3_Feres0";
				position[]={21640.721,7583.9302};
				type="NameVillage";
				demography="CIV";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class Selakano
			{
				name="$STR_A3_Selakano0";
				position[]={20769.779,6736.46};
				type="NameVillage";
				demography="CIV";
				radiusA=350;
				radiusB=120;
				angle=0;
			};
			class Pyrgos
			{
				name="$STR_A3_Pyrgos0";
				position[]={16780.609,12604.47};
				type="NameCityCapital";
				demography="CIV";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class CityC_Neri
			{
				name="";
				position[]={4183.1299,11743.95};
				type="CityCenter";
				demography="CIV";
				radiusA=100;
				radiusB=100;
				angle=0;
			};
			class CityC_AgiosDionysios
			{
				name="";
				position[]={9287.6602,15858.07};
				type="CityCenter";
				demography="CIV";
				radiusA=235.06;
				radiusB=264.04999;
				angle=0;
			};
			class CityC_Katalakes
			{
				name="";
				position[]={9459.6201,20281.93};
				type="CityCenter";
				demography="CIV";
				radiusA=213.45;
				radiusB=239.78;
				angle=0;
			};
			class Kavala
			{
				name="Extremo Capital";
				position[]={3458.95,12966.37};
				type="NameCityCapital";
				demography="CIV";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class Poliakko
			{
				name="$STR_A3_Poliakko0";
				position[]={10966.47,13435.28};
				type="NameCity";
				demography="CIV";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Bomos
			{
				name="$STR_A3_Bomos0";
				position[]={2307.3101,22165.18};
				type="NameLocal";
				radiusA=600;
				radiusB=250;
				angle=0;
			};
			class Oreokastro
			{
				name="$STR_A3_Oreokastro0";
				position[]={4560.4502,21460.641};
				type="NameVillage";
				radiusA=800;
				radiusB=300;
				angle=0;
			};
			class castle
			{
				name="$STR_A3_castle0";
				position[]={4802.9902,21855.49};
				type="NameLocal";
				radiusA=500;
				radiusB=300;
				angle=0;
			};
			class Thronos
			{
				name="$STR_A3_Thronos0";
				position[]={4919.3198,21951.74};
				type="Hill";
				radiusA=346.59;
				radiusB=263.04001;
				angle=0;
			};
			class Faros
			{
				name="$STR_A3_Faros0";
				position[]={6565.2998,22639.109};
				type="NameLocal";
				radiusA=433.23999;
				radiusB=328.79999;
				angle=0;
			};
			class dump
			{
				name="$STR_A3_dump0";
				position[]={5887.1299,20236.48};
				type="NameLocal";
				radiusA=277.26999;
				radiusB=210.42999;
				angle=0;
			};
			class Synneforos
			{
				name="$STR_A3_Synneforos0";
				position[]={6513.79,21604.699};
				type="Hill";
				radiusA=600;
				radiusB=250;
				angle=0;
			};
			class Aristi
			{
				name="$STR_A3_Aristi0";
				position[]={7914.0498,21305.189};
				type="NameLocal";
				radiusA=277.26999;
				radiusB=210.42999;
				angle=0;
			};
			class Fotia
			{
				name="$STR_A3_Fotia0";
				position[]={2993.48,18517.359};
				type="NameLocal";
				radiusA=260.95999;
				radiusB=198.05;
				angle=0;
			};
			class hill01
			{
				name="";
				position[]={4162.73,19455.529};
				type="Hill";
				radiusA=350;
				radiusB=350;
				angle=0;
			};
			class Hill02
			{
				name="$STR_A3_Hill020";
				position[]={4808.1802,17694.35};
				type="Hill";
				radiusA=500;
				radiusB=300;
				angle=0;
			};
			class Gori
			{
				name="$STR_A3_Gori0";
				position[]={5455.7202,17553.66};
				type="NameLocal";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class AgiosMinas
			{
				name="$STR_A3_AgiosMinas0";
				position[]={7846.96,18005.439};
				type="Hill";
				radiusA=600;
				radiusB=300;
				angle=0;
			};
			class Pyrsos
			{
				name="$STR_A3_Pyrsos0";
				position[]={9127.0996,19271.65};
				type="Hill";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class hill03
			{
				name="";
				position[]={10748.89,20401};
				type="Hill";
				radiusA=250;
				radiusB=250;
				angle=0;
			};
			class KryaNera
			{
				name="$STR_A3_KryaNera0";
				position[]={9681.5801,22294.49};
				type="NameLocal";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class hill04
			{
				name="";
				position[]={14574.43,21994.801};
				type="Hill";
				radiusA=250;
				radiusB=250;
				angle=0;
			};
			class CapAgrios
			{
				name="$STR_A3_CapAgrios0";
				position[]={14688.23,23496.23};
				type="NameLocal";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Nychi
			{
				name="$STR_A3_Nychi0";
				position[]={16837.42,21889.99};
				type="NameLocal";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class factory01
			{
				name="$STR_A3_factory040";
				position[]={14294.59,18928.49};
				type="NameLocal";
				radiusA=250;
				radiusB=200;
				angle=0;
			};
			class AgiaTriada
			{
				name="$STR_A3_AgiaTriada0";
				position[]={16668.5,20487.029};
				type="NameVillage";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class Orino
			{
				name="$STR_A3_Orino0";
				position[]={10410.36,17243.119};
				type="NameVillage";
				radiusA=450;
				radiusB=200;
				angle=0;
			};
			class military01
			{
				name="$STR_A3_military010";
				position[]={12771.58,16694.289};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class factory02
			{
				name="$STR_A3_factory040";
				position[]={12577.36,16352.75};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class airbase01
			{
				name="$STR_A3_airbase010";
				position[]={14037.58,16143.33};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class terminal01
			{
				name="$STR_A3_terminal010";
				position[]={14522.41,16833.949};
				type="NameLocal";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class military02
			{
				name="$STR_A3_military010";
				position[]={15137.16,17297.801};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class military03
			{
				name="$STR_A3_military010";
				position[]={16030.42,17004.84};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class PowerPlant01
			{
				name="$STR_A3_PowerPlant020";
				position[]={15420.83,16223.64};
				type="NameLocal";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Amfissa
			{
				name="$STR_A3_Amfissa0";
				position[]={8088.8101,17257.66};
				type="NameLocal";
				radiusA=200;
				radiusB=150;
				angle=0;
			};
			class Amoni
			{
				name="$STR_A3_Amoni0";
				position[]={7859.98,16673.561};
				type="Hill";
				radiusA=300;
				radiusB=200;
				angle=0;
			};
			class factory03
			{
				name="$STR_A3_factory040";
				position[]={6109.4902,16246.18};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class Stadium
			{
				name="$STR_A3_Stadium0";
				position[]={5429.6899,14996.68};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class factory04
			{
				name="$STR_A3_factory040";
				position[]={5307.1201,14500.11};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class hill05
			{
				name="$STR_A3_hill050";
				position[]={9187.7402,11502.53};
				type="Hill";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class XirolimniDam
			{
				name="$STR_A3_XirolimniDam0";
				position[]={9115.2197,13959.85};
				type="NameLocal";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class AgiaStemma
			{
				name="$STR_A3_AgiaStemma0";
				position[]={7883.5801,14626.41};
				type="Hill";
				radiusA=509.67999;
				radiusB=386.82001;
				angle=0;
			};
			class AACairfield
			{
				name="$STR_A3_AACairfield0";
				position[]={11461.19,11661.67};
				type="NameLocal";
				radiusA=350;
				radiusB=150;
				angle=0;
			};
			class Drimea
			{
				name="$STR_A3_Drimea0";
				position[]={10781.89,10881.59};
				type="NameLocal";
				radiusA=450;
				radiusB=200;
				angle=0;
			};
			class Kastro
			{
				name="$STR_A3_Kastro0";
				position[]={3041.3999,13162.75};
				type="NameLocal";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class KavalaPier
			{
				name="$STR_A3_KavalaPier0";
				position[]={3014.8301,12587.34};
				type="NameLocal";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class PowerPlant02
			{
				name="$STR_A3_PowerPlant020";
				position[]={4163.6001,15047.23};
				type="NameLocal";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class Magos
			{
				name="$STR_A3_Magos0";
				position[]={4564.7202,15393.25};
				type="Hill";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class quarry01
			{
				name="$STR_A3_quarry020";
				position[]={4379.1499,12594.37};
				type="NameLocal";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class SavriIsland
			{
				name="$STR_A3_SavriIsland0";
				position[]={2370.95,11507.01};
				type="NameLocal";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class CapDrakontas
			{
				name="$STR_A3_CapDrakontas0";
				position[]={2657.3201,11461.45};
				type="NameLocal";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class FournosIsland
			{
				name="$STR_A3_FournosIsland0";
				position[]={2313.6699,9289.3096};
				type="NameLocal";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class Athanos
			{
				name="$STR_A3_Athanos0";
				position[]={3571.22,10243.74};
				type="NameLocal";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class Edoris
			{
				name="$STR_A3_Edoris0";
				position[]={6002.75,10511.37};
				type="NameLocal";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class hill06
			{
				name="";
				position[]={4188.9902,10754.86};
				type="Hill";
				radiusA=200;
				radiusB=200;
				angle=0;
			};
			class hill07
			{
				name="";
				position[]={5320.3101,10316.03};
				type="Hill";
				radiusA=200;
				radiusB=200;
				angle=0;
			};
			class Tafos
			{
				name="$STR_A3_Tafos0";
				position[]={5588.8599,11749.69};
				type="Hill";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class hill08
			{
				name="";
				position[]={6405.6899,12365.63};
				type="Hill";
				radiusA=200;
				radiusB=200;
				angle=0;
			};
			class AgiosPanagiotis
			{
				name="$STR_A3_AgiosPanagiotis0";
				position[]={6272.75,12173.9};
				type="NameLocal";
				radiusA=450;
				radiusB=150;
				angle=0;
			};
			class dump02
			{
				name="$STR_A3_dump0";
				position[]={5900.4702,12454.43};
				type="NameLocal";
				radiusA=200;
				radiusB=150;
				angle=0;
			};
			class Kavirida
			{
				name="$STR_A3_Kavirida0";
				position[]={7324.2402,12125.41};
				type="NameLocal";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class Edessa
			{
				name="$STR_A3_Edessa0";
				position[]={7194.23,11043.95};
				type="NameLocal";
				radiusA=300;
				radiusB=130;
				angle=0;
			};
			class hill09
			{
				name="";
				position[]={7048.1001,14070.4};
				type="Hill";
				radiusA=200;
				radiusB=200;
				angle=0;
			};
			class AtsalisIsland
			{
				name="$STR_A3_AtsalisIsland0";
				position[]={8304.8301,25081.221};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class Vikos
			{
				name="$STR_A3_Vikos0";
				position[]={11556.89,9417.0596};
				type="NameLocal";
				radiusA=250;
				radiusB=100;
				angle=0;
			};
			class Agela
			{
				name="$STR_A3_Agela0";
				position[]={9186.3398,8388.4404};
				type="Hill";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class hill10
			{
				name="";
				position[]={10729.75,7615.71};
				type="Hill";
				radiusA=200;
				radiusB=200;
				angle=0;
			};
			class Skopos
			{
				name="$STR_A3_Skopos0";
				position[]={11668.95,7579.9102};
				type="Hill";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class CapMakrinos
			{
				name="$STR_A3_CapMakrinos0";
				position[]={14225.87,6237.9902};
				type="NameLocal";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class PyrgiIsland
			{
				name="$STR_A3_PyrgiIsland0";
				position[]={14489.94,5871.7002};
				type="NameLocal";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class Eginio
			{
				name="$STR_A3_Eginio0";
				position[]={11549.17,7088.3901};
				type="NameLocal";
				radiusA=300;
				radiusB=200;
				angle=0;
			};
			class Sfaka
			{
				name="$STR_A3_Sfaka0";
				position[]={9213.9502,8079.0298};
				type="NameLocal";
				radiusA=300;
				radiusB=150;
				angle=0;
			};
			class AgiosKosmas
			{
				name="$STR_A3_AgiosKosmas0";
				position[]={8555.3203,7335.5098};
				type="NameLocal";
				radiusA=260.95999;
				radiusB=100;
				angle=0;
			};
			class MonisiIsland
			{
				name="$STR_A3_MonisiIsland0";
				position[]={7813.3599,7641.1899};
				type="NameLocal";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class MakrynisiIsland
			{
				name="$STR_A3_MakrynisiIsland0";
				position[]={13471.94,12018.51};
				type="NameLocal";
				radiusA=400;
				radiusB=250;
				angle=0;
			};
			class SagonisiIsland
			{
				name="$STR_A3_SagonisiIsland0";
				position[]={14281.17,13469.27};
				type="NameLocal";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class ChelonisiIsland
			{
				name="$STR_A3_ChelonisiIsland0";
				position[]={16636.539,13582.2};
				type="NameLocal";
				radiusA=400;
				radiusB=100;
				angle=0;
			};
			class Faronaki
			{
				name="$STR_A3_Faronaki0";
				position[]={14934.42,11079.48};
				type="NameLocal";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class Ekali
			{
				name="$STR_A3_Ekali0";
				position[]={17059.711,9992.3203};
				type="NameVillage";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class hill11
			{
				name="";
				position[]={16535.98,10787.18};
				type="Hill";
				radiusA=200;
				radiusB=200;
				angle=0;
			};
			class Didymos
			{
				name="$STR_A3_Didymos0";
				position[]={17768.881,9914.4102};
				type="Hill";
				radiusA=200;
				radiusB=100;
				angle=0;
			};
			class hill12
			{
				name="";
				position[]={18832.08,10222.03};
				type="Hill";
				radiusA=200;
				radiusB=200;
				angle=0;
			};
			class Aktinarki
			{
				name="$STR_A3_Aktinarki0";
				position[]={21449.939,10873.76};
				type="NameLocal";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class Trachia
			{
				name="$STR_A3_Trachia0";
				position[]={22128.141,8453.9805};
				type="NameLocal";
				radiusA=200;
				radiusB=80;
				angle=0;
			};
			class AgiaPelagia
			{
				name="$STR_A3_AgiaPelagia0";
				position[]={22707.59,6930.5698};
				type="NameLocal";
				radiusA=350;
				radiusB=120;
				angle=0;
			};
			class Mazi
			{
				name="$STR_A3_Mazi0";
				position[]={21772.43,6014.5298};
				type="NameLocal";
				radiusA=150;
				radiusB=100;
				angle=0;
			};
			class Livadi
			{
				name="$STR_A3_Livadi0";
				position[]={18410.51,8098.2998};
				type="NameLocal";
				radiusA=150;
				radiusB=60;
				angle=0;
			};
			class CapKategidis
			{
				name="$STR_A3_CapKategidis0";
				position[]={22792,13638.38};
				type="NameLocal";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class SufrClub
			{
				name="$STR_A3_SufrClub0";
				position[]={21339.369,10434.01};
				type="NameLocal";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class Limni
			{
				name="$STR_A3_Limni0";
				position[]={20920.789,14775.38};
				type="NameLocal";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class Ochrolimni
			{
				name="$STR_A3_Ochrolimni0";
				position[]={23650.08,16227.26};
				type="NameLocal";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class CapThelos
			{
				name="$STR_A3_CapThelos0";
				position[]={24067.6,15560.25};
				type="NameLocal";
				radiusA=500;
				radiusB=250;
				angle=0;
			};
			class Zeloran
			{
				name="$STR_A3_Zeloran0";
				position[]={17043.461,19592.15};
				type="NameLocal";
				radiusA=150;
				radiusB=60;
				angle=0;
			};
			class quarry02
			{
				name="$STR_A3_quarry020";
				position[]={17060.539,11339.1};
				type="NameLocal";
				radiusA=260.95999;
				radiusB=198.05;
				angle=0;
			};
			class storage01
			{
				name="$STR_A3_storage010";
				position[]={18260.609,15551.22};
				type="NameLocal";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class quarry03
			{
				name="$STR_A3_quarry020";
				position[]={19566.391,15617.26};
				type="NameLocal";
				radiusA=300;
				radiusB=120;
				angle=0;
			};
			class Rodopoli
			{
				name="$STR_A3_Rodopoli0";
				position[]={18753.41,16597.119};
				type="NameCity";
				radiusA=500;
				radiusB=300;
				angle=0;
			};
			class CapZefyris
			{
				name="$STR_A3_CapZefyris0";
				position[]={18049.34,19186.59};
				type="NameLocal";
				radiusA=450;
				radiusB=150;
				angle=0;
			};
			class AgiosGeorgios
			{
				name="$STR_A3_AgiosGeorgios0";
				position[]={20296.27,18635.09};
				type="NameLocal";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class Almyra
			{
				name="$STR_A3_Almyra0";
				position[]={23495.561,18392.6};
				type="NameLocal";
				radiusA=400;
				radiusB=250;
				angle=0;
			};
			class Iraklia
			{
				name="$STR_A3_Iraklia0";
				position[]={21628.32,21274.939};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class military04
			{
				name="$STR_A3_military010";
				position[]={23533.16,21107.99};
				type="NameLocal";
				radiusA=300;
				radiusB=120;
				angle=0;
			};
			class Nidasos
			{
				name="$STR_A3_Nidasos0";
				position[]={23662.9,21796.08};
				type="NameLocal";
				radiusA=300;
				radiusB=100;
				angle=0;
			};
			class military05
			{
				name="$STR_A3_military010";
				position[]={25350.641,21790.859};
				type="NameLocal";
				radiusA=400;
				radiusB=100;
				angle=0;
			};
			class Skiptro
			{
				name="$STR_A3_Skiptro0";
				position[]={24833.859,21802.1};
				type="Hill";
				radiusA=250;
				radiusB=100;
				angle=0;
			};
			class PowerPlant03
			{
				name="$STR_A3_PowerPlant020";
				position[]={25462.631,20357.66};
				type="NameLocal";
				radiusA=500;
				radiusB=200;
				angle=0;
			};
			class Gatolia
			{
				name="$STR_A3_Gatolia0";
				position[]={26723.01,21230.33};
				type="NameLocal";
				radiusA=220;
				radiusB=100;
				angle=0;
			};
			class Polemistia
			{
				name="$STR_A3_Polemistia0";
				position[]={27998.57,23775.75};
				type="NameLocal";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class MolosAirfield
			{
				name="$STR_A3_MolosAirfield0";
				position[]={26939.82,24743.811};
				type="NameLocal";
				radiusA=400;
				radiusB=100;
				angle=0;
			};
			class Limnichori
			{
				name="$STR_A3_Limnichori0";
				position[]={25703.65,23561.58};
				type="NameLocal";
				radiusA=400;
				radiusB=100;
				angle=0;
			};
			class CapStrigla
			{
				name="$STR_A3_CapStrigla0";
				position[]={28059.23,25626.369};
				type="NameLocal";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class Sideras
			{
				name="$STR_A3_Sideras0";
				position[]={23274.539,24198.301};
				type="NameLocal";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class AgiosAndreas
			{
				name="$STR_A3_AgiosAndreas0";
				position[]={23682.881,24239.26};
				type="Hill";
				radiusA=400;
				radiusB=100;
				angle=0;
			};
			class NeriBay
			{
				name="$STR_A3_NeriBay0";
				position[]={3166,11234.17};
				type="NameMarine";
				radiusA=400;
				radiusB=200;
				angle=0;
			};
			class KavalaBay
			{
				name="$STR_A3_KavalaBay0";
				position[]={3004.5801,13675.91};
				type="NameMarine";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class NegadesBay
			{
				name="$STR_A3_NegadesBay0";
				position[]={3458.04,16859.631};
				type="NameMarine";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class PanochoriBay
			{
				name="$STR_A3_PanochoriBay0";
				position[]={4005.29,9908.5898};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class IremiBay
			{
				name="$STR_A3_IremiBay0";
				position[]={5117.6299,9761.5};
				type="NameMarine";
				radiusA=400;
				radiusB=150;
				angle=0;
			};
			class EdessaBay
			{
				name="$STR_A3_EdessaBay0";
				position[]={6862.3301,10614.14};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class ZarosBay
			{
				name="$STR_A3_ZarosBay0";
				position[]={9210.6602,10250.45};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class NaftiaBay
			{
				name="$STR_A3_NaftiaBay0";
				position[]={12157.59,6376.2402};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class MelaneraBay
			{
				name="$STR_A3_MelaneraBay0";
				position[]={11226.19,10574.7};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class KatalakiBay
			{
				name="$STR_A3_KatalakiBay0";
				position[]={12269.85,13659.34};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class PyrgosGulf
			{
				name="$STR_A3_PyrgosGulf0";
				position[]={15139.24,14229.94};
				type="NameMarine";
				radiusA=600;
				radiusB=200;
				angle=0;
			};
			class MaziBay
			{
				name="$STR_A3_MaziBay0";
				position[]={22181.439,6154.23};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class ChalkeiaBay
			{
				name="$STR_A3_ChalkeiaBay0";
				position[]={21859.609,12594.88};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class ThelosBay
			{
				name="$STR_A3_ThelosBay0";
				position[]={22979.689,14938.95};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class MolosBay
			{
				name="$STR_A3_MolosBay0";
				position[]={27826.85,24244.449};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class GalanaNeraBay
			{
				name="$STR_A3_GalanaNeraBay0";
				position[]={24924.08,24206.551};
				type="NameMarine";
				radiusA=690;
				radiusB=150;
				angle=0;
			};
			class PefkasBay
			{
				name="$STR_A3_PefkasBay0";
				position[]={21204.699,20464.641};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class KalitheaBay
			{
				name="$STR_A3_KalitheaBay0";
				position[]={18160.961,18676.631};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class TonosBay
			{
				name="$STR_A3_TonosBay0";
				position[]={11988.3,22985.67};
				type="NameMarine";
				radiusA=260.95999;
				radiusB=198.05;
				angle=0;
			};
			class AmmolofiBay
			{
				name="$STR_A3_AmmolofiBay0";
				position[]={9525.4404,22649.01};
				type="NameMarine";
				radiusA=500;
				radiusB=150;
				angle=0;
			};
			class Mine01
			{
				name="$STR_A3_Mine010";
				position[]={18435.119,14301.76};
				type="NameLocal";
				radiusA=200;
				radiusB=100;
				angle=0;
			};
		};
	};
	class Stratis: CAWorld
	{
		author = "Bohemia Interactive";
		description = "Stratis Survival Map";
		pictureMap = "Extremo_Assets\texture\mod\logo.paa";
		pictureShot = "Extremo_Assets\texture\mod\logo.paa";
		previewVideo="Extremo_Assets\video\menu.ogv";
		loadingTexts[] = {"Hardcore Survival Server"};
	};
	class Enoch: CAWorld
	{//Livonia
		author = "Bohemia Interactive";
		description = "Livonia Survival Map";
		pictureMap = "Extremo_Assets\texture\mod\logo.paa";
		pictureShot = "Extremo_Assets\texture\mod\logo.paa";
		//previewVideo="Extremo_Assets\video\menu.ogv";
		loadingTexts[] = {"Hardcore Survival Server"};
		cutscenes[]= {"Enoch_intro1"};
	};
	class Livonia: Enoch
	{//Livonia
		description = "Livonia Survival Map (Opened)";
		access = 3;//allow non dlc owners (not fully sure but altis is 3 and Enoch was 0)
		appId = 639600;//allow non dlc owners (malden appId, checks if appid is owned!)
		worldId = 909;//allow non dlc owners (not fully sure made a random Id)
	};
	class Malden: CAWorld
	{
		author = "Bohemia Interactive";
		description = "Malden Survival Map";
		pictureMap = "Extremo_Assets\texture\mod\logo.paa";
		pictureShot = "Extremo_Assets\texture\mod\logo.paa";
		previewVideo="Extremo_Assets\video\menu.ogv";
		loadingTexts[] = {"Hardcore Survival Server"};
	};
	class Tanoa: CAWorld
	{
		author = "Bohemia Interactive";
		description = "Tanoa Survival Map";
		pictureMap = "Extremo_Assets\texture\mod\logo.paa";
		pictureShot = "Extremo_Assets\texture\mod\logo.paa";
		previewVideo="Extremo_Assets\video\menu.ogv";
		loadingTexts[] = {"Hardcore Survival Server"};
		cutscenes[]= {"Tanoa_intro1"};
		worldName="A3\Map_Tanoabuka\Tanoa.wrp";
		newRoadsShape="A3\Map_Tanoabuka\data\roads\roads.shp";
		startTime="12:00";
		startDate="1/1/2021"
	};
	class VR: CAWorld
	{
		author = "Bohemia Interactive";
		description = "VR Survival Map";
		pictureMap = "Extremo_Assets\texture\mod\logo.paa";
		pictureShot = "Extremo_Assets\texture\mod\logo.paa";
		previewVideo="Extremo_Assets\video\menu.ogv";
		loadingTexts[] = {"Hardcore Survival Server"};
		cutscenes[]= {"ExtremoIntro"};
	}; 
	
	initWorld="Livonia";
	demoWorld="VR";
	groupNameFormat="Inmate %ExtremoAlphabet-%ExtremoNumbers";
	class ExtremoAlphabet
	{
		class A
		{
			name="A";
		};
		class B
		{
			name="B";
		};
		class C
		{
			name="C";
		};
		class D
		{
			name="D";
		};
		class E
		{
			name="E";
		};
		class F
		{
			name="F";
		};
		class G
		{
			name="G";
		};
		class H
		{
			name="H";
		};
		class I
		{
			name="I";
		};
		class J
		{
			name="J";
		};
		class K
		{
			name="K";
		};
		class L
		{
			name="L";
		};
		class M
		{
			name="M";
		};
		class N
		{
			name="N";
		};
		class O
		{
			name="O";
		};
		class P
		{
			name="P";
		};
		class Q
		{
			name="Q";
		};
		class R
		{
			name="R";
		};
		class S
		{
			name="S";
		};
		class T
		{
			name="T";
		};
		class U
		{
			name="U";
		};
		class V
		{
			name="V";
		};
		class W
		{
			name="W";
		};
		class X
		{
			name="X";
		};
		class Y
		{
			name="Y";
		};
		class Z
		{
			name="Z";
		};
	};
	class ExtremoNumbers
	{
		class Number1
		{
			name="1";
		};
		class Number2
		{
			name="2";
		};
		class Number3
		{
			name="3";
		};
		class Number4
		{
			name="4";
		};
		class Number5
		{
			name="5";
		};
		class Number6
		{
			name="6";
		};
		class Number7
		{
			name="7";
		};
		class Number8
		{
			name="8";
		};
		class Number9
		{
			name="9";
		};
	};
};

class CfgWorldList
{
	class Livonia {};
};

//--- Missions
class CfgMissions
{
	class Cutscenes
	{
		class ExtremoIntro
		{
			directory="Extremo_Assets\mission\ExtremoIntro.VR";
		};
	};
}; 

//---  Mission Difficultys
class CfgDifficultyPresets
{
	class Veteran;
	defaultPreset="ExtremoRegular";
	class ExtremoRegular: Veteran
	{
		BleedingRate=0.00050000002;
		displayName="Regular Extremo";
		class Options
		{
			reducedDamage=0;
			groupIndicators=0;
			friendlyTags=0;
			enemyTags=0;
			detectedMines=0;
			commands=0;
			waypoints=0;
			weaponInfo=0;
			stanceIndicator=0;
			staminaBar=0;
			weaponCrosshair=1;
			visionAid=0;
			thirdPersonView=1;
			cameraShake=1;
			scoreTable=0;
			deathMessages=0;
			vonID=0;
			squadRadar=0;
			mapContent=0;
			autoReport=0;
			multipleSaves=0;
		};
	};
	class ExtremoDevHappyfeet: ExtremoRegular
	{ 
		displayName="Happyfeet | Development Server"; 
	};
	class ExtremoDevNikko: ExtremoRegular
	{ 
		displayName="Nikko | Development Server";  
	};
	class ExtremoHardcore: Veteran
	{
		BleedingRate=0.0049999999;
		displayName="Hardcore Extremo";
		class Options
		{
			reducedDamage=0;
			groupIndicators=0;
			friendlyTags=0;
			enemyTags=0;
			detectedMines=0;
			commands=0;
			waypoints=0;
			weaponInfo=0;
			stanceIndicator=0;
			staminaBar=0;
			weaponCrosshair=0;
			visionAid=0;
			thirdPersonView=0;
			cameraShake=1;
			scoreTable=0;
			deathMessages=0;
			vonID=0;
			squadRadar=0;
			mapContent=0;
			autoReport=0;
			multipleSaves=0;
		};
	};
};

//--- Mission Respawn Templates
class CfgRespawnTemplates
{
	class Extremo
	{
		isCall=1;
		onPlayerKilled="Extremo_fnc_event_player_killed";
		onPlayerRespawn="Extremo_fnc_event_player_respawned";
		respawnDelay=30;
		respawnOnStart=0;
		respawnButton=1;
	};
};

//--- Sounds
class CfgSounds
{
	class SndExtremoTwinkleTwisterCharge01
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\twinkle_twister_charge_01",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoTwinkleTwisterCharge02
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\twinkle_twister_charge_02",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoTwinkleTwisterCharge03
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\twinkle_twister_charge_03",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoTwinkleTwisterChargeDone01
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\twinkle_twister_charge_done_01",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoTwinkleTwisterChargeDone02
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\twinkle_twister_charge_done_02",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoTwinkleTwisterChargeDone03
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\twinkle_twister_charge_done_03",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoTwinkleTwisterSuccess
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\twinkle_twister_success",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoTwinkleTwisterFail
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\twinkle_twister_fail",
			1,
			1
		};
		titles[]={};
	};
	class SndXM8PowerOn
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\xm8_power_on",
			1,
			1
		};
		titles[]={};
	};
	class SndXM8PowerOff
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\xm8_power_off",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoHeartbeatFast
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\heartbeat_fast.ogg",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoHeartbeatSlow
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\heartbeat_slow.ogg",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoHeartbeatSlowSingle
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\heartbeat_slow_single.ogg",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoHeartbeatStopping
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\heartbeat_stopping.ogg",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoHeartbeatEating01
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\eating01.ogg",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoHeartbeatEating02
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\eating02.ogg",
			1,
			1
		};
		titles[]={};
	};
	class SndExtremoHeartbeatDrinking01
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\drinking01.ogg",
			1,
			1
		};
		titles[]={};
	};
	class BaDumTss
	{
		name="";
		sound[]=
		{
			"Extremo_Assets\sound\ba_dum_tss",
			10,
			1
		};
		titles[]={};
	};
	class ExtremoIntro01
	{
		name="";
		sound[]=
		{
			"\a3\dubbing_f_bootcamp\BOOT_m02\15_Introduction\boot_m02_15_introduction_ADA_0.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro02
	{
		name="";
		sound[]=
		{
			"\a3\dubbing_f_bootcamp\BOOT_m02\15_Introduction\boot_m02_15_introduction_ADA_1.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro03
	{
		name="";
		sound[]=
		{
			"a3\dubbing_f_bootcamp\BOOT_m02\d05_AAF_Anger\boot_m02_d05_aaf_anger_ADA_0.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro04
	{
		name="";
		sound[]=
		{
			"a3\dubbing_f_bootcamp\BOOT_m02\d05_AAF_Anger\boot_m02_d05_aaf_anger_ADA_1.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro05
	{
		name="";
		sound[]=
		{
			"a3\dubbing_f_bootcamp\BOOT_m02\d05_AAF_Anger\boot_m02_15_introduction_ADA_2.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro06
	{
		name="";
		sound[]=
		{
			"\a3\dubbing_f_bootcamp\BOOT_m03\20_Lesson\boot_m03_20_lesson_ADA_0.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro07
	{
		name="";
		sound[]=
		{
			"a3\dubbing_f_bootcamp\BOOT_m03\75_Orders\boot_m03_75_orders_ADA_0.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro08
	{
		name="";
		sound[]=
		{
			"\a3\dubbing_f_bootcamp\BOOT_m03\80_Get_In\boot_m03_80_get_in_ADA_0.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro09
	{
		name="";
		sound[]=
		{
			"\a3\dubbing_f_bootcamp\BOOT_m04\65_Regroup\boot_m04_65_regroup_ADA_0.ogg",
			1,
			1
		};
		titles[]={};
	};
	class ExtremoIntro10
	{
		name="";
		sound[]=
		{
			"\a3\sounds_f\characters\movements\bodyfallsbodyfall_concrete_3.wss",
			1,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_Low01
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_Low01.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_Low02
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_Low02.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_Low03
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_Low03.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_Medium01
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_Medium01.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_Medium02
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_Medium02.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_Medium03
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_Medium03.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_High01
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_High01.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_High02
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_High02.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GeigerCounter_High03
	{
		name="Geiger Counter";
		sound[]=
		{
			"\Extremo_Assets\sound\Extremo_GeigerCounter_High03.wss",
			0.5,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GasMaskBreathing01
	{
		name="Gas Mask Breathing";
		sound[]=
		{
			"\a3\sounds_f\characters\human-sfx\diver-breath-1.wss",
			0.25,
			1
		};
		titles[]={};
	};
	class Extremo_Sound_GasMaskBreathing02
	{
		name="Gas Mask Breathing";
		sound[]=
		{
			"\a3\sounds_f\characters\human-sfx\diver-breath-3.wss",
			0.25,
			1
		};
		titles[]={};
	};
};

//--- Actions
class CfgActions
{
	class None;
	class OpenBag: None
	{
		show=0;
	};
	class FireInflame: None
	{
		show=0;
	};
	class FirePutDown: None
	{
		show=0;
	};
	class Heal: None
	{
		show=0;
	};
	class HealSoldier: None
	{
		show=0;
	};
	class FirstAid: None
	{
		show=0;
	};
	class ListRightVehicleDisplay: None
	{
		show=0;
	};
	class ListLeftVehicleDisplay: None
	{
		show=0;
	};
	class ListPrevRightVehicleDisplay: None
	{
		show=0;
	};
	class ListPrevLeftVehicleDisplay: None
	{
		show=0;
	};
	class CloseRightVehicleDisplay: None
	{
		show=0;
	};
	class CloseLeftVehicleDisplay: None
	{
		show=0;
	};
	class NextModeRightVehicleDisplay: None
	{
		show=0;
	};
	class NextModeLeftVehicleDisplay: None
	{
		show=0;
	};
	class UseContainerMagazine: None
	{
		show=0;
	};
	class TakeBag: None
	{
		show=0;
	};
	class TakeItem: None
	{
		show=0;
	};
	class TakeWeapon: None
	{
		show=0;
	};
	class TakeMagazine: None
	{
		show=0;
	};
	class TakeItemFromBody: None
	{
		show=0;
	};
	class TakeWeaponFromBody: None
	{
		show=0;
	};
	class TakeBackpackFromBody: None
	{
		show=0;
	};
	class TakeMine: None
	{
		show=0;
	};
};

#include "hpp\ammo.hpp"
#include "hpp\animations.hpp"
#include "hpp\construction.hpp"
#include "hpp\selections.hpp"

class CfgFactionClasses
{
	class Player_Faction
    {
        displayname = "Survialist"; //Shows in menu
        icon = "Extremo_Assets\texture\mod\icon.paa"; //Logo in menu
        priority = 10; 
        side = 2;
    };
	class Trader_Faction
    {
        displayname = "Trader"; //Shows in menu
        icon = "Extremo_Assets\texture\mod\icon.paa"; //Logo in menu
        priority = 9; 
        side = 2;
    };
    class Zombie_Faction
    {
        displayname = "The Walking Dead"; //Shows in menu
        icon = "Extremo_Assets\texture\mod\icon.paa"; //Logo in menu
        priority = 8; 
        side = 0;
    };
};

class CfgExtremoToasts
{
	class InfoEmpty
	{
		template="%1";
		color[]={0.24699999,0.83099997,0.98799998,1};
	};
	class InfoTitleOnly
	{
		template="<t size='22' font='PuristaMedium'>%1</t>";
		color[]={0.24699999,0.83099997,0.98799998,1};
	};
	class InfoTitleAndText
	{
		template="<t size='22' font='PuristaMedium'>%1</t><br/><t color='#ff979ba1' size='19' font='PuristaLight'>%2</t>";
		color[]={0.24699999,0.83099997,0.98799998,1};
	};
	class SuccessEmpty
	{
		template="%1";
		color[]={0.62699997,0.87400001,0.23100001,1};
	};
	class SuccessTitleOnly
	{
		template="<t size='22' font='PuristaMedium'>%1</t>";
		color[]={0.62699997,0.87400001,0.23100001,1};
	};
	class SuccessTitleAndText
	{
		template="<t size='22' font='PuristaMedium'>%1</t><br/><t color='#ff979ba1' size='19' font='PuristaLight'>%2</t>";
		color[]={0.62699997,0.87400001,0.23100001,1};
	};
	class ErrorEmpty
	{
		template="%1";
		color[]={0.77999997,0.149,0.31799999,1};
	};
	class ErrorTitleOnly
	{
		template="<t size='22' font='PuristaMedium'>%1</t>";
		color[]={0.77999997,0.149,0.31799999,1};
	};
	class ErrorTitleAndText
	{
		template="<t size='22' font='PuristaMedium'>%1</t><br/><t color='#ff979ba1' size='19' font='PuristaLight'>%2</t>";
		color[]={0.77999997,0.149,0.31799999,1};
	};
	class WarningEmpty
	{
		template="%1";
		color[]={0.87099999,0.796,0.227,1};
	};
	class WarningTitleOnly
	{
		template="<t size='22' font='PuristaMedium'>%1</t>";
		color[]={0.87099999,0.796,0.227,1};
	};
	class WarningTitleAndText
	{
		template="<t size='22' font='PuristaMedium'>%1</t><br/><t color='#ff979ba1' size='19' font='PuristaLight'>%2</t>";
		color[]={0.87099999,0.796,0.227,1};
	};
};
class CfgFlagsNative
{
	class BI
	{
		name="Bohemia Interactive";
		texture="Extremo_Assets\texture\flag\flag_mate_bis_co.paa";
		uids[]={"76561197977933359","76561197968664825","76561198003485468","76561198050098256","76561198007169107","76561197971697870","76561198085333695","76561197991855773"};
	};
	class Vish
	{
		name="Vish";
		texture="Extremo_Assets\texture\flag\flag_mate_vish_co.paa";
		uids[]={"76561198075905447"};
	};
	class Hollow
	{
		name="Hollow";
		texture="Extremo_Assets\texture\flag\flag_mate_hollow_co.paa";
		uids[]={"76561198182951970"};
	};
	class Legion
	{
		name="Legion";
		texture="Extremo_Assets\texture\flag\flag_mate_legion_ca.paa";
		uids[]={"76561198010969041","76561198124983829","76561198094881952","76561198111208683","76561198015966307","76561198078247060","76561198034836765","76561197998832240","76561197970701357","76561198123330495"};
	};
	class DogesOfMassDestruction
	{
		name="21 DMD";
		texture="Extremo_Assets\texture\flag\flag_mate_21dmd_co.paa";
		uids[]={"76561198021615590"};
	};
	class Spawny
	{
		name="sp4wny";
		texture="Extremo_Assets\texture\flag\flag_mate_spawny_co.paa";
		uids[]={"76561197960452768"};
	};
	class Tomms
	{
		name="Tomms";
		texture="Extremo_Assets\texture\flag\flag_mate_secretone_co.paa";
		uids[]={"76561198003041335"};
	};
	class StitchMoonz
	{
		name="StitchMoonz";
		texture="Extremo_Assets\texture\flag\flag_mate_stitchmoonz_co.paa";
		uids[]={"76561198112458056"};
	};
	class CommanderMalc
	{
		name="CommanderMalc";
		texture="Extremo_Assets\texture\flag\flag_mate_commandermalc_co.paa";
		uids[]={"76561197998522808"};
	};
	class Blue
	{
		name="Blue";
		texture="\A3\Data_F\Flags\flag_blue_co.paa";
		uids[]={};
	};
	class Green
	{
		name="Green";
		texture="\A3\Data_F\Flags\flag_green_co.paa";
		uids[]={};
	};
	class Red
	{
		name="Red";
		texture="\A3\Data_F\Flags\flag_red_co.paa";
		uids[]={};
	};
	class White
	{
		name="White";
		texture="\A3\Data_F\Flags\flag_white_co.paa";
		uids[]={};
	};
	class CountryUK
	{
		name="United Kingdom";
		texture="\A3\Data_F\Flags\flag_uk_co.paa";
		uids[]={};
	};
	class CountryDE
	{
		name="Germany";
		texture="Extremo_Assets\texture\flag\flag_country_de_co.paa";
		uids[]={};
	};
	class CountryAT
	{
		name="Austria";
		texture="Extremo_Assets\texture\flag\flag_country_at_co.paa";
		uids[]={};
	};
	class CountrySCT
	{
		name="Scotland";
		texture="Extremo_Assets\texture\flag\flag_country_sct_co.paa";
		uids[]={};
	};
	class CountryEE
	{
		name="Estonia";
		texture="Extremo_Assets\texture\flag\flag_country_ee_co.paa";
		uids[]={};
	};
	class CountryCZ
	{
		name="Czech Republic";
		texture="Extremo_Assets\texture\flag\flag_country_cz_co.paa";
		uids[]={};
	};
	class CountryNL
	{
		name="The Netherlands";
		texture="Extremo_Assets\texture\flag\flag_country_nl_co.paa";
		uids[]={};
	};
	class CountryHR
	{
		name="Croatia";
		texture="Extremo_Assets\texture\flag\flag_country_hr_co.paa";
		uids[]={};
	};
	class CountryCN
	{
		name="Canada";
		texture="Extremo_Assets\texture\flag\flag_country_cn_co.paa";
		uids[]={};
	};
	class CountryRU
	{
		name="Russia";
		texture="Extremo_Assets\texture\flag\flag_country_ru_co.paa";
		uids[]={};
	};
	class CountryIR
	{
		name="Ireland";
		texture="Extremo_Assets\texture\flag\flag_country_ir_co.paa";
		uids[]={};
	};
	class CountryBY
	{
		name="Belarus";
		texture="Extremo_Assets\texture\flag\flag_country_by_co.paa";
		uids[]={};
	};
	class CountryFI
	{
		name="Finland";
		texture="Extremo_Assets\texture\flag\flag_country_fi_co.paa";
		uids[]={};
	};
	class CountryFR
	{
		name="France";
		texture="Extremo_Assets\texture\flag\flag_country_fr_co.paa";
		uids[]={};
	};
	class CountryAU
	{
		name="Australia";
		texture="Extremo_Assets\texture\flag\flag_country_au_co.paa";
		uids[]={};
	};
	class CountryBE
	{
		name="Belgium";
		texture="Extremo_Assets\texture\flag\flag_country_be_co.paa";
		uids[]={};
	};
	class CountrySE
	{
		name="Sweden";
		texture="Extremo_Assets\texture\flag\flag_country_se_co.paa";
		uids[]={};
	};
	class CountryPL
	{
		name="Poland";
		texture="Extremo_Assets\texture\flag\flag_country_pl_co.paa";
		uids[]={};
	};
	class CountryPL2
	{
		name="Poland 2";
		texture="Extremo_Assets\texture\flag\flag_country_pl2_co.paa";
		uids[]={};
	};
	class CountryPT
	{
		name="Portugal";
		texture="Extremo_Assets\texture\flag\flag_country_pt_co.paa";
		uids[]={};
	};
	class Zand3rs
	{
		name="Zand3rs";
		texture="Extremo_Assets\texture\flag\flag_mate_zanders_streched_co.paa";
		uids[]={};
	};
	class Brunswik
	{
		name="Brunswik";
		texture="Extremo_Assets\texture\flag\flag_misc_brunswik_co.paa";
		uids[]={};
	};
	class Dorset
	{
		name="Dorset";
		texture="Extremo_Assets\texture\flag\flag_misc_dorset_co.paa";
		uids[]={};
	};
	class Svarog
	{
		name="Children of Svarog";
		texture="Extremo_Assets\texture\flag\flag_misc_svarog_co.paa";
		uids[]={};
	};
	class Extremo
	{
		name="Extremo";
		texture="Extremo_Assets\texture\flag\flag_misc_Extremo_co.paa";
		uids[]={};
	};
	class UTcity
	{
		name="UTcity";
		texture="Extremo_Assets\texture\flag\flag_misc_utcity_co.paa";
		uids[]={};
	};
	class Dickbutt
	{
		name="Dickbut";
		texture="Extremo_Assets\texture\flag\flag_misc_dickbutt_co.paa";
		uids[]={};
	};
	class Rainbow
	{
		name="Rainbow";
		texture="Extremo_Assets\texture\flag\flag_misc_rainbow_co.paa";
		uids[]={};
	};
	class BattlEye
	{
		name="BattlEye";
		texture="Extremo_Assets\texture\flag\flag_misc_battleye_co.paa";
		uids[]={};
	};
	class BSS
	{
		name="Bluescreen Simulator";
		texture="Extremo_Assets\texture\flag\flag_misc_bss_co.paa";
		uids[]={};
	};
	class Skippy
	{
		name="Skippy";
		texture="Extremo_Assets\texture\flag\flag_misc_skippy_co.paa";
		uids[]={};
	};
	class KiwiFern
	{
		name="Silver Fern";
		texture="Extremo_Assets\texture\flag\flag_misc_kiwifern_co.paa";
		uids[]={};
	};
	class Trololol
	{
		name="Trololol";
		texture="Extremo_Assets\texture\flag\flag_misc_trololol_co.paa";
		uids[]={};
	};
	class DreamCat
	{
		name="Dream Cat";
		texture="Extremo_Assets\texture\flag\flag_misc_dream_cat_co.paa";
		uids[]={};
	};
	class Pirate
	{
		name="Pirate";
		texture="Extremo_Assets\texture\flag\flag_misc_pirate_co.paa";
		uids[]={};
	};
	class Pedobear
	{
		name="Pedobear";
		texture="Extremo_Assets\texture\flag\flag_misc_pedobear_co.paa";
		uids[]={};
	};
	class Petoria
	{
		name="Petoria";
		texture="Extremo_Assets\texture\flag\flag_misc_petoria_co.paa";
		uids[]={};
	};
	class Smashing
	{
		name="Smashing";
		texture="Extremo_Assets\texture\flag\flag_misc_smashing_co.paa";
		uids[]={};
	};
	class LemonParty
	{
		name="Lemon Party";
		texture="Extremo_Assets\texture\flag\flag_misc_lemonparty_co.paa";
		uids[]={};
	};
	class RMA
	{
		name="Respect my autoritah!";
		texture="Extremo_Assets\texture\flag\flag_misc_rma_co.paa";
		uids[]={};
	};
	class CP
	{
		name="ClarkyCallad";
		texture="Extremo_Assets\texture\flag\flag_cp_co.paa";
		uids[]={};
	};
	class Trouble2_NA
	{
		name="Trouble2";
		texture="Extremo_Assets\texture\flag\flag_trouble2_co.paa";
		uids[]={};
	};
	class ExtremoCity
	{
		name="Extremo City";
		texture="Extremo_Assets\texture\flag\flag_Extremo_city_co.paa";
		uids[]={};
	};
	class Eraser1
	{
		name="eraser1";
		texture="Extremo_Assets\texture\flag\flag_misc_eraser1_co.paa";
		uids[]={};
	};
	class Trespassers
	{
		name="Trespassers will be eaten";
		texture="Extremo_Assets\texture\flag\flag_misc_willbeeaten_co.paa";
		uids[]={};
	};
	class PrivateProperty
	{
		name="Private Property";
		texture="Extremo_Assets\texture\flag\flag_misc_privateproperty_co.paa";
		uids[]={};
	};
	class NuCoolR
	{
		name="Nu Cool R";
		texture="Extremo_Assets\texture\flag\flag_misc_nuclear_co.paa";
		uids[]={};
	};
	class LazerKiwi
	{
		name="Lazer Kiwi";
		texture="Extremo_Assets\texture\flag\flag_misc_lazerkiwi_co.paa";
		uids[]={};
	};
	class Beardageddon
	{
		name="Beardageddon";
		texture="Extremo_Assets\texture\flag\flag_misc_beardageddon_co.paa";
		uids[]={};
	};
	class CountryDK
	{
		name="Denmark";
		texture="Extremo_Assets\texture\flag\flag_country_dk_co.paa";
		uids[]={};
	};
	class CountryIT
	{
		name="Italy";
		texture="Extremo_Assets\texture\flag\flag_country_it_co.paa";
		uids[]={};
	};
	class Alkohol
	{
		name="Alkohol";
		texture="Extremo_Assets\texture\flag\flag_misc_alkohol_co.paa";
		uids[]={};
	};
	class Kickass
	{
		name="Fort Kickass";
		texture="Extremo_Assets\texture\flag\flag_misc_kickass_co.paa";
		uids[]={};
	};
	class Knuckles
	{
		name="Da Wae?";
		texture="Extremo_Assets\texture\flag\flag_misc_knuckles_co.paa";
		uids[]={};
	};
	class Snake
	{
		name="Don't Tread on Me";
		texture="Extremo_Assets\texture\flag\flag_misc_snake_co.paa";
		uids[]={};
	};
	class WeebCity
	{
		name="Weeb City";
		texture="Extremo_Assets\texture\flag\flag_misc_weeb_co.paa";
		uids[]={};
	};
};
class CfgGlasses
{
	class G_I_Diving;
	class G_O_Diving;
	class G_B_Diving;
	class Extremo_Glasses_Diving_AAF: G_I_Diving
	{
		scope=2;
		author="Nikko Renolds";
		displayName="Diving Goggles (AAF, Forced)";
		mode=0;
	};
	class Extremo_Glasses_Diving_CSAT: G_O_Diving
	{
		scope=2;
		author="Nikko Renolds";
		displayName="Diving Goggles (CSAT, Forced)";
		mode=0;
	};
	class Extremo_Glasses_Diving_NATO: G_B_Diving
	{
		scope=2;
		author="Nikko Renolds";
		displayName="Diving Goggles (NATO, Forced)";
		mode=0;
	};
};
class CfgInventoryGlobalVariable
{
	maxSoldierLoad=1700;
};
class CfgLocationTypes
{
	class Name;
	class ExtremoTerritory: Name
	{
		color[]={0.91000003,0,0,1};
		drawStyle="name";
		font="PuristaMedium";
		name="Extremo Territory";
		textSize=0.050000001;
		size=15;
	};
};
class CfgMarkerClasses
{
	class ExtremoEvents
	{
		displayName="Extremo Events";
	};
	class ExtremoNonConstructionZone
	{
		displayName="Extremo Non-Construction Zone";
	};
	class ExtremoSpawnZone
	{
		displayName="Extremo Spawn Zone";
	};
	class ExtremoSpawnZoneIcon
	{
		displayName="Extremo Spawn Zone Icon";
	};
	class ExtremoTraderZone
	{
		displayName="Extremo Trader Zone";
	};
	class ExtremoTraderZoneIcon
	{
		displayName="Extremo Trader Zone Icon";
	};
	class ExtremoContaminatedZone
	{
		displayName="Extremo Contaminated Zone";
	};
	class ExtremoContaminatedZoneIcon
	{
		displayName="Extremo Contaminated Zone Icon";
	};
	class ExtremoConcreteMixerZone
	{
		displayName="Extremo Concrete Mixer Zone";
	};
	class ExtremoConcreteMixerZoneIcon
	{
		displayName="Extremo Concrete Mixer Zone Icon";
	};
	class ExtremoPlayer
	{
		displayName="Extremo Player";
	};
	class ExtremoLandVehicleSpawn
	{
		displayName="Extremo Land Vehicle Spawn";
	};
	class ExtremoAirVehicleSpawn
	{
		displayName="Extremo Air Vehicle Spawn";
	};
	class ExtremoSeaVehicleSpawn
	{
		displayName="Extremo Sea Vehicle Spawn";
	};
	class ExtremoRussianRouletteIcon
	{
		displayName="Extremo Russian Roulette Icon";
	};
	class ExtremoSpecOpsTraderIcon
	{
		displayName="Extremo Spec Ops Trader Icon";
	};
	class ExtremoAircraftTraderIcon
	{
		displayName="Extremo Aircraft Trader Icon";
	};
	class ExtremoBoatTraderIcon
	{
		displayName="Extremo Boat Trader Icon";
	};
	class ExtremoDiversTraderIcon
	{
		displayName="Extremo Divers Trader Icon";
	};
	class ExtremoHackingIcon
	{
		displayName="Extremo Hacking Icon";
	};
	class ExtremoVehicleIcon
	{
		displayName="Extremo Vehicle Icon";
	};
};
class CfgMarkers
{
	class ExtremoMissionHardcoreIcon
	{
		scope=0;
		name="Extremo Mission Icon (Hardcore)";
		icon="Extremo_Assets\texture\marker\mission_hardcore_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoEvents";
		showEditorMarkerColor=0;
	};
	class ExtremoMissionModerateIcon
	{
		scope=0;
		name="Extremo Mission Icon (Moderate)";
		icon="Extremo_Assets\texture\marker\mission_moderate_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoEvents";
		showEditorMarkerColor=0;
	};
	class ExtremoMissionDifficultIcon
	{
		scope=0;
		name="Extremo Mission Icon (Difficult)";
		icon="Extremo_Assets\texture\marker\mission_difficult_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoEvents";
		showEditorMarkerColor=0;
	};
	class ExtremoMissionEasyIcon
	{
		scope=0;
		name="Extremo Mission Icon (Easy)";
		icon="Extremo_Assets\texture\marker\mission_easy_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoEvents";
		showEditorMarkerColor=0;
	};
	class ExtremoMissionCapturePointIcon
	{
		scope=0;
		name="Extremo Capture Point Icon";
		icon="Extremo_Assets\texture\marker\capture_point_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoEvents";
		showEditorMarkerColor=0;
	};
	class ExtremoMissionStrongholdIcon
	{
		scope=0;
		name="Extremo Stronghold Icon";
		icon="Extremo_Assets\texture\marker\stronghold_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoEvents";
		showEditorMarkerColor=0;
	};
	class ExtremoNonConstructionZone
	{
		scope=0;
		name="Extremo Non-Construction Zone";
		icon="Extremo_Assets\texture\marker\spawn_zone_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoNonConstructionZone";
		showEditorMarkerColor=0;
	};
	class ExtremoSpawnZone
	{
		scope=0;
		name="Extremo Spawn Zone";
		icon="Extremo_Assets\texture\marker\spawn_zone_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoSpawnZone";
		showEditorMarkerColor=0;
	};
	class ExtremoSpawnZoneIcon
	{
		scope=0;
		name="Extremo Spawn Zone Icon";
		icon="Extremo_Assets\texture\marker\spawn_zone_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoSpawnZoneIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoTraderZone
	{
		scope=0;
		name="Extremo Trader Zone";
		icon="Extremo_Assets\texture\marker\trader_zone_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoTraderZone";
		showEditorMarkerColor=0;
	};
	class ExtremoTraderZoneIcon
	{
		scope=0;
		name="Extremo Trader Zone Icon";
		icon="Extremo_Assets\texture\marker\trader_zone_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoTraderZoneIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoPlayer
	{
		scope=0;
		name="Extremo Player";
		icon="\A3\ui_f\data\map\VehicleIcons\iconman_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoPlayer";
		showEditorMarkerColor=0;
	};
	class ExtremoSafe
	{
		scope=0;
		name="Extremo Safe";
		icon="Extremo_Assets\texture\marker\unlocked_safe_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoSafe";
		showEditorMarkerColor=0;
	};
	class ExtremoHeart
	{
		scope=0;
		name="Extremo Heart";
		icon="Extremo_Assets\texture\marker\supply_drop_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoHeart";
		showEditorMarkerColor=0;
	};
	class ExtremoContaminatedZone
	{
		scope=0;
		name="Extremo Heart";
		icon="Extremo_Assets\texture\marker\contaminated_zone_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoContaminatedZone";
		showEditorMarkerColor=0;
	};
	class ExtremoContaminatedZoneIcon
	{
		scope=0;
		name="Extremo Heart";
		icon="Extremo_Assets\texture\marker\contaminated_zone_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoContaminatedZoneIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoConcreteMixerZone
	{
		scope=0;
		name="Extremo Concrete Mixer Zone";
		icon="Extremo_Assets\texture\marker\spawn_zone_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoConcreteMixerZone";
		showEditorMarkerColor=0;
	};
	class ExtremoConcreteMixerZoneIcon
	{
		scope=0;
		name="Extremo Concrete Mixer Zone Icon";
		icon="Extremo_Assets\texture\marker\concrete_mixer_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoConcreteMixerZoneIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoDiversTraderIcon
	{
		scope=0;
		name="Extremo Divers Trader Icon";
		icon="Extremo_Assets\texture\marker\divers_trader_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoDiversTraderIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoBoatTraderIcon
	{
		scope=0;
		name="Extremo Boat Trader Icon";
		icon="Extremo_Assets\texture\marker\boat_trader_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoBoatTraderIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoAircraftTraderIcon
	{
		scope=0;
		name="Extremo Aircraft Trader Icon";
		icon="Extremo_Assets\texture\marker\aircraft_trader_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoAircraftTraderIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoSpecOpsTraderIcon
	{
		scope=0;
		name="Extremo Spec Ops Trader Icon";
		icon="Extremo_Assets\texture\marker\spec_ops_trader_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoSpecOpsTraderIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoRussianRouletteIcon
	{
		scope=0;
		name="Extremo Russian Roulette Icon";
		icon="Extremo_Assets\texture\marker\russian_roulette_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoRussianRouletteIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoHackingIcon
	{
		scope=0;
		name="Extremo Hacking Icon";
		icon="Extremo_Assets\texture\marker\hacking_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoHackingIcon";
		showEditorMarkerColor=0;
	};
	class ExtremoVehicleIcon
	{
		scope=0;
		name="Extremo Vehicle Icon";
		icon="Extremo_Assets\texture\marker\vehicle_ca.paa";
		color[]={1,1,1,1};
		size=32;
		shadow=0;
		markerClass="ExtremoVehicleIcon";
		showEditorMarkerColor=0;
	};
};
class CfgNetworkMessages
{
	class kickClient
	{
		module="object_player";
		parameters[]={};
	};
	class youWonMate
	{
		module="object_player";
		parameters[]={};
	};
	class playerStart
	{
		module="object_player";
		parameters[]={};
	};
	class tagSpectateRequest
	{
		module="object_player";
		parameters[]=
		{
			"STRING"
		};
	};
	class spectateRequest
	{
		module="object_player";
		parameters[]=
		{
			"OBJECT",
			"STRING"
		};
	};
	class spectateResponse
	{
		module="object_player";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class escapeVariables
	{
		module="object_player";
		parameters[]=
		{
			"SCALAR",
			"SCALAR"
		};
	};
	class announceAnimalRequest
	{
		module="object_animal";
		parameters[]=
		{
			"STRING"
		};
	};
	class gutAnimalRequest
	{
		module="object_animal";
		parameters[]=
		{
			"STRING"
		};
	};
	class playEarthQuakeEffectRequest
	{
		module="system_earthQuake";
		parameters[]=
		{
			"SCALAR"
		};
	};
	class requestJoinRussianRouletteDialogRequest
	{
		module="system_russianRoulette";
		parameters[]={};
	};
	class requestJoinRussianRouletteDialogResponse
	{
		module="system_russianRoulette";
		parameters[]=
		{
			"SCALAR",
			"SCALAR"
		};
	};
	class concreteMixerStartRequest
	{
		module="object_concreteMixer";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class concreteMixerAddSmokeRequest
	{
		module="object_concreteMixer";
		parameters[]=
		{
			"STRING"
		};
	};
	class concreteMixerRemoveSmokeRequest
	{
		module="object_concreteMixer";
		parameters[]=
		{
			"STRING"
		};
	};
	class winRussianRouletteRequest
	{
		module="system_russianRoulette";
		parameters[]=
		{
			"ARRAY",
			"SCALAR",
			"SCALAR"
		};
	};
	class joinRussianRouletteRequest
	{
		module="system_russianRoulette";
		parameters[]={};
	};
	class joinRussianRouletteResponse
	{
		module="system_russianRoulette";
		parameters[]=
		{
			"STRING"
		};
	};
	class leaveRussianRouletteRequest
	{
		module="system_russianRoulette";
		parameters[]={};
	};
	class leaveRussianRouletteResponse
	{
		module="system_russianRoulette";
		parameters[]=
		{
			"ARRAY",
			"SCALAR"
		};
	};
	class updateRussianRouletteGameStatusRequest
	{
		module="system_russianRoulette";
		parameters[]=
		{
			"SCALAR",
			"SCALAR",
			"ARRAY",
			"STRING",
			"SCALAR",
			"SCALAR"
		};
	};
	class fireRussianRouletteRevolverRequest
	{
		module="system_russianRoulette";
		parameters[]=
		{
			"BOOL"
		};
	};
	class fireRussianRouletteRevolverResponse
	{
		module="system_russianRoulette";
		parameters[]={};
	};
	class startSessionRequest
	{
		module="system_session";
		parameters[]=
		{
			"STRING"
		};
	};
	class startSessionResponse
	{
		module="system_session";
		parameters[]=
		{
			"STRING"
		};
	};
	class updateSessionRequest
	{
		module="system_session";
		parameters[]=
		{
			"STRING"
		};
	};
	class switchMoveRequest
	{
		module="object_player";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class updateStatsRequest
	{
		module="object_player";
		parameters[]=
		{
			"STRING",
			"SCALAR",
			"SCALAR"
		};
	};
	class showFragRequest
	{
		module="gui";
		parameters[]=
		{
			"ARRAY"
		};
	};
	class hasPlayerRequest
	{
		module="object_player";
		parameters[]={};
	};
	class hasPlayerResponse
	{
		module="object_player";
		parameters[]=
		{
			"BOOL"
		};
	};
	class createPlayerRequest
	{
		module="object_player";
		parameters[]=
		{
			"STRING"
		};
	};
	class createPlayerResponse
	{
		module="object_player";
		parameters[]=
		{
			"OBJECT",
			"STRING",
			"STRING",
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"ARRAY",
			"SCALAR"
		};
	};
	class loadPlayerRequest
	{
		module="object_player";
		parameters[]={};
	};
	class loadPlayerResponse
	{
		module="object_player";
		parameters[]=
		{
			"STRING",
			"STRING",
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"ARRAY",
			"SCALAR",
			"SCALAR"
		};
	};
	class updatePlayerIncapacitatedRequest
	{
		module="object_player";
		parameters[]=
		{
			"BOOL"
		};
	};
	class savePlayerRequest
	{
		module="object_player";
		parameters[]=
		{
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"SCALAR",
			"SCALAR"
		};
	};
	class hideBodyRequest
	{
		module="object_player";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class chopTreeRequest
	{
		module="object_tree";
		parameters[]=
		{
			"STRING"
		};
	};
	class smashShippingContainerRequest
	{
		module="object_shippingContainer";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class chopBushRequest
	{
		module="object_bush";
		parameters[]=
		{
			"STRING"
		};
	};
	class systemChatRequest
	{
		module="gui";
		parameters[]=
		{
			"STRING"
		};
	};
	class advancedHintRequest
	{
		module="gui";
		parameters[]=
		{
			"STRING"
		};
	};
	class standardHintRequest
	{
		module="gui";
		parameters[]=
		{
			"STRING"
		};
	};
	class toastRequest
	{
		module="gui";
		parameters[]=
		{
			"STRING",
			"ARRAY"
		};
	};
	class baguetteRequest
	{
		module="gui";
		parameters[]=
		{
			"STRING"
		};
	};
	class dynamicTextRequest
	{
		module="gui";
		parameters[]=
		{
			"STRING",
			"SCALAR",
			"SCALAR",
			"STRING"
		};
	};
	class resetPlayerRequest
	{
		module="object_player";
		parameters[]={};
	};
	class buildConstructionRequest
	{
		module="object_construction";
		parameters[]=
		{
			"STRING",
			"ARRAY"
		};
	};
	class repairConstructionRequest
	{
		module="object_construction";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class repairConstructionResponse
	{
		module="object_construction";
		parameters[]=
		{
			"STRING"
		};
	};
	class payTerritoryProtectionMoneyRequest
	{
		module="system_territory";
		parameters[]=
		{
			"STRING"
		};
	};
	class buildTerritoryRequest
	{
		module="object_construction";
		parameters[]=
		{
			"STRING",
			"ARRAY",
			"STRING",
			"STRING"
		};
	};
	class constructionResponse
	{
		module="object_construction";
		parameters[]=
		{
			"STRING"
		};
	};
	class swapConstructionRequest
	{
		module="object_construction";
		parameters[]=
		{
			"STRING",
			"STRING",
			"ARRAY"
		};
	};
	class deconstructConstructionRequest
	{
		module="object_construction";
		parameters[]=
		{
			"STRING"
		};
	};
	class moveConstructionRequest
	{
		module="object_construction";
		parameters[]=
		{
			"STRING"
		};
	};
	class constructionMoveResponse
	{
		module="object_construction";
		parameters[]=
		{
			"BOOL",
			"STRING"
		};
	};
	class upgradeConstructionRequest
	{
		module="object_construction";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class upgradeConstructionResponse
	{
		module="object_construction";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class flipVehRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING"
		};
	};
	class pushVehicleRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING",
			"SCALAR",
			"SCALAR",
			"STRING"
		};
	};
	class rotateVehicleRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class lockVehicleRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING",
			"BOOL"
		};
	};
	class lockResponse
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING",
			"BOOL",
			"STRING",
			"STRING",
			"SCALAR"
		};
	};
	class spawnLootRequest
	{
		module="system_lootManager";
		parameters[]=
		{
			"ARRAY"
		};
	};
	class toggleFloodLightRequest
	{
		module="object_floodLight";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class connectionTest
	{
		module="object_player";
		parameters[]=
		{
			"BOOL"
		};
	};
	class purchaseVehicleRequest
	{
		module="system_trading";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class purchaseVehicleResponse
	{
		module="system_trading";
		parameters[]=
		{
			"SCALAR",
			"STRING",
			"SCALAR"
		};
	};
	class vehicleSaveRequest
	{
		module="system_vehicleSaveQueue";
		parameters[]=
		{
			"STRING"
		};
	};
	class purchaseVehicleSkinRequest
	{
		module="system_trading";
		parameters[]=
		{
			"STRING",
			"ARRAY"
		};
	};
	class purchaseVehicleSkinResponse
	{
		module="system_trading";
		parameters[]=
		{
			"SCALAR",
			"SCALAR"
		};
	};
	class endBambiStateRequest
	{
		module="object_player";
		parameters[]={};
	};
	class purchaseItemRequest
	{
		module="system_trading";
		parameters[]=
		{
			"STRING",
			"SCALAR",
			"SCALAR",
			"STRING"
		};
	};
	class purchaseItemResponse
	{
		module="system_trading";
		parameters[]=
		{
			"SCALAR",
			"SCALAR",
			"STRING",
			"SCALAR",
			"SCALAR",
			"STRING"
		};
	};
	class sellItemRequest
	{
		module="system_trading";
		parameters[]=
		{
			"STRING",
			"SCALAR",
			"SCALAR",
			"STRING"
		};
	};
	class sellItemResponse
	{
		module="system_trading";
		parameters[]=
		{
			"SCALAR",
			"SCALAR",
			"STRING",
			"SCALAR",
			"SCALAR",
			"STRING",
			"STRING"
		};
	};
	class hotwireLockRequest
	{
		module="object_lock";
		parameters[]=
		{
			"STRING"
		};
	};
	class lockToggle
	{
		module="object_lock";
		parameters[]=
		{
			"STRING",
			"STRING",
			"BOOL"
		};
	};
	class setPin
	{
		module="object_lock";
		parameters[]=
		{
			"STRING",
			"STRING",
			"STRING"
		};
	};
	class setPinResponse
	{
		module="object_lock";
		parameters[]=
		{
			"ARRAY",
			"STRING",
			"STRING"
		};
	};
	class packRequest
	{
		module="object_container";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class setFuelRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class registerClanRequest
	{
		module="system_clan";
		parameters[]=
		{
			"STRING"
		};
	};
	class registerClanResponse
	{
		module="system_clan";
		parameters[]=
		{
			"SCALAR",
			"SCALAR",
			"ARRAY"
		};
	};
	class leaveClanRequest
	{
		module="system_clan";
		parameters[]={};
	};
	class leaveClanResponse
	{
		module="system_clan";
		parameters[]=
		{
			"BOOL",
			"STRING"
		};
	};
	class updateClanInfoFull
	{
		module="system_clan";
		parameters[]=
		{
			"STRING",
			"STRING",
			"ARRAY",
			"ARRAY",
			"ARRAY",
			"GROUP"
		};
	};
	class updateClanGotKicked
	{
		module="system_clan";
		parameters[]=
		{
			"STRING",
			"ARRAY"
		};
	};
	class updateMarkers
	{
		module="system_clan";
		parameters[]=
		{
			"ARRAY"
		};
	};
	class updatePolys
	{
		module="system_clan";
		parameters[]=
		{
			"ARRAY"
		};
	};
	class inviteToClanRequest
	{
		module="system_clan";
		parameters[]=
		{
			"STRING"
		};
	};
	class inviteToClanRequestClient
	{
		module="system_clan";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class inviteToClanRequestClientResponse
	{
		module="system_clan";
		parameters[]=
		{
			"BOOL"
		};
	};
	class clanInviteServerResponse
	{
		module="system_clan";
		parameters[]=
		{
			"BOOL"
		};
	};
	class kickClanPlayerRequest
	{
		module="system_clan";
		parameters[]=
		{
			"STRING"
		};
	};
	class addMarkerRequest
	{
		module="system_clan";
		parameters[]=
		{
			"STRING",
			"ARRAY",
			"ARRAY",
			"SCALAR",
			"STRING",
			"SCALAR"
		};
	};
	class addPolyRequest
	{
		module="system_clan";
		parameters[]=
		{
			"ARRAY",
			"ARRAY"
		};
	};
	class removeMarkerRequest
	{
		module="system_clan";
		parameters[]=
		{
			"SCALAR",
			"SCALAR"
		};
	};
	class inviteToPartyRequest
	{
		module="system_party";
		parameters[]=
		{
			"STRING"
		};
	};
	class joinPartyRequest
	{
		module="system_party";
		parameters[]=
		{
			"STRING"
		};
	};
	class kickFromPartyRequest
	{
		module="system_party";
		parameters[]=
		{
			"STRING"
		};
	};
	class announceTerritoryRequest
	{
		module="system_territory";
		parameters[]=
		{
			"STRING"
		};
	};
	class addToTerritoryRequest
	{
		module="system_territory";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class removeFromTerritoryRequest
	{
		module="system_territory";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class moderationTerritoryRequest
	{
		module="system_territory";
		parameters[]=
		{
			"STRING",
			"STRING",
			"BOOL"
		};
	};
	class purchaseTerritory
	{
		module="system_territory";
		parameters[]={};
	};
	class purchaseTerritoryResponse
	{
		module="system_territory";
		parameters[]=
		{
			"SCALAR"
		};
	};
	class requestTerritoryUpgradeDialog
	{
		module="system_territory";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class payFlagRansomRequest
	{
		module="system_territory";
		parameters[]=
		{
			"STRING"
		};
	};
	class restoreFlagRequest
	{
		module="system_territory";
		parameters[]=
		{
			"STRING"
		};
	};
	class addLockRequest
	{
		module="object_construction";
		parameters[]=
		{
			"OBJECT",
			"STRING"
		};
	};
	class addLockResponse
	{
		module="object_construction";
		parameters[]=
		{
			"STRING"
		};
	};
	class territoryUpgradeDialogResponse
	{
		module="gui_upgradeTerritoryDialog";
		parameters[]=
		{
			"SCALAR"
		};
	};
	class territoryUpgradeRequest
	{
		module="system_territory";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class deleteGroupPlz
	{
		module="system";
		parameters[]=
		{
			"GROUP"
		};
	};
	class wasteDumpRequest
	{
		module="system_trading";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class wasteDumpResponse
	{
		module="system_trading";
		parameters[]=
		{
			"SCALAR",
			"SCALAR",
			"STRING"
		};
	};
	class beginTakeAllRequest
	{
		module="object_player";
		parameters[]=
		{
			"STRING"
		};
	};
	class beginTakeAllResponse
	{
		module="object_player";
		parameters[]=
		{
			"STRING"
		};
	};
	class endTakeAllRequest
	{
		module="object_player";
		parameters[]=
		{
			"STRING"
		};
	};
	class scanCodeLockRequest
	{
		module="object_lock";
		parameters[]=
		{
			"STRING"
		};
	};
	class scanCodeLockResponse
	{
		module="object_lock";
		parameters[]=
		{
			"STRING"
		};
	};
	class enableSimulationRequest
	{
		module="system_simulationMonitor";
		parameters[]=
		{
			"STRING"
		};
	};
	class attachSupplyBoxRequest
	{
		module="object_supplyBox";
		parameters[]=
		{
			"STRING"
		};
	};
	class detachSupplyBoxRequest
	{
		module="object_supplyBox";
		parameters[]=
		{
			"STRING"
		};
	};
	class installSupplyBoxRequest
	{
		module="object_supplyBox";
		parameters[]=
		{
			"STRING"
		};
	};
	class handcuffRequest
	{
		module="object_handcuffs";
		parameters[]=
		{
			"STRING"
		};
	};
	class handcuffResponse
	{
		module="object_handcuffs";
		parameters[]=
		{
			"STRING"
		};
	};
	class freeRequest
	{
		module="object_handcuffs";
		parameters[]=
		{
			"STRING"
		};
	};
	class freeResponse
	{
		module="object_handcuffs";
		parameters[]=
		{
			"STRING"
		};
	};
	class breakFreeRequest
	{
		module="object_handcuffs";
		parameters[]={};
	};
	class breakFreeResponse
	{
		module="object_handcuffs";
		parameters[]=
		{
			"STRING"
		};
	};
	class updateMyPartyMarkerRequest
	{
		module="system_party";
		parameters[]=
		{
			"BOOL",
			"ARRAY"
		};
	};
	class updatePartyMarkerRequest
	{
		module="system_party";
		parameters[]=
		{
			"STRING",
			"BOOL",
			"ARRAY"
		};
	};
	class resetCodeRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING",
			"STRING",
			"STRING"
		};
	};
	class resetCodeResponse
	{
		module="object_vehicle";
		parameters[]=
		{
			"ARRAY",
			"STRING",
			"STRING"
		};
	};
	class rekeyVehicleRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class rekeyVehicleDialogRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class rekeyVehicleDialogResponse
	{
		module="gui_vehicleRekeyDialog";
		parameters[]=
		{
			"STRING",
			"STRING",
			"SCALAR"
		};
	};
	class resetCodeDialogRequest
	{
		module="object_vehicle";
		parameters[]=
		{
			"STRING"
		};
	};
	class resetCodeDialogResponse
	{
		module="gui_vehicleRekeyDialog";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class putMoneyRequest
	{
		module="system_money";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class takeMoneyRequest
	{
		module="system_money";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class moneyTransactionResponse
	{
		module="system_money";
		parameters[]=
		{
			"STRING",
			"SCALAR"
		};
	};
	class flagStolenRequest
	{
		module="system_territory";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class lockerDepositRequest
	{
		module="system_locker";
		parameters[]=
		{
			"STRING"
		};
	};
	class lockerWithdrawRequest
	{
		module="system_locker";
		parameters[]=
		{
			"STRING"
		};
	};
	class lockerResponse
	{
		module="system_locker";
		parameters[]={};
	};
	class slothMachineRequest
	{
		module="system_slothMachine";
		parameters[]={};
	};
	class slothMachineResponse
	{
		module="system_slothMachine";
		parameters[]=
		{
			"STRING",
			"SCALAR",
			"SCALAR",
			"ARRAY"
		};
	};
	class breachingStart
	{
		module="system_breaching";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class breachingResponse
	{
		module="system_breaching";
		parameters[]=
		{
			"OBJECT",
			"OBJECT"
		};
	};
	class breachingPlaceRequest
	{
		module="system_breaching";
		parameters[]=
		{
			"ARRAY",
			"ARRAY",
			"OBJECT"
		};
	};
	class breachingCancel
	{
		module="system_breaching";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class breachingPlaceResponse
	{
		module="system_breaching";
		parameters[]=
		{
			"OBJECT"
		};
	};
	class chargePlanted
	{
		module="system_breaching";
		parameters[]={};
	};
	class detonateAllCharges
	{
		module="system_breaching";
		parameters[]={};
	};
	class hackLockRequest
	{
		module="object_lock";
		parameters[]=
		{
			"STRING"
		};
	};
	class updateHackAttemptRequest
	{
		module="object_lock";
		parameters[]=
		{
			"STRING"
		};
	};
	class startHackRequest
	{
		module="object_lock";
		parameters[]=
		{
			"STRING"
		};
	};
	class grindNotificationRequest
	{
		module="object_lock";
		parameters[]=
		{
			"STRING"
		};
	};
	class grindLockRequest
	{
		module="object_lock";
		parameters[]=
		{
			"STRING"
		};
	};
	class storeVehicleRequest
	{
		module="vehicle";
		parameters[]=
		{
			"STRING",
			"STRING"
		};
	};
	class storeVehicleResponse
	{
		module="object_vehicle";
		parameters[]=
		{
			"BOOL",
			"STRING"
		};
	};
	class retrieveVehicleRequest
	{
		module="vehicle";
		parameters[]=
		{
			"STRING"
		};
	};
	class retrieveVehicleResponse
	{
		module="object_vehicle";
		parameters[]=
		{
			"BOOL"
		};
	};
	class startAirdrop
	{
		module="airdrop";
		parameters[] = {"STRING","STRING","STRING"};
	};
};
class CfgPoptabStorage
{
	class Extremo_Container_Safe_Small { max = 25000; };	
};
class CfgSimulation
{
	/*
		Use Arma built in Dynamic Simulation. 
		If you have any issues with players unable to get into cars, control vehicles, fly planes, etc. try turning this off
		Options:
			0: Use Extremo's built in simulation system (Same system in 1.0.3 and below)
			1: Use Dynamic Simulation
	*/
	enableDynamicSimulation = 1;
	
	/*
		Simulation distance settings
		For more information:
			https://community.bistudio.com/wiki/setDynamicSimulationDistance
			https://community.bistudio.com/wiki/setDynamicSimulationDistanceCoef
	*/
	
	// The distance, in meters, will infantry units be simulated. Default: 500m
	groupSimulationDistance = 500;
	
	// The distance, in meters, will vehicles with crew be simulated. Default: 350m
	vehicleSimulationDistance = 250;
	
	// The distance, in meters, will all vehicles without crew be simulated. Default: 250m
	emptyVehicleSimulationDistance = 250;
	
	// The distance, in meters, will static objects be simulated. This includes anything from a small tin can to a building. Default: 50m
	propSimulationDistance = 50;
	
	// Multiplies the entity activation distance by set value if the entity is moving. Default: 2
	isMovingSimulationCoef = 2;
};
class CfgSFX
{
	class Extremo_Sfx_Flies
	{
		name="Extremo Flies";
		sounds[]=
		{
			"flies01"
		};
		flies01[]=
		{
			"\Extremo_Assets\sound\flies.ogg",
			3,
			1,
			60,
			1,
			0,
			0,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			1,
			3,
			5
		};
	};
	class Extremo_Sfx_PortableGenerator
	{
		name="Extremo Extremo_Sfx_PortableGenerator";
		sounds[]=
		{
			"noise01"
		};
		noise01[]=
		{
			"\a3\sounds_f\ambient\objects\aircontition_5.wss",
			1,
			1,
			50,
			1,
			0,
			0,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			1,
			3,
			5
		};
	};
	class Extremo_Sfx_Grinding
	{
		name="Extremo Extremo_Sfx_Grinding";
		sounds[]=
		{
			"grind01"
		};
		grind01[]=
		{
			"\Extremo_Assets\sound\Extremo_Grinding01.wss",
			1.5,
			1,
			50,
			1,
			0,
			0,
			0
		};
		empty[]=
		{
			"",
			0,
			0,
			0,
			0,
			1,
			3,
			5
		};
	};
};
class CfgTwinkleTwister
{
	chances[]=
	{
		
		{
			30,
			""
		},
		
		{
			40,
			"FreeRound"
		},
		
		{
			70,
			"GloriousKnakworst"
		},
		
		{
			80,
			"InstaDoc"
		},
		
		{
			95,
			"CookingPot"
		},
		
		{
			100,
			"Rangefinder"
		}
	};
	class Prizes
	{
		class FreeRound
		{
			name="100 Pop Tabs";
			symbol="Banana";
			color="#e4e645";
			type=0;
			prize=100;
		};
		class GloriousKnakworst
		{
			name="Glorious Knakworst";
			symbol="Strawberry";
			color="#c90d0d";
			type=1;
			prize="Extremo_Item_GloriousKnakworst";
		};
		class InstaDoc
		{
			name="InstaDoc";
			symbol="Cucumber";
			color="#9eed3f";
			type=1;
			prize="Extremo_Item_InstaDoc";
		};
		class CookingPot
		{
			name="Cooking Pot";
			symbol="Pineapple";
			color="#e4e645";
			type=1;
			prize="Extremo_Item_CookingPot";
		};
		class Rangefinder
		{
			name="Rangefinder";
			symbol="Grape";
			color="#304bef";
			type=1;
			prize="Rangefinder";
		};
	};
};
class CfgUnitInsignia
{
	class ExtremoBrunswik
	{
		author="Nikko Renolds";
		displayName="Brunswik";
		texture="\Extremo_Assets\texture\insignia\brunswik_ca.paa";
		textureVehicle="";
		scopeArsenal=2;
	};
	class Extremo
	{
		author="Nikko Renolds";
		displayName="Extremo";
		texture="\Extremo_Assets\texture\insignia\Extremo_co.paa";
		textureVehicle="";
		scopeArsenal=2;
	};
};
class CfgClanMakerIcons
{
	Icons[]=
	{
		
		{
			"Text only",
			"\A3\ui_f\data\map\markers\system\dummy_ca.paa"
		},
		
		{
			"Empty",
			"\A3\ui_f\data\map\markers\system\empty_ca.paa"
		},
		
		{
			"Objective",
			"\A3\ui_f\data\map\markers\military\objective_CA.paa"
		},
		
		{
			"Marker",
			"\A3\ui_f\data\map\markers\military\marker_CA.paa"
		},
		
		{
			"Flag",
			"\A3\ui_f\data\map\markers\military\flag_CA.paa"
		},
		
		{
			"Arrow",
			"\A3\ui_f\data\map\markers\military\arrow_CA.paa"
		},
		
		{
			"Arrow (filled)",
			"\A3\ui_f\data\map\markers\military\arrow2_CA.paa"
		},
		
		{
			"Ambush",
			"\A3\ui_f\data\map\markers\military\ambush_CA.paa"
		},
		
		{
			"Destroy",
			"\A3\ui_f\data\map\markers\military\destroy_CA.paa"
		},
		
		{
			"Start",
			"\A3\ui_f\data\map\markers\military\start_CA.paa"
		},
		
		{
			"End",
			"\A3\ui_f\data\map\markers\military\end_CA.paa"
		},
		
		{
			"Pick Up",
			"\A3\ui_f\data\map\markers\military\pickup_CA.paa"
		},
		
		{
			"Join",
			"\A3\ui_f\data\map\markers\military\join_CA.paa"
		},
		
		{
			"Warning",
			"\A3\ui_f\data\map\markers\military\warning_CA.paa"
		},
		
		{
			"Unknown",
			"\A3\ui_f\data\map\markers\military\unknown_CA.paa"
		},
		
		{
			"Circle",
			"\A3\ui_f\data\map\markers\military\circle_CA.paa"
		},
		
		{
			"Dot",
			"\A3\ui_f\data\map\markers\military\dot_CA.paa"
		},
		
		{
			"Square",
			"\A3\ui_f\data\map\markers\military\box_CA.paa"
		},
		
		{
			"Triangle",
			"\A3\ui_f\data\map\markers\military\triangle_CA.paa"
		},
		
		{
			"Select",
			"\A3\ui_f\data\igui\cfg\islandmap\iconplayer_ca.paa"
		},
		
		{
			"Waypoint",
			"\A3\ui_f\data\map\groupicons\waypoint.paa"
		},
		
		{
			"Selector - Selectable",
			"\A3\ui_f\data\map\groupicons\selector_selectable_ca.paa"
		},
		
		{
			"Selector - Selected Enemy",
			"\A3\ui_f\data\map\groupicons\selector_selectedEnemy_ca.paa"
		},
		
		{
			"Selector - Selected Friendly",
			"\A3\ui_f\data\map\groupicons\selector_selectedFriendly_ca.paa"
		},
		
		{
			"Selector - Selected Mission",
			"\A3\ui_f\data\map\groupicons\selector_selectedMission_ca.paa"
		},
		
		{
			"KIA",
			"\a3\Ui_F_Curator\Data\CfgMarkers\kia_ca.paa"
		},
		
		{
			"Minefield",
			"\a3\Ui_F_Curator\Data\CfgMarkers\minefield_ca.paa"
		},
		
		{
			"Minefield (AP)",
			"\a3\Ui_F_Curator\Data\CfgMarkers\minefieldAP_ca.paa"
		},
		
		{
			"NATO",
			"\A3\ui_f\data\map\markers\flags\nato_ca.paa"
		},
		
		{
			"CSAT",
			"\A3\ui_f\data\map\markers\flags\CSAT_ca.paa"
		},
		
		{
			"Altis Armed Forces",
			"\A3\ui_f\data\map\markers\flags\AAF_ca.paa"
		},
		
		{
			"Altis",
			"\A3\ui_f\data\map\markers\flags\Altis_ca.paa"
		},
		
		{
			"Altis (Colonial)",
			"\A3\ui_f\data\map\markers\flags\AltisColonial_ca.paa"
		},
		
		{
			"FIA",
			"\A3\ui_f\data\map\markers\flags\FIA_ca.paa"
		},
		
		{
			"European Union",
			"\A3\ui_f\data\map\markers\flags\EU_ca.paa"
		},
		
		{
			"United Nations",
			"\A3\ui_f\data\map\markers\flags\UN_ca.paa"
		},
		
		{
			"Belgium",
			"\A3\ui_f\data\map\markers\flags\Belgium_ca.paa"
		},
		
		{
			"Canada",
			"\A3\ui_f\data\map\markers\flags\Canada_ca.paa"
		},
		
		{
			"Croatia",
			"\A3\ui_f\data\map\markers\flags\Croatia_ca.paa"
		},
		
		{
			"Czech Republic",
			"\A3\ui_f\data\map\markers\flags\CzechRepublic_ca.paa"
		},
		
		{
			"Denmark",
			"\A3\ui_f\data\map\markers\flags\Denmark_ca.paa"
		},
		
		{
			"France",
			"\A3\ui_f\data\map\markers\flags\France_ca.paa"
		},
		
		{
			"Georgia",
			"\A3\ui_f\data\map\markers\flags\Georgia_ca.paa"
		},
		
		{
			"Germany",
			"\A3\ui_f\data\map\markers\flags\Germany_ca.paa"
		},
		
		{
			"Greece",
			"\A3\ui_f\data\map\markers\flags\Greece_ca.paa"
		},
		
		{
			"Hungary",
			"\A3\ui_f\data\map\markers\flags\Hungary_ca.paa"
		},
		
		{
			"Iceland",
			"\A3\ui_f\data\map\markers\flags\Iceland_ca.paa"
		},
		
		{
			"Italy",
			"\A3\ui_f\data\map\markers\flags\Italy_ca.paa"
		},
		
		{
			"Luxembourg",
			"\A3\ui_f\data\map\markers\flags\Luxembourg_ca.paa"
		},
		
		{
			"Netherlands",
			"\A3\ui_f\data\map\markers\flags\Netherlands_ca.paa"
		},
		
		{
			"Norway",
			"\A3\ui_f\data\map\markers\flags\Norway_ca.paa"
		},
		
		{
			"Poland",
			"\A3\ui_f\data\map\markers\flags\Poland_ca.paa"
		},
		
		{
			"Portugal",
			"\A3\ui_f\data\map\markers\flags\Portugal_ca.paa"
		},
		
		{
			"Slovakia",
			"\A3\ui_f\data\map\markers\flags\Slovakia_ca.paa"
		},
		
		{
			"Slovenia",
			"\A3\ui_f\data\map\markers\flags\Slovenia_ca.paa"
		},
		
		{
			"Spain",
			"\A3\ui_f\data\map\markers\flags\Spain_ca.paa"
		},
		
		{
			"UK",
			"\A3\ui_f\data\map\markers\flags\UK_ca.paa"
		},
		
		{
			"USA",
			"\A3\ui_f\data\map\markers\flags\USA_ca.paa"
		}
	};
};
class CfgCloudlets
{
	class Default;
	class Extremo_Snow_Close: Default
	{
		destroyOnWaterSurface=1;
		destroyOnWaterSurfaceOffset=0;
		onSurface=0;
		keepOnSurface=0;
		surfaceOffset=0;
		bounceOnSurface=-1;
		bounceOnSurfaceVar=0;
		postEffects="";
		particleEffects="";
		blockAIVisibility=0;
		emissiveColor[]=
		{
			{2,2,2,0}
		};
		particleType="Billboard";
		particleShape="\Extremo_Assets\model\Extremo_Snow";
		particleFSFrameCount=1;
		particleFSIndex=0;
		particleFSLoop=0;
		particleFSNtieth=3;
		circleRadius=5;
		circleVelocity[]={0,0,0};
		angle=0;
		angleVar=360;
		animationSpeedCoef=1;
		animationSpeed[]={1};
		animationName="";
		color[]=
		{
			{2,2,2,0},
			{2,2,2,2},
			{2,2,2,2},
			{2,2,2,2},
			{2,2,2,2},
			{2,2,2,2},
			{2,2,2,2},
			{2,2,2,0}
		};
		colorCoef[]={1,1,1,1};
		colorVar[]={0,0,0,0};
		interval=0.0099999998;
		lifeTime=6;
		lifeTimeVar=1;
		timerPeriod=30;
		onTimerScript="";
		beforeDestroyScript="";
		moveVelocity[]={0,0,-0.30000001};
		moveVelocityVar[]={0,0,0.1};
		moveVelocityVarConst[]={0,0,0};
		position[]={0,0,0};
		positionVar[]={5,5,0};
		positionVarConst[]={0,0,0};
		rotationVelocity=2;
		rotationVelocityVar=2;
		size[]={1};
		sizeCoef=1;
		sizeVar=0.5;
		weight=1;
		volume=0.75;
		rubbing=0.050000001;
		randomDirectionIntensity=0;
		randomDirectionIntensityVar=0;
		randomDirectionPeriod=0;
		randomDirectionPeriodVar=0;
	};
	class Extremo_Snow_Near: Extremo_Snow_Close
	{
		particleFSIndex=0;
		positionVar[]={6,6,0};
		lifeTime=7;
	};
	class Extremo_Snow_Far: Extremo_Snow_Close
	{
		particleFSIndex=2;
		positionVar[]={7,7,0};
		lifeTime=8;
	};
}; 
class CfgExtremoHUD
{
	class ShortItemNames
	{
		SmokeShell[] 						= {"WHITE", 	"SMOKE"};
		1Rnd_Smoke_Grenade_shell[] 			= {"WHITE", 	"SMOKE"};
		3Rnd_Smoke_Grenade_shell[] 			= {"WHITE", 	"SMOKE"};

		SmokeShellBlue[] 					= {"BLUE", 		"SMOKE"};
		1Rnd_SmokeBlue_Grenade_shell[] 		= {"BLUE", 		"SMOKE"};
		3Rnd_SmokeBlue_Grenade_shell[] 		= {"BLUE", 		"SMOKE"};

		SmokeShellGreen[] 					= {"GREEN", 	"SMOKE"};
		1Rnd_SmokeGreen_Grenade_shell[] 	= {"GREEN", 	"SMOKE"};
		3Rnd_SmokeGreen_Grenade_shell[] 	= {"GREEN", 	"SMOKE"};

		SmokeShellOrange[] 					= {"ORANGE", 	"SMOKE"};
		1Rnd_SmokeOrange_Grenade_shell[]	= {"ORANGE", 	"SMOKE"};
		3Rnd_SmokeOrange_Grenade_shell[] 	= {"ORANGE", 	"SMOKE"};

		SmokeShellPurple[] 					= {"PURPLE", 	"SMOKE"};
		1Rnd_SmokePurple_Grenade_shell[] 	= {"PURPLE", 	"SMOKE"};
		3Rnd_SmokePurple_Grenade_shell[] 	= {"PURPLE", 	"SMOKE"};

		SmokeShellRed[] 					= {"RED", 		"SMOKE"};
		1Rnd_SmokeRed_Grenade_shell[] 		= {"RED", 		"SMOKE"};
		3Rnd_SmokeRed_Grenade_shell[] 		= {"RED", 		"SMOKE"};
				
		SmokeShellYellow[] 					= {"YELLOW", 	"SMOKE"};
		1Rnd_SmokeYellow_Grenade_shell[] 	= {"YELLOW", 	"SMOKE"};
		3Rnd_SmokeYellow_Grenade_shell[] 	= {"YELLOW", 	"SMOKE"};
				
		UGL_FlareCIR_F[] 					= {"IR", 		"FLARE"};
		3Rnd_UGL_FlareCIR_F[] 				= {"IR", 		"FLARE"};

		UGL_FlareGreen_F[] 					= {"GREEN", 	"FLARE"};
		3Rnd_UGL_FlareGreen_F[] 			= {"GREEN", 	"FLARE"};

		UGL_FlareRed_F[] 					= {"RED", 		"FLARE"};
		3Rnd_UGL_FlareRed_F[] 				= {"RED", 		"FLARE"};

		UGL_FlareWhite_F[] 					= {"WHITE", 	"FLARE"};
		3Rnd_UGL_FlareWhite_F[] 			= {"WHITE", 	"FLARE"};

		UGL_FlareYellow_F[] 				= {"YELLOW", 	"FLARE"};
		3Rnd_UGL_FlareYellow_F[] 			= {"YELLOW", 	"FLARE"};

		Chemlight_blue[] 					= {"BLUE", 		"LIGHT"};
		Chemlight_green[] 					= {"GREEN", 	"LIGHT"};
		Chemlight_red[] 					= {"RED", 		"LIGHT"};
		Chemlight_yellow[] 					= {"YELLOW", 	"LIGHT"};

		1Rnd_HE_Grenade_shell[] 			= {"40MM"};
		3Rnd_HE_Grenade_shell[] 			= {"40MM"};

		O_IR_Grenade[] 						= {"IR"};
		I_IR_Grenade[] 						= {"IR"};
		B_IR_Grenade[] 						= {"IR"};

		HandGrenade[] 						= {"RGO"};
		MiniGrenade[] 						= {"RGN"};

		Extremo_Item_ZipTie[]					= {"ZIP", "TIE"};
	};
};
class CfgExtremoParty 
{
	showESP = 1;
	allow3DMarkers = 1;
};
class CfgPlayer 
{
	hungerDecay = 90;
	thirstDecay = 60;

	healthDecay = 5.0;

	thirstRegen = 90;
	hungerRegen = 90;

	recoveryPerMinute = 2;

	customAimCoefficient = 0.5;

	enableFatigue = 0;
	enableStamina = 0;

	autorun = 1;
	autoswim = 1;//needs auto run enabled
};
class CfgClans
{
	registrationFee = 20000;
	clanNameAlphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 -!";
};
class SpawnVehicleItems
{
    class WorldVehicles
	{
        vehicleItemsAllowed = 1;
        maximumItemsPerVehicle = 5;

        allowedItems[] = {
            "Extremo_Item_ToiletPaper",
            "Extremo_Item_PlasticBottleEmpty",
            "Extremo_Item_Can_Empty",
            "Extremo_Item_Rope",
			"Extremo_Item_DuctTape",
			"Extremo_Item_ExtensionCord",
			"Extremo_Item_FuelCanisterEmpty",
			"Extremo_Item_JunkMetal",
			"Extremo_Item_WoodPlank",
			"Extremo_Item_MetalPole",
			"class Extremo_Item_LightBulb",
			"Extremo_Melee_Axe",
			"Extremo_Melee_Pickaxe",
			"Extremo_Melee_Sword",			
			"Extremo_Item_metalboard"
        };
    };
};
class CfgCraftingRecipes
{
	class CookBBQSandwich: Extremo_AbstractCraftingRecipe
	{
		name = "Cook BBQ Sandwich";
		pictureItem = "Extremo_Item_BBQSandwich_Cooked";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_BBQSandwich_Cooked"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_BBQSandwich"}
		};
	};
	class CookCatFood: Extremo_AbstractCraftingRecipe
	{
		name = "Cook Cat Food";
		pictureItem = "Extremo_Item_CatFood_Cooked";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_CatFood_Cooked"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_CatFood"}
		};
	};
	class CookChristmasTinner: Extremo_AbstractCraftingRecipe
	{
		name = "Cook Christmas Tinner";
		pictureItem = "Extremo_Item_ChristmasTinner_Cooked";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_ChristmasTinner_Cooked"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_ChristmasTinner"}
		};
	};
	class CookCoffee: Extremo_AbstractCraftingRecipe
	{
		name = "Brew Coffee";
		pictureItem = "Extremo_Item_PlasticBottleCoffee";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_PlasticBottleCoffee"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_PlasticBottleFreshWater"},
			{1, "Extremo_Item_InstantCoffee"}
		};
	};
	class CookDogFood: Extremo_AbstractCraftingRecipe
	{
		name = "Cook Dog Food";
		pictureItem = "Extremo_Item_DogFood_Cooked";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_DogFood_Cooked"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_DogFood"}
		};
	};
	class CookGloriousKnakworst: Extremo_AbstractCraftingRecipe
	{
		name = "Cook Glorious Knakworst";
		pictureItem = "Extremo_Item_GloriousKnakworst_Cooked";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_GloriousKnakworst_Cooked"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_GloriousKnakworst"}
		};
	};
	class CookPlasticBottleDirtyWater: Extremo_AbstractCraftingRecipe
	{
		name = "Cook Dirty Water";
		pictureItem = "Extremo_Item_PlasticBottleFreshWater";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_PlasticBottleFreshWater"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_PlasticBottleDirtyWater"}
		};
	};
	class CookPlasticBottleSaltWater: Extremo_AbstractCraftingRecipe
	{
		name = "Cook Salt Water";
		pictureItem = "Extremo_Item_PlasticBottleFreshWater";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_PlasticBottleFreshWater"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_PlasticBottleSaltWater"}
		};
	};
	class CookSausageGravy: Extremo_AbstractCraftingRecipe
	{
		name = "Cook Sausage Gravy";
		pictureItem = "Extremo_Item_SausageGravy_Cooked";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_SausageGravy_Cooked"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_SausageGravy"}
		};
	};
	class CookSurstromming: Extremo_AbstractCraftingRecipe
	{
		name = "Cook Surströmming";
		pictureItem = "Extremo_Item_Surstromming_Cooked";
		requiresFire = 1;
		returnedItems[] =
		{
			{1, "Extremo_Item_Surstromming_Cooked"}
		};
		tools[] =
		{
			"Extremo_Item_CookingPot"
		};
		components[] = 
		{
			{1, "Extremo_Item_Surstromming"}
		};
	};
	class CraftBushKitGreen: Extremo_AbstractCraftingRecipe
	{
		name = "Craft a Bush Kit (Green)";
		pictureItem = "Extremo_Item_BushKit_Green";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_BushKit_Green"}
		};
		components[] = 
		{
			{10, "Extremo_Item_Leaves"},
			{5, "Extremo_Item_WoodSticks"},
			{1, "Extremo_Item_Rope"}
		};
	};
	class CraftFirePlace: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Fire Place";
		pictureItem = "Extremo_Item_CampFireKit";
		returnedItems[] = 
		{
			{1, "Extremo_Item_CampFireKit"}
		};
		components[] = 
		{
			{2, "Extremo_Item_WoodLog"}
		};
	};
	class CraftFloodLight: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Flood Light";
		pictureItem = "Extremo_Item_FloodLightKit";
		requiresFire = 1;
		returnedItems[] = 
		{
			{1, "Extremo_Item_FloodLightKit"}
		};
		components[] = 
		{
			{1, "Extremo_Item_MetalPole"},
			{1, "Extremo_Item_LightBulb"},
			{1, "Extremo_Item_ExtensionCord"}
		};
	};
	class CraftFortificationUpgrade: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Fortification Upgrade";
		pictureItem = "Extremo_Item_MetalBoard"; //<< CHANGE IT
		requiresFire = 1;
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_FortificationUpgrade"}
		};
		components[] = 
		{
			{2, "Extremo_Item_MetalPole"},
			{4, "Extremo_Item_MetalBoard"}
		};
		tools[] = {"Extremo_Item_Grinder"};
	};
	class CraftMetalBoard: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Metal Board";
		pictureItem = "Extremo_Item_MetalBoard";
		requiresFire = 1;
		returnedItems[] = 
		{
			{1, "Extremo_Item_MetalBoard"}
		};
		components[] = 
		{
			{2, "Extremo_Item_JunkMetal"}
		};
		tools[] = {"Extremo_Item_Grinder"};
	};
	class CraftMetalPole: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Metal Pole";
		pictureItem = "Extremo_Item_MetalPole";
		requiresFire = 1;
		returnedItems[] = 
		{
			{1, "Extremo_Item_MetalPole"}
		};
		components[] = 
		{
			{4, "Extremo_Item_JunkMetal"}
		};
		tools[] = {"Extremo_Item_Grinder"};
	};
	class CraftPortableGenerator: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Portable Generator";
		pictureItem = "Extremo_Item_PortableGeneratorKit";
		requiresFire = 1;
		returnedItems[] = 
		{
			{1, "Extremo_Item_PortableGeneratorKit"}
		};
		components[] = 
		{
			{4, "Extremo_Item_MetalBoard"},
			{1, "Extremo_Item_FuelCanisterFull"},
			{1, "Extremo_Item_ExtensionCord"}
		};
	};
	class CraftStorageCrate: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Storage Crate";
		pictureItem = "Extremo_Item_StorageCrateKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_StorageCrateKit"}
		};
		components[] = 
		{
			{5, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodDoorWay: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Doorway";
		pictureItem = "Extremo_Item_WoodDoorwayKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodDoorwayKit"}
		};
		components[] = 
		{
			{6, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodFloor: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Floor";
		pictureItem = "Extremo_Item_WoodFloorKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodFloorKit"}
		};
		components[] = 
		{
			{4, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodFloorPort: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Floor Port";
		pictureItem = "Extremo_Item_WoodFloorPortKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodFloorPortKit"}
		};
		components[] = 
		{
			{6, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodGate: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Gate";
		pictureItem = "Extremo_Item_WoodGateKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodGateKit"}
		};
		components[] = 
		{
			{8, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodPlank: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Plank";
		pictureItem = "Extremo_Item_WoodPlank";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodPlank"}
		};
		components[] = 
		{
			{2, "Extremo_Item_WoodLog"}
		};
		tools[] = {"Extremo_Item_Handsaw"};
	};
	class CraftWoodStairs: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Stairs";
		pictureItem = "Extremo_Item_WoodStairsKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodStairsKit"}
		};
		components[] = 
		{
			{6, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodSupport: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Support";
		pictureItem = "Extremo_Item_WoodSupportKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodSupportKit"}
		};
		components[] = 
		{
			{6, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodWall: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Wall";
		pictureItem = "Extremo_Item_WoodWallKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodWallKit"}
		};
		components[] = 
		{
			{4, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodWallHalf: Extremo_AbstractCraftingRecipe
	{
		name = "Craft 1/2 Wood Wall";
		pictureItem = "Extremo_Item_WoodWallHalfKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodWallHalfKit"}
		};
		components[] = 
		{
			{2, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWoodWindow: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Wood Window";
		pictureItem = "Extremo_Item_WoodWindowKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodWindowKit"}
		};
		components[] = 
		{
			{6, "Extremo_Item_WoodPlank"}
		};
	};
	class CraftWorkBench: Extremo_AbstractCraftingRecipe
	{
		name = "Craft Work Bench";
		pictureItem = "Extremo_Item_WorkBenchKit";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WorkBenchKit"}
		};
		components[] = 
		{
			{4, "Extremo_Item_WoodLog"}
		};
	};
	class EmptyFuelCanister: Extremo_AbstractCraftingRecipe
	{
		name = "Empty Fuel Canister";
		pictureItem = "Extremo_Item_FuelCanisterEmpty";
		returnedItems[] = 
		{
			{1, "Extremo_Item_FuelCanisterEmpty"}
		};
		components[] = 
		{
			{1, "Extremo_Item_FuelCanisterFull"}
		};
	};
	class EmptyPlasticBottleDirtyWater: Extremo_AbstractCraftingRecipe
	{
		name = "Empty Dirty Water";
		pictureItem = "Extremo_Item_PlasticBottleEmpty";
		returnedItems[] =
		{
			{1, "Extremo_Item_PlasticBottleEmpty"}
		};
		components[] =
		{
			{1, "Extremo_Item_PlasticBottleDirtyWater"}
		};
	};
	class EmptyPlasticBottleSaltWater: Extremo_AbstractCraftingRecipe
	{
		name = "Empty Salt Water";
		pictureItem = "Extremo_Item_PlasticBottleEmpty";
		returnedItems[] =
		{
			{1, "Extremo_Item_PlasticBottleEmpty"}
		};
		components[] =
		{
			{1, "Extremo_Item_PlasticBottleSaltWater"}
		};
	};
	class FillEmptyPlasticBottleWithDirtyWater: Extremo_AbstractCraftingRecipe
	{
		name = "Fill Dirty Water";
		pictureItem = "Extremo_Item_PlasticBottleDirtyWater";
		requiredInteractionModelGroup = "WaterSource";
		returnedItems[] =
		{
			{1, "Extremo_Item_PlasticBottleDirtyWater"}
		};
		components[] = 
		{
			{1, "Extremo_Item_PlasticBottleEmpty"}
		};
	};
	class FillEmptyPlasticBottleWithFreshWater: Extremo_AbstractCraftingRecipe
	{
		name = "Fill Fresh Water";
		pictureItem = "Extremo_Item_PlasticBottleFreshWater";
		requiredInteractionModelGroup = "CleanWaterSource";
		returnedItems[] =
		{
			{1, "Extremo_Item_PlasticBottleFreshWater"}
		};
		components[] = 
		{
			{1, "Extremo_Item_PlasticBottleEmpty"}
		};
	};
	class FillEmptyPlasticBottleWithSaltWater: Extremo_AbstractCraftingRecipe
	{
		name = "Fill Salt Water";
		pictureItem = "Extremo_Item_PlasticBottleSaltWater";
		requiresOcean = 1;
		returnedItems[] = 
		{
			{1, "Extremo_Item_PlasticBottleSaltWater"}
		};
		components[] = 
		{
			{1, "Extremo_Item_PlasticBottleEmpty"}
		};
	};
	class FillFuelCanister: Extremo_AbstractCraftingRecipe
	{
		name = "Fill Fuel Canister";
		pictureItem = "Extremo_Item_FuelCanisterFull";
		requiredInteractionModelGroup = "FuelSource";
		returnedItems[] = 
		{
			{1, "Extremo_Item_FuelCanisterFull"}
		};
		components[] = 
		{
			{1, "Extremo_Item_FuelCanisterEmpty"}
		};
	};
	class UpgradeToWoodDoor: Extremo_AbstractCraftingRecipe
	{
		name = "Upgrade to Wood Door";
		pictureItem = "Extremo_Item_WoodDoorKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodDoorKit"}
		};
		components[] = 
		{
			{1, "Extremo_Item_WoodDoorwayKit"},
			{2, "Extremo_Item_WoodPlank"}
		};
	};
	class UpgradeToWoodFloorPort: Extremo_AbstractCraftingRecipe
	{
		name = "Upgrade to Wood Floor Port";
		pictureItem = "Extremo_Item_WoodFloorPortKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodFloorPortKit"}
		};
		components[] = 
		{
			{1, "Extremo_Item_WoodFloorKit"},
			{2, "Extremo_Item_WoodPlank"}
		};
	};
	class UpgradeToWoodGate: Extremo_AbstractCraftingRecipe
	{
		name = "Upgrade to Wood Gate";
		pictureItem = "Extremo_Item_WoodGateKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodGateKit"}
		};
		components[] = 
		{
			{1, "Extremo_Item_WoodWallKit"},
			{4, "Extremo_Item_WoodPlank"}
		};
	};
	class UpgradeToWoodWall: Extremo_AbstractCraftingRecipe
	{
		name = "Upgrade to Wood Wall";
		pictureItem = "Extremo_Item_WoodWallHalfKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodWallKit"}
		};
		components[] = 
		{
			{2, "Extremo_Item_WoodWallHalfKit"}
		};
	};
	class UpgradeToWoodWindow: Extremo_AbstractCraftingRecipe
	{
		name = "Upgrade to Wood Window";
		pictureItem = "Extremo_Item_WoodWindowKit";
		requiredInteractionModelGroup = "WorkBench";
		returnedItems[] = 
		{
			{1, "Extremo_Item_WoodWindowKit"}
		};
		components[] = 
		{
			{1, "Extremo_Item_WoodWallKit"},
			{2, "Extremo_Item_WoodPlank"}
		};
	};
};
class CfgExtremoArsenal
{
	class Extremo_Uniform_BambiOverall				{ quality = 1; price = 1; sellPrice = 1; };

	class U_C_Journalist 							{ quality = 1; price = 20; };
	class U_C_Poloshirt_blue 						{ quality = 1; price = 20; };
	class U_C_Poloshirt_burgundy 					{ quality = 1; price = 20; };
	class U_C_Poloshirt_salmon 						{ quality = 1; price = 20; };
	class U_C_Poloshirt_stripped 					{ quality = 1; price = 20; };
	class U_C_Poloshirt_tricolour 					{ quality = 1; price = 20; };
	class U_C_Poor_1 								{ quality = 1; price = 20; };
	class U_C_Poor_2 								{ quality = 1; price = 20; };
	class U_C_Poor_shorts_1 						{ quality = 1; price = 20; };
	class U_C_Scientist 							{ quality = 1; price = 20; };
	class U_OrestesBody 							{ quality = 3; price = 40; };
	class U_Rangemaster 							{ quality = 1; price = 40; };
	class U_NikosAgedBody 							{ quality = 3; price = 40; };
	class U_NikosBody 								{ quality = 3; price = 40; };
	class U_Competitor 								{ quality = 1; price = 40; };

	class U_B_CombatUniform_mcam 					{ quality = 2; price = 40; };
	class U_B_CombatUniform_mcam_tshirt 			{ quality = 1; price = 40; };
	class U_B_CombatUniform_mcam_vest 				{ quality = 1; price = 40; };
	class U_B_CombatUniform_mcam_worn 				{ quality = 1; price = 40; };
	class U_B_CTRG_1 								{ quality = 2; price = 40; };
	class U_B_CTRG_2 								{ quality = 2; price = 40; };
	class U_B_CTRG_3								{ quality = 2; price = 40; };
	class U_I_CombatUniform 						{ quality = 1; price = 40; };
	class U_I_CombatUniform_shortsleeve				{ quality = 1; price = 40; };
	class U_I_CombatUniform_tshirt					{ quality = 1; price = 40; };
	class U_I_OfficerUniform						{ quality = 1; price = 40; };
	class U_O_CombatUniform_ocamo 					{ quality = 1; price = 40; };
	class U_O_CombatUniform_oucamo 					{ quality = 1; price = 40; };
	class U_O_OfficerUniform_ocamo 					{ quality = 3; price = 80; };
	class U_B_SpecopsUniform_sgg 					{ quality = 3; price = 80; };
	class U_O_SpecopsUniform_blk 					{ quality = 3; price = 80; };
	class U_O_SpecopsUniform_ocamo 					{ quality = 3; price = 80; };
	class U_I_G_Story_Protagonist_F 				{ quality = 3; price = 100; };
	class Extremo_Uniform_Woodland 					{ quality = 3; price = 150; };

	class U_C_HunterBody_grn						{ quality = 1; price = 40; };
	class U_IG_Guerilla1_1							{ quality = 1; price = 40; };
	class U_IG_Guerilla2_1							{ quality = 2; price = 60; };
	class U_IG_Guerilla2_2							{ quality = 1; price = 40; };
	class U_IG_Guerilla2_3							{ quality = 1; price = 40; };
	class U_IG_Guerilla3_1							{ quality = 1; price = 40; };
	class U_BG_Guerilla2_1							{ quality = 1; price = 40; };
	class U_IG_Guerilla3_2							{ quality = 1; price = 40; };
	class U_BG_Guerrilla_6_1						{ quality = 2; price = 60; };
	class U_BG_Guerilla1_1							{ quality = 1; price = 40; };
	class U_BG_Guerilla2_2							{ quality = 1; price = 40; };
	class U_BG_Guerilla2_3							{ quality = 1; price = 40; };
	class U_BG_Guerilla3_1							{ quality = 1; price = 40; };
	class U_BG_leader								{ quality = 1; price = 40; };
	class U_IG_leader								{ quality = 1; price = 40; };
	class U_I_G_resistanceLeader_F					{ quality = 3; price = 100; };

	class U_B_FullGhillie_ard						{ quality = 3; price = 150; };
	class U_B_FullGhillie_lsh						{ quality = 3; price = 150; };
	class U_B_FullGhillie_sard						{ quality = 3; price = 150; };
	class U_B_GhillieSuit							{ quality = 2; price = 100; };
	class U_I_FullGhillie_ard						{ quality = 3; price = 150; };
	class U_I_FullGhillie_lsh						{ quality = 3; price = 150; };
	class U_I_FullGhillie_sard						{ quality = 3; price = 150; };
	class U_I_GhillieSuit							{ quality = 2; price = 100; };
	class U_O_FullGhillie_ard						{ quality = 3; price = 150; };
	class U_O_FullGhillie_lsh						{ quality = 3; price = 150; };
	class U_O_FullGhillie_sard						{ quality = 3; price = 150; };
	class U_O_GhillieSuit							{ quality = 2; price = 100; };

	class U_I_Wetsuit								{ quality = 3; price = 80; };
	class U_O_Wetsuit								{ quality = 3; price = 80; };
	class U_B_Wetsuit								{ quality = 3; price = 80; };
	class U_B_survival_uniform						{ quality = 3; price = 80; };

	class V_BandollierB_blk							{ quality = 1; price = 20; };
	class V_BandollierB_cbr							{ quality = 1; price = 20; };
	class V_BandollierB_khk							{ quality = 1; price = 20; };
	class V_BandollierB_oli							{ quality = 1; price = 20; };
	class V_BandollierB_rgr							{ quality = 1; price = 20; };

	class V_Chestrig_blk 							{ quality = 1; price = 30; };
	class V_Chestrig_khk 							{ quality = 1; price = 30; };
	class V_Chestrig_oli 							{ quality = 1; price = 30; };
	class V_Chestrig_rgr 							{ quality = 1; price = 30; };

	class V_Press_F									{ quality = 1; price = 10; };
	class V_Rangemaster_belt						{ quality = 1; price = 6; };
	class V_TacVest_blk								{ quality = 2; price = 50; };
	class V_TacVest_blk_POLICE						{ quality = 3; price = 50; };
	class V_TacVest_brn								{ quality = 2; price = 50; };
	class V_TacVest_camo							{ quality = 2; price = 50; };
	class V_TacVest_khk								{ quality = 2; price = 50; };
	class V_TacVest_oli								{ quality = 2; price = 50; };
	class V_TacVestCamo_khk							{ quality = 2; price = 50; };
	class V_TacVestIR_blk							{ quality = 2; price = 50; };
	class V_I_G_resistanceLeader_F					{ quality = 2; price = 50; };

	class V_HarnessO_brn							{ quality = 1; price = 40; };
	class V_HarnessO_gry							{ quality = 1; price = 40; };
	class V_HarnessOGL_brn							{ quality = 1; price = 30; };
	class V_HarnessOGL_gry							{ quality = 1; price = 30; };
	class V_HarnessOSpec_brn						{ quality = 1; price = 40; };
	class V_HarnessOSpec_gry						{ quality = 1; price = 40; };

	class V_PlateCarrier1_blk 						{ quality = 1; price = 80; };
	class V_PlateCarrier1_rgr 						{ quality = 1; price = 80; };
	class V_PlateCarrier2_rgr 						{ quality = 2; price = 100; };
	class V_PlateCarrier3_rgr 						{ quality = 2; price = 100; };
	class V_PlateCarrierGL_blk 						{ quality = 3; price = 500; };
	class V_PlateCarrierGL_mtp 						{ quality = 3; price = 500; };
	class V_PlateCarrierGL_rgr 						{ quality = 3; price = 500; };
	class V_PlateCarrierH_CTRG 						{ quality = 2; price = 100; };
	class V_PlateCarrierIA1_dgtl 					{ quality = 2; price = 80; };
	class V_PlateCarrierIA2_dgtl 					{ quality = 2; price = 100; };
	class V_PlateCarrierIAGL_dgtl 					{ quality = 3; price = 400; };
	class V_PlateCarrierIAGL_oli 					{ quality = 3; price = 400; };
	class V_PlateCarrierL_CTRG 						{ quality = 2; price = 100; };
	class V_PlateCarrierSpec_blk 					{ quality = 3; price = 200; };
	class V_PlateCarrierSpec_mtp 					{ quality = 3; price = 200; };
	class V_PlateCarrierSpec_rgr 					{ quality = 3; price = 200; };

	class H_Cap_blk 								{ quality = 1; price = 6; };
	class H_Cap_blk_Raven 							{ quality = 1; price = 6; };
	class H_Cap_blu 								{ quality = 1; price = 6; };
	class H_Cap_brn_SPECOPS 						{ quality = 1; price = 6; };
	class H_Cap_grn 								{ quality = 1; price = 6; };
	class H_Cap_headphones 							{ quality = 1; price = 6; };
	class H_Cap_khaki_specops_UK 					{ quality = 1; price = 6; };
	class H_Cap_oli 								{ quality = 1; price = 6; };
	class H_Cap_press 								{ quality = 1; price = 6; };
	class H_Cap_red 								{ quality = 1; price = 6; };
	class H_Cap_tan 								{ quality = 1; price = 6; };
	class H_Cap_tan_specops_US 						{ quality = 1; price = 6; };

	class H_MilCap_blue 							{ quality = 1; price = 8; };
	class H_MilCap_dgtl 							{ quality = 1; price = 8; };
	class H_MilCap_mcamo 							{ quality = 1; price = 8; };
	class H_MilCap_ocamo 							{ quality = 1; price = 8; };
	class H_MilCap_oucamo 							{ quality = 1; price = 8; };
	class H_MilCap_rucamo 							{ quality = 1; price = 8; };

	class H_Watchcap_blk 							{ quality = 1; price = 6; };
	class H_Watchcap_camo 							{ quality = 1; price = 6; };
	class H_Watchcap_khk 							{ quality = 1; price = 6; };
	class H_Watchcap_sgg 							{ quality = 1; price = 6; };

	class H_Bandanna_camo							{ quality = 1; price = 4; };
	class H_Bandanna_cbr							{ quality = 1; price = 4; };
	class H_Bandanna_gry							{ quality = 1; price = 4; };
	class H_Bandanna_khk							{ quality = 1; price = 4; };
	class H_Bandanna_khk_hs							{ quality = 1; price = 4; };
	class H_Bandanna_mcamo							{ quality = 1; price = 4; };
	class H_Bandanna_sgg							{ quality = 1; price = 4; };
	class H_Bandanna_surfer							{ quality = 1; price = 4; };

	class H_Booniehat_dgtl							{ quality = 1; price = 6; };
	class H_Booniehat_dirty							{ quality = 1; price = 6; };
	class H_Booniehat_grn							{ quality = 1; price = 6; };
	class H_Booniehat_indp							{ quality = 1; price = 6; };
	class H_Booniehat_khk							{ quality = 1; price = 6; };
	class H_Booniehat_khk_hs						{ quality = 1; price = 6; };
	class H_Booniehat_mcamo							{ quality = 1; price = 6; };
	class H_Booniehat_tan							{ quality = 1; price = 6; };

	class H_Hat_blue								{ quality = 1; price = 6; };
	class H_Hat_brown								{ quality = 1; price = 6; };
	class H_Hat_camo								{ quality = 1; price = 6; };
	class H_Hat_checker								{ quality = 1; price = 6; };
	class H_Hat_grey								{ quality = 1; price = 6; };
	class H_Hat_tan									{ quality = 1; price = 6; };
	class H_StrawHat								{ quality = 1; price = 6; };
	class H_StrawHat_dark							{ quality = 1; price = 6; };

	class H_Beret_02								{ quality = 1; price = 6; };
	class H_Beret_blk								{ quality = 1; price = 6; };
	class H_Beret_blk_POLICE						{ quality = 1; price = 6; };
	class H_Beret_brn_SF							{ quality = 1; price = 6; };
	class H_Beret_Colonel							{ quality = 3; price = 8; };
	class H_Beret_grn								{ quality = 1; price = 6; };
	class H_Beret_grn_SF							{ quality = 1; price = 6; };
	class H_Beret_ocamo								{ quality = 1; price = 6; };
	class H_Beret_red								{ quality = 1; price = 6; };

	class H_Shemag_khk								{ quality = 1; price = 10; };
	class H_Shemag_olive							{ quality = 1; price = 10; };
	class H_Shemag_olive_hs							{ quality = 1; price = 10; };
	class H_Shemag_tan								{ quality = 1; price = 10; };
	class H_ShemagOpen_khk							{ quality = 1; price = 10; };
	class H_ShemagOpen_tan							{ quality = 1; price = 10; };
	class H_TurbanO_blk								{ quality = 1; price = 10; };

	class H_HelmetB_light							{ quality = 1; price = 20; };
	class H_HelmetB_light_black						{ quality = 1; price = 20; };
	class H_HelmetB_light_desert					{ quality = 1; price = 20; };
	class H_HelmetB_light_grass						{ quality = 1; price = 20; };
	class H_HelmetB_light_sand						{ quality = 1; price = 20; };
	class H_HelmetB_light_snakeskin					{ quality = 1; price = 20; };

	class H_HelmetIA								{ quality = 1; price = 40; };
	class H_HelmetIA_camo							{ quality = 1; price = 40; };
	class H_HelmetIA_net							{ quality = 1; price = 40; };
	class H_HelmetB									{ quality = 2; price = 60; };
	class H_HelmetB_black							{ quality = 2; price = 60; };
	class H_HelmetB_camo							{ quality = 3; price = 80; };
	class H_HelmetB_desert							{ quality = 2; price = 60; };
	class H_HelmetB_grass							{ quality = 2; price = 60; };
	class H_HelmetB_paint							{ quality = 2; price = 60; };
	class H_HelmetB_plain_blk						{ quality = 2; price = 60; };
	class H_HelmetB_sand							{ quality = 2; price = 60; };
	class H_HelmetB_snakeskin						{ quality = 2; price = 60; };

	class H_HelmetSpecB								{ quality = 2; price = 80; };
	class H_HelmetSpecB_blk							{ quality = 2; price = 80; };
	class H_HelmetSpecB_paint1						{ quality = 2; price = 80; };
	class H_HelmetSpecB_paint2						{ quality = 2; price = 80; };

	class H_HelmetO_ocamo							{ quality = 3; price = 150; };
	class H_HelmetO_oucamo							{ quality = 3; price = 150; };
	class H_HelmetSpecO_blk							{ quality = 3; price = 100; };
	class H_HelmetSpecO_ocamo						{ quality = 3; price = 100; };
	class H_HelmetLeaderO_ocamo						{ quality = 3; price = 200; };
	class H_HelmetLeaderO_oucamo					{ quality = 3; price = 200; };

	class acc_flashlight 							{ quality = 1; price = 4; };
	class acc_pointer_IR 							{ quality = 1; price = 10; };

	class bipod_01_F_blk	 						{ quality = 1; price = 10; };
	class bipod_01_F_mtp	 						{ quality = 1; price = 10; };
	class bipod_01_F_snd	 						{ quality = 1; price = 10; };
	class bipod_02_F_blk	 						{ quality = 1; price = 10; };
	class bipod_02_F_hex	 						{ quality = 1; price = 10; };
	class bipod_02_F_tan	 						{ quality = 1; price = 10; };
	class bipod_03_F_blk	 						{ quality = 1; price = 10; };
	class bipod_03_F_oli	 						{ quality = 1; price = 10; };

	class muzzle_snds_338_black 					{ quality = 2; price = 50; };
	class muzzle_snds_338_green 					{ quality = 2; price = 50; };
	class muzzle_snds_338_sand 						{ quality = 2; price = 50; };
	class muzzle_snds_93mmg 						{ quality = 2; price = 50; };
	class muzzle_snds_93mmg_tan 					{ quality = 2; price = 50; };
	class muzzle_snds_acp 							{ quality = 1; price = 10; };
	class muzzle_snds_B 							{ quality = 1; price = 20; };
	class muzzle_snds_H 							{ quality = 2; price = 20; };
	class muzzle_snds_H_MG 							{ quality = 2; price = 20; };
	class muzzle_snds_H_SW 							{ quality = 2; price = 20; };
	class muzzle_snds_L 							{ quality = 1; price = 10; };
	class muzzle_snds_M 							{ quality = 1; price = 10; };

	class I_UavTerminal								{ quality = 3; price = 750; };
	class I_UAV_01_backpack_F						{ quality = 3; price = 3000; };

	class O_HMG_01_weapon_F 						{ quality = 3; price = 5000; };
	class O_HMG_01_support_F 						{ quality = 3; price = 1000; };

	class optic_Aco									{ quality = 1; price = 70; };
	class optic_ACO_grn								{ quality = 1; price = 70; };
	class optic_ACO_grn_smg							{ quality = 1; price = 70; };
	class optic_Aco_smg								{ quality = 1; price = 70; };
	class optic_AMS									{ quality = 3; price = 300; };
	class optic_AMS_khk								{ quality = 3; price = 300; };
	class optic_AMS_snd								{ quality = 3; price = 300; };
	class optic_Arco								{ quality = 1; price = 100; };
	class optic_DMS									{ quality = 1; price = 150; };
	class optic_Hamr								{ quality = 3; price = 200; };
	class optic_Holosight							{ quality = 1; price = 50; };
	class optic_Holosight_smg						{ quality = 1; price = 50; };
	class optic_KHS_blk								{ quality = 3; price = 300; };
	class optic_KHS_hex								{ quality = 3; price = 300; };
	class optic_KHS_old								{ quality = 3; price = 300; };
	class optic_KHS_tan								{ quality = 3; price = 300; };
	class optic_LRPS								{ quality = 2; price = 300; };
	class optic_MRCO								{ quality = 1; price = 100; };
	class optic_MRD									{ quality = 1; price = 10; };
	class optic_Nightstalker						{ quality = 3; price = 1000; };
	class optic_NVS									{ quality = 2; price = 500; };
	class optic_SOS									{ quality = 2; price = 200; };
	//class optic_tws									{ quality = 3; price = 1500; };
	//class optic_tws_mg								{ quality = 3; price = 1500; };
	class optic_Yorris								{ quality = 1; price = 10; };

	class Extremo_Item_Rope							{ quality = 1; price = 20; };
	class Extremo_Item_DuctTape						{ quality = 1; price = 300; };
	class Extremo_Item_ExtensionCord					{ quality = 1; price = 40; };
	class Extremo_Item_FuelCanisterEmpty				{ quality = 1; price = 40; };
	class Extremo_Item_JunkMetal						{ quality = 1; price = 400; };
	class Extremo_Item_LightBulb						{ quality = 1; price = 20; };
	class Extremo_Item_MetalBoard						{ quality = 1; price = 600; };
	//class Extremo_Item_MetalHedgehogKit				{ quality = 1; price = 1200; };
	class Extremo_Item_SafeKit						{ quality = 3; price = 10000; };
	class Extremo_Item_CodeLock						{ quality = 2; price = 5000; };
	//class Extremo_Item_Laptop						{ quality = 2; price = 9000; };
	//class Extremo_Item_BaseCameraKit				{ quality = 2; price = 5000; };
	class Extremo_Item_CamoTentKit					{ quality = 1; price = 250; };
	class Extremo_Item_MetalPole						{ quality = 1; price = 800; };
	//class Extremo_Item_MetalScrews					{ quality = 1; price = 100; };
	//class Extremo_Item_MetalWire						{ quality = 1; price = 100; };
	//class Extremo_Item_Cement							{ quality = 1; price = 20; };
	//class Extremo_Item_Sand							{ quality = 1; price = 20; };
	//class Extremo_Item_CarWheel						{ quality = 1; price = 1000; };
	
	class Extremo_Item_EMRE							{ quality = 3; price = 54; }; //75, 60
	class Extremo_Item_GloriousKnakworst				{ quality = 3; price = 40; }; //60, 30
	class Extremo_Item_Surstromming					{ quality = 3; price = 34; }; //55, 25
	class Extremo_Item_SausageGravy					{ quality = 3; price = 30; }; //50, 25
	class Extremo_Item_Catfood						{ quality = 2; price = 24; }; //40, 40
	class Extremo_Item_ChristmasTinner				{ quality = 3; price = 20; }; //40, 60
	class Extremo_Item_BBQSandwich					{ quality = 3; price = 20; }; //40, 60
	class Extremo_Item_Dogfood						{ quality = 2; price = 18; }; //30, 30
	class Extremo_Item_BeefParts						{ quality = 2; price = 18; }; //30, 30
	class Extremo_Item_Cheathas						{ quality = 2; price = 18; }; //30, 30
	class Extremo_Item_Noodles						{ quality = 1; price = 14; }; //25, 50
	class Extremo_Item_SeedAstics						{ quality = 1; price = 12; }; //20, 40
	class Extremo_Item_Raisins						{ quality = 1; price = 10; }; //15, 30
	class Extremo_Item_Moobar							{ quality = 1; price = 8; }; //10, 30
	class Extremo_Item_InstantCoffee					{ quality = 1; price = 20; }; //5, 10
	class Extremo_Item_Can_Empty						{ quality = 1; price = 1; sellPrice = 1; };

	class Extremo_Item_PlasticBottleCoffee	 		{ quality = 3; price = 40; }; //100, 60
	class Extremo_Item_PowerDrink						{ quality = 3; price = 60; }; //95, 10
	class Extremo_Item_PlasticBottleFreshWater 		{ quality = 2; price = 50; sellPrice = 4; }; //80, 15
	class Extremo_Item_Beer 							{ quality = 1; price = 50; }; //75, 30
	class Extremo_Item_EnergyDrink					{ quality = 1; price = 40; }; //75, 20
	class Extremo_Item_MountainDupe					{ quality = 1; price = 30; }; //50, 20
	class Extremo_Item_PlasticBottleEmpty				{ quality = 1; price = 4; };
	
	class Extremo_Item_InstaDoc                       { quality = 1; price = 1250; };
	class Extremo_Item_Vishpirin						{ quality = 1; price = 300; };
	class Extremo_Item_Bandage	                    { quality = 1; price = 100; };
	//class Extremo_Item_Defibrillator				{ quality = 1; price = 7500; };
	
	class Extremo_Item_Matches 						{ quality = 1; price = 60; };
	class Extremo_Item_CookingPot						{ quality = 2; price = 80; };
	class Extremo_Melee_Axe							{ quality = 1; price = 100; };
	class Extremo_Melee_Pickaxe						{ quality = 1; price = 100; };
	class Extremo_Melee_Sword						{ quality = 1; price = 100; };
	class Extremo_Item_CanOpener						{ quality = 1; price = 80; };
	class Extremo_Item_Handsaw						{ quality = 1; price = 500; };
	class Extremo_Item_Pliers							{ quality = 1; price = 350; };
	class Extremo_Item_Grinder						{ quality = 1; price = 1250; };
	//class Extremo_Item_Foolbox						{ quality = 1; price = 4000; };
	//class Extremo_Item_CordlessScrewdriver			{ quality = 1; price = 750; };
	//class Extremo_Item_FireExtinguisher				{ quality = 1; price = 650; };
	//class Extremo_Item_Hammer						{ quality = 1; price = 600; };
	//class Extremo_Item_OilCanister					{ quality = 1; price = 1750; };
	//class Extremo_Item_Screwdriver					{ quality = 1; price = 250; };
	//class Extremo_Item_Shovel						{ quality = 1; price = 700; };
	//class Extremo_Item_Wrench						{ quality = 1; price = 250; };
	//class Extremo_Item_SleepingMat					{ quality = 1; price = 1250; };
	//class Extremo_Item_ToiletPaper					{ quality = 1; price = 5; };
	//class Extremo_Item_ZipTie						{ quality = 1; price = 250; };

	class ItemWatch									{ quality = 1; price = 2; };	
	class ItemGPS									{ quality = 1; price = 40; };
	class ItemMap									{ quality = 1; price = 6; };
	class ItemCompass								{ quality = 1; price = 6; }; 
	class Binocular									{ quality = 1; price = 40; };
	class Rangefinder								{ quality = 2; price = 200; };
	class Laserdesignator							{ quality = 3; price = 750; };
	class Laserdesignator_02						{ quality = 3; price = 750; };
	class Laserdesignator_03						{ quality = 3; price = 750; };
	class NVGoggles									{ quality = 2; price = 100; };
	class NVGoggles_INDEP							{ quality = 2; price = 100; };
	class NVGoggles_OPFOR							{ quality = 2; price = 100; };
	class Extremo_Item_XM8							{ quality = 2; price = 20; };

	class V_RebreatherB								{ quality = 2; price = 250; };
	class V_RebreatherIA							{ quality = 2; price = 250; };
	class V_RebreatherIR							{ quality = 2; price = 250; };

	class B_Parachute								{ quality = 3; price = 150; };
	class H_CrewHelmetHeli_B						{ quality = 2; price = 150; };
	class H_CrewHelmetHeli_I						{ quality = 2; price = 150; };
	class H_CrewHelmetHeli_O						{ quality = 2; price = 150; };
	class H_HelmetCrew_I							{ quality = 1; price = 100; };
	class H_HelmetCrew_B							{ quality = 1; price = 100; };
	class H_HelmetCrew_O							{ quality = 1; price = 100; };
	class H_PilotHelmetHeli_B						{ quality = 3; price = 100; };
	class H_PilotHelmetHeli_I						{ quality = 3; price = 100; };
	class H_PilotHelmetHeli_O						{ quality = 3; price = 100; };
	class U_B_HeliPilotCoveralls					{ quality = 1; price = 80; };
	class U_B_PilotCoveralls						{ quality = 1; price = 60; };
	class U_I_HeliPilotCoveralls					{ quality = 1; price = 60; };
	class U_I_pilotCoveralls						{ quality = 1; price = 60; };
	class U_O_PilotCoveralls						{ quality = 1; price = 60; };
	class H_PilotHelmetFighter_B					{ quality = 2; price = 150; };
	class H_PilotHelmetFighter_I					{ quality = 2; price = 150; };
	class H_PilotHelmetFighter_O					{ quality = 2; price = 150; };

	class B_HuntingBackpack							{ quality = 3; price = 70; };
	class B_OutdoorPack_blk							{ quality = 1; price = 80; };
	class B_OutdoorPack_blu							{ quality = 1; price = 80; };
	class B_OutdoorPack_tan							{ quality = 1; price = 80; };
	class B_AssaultPack_blk							{ quality = 1; price = 90; };
	class B_AssaultPack_cbr							{ quality = 1; price = 90; };
	class B_AssaultPack_dgtl						{ quality = 1; price = 90; };
	class B_AssaultPack_khk							{ quality = 1; price = 90; };
	class B_AssaultPack_mcamo						{ quality = 1; price = 90; };
	class B_AssaultPack_rgr							{ quality = 1; price = 90; };
	class B_AssaultPack_sgg							{ quality = 1; price = 90; };
	class B_FieldPack_blk							{ quality = 2; price = 120; };
	class B_FieldPack_cbr							{ quality = 2; price = 120; };
	class B_FieldPack_ocamo							{ quality = 2; price = 120; };
	class B_FieldPack_oucamo						{ quality = 2; price = 120; };
	class B_TacticalPack_blk						{ quality = 2; price = 150; };
	class B_TacticalPack_rgr						{ quality = 2; price = 150; };
	class B_TacticalPack_ocamo						{ quality = 2; price = 150; };
	class B_TacticalPack_mcamo						{ quality = 2; price = 150; };
	class B_TacticalPack_oli						{ quality = 2; price = 150; };
	class B_Kitbag_cbr								{ quality = 3; price = 200; };
	class B_Kitbag_mcamo							{ quality = 3; price = 200; };
	class B_Kitbag_sgg								{ quality = 3; price = 200; };
	class B_Bergen_blk								{ quality = 2; price = 200; };
	class B_Bergen_mcamo							{ quality = 2; price = 200; };
	class B_Bergen_rgr								{ quality = 2; price = 200; };
	class B_Bergen_sgg								{ quality = 2; price = 200; };
	class B_Carryall_cbr							{ quality = 3; price = 300; };
	class B_Carryall_khk							{ quality = 3; price = 300; };
	class B_Carryall_mcamo							{ quality = 3; price = 300; };
	class B_Carryall_ocamo							{ quality = 3; price = 300; };
	class B_Carryall_oli							{ quality = 3; price = 300; };
	class B_Carryall_oucamo							{ quality = 3; price = 300; };

	class 100Rnd_65x39_caseless_mag 				{ quality = 1; price = 30; };
	class 100Rnd_65x39_caseless_mag_Tracer 			{ quality = 2; price = 40; };
	class 10Rnd_127x54_Mag 							{ quality = 1; price = 30; };
	// Broken in Arma
	class 10Rnd_338_Mag 							{ quality = 1; price = 30; };

	class 10Rnd_762x54_Mag 							{ quality = 1; price = 30; };
	//class 10Rnd_762x51_Mag 						{ quality = 1; price = 30; };
	class 10Rnd_93x64_DMR_05_Mag 					{ quality = 1; price = 40; };
	class 11Rnd_45ACP_Mag 							{ quality = 1; price = 8; };
	class 150Rnd_762x54_Box 						{ quality = 1; price = 20; };
	class 150Rnd_762x54_Box_Tracer 					{ quality = 2; price = 30; };
	class 16Rnd_9x21_Mag 							{ quality = 1; price = 20; };
	class 200Rnd_65x39_cased_Box 					{ quality = 1; price = 30; };
	class 200Rnd_65x39_cased_Box_Tracer 			{ quality = 2; price = 30; };
	class 150Rnd_93x64_Mag 							{ quality = 2; price = 50; };
	class 130Rnd_338_Mag 							{ quality = 2; price = 40; };
	class 20Rnd_556x45_UW_mag 						{ quality = 1; price = 20; };
	class 20Rnd_762x51_Mag 							{ quality = 1; price = 20; };
	class 30Rnd_45ACP_Mag_SMG_01 					{ quality = 1; price = 10; };
	class 30Rnd_45ACP_Mag_SMG_01_Tracer_Green 		{ quality = 2; price = 10; };
	class 30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow		{ quality = 2; price = 10; };
	class 30Rnd_45ACP_Mag_SMG_01_Tracer_Red			{ quality = 2; price = 10; };
	class 30Rnd_556x45_Stanag 						{ quality = 1; price = 20; };
	class 30Rnd_556x45_Stanag_Tracer_Green 			{ quality = 2; price = 20; };
	class 30Rnd_556x45_Stanag_green  				{ quality = 2; price = 20; };
	class 30Rnd_556x45_Stanag_Tracer_Red 			{ quality = 2; price = 20; };
	class 30Rnd_556x45_Stanag_Tracer_Yellow 		{ quality = 2; price = 20; };
	class 30Rnd_556x45_Stanag_red 					{ quality = 2; price = 20; };
	class 30Rnd_65x39_caseless_green 				{ quality = 1; price = 20; };
	class 30Rnd_65x39_caseless_green_mag_Tracer 	{ quality = 2; price = 30; };
	class 30Rnd_65x39_caseless_mag 					{ quality = 1; price = 20; };
	class 30Rnd_65x39_caseless_mag_Tracer 			{ quality = 2; price = 30; };
	class 30Rnd_9x21_Mag 							{ quality = 1; price = 40; };
	class 5Rnd_127x108_APDS_Mag 					{ quality = 2; price = 50; };
	class 5Rnd_127x108_Mag 							{ quality = 1; price = 40; };
	class 6Rnd_45ACP_Cylinder 						{ quality = 1; price = 8; };
	class 6Rnd_GreenSignal_F 						{ quality = 9000; price = 30; };
	class 6Rnd_RedSignal_F 							{ quality = 9000; price = 30; };
	class 7Rnd_408_Mag 								{ quality = 1; price = 10; };
	class 9Rnd_45ACP_Mag 							{ quality = 1; price = 6; };

	class Chemlight_blue							{ quality = 1; price = 2; };
	class Chemlight_green							{ quality = 1; price = 2; };
	class Chemlight_red								{ quality = 1; price = 2; };
	class FlareGreen_F								{ quality = 1; price = 6; };
	class FlareRed_F								{ quality = 1; price = 6; };
	class FlareWhite_F								{ quality = 1; price = 6; };
	class FlareYellow_F								{ quality = 1; price = 6; };
	class UGL_FlareGreen_F							{ quality = 2; price = 8; };
	class UGL_FlareRed_F							{ quality = 2; price = 8; };
	class UGL_FlareWhite_F							{ quality = 2; price = 8; };
	class UGL_FlareYellow_F							{ quality = 2; price = 8; };
	class 3Rnd_UGL_FlareGreen_F						{ quality = 3; price = 8*3; };
	class 3Rnd_UGL_FlareRed_F						{ quality = 3; price = 8*3; };
	class 3Rnd_UGL_FlareWhite_F						{ quality = 3; price = 8*3; };
	class 3Rnd_UGL_FlareYellow_F					{ quality = 3; price = 8*3; };

	class SmokeShell								{ quality = 1; price = 6; };
	class SmokeShellBlue							{ quality = 1; price = 6; };
	class SmokeShellGreen							{ quality = 1; price = 6; };
	class SmokeShellOrange							{ quality = 1; price = 6; };
	class SmokeShellPurple							{ quality = 1; price = 6; };
	class SmokeShellRed								{ quality = 1; price = 6; };
	class SmokeShellYellow							{ quality = 1; price = 6; };
	class 1Rnd_Smoke_Grenade_shell					{ quality = 2; price = 8; };
	class 1Rnd_SmokeBlue_Grenade_shell				{ quality = 2; price = 8; };
	class 1Rnd_SmokeGreen_Grenade_shell				{ quality = 2; price = 8; };
	class 1Rnd_SmokeOrange_Grenade_shell			{ quality = 2; price = 8; };
	class 1Rnd_SmokePurple_Grenade_shell			{ quality = 2; price = 8; };
	class 1Rnd_SmokeRed_Grenade_shell				{ quality = 2; price = 8; };
	class 1Rnd_SmokeYellow_Grenade_shell			{ quality = 2; price = 8; };
	class 3Rnd_Smoke_Grenade_shell					{ quality = 3; price = 8*3; };
	class 3Rnd_SmokeBlue_Grenade_shell				{ quality = 3; price = 8*3; };
	class 3Rnd_SmokeGreen_Grenade_shell				{ quality = 3; price = 8*3; };
	class 3Rnd_SmokeOrange_Grenade_shell			{ quality = 3; price = 8*3; };
	class 3Rnd_SmokePurple_Grenade_shell			{ quality = 3; price = 8*3; };
	class 3Rnd_SmokeRed_Grenade_shell				{ quality = 3; price = 8*3; };
	class 3Rnd_SmokeYellow_Grenade_shell			{ quality = 3; price = 8*3; };

	class HandGrenade								{ quality = 3; price = 40; };
	class MiniGrenade								{ quality = 2; price = 30; };
	class B_IR_Grenade								{ quality = 1; price = 50; };
	class O_IR_Grenade								{ quality = 1; price = 50; };
	class I_IR_Grenade								{ quality = 1; price = 50; };
	class 1Rnd_HE_Grenade_shell						{ quality = 2; price = 70; };
	class 3Rnd_HE_Grenade_shell						{ quality = 3; price = 70*3; };
	class APERSBoundingMine_Range_Mag				{ quality = 3; price = 500; };
	class APERSMine_Range_Mag						{ quality = 3; price = 600; };
	class APERSTripMine_Wire_Mag					{ quality = 3; price = 300; };
	class ClaymoreDirectionalMine_Remote_Mag		{ quality = 3; price = 350; };
	class DemoCharge_Remote_Mag						{ quality = 3; price = 700; };
	class IEDLandBig_Remote_Mag						{ quality = 3; price = 600; };
	class IEDLandSmall_Remote_Mag					{ quality = 3; price = 300; };
	class IEDUrbanBig_Remote_Mag					{ quality = 3; price = 800; };
	class IEDUrbanSmall_Remote_Mag					{ quality = 3; price = 400; };
	class SatchelCharge_Remote_Mag					{ quality = 3; price = 1000; };
	class SLAMDirectionalMine_Wire_Mag				{ quality = 3; price = 700; };

	class hgun_ACPC2_F 								{ quality = 1; price = 50; };
	class hgun_P07_F 								{ quality = 1; price = 50; };
	class hgun_Pistol_heavy_01_F 					{ quality = 2; price = 80; };
	class hgun_Pistol_heavy_02_F 					{ quality = 2; price = 80; };
	class hgun_Pistol_Signal_F 						{ quality = 9000; price = 100; };
	class hgun_Rook40_F 							{ quality = 1; price = 50; };

	class hgun_PDW2000_F 							{ quality = 1; price = 100; };
	class SMG_01_F 									{ quality = 1; price = 150; };
	class SMG_02_F 									{ quality = 1; price = 150; };

	class arifle_MX_SW_Black_F						{ quality = 2; price = 250; };
	class arifle_MX_SW_F							{ quality = 2; price = 250; };
	class LMG_Mk200_F								{ quality = 2; price = 300; };
	class LMG_Zafir_F								{ quality = 2; price = 350; };
	class MMG_01_hex_F								{ quality = 3; price = 800; };
	class MMG_01_tan_F								{ quality = 3; price = 800; };
	class MMG_02_black_F							{ quality = 3; price = 450; };
	class MMG_02_camo_F								{ quality = 3; price = 450; };
	class MMG_02_sand_F								{ quality = 3; price = 450; };

	class arifle_Katiba_C_F							{ quality = 1; price = 150; };
	class arifle_Katiba_F							{ quality = 1; price = 150; };
	class arifle_Katiba_GL_F						{ quality = 2; price = 200; };
	class arifle_Mk20_F								{ quality = 1; price = 150; };
	class arifle_Mk20_GL_F							{ quality = 2; price = 200; };
	class arifle_Mk20_GL_plain_F					{ quality = 2; price = 200; };
	class arifle_Mk20_plain_F						{ quality = 1; price = 150; };
	class arifle_Mk20C_F							{ quality = 1; price = 150; };
	class arifle_Mk20C_plain_F						{ quality = 1; price = 150; };
	class arifle_MX_Black_F							{ quality = 1; price = 450; };
	class arifle_MX_F								{ quality = 1; price = 450; };
	class arifle_MX_GL_Black_F						{ quality = 2; price = 450; };
	class arifle_MX_GL_F							{ quality = 2; price = 450; };
	class arifle_MXC_Black_F						{ quality = 1; price = 350; };
	class arifle_MXC_F								{ quality = 1; price = 350; };
	class arifle_SDAR_F								{ quality = 3; price = 650; };
	class arifle_TRG20_F							{ quality = 1; price = 250; };
	class arifle_TRG21_F							{ quality = 1; price = 250; };
	class arifle_TRG21_GL_F							{ quality = 2; price = 350; };

	class arifle_MXM_Black_F 						{ quality = 1; price = 550; };
	class arifle_MXM_F 								{ quality = 1; price = 550; };
	class srifle_DMR_01_F 							{ quality = 2; price = 600; };
	class srifle_DMR_02_camo_F 						{ quality = 3; price = 800; };
	class srifle_DMR_02_F 							{ quality = 3; price = 800; };
	class srifle_DMR_02_sniper_F 					{ quality = 3; price = 800; };
	class srifle_DMR_03_F 							{ quality = 3; price = 750; };
	class srifle_DMR_03_khaki_F 					{ quality = 3; price = 750; };
	class srifle_DMR_03_multicam_F 					{ quality = 3; price = 750; };
	class srifle_DMR_03_tan_F 						{ quality = 3; price = 750; };
	class srifle_DMR_03_woodland_F 					{ quality = 3; price = 750; };
	class srifle_DMR_04_F 							{ quality = 3; price = 700; };
	class srifle_DMR_04_Tan_F 						{ quality = 3; price = 700; };
	class srifle_DMR_05_blk_F 						{ quality = 3; price = 850; };
	class srifle_DMR_05_hex_F 						{ quality = 3; price = 850; };
	class srifle_DMR_05_tan_f 						{ quality = 3; price = 850; };
	class srifle_DMR_06_camo_F 						{ quality = 3; price = 800; };
	class srifle_DMR_06_olive_F 					{ quality = 3; price = 800; };
	class srifle_EBR_F 								{ quality = 2; price = 700; };
	class srifle_GM6_camo_F 						{ quality = 3; price = 900; };
	class srifle_GM6_F 								{ quality = 3; price = 900; };
	class srifle_LRR_camo_F 						{ quality = 3; price = 850; };
	class srifle_LRR_F 								{ quality = 3; price = 850; };

	class Extremo_Bike_OldBike 						{ quality = 1; price = 40; };
	class Extremo_Bike_MountainBike 					{ quality = 1; price = 50; };

	class Extremo_Bike_QuadBike_Black					{ quality = 1; price = 2500; };
	class Extremo_Bike_QuadBike_Blue					{ quality = 1; price = 2500; };
	class Extremo_Bike_QuadBike_Red					{ quality = 1; price = 2500; };
	class Extremo_Bike_QuadBike_White					{ quality = 1; price = 2500; };
	class Extremo_Bike_QuadBike_Nato					{ quality = 1; price = 2500; };
	class Extremo_Bike_QuadBike_Csat					{ quality = 1; price = 2500; };
	class Extremo_Bike_QuadBike_Fia					{ quality = 1; price = 2500; };
	class Extremo_Bike_QuadBike_Guerilla01			{ quality = 1; price = 2500; };
	class Extremo_Bike_QuadBike_Guerilla02			{ quality = 1; price = 2500; };

	class Extremo_Car_Kart_BluKing					{ quality = 1; price = 1100; };
	class Extremo_Car_Kart_RedStone					{ quality = 1; price = 1100; };
	class Extremo_Car_Kart_Vrana						{ quality = 1; price = 1100; };
	class Extremo_Car_Kart_Green						{ quality = 1; price = 1100; };
	class Extremo_Car_Kart_Blue						{ quality = 1; price = 1100; };
	class Extremo_Car_Kart_Orange						{ quality = 1; price = 1100; };
	class Extremo_Car_Kart_White						{ quality = 1; price = 1100; };
	class Extremo_Car_Kart_Yellow						{ quality = 1; price = 1100; };
	class Extremo_Car_Kart_Black						{ quality = 1; price = 1100; };

	class Extremo_Boat_MotorBoat_Police				{ quality = 1; price = 700; };
	class Extremo_Boat_MotorBoat_Orange				{ quality = 1; price = 700; };
	class Extremo_Boat_MotorBoat_White				{ quality = 1; price = 700; };

	class Extremo_Boat_RubberDuck_CSAT				{ quality = 1; price = 500; };
	class Extremo_Boat_RubberDuck_Digital				{ quality = 1; price = 500; };
	class Extremo_Boat_RubberDuck_Orange				{ quality = 1; price = 500; };
	class Extremo_Boat_RubberDuck_Blue				{ quality = 1; price = 500; };
	class Extremo_Boat_RubberDuck_Black				{ quality = 1; price = 500; };

	class Extremo_Boat_SDV_CSAT						{ quality = 1; price = 11000; };
	class Extremo_Boat_SDV_Digital					{ quality = 1; price = 11000; };
	class Extremo_Boat_SDV_Grey						{ quality = 1; price = 11000; };

	class Extremo_Chopper_Hellcat_Green				{ quality = 1; price = 27500; };
	class Extremo_Chopper_Hellcat_FIA					{ quality = 1; price = 27500; };

	class Extremo_Chopper_Hummingbird_Green			{ quality = 1; price = 23000; };

	class Extremo_Chopper_Hummingbird_Civillian_Blue				{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Red				{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_ION				{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_BlueLine			{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Digital			{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Elliptical		{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Furious			{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_GrayWatcher		{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Jeans				{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Light				{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Shadow			{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Sheriff			{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Speedy			{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Sunset			{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Vrana				{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Wasp				{ quality = 1; price = 17000; };
	class Extremo_Chopper_Hummingbird_Civillian_Wave				{ quality = 1; price = 17000; };

	class Extremo_Chopper_Huron_Black								{ quality = 1; price = 50000; };
	class Extremo_Chopper_Huron_Green								{ quality = 1; price = 50000; };

	class Extremo_Chopper_Mohawk_FIA								{ quality = 1; price = 45000; };

	class Extremo_Chopper_Orca_CSAT								{ quality = 1; price = 28000; };
	class Extremo_Chopper_Orca_Black								{ quality = 1; price = 28000; };
	class Extremo_Chopper_Orca_BlackCustom						{ quality = 1; price = 28000; };

	class Extremo_Chopper_Taru_Transport_CSAT						{ quality = 1; price = 17000; };
	class Extremo_Chopper_Taru_Transport_Black					{ quality = 1; price = 17000; };
	
	class Extremo_Chopper_Taru_CSAT								{ quality = 1; price = 33000; };
	class Extremo_Chopper_Taru_Black								{ quality = 1; price = 33000; };

	class Extremo_Chopper_Taru_Covered_CSAT						{ quality = 1; price = 43000; };
	class Extremo_Chopper_Taru_Covered_Black						{ quality = 1; price = 43000; };

	class Extremo_Plane_Cessna									{ quality = 1; price = 16500; };

	class Extremo_Car_Hatchback_Beige						{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Green						{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Blue						{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_BlueCustom				{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_BeigeCustom				{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Yellow					{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Grey						{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Black						{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Dark						{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Rusty1					{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Rusty2					{ quality = 1; price = 12000; };
	class Extremo_Car_Hatchback_Rusty3					{ quality = 1; price = 12000; };

	class Extremo_Car_Ikarus_Blue 				{ quality = 1; price = 17000; };
	class Extremo_Car_Ikarus_Red 					{ quality = 1; price = 17000; };
	class Extremo_Car_Ikarus_Party 				{ quality = 1; price = 17000; };

	class Extremo_Car_Ural_Open_Blue			{ quality = 1; price = 25000; };
	class Extremo_Car_Ural_Open_Yellow		{ quality = 1; price = 25000; };
	class Extremo_Car_Ural_Open_Worker		{ quality = 1; price = 25000; };
	class Extremo_Car_Ural_Open_Military		{ quality = 1; price = 25000; };

	class Extremo_Car_Ural_Covered_Blue			{ quality = 1; price = 28000; };
	class Extremo_Car_Ural_Covered_Yellow			{ quality = 1; price = 28000; };
	class Extremo_Car_Ural_Covered_Worker			{ quality = 1; price = 28000; };
	class Extremo_Car_Ural_Covered_Military		{ quality = 1; price = 28000; };

	class Extremo_Car_SUVXL_Black 				{ quality = 1; price = 20000; };

	class Extremo_Car_Lada_Green 				{ quality = 1; price = 6000; };
	class Extremo_Car_Lada_Taxi 				{ quality = 1; price = 6000; };
	class Extremo_Car_Lada_Red 				{ quality = 1; price = 6000; };
	class Extremo_Car_Lada_White 				{ quality = 1; price = 6000; };
	class Extremo_Car_Lada_Hipster 			{ quality = 1; price = 6000; };

	class Extremo_Car_Volha_Blue				{ quality = 1; price = 6000; };
	class Extremo_Car_Volha_White				{ quality = 1; price = 6000; };
	class Extremo_Car_Volha_Black				{ quality = 1; price = 6000; };

	class Extremo_Car_Hatchback_Sport_Red					{ quality = 1; price = 14000; };
	class Extremo_Car_Hatchback_Sport_Blue				{ quality = 1; price = 14000; };
	class Extremo_Car_Hatchback_Sport_Orange				{ quality = 1; price = 14000; };
	class Extremo_Car_Hatchback_Sport_White				{ quality = 1; price = 14000; };
	class Extremo_Car_Hatchback_Sport_Beige				{ quality = 1; price = 14000; };
	class Extremo_Car_Hatchback_Sport_Green				{ quality = 1; price = 14000; };

	class Extremo_Car_HEMMT 								{ quality = 1; price = 48000; };

	class Extremo_Car_Hunter 								{ quality = 1; price = 26500; };

	class Extremo_Car_Ifrit 								{ quality = 1; price = 23000; };

	class Extremo_Car_Offroad_Red							{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Beige						{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_White						{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Blue						{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_DarkRed						{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_BlueCustom					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla01					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla02					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla03					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla04					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla05					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla06					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla07					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla08					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla09					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla10					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla11					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Guerilla12					{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Rusty1						{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Rusty2						{ quality = 1; price = 16000; };
	class Extremo_Car_Offroad_Rusty3						{ quality = 1; price = 16000; };

	class Extremo_Car_Offroad_Armed_Guerilla01 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla02 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla03 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla04 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla05 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla06 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla07 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla08 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla09 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla10 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla11 			{ quality = 1; price = 25000; };
	class Extremo_Car_Offroad_Armed_Guerilla12 			{ quality = 1; price = 25000; };

	class Extremo_Car_Offroad_Repair_Civillian 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Red 					{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Beige 				{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_White 				{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Blue 				{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_DarkRed 				{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_BlueCustom 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla01 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla02 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla03 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla04 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla05 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla06 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla07 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla08 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla09 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla10 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla11 			{ quality = 1; price = 12500; };
	class Extremo_Car_Offroad_Repair_Guerilla12 			{ quality = 1; price = 12500; };

	class Extremo_Car_Strider 							{ quality = 1; price = 44000; };

	class Extremo_Car_SUV_Red 							{ quality = 1; price = 14000; };
	class Extremo_Car_SUV_Black 							{ quality = 1; price = 14000; };
	class Extremo_Car_SUV_Grey 							{ quality = 1; price = 14000; };
	class Extremo_Car_SUV_Orange 							{ quality = 1; price = 14000; };

	class Extremo_Car_Tempest 							{ quality = 1; price = 48300; };

	class Extremo_Car_Van_Black 							{ quality = 1; price = 12000; };
	class Extremo_Car_Van_White 							{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Red 							{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Guerilla01 						{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Guerilla02 						{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Guerilla03 						{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Guerilla04 						{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Guerilla05 						{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Guerilla06 						{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Guerilla07 						{ quality = 1; price = 12000; };
	class Extremo_Car_Van_Guerilla08 						{ quality = 1; price = 12000; };

	class Extremo_Car_Van_Box_Black 						{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_White 						{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Red 						{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Guerilla01 					{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Guerilla02 					{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Guerilla03 					{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Guerilla04 					{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Guerilla05 					{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Guerilla06 					{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Guerilla07 					{ quality = 1; price = 17000; };
	class Extremo_Car_Van_Box_Guerilla08 					{ quality = 1; price = 17000; };

	class Extremo_Car_Van_Fuel_Black 						{ quality = 1; price = 15000; };
	class Extremo_Car_Van_Fuel_White 						{ quality = 1; price = 15000; };
	class Extremo_Car_Van_Fuel_Red 						{ quality = 1; price = 15000; };
	class Extremo_Car_Van_Fuel_Guerilla01 				{ quality = 1; price = 15000; };
	class Extremo_Car_Van_Fuel_Guerilla02 				{ quality = 1; price = 15000; };
	class Extremo_Car_Van_Fuel_Guerilla03 				{ quality = 1; price = 15000; };

	class Extremo_Car_Zamak 								{ quality = 1; price = 43000; };
};
class CfgFlags 
{
	class USA
	{
		name = "USA";
		texture = "\A3\Data_F\Flags\flag_us_co.paa";
		uid = "";
	};
};
class CfgInteractionMenus
{
	class Car 
	{
		targetType = 2;
		target = "Car";

		class Actions 
		{
			class ScanLock: ExtremoAbstractAction
			{
				title = "Scan Lock";
				condition = "('Extremo_Item_ThermalScannerPro' in (magazines player)) && !ExtremoPlayerInSafezone && ((locked ExtremoClientInteractionObject) != 1)";
				action = "_this call Extremo_fnc_object_lock_scan";
			};

			class Lock: ExtremoAbstractAction
			{
				title = "Lock";
				condition = "((locked ExtremoClientInteractionObject) isEqualTo 0) && ((locked ExtremoClientInteractionObject) != 1)";
				action = "true spawn Extremo_fnc_object_lock_toggle";
			};

			class Unlock: ExtremoAbstractAction
			{
				title = "Unlock";
				condition = "((locked ExtremoClientInteractionObject) isEqualTo 2) && ((locked ExtremoClientInteractionObject) != 1)";
				action = "false spawn Extremo_fnc_object_lock_toggle";
			};

			class Repair: ExtremoAbstractAction
			{
				title = "Repair";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_Repair";
			};

			class Flip: ExtremoAbstractAction
			{
				title = "Flip";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_flip";
			};

			class Refuel: ExtremoAbstractAction
			{
				title = "Refuel";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_refuel";
			};

			class DrainFuel: ExtremoAbstractAction
			{
				title = "Drain Fuel";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_drain";
			};
		};
	};

	class Air
	{
		target = "Air";
		targetType = 2;

		class Actions
		{
			class ScanLock: ExtremoAbstractAction
			{
				title = "Scan Lock";
				condition = "('Extremo_Item_ThermalScannerPro' in (magazines player)) && ((locked ExtremoClientInteractionObject) != 1) && !ExtremoPlayerInSafezone";
				action = "_this call Extremo_fnc_object_lock_scan";
			};

			class Lock: ExtremoAbstractAction
			{
				title = "Lock";
				condition = "((locked ExtremoClientInteractionObject) isEqualTo 0) && ((locked ExtremoClientInteractionObject) != 1)";
				action = "true spawn Extremo_fnc_object_lock_toggle";
			};

			class Unlock: ExtremoAbstractAction
			{
				title = "Unlock";
				condition = "((locked ExtremoClientInteractionObject) isEqualTo 2) && ((locked ExtremoClientInteractionObject) != 1)";
				action = "false spawn Extremo_fnc_object_lock_toggle";
			};

			class Repair: ExtremoAbstractAction
			{
				title = "Repair";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_Repair";
			};

			class Flip: ExtremoAbstractAction
			{
				title = "Flip";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_flip";
			};

			class Refuel: ExtremoAbstractAction
			{
				title = "Refuel";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_refuel";
			};

			class DrainFuel: ExtremoAbstractAction
			{
				title = "Drain Fuel";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_drain";
			};

			class RotateLeft: ExtremoAbstractAction
			{
				title = "Rotate Left";	
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "[ExtremoClientInteractionObject,-15] call Extremo_fnc_object_vehicle_rotate";
			};

			class RotateRight: ExtremoAbstractAction
			{
				title = "Rotate Right";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "[ExtremoClientInteractionObject,15] call Extremo_fnc_object_vehicle_rotate";
			};
		};
	};

	class Safe
	{
		targetType = 2;
		target = "Extremo_Container_Safe";

		class Actions 
		{
			class ScanLock: ExtremoAbstractAction
			{
				title = "Scan Lock";
				condition = "('Extremo_Item_ThermalScannerPro' in (magazines player)) && !((ExtremoClientInteractionObject getvariable ['ExtremoIsLocked',1]) isEqualTo 1) && !ExtremoPlayerInSafezone";
				action = "_this call Extremo_fnc_object_lock_scan";
			};

			class Lock : ExtremoAbstractAction
			{
				title = "Lock";
				condition = "((ExtremoClientInteractionObject getvariable ['ExtremoIsLocked',1]) isEqualTo 0)";
				action = "true spawn Extremo_fnc_object_lock_toggle";
			};

			class Unlock : ExtremoAbstractAction
			{
				title = "Unlock";
				condition = "((ExtremoClientInteractionObject getvariable ['ExtremoIsLocked',1]) isEqualTo -1)";
				action = "false spawn Extremo_fnc_object_lock_toggle";
			};

			class Pack : ExtremoAbstractAction
			{
				title = "Pack";
				condition = "((ExtremoClientInteractionObject getvariable ['ExtremoIsLocked',1]) isEqualTo 0)";
				action = "_this spawn Extremo_fnc_object_container_pack";
			};

			class SetPinCode : ExtremoAbstractAction
			{
				title = "Set PIN";
				condition = "((ExtremoClientInteractionObject getvariable ['ExtremoIsLocked',1]) isEqualTo 0)";
				action = "_this spawn Extremo_fnc_Object_lock_SetPin";
			};
		};
	};

	class Laptop
	{
		targetType = 2;
		target = "Extremo_Construction_Laptop_Static";

		class Actions
		{
			class CameraSystem: ExtremoAbstractAction
			{
				title = "CCTV Access";
				condition = "((ExtremoClientInteractionObject animationPhase 'LaptopLidRotation') >= 0.5)";
				action = "_this call Extremo_fnc_gui_baseCamera_show";
			};
		};
	};

	class SupplyBox
	{
		targetType = 2;
		target = "Extremo_Container_SupplyBox";

		class Actions
		{
			class Mount: ExtremoAbstractAction
			{
				title = "Mount";
				condition = "isNull (attachedTo ExtremoClientInteractionObject)";
				action = "_this call Extremo_fnc_object_supplyBox_mount";
			};

			class Install: ExtremoAbstractAction
			{
				title = "Install";
				condition = "isNull (attachedTo ExtremoClientInteractionObject)";
				action = "_this call Extremo_fnc_object_supplyBox_install";
			};

			class Unmount: ExtremoAbstractAction
			{
				title = "Unmount";
				condition = "!(isNull (attachedTo ExtremoClientInteractionObject))";
				action = "_this call Extremo_fnc_object_supplyBox_unmount";
			};
		};
	};

	class Construction
	{
		targetType = 2;
		target = "Extremo_Construction_Abstract_Static";

		class Actions 
		{
			class ScanLock: ExtremoAbstractAction
			{
				title = "Scan Lock";
				condition = "('Extremo_Item_ThermalScannerPro' in (magazines player)) && !((ExtremoClientInteractionObject getvariable ['ExtremoIsLocked',1]) isEqualTo 1)";
				action = "_this call Extremo_fnc_object_lock_scan";
			};

			class Unlock : ExtremoAbstractAction
			{
				title = "Unlock";
				condition = "((ExtremoClientInteractionObject getvariable ['ExtremoIsLocked',1]) isEqualTo -1)";
				action = "false spawn Extremo_fnc_object_lock_toggle";
			};

			class Lock : ExtremoAbstractAction
			{
				title = "Lock";
				condition = "((ExtremoClientInteractionObject getvariable ['ExtremoIsLocked',1]) isEqualTo 0)";
				action = "true spawn Extremo_fnc_object_lock_toggle";
			};

			class Move: ExtremoAbstractAction
			{
				title = "Move";
				condition = "true";
				action = "_this spawn Extremo_fnc_object_construction_move";
			};

			class Deconstruct: ExtremoAbstractAction
			{
				title = "Remove";
				condition = "true";
				action = "_this spawn Extremo_fnc_object_construction_deconstruct";
			};

			class AddALock : ExtremoAbstractAction
			{
				title = "Add a Lock";
				condition = "call Extremo_fnc_object_construction_lockAddShow";
				action = "_this spawn Extremo_fnc_object_construction_lockAdd";
			};

			class Upgrade : ExtremoAbstractAction
			{
				title = "Upgrade";
				condition = "call Extremo_fnc_object_construction_upgradeShow";
				action = "_this call Extremo_fnc_object_construction_upgrade";
			};

		};
	};

	class Container 
	{
		targetType = 2;
		target = "Extremo_Container_Abstract";

		class Actions 
		{
			class Pack 
			{
				title = "Pack";
				condition = "true";
				action = "_this spawn Extremo_fnc_object_container_pack";
			};
		};
	};

	class Flag
	{
		targetType = 2;
		target = "Extremo_Construction_Flag_Static";

		class Actions
		{
			class Upgrade: ExtremoAbstractAction
			{
				title = "Upgrade";
				condition = "true";
				action = "_this call Extremo_fnc_gui_upgradeterritoryDialog_request";
			};
		};
	};

	class Boat 
	{
		targetType = 2;
		target = "Ship";

		class Actions
		{

			class Lock: ExtremoAbstractAction
			{
				title = "Lock";
				condition = "((locked ExtremoClientInteractionObject) isEqualTo 0) && ((locked ExtremoClientInteractionObject) != 1)";
				action = "true spawn Extremo_fnc_object_lock_toggle";
			};

			class Unlock: ExtremoAbstractAction
			{
				title = "Unlock";
				condition = "((locked ExtremoClientInteractionObject) isEqualTo 2) && ((locked ExtremoClientInteractionObject) != 1)";
				action = "false spawn Extremo_fnc_object_lock_toggle";
			};

			class Repair: ExtremoAbstractAction
			{
				title = "Repair";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_Repair";
			};

			class Refuel: ExtremoAbstractAction
			{
				title = "Refuel";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_refuel";
			};

			class DrainFuel: ExtremoAbstractAction
			{
				title = "Drain Fuel";
				condition = "call Extremo_fnc_object_vehicle_interaction_show";
				action = "_this call Extremo_fnc_object_vehicle_drain";
			};

			class Push: ExtremoAbstractAction
			{
				title = "Fus Ro Dah!";
				condition = "((crew ExtremoClientInteractionObject) isEqualTo [])";
				action = "_this call Extremo_fnc_object_vehicle_push";
			};
		};
	};

	class Bikes
	{
		targetType = 2;
		target = "Bicycle";

		class Actions
		{
			class Flip: ExtremoAbstractAction
			{
				title = "Flip";
				condition = "true";
				action = "_this call Extremo_fnc_object_vehicle_flip";
			};
			class Scrap: ExtremoAbstractAction
			{
				title = "Scrap";
				condition = "true";
				action = "execVM 'scripts\bikescrap.sqf';";
			};
		};
	};

	class Player 
	{
		targetType = 2;
		target = "Extremo_Unit_Player";

		class Actions 
		{
			class Free: ExtremoAbstractAction
			{
				title = "Free";
				condition = "(alive ExtremoClientInteractionObject) && (ExtremoClientInteractionObject getVariable ['ExtremoIsHandcuffed', false]) && !ExtremoClientIsHandcuffed";
				action = "_this call Extremo_fnc_object_handcuffs_free";
			};
			
			class Search: ExtremoAbstractAction
			{
				title = "Search Gear";
				condition = "(alive ExtremoClientInteractionObject) && (ExtremoClientInteractionObject getVariable ['ExtremoIsHandcuffed', false]) && !ExtremoClientIsHandcuffed";
				action = "_this call Extremo_fnc_object_handcuffs_searchGear";
			};

			class Identify: ExtremoAbstractAction
			{
				title = "Identify Body";
				condition = "!(alive ExtremoClientInteractionObject)";
				action = "_this call Extremo_fnc_object_player_identifyBody";
			};
		};
	};
};
class CfgInteractionModels
{
	class WaterSource
	{
		name = "Water tanks, barrels, coolers or pumps";
		models[] = 	
		{
			"barrelwater_f", 
			"barrelwater_grey_f",
			"waterbarrel_f",
			"Extremo_Container_WoodBucket",
			"watertank_f",
			"stallwater_f",
			"waterpump_01_f",
			"water_source_f"
		};
	};

	class CleanWaterSource
	{
		name = "Water cooler";
		models[] = 	
		{
			"watercooler"
		};
	};

	class WorkBench
	{
		name = "Work Bench";
		models[] = 
		{
			"workstand_f.p3d"
		};
	};

	class WoodSource
	{
		name = "Trees";
		models[] = 
		{
			" t_",
			" bo_t_",

			// A2 trees
            " str_",
            " Smrk_",
            " les_",
            " brg_"			
		};
	};

	class BushSource
	{
		name = "Bushes";
		models[] = {" b_"};
	};

	class StoneSource
	{
		name = "Stones, stone walls or rocks";
		models[] = 
		{
			"stone",
			"Stone",
			"Rock",
			"rock",
			"cobble",
			"Cobble",
			"sea_wall_f.p3d"
		};
	};

	class FuelSource
	{
		name = "Fuel pumps, stations or barrels";
		models[] = 
		{
			"fuelstation_feed_f.p3d",
			"metalbarrel_f.p3d",
			"flexibletank_01_f.p3d",
			"fs_feed_f.p3d"
		};	
	};

	class Wrecks
	{
		name = "Wrecks";
		models[] = 
		{
			"wreck_"
		};
	};

	class Trash
	{
		name = "Trash";
		models[] = 
		{
			"trash",
			"garbage",
			"crabcages_f.p3d",
			"fishinggear",
			"junkpile_f.p3d",
			"wheeliebin_01_f.p3d"
		};
	};
};
class CfgTerritories
{

	prices[] = 
	{
		// Purchase Price 		Radius 		Number of Objects
		{5000,					15,			30 					}, // Level 1
		{10000,					30,			60 					}, // Level 2 
		{15000,					45,			90 					}, // Level 3
		{20000,					60,			120					}, // Level 4
		{25000,					75,			150					}, // Level 5
		{30000,					90,			180					}, // Level 6
		{35000,					105,		210					}, // Level 7
		{40000,					120,		240					}, // Level 8
		{45000,					135,		270					}, // Level 9
		{50000,					150,		300					}  // Level 10
	};

	maximumRadius = 150;

	minimumDistanceToOtherTerritories = 325; 

	maximumNumberOfTerritoriesPerPlayer = 2;


	minimumDistanceToTraderZones = 1000;

	minimumDistanceToSpawnZones = 1000;

	popTabAmountPerObject = 10;
	respectAmountPerObject = 5;
};
class CfgTraderCategories 
{
	class Community
	{
		name = "Community Items";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community2
	{
		name = "Community Items 2";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community3
	{
		name = "Community Items 3";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community4
	{
		name = "Community Items 4";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community5
	{
		name = "Community Items 5";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community6
	{
		name = "Community Items 6";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community7
	{
		name = "Community Items 7";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community8
	{
		name = "Community Items 8";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community9
	{
		name = "Community Items 9";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Community10
	{
		name = "Community Items 10";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			// Add your items here <3
		};
	};

	class Uniforms
	{
		name = "Uniforms";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\uniform_ca.paa";
		items[] = 
		{
			"U_C_Journalist",
			"U_C_Poloshirt_blue",
			"U_C_Poloshirt_burgundy",
			"U_C_Poloshirt_salmon",
			"U_C_Poloshirt_stripped",
			"U_C_Poloshirt_tricolour",
			"U_C_Poor_1",
			"U_C_Poor_2",
			"U_C_Poor_shorts_1",
			"U_C_Scientist",
			"U_OrestesBody",
			"U_Rangemaster",
			"U_NikosAgedBody",
			"U_NikosBody",
			"U_Competitor",
			"U_B_CombatUniform_mcam",
			"U_B_CombatUniform_mcam_tshirt",
			"U_B_CombatUniform_mcam_vest",
			"U_B_CombatUniform_mcam_worn",
			"U_B_CTRG_1",
			"U_B_CTRG_2",
			"U_B_CTRG_3",
			"U_I_CombatUniform",
			"U_I_CombatUniform_shortsleeve",
			"U_I_CombatUniform_tshirt",
			"U_I_OfficerUniform",
			"U_O_CombatUniform_ocamo",
			"U_O_CombatUniform_oucamo",
			"U_O_OfficerUniform_ocamo",
			"U_B_SpecopsUniform_sgg",
			"U_O_SpecopsUniform_blk",
			"U_O_SpecopsUniform_ocamo",
			"U_I_G_Story_Protagonist_F",
			"Extremo_Uniform_Woodland",
			"U_C_HunterBody_grn",
			"U_IG_Guerilla1_1",
			"U_IG_Guerilla2_1",
			"U_IG_Guerilla2_2",
			"U_IG_Guerilla2_3",
			"U_IG_Guerilla3_1",
			"U_BG_Guerilla2_1",
			"U_IG_Guerilla3_2",
			"U_BG_Guerrilla_6_1",
			"U_BG_Guerilla1_1",
			"U_BG_Guerilla2_2",
			"U_BG_Guerilla2_3",
			"U_BG_Guerilla3_1",
			"U_BG_leader",
			"U_IG_leader",
			"U_I_G_resistanceLeader_F",
			"U_I_Wetsuit",
			"U_O_Wetsuit",
			"U_B_Wetsuit",
			"U_B_survival_uniform",
			"U_B_HeliPilotCoveralls",
			"U_I_HeliPilotCoveralls",
			"U_B_PilotCoveralls",
			"U_I_pilotCoveralls",
			"U_O_PilotCoveralls"
		};
	};

	class Vests
	{
		name = "Vests";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\vest_ca.paa";
		items[] = 
		{
			"V_Press_F",
			"V_Rangemaster_belt",
			"V_TacVest_blk",
			"V_TacVest_blk_POLICE",
			"V_TacVest_brn",
			"V_TacVest_camo",
			"V_TacVest_khk",
			"V_TacVest_oli",
			"V_TacVestCamo_khk",
			"V_TacVestIR_blk",
			"V_I_G_resistanceLeader_F",
			"V_BandollierB_blk",
			"V_BandollierB_cbr",
			"V_BandollierB_khk",
			"V_BandollierB_oli",
			"V_BandollierB_rgr",
			"V_Chestrig_blk",
			"V_Chestrig_khk",
			"V_Chestrig_oli",
			"V_Chestrig_rgr",
			"V_HarnessO_brn",
			"V_HarnessO_gry",
			"V_HarnessOGL_brn",
			"V_HarnessOGL_gry",
			"V_HarnessOSpec_brn",
			"V_HarnessOSpec_gry",
			"V_PlateCarrier1_blk",
			"V_PlateCarrier1_rgr",
			"V_PlateCarrier2_rgr",
			"V_PlateCarrier3_rgr",
			"V_PlateCarrierGL_blk",
			"V_PlateCarrierGL_mtp",
			"V_PlateCarrierGL_rgr",
			"V_PlateCarrierH_CTRG",
			"V_PlateCarrierIA1_dgtl",
			"V_PlateCarrierIA2_dgtl",
			"V_PlateCarrierIAGL_dgtl",
			"V_PlateCarrierIAGL_oli",
			"V_PlateCarrierL_CTRG",
			"V_PlateCarrierSpec_blk",
			"V_PlateCarrierSpec_mtp",
			"V_PlateCarrierSpec_rgr"
		};
	};

	class Headgear 
	{
		name = "Headgear";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\headgear_ca.paa";
		items[] =
		{
			"H_Cap_blk",
			"H_Cap_blk_Raven",
			"H_Cap_blu",
			"H_Cap_brn_SPECOPS",
			"H_Cap_grn",
			"H_Cap_headphones",
			"H_Cap_khaki_specops_UK",
			"H_Cap_oli",
			"H_Cap_press",
			"H_Cap_red",
			"H_Cap_tan",
			"H_Cap_tan_specops_US",
			"H_Watchcap_blk",
			"H_Watchcap_camo",
			"H_Watchcap_khk",
			"H_Watchcap_sgg",
			"H_MilCap_blue",
			"H_MilCap_dgtl",
			"H_MilCap_mcamo",
			"H_MilCap_ocamo",
			"H_MilCap_oucamo",
			"H_MilCap_rucamo",
			"H_Bandanna_camo",
			"H_Bandanna_cbr",
			"H_Bandanna_gry",
			"H_Bandanna_khk",
			"H_Bandanna_khk_hs",
			"H_Bandanna_mcamo",
			"H_Bandanna_sgg",
			"H_Bandanna_surfer",
			"H_Booniehat_dgtl",
			"H_Booniehat_dirty",
			"H_Booniehat_grn",
			"H_Booniehat_indp",
			"H_Booniehat_khk",
			"H_Booniehat_khk_hs",
			"H_Booniehat_mcamo",
			"H_Booniehat_tan",
			"H_Hat_blue",
			"H_Hat_brown",
			"H_Hat_camo",
			"H_Hat_checker",
			"H_Hat_grey",
			"H_Hat_tan",
			"H_StrawHat",
			"H_StrawHat_dark",
			"H_Beret_02",
			"H_Beret_blk",
			"H_Beret_blk_POLICE",
			"H_Beret_brn_SF",
			"H_Beret_Colonel",
			"H_Beret_grn",
			"H_Beret_grn_SF",
			"H_Beret_ocamo",
			"H_Beret_red",
			"H_Shemag_khk",
			"H_Shemag_olive",
			"H_Shemag_olive_hs",
			"H_Shemag_tan",
			"H_ShemagOpen_khk",
			"H_ShemagOpen_tan",
			"H_TurbanO_blk",
			"H_HelmetB",
			"H_HelmetB_black",
			"H_HelmetB_camo",
			"H_HelmetB_desert",
			"H_HelmetB_grass",
			"H_HelmetB_light",
			"H_HelmetB_light_black",
			"H_HelmetB_light_desert",
			"H_HelmetB_light_grass",
			"H_HelmetB_light_sand",
			"H_HelmetB_light_snakeskin",
			"H_HelmetB_paint",
			"H_HelmetB_plain_blk",
			"H_HelmetB_sand",
			"H_HelmetB_snakeskin",
			"H_HelmetCrew_B",
			"H_HelmetCrew_I",
			"H_HelmetCrew_O",
			"H_HelmetIA",
			"H_HelmetIA_camo",
			"H_HelmetIA_net",
			"H_HelmetLeaderO_ocamo",
			"H_HelmetLeaderO_oucamo",
			"H_HelmetO_ocamo",
			"H_HelmetO_oucamo",
			"H_HelmetSpecB",
			"H_HelmetSpecB_blk",
			"H_HelmetSpecB_paint1",
			"H_HelmetSpecB_paint2",
			"H_HelmetSpecO_blk",
			"H_HelmetSpecO_ocamo",
			"H_CrewHelmetHeli_B",
			"H_CrewHelmetHeli_I",
			"H_CrewHelmetHeli_O",
			"H_HelmetCrew_I",
			"H_HelmetCrew_B",
			"H_HelmetCrew_O",
			"H_PilotHelmetHeli_B",
			"H_PilotHelmetHeli_I",
			"H_PilotHelmetHeli_O"
		};
	};


	class PointerAttachments 
	{
		name = "Pointer Attachments";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"acc_flashlight",
			"acc_pointer_IR"
		};
	};

	class BipodAttachments 
	{
		name = "Bipod Attachments";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itembipod_ca.paa";
		items[] = 
		{
			"bipod_01_F_blk",
			"bipod_01_F_mtp",
			"bipod_01_F_snd",
			"bipod_02_F_blk",
			"bipod_02_F_hex",
			"bipod_02_F_tan",
			"bipod_03_F_blk",
			"bipod_03_F_oli"
		};
	};

	class MuzzleAttachments 
	{
		name = "Suppressor Attachments";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemmuzzle_ca.paa";
		items[] = 
		{
			"muzzle_snds_338_black",
			"muzzle_snds_338_green",
			"muzzle_snds_338_sand",
			"muzzle_snds_93mmg",
			"muzzle_snds_93mmg_tan",
			"muzzle_snds_acp",
			"muzzle_snds_B",
			"muzzle_snds_H",
			"muzzle_snds_H_MG",
			"muzzle_snds_H_SW",
			"muzzle_snds_L",
			"muzzle_snds_M"
		};
	};

	class UAVs
	{
		name = "Unmanned Aerial Vehicles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\gps_ca.paa";
		items[] = 
		{
			"I_UavTerminal",
			"I_UAV_01_backpack_F"
		};
	};

	class StaticMGs
	{
		name = "Static Machine Guns";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"O_HMG_01_support_F",
			"O_HMG_01_weapon_F"
		};
	};

	class OpticAttachments 
	{
		name = "Scopes";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemoptic_ca.paa";
		items[] = 
		{
			"optic_Aco",
			"optic_ACO_grn",
			"optic_ACO_grn_smg",
			"optic_Aco_smg",
			"optic_AMS",
			"optic_AMS_khk",
			"optic_AMS_snd",
			"optic_Arco",
			"optic_DMS",
			"optic_Hamr",
			"optic_Holosight",
			"optic_Holosight_smg",
			"optic_KHS_blk",
			"optic_KHS_hex",
			"optic_KHS_old",
			"optic_KHS_tan",
			"optic_LRPS",
			"optic_MRCO",
			"optic_MRD",
			"optic_Nightstalker",
			"optic_NVS",
			"optic_SOS",
			//"optic_tws",
			//"optic_tws_mg",
			"optic_Yorris"
		};
	};

	class Hardware 
	{
		name = "Hardware";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Item_Rope",
			"Extremo_Item_DuctTape",
			"Extremo_Item_ExtensionCord",
			"Extremo_Item_FuelCanisterEmpty",
			"Extremo_Item_JunkMetal",
			"Extremo_Item_LightBulb",
			"Extremo_Item_MetalBoard",
			"Extremo_Item_MetalPole",
			"Extremo_Item_SafeKit",
			"Extremo_Item_CamoTentKit",
			"Extremo_Item_CodeLock"
			
		};
	};

	class Food 
	{
		name = "Fast Food";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Extremo_Item_EMRE",		
			"Extremo_Item_GloriousKnakworst",
			"Extremo_Item_Surstromming",
			"Extremo_Item_SausageGravy",
			"Extremo_Item_Catfood",
			"Extremo_Item_ChristmasTinner",
			"Extremo_Item_BBQSandwich",
			"Extremo_Item_Dogfood",
			"Extremo_Item_BeefParts",
			"Extremo_Item_Cheathas",
			"Extremo_Item_Noodles",
			"Extremo_Item_SeedAstics",
			"Extremo_Item_Raisins",
			"Extremo_Item_Moobar",
			"Extremo_Item_InstantCoffee"
		};
	};

	class Drinks 
	{
		name = "Drinks";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] =
		{
			"Extremo_Item_PlasticBottleCoffee",
			"Extremo_Item_PowerDrink",
			"Extremo_Item_PlasticBottleFreshWater",
			"Extremo_Item_Beer",
			"Extremo_Item_Whisky",			
			"Extremo_Item_EnergyDrink",
			"Extremo_Item_MountainDupe",
			"Extremo_Item_PlasticBottleEmpty"
		};
	};

	class Tools
	{
		name = "Tools";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Item_Matches",
			"Extremo_Item_CookingPot",
			"Extremo_Item_CanOpener",
			"Extremo_Item_Handsaw",
			"Extremo_Item_Pliers",
			"Extremo_Item_Grinder",
			"Binocular",
			"Rangefinder",
			"NVGoggles",
			"NVGoggles_INDEP",
			"NVGoggles_OPFOR",
			"ItemGPS",
			"ItemMap",
			"ItemCompass", 
			"ItemWatch",
			"Extremo_Item_XM8"
		};
	};

	class FirstAid
	{
		name = "FirstAid";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Item_InstaDoc",
			"Extremo_Item_Bandage",
			"Extremo_Item_Vishpirin"

			// Not available in 0.9.4!
			//"Extremo_Item_Defibrillator"
		};
	};
	class Navigation
	{
		name = "Special Environment";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"B_Parachute",
			"V_RebreatherB",
			"V_RebreatherIA",
			"V_RebreatherIR"		
		};
	};

	class Backpacks
	{
		name = "Backpacks";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\backpack_ca.paa";
		items[] = 
		{
			"B_AssaultPack_blk",
			"B_AssaultPack_cbr",
			"B_AssaultPack_dgtl",
			"B_AssaultPack_khk",
			"B_AssaultPack_mcamo",
			"B_AssaultPack_rgr",
			"B_AssaultPack_sgg",
			"B_Bergen_blk",
			"B_Bergen_mcamo",
			"B_Bergen_rgr",
			"B_Bergen_sgg",
			"B_Carryall_cbr",
			"B_Carryall_khk",
			"B_Carryall_mcamo",
			"B_Carryall_ocamo",
			"B_Carryall_oli",
			"B_Carryall_oucamo",
			"B_FieldPack_blk",
			"B_FieldPack_cbr",
			"B_FieldPack_ocamo",
			"B_FieldPack_oucamo",
			"B_HuntingBackpack",
			"B_Kitbag_cbr",
			"B_Kitbag_mcamo",
			"B_Kitbag_sgg",
			"B_OutdoorPack_blk",
			"B_OutdoorPack_blu",
			"B_OutdoorPack_tan",
			"B_TacticalPack_blk",
			"B_TacticalPack_mcamo",
			"B_TacticalPack_ocamo",
			"B_TacticalPack_oli",
			"B_TacticalPack_rgr"
		};
	};

	class Ammunition
	{
		name = "Ammunition";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"100Rnd_65x39_caseless_mag",
			"100Rnd_65x39_caseless_mag_Tracer",
			"10Rnd_127x54_Mag",
			"10Rnd_338_Mag",
			"10Rnd_762x54_Mag",
			"10Rnd_93x64_DMR_05_Mag",
			"11Rnd_45ACP_Mag",
			//"130Rnd_338_Mag", SPMG
			"150Rnd_762x54_Box",
			"150Rnd_762x54_Box_Tracer",
			//"150Rnd_93x64_Mag", // NAVID
			"16Rnd_9x21_Mag",
			"200Rnd_65x39_cased_Box",
			"200Rnd_65x39_cased_Box_Tracer",
			"20Rnd_556x45_UW_mag",
			"20Rnd_762x51_Mag",
			"30Rnd_45ACP_Mag_SMG_01",
			"30Rnd_45ACP_Mag_SMG_01_tracer_green",
			"30Rnd_45ACP_Mag_SMG_01_Tracer_Red",
			"30Rnd_45ACP_Mag_SMG_01_Tracer_Yellow",
			"30Rnd_556x45_Stanag",
			"30Rnd_556x45_Stanag_Tracer_Green",
			"30Rnd_556x45_Stanag_Tracer_Red",
			"30Rnd_556x45_Stanag_Tracer_Yellow",
			"30Rnd_65x39_caseless_green",
			"30Rnd_65x39_caseless_green_mag_Tracer",
			"30Rnd_65x39_caseless_mag",
			"30Rnd_65x39_caseless_mag_Tracer",
			"30Rnd_9x21_Mag",
			"5Rnd_127x108_APDS_Mag",
			"5Rnd_127x108_Mag",
			"6Rnd_45ACP_Cylinder",
			"6Rnd_GreenSignal_F",
			"6Rnd_RedSignal_F",
			"7Rnd_408_Mag",
			"9Rnd_45ACP_Mag"
		};
	};

	class Flares 
	{
		name = "Flares";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Chemlight_blue",
			"Chemlight_green",
			"Chemlight_red",
			"FlareGreen_F",
			"FlareRed_F",
			"FlareWhite_F",
			"FlareYellow_F",
			"UGL_FlareGreen_F",
			"UGL_FlareRed_F",
			"UGL_FlareWhite_F",
			"UGL_FlareYellow_F",
			"3Rnd_UGL_FlareGreen_F",
			"3Rnd_UGL_FlareRed_F",
			"3Rnd_UGL_FlareWhite_F",
			"3Rnd_UGL_FlareYellow_F"
		};
	};

	class Smokes 
	{
		name = "Smokes";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"SmokeShell",
			"SmokeShellBlue",
			"SmokeShellGreen",
			"SmokeShellOrange",
			"SmokeShellPurple",
			"SmokeShellRed",
			"SmokeShellYellow",
			"1Rnd_Smoke_Grenade_shell",
			"1Rnd_SmokeBlue_Grenade_shell",
			"1Rnd_SmokeGreen_Grenade_shell",
			"1Rnd_SmokeOrange_Grenade_shell",
			"1Rnd_SmokePurple_Grenade_shell",
			"1Rnd_SmokeRed_Grenade_shell",
			"1Rnd_SmokeYellow_Grenade_shell",
			"3Rnd_Smoke_Grenade_shell",
			"3Rnd_SmokeBlue_Grenade_shell",
			"3Rnd_SmokeGreen_Grenade_shell",
			"3Rnd_SmokeOrange_Grenade_shell",
			"3Rnd_SmokePurple_Grenade_shell",
			"3Rnd_SmokeRed_Grenade_shell",
			"3Rnd_SmokeYellow_Grenade_shell"
		};
	};	

	class Explosives
	{
		name = "Explosives";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\cargothrow_ca.paa";
		items[] = 
		{
			"HandGrenade",
			"MiniGrenade",
			"B_IR_Grenade",
			"O_IR_Grenade",
			"I_IR_Grenade",
			"1Rnd_HE_Grenade_shell",
			"3Rnd_HE_Grenade_shell",
			"APERSBoundingMine_Range_Mag",
			"APERSMine_Range_Mag",
			"APERSTripMine_Wire_Mag",
			"ClaymoreDirectionalMine_Remote_Mag",
			"DemoCharge_Remote_Mag",
			"IEDLandBig_Remote_Mag",
			"IEDLandSmall_Remote_Mag",
			"IEDUrbanBig_Remote_Mag",
			"IEDUrbanSmall_Remote_Mag",
			"SatchelCharge_Remote_Mag",
			"SLAMDirectionalMine_Wire_Mag"
		};
	};

	class Pistols 
	{
		name = "Pistols";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\handgun_ca.paa";
		items[] = 
		{
			"hgun_ACPC2_F",
			"hgun_P07_F",
			"hgun_Pistol_heavy_01_F",
			"hgun_Pistol_heavy_02_F",
			"hgun_Pistol_Signal_F",
			"hgun_Rook40_F"
		};
	};

	class SubMachineGuns 
	{
		name = "Sub Machine Guns";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"hgun_PDW2000_F",
			"SMG_01_F",
			"SMG_02_F"
		};
	};

	class LightMachineGuns 
	{
		name = "Light Machine Guns";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"arifle_MX_SW_Black_F",
			"arifle_MX_SW_F",
			"LMG_Mk200_F",
			"LMG_Zafir_F"

		};
	};

	class AssaultRifles
	{
		name = "Assault Rifles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"arifle_Katiba_C_F",
			"arifle_Katiba_F",
			"arifle_Katiba_GL_F",
			"arifle_Mk20_F",
			"arifle_Mk20_GL_F",
			"arifle_Mk20_GL_plain_F",
			"arifle_Mk20_plain_F",
			"arifle_Mk20C_F",
			"arifle_Mk20C_plain_F",
			"arifle_MX_Black_F",
			"arifle_MX_F",
			"arifle_MX_GL_Black_F",
			"arifle_MX_GL_F",
			"arifle_MXC_Black_F",
			"arifle_MXC_F",
			"arifle_SDAR_F",
			"arifle_TRG20_F",
			"arifle_TRG21_F",
			"arifle_TRG21_GL_F"
		};
	};

	class SniperRifles
	{
		name = "Sniper Rifles";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"arifle_MXM_Black_F",
			"arifle_MXM_F",
			"srifle_DMR_01_F",
			"srifle_DMR_02_camo_F",
			"srifle_DMR_02_F",
			"srifle_DMR_02_sniper_F",
			"srifle_DMR_03_F",
			"srifle_DMR_03_khaki_F",
			"srifle_DMR_03_multicam_F",
			"srifle_DMR_03_tan_F",
			"srifle_DMR_03_woodland_F",
			"srifle_DMR_04_F",
			"srifle_DMR_04_Tan_F",
			"srifle_DMR_05_blk_F",
			"srifle_DMR_05_hex_F",
			"srifle_DMR_05_tan_f",
			"srifle_DMR_06_camo_F",
			"srifle_DMR_06_olive_F",
			"srifle_EBR_F",
			"srifle_GM6_camo_F",
			"srifle_GM6_F",
			"srifle_LRR_camo_F",
			"srifle_LRR_F"
		};
	};

	class Bikes
	{
		name = "Bikes";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Bike_OldBike",
			"Extremo_Bike_MountainBike"
		};
	};

	class Cars
	{
		name = "Cars";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Car_Kart_Black",
			"Extremo_Bike_QuadBike_Black",
			"Extremo_Car_Lada_Green",
			"Extremo_Car_Volha_White",
			"Extremo_Car_Hatchback_Rusty1",
			"Extremo_Car_Hatchback_Rusty2",
			"Extremo_Car_Hatchback_Rusty3",
			"Extremo_Car_Hatchback_Sport_Red",
			"Extremo_Car_SUV_Red",
			"Extremo_Car_SUVXL_Black",
			"Extremo_Car_Offroad_Rusty1",
			"Extremo_Car_Offroad_Rusty2",
			"Extremo_Car_Offroad_Rusty3",
			"Extremo_Car_Offroad_Repair_Civillian",
			"Extremo_Car_Offroad_Armed_Guerilla01",
			"Extremo_Car_Strider",
			"Extremo_Car_Hunter",
			"Extremo_Car_Ifrit"
		};
	};

	class Trucks
	{
		name = "Trucks";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Car_Van_Black",
			"Extremo_Car_Van_Box_Black",
			"Extremo_Car_Van_Fuel_Black",
			"Extremo_Car_Zamak",
			"Extremo_Car_Tempest",
			"Extremo_Car_HEMMT",
			"Extremo_Car_Ikarus_Blue",
			"Extremo_Car_Ural_Open_Worker",
			"Extremo_Car_Ural_Covered_Worker"
		};
	};

	class Choppers
	{
		name = "Helicopters";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Chopper_Hummingbird_Green",
			"Extremo_Chopper_Hummingbird_Civillian_Wasp",
			"Extremo_Chopper_Taru_Black",
			"Extremo_Chopper_Taru_Covered_Black",
			"Extremo_Chopper_Taru_Transport_Black",
			"Extremo_Chopper_Orca_BlackCustom",
			"Extremo_Chopper_Mohawk_FIA",
			"Extremo_Chopper_Huron_Black",
			"Extremo_Chopper_Hellcat_Green"
		};
	};

	class Boats
	{
		name = "Boats";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Boat_RubberDuck_CSAT",
			"Extremo_Boat_RubberDuck_Digital",
			"Extremo_Boat_RubberDuck_Orange",
			"Extremo_Boat_RubberDuck_Blue",
			"Extremo_Boat_RubberDuck_Black",
			"Extremo_Boat_MotorBoat_Police",
			"Extremo_Boat_MotorBoat_Orange",
			"Extremo_Boat_MotorBoat_White",
			"Extremo_Boat_SDV_CSAT",
			"Extremo_Boat_SDV_Digital",
			"Extremo_Boat_SDV_Grey"
		};
	};

	class Planes
	{
		name = "Planes";
		icon = "a3\ui_f\data\gui\Rsc\RscDisplayArsenal\itemacc_ca.paa";
		items[] = 
		{
			"Extremo_Plane_Cessna"
		};
	};
};
class CfgTraders
{

	class Extremo_Trader_Armory
	{
		name = "ARMORY";
		showWeaponFilter = 1;
		categories[] = 
		{
			"PointerAttachments",
			"BipodAttachments",
			"MuzzleAttachments",
			"OpticAttachments",
			"Ammunition",
			"Pistols",
			"SubMachineGuns",
			"LightMachineGuns",
			"AssaultRifles",
			"SniperRifles"
		};
	};

	class Extremo_Trader_SpecialOperations
	{
		name = "SPECIAL OPERATIONS";
		showWeaponFilter = 1;
		categories[] = 
		{
			"Flares",
			"Smokes",
			"UAVs",
			"StaticMGs",
			"Explosives",
			"Navigation"
		};
	};


	class Extremo_Trader_Equipment
	{	
		name = "EQUIPMENT";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Headgear",
			"Uniforms",
			"Vests",
			"Backpacks",
			"FirstAid"
		};
	};


	class Extremo_Trader_Food
	{
		name = "FAST FOOD";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Food",
			"Drinks"
		};
	};


	class Extremo_Trader_Hardware
	{
		name = "HARDWARE";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Hardware",
			"Tools"
		};
	};


	class Extremo_Trader_Vehicle
	{
		name = "VEHICLE";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Cars",
			"Trucks"
		};
	};

	class Extremo_Trader_Aircraft
	{
		name = "AIRCRAFT";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Choppers", 
			"Planes"
		};
	};
 
	class Extremo_Trader_Boat
	{
		name = "BOAT";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Boats"
		};
	};

	class Extremo_Trader_CommunityCustoms
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community"
		};
	};

	class Extremo_Trader_CommunityCustoms2
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community2"
		};
	};

	class Extremo_Trader_CommunityCustoms3
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community3"
		};
	};

	class Extremo_Trader_CommunityCustoms4
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community4"
		};
	};

	class Extremo_Trader_CommunityCustoms5
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community5"
		};
	};

	class Extremo_Trader_CommunityCustoms6
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community6"
		};
	};

	class Extremo_Trader_CommunityCustoms7
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community7"
		};
	};

	class Extremo_Trader_CommunityCustoms8
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community8"
		};
	};

	class Extremo_Trader_CommunityCustoms9
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community9"
		};
	};

	class Extremo_Trader_CommunityCustoms10
	{
		name = "COMMUNITY";
		showWeaponFilter = 0;
		categories[] = 
		{
			"Community10"
		};
	};
};
class CfgTrading 
{
	sellPriceFactor = 0.5;
};
class CfgVehicleCustoms
{
	class Extremo_Bike_QuadBike_Abstract
	{
		skins[] = 
		{
			{"Extremo_Bike_QuadBike_Black",		100},
			{"Extremo_Bike_QuadBike_Blue",		100},
			{"Extremo_Bike_QuadBike_Red",			100},
			{"Extremo_Bike_QuadBike_White",		100},
			{"Extremo_Bike_QuadBike_Nato",		150},
			{"Extremo_Bike_QuadBike_Csat",		150},
			{"Extremo_Bike_QuadBike_Fia",			150},
			{"Extremo_Bike_QuadBike_Guerilla01",	150},
			{"Extremo_Bike_QuadBike_Guerilla02",	150}
		};
	};

	class Extremo_Boat_MotorBoat_Abstract
	{
		skins[] = 
		{
			{"Extremo_Boat_MotorBoat_Police",		350},
			{"Extremo_Boat_MotorBoat_Orange",		300},
			{"Extremo_Boat_MotorBoat_White",		300}
		};
	};

	class Extremo_Boat_RubberDuck_Abstract
	{
		skins[] = 
		{
			{"Extremo_Boat_RubberDuck_CSAT",		200},
			{"Extremo_Boat_RubberDuck_Digital",	200},
			{"Extremo_Boat_RubberDuck_Orange",	150},
			{"Extremo_Boat_RubberDuck_Blue",		150},
			{"Extremo_Boat_RubberDuck_Black",		150}
		};
	};

	class Extremo_Boat_SDV_Abstract
	{
		skins[] = 
		{
			{"Extremo_Boat_SDV_CSAT",		200},
			{"Extremo_Boat_SDV_Digital",	200},
			{"Extremo_Boat_SDV_Grey",		100}
		};
	};

	class Extremo_Chopper_Hellcat_Abstract
	{
		skins[] = 
		{
			{"Extremo_Chopper_Hellcat_Green", 350},
			{"Extremo_Chopper_Hellcat_FIA", 	500}
		};
	};

	class Extremo_Car_Kart_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_Kart_BluKing", 				100},	
			{"Extremo_Car_Kart_RedStone", 			100},
			{"Extremo_Car_Kart_Vrana", 				100},	
			{"Extremo_Car_Kart_Green", 				100},	
			{"Extremo_Car_Kart_Blue", 				100},	
			{"Extremo_Car_Kart_Orange", 				100},	
			{"Extremo_Car_Kart_White", 				100},	
			{"Extremo_Car_Kart_Yellow", 				100},	
			{"Extremo_Car_Kart_Black", 				100}	
		};
	};

	class Extremo_Chopper_Hummingbird_Civillian_Abstract
	{
		skins[] = 
		{
			{"Extremo_Chopper_Hummingbird_Civillian_Blue", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_Red", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_ION", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_BlueLine", 	350},
			{"Extremo_Chopper_Hummingbird_Civillian_Digital", 	350},
			{"Extremo_Chopper_Hummingbird_Civillian_Elliptical", 	350},
			{"Extremo_Chopper_Hummingbird_Civillian_Furious", 	350},
			{"Extremo_Chopper_Hummingbird_Civillian_GrayWatcher", 350},
			{"Extremo_Chopper_Hummingbird_Civillian_Jeans", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_Light", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_Shadow", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_Sheriff", 	350},
			{"Extremo_Chopper_Hummingbird_Civillian_Speedy", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_Sunset", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_Vrana", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_Wasp", 		350},
			{"Extremo_Chopper_Hummingbird_Civillian_Wave", 		350}
		};
	};

	class Extremo_Chopper_Huron_Abstract
	{
		skins[] = 
		{
			{"Extremo_Chopper_Huron_Black", 	450},
			{"Extremo_Chopper_Huron_Green", 	450}
		};
	};

	class Extremo_Chopper_Orca_Abstract
	{
		skins[] = 
		{
			{"Extremo_Chopper_Orca_CSAT", 		350},
			{"Extremo_Chopper_Orca_Black", 		350},
			{"Extremo_Chopper_Orca_BlackCustom", 	350}
		};
	};

	class Extremo_Chopper_Taru_Abstract
	{
		skins[] = 
		{
			{"Extremo_Chopper_Taru_CSAT",		500},
			{"Extremo_Chopper_Taru_Black",	500}
		};
	};

	class Extremo_Chopper_Taru_Transport_Abstract
	{
		skins[] = 
		{
			{"Extremo_Chopper_Taru_Transport_CSAT",	500},
			{"Extremo_Chopper_Taru_Transport_Black",	500}
		};
	};

	class Extremo_Chopper_Taru_Covered_Abstract
	{
		skins[] = 
		{
			{"Extremo_Chopper_Taru_Covered_CSAT",		500},
			{"Extremo_Chopper_Taru_Covered_Black",	500}
		};
	};

	class Extremo_Car_Hatchback_Abstract
	{	
		skins[] = 
		{
			{"Extremo_Car_Hatchback_Rusty1", 			50},
			{"Extremo_Car_Hatchback_Rusty2", 			50},
			{"Extremo_Car_Hatchback_Rusty3", 			50},
			{"Extremo_Car_Hatchback_Beige", 			100},
			{"Extremo_Car_Hatchback_Green", 			100},
			{"Extremo_Car_Hatchback_Blue", 			100},
			{"Extremo_Car_Hatchback_BlueCustom", 		100},
			{"Extremo_Car_Hatchback_BeigeCustom", 	100},
			{"Extremo_Car_Hatchback_Yellow", 			100},
			{"Extremo_Car_Hatchback_Grey", 			100},
			{"Extremo_Car_Hatchback_Black", 			100},
			{"Extremo_Car_Hatchback_Dark", 			100}
		};
	};

	class Extremo_Car_Hatchback_Sport_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_Hatchback_Sport_Red", 		100},
			{"Extremo_Car_Hatchback_Sport_Blue", 		100},
			{"Extremo_Car_Hatchback_Sport_Orange", 	100},
			{"Extremo_Car_Hatchback_Sport_White", 	100},
			{"Extremo_Car_Hatchback_Sport_Beige", 	100},
			{"Extremo_Car_Hatchback_Sport_Green", 	100}
		};
	};

	class Extremo_Car_Offroad_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_Offroad_Rusty1", 		50},
			{"Extremo_Car_Offroad_Rusty2", 		50},
			{"Extremo_Car_Offroad_Rusty3", 		50},
			{"Extremo_Car_Offroad_Red", 			500},
			{"Extremo_Car_Offroad_Beige", 		500},
			{"Extremo_Car_Offroad_White", 		500},
			{"Extremo_Car_Offroad_Blue", 			500},
			{"Extremo_Car_Offroad_DarkRed", 		500},
			{"Extremo_Car_Offroad_BlueCustom", 	500},
			{"Extremo_Car_Offroad_Guerilla01", 	700},
			{"Extremo_Car_Offroad_Guerilla02", 	700},
			{"Extremo_Car_Offroad_Guerilla03", 	700},
			{"Extremo_Car_Offroad_Guerilla04", 	700},
			{"Extremo_Car_Offroad_Guerilla05", 	700},
			{"Extremo_Car_Offroad_Guerilla06", 	700},
			{"Extremo_Car_Offroad_Guerilla07", 	700},
			{"Extremo_Car_Offroad_Guerilla08", 	700},
			{"Extremo_Car_Offroad_Guerilla09", 	700},
			{"Extremo_Car_Offroad_Guerilla10", 	700},
			{"Extremo_Car_Offroad_Guerilla11", 	700},
			{"Extremo_Car_Offroad_Guerilla12", 	700}
		};
	};

	class Extremo_Car_Offroad_Armed_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_Offroad_Armed_Guerilla01",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla02",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla03",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla04",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla05",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla06",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla07",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla08",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla09",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla10",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla11",	250},
			{"Extremo_Car_Offroad_Armed_Guerilla12",	250}
		};
	};

	class Extremo_Car_Offroad_Repair_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_Offroad_Repair_Civillian",		150},
			{"Extremo_Car_Offroad_Repair_Red",			150},
			{"Extremo_Car_Offroad_Repair_Beige",			150},
			{"Extremo_Car_Offroad_Repair_White",			150},
			{"Extremo_Car_Offroad_Repair_Blue",			150},
			{"Extremo_Car_Offroad_Repair_DarkRed",		150},
			{"Extremo_Car_Offroad_Repair_BlueCustom",		150},
			{"Extremo_Car_Offroad_Repair_Guerilla01",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla02",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla03",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla04",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla05",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla06",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla07",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla08",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla09",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla10",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla11",		250},
			{"Extremo_Car_Offroad_Repair_Guerilla12",		250}
		};
	};

	class Extremo_Car_SUV_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_SUV_Red", 		100},
			{"Extremo_Car_SUV_Black", 	150},
			{"Extremo_Car_SUV_Grey", 		100},
			{"Extremo_Car_SUV_Orange", 	100}
		};
	};

	class Extremo_Car_SUVXL_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_SUVXL_Black", 100}
		};
	};

	class Extremo_Car_Van_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_Van_Black",			100},
			{"Extremo_Car_Van_White",			100},
			{"Extremo_Car_Van_Red",			100},
			{"Extremo_Car_Van_Guerilla01",	150},
			{"Extremo_Car_Van_Guerilla02",	150},
			{"Extremo_Car_Van_Guerilla03",	150},
			{"Extremo_Car_Van_Guerilla04",	150},
			{"Extremo_Car_Van_Guerilla05",	150},
			{"Extremo_Car_Van_Guerilla06",	150},
			{"Extremo_Car_Van_Guerilla07",	150},
			{"Extremo_Car_Van_Guerilla08",	150}
		};
	};

	class Extremo_Car_Van_Box_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_Van_Box_Black",				100},
			{"Extremo_Car_Van_Box_White",				100},
			{"Extremo_Car_Van_Box_Red",				100},
			{"Extremo_Car_Van_Box_Guerilla01",		150},
			{"Extremo_Car_Van_Box_Guerilla02",		150},
			{"Extremo_Car_Van_Box_Guerilla03",		150},
			{"Extremo_Car_Van_Box_Guerilla04",		150},
			{"Extremo_Car_Van_Box_Guerilla05",		150},
			{"Extremo_Car_Van_Box_Guerilla06",		150},
			{"Extremo_Car_Van_Box_Guerilla07",		150},
			{"Extremo_Car_Van_Box_Guerilla08",		150}
		};
	};

	class Extremo_Car_Van_Fuel_Abstract
	{
		skins[] = 
		{
			{"Extremo_Car_Van_Fuel_Black",			100},
			{"Extremo_Car_Van_Fuel_White",			100},
			{"Extremo_Car_Van_Fuel_Red",				100},
			{"Extremo_Car_Van_Fuel_Guerilla01",		150},
			{"Extremo_Car_Van_Fuel_Guerilla02",		150},
			{"Extremo_Car_Van_Fuel_Guerilla03",		150}
		};
	};

	class Extremo_Car_Ikarus_Abstract
	{	
		skins[] = 
		{
			{"Extremo_Car_Ikarus_Blue", 		200},
			{"Extremo_Car_Ikarus_Red", 		200},
			{"Extremo_Car_Ikarus_Party", 		500}
		};
	};

	class Extremo_Car_Ural_Open_Abstract
	{	
		skins[] = 
		{
			{"Extremo_Car_Ural_Open_Blue",			300},
			{"Extremo_Car_Ural_Open_Yellow",			300},
			{"Extremo_Car_Ural_Open_Worker",			300},
			{"Extremo_Car_Ural_Open_Military",		300}
		};
	};

	class Extremo_Car_Ural_Covered_Abstract
	{	
		skins[] = 
		{
			{"Extremo_Car_Ural_Covered_Blue",			300},
			{"Extremo_Car_Ural_Covered_Yellow",		300},
			{"Extremo_Car_Ural_Covered_Worker",		300},
			{"Extremo_Car_Ural_Covered_Military",		300}
		};
	};

	class Extremo_Car_Lada_Abstract
	{	
		skins[] = 
		{
			{"Extremo_Car_Lada_Green", 		100},
			{"Extremo_Car_Lada_Taxi", 		100},
			{"Extremo_Car_Lada_Red", 			100},
			{"Extremo_Car_Lada_White", 		100},
			{"Extremo_Car_Lada_Hipster", 		100}
		};
	};

	class Extremo_Car_Volha_Abstract
	{	
		skins[] = 
		{
			{"Extremo_Car_Volha_Blue", 		100},
			{"Extremo_Car_Volha_White", 		100},
			{"Extremo_Car_Volha_Black",		100}
		};
	};
};
class CfgVehicleTransport 
{
	class Extremo_Container_SupplyBox
	{
		vehicles[] = {"Extremo_Car_Van_Abstract", "Extremo_Car_Offroad_Abstract", "Extremo_Car_Zamak_Abstract", "Extremo_Car_HEMMT_Abstract", "Extremo_Car_Tempest_Abstract"};

		class Extremo_Car_Van_Abstract
		{
			attachPosition[] = {0, -1.1, 0.2};
			cargoIndizes[] = {2, 3, 4, 5, 6, 7}; 
			detachPosition[] = {0, -4.4};
		};

		class Extremo_Car_Offroad_Abstract
		{
			attachPosition[] = {0, -1.6, 0.4};
			cargoIndizes[] = {1, 2, 3, 4}; 
			detachPosition[] = {0, -4};
		};

		class Extremo_Car_Zamak_Abstract
		{
			attachPosition[] = {0.03, 0.3, 0};
			cargoIndizes[] = {2, 3, 4, 5, 6, 7}; 
			detachPosition[] = {0.03, -4.8};
		};

		class Extremo_Car_HEMMT_Abstract
		{
			attachPosition[] = {0.05, -0.1, 0.3};
			cargoIndizes[] = {1, 2, 8, 9}; 
			detachPosition[] = {0.05, -6.1};
		};

		class Extremo__Car_Tempest_Abstract
		{
			attachPosition[] = {0.08, -0.85, 0.4};
			cargoIndizes[] = {1, 6, 7, 9}; 
			detachPosition[] = {0.08, -6};
		};
	};
};
class CfgIdentities
{
	class ExtremoPlayer
	{
		name		= "Survialist";
		nameSound	= "ExtremoPLayer";
		face		= "whiteHead_06";
		glasses		= "None";
		speaker		= "Male05ENG";
		pitch		= 1.1;
	};
	class ExtremoTrader
	{
		name		= "Trader";
		nameSound	= "ExtremoTrader";
		face		= "whiteHead_06";
		glasses		= "None";
		speaker		= "Male05ENG";
		pitch		= 1.1;
	};
	class ExtremoZombie
	{
		name		= "Zombie";
		nameSound	= "ExtremoZombie";
		face		= "whiteHead_06";
		glasses		= "None";
		speaker		= "Male05ENG";
		pitch		= 1.1;
	};
};
class RadioProtocolENG 
{
	class Words 
	{
		ExtremoPLayer[]= {"RadioProtocolENG\Normal\020_Names\Givens.ogg"};
		ExtremoTrader[]= {"RadioProtocolENG\Normal\020_Names\Givens.ogg"};
		ExtremoZombie[]= {"RadioProtocolENG\Normal\020_Names\Givens.ogg"};
	}
};
class CfgEditorCategories
{
	//editorCategory = "Character";
	//editorSubcategory = "Men";
	class Character  { displayName = "Characters"; };
	class Zombie { displayName = "Zombies"; };
	class Animal { displayName = "Animals"; };
	class Building { displayName = "Buildings"; };
	class Vehicle { displayName = "Vehicles"; };
	class Object { displayName = "Objects"; };
	class Gear { displayName = "Gear"; };
};
class CfgEditorSubcategories
{
	//-- Character & Zombie
	class Men { displayName = "Men (Extremo)"; }; 
	class Women { displayName = "Women (Extremo)"; };
	class Slot { displayName = "Slot (Extremo)"; };
	class HC { displayName = "Headless (Extremo)"; };
	//-- Building
	class Construction { displayName = "Construction"; };
	//-- Vehicle
	class Land { displayName = "Land (Extremo)"; };
	class Air { displayName = "Air (Extremo)"; };
	class Water { displayName = "Water (Extremo)"; };
	//-- Object
	class Tablet { displayName = "Tablets (Extremo)"; };
	class Phone { displayName = "Phones (Extremo)"; }; 
	//-- Gear
	class Suit { displayName = "Suits (Extremo)"; };
	class Uniform { displayName = "Uniforms (Extremo)"; };
	class Backpack { displayName = "Backpacks (Extremo)"; };
	class Vest { displayName = "Vests (Extremo)"; };
};

#include "hpp\CfgVehicles.hpp"
#include "hpp\CfgWeapons.hpp"
#include "hpp\ui.hpp"