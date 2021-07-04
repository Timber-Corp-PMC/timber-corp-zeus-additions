class GVAR(RscRespawnTickets)
{
	idd = -1;
	onLoad = "uiNamespace setVariable ['timberZA_main_RscRespawnTicketsDisplay',_this select 0];";
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
            text = "Edit respawn tickets";
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

				class BluforInput: RscEdit
				{
					idc = IDC_RESPAWN_TICKETS_BLUFORINPUT;
					h = POS_H(1);
					w = POS_W(3);
					x = POS_X(13);
					y = POS_Y(0);
				};
				class OpforInput: RscEdit
				{
					idc = IDC_RESPAWN_TICKETS_OPFORINPUT;
					h = POS_H(1);
					w = POS_W(3);
					x = POS_X(13);
					y = POS_Y(2);
				};
				class IndepInput: RscEdit
				{
					idc = IDC_RESPAWN_TICKETS_INDEPINPUT;
					h = POS_H(1);
					w = POS_W(3);
					x = POS_X(13);
					y = POS_Y(4);
				};
				class CivInput: RscEdit
				{
					idc = IDC_RESPAWN_TICKETS_CIVINPUT;
					h = POS_H(1);
					w = POS_W(3);
					x = POS_X(13);
					y = POS_Y(6);
				};
				class BluforLabel: RscText
				{
					idc = IDC_RESPAWN_TICKETS_BLUFORLABEL;
					h = POS_H(1);
					w = POS_W(9);
					x = POS_X(6.5);
					y = POS_Y(0);
					text = "BLUFOR tickets"; //--- ToDo: Localize;
				};
				class OpforLabel: RscText
				{
					idc = IDC_RESPAWN_TICKETS_OPFORLABEL;
					h = POS_H(1);
					w = POS_W(9);
					x = POS_X(6.5);
					y = POS_Y(2);
					text = "OPFOR tickets"; //--- ToDo: Localize;
				};
				class IndepLabel: RscText
				{
					idc = IDC_RESPAWN_TICKETS_INDEPLABEL;
					h = POS_H(1);
					w = POS_W(9);
					x = POS_X(6.5);
					y = POS_Y(4);
					text = "INDEP tickets"; //--- ToDo: Localize;
				};
				class CivLabel: RscText
				{
					idc = IDC_RESPAWN_TICKETS_CIVLABEL;
					h = POS_H(1);
					w = POS_W(9);
					x = POS_X(6.5);
					y = POS_Y(6);
					text = "CIV tickets"; //--- ToDo: Localize;
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


