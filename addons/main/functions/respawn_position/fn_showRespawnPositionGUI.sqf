#include "script_component.hpp"

params [["_args", []], ["_onOk", {}]];

//create display
if (!createDialog "timberZA_main_RscRespawnPosition") exitWith {
	systemChat "Error opening dialog timberZA_main_RscRespawnPosition";
};

//Register an handler to call the onOk callback;
[
    QGVAR(RscRespawnPositionDisplayEvent),
    {
        params ["_name", "_side"];
        _thisArgs params ["_args", "_onOk"];
        [_thisType, _thisId] call CBA_fnc_removeEventHandler;
        [_name, _side] + _args call _onOk;
    },
    [_args, _onOk]
] call CBA_fnc_addEventHandlerArgs;

//get display
private _display = uiNamespace getVariable QGVAR(RscRespawnPositionDisplay);
[_display] call zen_common_fnc_initDisplayPositioning;

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

    //get name
    private _nameInput = _display displayCtrl IDC_RESPAWN_POSITION_NAME;
    private _name = ctrlText _nameInput;

    //Get selected side
    private _sideInput = _display displayCtrl IDC_RESPAWN_POSITION_SIDE;
    private _selectedSide = lbCurSel _sideInput;
    private _sideId = _sideInput lbValue _selectedSide;
    private _side = _sideId call BIS_fnc_sideType;

    //trigger the event with GUI values
    [QGVAR(RscRespawnPositionDisplayEvent), [_name, _side]] call CBA_fnc_localEvent;

	_display closeDisplay IDC_OK;
}];