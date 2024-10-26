modded class MissionServer
{
    private ref PBHZConfig m_PBHZConfig;

    void MissionServer()
    {
        GetRPCManager().AddRPC("PBHZConfig", "GetPBHZConfigCfg", this, SingeplayerExecutionType.Server);
    }

    override void OnInit()
    {
        super.OnInit();

        Print("[PBHZConfig] Server Cfg loading...");

        m_PBHZConfig = new PBHZConfig();
        g_Game.SetPBHZConfig( m_PBHZConfig );
    }

    void GetPBHZConfigCfg(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type == CallType.Server && sender != null) //Verify that sender is still around so we don't send a null RPC ( sending and RPC with null target will send it to all players in the session )
        {
            Print("[PBHZConfig] MissionServer --> Sending instance of cfg to client: " + sender.GetName());
            GetRPCManager().SendRPC("PBHZConfig", "PBHZConfigStoreConfig", new Param1<ref PBHZConfig>( m_PBHZConfig ), true, sender);
        }
    }
};

// vim:ft=enforce
