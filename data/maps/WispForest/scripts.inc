WispForest_MapScripts::
	.byte 0


ShilouWoods_Sign_DirectionSign::
	msgbox ShilouWoods_Sign_DirectionSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


ShilouWoods_Sign_DeeperWoodsWarp::
	lock
	msgbox ShilouWoods_Sign_DeeperWoodsWarp_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq ShilouWoods_Sign_DeeperWoodsWarp_1
	release
	end

ShilouWoods_Sign_DeeperWoodsWarp_1:
	warp MAP_SHILOU_WOODS_DEEP, 0, 0, 0
	release
	end


ShilouWoods_Object_LittleGirl::
	lock
	compare VAR_SHILOUWOODS_GHOST_BOY, 0
	goto_if_eq ShilouWoods_Object_LittleGirl_1
	faceplayer
	msgbox ShilouWoods_Object_LittleGirl_Text_3, MSGBOX_AUTOCLOSE
	release
	end

ShilouWoods_Object_LittleGirl_1:
	delay 20
	faceplayer
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox ShilouWoods_Object_LittleGirl_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq ShilouWoods_Object_LittleGirl_4
	msgbox ShilouWoods_Object_LittleGirl_Text_2, MSGBOX_AUTOCLOSE
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

ShilouWoods_Object_LittleGirl_4:
	msgbox ShilouWoods_Object_LittleGirl_Text_1, MSGBOX_AUTOCLOSE
	setvar VAR_SHILOUWOODS_GHOST_BOY, 1
	release
	end


ShilouWoods_Trainer_BugCatcher::
	trainerbattle_single TRAINER_BUG_CATCHER_MITCH, ShilouWoods_Trainer_BugCatcher_Text_0, ShilouWoods_Trainer_BugCatcher_Text_1
	msgbox ShilouWoods_Trainer_BugCatcher_Text_2, MSGBOX_NPC
	end


ShilouWoods_Trainer_BugManiac_1::
	trainerbattle_single TRAINER_BUG_MANIAC_GARY, ShilouWoods_Trainer_BugManiac_1_Text_0, ShilouWoods_Trainer_BugManiac_1_Text_1
	msgbox ShilouWoods_Trainer_BugManiac_1_Text_2, MSGBOX_NPC
	end


ShilouWoods_Trainer_PsychicM::
	trainerbattle_single TRAINER_PSYCHIC_CALE, ShilouWoods_Trainer_PsychicM_Text_0, ShilouWoods_Trainer_PsychicM_Text_1
	msgbox ShilouWoods_Trainer_PsychicM_Text_2, MSGBOX_NPC
	end


ShilouWoods_Trainer_BugManiac_2::
	trainerbattle_single TRAINER_BUG_MANIAC_DARIO, ShilouWoods_Trainer_BugManiac_2_Text_0, ShilouWoods_Trainer_BugManiac_2_Text_1
	msgbox ShilouWoods_Trainer_BugManiac_2_Text_2, MSGBOX_NPC
	end


ShilouWoods_Sign_DirectionSign_Text_0:
	.string "{COLOR LIGHT_GREEN}Shilou Woods\p"
	.string "{COLOR DARK_GREY}{RIGHT_ARROW} {COLOR LIGHT_GREEN}Altos Heights\n"
	.string "{COLOR DARK_GREY}{DOWN_ARROW} {COLOR LIGHT_GREEN}Sunflora Town$"

ShilouWoods_Sign_DeeperWoodsWarp_Text_0:
	.string "It's a dark and narrow passage.\n"
	.string "Will you follow it?$"

ShilouWoods_Object_LittleGirl_Text_0:
	.string "{COLOR RED}Oh!\n"
	.string "You scared me!\p"
	.string "I was just here with my brother... but I\n"
	.string "don't know where he went.\p"
	.string "Could you help me find my brother?$"

ShilouWoods_Object_LittleGirl_Text_1:
	.string "{COLOR RED}Thanks stranger!\p"
	.string "Me and my brother were playing out in\n"
	.string "the deeper woods, but then we got split\l"
	.string "and he got lost...\p"
	.string "I'm too scared to go back in!$"

ShilouWoods_Object_LittleGirl_Text_2:
	.string "{COLOR RED}Oh{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20} Okay{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.$"

ShilouWoods_Object_LittleGirl_Text_3:
	.string "{COLOR RED}Me and my brother were playing out in\n"
	.string "the deeper woods...\p"
	.string "But then he got lost and I couldn't find\n"
	.string "him.\p"
	.string "It's too scary to go back in!$"

ShilouWoods_Trainer_BugCatcher_Text_0:
	.string "{COLOR BLUE}These woods scare me!$"

ShilouWoods_Trainer_BugCatcher_Text_1:
	.string "My bugs!$"

ShilouWoods_Trainer_BugCatcher_Text_2:
	.string "{COLOR BLUE}Hopefully my bugs can protect me from\n"
	.string "the ghosts...$"

ShilouWoods_Trainer_BugManiac_1_Text_0:
	.string "{COLOR BLUE}You don't seem well equipped to catch\n"
	.string "bugs!$"

ShilouWoods_Trainer_BugManiac_1_Text_1:
	.string "Bugs are surperior!$"

ShilouWoods_Trainer_BugManiac_1_Text_2:
	.string "{COLOR BLUE}Bug-type Pokémon are super-effective\n"
	.string "against Psychic, Dark and Grass-typed\l"
	.string "Pokémon.$"

ShilouWoods_Trainer_PsychicM_Text_0:
	.string "{COLOR BLUE}The spirits here...\n"
	.string "They sense your strength...$"

ShilouWoods_Trainer_PsychicM_Text_1:
	.string "Alas!\n"
	.string "The strength they sensed!$"

ShilouWoods_Trainer_PsychicM_Text_2:
	.string "{COLOR BLUE}The Pokémon that roam these woods\n"
	.string "have a strong connection with the\l"
	.string "trainers that travel through.\p"
	.string "Sometimes, the ghosts might attach\n"
	.string "themselves to a trainer.$"

ShilouWoods_Trainer_BugManiac_2_Text_0:
	.string "{COLOR BLUE}Buzz buzz!$"

ShilouWoods_Trainer_BugManiac_2_Text_1:
	.string "Buzz buzz...$"

ShilouWoods_Trainer_BugManiac_2_Text_2:
	.string "{COLOR BLUE}I love the noises that bugs make!\p"
	.string "Buzz buzz!$"
