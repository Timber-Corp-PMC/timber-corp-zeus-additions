#include "script_component.hpp"
if (is3DEN) then {

    private _onConfirm = {
        params ["_dialogResult", "_arguments"];

        //Get parameter from dialog inputs and arguments passed
        _dialogResult params ["_amountPerPlayer", "_onlyMan", "_onlyPlayable", "_includesMedical", "_boxType"];
        _arguments params ["_units"];

        private _magazineList = [];
        private _itemsList = [];
        private _unitCount = 0;

        //Function do filter out units
        private _filter = {
            params ["_unit", "_onlyMan", "_onlyPlayable"];

            if (_onlyMan && ((_unit isKindOf "Man") isEqualTo false)) then {
                breakWith false;
            };

            if (_onlyPlayable && (((_unit get3DENAttribute "ControlMP") select 0) isEqualTo false)) then {
                breakWith false;
            };

            true;
        };

        private _itemsBlackList = ["Medikit", "FirstAidKit"];

        // run though all selected units
        {
            if ([_x, _onlyMan, _onlyPlayable] call _filter) then {
                private _allItems = itemsWithMagazines _x;

                {
                    if (_x in _itemsBlackList) then {
                        continue;
                    };

                    if (isClass (configfile >> "CfgMagazines" >> _x)) then {
                        _magazineList pushBackUnique _x;
                        continue;
                    };

                    if (_includesMedical) then {
                        private _addons = configSourceAddonList (configFile >> "CfgWeapons" >> _x);
                        if ("ace_medical_treatment" in _addons) then {
                            _itemsList pushBackUnique _x;
                            continue;
                        };
                    };

                } forEach _allItems;

                // increment players, could get it from playercount, but we are here anyway and can sort zeus out this way
                _unitCount = _unitCount + 1;
            };

        } forEach _units;

        if (_unitCount isEqualTo 0) exitWith {
            ["No selected unit meets the requirements", 1, 2, false] call BIS_fnc_3DENNotification;
        };

        // got all mags, now get rid of duplicates
        private _magazineList = _magazineList arrayIntersect _magazineList;

        // add amount
        private _addAmount = _unitCount * (round _amountPerPlayer);

        // spawn container
        private _container = create3DENEntity  ["Object", _boxType, screenToWorld [0.5,0.5], true];
        private _magazines = [];
        private _magazinesAmount = [];
        private _items = [];
        private _itemsAmmount = [];

        {
            _magazines pushBack _x;
            _magazinesAmount pushBack _addAmount;
        } forEach _magazineList;

        {
            _items pushBack _x;
            _itemsAmmount pushBack _addAmount;
        } forEach _itemsList;

        private _value = str
        [
          [
            [[], []],
            [_magazines, _magazinesAmount],
            [_items, _itemsAmmount],
            [[], []]
          ],
          false
        ];
        _container set3DENAttribute ["ammoBox", _value];
        do3DENAction "MissionSave";
        ["Supply crate placed", 0, 2, false] call BIS_fnc_3DENNotification;
    };

    private _ammoBoxesComboOptions = uiNamespace getVariable [QGVAR(ammoBoxesComboOptions), []];

    if (count _ammoBoxesComboOptions isEqualTo 0) exitWith {
        ["No ammo box found", 1, 2, false] call BIS_fnc_3DENNotification;
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
                ["Box type", "Name of the box used"],
                [
                    _ammoBoxesComboOptions select 0,
                    _ammoBoxesComboOptions select 1,
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