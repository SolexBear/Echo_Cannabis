class Echo_DrugTable_Base_Kit : ItemBase
{
	ref protected EffectSound m_DeployLoopSound;
	
	override void EEInit()
	{
		super.EEInit();
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
		return "deployLoop_Fence_SoundSet";
	}
}

class Echo_DrugTable_Kit : Echo_DrugTable_Base_Kit
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}	
}

// Hologram klasa dla Ecka
class Echo_DrugTable_Holo : ItemBase
{
	override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
	}	
}
