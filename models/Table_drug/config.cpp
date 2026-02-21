
#define _ARMA_

class CfgPatches
{
	class Table_Drug
	{
		units[] = {"Table_Drug","Table_Drug_Holo","Table_Drug_Kit"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","DZ_Scripts","DZ_Gear_Tools","DZ_Gear_Consumables","DZ_Weapons_Melee"};
	};
};
class CfgSlots
{
	class Slot_Echo_BL_lamp
	{
		name = "Echo_BL_lamp";
		displayName = "Echo_BL_lamp";
		ghostIcon = "";
	};
	class Slot_Echo_Paper
	{
		name = "Echo_Paper";
		displayName = "Echo_Paper";
		ghostIcon = "";
	};
	class Slot_Echo_Rag
	{
		name = "Echo_Rag";
		displayName = "Echo_Rag";
		ghostIcon = "";
	};
	class Slot_Echo_disinfectantspray
	{
		name = "Echo_disinfectantspray";
		displayName = "Echo_disinfectantspray";
		ghostIcon = "";
	};
	class Slot_Echo_DisinfectantAlcohol
	{
		name = "Echo_DisinfectantAlcohol";
		displayName = "Echo_DisinfectantAlcohol";
		ghostIcon = "";
	};
	class Slot_Echo_heatpack
	{
		name = "Echo_heatpack";
		displayName = "Echo_heatpack";
		ghostIcon = "";
	};
	class Slot_Echo_DuctTape
	{
		name = "Echo_DuctTape";
		displayName = "Echo_DuctTape";
		ghostIcon = "";
	};
	class Slot_Echo_Scale
	{
		name = "Echo_Scale";
		displayName = "Echo_Scale";
		ghostIcon = "";
	};
	class Slot_Echo_Cannabis
	{
		name = "Echo_Cannabis";
		displayName = "Echo_Cannabis";
		ghostIcon = "";
	};
	class Slot_Echo_Empty_Bag
	{
		name = "Echo_Empty_Bag";
		displayName = "Echo_Empty_Bag";
		ghostIcon = "";
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Container_Base;
	class Bottle_Base;
	class WoodenCrate;
	class bl_placeable;
	class Edible_Base;
	class Echo_Bag_Drugs;
	class Echo_DrugTable: Container_Base
	{
		scope = 2;
		displayName = "$STR_Table_Drug";
		descriptionShort = "$STR_Opis_Table_Drug";
		model = "Echo_Cannabis\models\Table_drug\table_drug.p3d";
		forceFarBubble = "true";
		physLayer = "item_large";
		weight = 100000;
		itemSize[] = {10,50};
		itemBehaviour = 0;
		soundImpactType = "metal";
		overrideDrawArea = "8.0";
		slopeTolerance = 0.2;
		yawPitchRollLimit[] = {45,45,45};
		allowOwnedCargoManipulation = 1;
		destroyOnEmpty = 0;
		class Cargo
		{
			itemsCargoSize[] = {10,4};
			openable = 0;
			allowOwnedCargoManipulation = 1;
		};
		attachments[] = {"Echo_BL_lamp","Echo_Paper","Echo_Rag","Echo_disinfectantspray","Echo_DisinfectantAlcohol","Echo_heatpack","Echo_DuctTape","Echo_Cannabis","Echo_Scale","Echo_Empty_Bag"};
		class GUIInventoryAttachmentsProps
		{
			class Echo_CannabisLamp
			{
				name = "Lampa";
				description = "";
				attachmentSlots[] = {"Echo_BL_lamp"};
				icon = "set:dayz_inventory image:tools";
			};
			class Echo_CannabisCleaning
			{
				name = "Cleaning";
				description = "";
				attachmentSlots[] = {"Echo_Rag","Echo_disinfectantspray","Echo_DisinfectantAlcohol","Echo_heatpack"};
				icon = "";
			};
			class Echo_CannabisPackaging
			{
				name = "Packaging";
				description = "";
				attachmentSlots[] = {"Echo_Paper","Echo_DuctTape","Echo_Empty_Bag","Echo_Scale","Echo_Cannabis"};
				icon = "";
			};
		};
	};
	class Echo_DrugTable_Holo: Echo_DrugTable
	{
		scope = 2;
		displayName = "";
		model = "Echo_Cannabis\models\Table_drug\table_holo.p3d";
	};
	class Echo_DrugTable_Kit: WoodenCrate
	{
		scope = 2;
		displayName = "$STR_Kit_Table_Drug";
		descriptionShort = "";
		itemSize[] = {7,5};
		class Cargo{};
	};
	class bl_desk_lamp: bl_placeable
	{
		scope = 2;
		inventorySlot[] += {"Echo_BL_lamp"};
	};
	class Paper: Inventory_Base
	{
		scope = 2;
		inventorySlot[] += {"Echo_Paper"};
	};
	class Rag: Inventory_Base
	{
		scope = 2;
		inventorySlot[] += {"Echo_Rag"};
	};
	class DisinfectantSpray: Edible_Base
	{
		scope = 2;
		inventorySlot[] += {"Echo_disinfectantspray"};
	};
	class DisinfectantAlcohol: Edible_Base
	{
		scope = 2;
		inventorySlot[] += {"Echo_DisinfectantAlcohol"};
	};
	class Heatpack: Inventory_Base
	{
		inventorySlot[] += {"Echo_heatpack"};
	};
	class DuctTape: Inventory_Base
	{
		inventorySlot[] += {"Echo_DuctTape"};
	};
	class Echo_Scale: Inventory_Base
	{
		inventorySlot[] += {"Echo_Scale"};
	};
	class Cannabis: Edible_Base
	{
		inventorySlot[] += {"Echo_Cannabis"};
	};
    class Echo_Bag_Empty_Drugs: Echo_Bag_Drugs
	{
		inventorySlot[] += {"Echo_Empty_Bag"};
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyEcho_BL_lampProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_BL_lamp";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_BL_lampProx.p3d";
	};
	class ProxyEcho_PaperProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_Paper";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_PaperProx.p3d";
	};
	class ProxyEcho_RagProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_Rag";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_RagProx.p3d";
	};
	class ProxyEcho_disinfectantsprayProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_disinfectantspray";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_disinfectantsprayProx.p3d";
	};
	class ProxyEcho_DisinfectantAlcoholProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_DisinfectantAlcohol";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_DisinfectantAlcoholProx.p3d";
	};
	class ProxyEcho_heatpackProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_heatpack";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_heatpackProx.p3d";
	};
	class ProxyEcho_DuctTapeProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_DuctTape";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_DuctTapeProx.p3d";
	};
	class ProxyEcho_ScaleProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_Scale";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_ScaleProx.p3d";
	};
	class ProxyEcho_CannabisProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_Cannabis";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_CannabisProx.p3d";
	};
	class ProxyEcho_Empty_BagProx: ProxyAttachment
	{
		scope = 2;
		inventorySlot = "Echo_Empty_Bag";
		model = "Echo_Cannabis\models\Table_drug\Proxy\Echo_Empty_BagProx.p3d";
	};
};
