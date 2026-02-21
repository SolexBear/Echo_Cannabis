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

};

class Echo_DrugTable_Base_Kit : ItemBase
{
	
	ref protected EffectSound 						m_DeployLoopSound;
	
	override void EEInit()
	{
		super.EEInit();
	}
	
	override void OnItemLocationChanged( EntityAI old_owner, EntityAI new_owner ) 
	{
		super.OnItemLocationChanged( old_owner, new_owner );
	}	
	
	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( IsDeploySound() )
		{
			PlayDeploySound();
		}
				
		if ( CanPlayDeployLoopSound() )
		{
			PlayDeployLoopSound();
		}
					
		if ( m_DeployLoopSound && !CanPlayDeployLoopSound() )
		{
			StopDeployLoopSound();
		}
	}
	
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }		
	
	override bool IsDeployable()
	{
		return true;
	}	
	
	override string GetDeploySoundset()
	{
		return "putDown_FenceKit_SoundSet";
	}
	
	override string GetLoopDeploySoundset()
	{
		return "BarbedWire_Deploy_loop_SoundSet";
	}
	
	void PlayDeployLoopSound()
	{		
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{		
			m_DeployLoopSound = SEffectManager.PlaySound( GetLoopDeploySoundset(), GetPosition() );
		}
	}
	
	void StopDeployLoopSound()
	{
		if ( GetGame().IsMultiplayer() && GetGame().IsClient() || !GetGame().IsMultiplayer() )
		{	
			m_DeployLoopSound.SoundStop();
			delete m_DeployLoopSound;
		}
	}	
	
};


class Echo_DrugTable_Kit : Echo_DrugTable_Base_Kit
{	
	protected Object								Echo_DrugTable1;

	void Echo_DrugTable_Kit()
	{
		RegisterNetSyncVariableBool("m_IsSoundSynchRemote");
	}

	override void OnPlacementComplete( Man player, vector position = "0 0 0", vector orientation = "0 0 0" )
{
    super.OnPlacementComplete( player );
    
    PlayerBase pb = PlayerBase.Cast( player );
    if ( GetGame().IsServer() )
    {
        PlayerBase player_base = PlayerBase.Cast( player );
        vector newPosition = player_base.GetLocalProjectionPosition();
        vector newOrientation = player_base.GetLocalProjectionOrientation();
            
        vector pos = pb.GetLocalProjectionPosition();
        vector ori = pb.GetLocalProjectionOrientation();

        Echo_DrugTable1 = GetGame().CreateObject("Echo_DrugTable", pos, false);
        Echo_DrugTable1.SetPosition(pos);
        Echo_DrugTable1.SetOrientation(ori);
    }   
    
    SetIsDeploySound( true );
    SetLifetime(3888000);
}

}


class Echo_DrugTable_Base_Holo : ItemBase {

};
 

class Echo_DrugTable_Holo : Echo_DrugTable_Base_Holo
{

};



