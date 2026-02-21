class Echo_DrugTable : Container_Base
{
	static const string 		MICROSCOPE_ATTACH_SOUND = "sparkplug_attach_SoundSet";
	static const string 		MICROSCOPE_DETACH_SOUND = "sparkplug_detach_SoundSet";
	
	override void EEInit()
	{
		super.EEInit();			
	}

	override bool CanDisplayAttachmentCategory( string category_name )
	{	
		return super.CanDisplayAttachmentCategory(category_name);
	}
	
	override string GetPlaceSoundset()
	{
		return "placeBarrel_SoundSet";
	}

	override bool CanPutInCargo( EntityAI parent )
	{
        return false;
	}
	
	override bool CanPutIntoHands( EntityAI parent )
	{
        return false;
	}
	
	override bool CanReceiveItemIntoCargo( EntityAI item )
	{
		return true;
	}

	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionCreateCanSalt); 
		AddAction(ActionCreateCanSugar); 
		AddAction(ActionCreateCanOcet); 
		AddAction(ActionCreateJarOcet);
		AddAction(ActionCreateJarSugar);
		AddAction(ActionCreateMeatCanRabbit);
        AddAction(ActionCreateMeatCanCarp);
        AddAction(ActionCreateMeatCanMackerel);		
		AddAction(ActionCreateMeatCanBear); 
		AddAction(ActionCreateMeatCanBoar);
        AddAction(ActionCreateMeatCanChicken);
        AddAction(ActionCreateMeatCanCow);		
		AddAction(ActionCreateMeatCanDeer); 
		AddAction(ActionCreateMeatCanFox);
        AddAction(ActionCreateMeatCanGoat);
        AddAction(ActionCreateMeatCanPig);
		AddAction(ActionCreateMeatCanSheep);
        AddAction(ActionCreateMeatCanTrout);
        AddAction(ActionCreateMeatCanWalleyePollock);
		AddAction(ActionCreateMeatCanWolf);
		AddAction(ActionCreateMeatCanSardines);
		AddAction(ActionCreateMeatCanReindeer);
		AddAction(ActionCreateMeatCanLard);
		AddAction(ActionCreateFruitCanPear);
		AddAction(ActionCreateFruitCanApple);
		AddAction(ActionCreateFruitCanPlum);
		AddAction(ActionCreateFruitCanPumpkin);
		AddAction(ActionCreateFruitCanpotatoes);
		AddAction(ActionCreateFruitCanTomato);
		AddAction(ActionCreatePickledJarPear);
		AddAction(ActionCreatePickledJarAgaricusMushroom);
		AddAction(ActionCreatePickledJarBoletusMushroom);
		AddAction(ActionCreatePickledJarLactariusMushroom);
		AddAction(ActionCreatePickledJarMacrolepiotaMushroom);
		AddAction(ActionCreatePickledJarPleurotusMushroom);
		AddAction(ActionCreatePickledJarZucchini);
		AddAction(ActionCreatePickledJarPeppers);
		AddAction(ActionCreatePickledJarPumpkin);
		AddAction(ActionCreatePickledCanPeppers);
		AddAction(ActionCreateJamJarPear);
		AddAction(ActionCreateJamJarApple);
		AddAction(ActionCreateJamJarPlum);
		AddAction(ActionCreateJamJarPumpkin);
		AddAction(ActionCreateJamJarCaninaBerry);
		AddAction(ActionCreateJamJarSambucusBerry);
	}
	
	override void EEItemAttached ( EntityAI item, string slot_name )
	{
		super.EEItemAttached ( item, slot_name );
		
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			SEffectManager.PlaySound(MICROSCOPE_ATTACH_SOUND, GetPosition() );
		}
	}
	
	override void EEItemDetached ( EntityAI item, string slot_name )
	{
		super.EEItemDetached ( item, slot_name );
		
		if ( !GetGame().IsServer()  ||  !GetGame().IsMultiplayer() )
		{
			SEffectManager.PlaySound(MICROSCOPE_DETACH_SOUND, GetPosition() );
		}
	}	
}