#include "script_component.hpp"

/**
    Preload some heavy duty to have a better performance
*/

if (!is3den) exitWith {};

//--- Ammoboxes
private _ammoBoxes =  [];
{
    private _classHierarchy = [_x, true] call BIS_fnc_returnParents;
    //Get all classes with ReammoBox_F as a parent and take only public classes (available inside the editor)
    if (('ReammoBox_F' in _classHierarchy) isNotEqualTo true || (getNumber (_x >> "scope")) isNotEqualTo 2) then {
        continue;
    };

    _ammoBoxes pushBackUnique [
        getText (_x >> "displayName"),
        configName _x,
        getText (_x >> "editorPreview")
    ];
}
forEach ("true" configClasses (configFile >> "CfgVehicles"));

// sort alphabetically
_ammoBoxes sort true;

uiNamespace setVariable [QGVAR(ammoBoxes), _ammoBoxes];

// create an array for using inside a list
private _ammoBoxesComboOptionsLabels = [];
private _ammoBoxesComboOptionsValues = [];

{
    _ammoBoxesComboOptionsLabels pushBack (_x select 0);
    _ammoBoxesComboOptionsValues pushBack (_x select 1);
} forEach _ammoBoxes;

uiNamespace setVariable [QGVAR(ammoBoxesComboOptions), [_ammoBoxesComboOptionsValues, _ammoBoxesComboOptionsLabels]];