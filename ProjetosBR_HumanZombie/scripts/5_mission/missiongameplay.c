modded class MissionGameplay
{
    void MissionGameplay()
    {
        GetRPCManager().AddRPC("PBHZConfig", "PBHZConfigStoreConfig", this, SingeplayerExecutionType.Client); //Add this RPC as listner to the catch the cfg sent from server.
        GetRPCManager().SendRPC("PBHZConfig", "GetPBHZConfigCfg", null, true, null); //send RPC to server once this class starts to get cfg. Identity is null in this case becuase we are sending an RPC from client, clients can't target specific identities
    }

    void PBHZConfigStoreConfig(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        ref Param1<ref PBHZConfig> data;
        if (type == CallType.Client)
        {
            if (!ctx.Read(data)) return; //Return if failed to read data for somereason.

            g_Game.SetPBHZConfig( data.param1 );
            Print("[PBHZConfig] MissionGameplay --> Got instance of cfg: " + data.param1);
        }
    }
};
