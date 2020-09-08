Route103_Gatehouse_MapScripts::
	//map_script MAP_SCRIPT_ON_TRANSITION, AlnerwickLibrary_OnTransition
	.byte 0

Route103_GH_Object_Officer::
	msgbox Route103_GH_Object_Officer_Text_0, MSGBOX_NPC
	end


Route103_GH_Object_Girl::
	msgbox Route103_GH_Object_Girl_Text_0, MSGBOX_NPC
	end


Route103_GH_Object_Officer_Text_0:
	.string "{COLOR GREEN}Alnerwick Lowlands{COLOR BLUE} is a route\n"
	.string "connecting {COLOR GREEN}Alnerwick City{COLOR BLUE} and\l"
	.string "{COLOR GREEN}Davnridge Town{COLOR BLUE}.\p"
	.string "The route ahead has some diverse\n"
	.string "terrain with a lot of trainers and some\l"
	.string "unique Pokémon.$"

Route103_GH_Object_Girl_Text_0:
	.string "{COLOR RED}I love picking the flowers from the\n"
	.string "lowlands outside of Alnerwick.$"
