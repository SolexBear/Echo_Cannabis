class CfgPatches
{
	class Echo_Scale
	{
		units[] = {""};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Gear_Camping","DZ_Gear_Medical"};
	};
};
class CfgVehicles
{
    class Inventory_Base;
	class Echo_Scale: Inventory_Base
	{
		scope = 2;
		displayName = "Digital scale";
		descriptionShort = "A digital precision scale, by the looks of it, it has gunpowder residue on it. ";
		model = "Echo_Cannabis\models\Scale\Scale.p3d";
		canBeDigged = 0;
		isMeleeWeapon = 1;
		rotationFlags = 17;
		canBeSplit = 0;
		varQuantityInit = 0;
		varQuantityMin = 0;
		varQuantityMax = 0;
		weight = 200;
		itemSize[] = {2,1};
		repairableWithKits[] = {0};
	};
};	