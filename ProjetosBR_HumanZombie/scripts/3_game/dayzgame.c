modded class DayZGame
{
    private ref PBHZConfig m_PBHZConfig;

    ref PBHZConfig GetPBHZConfig()
    {
        if (m_PBHZConfig)
        {
            return m_PBHZConfig;
        }

        Print("[PBHZConfig] DayZGame --> Cannot Locate PBHZConfig Config File...");
	    return null;
    }

    void SetPBHZConfig(ref PBHZConfig cfg)
	{
		m_PBHZConfig = cfg;
	}
}