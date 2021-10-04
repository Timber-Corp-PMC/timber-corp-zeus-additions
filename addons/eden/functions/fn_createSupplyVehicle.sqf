#include "script_component.hpp"
if (is3DEN) then {

    private _onConfirm = {
        params ["_dialogResult", "_arguments"];

        //Get parameter from dialog inputs and arguments passed
        _dialogResult params ["_amountPerPlayer", "_onlyMan", "_onlyPlayable", "_includesMedical", "_vehicleType"];
        _arguments params ["_units"];

        private _ammoBox = [_units, _amountPerPlayer, _onlyMan, _onlyPlayable, _includesMedical] call FUNC(getAmmoBoxFromUnits);

        // spawn container
        private _container = create3DENEntity  ["Object", _vehicleType, screenToWorld [0.5,0.5], true];
        _container set3DENAttribute ["ammoBox", _ammoBox];

        do3DENAction "MissionSave";
        ["Vehicle placed", 0, 2, false] call BIS_fnc_3DENNotification;
    };

    private _vehiclesComboOptions = uiNamespace getVariable [QGVAR(vehiclesComboOptions), []];

    if (count _vehiclesComboOptions isEqualTo 0) exitWith {
        ["No vehicles found", 1, 2, false] call BIS_fnc_3DENNotification;
    };

    [
        "Magazine count per player",
        [
            [
                "SLIDER",
                ["Ammount per unit", "The result will be => selected units count * magazine count per player"],
                [1,50,5,0], //1 to 50, default 5 and showing 0 decimal
                true
            ],
            [
                "CHECKBOX",
                ["Only units", "Take only units into account"],
                [true],
                true
            ],
            [
                "CHECKBOX",
                ["Only playable", "Take only playable units into account"],
                [true],
                true
            ],
            [
                "CHECKBOX",
                ["Includes medicals", "Add medicals items too"],
                [true],
                true
            ],
            [
                "COMBO",
                ["Vehicle type", "Name of the vehicle used"],
                [
                    _vehiclesComboOptions select 0,
                    _vehiclesComboOptions select 1,
                    0
                ],
                true
            ]
        ],
        _onConfirm,
        {},
        [
            get3DENSelected "object"
        ]
    ] call EFUNC(main,createDisplay);
};