#include "\a3\ui_f\hpp\defineCommonGrids.inc"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
#include "\a3\ui_f_curator\ui\defineResinclDesign.inc"
#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"zen_custom_modules", "A3_Modules_F", "A3_Modules_F_Curator"};
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
	#include "cfgFunctions.hpp"
};

#include "ui.hpp"