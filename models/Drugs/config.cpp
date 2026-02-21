
#define _ARMA_

class CfgPatches
{
	class Drug_Brick
	{
		units[] = {"Drug_Brick","Drug_Brick_Holo"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Tools","DZ_Gear_Consumables","DZ_Weapons_Melee"};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;

	class Drug_Brick: Container_Base
	{
		scope = 2;
		displayName = "$STR_Drug_Brick";
		descriptionShort = "$STR_Opis_Drug_Brick";
		model = "Echo_Cannabis\models\Drugs\Drugs.p3d";
		forceFarBubble = "true";
		physLayer = "item_large";
		weight = 100000;
		itemSize[] = {2,2};
		itemBehaviour = 0;
		soundImpactType = "metal";
		overrideDrawArea = "8.0";
		slopeTolerance = 0.2;
		yawPitchRollLimit[] = {45,45,45};
		allowOwnedCargoManipulation = 1;
		destroyOnEmpty = 0;
		class Cargo
		{
			itemsCargoSize[] = {4,4};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		attachments[] = {};
	
	};
	class Drug_Brick_Holo: Drug_Brick
	{
		scope = 2;
		displayName = "";
		model = "Echo_Cannabis\models\Drugs\Drugs.p3d";
	};
};