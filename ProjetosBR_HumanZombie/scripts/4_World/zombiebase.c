/**
 * @author Morette [Bob Construtor] (https://dayzprojectbr.wixsite.com/projectbr)
 * @copyright ProjetoBR (c) 2021
 */

modded class ZombieBase : DayZInfected
{
    protected bool m_ReceivedAttachments;

    void HumanZombie_Base()
    {
        RegisterNetSyncVariableBool("m_ReceivedAttachments");
    }

    void TransferAttachmentsFromZombie(EntityAI entity)
    {
        if (g_Game.GetPBHZConfig().Get_SpawnZombieOnPlayersDeath())
        {
        for (int i = 0; i < entity.GetInventory().GetAttachmentSlotsCount(); i++)
        {
            int slot = entity.GetInventory().GetAttachmentSlotId(i);
            EntityAI item = entity.GetInventory().FindAttachment(slot);

            if (item)
            {
                float health;

                if (GetGame().IsServer())
                {
                    health = item.GetHealth();
                    item.SetHealth(item.GetMaxHealth());
                }

                if (GetInventory().CanAddAttachment(item))
                {
                    if (GetGame().IsMultiplayer())
                        entity.ServerTakeEntityToTargetInventory(this, FindInventoryLocationType.ATTACHMENT, item);
                    else
                        entity.LocalTakeEntityToTargetInventory(this, FindInventoryLocationType.ATTACHMENT, item);
                }
                else
                {
                    if (GetGame().IsMultiplayer())
                        entity.GetInventory().DropEntity(InventoryMode.SERVER, entity, item);
                    else
                        entity.GetInventory().DropEntity(InventoryMode.LOCAL, entity, item);
                }

                if (GetGame().IsServer())
                    item.SetHealth(health);
            }
        }

        m_ReceivedAttachments = true;
        SetSynchDirty();
        }
    }

    override bool HandleDeath(int pCurrentCommandID)
    {
        if ( pCurrentCommandID == DayZInfectedConstants.COMMANDID_DEATH )
        {
            return true;
        }

        if ( !IsAlive() )
        {
            StartCommand_Death(m_DeathType, m_DamageHitDirection);
            m_MovementSpeed = -1;
            m_MindState = -1;
            SetSynchDirty();
            return true;
        }

        return false;
    }
};

// vim:ft=enforce
