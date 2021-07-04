#include "script_component.hpp"

private _hasZen = isClass (configFile >> "CfgPatches" >> "zen_custom_modules");
if !(_hasZen) exitWith
{
	diag_log Format ["******CBA and/or ZEN not detected. They are required for timberZA"];
};

//only load for zeus
if (!hasInterface) exitWith {};

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

	private _moduleList = [
		["Add respawn tickets", {_this call timberZA_main_fnc_addRespawnTicketsModule}, "\a3\modules_f\data\portraitmodule_ca.paa"]
	];

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
	 
};

diag_log format ["timberZA:fn_zeusRegister: Zeus initialization complete. Zeus Enhanced Detected: %1", _hasZen];