class GVAR(RscRespawnTickets)
{
	idd = IDD_RESPAWN_TICKETS;
	onLoad = "uiNamespace setVariable ['timberZA_main_RscRespawnTicketsDisplay',_this select 0];";

	class controls {

		class Background: RscBackground
		{
			idc = -1;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.257813 * safezoneW;
			h = 0.286 * safezoneH;
			colorBackground[] = {0, 0, 0, 0.7};
		};
		
		class ButtonOk: RscButtonMenuOK
		{
			idc = IDC_OK;
			x = 0.561875 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			idc = IDC_CANCEL;
			x = 0.474219 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0721875 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BluforInput: RscEdit
		{
			idc = IDC_RESPAWN_TICKETS_BLUFOR_INPUT;
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class BluforLabel: RscText
		{
			idc = -1;
			text = "BLUFOR tickets"; //--- ToDo: Localize;
			x = 0.391719 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class OpforLabel: RscText
		{
			idc = -1;
			text = "OPFOR tickets"; //--- ToDo: Localize;
			x = 0.391719 * safezoneW + safezoneX;
			y = 0.423 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class OpforInput: RscEdit
		{
			idc = IDC_RESPAWN_TICKETS_OPFOR_INPUT;
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.423 * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class CivLabel: RscText
		{
			idc = -1;
			text = "CIV tickets"; //--- ToDo: Localize;
			x = 0.391719 * safezoneW + safezoneX;
			y = 0.467 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class IndepLabel: RscText
		{
			idc = -1;
			text = "INDEP tickets"; //--- ToDo: Localize;
			x = 0.391719 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.0876563 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class CivInput: RscEdit
		{
			idc = IDC_RESPAWN_TICKETS_CIV_INPUT;
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.467 * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class IndepInput: RscEdit
		{
			idc = IDC_RESPAWN_TICKETS_INDEP_INPUT;
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.511 * safezoneH + safezoneY;
			w = 0.103125 * safezoneW;
			h = 0.022 * safezoneH;
		};
		class Title: RscTitle
		{
			idc = -1;
			text = "Edit respawn tickets"; //--- ToDo: Localize;
			x = 0.381406 * safezoneW + safezoneX;
			y = 0.313 * safezoneH + safezoneY;
			w = 0.257813 * safezoneW;
			h = 0.033 * safezoneH;
			colorBackground[] = GUI_THEME_COLOR;
		};
	};
};


