modded class DayZGame
{
    private ref PBHZConfig m_PBHZConfig;

    PBHZConfig GetPBHZConfig()
    {
        if (m_PBHZConfig)
        {
            return m_PBHZConfig;
        }

        Print("[PBHZConfig] DayZGame --> Cannot Locate PBHZConfig Config File...");
        return null;
    }

    void SetPBHZConfig(PBHZConfig cfg)
    {
        m_PBHZConfig = cfg;
    }
};

// vim:ft=enforce
