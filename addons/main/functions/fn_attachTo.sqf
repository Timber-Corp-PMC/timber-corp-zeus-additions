/*
	author: Geelik
	description: none
	returns: nothing
*/

params ["_object"];

// Detach object if currently attached
if (!isNull attachedTo _object) exitWith {
    detach _object;
    [objNull, "Object detached"] call BIS_fnc_showCuratorFeedbackMessage;
};

// Get object to attach to
[_object, {
    params ["_successful", "_object"];

    if (!_successful) exitWith {};

    curatorMouseOver params ["_type", "_entity"];
    if (_type != "OBJECT") exitWith {};

    if (_object == _entity) exitWith {
        [objNull, "Cannot attach object to itself"] call BIS_fnc_showCuratorFeedbackMessage;
    };

    private _direction = getDir _object - getDir _entity;

    _object attachTo [_entity];
    ["zen_common_setDir", [_object, _direction], _object] call CBA_fnc_targetEvent;

    [objNull, "Object attached"] call BIS_fnc_showCuratorFeedbackMessage;
}, [], "Attach To"] call zen_common_fnc_selectPosition;