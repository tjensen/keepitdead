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
