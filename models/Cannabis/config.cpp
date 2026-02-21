class CfgPatches
{
	class DZ_Gear_Food
	{
		units[]=
		{
			"CannabisSeeds",
			"CannabisSeedsPack",
			"Plant_Cannabis",
			"Cannabis",
			"Carter_Cannabis_SeedsPack"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgVehicles
{
	class Static;
	class PlantBase;
	class SeedBase;
	class HouseNoDestruct;
	class Inventory_Base;
	class Edible_Base;
	class ClutterCutter6x6: Static
	{
		scope=1;
		model="\DZ\gear\cultivation\clutter_cutter_6m_x_6m.p3d";
		displayName="$STR_CfgVehicles_ClutterCutter6x60";
		destrType="DestructNo";
	};
	class ClutterCutter2x2: Static
	{
		scope=1;
		model="\DZ\gear\cultivation\clutter_cutter_2m_x_2m.p3d";
		displayName="$STR_CfgVehicles_ClutterCutter2x20";
		destrType="DestructNo";
	};
	class Trapping
	{
		baitTypes[]={4,3};
		baitTypeChances[]={0.64999998,0.050000001};
		resultQuantityBaseMod=0;
		resultQuantityDispersionMin=0;
		resultQuantityDispersionMax=0;
	};
	class AnimEvents
	{
		class SoundWeapon
		{
			class pickup
			{
				soundSet="seeds_pickup_SoundSet";
				id=797;
			};
		};
	};
    class CannabisSeeds: SeedBase
    {
		scope=0;
		model="\dz\gear\cultivation\cannabis_seeds.p3d";
		canBeSplit=1;
		varQuantityInit=20;
		varQuantityMin=0;
		varQuantityMax=20;
		class Horticulture
		{
			PlantType="Plant_Cannabis";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="seedpack_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
	class Carter_Cannabis_Seeds: CannabisSeeds
    {
		scope=2;
		displayName="$STR_Cannabis_A";
		descriptionShort="$STR_Cannabis_AA";
		class Horticulture
		{
			PlantType="Plant_Carter_Cannabis";
		};
;
	};
	class Carter_CannabisPoster_Seeds: CannabisSeeds
    {
		scope=2;
		displayName="Poster";
		descriptionShort="$STR_Cannabis_AA";
		class Horticulture
		{
			PlantType="Plant_CarterPoster_Cannabis";
		};
;
	};

	class CannabisSeedsPack: Inventory_Base
	{
		scope=0;
		displayName="$STR_Cannabis_B";
		descriptionShort="$STR_Cannabis_BB";
		model="\dz\gear\cultivation\cannabis_seeds_pack.p3d";
		rotationFlags=17;
		quantityBar=1;
		itemSize[]={1,1};
		weight=30;
		spawnOffset=0;
		lootCategory="Materials";
		lootTag[]=
		{
			"Farm",
			"Kitchen",
			"Forester"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=5;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\cultivation\data\cannabis_seeds_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class Horticulture
		{
			ContainsSeedsType="CannabisSeeds";
			ContainsSeedsQuantity=10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack0";
				displayName="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack1";
				position="action";
				onlyForPlayer=1;
				radius=2;
				condition="true";
				statement="this callMethod ['EmptySeedPack', _person];";
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickup
				{
					soundSet="seedpack_pickup_SoundSet";
					id=797;
				};
			};
		};
	};
	class Carter_Cannabis_SeedsPack: CannabisSeedsPack
	{
		scope=2;
		displayName="$STR_Cannabis_B";
		descriptionShort="$STR_Cannabis_BB";

		class Horticulture
		{
			ContainsSeedsType="Carter_Cannabis_Seeds";
			ContainsSeedsQuantity=10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack0";
				displayName="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack1";
				position="action";
				onlyForPlayer=1;
				radius=2;
				condition="true";
				statement="this callMethod ['EmptySeedPack', _person];";
			};
		};

	};
	class Carter_CannabisPoster_SeedsPack: CannabisSeedsPack
	{
		scope=2;
		displayName="seed_Poster";
		descriptionShort="$STR_Cannabis_BB";

		class Horticulture
		{
			ContainsSeedsType="Carter_CannabisPoster_Seeds";
			ContainsSeedsQuantity=10;
		};
		class UserActions
		{
			class EmptyPack
			{
				displayNameDefault="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack0";
				displayName="$STR_CfgVehicles_CannabisSeedsPack_UserActions_EmptyPack1";
				position="action";
				onlyForPlayer=1;
				radius=2;
				condition="true";
				statement="this callMethod ['EmptySeedPack', _person];";
			};
		};

	};
	class Plant_Cannabis: PlantBase
	{
		scope=0;
		displayName="$STR_Cannabis_C";
		descriptionShort="$STR_Cannabis_CC";
		model="DZ\gear\cultivation\Cannabis_plant.p3d";
		hiddenSelectionsTextures[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsCount=7;
			CropsType="Cannabis";
		};
	};
	class Plant_Carter_Cannabis: Plant_Cannabis
	{
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\cultivation\data\Cannabis_plant.rvmat"
		};
		class Horticulture
		{
			GrowthStagesCount=6;
			CropsCount=7;
			CropsType="Carter_Cannabis";
		};
	};
	class Cannabis: Edible_Base
	{
		scope=0;
		displayName="$STR_Cannabis_D";
		descriptionShort="$STR_Cannabis_DD";
		model="\dz\gear\food\cannabis_seedman.p3d";
		debug_ItemCategory=6;
		rotationFlags=34;
		weight=250;
		itemSize[]={2,2};
		stackedUnit="g";
		absorbency=0.2;
		varQuantityInit=10;
		varQuantityMin=0;
		varQuantityMax=10;
		quantityBar=1;
		varTemperatureFreezeTime=2376;
		varTemperatureThawTime=2376;
		varTemperatureMax=110;
		temperaturePerQuantityWeight=0.5;
		inventorySlot[]=
		{
			"Ingredient"
		};
		containsSeedsType="";
		containsSeedsQuantity="0";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\food\data\cannabis_seedman_raw_CO.paa",
			"dz\gear\food\data\cannabis_seedman_baked_CO.paa",
			"dz\gear\food\data\cannabis_seedman_raw_CO.paa",
			"dz\gear\food\data\cannabis_seedman_raw_CO.paa",
			"dz\gear\food\data\cannabis_seedman_baked_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\cannabis_seedman_raw.rvmat",
			"dz\gear\food\data\cannabis_seedman_baked.rvmat",
			"dz\gear\food\data\cannabis_seedman_raw.rvmat",
			"dz\gear\food\data\cannabis_seedman_dried.rvmat",
			"dz\gear\food\data\cannabis_seedman_burnt.rvmat",
			"dz\gear\food\data\cannabis_seedman_rotten.rvmat"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							{}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							{}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							{}
						}
					};
				};
			};
		};	
	};
	class Carter_Cannabis: Cannabis
	{
		scope=2;
		displayName="$STR_Cannabis_D";
		descriptionShort="$STR_Cannabis_DD";
		hiddenSelections[]=
		{
			"cs_raw"
		};
		hiddenSelectionsTextures[]=
		{
			"dz\gear\food\data\cannabis_seedman_raw_CO.paa",
			"dz\gear\food\data\cannabis_seedman_baked_CO.paa",
			"dz\gear\food\data\cannabis_seedman_raw_CO.paa",
			"dz\gear\food\data\cannabis_seedman_raw_CO.paa",
			"dz\gear\food\data\cannabis_seedman_baked_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"dz\gear\food\data\cannabis_seedman_raw.rvmat",
			"dz\gear\food\data\cannabis_seedman_baked.rvmat",
			"dz\gear\food\data\cannabis_seedman_raw.rvmat",
			"dz\gear\food\data\cannabis_seedman_dried.rvmat",
			"dz\gear\food\data\cannabis_seedman_burnt.rvmat",
			"dz\gear\food\data\cannabis_seedman_rotten.rvmat"
		};
	};
	
};