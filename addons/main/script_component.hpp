#define COMPONENT main
#define COMPONENT_BEAUTIFIED Main

#include "\a3\ui_f\hpp\defineCommonGrids.inc"
#include "\a3\ui_f\hpp\defineDIKCodes.inc"
#include "\a3\ui_f_curator\ui\defineResinclDesign.inc"

//gui defines - Using same approach as ZEN for gui styling
#define POS_X(N) ((N) * GUI_GRID_W + GUI_GRID_CENTER_X)
#define POS_Y(N) ((N) * GUI_GRID_H + GUI_GRID_CENTER_Y)
#define POS_W(N) ((N) * GUI_GRID_W)
#define POS_H(N) ((N) * GUI_GRID_H)

//colour defines 
#define COLOR_BACKGROUND_SETTING {1,1,1,0.2}

//IDC for the gui - Cannot change this as the initial display pos from ZEN depends on the same three defines
#define IDC_TITLE 10
#define IDC_BACKGROUND 20
#define IDC_CONTENT 30

#define IDC_ATTRIBUTE_GROUP      400
#define IDC_ATTRIBUTE_LABEL      401
#define IDC_ATTRIBUTE_BACKGROUND 402
#define IDC_ATTRIBUTE_COMBO      403
#define IDC_ATTRIBUTE_EDIT       404
#define IDC_ATTRIBUTE_SLIDER     405
#define IDC_ATTRIBUTE_TOOLBOX    406
#define IDC_ATTRIBUTE_MODE       407

#define IDC_ROW_GROUP 1000
#define IDC_ROW_LABEL 1001
#define IDC_ROW_CHECKBOX 1002
#define IDC_ROW_COMBO 1003
#define IDC_ROW_EDIT 1004
#define IDC_ROW_SLIDER 1005
#define IDC_ROW_TOOLBOX 1006
#define IDC_ROW_SIDES 1007
#define IDC_ROW_OWNERS 1008
#define IDC_ROW_COLOR_PREVIEW 1009
#define IDC_ROW_COLOR_RED 1010
#define IDC_ROW_COLOR_RED_EDIT 1011
#define IDC_ROW_COLOR_GREEN 1012
#define IDC_ROW_COLOR_GREEN_EDIT 1013
#define IDC_ROW_COLOR_BLUE 1014
#define IDC_ROW_COLOR_BLUE_EDIT 1015
#define IDC_ROW_COLOR_ALPHA 1016
#define IDC_ROW_COLOR_ALPHA_EDIT 1017
#define IDC_ROW_VECTOR_X 1018
#define IDC_ROW_VECTOR_Y 1019
#define IDC_ROW_VECTOR_Z 1020

#define IDC_TITLE_GROUP 		1540
#define IDC_TITLE_GROUP_LEADER	1541
#define IDC_LIST       			1543
#define IDC_BTN_SEARCH 			1546
#define IDC_SEARCH_BAR 			1547
#define IDC_WEIGHT	   			1548

//IDC for RscRespawnTickets
#define IDC_OK 1
#define IDC_CANCEL 2
#define IDC_RESPAWN_TICKETS_BLUFORINPUT 8001
#define IDC_RESPAWN_TICKETS_OPFORINPUT 8002
#define IDC_RESPAWN_TICKETS_INDEPINPUT 8003
#define IDC_RESPAWN_TICKETS_CIVINPUT 8004

#include "\x\timberZA\addons\main\script_mod.hpp"
#include "\x\timberZA\addons\main\script_macros.hpp"
