class GVAR(RscRespawnTickets) : GVAR(RscDisplay)
{
	onLoad = "uiNamespace setVariable ['timberZA_zeus_RscRespawnTicketsDisplay', _this select 0];";
	movingEnable = 1;

	class controls : controls {

        class Title: Title {
            text = "Edit respawn tickets";
        };

		class Background: Background {};

		class Content: Content {

			h = POS_H(10);

			class controls {

				class BluforInput: zen_common_RscEdit
				{
					idc = IDC_RESPAWN_TICKETS_BLUFORINPUT;
					y = POS_Y(0);
				};

				class OpforInput: zen_common_RscEdit
				{
					idc = IDC_RESPAWN_TICKETS_OPFORINPUT;
					y = POS_Y(2);
				};

				class IndepInput: zen_common_RscEdit
				{
					idc = IDC_RESPAWN_TICKETS_INDEPINPUT;
					y = POS_Y(4);
				};

				class CivInput: zen_common_RscEdit
				{
					idc = IDC_RESPAWN_TICKETS_CIVINPUT;
					y = POS_Y(6);
				};

				class BluforLabel: zen_common_RscLabel
				{
					y = POS_Y(0);
					text = "BLUFOR tickets"; //--- ToDo: Localize;
				};

				class OpforLabel: zen_common_RscLabel
				{
					y = POS_Y(2);
					text = "OPFOR tickets"; //--- ToDo: Localize;
				};

				class IndepLabel: zen_common_RscLabel
				{
					y = POS_Y(4);
					text = "INDEP tickets"; //--- ToDo: Localize;
				};

				class CivLabel: zen_common_RscLabel
				{
					y = POS_Y(6);
					text = "CIV tickets"; //--- ToDo: Localize;
				};
			};
        };
        class ButtonOK: ButtonOK {};
        class ButtonCancel: ButtonCancel{};
    };
};


