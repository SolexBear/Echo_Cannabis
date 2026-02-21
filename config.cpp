////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.98
//https://mikero.bytex.digital/Downloads
//'now' is Tue Dec 23 18:27:57 2025 : 'file' last modified on Sat Sep 27 19:26:08 2025
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class Echo_Cannabis
	{
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Tools"};
		units[] = {};
	};
};
class CfgMods
{
	class Echo_Cannabis
	{
		dir = "Echo_Cannabis";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "Echo_Cannabis";
		credits = "";
		author = "Mudarken";
		authorID = "0";
		version = "0.1";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class imageSets
			{
				files[] = {"Echo_Cannabis/GUI/ImageSets/Echo_Cannabis_icon.imageset"};
			};
			class gameScriptModule
			{
				value = "";
				files[] = {"Echo_Cannabis/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Echo_Cannabis/scripts/4_world"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Echo_Cannabis/scripts/5_Mission"};
			};
		};
	};
};
