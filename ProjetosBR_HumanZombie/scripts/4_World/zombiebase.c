/**
 * @author Morette [Bob Construtor] (https://dayzprojectbr.wixsite.com/projectbr)
 * @copyright ProjetoBR (c) 2021
 */

#ifdef SERVER
modded class ZombieBase : DayZInfected
{
    void TransferAttachmentsFrom(EntityAI entity)
    {
        for (int i = 0; i < entity.GetInventory().GetAttachmentSlotsCount(); i++)
        {
            int slot = entity.GetInventory().GetAttachmentSlotId(i);
            EntityAI item = entity.GetInventory().FindAttachment(slot);

            if (item)
            {
                float health = item.GetHealth();
                item.SetHealth(item.GetMaxHealth());

                if (GetInventory().CanAddAttachment(item))
                {
                    entity.ServerTakeEntityToTargetInventory(this, FindInventoryLocationType.ATTACHMENT, item);
                }
                else
                {
                    entity.GetInventory().DropEntity(InventoryMode.SERVER, entity, item);
                }

                item.SetHealth(health);
            }
        }
    }
};
#endif // SERVER

// vim:ft=enforce
