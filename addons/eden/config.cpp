#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {
            "timberZA_main"
        };
        author = "Geelik";
        url = "https://github.com/Timber-Corp-PMC/timber-corp-zeus-additions";
        VERSION_CONFIG;
    };
};

class CfgFactionClasses
{
	class NO_CATEGORY;
	class GVAR(Cat): NO_CATEGORY
	{
		displayName = "Timber Corp ZA";
	};
};

class CfgFunctions
{
	#include "CfgFunctions.hpp"
};

#include "CfgEventHandlers.hpp"
#include "Display3DEN.hpp"