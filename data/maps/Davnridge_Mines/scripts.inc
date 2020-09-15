Davnridge_Mines_MapScripts::
	.byte 0

DavnridgeMines_Sign_LocationName::
	msgbox DavnridgeMines_Sign_LocationName_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


DavnridgeMines_Trigger_NoPassage::
	lock
	applymovement 5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	delay 15
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 29
	goto_if_eq DavnridgeMines_Trigger_NoPassage_2
DavnridgeMines_Trigger_NoPassage_1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox DavnridgeMines_Trigger_NoPassage_Text_0, MSGBOX_AUTOCLOSE
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, DavnridgeMines_Movement_NoPassage_1
	waitmovement 0
	compare VAR_TEMP_1, 29
	goto_if_eq DavnridgeMines_Trigger_NoPassage_5
DavnridgeMines_Trigger_NoPassage_4:
	release
	end

DavnridgeMines_Trigger_NoPassage_2:
	applymovement 5, DavnridgeMines_Movement_NoPassage_0
	waitmovement 0
	goto DavnridgeMines_Trigger_NoPassage_1

DavnridgeMines_Trigger_NoPassage_5:
	applymovement 5, DavnridgeMines_Movement_NoPassage_2
	waitmovement 0
	goto DavnridgeMines_Trigger_NoPassage_4


DavnridgeMines_Movement_NoPassage_0:
	walk_down
	step_end

DavnridgeMines_Movement_NoPassage_1:
	walk_left
	step_end

DavnridgeMines_Movement_NoPassage_2:
	walk_up
	delay_4
	walk_in_place_down
	step_end

DavnridgeMines_Trigger_Lilith::
	lock
	special SpawnCameraObject
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 27
	goto_if_eq DavnridgeMines_Trigger_Lilith_2
	compare VAR_TEMP_0, 28
	goto_if_eq DavnridgeMines_Trigger_Lilith_3
	compare VAR_TEMP_0, 29
	goto_if_eq DavnridgeMines_Trigger_Lilith_4
DavnridgeMines_Trigger_Lilith_1:
	delay 10
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox DavnridgeMines_Trigger_Lilith_Text_0, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 9, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	delay 10
	msgbox DavnridgeMines_Trigger_Lilith_Text_1, MSGBOX_AUTOCLOSE
	delay 5
	compare VAR_TEMP_0, 27
	goto_if_eq DavnridgeMines_Trigger_Lilith_9
	compare VAR_TEMP_0, 28
	goto_if_eq DavnridgeMines_Trigger_Lilith_10
	compare VAR_TEMP_0, 29
	goto_if_eq DavnridgeMines_Trigger_Lilith_11
DavnridgeMines_Trigger_Lilith_8:
	special RemoveCameraObject
	delay 10
	msgbox DavnridgeMines_Trigger_Lilith_Text_2, MSGBOX_AUTOCLOSE
	compare VAR_TEMP_0, 28
	goto_if_eq DavnridgeMines_Trigger_Lilith_16
	applymovement 9, DavnridgeMines_Lilith_Movement_4
	waitmovement 0
DavnridgeMines_Trigger_Lilith_15:
	removeobject 9
	playse SE_KAIDAN
	setflag FLAG_DAVNRIDGEMINES_LILITH
	setvar VAR_DAVNRIDGEMINES_STATE, 1
	release
	end

DavnridgeMines_Trigger_Lilith_2:
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_1
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_1

DavnridgeMines_Trigger_Lilith_3:
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_0
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_1

DavnridgeMines_Trigger_Lilith_4:
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_2
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_1

DavnridgeMines_Trigger_Lilith_9:
	applymovement 9, DavnridgeMines_Lilith_Movement_1
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_8

DavnridgeMines_Trigger_Lilith_10:
	applymovement 9, DavnridgeMines_Lilith_Movement_0
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_3
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_8

DavnridgeMines_Trigger_Lilith_11:
	applymovement 9, DavnridgeMines_Lilith_Movement_2
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_8

DavnridgeMines_Trigger_Lilith_16:
	applymovement 9, DavnridgeMines_Lilith_Movement_3
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_15


DavnridgeMines_Lilith_CMovement_0:
	walk_down
	walk_down
	walk_down
	step_end

DavnridgeMines_Lilith_CMovement_1:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

DavnridgeMines_Lilith_CMovement_2:
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

DavnridgeMines_Lilith_Movement_0:
	walk_up
	walk_up
	step_end

DavnridgeMines_Lilith_Movement_1:
	walk_up
	walk_up
	walk_up
	walk_in_place_left
	step_end

DavnridgeMines_Lilith_Movement_2:
	walk_up
	walk_up
	walk_up
	walk_in_place_right
	step_end

DavnridgeMines_Lilith_CMovement_3:
	walk_up
	walk_up
	walk_up
	step_end

DavnridgeMines_Lilith_CMovement_4:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

DavnridgeMines_Lilith_CMovement_5:
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

DavnridgeMines_Lilith_Movement_3:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

DavnridgeMines_Lilith_Movement_4:
	walk_up
	walk_up
	walk_up
	step_end

DavnridgeMines_Trainer_Miner_1::
	trainerbattle_single TRAINER_MINER_CLARK, DavnridgeMines_Trainer_Miner_1_Text_0, DavnridgeMines_Trainer_Miner_1_Text_1
	msgbox DavnridgeMines_Trainer_Miner_1_Text_2, MSGBOX_NPC
	end


DavnridgeMines_Trainer_Miner_2::
	trainerbattle_single TRAINER_MINER_LUIS, DavnridgeMines_Trainer_Miner_2_Text_0, DavnridgeMines_Trainer_Miner_2_Text_1
	msgbox DavnridgeMines_Trainer_Miner_2_Text_2, MSGBOX_NPC
	end


DavnridgeMines_Trainer_Hiker::
	trainerbattle_single TRAINER_HIKER_ED, DavnridgeMines_Trainer_Hiker_Text_0, DavnridgeMines_Trainer_Hiker_Text_1
	msgbox DavnridgeMines_Trainer_Hiker_Text_2, MSGBOX_NPC
	end


DavnridgeMines_Trainer_Fisherman::
	trainerbattle_single TRAINER_FISHERMAN_JAMARCUS, DavnridgeMines_Trainer_Fisherman_Text_0, DavnridgeMines_Trainer_Fisherman_Text_1
	msgbox DavnridgeMines_Trainer_Fisherman_Text_2, MSGBOX_NPC
	end


DavnridgeMines_Trainer_Maniac::
	trainerbattle_single TRAINER_MANIAC_IAN, DavnridgeMines_Trainer_Maniac_Text_0, DavnridgeMines_Trainer_Maniac_Text_1
	msgbox DavnridgeMines_Trainer_Maniac_Text_2, MSGBOX_NPC
	end


DavnridgeMines_Trainer_BlackBelt::
	trainerbattle_single TRAINER_BLACKBELT_ALVARO, DavnridgeMines_Trainer_BlackBelt_Text_0, DavnridgeMines_Trainer_BlackBelt_Text_1
	msgbox DavnridgeMines_Trainer_BlackBelt_Text_2, MSGBOX_NPC
	end


DavnridgeMines_Object_Miner_3::
	msgbox DavnridgeMines_Object_Miner_3_Text_0, MSGBOX_NPC
	end


DavnridgeMines_Object_Miner_NoPassage::
	msgbox DavnridgeMines_Trigger_NoPassage_Text_0, MSGBOX_NPC
	end


DavnridgeMines_Sign_LocationName_Text_0:
	.string "{COLOR LIGHT_GREEN}Davnridge Mines\p"
	.string "{COLOR DARK_GREY}There is spray paint over the rest of\n"
	.string "the sign...$"

DavnridgeMines_Trigger_NoPassage_Text_0:
	.string "{COLOR BLUE}Hey bud!\n"
	.string "This are over here is off limits right\l"
	.string "now.\p"
	.string "We're running some explosion tests, so\n"
	.string "no one is allowed through.\p"
	.string "Come back later when we're done.$"

DavnridgeMines_Trigger_Lilith_Text_0:
	.string "???: {COLOR RED}Good job Sudowoodo!\n"
	.string "Now, we should head back to the Gym.$"

DavnridgeMines_Trigger_Lilith_Text_1:
	.string "???: {COLOR RED}What are you doing in these parts?$"

DavnridgeMines_Trigger_Lilith_Text_2:
	.string "???: {COLOR RED}Wait, you don't need to tell me!\p"
	.string "I can tell you're a trainer who wants to\n"
	.string "challenge me!\p"
	.string "{COLOR DARK_GREY}Lilith: {COLOR RED}Hi, my name is Lilith.\n"
	.string "I'm {COLOR GREEN}Davnridge's Gym Leader{COLOR RED}!\p"
	.string "Come meet me at my Gym and I'll give you\n"
	.string "a challenge!$"

DavnridgeMines_Trainer_Miner_1_Text_0:
	.string "{COLOR BLUE}Wha' brings you to th' mines?$"

DavnridgeMines_Trainer_Miner_1_Text_1:
	.string "Wowza!\n"
	.string "You got some stron' Pokémon ther'!$"

DavnridgeMines_Trainer_Miner_1_Text_2:
	.string "{COLOR BLUE}I bet you'd be lookin' for ol' {COLOR GREEN}Lilith{COLOR BLUE}...\p"
	.string "I saw her go up those stairs ther'.$"

DavnridgeMines_Trainer_Miner_2_Text_0:
	.string "{COLOR BLUE}I'm on my 15 minute break.\p"
	.string "Let's make this battle quick!$"

DavnridgeMines_Trainer_Miner_2_Text_1:
	.string "Looks like my break is over...$"

DavnridgeMines_Trainer_Miner_2_Text_2:
	.string "{COLOR BLUE}Looks like my 15 minute break is over...$"

DavnridgeMines_Trainer_Hiker_Text_0:
	.string "{COLOR BLUE}That guy over there won't let me\n"
	.string "through the caves!$"

DavnridgeMines_Trainer_Hiker_Text_1:
	.string "Only if I was able to get through the\n"
	.string "reset of the caves...$"

DavnridgeMines_Trainer_Hiker_Text_2:
	.string "{COLOR BLUE}The rest of the caves are on the east\n"
	.string "passage in this tunnel here.\p"
	.string "That passage will take you outside the\n"
	.string "caves and towards {COLOR GREEN}Enclava Town{COLOR BLUE}.$"

DavnridgeMines_Trainer_Fisherman_Text_0:
	.string "{COLOR BLUE}This is a great fishing spot!$"

DavnridgeMines_Trainer_Fisherman_Text_1:
	.string "Agh!\n"
	.string "You scared the fish away!$"

DavnridgeMines_Trainer_Fisherman_Text_2:
	.string "{COLOR BLUE}This is my secret fishing spot!\p"
	.string "My buddies always ask me how I get such\n"
	.string "big Magikarp!$"

DavnridgeMines_Trainer_Maniac_Text_0:
	.string "{COLOR BLUE}I found a rare Pokémon!\n"
	.string "Want to see it?$"

DavnridgeMines_Trainer_Maniac_Text_1:
	.string "No!\n"
	.string "My rare Pokémon!$"

DavnridgeMines_Trainer_Maniac_Text_2:
	.string "{COLOR BLUE}There is a very rare chance to find a\n"
	.string "Gligar in these mines.\p"
	.string "Surprisingly, there aren't any Zubats...$"

DavnridgeMines_Trainer_BlackBelt_Text_0:
	.string "{COLOR BLUE}Hai-ya!$"

DavnridgeMines_Trainer_BlackBelt_Text_1:
	.string "Fwah!$"

DavnridgeMines_Trainer_BlackBelt_Text_2:
	.string "{COLOR BLUE}Hwah!$"

DavnridgeMines_Object_Miner_3_Text_0:
	.string "{COLOR BLUE}Oh you want to battle?\p"
	.string "I didn't bring my Pokémon with me\n"
	.string "today...\l"
	.string "My daughter wanted to play with them\l"
	.string "today.$"
