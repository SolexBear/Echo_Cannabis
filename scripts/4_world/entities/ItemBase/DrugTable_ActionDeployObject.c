modded class ActionDeployObject
{
    override void OnEndServer(ActionData action_data)
    {
        if (!action_data || !action_data.m_MainItem)
            return;

        PlaceObjectActionData poActionData = PlaceObjectActionData.Cast(action_data);

        // Jeśli obiekt NIE został postawiony
        if (!poActionData.m_AlreadyPlaced)
        {
            EntityAI entity_for_placing = action_data.m_MainItem;
            GetGame().ClearJuncture(action_data.m_Player, entity_for_placing);
            action_data.m_MainItem.SetIsBeingPlaced(false);

            if (GetGame().IsMultiplayer())
            {
                action_data.m_Player.PlacingCancelServer();
                action_data.m_MainItem.SoundSynchRemoteReset();
            }
            else
            {
                action_data.m_Player.PlacingCancelLocal();
                action_data.m_Player.LocalTakeEntityToHands(entity_for_placing);
            }

            GetGame().ClearJuncture(action_data.m_Player, action_data.m_MainItem);
            return;
        }

        // Jeśli obiekt ZOSTAŁ postawiony
        action_data.m_MainItem.SetIsDeploySound(false);
        action_data.m_MainItem.SetIsPlaceSound(false);
        action_data.m_MainItem.SoundSynchRemoteReset();

        // Nasz kit
        if (action_data.m_MainItem.IsKindOf("Echo_DrugTable_Kit"))
        {
            Hologram holo = action_data.m_Player.GetHologramServer();

            if (holo)
            {
                vector pos = holo.GetProjectionPosition();
                vector ori = holo.GetProjectionOrientation();

                // Jeśli model ma zły pivot, możesz wymusić poprawną wysokość:
                // pos[1] = GetGame().SurfaceY(pos[0], pos[2]);

                Object table = GetGame().CreateObject("Echo_DrugTable", pos, false, true, true);
                table.SetPosition(pos);
                table.SetOrientation(ori);
            }

            action_data.m_MainItem.Delete(); // usuń kit
            return;
        }

        super.OnEndServer(action_data);
    }
};
