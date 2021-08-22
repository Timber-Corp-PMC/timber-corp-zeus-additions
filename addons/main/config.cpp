#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"zen_custom_modules", "A3_Modules_F", "A3_Modules_F_Curator", "3den"};
        author = CSTRING(Author);
        url = CSTRING(URL);
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
#include "ui.hpp"