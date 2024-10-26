modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();

        Print("[PBHZConfig] Server Cfg loading...");

        PBHZConfig config = new PBHZConfig();
        g_Game.SetPBHZConfig(config);
    }
};

// vim:ft=enforce
