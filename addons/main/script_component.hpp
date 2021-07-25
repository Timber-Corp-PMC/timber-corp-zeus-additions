#define COMPONENT main
#define COMPONENT_BEAUTIFIED Main

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

#define IDC_TITLE_GROUP 		1540
#define IDC_TITLE_GROUP_LEADER	1541
#define IDC_LIST       			1543
#define IDC_BTN_SEARCH 			1546
#define IDC_SEARCH_BAR 			1547
#define IDC_WEIGHT	   			1548

//IDC for RscRespawnTickets
#define IDC_OK 1
#define IDC_CANCEL 2

//Respawn tickets
#define IDC_RESPAWN_TICKETS_BACKGROUND -1
#define IDC_RESPAWN_TICKETS_TITLE -1
#define IDC_RESPAWN_TICKETS_BLUFORINPUT 8001
#define IDC_RESPAWN_TICKETS_OPFORINPUT 8002
#define IDC_RESPAWN_TICKETS_INDEPINPUT 8003
#define IDC_RESPAWN_TICKETS_CIVINPUT 8004
#define IDC_RESPAWN_TICKETS_BLUFORLABEL -1
#define IDC_RESPAWN_TICKETS_OPFORLABEL -1
#define IDC_RESPAWN_TICKETS_INDEPLABEL -1
#define IDC_RESPAWN_TICKETS_CIVLABEL -1

//Respawn position
#define IDC_RESPAWN_POSITION_NAME_LABEL -1
#define IDC_RESPAWN_POSITION_NAME 8101
#define IDC_RESPAWN_POSITION_SIDE_LABEL -1
#define IDC_RESPAWN_POSITION_SIDE 8102

#include "\x\timberZA\addons\main\script_mod.hpp"
#include "\x\timberZA\addons\main\script_macros.hpp"
