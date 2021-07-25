#include "script_component.hpp"
params [["_pos",[0,0,0],[[]],3], ["_unit",objNull,[objNull]]];


private _curatorModule = getAssignedCuratorLogic player;
if (isNull _curatorModule) exitWith {
    systemChat "Curator modulee not found";
};

//add handler to all curators to allow moving respawn position
private _respawnPositionMoveHandler = missionNamespace getVariable [QGVAR(RespawnPositionMoveHandler), false];
if (_respawnPositionMoveHandler isEqualTo false) then {
    {
        _x addEventHandler ["CuratorObjectEdited", {
            params ["_curator", "_entity"];

            private _respawnPosition = _entity getVariable QGVAR(RespawnPosition);

            if (typeOf _entity == "Logic" && !isNil "_respawnPosition") then {
                //Delete old position
                (_respawnPosition select 0) call BIS_fnc_removeRespawnPosition;

                // Create respawn position
                private _pos = getPos _entity;
                private _side = _respawnPosition select 1;
                private _name = _respawnPosition select 2;
                private _newRespawnPosition = [_side, [_pos select 0, _pos select 1, 0], _name] call BIS_fnc_addRespawnPosition;

                //Store respawn position
                _entity setVariable [QGVAR(RespawnPosition), [
                    _newRespawnPosition,
                    _side,
                    _name
                ], true];
            };
        }];
    } forEach allCurators;

     missionNamespace setVariable [QGVAR(RespawnPositionMoveHandler), true, true];
};

//Show respawn position GUI
[
    [
        _pos
    ],
    {
        params ["_name", "_side", "_pos"];

        //Create the lgoic whose gonna hold the respawn position
        private _logicCenter = createCenter sideLogic;
        private _logicGroup = createGroup _logicCenter;
        private _logic = _logicGroup createUnit ["Logic", [_pos select 0, _pos select 1, 0], [], 0, "NONE"];
        _logic setName (str _side) + " respawn : " + _name;

        //Add the logic to all curator
        {
            _x addCuratorEditableObjects [[_logic]];
        } forEach allCurators;

        // Create respawn position
        private _respawnPosition = [_side, [_pos select 0, _pos select 1, 0], _name] call BIS_fnc_addRespawnPosition;

       //Store respawn position
        _logic setVariable [QGVAR(RespawnPosition), [
            _respawnPosition,
            _side,
            _name
        ], true];
    }
] call timberZA_main_fnc_showRespawnPositionGUI;