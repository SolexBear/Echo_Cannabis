class CfgPatches
{
	class Echo_Bag_Drugs
	{
		units[] = {"Echo_Bag_Drugs","Echo_Bag_Drugs_empty_drugs","Echo_Bag_Drugs_hemp"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgSlots
{
    class Slot_VodkaBottle
	{
		name = "VodkaBottle";
		displayName = "$STR_VodkaBottle";
		ghostIcon = "set:Slots image:Bottle";
		show = "true";
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Echo_Bag_Drugs: Inventory_Base
	{
		scope=0;
		displayName="$STR_bag_drugs";
		descriptionShort="$STR_bag_drugs";
		model= "DZ\gear\tools\heatpack.p3d";
		rotationFlags=17;
		canBeSplit=1;
		varQuantityInit=16;
		varQuantityMin=0;
		varQuantityMax=160;
		varQuantityDestroyOnMin=1;
		varStackMax=16;
		weight=30;
		itemSize[]={1,3};
		hiddenSelections[]=
		{
			"zbytek"
		};
		inventorySlot[]=
		{
			"Drugs_Bags"
		};
	};	
	class Echo_Bag_Empty_Drugs: Echo_Bag_Drugs
	{
		scope=2;
		displayName="$STR_bag_emptydrugs";
		descriptionShort="$STR_bag_drugs";
		hiddenSelections[]={"zbytek"};
		hiddenSelectionsTextures[]={"Echo_Cannabis\models\bag_drug\data\echo_bag_drugs_empty_co.paa"};
		
	};
    class Echo_Bag_Drugs_hemp: Echo_Bag_Drugs
	{
		scope=2;
		displayName="$STR_bag_emptydrugs";
		descriptionShort="$STR_bag_drugs";
		hiddenSelections[]={"zbytek"};
		hiddenSelectionsTextures[]={"Echo_Cannabis\models\bag_drug\data\cannabis_bag_skunk_co.paa"};
		
	};	
};		
class CfgNonAIVehicles
{
	class ProxyAttachment;
};