class ADDON
{
	class GVAR(Main)
	{
		file = "\x\timberZA\addons\main\functions";
		class zeusRegister { postInit = 1; };
	};

	class GVAR(RespawnTickets)
	{
	    file = "\x\timberZA\addons\main\functions\respawn_tickets";
	    class editRespawnTicketsModule {};
	};

	class GVAR(RespawnPosition)
    {
        file = "\x\timberZA\addons\main\functions\respawn_position";
        class showRespawnPositionGUI {};
        class addRespawnPositionModule {};
    };
};