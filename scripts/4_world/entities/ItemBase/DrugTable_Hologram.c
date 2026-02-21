modded class Hologram
{   
    ItemBase DrugTableCollision()
    {
        vector center;
        vector relative_ofset; 
        vector absolute_ofset = "0 0.01 0"; 
        vector orientation = GetProjectionOrientation();
        vector edge_length;
        vector min_max[2];
        ref array<Object> excluded_objects = new array<Object>;
        ref array<Object> collided_objects = new array<Object>;
        
        m_Projection.GetCollisionBox(min_max);
        relative_ofset[1] = (min_max[1][1] - min_max[0][1]) / 2.4;
        center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
        edge_length = GetCollisionBoxSize(min_max);
        excluded_objects.Insert(m_Projection);

        if (GetGame().IsBoxColliding(center, orientation, edge_length, excluded_objects, collided_objects))
        {   
            for (int i = 0; i < collided_objects.Count(); i++)
            {
                Object obj_collided = collided_objects[i];

                // Sprawdzamy po nazwie zamiast po typie klasy
                string obj_name = obj_collided.GetType();
                
                if (obj_name == "Echo_DrugTable_Holo" || obj_collided.IsInherited(Echo_DrugTable))
                {
                    return ItemBase.Cast(obj_collided);
                }
            }
        }
        return null;
    } 

    override string ProjectionBasedOnParent()
    {
        ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());

        if (item_in_hands && item_in_hands.IsKindOf("Echo_DrugTable_Kit"))
            return "Echo_DrugTable_Holo";

        return super.ProjectionBasedOnParent();
    }

    override void EvaluateCollision(ItemBase action_item = null)
    {
        ItemBase projectionItem = m_Parent;

        if (projectionItem && projectionItem.IsKindOf("Echo_DrugTable"))
        {
            if (IsCollidingZeroPos())
            {
                SetIsColliding(true);
                return;
            }
            else
            {
                SetIsColliding(false);
            }
        }
        super.EvaluateCollision(action_item);
    }
}