#include "script_component.hpp"
params [["_pos",[0,0,0],[[]],3], ["_unit",objNull,[objNull]]];

//create display 
if (!createDialog QGVAR(RscRespawnTickets)) exitWith {
	systemChat "Error opening dialog GVAR(RscRespawnTickets)";
};

//get display
private _display = uiNamespace getVariable QGVAR(RscRespawnTicketsDisplay);

//use ZENs method to init display posisions. I can use it as I should have same base setup as ZEN uses in their gui
[_display] call zen_common_fnc_initDisplayPositioning;

private _bluforTicketCount = missionNamespace getVariable QGVAR(BluforTicketCount);
private _opforTicketCount = missionNamespace getVariable QGVAR(OpforTicketCount);
private _indepTicketCount = missionNamespace getVariable QGVAR(IndepTicketCount);
private _civilianTicketCount = missionNamespace getVariable QGVAR(CivilianTicketCount);

{
	_x params ["_variableName", "_controlIDC"];
	private _ticketCount = missionNamespace getVariable _variableName;
	private _input = _display displayCtrl _controlIDC;

	if (isNil QUOTE(_ticketCount)) then {
		_input ctrlEnable false;
		_input ctrlSetText "Ignored";
		_input ctrlSetTooltip "This value is not used by the mission";
	}
	else {
		_input ctrlSetText (str _ticketCount);
	};
} forEach [
	[QGVAR(BluforTicketCount), IDC_RESPAWN_TICKETS_BLUFORINPUT],
	[QGVAR(OpforTicketCount), IDC_RESPAWN_TICKETS_OPFORINPUT],
	[QGVAR(IndepTicketCount), IDC_RESPAWN_TICKETS_INDEPINPUT],
	[QGVAR(CivilianTicketCount), IDC_RESPAWN_TICKETS_CIVINPUT]
];

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
	//Change the ticket count for the used variables
	{
		_x params ["_variableName", "_controlIDC"];
		private _ticketCount = missionNamespace getVariable _variableName;
		private _input = _display displayCtrl _controlIDC;

		if (!isNil QUOTE(_ticketCount)) then {
			missionNamespace setVariable [_variableName, parseNumber ctrlText _input, true];
		};
	} forEach [
		[QGVAR(BluforTicketCount), IDC_RESPAWN_TICKETS_BLUFORINPUT],
		[QGVAR(OpforTicketCount), IDC_RESPAWN_TICKETS_OPFORINPUT],
		[QGVAR(IndepTicketCount), IDC_RESPAWN_TICKETS_INDEPINPUT],
		[QGVAR(CivilianTicketCount), IDC_RESPAWN_TICKETS_CIVINPUT]
	];

	_display closeDisplay IDC_OK;
}];