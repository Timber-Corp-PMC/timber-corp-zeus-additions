#include "script_component.hpp"
if (is3DEN) then {
    params ["_units", "_amountPerPlayer", "_onlyMan", "_onlyPlayable", "_includesMedical"];
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

    str [
        [
            [[], []],
            [_magazines, _magazinesAmount],
            [_items, _itemsAmmount],
            [[], []]
      ],
      false
    ];
}
else {
    str [
        [
            [[], []],
            [[], []],
            [[], []],
            [[], []]
        ],
        false
    ];
};

