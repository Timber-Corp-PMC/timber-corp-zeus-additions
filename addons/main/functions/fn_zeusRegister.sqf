#include "script_component.hpp"

//only load for zeus
if (!hasInterface) exitWith {};

private _hasZen = isClass (configFile >> "CfgPatches" >> "zen_custom_modules");
if !(_hasZen) exitWith
{
    diag_log Format ["******CBA and/or ZEN not detected. They are required for timberZA"];
};

//spawn script to register zen modules
private _wait = [player] spawn
{
    params ["_unit"];
    private _timeout = 0;
    waitUntil  {
        if (_timeout >= 10) exitWith  {
            diag_log "timberZA:fn_zeusRegister: Timed out!!!";
            true;
        };
        sleep 1;
        _timeout = _timeout + 1;
        if (count allCurators == 0 || {!isNull (getAssignedCuratorLogic _unit)}) exitWith {true};
        false;
    };

    private _moduleList = [];

    //Add the editRespawnTicketModule only if we detect it's used
    private _respawnSystemUsed = [] call {
        private _bluforTicketCount = missionNamespace getVariable QGVAR(BluforTicketCount);
        private _opforTicketCount = missionNamespace getVariable QGVAR(OpforTicketCount);
        private _indepTicketCount = missionNamespace getVariable QGVAR(IndepTicketCount);
        private _civilianTicketCount = missionNamespace getVariable QGVAR(CivilianTicketCount);

        private _respawnSystemUsed = (
            !isNil QUOTE(_bluforTicketCount)
            || !isNil QUOTE(_opforTicketCount)
            || !isNil QUOTE(_indepTicketCount)
            || !isNil QUOTE(_civilianTicketCount)
        );
        _respawnSystemUsed;
    };

    if (_respawnSystemUsed) then {
        _moduleList pushBack ["Edit respawn tickets", {_this call timberZA_main_fnc_editRespawnTicketsModule}, "\a3\modules_f\data\portraitmodule_ca.paa"];
    };

    //registering ZEN custom modules
    {
        private _reg =
        [
            "Timber Corp ZA",
            (_x select 0),
            (_x select 1),
            (_x select 2)
        ] call zen_custom_modules_fnc_register;
    } forEach _moduleList;

	//@todo getClassname

	private _contextActionList = [
	    //AttachTo action
	    [
	        [QGVAR(AttachTo), "Attach To", "\a3\modules_f\data\portraitmodule_ca.paa", {[_hoveredEntity] call timberZA_main_fnc_attachTo}, {!isNull _hoveredEntity}] call zen_context_menu_fnc_createAction,
            [],
	        0
	    ]
    ];

    //register context actions
    {
        private _reg = [
            //action, parent path, priority
            (_x select 0), (_x select 1), (_x select 2)
        ] call zen_context_menu_fnc_addAction;
    } forEach _contextActionList;
	 
};

diag_log format ["timberZA:fn_zeusRegister: Zeus initialization complete. Zeus Enhanced Detected: %1", _hasZen];
