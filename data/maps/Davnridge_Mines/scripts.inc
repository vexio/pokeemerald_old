Davnridge_Mines_MapScripts::
	.byte 0

DavnridgeMines_Sign_LocationName::
	msgbox DavnridgeMines_Sign_LocationName_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


DavnridgeMines_Trigger_NoPassage::
	lock
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox DavnridgeMines_Trigger_NoPassage_Text_0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox DavnridgeMines_Trigger_NoPassage_Text_1, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, DavnridgeMines_Movement_NoPassage_0
	waitmovement 0
	release
	end


DavnridgeMines_Movement_NoPassage_0:
	walk_down
	step_end

DavnridgeMines_Movement_NoPassage_2:
	walk_up
	delay_4
	walk_in_place_down
	step_end

DavnridgeMines_Trigger_Lilith::
	lockall
	special SpawnCameraObject
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 55
	goto_if_eq DavnridgeMines_Trigger_Lilith_2
	compare VAR_TEMP_1, 56
	goto_if_eq DavnridgeMines_Trigger_Lilith_3
	compare VAR_TEMP_1, 57
	goto_if_eq DavnridgeMines_Trigger_Lilith_4
DavnridgeMines_Trigger_Lilith_1:
	delay 16
	msgbox DavnridgeMines_Trigger_Lilith_Text_0, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_CRANIDOS, 0
	waitmoncry
	delay 5
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 2
	setvar VAR_0x8007, 1
	special ShakeCamera
	waitstate
	delay 10
	msgbox DavnridgeMines_Trigger_Lilith_Text_1, MSGBOX_AUTOCLOSE
	delay 15
	applymovement 7, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement 7, Common_Movement_QuestionMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox DavnridgeMines_Trigger_Lilith_Text_2
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox DavnridgeMines_Trigger_Lilith_Text_3
	compare VAR_TEMP_1, 55
	goto_if_eq DavnridgeMines_Trigger_Lilith_9
	compare VAR_TEMP_1, 56
	goto_if_eq DavnridgeMines_Trigger_Lilith_10
	compare VAR_TEMP_1, 57
	goto_if_eq DavnridgeMines_Trigger_Lilith_11
DavnridgeMines_Trigger_Lilith_8:
	delay 10
	msgbox DavnridgeMines_Trigger_Lilith_Text_4, MSGBOX_AUTOCLOSE
	compare VAR_TEMP_1, 56
	goto_if_eq DavnridgeMines_Trigger_Lilith_16
	applymovement 7, DavnridgeMines_Lilith_Movement_5
	waitmovement 0
DavnridgeMines_Trigger_Lilith_15:
	removeobject 7
	special RemoveCameraObject
	setflag FLAG_DAVNRIDGEMINES_LILITH
	setvar VAR_DAVNRIDGEMINES_STATE, 1
	releaseall
	end

DavnridgeMines_Trigger_Lilith_2:
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_0
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_1

DavnridgeMines_Trigger_Lilith_3:
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_1
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_1

DavnridgeMines_Trigger_Lilith_4:
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_2
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_1

DavnridgeMines_Trigger_Lilith_9:
	applymovement 7, DavnridgeMines_Lilith_Movement_1
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_8

DavnridgeMines_Trigger_Lilith_10:
	applymovement 7, DavnridgeMines_Lilith_Movement_2
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_4
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_8

DavnridgeMines_Trigger_Lilith_11:
	applymovement 7, DavnridgeMines_Lilith_Movement_3
	applymovement OBJ_EVENT_ID_CAMERA, DavnridgeMines_Lilith_CMovement_5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_8

DavnridgeMines_Trigger_Lilith_16:
	applymovement 7, DavnridgeMines_Lilith_Movement_4
	waitmovement 0
	goto DavnridgeMines_Trigger_Lilith_15


DavnridgeMines_Lilith_CMovement_0:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

DavnridgeMines_Lilith_CMovement_1:
	walk_left
	walk_left
	walk_left
	step_end

DavnridgeMines_Lilith_CMovement_2:
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

DavnridgeMines_Lilith_Movement_1:
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

DavnridgeMines_Lilith_Movement_2:
	walk_right
	walk_right
	step_end

DavnridgeMines_Lilith_Movement_3:
	walk_right
	walk_right
	walk_right
	walk_in_place_down
	step_end

DavnridgeMines_Lilith_CMovement_3:
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

DavnridgeMines_Lilith_CMovement_4:
	walk_right
	walk_right
	walk_right
	step_end

DavnridgeMines_Lilith_CMovement_5:
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

DavnridgeMines_Lilith_Movement_4:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

DavnridgeMines_Lilith_Movement_5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
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
	msgbox DavnridgeMines_Object_Miner_NoPassage_Text_0, MSGBOX_NPC
	end


DavnridgeMines_Sign_LocationName_Text_0:
	.string "{COLOR LIGHT_GREEN}Davnridge Mines\p"
	.string "{COLOR DARK_GREY}There is spray paint over the rest of\n"
	.string "the sign...$"

DavnridgeMines_Trigger_NoPassage_Text_0:
	.string "{COLOR BLUE}Whoa whoa!$"

DavnridgeMines_Trigger_NoPassage_Text_1:
	.string "{COLOR BLUE}This area is off limits!\p"
	.string "We're running some explosive tests in\n"
	.string "the mine up ahead.\p"
	.string "Come back later.$"

DavnridgeMines_Trigger_Lilith_Text_0:
	.string "???: {COLOR RED}Cranidos, use Rock Tomb!$"

DavnridgeMines_Trigger_Lilith_Text_1:
	.string "???: {COLOR RED}Great job Cranidos!\n"
	.string "Return!$"

DavnridgeMines_Trigger_Lilith_Text_2:
	.string "???: {COLOR RED}You don't look like one of my\n"
	.string "miners...$"

DavnridgeMines_Trigger_Lilith_Text_3:
	.string "???: {COLOR RED}Oh!\p"
	.string "You're a trainer!$"

DavnridgeMines_Trigger_Lilith_Text_4:
	.string "???: {COLOR RED}Nice to meet you, trainer!\p"
	.string "My name is {COLOR GREEN}Lilith{COLOR RED} and I'm the {COLOR GREEN}Davnridge\n"
	.string "Pokémon Gym Leader{COLOR RED}.\p"
	.string "I assume you came all this way to\n"
	.string "challenge me, so I'll be waiting at my\l"
	.string "gym!\p"
	.string "{COLOR DARK_GREY}Lilith:{COLOR RED} I look forward to challenging\n"
	.string "you, trainer!$"

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
	.string "Gligar in these mines.$"

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

DavnridgeMines_Object_Miner_NoPassage_Text_0:
	.string "{COLOR BLUE}Hey bud!\n"
	.string "This tunnel over here is off limits right\l"
	.string "now.\p"
	.string "We're running some explosion tests, so\n"
	.string "no one is allowed through.\p"
	.string "Come back later when we're done.$"
