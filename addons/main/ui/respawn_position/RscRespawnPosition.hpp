class GVAR(RscRespawnPosition)
{
    idd = -1;
    onLoad = "uiNamespace setVariable ['timberZA_main_RscRespawnPositionDisplay', _this select 0];";
    movingEnable = 1;

    class controls {
        class Title: RscText {
            idc = IDC_TITLE;
            h = POS_H(1);
            w = POS_W(20);
            x = POS_X(6.5);
            y = POS_Y(0);
            colorBackground[] = GUI_THEME_COLOR;
            moving = 1;
            text = "Add respawn position";
        };

        class Background: RscText {
            idc = IDC_BACKGROUND;
            h = POS_H(10);
            w = POS_W(20);
            x = POS_X(6.5);
            y = POS_Y(0);
            colorBackground[] = {0, 0, 0, 0.7};
        };

        class Content: RscControlsGroupNoScrollbars {
            idc = IDC_CONTENT;
            h = POS_H(10);
            w = POS_W(20);
            x = POS_X(6.5);
            y = POS_Y(0);

            class controls {

                class SideInput: RscCombo {
                    idc = IDC_RESPAWN_POSITION_SIDE;
                    h = POS_H(1);
                    w = POS_W(5);
                    x = POS_X(13);
                    y = POS_Y(0);
                    class ComboScrollBar;

                    class Items {
                        class BLUFOR {
                            text = "BLUFOR";
                            value = 1;
                            default = 1;
                        };
                        class OPFOR {
                            text = "OPFOR";
                            value = 0;
                        };
                        class Independent {
                            text = "Independent";
                            value = 2;
                        };
                        class Civilian {
                            text = "Civilian";
                            value = 3;
                        };
                    };
                };

                class NameInput: RscEdit
                {
                    idc = IDC_RESPAWN_POSITION_NAME;
                    h = POS_H(1);
                    w = POS_W(5);
                    x = POS_X(13);
                    y = POS_Y(2);
                };

                class SideLabel: RscText
                {
                    idc = IDC_RESPAWN_POSITION_SIDE_LABEL;
                    h = POS_H(1);
                    w = POS_W(9);
                    x = POS_X(6.5);
                    y = POS_Y(0);
                    text = "Side"; //--- ToDo: Localize;
                };

                class NameLabel: RscText
                {
                    idc = IDC_RESPAWN_POSITION_NAME_LABEL;
                    h = POS_H(1);
                    w = POS_W(9);
                    x = POS_X(6.5);
                    y = POS_Y(2);
                    text = "Name"; //--- ToDo: Localize;
                };
            };
        };
        class ButtonOK: RscButtonMenuOK {
            idc = IDC_OK;
            h = POS_H(1);
            w = POS_W(5);
            x = POS_X(21.5);
            y = POS_Y(6);
        };
        class ButtonCancel: RscButtonMenuCancel {
            idc = IDC_CANCEL;
            h = POS_H(1);
            w = POS_W(5);
            x = POS_X(6.5);
            y = POS_Y(6);
        };
    };
};


