class ctrlMenu;
class Display3DEN {
    class ContextMenu : ctrlMenu {
        class Items {
            items[] += {"TCZA_SubContextMenu"};

            class TCZA_SubContextMenu {
                text="Timber corp";
                items[] = {"TCZA_CreateSupplyBox"};
                picture = "\a3\3DEN\Data\Displays\Display3DEN\ToolBar\open_ca.paa";
                value = 0;
            };

            class TCZA_CreateSupplyBox {
                text="Create supply box";
                action="['execute'] call timberZA_main_fnc_createSupplyBox";
                conditionShow = "selected";
                opensNewWindow = 1;
            };
        };
    };
};