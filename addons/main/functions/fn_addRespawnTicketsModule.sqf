#include "script_component.hpp"
params [["_pos",[0,0,0],[[]],3], ["_unit",objNull,[objNull]]];

//create display 
if (!createDialog "timberZA_main_RscRespawnTickets") exitWith {
	systemChat "Error opening dialog timberZA_main_RscRespawnTickets";
};

//get display
private _display = uiNamespace getVariable QGVAR(RscRespawnTicketsDisplay);

//use ZENs method to init display posisions. I can use it as I should have same base setup as ZEN uses in their gui
[_display] call zen_common_fnc_initDisplayPositioning;

private _bluforTicketCount = missionNamespace getVariable [QGVAR(BluforTicketCount), -1];
private _opforTicketCount = missionNamespace getVariable [QGVAR(OpforTicketCount), -1];
private _indepTicketCount = missionNamespace getVariable [QGVAR(IndepTicketCount), -1];
private _civilianTicketCount = missionNamespace getVariable [QGVAR(CivilianforTicketCount), -1];

private _bluforInput = _display displayCtrl IDC_RESPAWN_TICKETS_BLUFOR_INPUT;
_bluforInput ctrlSetText (str _bluforTicketCount);

private _opforInput = _display displayCtrl IDC_RESPAWN_TICKETS_OPFOR_INPUT;
_opforInput ctrlSetText (str _opforTicketCount);

private _indepInput = _display displayCtrl IDC_RESPAWN_TICKETS_INDEP_INPUT;
_indepInput ctrlSetText (str _indepTicketCount);

private _civInput = _display displayCtrl IDC_RESPAWN_TICKETS_CIV_INPUT;
_civInput ctrlSetText (str _civilianTicketCount);

private _ctrlButtonCancel = _display displayCtrl IDC_CANCEL;
_ctrlButtonCancel ctrlAddEventHandler ["ButtonClick", {
    params ["_ctrlButtonCancel"];
    private _display = ctrlParent _ctrlButtonCancel;
    _display closeDisplay IDC_CANCEL;
}];

private _ctrlButtonOK = _display displayCtrl IDC_OK;
_ctrlButtonOK ctrlAddEventHandler ["ButtonClick", {
    params ["_ctrlButtonOK"];

    private _display = ctrlParent _ctrlButtonOK;

	private _bluforInput = _display displayCtrl IDC_RESPAWN_TICKETS_BLUFOR_INPUT;
	missionNamespace setVariable [QGVAR(BluforTicketCount), parseNumber ctrlText _bluforInput];

	private _opforInput = _display displayCtrl IDC_RESPAWN_TICKETS_OPFOR_INPUT;
	missionNamespace setVariable [QGVAR(OpforTicketCount), parseNumber ctrlText _opforInput];

	private _indepInput = _display displayCtrl IDC_RESPAWN_TICKETS_INDEP_INPUT;
	missionNamespace setVariable [QGVAR(IndepTicketCount), parseNumber ctrlText _indepInput];

	private _civInput = _display displayCtrl IDC_RESPAWN_TICKETS_CIV_INPUT;
	missionNamespace setVariable [QGVAR(CivilianforTicketCount), parseNumber ctrlText _civInput];

	_display closeDisplay IDC_OK;
}];