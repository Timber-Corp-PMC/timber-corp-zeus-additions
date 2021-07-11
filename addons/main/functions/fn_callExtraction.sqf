#include "script_component.hpp"

params [["_pos",[0,0,0],[[]],3], ["_unit",objNull,[objNull]]];

private _extractionBase = missionNamespace getVariable QGVAR(extractionBase);
private _extractionVehicleClass = missionNamespace getVariable [QGVAR(extractionVehicleClass), "B_Heli_Transport_03_unarmed_F"];

if (!(if (isNil "_extractionBase") then {false} else {(_extractionBase) isEqualType objNull})) exitWith {
    [objNull, "No starting position found"] call BIS_fnc_showCuratorFeedbackMessage;
};

private _vehicle = createVehicle [_extractionVehicleClass, _extractionBase, [], 0, "FLY"];
createVehicleCrew _vehicle;
private _vehicleGroup = group _vehicle;


private _wp = _vehicleGroup addWaypoint [_pos, 0];
_wp setWaypointType "MOVE";
_wp setWaypointStatements ["true", "vehicle this land 'GET IN';"];

_vehicle addAction [
    format ["<t color='#26E600'>RTB</t>"],	// title
    {
        params ["_vehicle", "_caller", "_actionId", "_arguments"]; // script
        private _extractionBase = _arguments select 0;
        private _vehicleGroup = group _vehicle;

        _vehicle removeAction _actionId;

        private _wp = _vehicleGroup addWaypoint [getPos _extractionBase, 0];
        _wp setWaypointType "MOVE";
        _wp setWaypointStatements ["true", "vehicle this land 'LAND';"];
    },
    [
        _extractionBase
    ],		// arguments
    1.5,		// priority
    true,		// showWindow
    true,		// hideOnUse
    "",			// shortcut
    "true", 	// condition
    50,			// radius
    false,		// unconscious
    "",			// selection
    ""			// memoryPoint
];
