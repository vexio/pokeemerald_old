Route107_MapScripts:: @ 81EE594
	map_script MAP_SCRIPT_ON_RESUME, Route107_OnResume
	.byte 0

Route107_OnResume::
	setstepcallback STEP_CB_ASH
	end

Route107_EventScript_Darrin:: @ 81EE595
	trainerbattle_single TRAINER_DARRIN, Route107_Text_DarrinIntro, Route107_Text_DarrinDefeated
	msgbox Route107_Text_DarrinPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Tony:: @ 81EE5AC
	trainerbattle_single TRAINER_TONY_1, Route107_Text_TonyIntro, Route107_Text_TonyDefeated, Route107_EventScript_TonyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route107_EventScript_TonyRematch
	msgbox Route107_Text_TonyPostBattle, MSGBOX_DEFAULT
	release
	end

Route107_EventScript_TonyRegisterMatchCallAfterBattle:: @ 81EE5D8
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route107_Text_TonyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TONY_1
	release
	end

Route107_EventScript_TonyRematch:: @ 81EE5F7
	trainerbattle_rematch TRAINER_TONY_1, Route107_Text_TonyRematchIntro, Route107_Text_TonyRematchDefeated
	msgbox Route107_Text_TonyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Denise:: @ 81EE60E
	trainerbattle_single TRAINER_DENISE, Route107_Text_DeniseIntro, Route107_Text_DeniseDefeated
	msgbox Route107_Text_DenisePostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Beth:: @ 81EE625
	trainerbattle_single TRAINER_BETH, Route107_Text_BethIntro, Route107_Text_BethDefeated
	msgbox Route107_Text_BethPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Lisa:: @ 81EE63C
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_LisaIntro, Route107_Text_LisaDefeated, Route107_Text_LisaNotEnoughPokemon
	msgbox Route107_Text_LisaPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Ray:: @ 81EE657
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_RayIntro, Route107_Text_RayDefeated, Route107_Text_RayNotEnoughPokemon
	msgbox Route107_Text_RayPostBattle, MSGBOX_AUTOCLOSE
	end

Route107_EventScript_Camron:: @ 81EE672
	trainerbattle_single TRAINER_CAMRON, Route107_Text_CamronIntro, Route107_Text_CamronDefeated
	msgbox Route107_Text_CamronPostBattle, MSGBOX_AUTOCLOSE
	end

FrostpineClimb_Sign_RouteSignBottom::
	msgbox FrostpineClimb_Sign_RouteSignBottom_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


FrostpineClimb_Sign_RouteSignTop::
	msgbox FrostpineClimb_Sign_RouteSignTop_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


FrostpineClimb_Trainer_Hiker::
	trainerbattle_single TRAINER_HIKER_YUSUF, FrostpineClimb_Trainer_Hiker_Text_0, FrostpineClimb_Trainer_Hiker_Text_1
	msgbox FrostpineClimb_Trainer_Hiker_Text_2, MSGBOX_NPC
	end


FrostpineClimb_Trainer_Ranger::
	trainerbattle_single TRAINER_RANGER_ELIJAH, FrostpineClimb_Trainer_Ranger_Text_0, FrostpineClimb_Trainer_Ranger_Text_1
	msgbox FrostpineClimb_Trainer_Ranger_Text_2, MSGBOX_NPC
	end


FrostpineClimb_Trainer_Kindler::
	trainerbattle_single TRAINER_KINDLER_DREW, FrostpineClimb_Trainer_Kindler_Text_0, FrostpineClimb_Trainer_Kindler_Text_1
	msgbox FrostpineClimb_Trainer_Kindler_Text_2, MSGBOX_NPC
	end


FrostpineClimb_Sign_Gate::
	msgbox FrostpineClimb_Sign_Gate_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	return


FrostpineClimb_Sign_RouteSignBottom_Text_0:
	.string "{COLOR LIGHT_GREEN}Frostpine Climb\p"
	.string "{COLOR DARK_GREY}{DOWN_ARROW}{COLOR LIGHT_GREEN} Triad Gorge\n"
	.string "{COLOR DARK_GREY}{UP_ARROW}{COLOR LIGHT_GREEN} Frostpine City$"

FrostpineClimb_Sign_RouteSignTop_Text_0:
	.string "{COLOR LIGHT_GREEN}Frostpine Climb\p"
	.string "{COLOR DARK_GREY}{UP_ARROW}{COLOR LIGHT_GREEN} Frostpine City\n"
	.string "{COLOR DARK_GREY}{DOWN_ARROW}{COLOR LIGHT_GREEN} Triad Gorge$"

FrostpineClimb_Trainer_Hiker_Text_0:
	.string "{COLOR BLUE}Brrr...\n"
	.string "It's getting cold!$"

FrostpineClimb_Trainer_Hiker_Text_1:
	.string "Chilling!$"

FrostpineClimb_Trainer_Hiker_Text_2:
	.string "{COLOR BLUE}Brrr...\p"
	.string "This climb is a cold one isn't it?$"

FrostpineClimb_Trainer_Ranger_Text_0:
	.string "{COLOR BLUE}Are you here to harm the wild Pokémon?$"

FrostpineClimb_Trainer_Ranger_Text_1:
	.string "Wow!\n"
	.string "You have a great relationship with your\l"
	.string "Pokémon!$"

FrostpineClimb_Trainer_Ranger_Text_2:
	.string "{COLOR BLUE}I'm here to protect these rare Pokémon\n"
	.string "from trainers who don't know how to\l"
	.string "properly take care of Pokémon!$"

FrostpineClimb_Trainer_Kindler_Text_0:
	.string "{COLOR BLUE}There's a fire burning in me!$"

FrostpineClimb_Trainer_Kindler_Text_1:
	.string "Extinguished!$"

FrostpineClimb_Trainer_Kindler_Text_2:
	.string "{COLOR BLUE}This is where I come to train my\n"
	.string "Fire-type Pokémon.\p"
	.string "Fire-type Pokémon melt through\n"
	.string "Ice-type Pokémon!$"

FrostpineClimb_Sign_Gate_Text_0:
	.string "{COLOR LIGHT_GREEN}Frostpine Gate$"
