class CfgPatches {
  class AGM_Overheat {
    units[] = {};
    weapons[] = {};
    requiredVersion = 0.60;
    requiredAddons[] = {A3_Weapons_F, Extended_EventHandlers, AGM_Core};
    version = 1.0;
    author[] = {"commy2", "KoffeinFlummi"};
    authorUrl = "https://github.com/commy2/";
  };
};

class CfgFunctions {
  class AGM_Overheat {
    class AGM_Overheat {
        file = "\AGM_overheat\functions";
      class firedEH {};
    };
  };
};

class Extended_PostInit_EventHandlers {
  class AGM_Overheat {
    clientInit = "execVM '\AGM_overheat\init.sqf'";
  };
};

class Extended_Init_EventHandlers {
  class CAManBase {
    class AGM_giveSpareBarrel {
      Init = "_this spawn {sleep 0.1; if (getNumber (configFile >> 'CfgWeapons' >> currentWeapon player >> 'AGM_Overheat_allowSwapBarrel') == 1) then {(_this select 0) addItem 'AGM_SpareBarrel'}}"; 
    };
  };
};

class Extended_Fired_EventHandlers {
  class CAManBase {
    class AGM_Overheat {
      clientFired = "if (player == (_this select 0)) then {_this call AGM_Overheat_fnc_firedEH}";
    };
  };
};

class CfgVehicles {
  class Man;

  class CAManBase: Man {
    class AGM_SelfActions {
      class AGM_SwapBarrel {
        displayName = "$STR_AGM_SwapBarrel";
        condition = "'AGM_SpareBarrel' in items player && {getNumber (configFile >> 'CfgWeapons' >> currentWeapon player >> 'AGM_Overheat_allowSwapBarrel') == 1}";
        statement = "[currentWeapon player] call AGM_Overheat_swapBarrel";
        showDisabled = 0;
        priority = 4;
      };
    };
  };
};

class CfgWeapons {
  class ItemCore;
  class InventoryItem_Base_F;

  class AGM_SpareBarrel: ItemCore {
    displayname = "$STR_AGM_SpareBarrelName";
    descriptionshort = "$STR_AGM_SpareBarrelDescription";
    //model = "";
    picture = "\AGM_Overheat\UI\spare_barrel_ca.paa";
    scope = 2;
    class ItemInfo: InventoryItem_Base_F {
      mass = 10;
      type = 201;
    };
  };

  class Rifle_Base_F;
  class Rifle_Long_Base_F;

  class arifle_MX_Base_F : Rifle_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class arifle_MX_SW_F : arifle_MX_Base_F {
    AGM_Overheat_Increment = 0.01;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class arifle_Katiba_Base_F : Rifle_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class mk20_base_F : Rifle_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class Tavor_base_F : Rifle_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class SDAR_base_F : Rifle_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class EBR_base_F : Rifle_Long_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class DMR_01_base_F : Rifle_Long_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class GM6_base_F : Rifle_Long_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class LRR_base_F : Rifle_Long_Base_F {
    AGM_Overheat_Increment = 0.012;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.001;
  };

  class LMG_Mk200_F : Rifle_Long_Base_F {
    AGM_Overheat_allowSwapBarrel = 1;
    AGM_Overheat_Increment = 0.01;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.002;
  };

  /*class LMG_RCWS : MGun {
  };*/

  class LMG_Zafir_F : Rifle_Long_Base_F {
    AGM_Overheat_allowSwapBarrel = 1;
    AGM_Overheat_Increment = 0.01;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.002;
  };

  class SMG_01_Base : Rifle_Base_F {
    AGM_Overheat_Increment = 0.015;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.004;
  };

  class SMG_02_base_F : Rifle_Base_F {
    AGM_Overheat_Increment = 0.015;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.004;
  };

  class pdw2000_base_F : Rifle_Base_F {
    AGM_Overheat_Increment = 0.015;
    AGM_Overheat_Cooldown = 0.002;
    AGM_Overheat_Dispersion = 0.004;
  };
};
