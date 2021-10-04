class ctrlMenu;
class Display3DEN {
    class ContextMenu : ctrlMenu {
        class Items {
            items[] += {QGVAR(SubContextMenu)};

            class GVAR(SubContextMenu) {
                text="Timber corp";
                items[] = {
                    QGVAR(CreateSupplyBox),
                    QGVAR(SwitchUnitSide)
                };
                picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
                value = 0;
            };

            class GVAR(CreateSupplyBox) {
                text="Create supply box";
                action="[] call timberZA_eden_fnc_createSupplyBox";
                conditionShow = "selected";
                opensNewWindow = 1;
            };

            class GVAR(SwitchUnitSide) {
                text="Switch unit side";
                action="[] call timberZA_eden_fnc_switchUnitSide";
                conditionShow = "selected";
                opensNewWindow = 1;
            };
        };
    };
};