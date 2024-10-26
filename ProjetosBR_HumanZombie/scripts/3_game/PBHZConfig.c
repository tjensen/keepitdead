class PBHZConfig
{
	static const string MODCONFIG_ROOT_FOLDER = "$profile:ProjetoBRs/";
    static const string CONFIG_PATH = MODCONFIG_ROOT_FOLDER + "PBHZ_Settings.json";

	private ref array<string> ZombieClassName;
    //private ref array<string> ZombieSpawnParasiteClassName;
    private bool SpawnZombieOnPlayersDeath = true;
	private bool SpawnParasiteOnZombiesDeath = true;

	void PBHZConfig()
	{
		if (!GetGame().IsServer()) return;

		if (!FileExist(MODCONFIG_ROOT_FOLDER))
        {
            MakeDirectory(MODCONFIG_ROOT_FOLDER);
        }

        if (!FileExist(CONFIG_PATH))
        {
            Default();
            return;
        }

        Load();
    }

	bool Load()
    {
        if (FileExist(CONFIG_PATH))
        {
            JsonFileLoader<PBHZConfig>.JsonLoadFile(CONFIG_PATH, this);
            return true;
        }
        return false;
    }

	protected void Save()
    {
        JsonFileLoader<PBHZConfig>.JsonSaveFile(CONFIG_PATH, this);
    }

	protected void Default()
    {
		ZombieClassName = {"ZmbM_HumanZombie", "ZmbM_usSoldier_normal_Woodland", "ZmbM_usSoldier_normal_Desert","ZmbM_SoldierNormal"};
        SpawnZombieOnPlayersDeath = true;
        SpawnParasiteOnZombiesDeath = true;
        //ZombieSpawnParasiteClassName = {"ZmbM_HumanZombie", "ZmbM_usSoldier_normal_Woodland", "ZmbM_usSoldier_normal_Desert","ZmbM_SoldierNormal"};
		Save();
	}

	ref array<string> Get_ZombieClassName()
	{
		return ZombieClassName;
	}

    bool Get_SpawnZombieOnPlayersDeath()
	{
		return SpawnZombieOnPlayersDeath;
	}

	bool Get_SpawnParasiteOnZombiesDeath()
	{
		return SpawnParasiteOnZombiesDeath;
	}

    //ref array<string> Get_ZombieSpawnParasiteClassName()
	//{
	//	return ZombieSpawnParasiteClassName;
	//}

};
