class CfgMods
{
    class ProjetosBR_HumanZombie
    {
        dir="ProjetosBR_HumanZombie";
        picture="";
        action="";
        hideName=1;
        hidePicture=1;
        name="ProjetosBR_HumanZombie";
        credits="";
        author="Morette";
        authorID="0";
        version="1.0";
        extra=0;
        type="mod";
        dependencies[]=
        {
            "Game",
            "World",
            "Mission"
        };
        class defs
        {
            class gameScriptModule
            {
                value="";
                files[]=
                {
                    "ProjetosBR_HumanZombie/scripts/3_Game"
                };
            };
            class worldScriptModule
            {
                value="";
                files[]=
                {
                    "ProjetosBR_HumanZombie/scripts/4_World"
                };
            };
            class missionScriptModule
            {
                value="";
                files[]=
                {
                    "ProjetosBR_HumanZombie/scripts/5_Mission"
                };
            };
        };
    };
};
class CfgPatches
{
    class ProjetosBR_HumanZombie
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "DZ_Characters",
            "DZ_Characters_Zombies",
            "DZ_Characters_Backpacks",
            "DZ_Characters_Pants",
            "DZ_Characters_Tops",
            "DZ_Gear_Containers",
            "DZ_Characters_Headgear",
            "DZ_Gear_Camping",
            "DZ_Gear_Crafting",
            "DZ_Gear_Cooking",
            "DZ_Gear_Tools",
            "DZ_Animals",
            "DZ_Data",
            "DZ_Characters_Shoes",
            "DZ_Characters_Gloves"
        };
    };
};
class cfgWeapons
{
    class RifleCore;
    class Rifle_Base: RifleCore
    {
        inventorySlot[]=
        {
            "Shoulder",
            "Melee",
            "Shoulder1",
            "Shoulder2",
            "Shoulder3",
            "Shoulder4",
            "Shoulder5",
            "Shoulder6",
            "Shoulder7",
            "Shoulder8",
            "Shoulder9",
            "Shoulder10",
            "Shoulder11",
            "Shoulder12",
            "Shoulder13",
            "Shoulder14",
            "Shoulder15",
            "Shoulder16",
            "Shoulder17",
            "Shoulder18",
            "Shoulder19",
            "Shoulder20",
            "Shoulder21",
            "Shoulder22",
            "Shoulder23",
            "Shoulder24",
            "Shoulder25",
            "Shoulder26",
            "Shoulder27",
            "Shoulder28",
            "Shoulder29",
            "Shoulder30"
        };
    };
};
class CfgSlots
{
    class Slot_Shoulder
    {
    };
    class Slot_Shoulder1: Slot_Shoulder
    {
        name="Shoulder1";
    };
};
class CfgVehicles
{
    class DZ_LightAI;
    class DayZInfected: DZ_LightAI
    {
    };
    class ZombieBase: DayZInfected
    {
        class Cargo
        {
            itemsCargoSize[]={10,5};
            allowOwnedCargoManipulation=1;
            openable=0;
        };
        attachments[]=
        {
            "Shoulder1",
            "Melee",
            "Vest",
            "Body",
            "Hips",
            "Legs",
            "Back",
            "Headgear",
            "Mask",
            "Eyewear",
            "Gloves",
            "Feet",
            "Armband"
        };
        class InventoryEquipment
        {
            playerSlots[]=
            {
                "Slot_Shoulder1",
                "Slot_Melee",
                "Slot_Vest",
                "Slot_Body",
                "Slot_Hips",
                "Slot_Legs",
                "Slot_Back",
                "Slot_Headgear",
                "Slot_Mask",
                "Slot_Eyewear",
                "Slot_Gloves",
                "Slot_Feet",
                "Slot_Armband"
            };
        };
    };
    class ZmbM_SoldierNormal_Base;
    class ZmbM_HumanZombie: ZmbM_SoldierNormal_Base
    {
        scope=2;
        model="ProjetosBR_HumanZombie\Models\HumamZombie\HumamZombie.p3d";
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=600;
                    healthLevels[]=
                    {
                        
                        {
                            1.01,
                            {}
                        },
                        
                        {
                            0.69999999,
                            {}
                        },
                        
                        {
                            0.5,
                            {}
                        },
                        
                        {
                            0.30000001,
                            {}
                        },
                        
                        {
                            0.0099999998,
                            {}
                        }
                    };
                };
            };
            class DamageZones
            {
                class Head
                {
                    class Health
                    {
                        hitpoints=200;
                        transferToGlobalCoef=1;
                    };
                    class ArmorType
                    {
                        class Projectile
                        {
                            class Health
                            {
                                damage=1.5;
                            };
                        };
                        class Melee
                        {
                            class Health
                            {
                                damage=0.69999999;
                            };
                        };
                        class FragGrenade
                        {
                            class Health
                            {
                                damage=3;
                            };
                        };
                    };
                    componentNames[]=
                    {
                        "Head",
                        "Neck"
                    };
                    fatalInjuryCoef=0.1;
                    inventorySlots[]=
                    {
                        "Headgear",
                        "Mask"
                    };
                };
                class Torso
                {
                    class Health
                    {
                        hitpoints=400;
                        transferToGlobalCoef=1;
                    };
                    class ArmorType
                    {
                        class Melee
                        {
                            class Health
                            {
                                damage=1.2;
                            };
                        };
                        class FragGrenade
                        {
                            class Health
                            {
                                damage=2;
                            };
                        };
                    };
                    componentNames[]=
                    {
                        "Spine1",
                        "Spine3"
                    };
                    fatalInjuryCoef=-1;
                    inventorySlots[]=
                    {
                        "Vest",
                        "Body",
                        "Back"
                    };
                    inventorySlotsCoefs[]={1,1,1};
                };
                class LeftArm: Torso
                {
                    componentNames[]=
                    {
                        "LeftArm",
                        "LeftForeArm"
                    };
                    inventorySlots[]=
                    {
                        "Vest",
                        "Body",
                        "Back"
                    };
                    inventorySlotsCoefs[]={1,1,1};
                    fatalInjuryCoef=-1;
                };
                class RightArm: LeftArm
                {
                    componentNames[]=
                    {
                        "RightArm",
                        "RightForeArm"
                    };
                    inventorySlots[]=
                    {
                        "Vest",
                        "Body",
                        "Back"
                    };
                    inventorySlotsCoefs[]={1,1,1};
                    fatalInjuryCoef=-1;
                };
                class LeftLeg
                {
                    class Health
                    {
                        hitpoints=400;
                        transferToGlobalCoef=0.33000001;
                    };
                    class ArmorType
                    {
                        class FragGrenade
                        {
                            class Health
                            {
                                damage=2;
                            };
                        };
                    };
                    componentNames[]=
                    {
                        "LeftLeg",
                        "LeftUpLeg"
                    };
                    fatalInjuryCoef=-1;
                    inventorySlots[]=
                    {
                        "Legs"
                    };
                };
                class RightLeg: LeftLeg
                {
                    componentNames[]=
                    {
                        "RightLeg",
                        "RightUpLeg"
                    };
                    fatalInjuryCoef=-1;
                    inventorySlots[]=
                    {
                        "Legs"
                    };
                };
                class LeftFoot
                {
                    class Health
                    {
                        hitpoints=400;
                        transferToGlobalCoef=0.1;
                    };
                    class ArmorType
                    {
                        class FragGrenade
                        {
                            class Health
                            {
                                damage=2;
                            };
                        };
                    };
                    transferToZonesNames[]=
                    {
                        "LeftLeg"
                    };
                    transferToZonesCoefs[]={0.1};
                    componentNames[]=
                    {
                        "LeftFoot"
                    };
                    fatalInjuryCoef=-1;
                    inventorySlots[]=
                    {
                        "Feet"
                    };
                };
                class RightFoot: LeftFoot
                {
                    transferToZonesNames[]=
                    {
                        "RightLeg"
                    };
                    transferToZonesCoefs[]={0.1};
                    componentNames[]=
                    {
                        "RightFoot"
                    };
                    fatalInjuryCoef=-1;
                    inventorySlots[]=
                    {
                        "Feet"
                    };
                };
            };
        };
    };
};
