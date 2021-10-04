#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "cba_main",
            "cba_xeh",
            "ace_common",
            "ace_medical",
            "zen_custom_modules",
            "A3_Modules_F",
            "A3_Modules_F_Curator",
            "3den"
        };
        author = "Geelik";
        url = "https://github.com/Timber-Corp-PMC/timber-corp-zeus-additions";
        VERSION_CONFIG;
    };
};

class CfgFunctions
{
	#include "CfgFunctions.hpp"
};