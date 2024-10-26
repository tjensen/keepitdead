/**
 * @file zombiemilitary.c
 * @author Morette [Bob Construtor] (https://dayzprojectbr.wixsite.com/projectbr)
 * @brief A simple script to generate a zombie.
 * @version 0.1
 * @date 2021-09-22
 *
 * @copyright ProjetoBR (c) 2021
 *
 */

modded class ZombieBase extends DayZInfected
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

    bool HandleDeath(int pCurrentCommandID)
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
class ZmbM_HumanZombie: ZmbM_SoldierNormal_Base{};

modded class DayZPlayerImplement
{
    override void EEKilled(Object killer)
    {
        super.EEKilled(killer);
        if (g_Game.GetPBHZConfig().Get_SpawnZombieOnPlayersDeath())
        {
            vector zombieOffset = GetPosition() - "0.3 -0.3 0.3";

            ZombieBase humanZ2;

            ref array<string> Hz_ZombieClass = g_Game.GetPBHZConfig().Get_ZombieClassName();
            humanZ2 = ZombieBase.Cast(GetGame().CreateObjectEx(Hz_ZombieClass.GetRandomElement(), zombieOffset, ECE_PLACE_ON_SURFACE | ECE_INITAI));

            humanZ2.TransferAttachmentsFromZombie(this);
            humanZ2.SetOrientation(GetOrientation());

            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Delete, 2500);
        }
    }
};

// vim:ft=enforce
