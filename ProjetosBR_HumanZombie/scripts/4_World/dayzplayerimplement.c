#ifdef SERVER
modded class DayZPlayerImplement
{
    private ZombieBase Keepitdead_zombie;

    override void EEKilled(Object killer)
    {
        super.EEKilled(killer);

        if (Keepitdead_zombie)
        {
            PrintFormat("Dead player %1 already spawned infected; skipping", this);
            return;
        }

        PrintFormat("Player %1 has died; spawning infected", this);

        vector zombieOffset = GetPosition() - "0.3 -0.3 0.3";

        Keepitdead_zombie = ZombieBase.Cast(
            GetGame().CreateObjectEx(
                "ZmbM_HumanZombie",
                zombieOffset,
                ECE_PLACE_ON_SURFACE | ECE_INITAI));

        Keepitdead_zombie.TransferAttachmentsFromZombie(this);
        Keepitdead_zombie.SetOrientation(GetOrientation());

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(Delete, 2500);
    }
};
#endif // SERVER

// vim:ft=enforce
