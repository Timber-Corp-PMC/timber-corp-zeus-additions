#include "script_component.hpp"
if (is3DEN) then {

    private _onConfirm = {
        params ["_dialogResult", "_arguments"];

        //Get parameter from dialog inputs and arguments passed
        _dialogResult params ["_choosenSide"];
        _arguments params ["_units"];

        private _dummyUnitClassName = "";

        switch (_choosenSide) do {
            case blufor: {
                _dummyUnitClassName = "B_Soldier_A_F";
            };
            case opfor: {
                _dummyUnitClassName = "O_Soldier_A_F";
            };
            case independent: {
                _dummyUnitClassName = "I_Soldier_A_F";
            };
            case civilian: {
                _dummyUnitClassName = "C_man_polo_1_F";
            };
        };

        if (_dummyUnitClassName isEqualTo "") exitWith {
            ["This faction is not supported", 1, 2, false] call BIS_fnc_3DENNotification;
        };

        private _dummyUnit = create3DENEntity ["Object", _dummyUnitClassName, getPos (_units select 0)];
        add3DENConnection ["Group", _units, group _dummyUnit];
        delete3DENEntities [_dummyUnit];

        ["Units side switched", 0, 2, false] call BIS_fnc_3DENNotification;
    };

    private _selectedObjects = get3DENSelected "object";

    [
        "Switch unit side",
        [
            [
                "SIDES",
                "Side",
                blufor,
                true
            ]
        ],
        _onConfirm,
        {},
        [
            _selectedObjects
        ]
    ] call EFUNC(main,createDisplay);
};