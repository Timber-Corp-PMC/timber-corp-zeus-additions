class GVAR(RscRespawnTickets)
{
	idd = IDD_RESPAWN_TICKETS;
	onLoad = "uiNamespace setVariable ['timberZA_main_RscRespawnTicketsDisplay',_this select 0];";

	class controls {

		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT START (by Geelik, v1.063, #Miqipo)
		////////////////////////////////////////////////////////

		class Background: RscText
		{
			idc = IDC_RESPAWN_TICKETS_BACKGROUND;
			x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 13.5 * GUI_GRID_CENTER_W;
			h = 11.5 * GUI_GRID_CENTER_H;
			colorBackground[] = {0,0,0,0.7};
		};
		class ButtonOk: RscButtonMenuOK
		{
			idc = IDC_OK;
			x = 21 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 3.5 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
		};
		class ButtonCancel: RscButtonMenuCancel
		{
			idc = IDC_CANCEL;
			x = 16.5 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 13 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 3.5 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
		};
		class Title: RscText
		{
			idc = IDC_RESPAWN_TICKETS_TITLE;
			x = 12 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 3 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 13.5 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
			
			colorText[] = {0.95,0.95,0.95,1};
			colorBackground[] = GUI_THEME_COLOR;
			text = "Edit respawn tickets"; //--- ToDo: Localize;
		};
		class BluforInput: RscEdit
		{
			idc = IDC_RESPAWN_TICKETS_BLUFORINPUT;
			x = 20 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 4.5 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
		};
		class OpforInput: RscEdit
		{
			idc = IDC_RESPAWN_TICKETS_OPFORINPUT;
			x = 20 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 4.5 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
		};
		class IndepInput: RscEdit
		{
			idc = IDC_RESPAWN_TICKETS_INDEPINPUT;
			x = 20 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 4.5 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
		};
		class CivInput: RscEdit
		{
			idc = IDC_RESPAWN_TICKETS_CIVINPUT;
			x = 20 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 11 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 4.5 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
		};
		class BluforLabel: RscText
		{
			idc = IDC_RESPAWN_TICKETS_BLUFORLABEL;
			x = 13 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 5 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 6 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
			text = "BLUFOR tickets"; //--- ToDo: Localize;
		};
		class OpforLabel: RscText
		{
			idc = IDC_RESPAWN_TICKETS_OPFORLABEL;
			x = 13 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 7 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 6 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
			text = "OPFOR tickets"; //--- ToDo: Localize;
		};
		class IndepLabel: RscText
		{
			idc = IDC_RESPAWN_TICKETS_INDEPLABEL;
			x = 13 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 9 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 6 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
			text = "INDEP tickets"; //--- ToDo: Localize;
		};
		class CivLabel: RscText
		{
			idc = IDC_RESPAWN_TICKETS_CIVLABEL;
			x = 13 * GUI_GRID_CENTER_W + GUI_GRID_CENTER_X;
			y = 11 * GUI_GRID_CENTER_H + GUI_GRID_CENTER_Y;
			w = 6 * GUI_GRID_CENTER_W;
			h = 1 * GUI_GRID_CENTER_H;
			text = "CIV tickets"; //--- ToDo: Localize;
		};
		////////////////////////////////////////////////////////
		// GUI EDITOR OUTPUT END
		////////////////////////////////////////////////////////
	};
};


