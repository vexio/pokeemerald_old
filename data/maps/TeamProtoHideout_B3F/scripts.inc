TeamProtoHideout_B3F_MapScripts::
	.byte 0


ProtoHideoutB3F_Trainer_Grunt4::
	trainerbattle_single TRAINER_GRUNT_HIDEOUT_4, ProtoHideoutB3F_Trainer_Grunt4_Text_0, ProtoHideoutB3F_Trainer_Grunt4_Text_1
	msgbox ProtoHideoutB3F_Trainer_Grunt4_Text_2, MSGBOX_NPC
	end


ProtoHideoutB3F_Trainer_Scientist7::
	trainerbattle_single TRAINER_SCIENTIST_HIDEOUT_7, ProtoHideoutB3F_Trainer_Scientist7_Text_0, ProtoHideoutB3F_Trainer_Scientist7_Text_1
	msgbox ProtoHideoutB3F_Trainer_Scientist7_Text_2, MSGBOX_NPC
	end


ProtoHideoutB3F_Object_Skip::
	lockall
	faceplayer
	msgbox ProtoHideoutB3F_Object_Skip_Text_0
	checkitem ITEM_BASEMENT_KEY, 1
	compare VAR_RESULT, TRUE
	goto_if_eq ProtoHideoutB3F_Object_Skip_1
	closemessage
	release
	end

ProtoHideoutB3F_Object_Skip_1:
	applymovement 8, Common_Movement_QuestionMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox ProtoHideoutB3F_Object_Skip_Text_1, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 1
	goto_if_eq ProtoHideoutB3F_Object_Skip_5
	compare VAR_TEMP_0, 3
	goto_if_eq ProtoHideoutB3F_Object_Skip_5
	compare VAR_TEMP_0, 2
	goto_if_eq ProtoHideoutB3F_Object_Skip_6
ProtoHideoutB3F_Object_Skip_4:
	delay 20
	setmetatile 1, 11, 513, 0
	setmetatile 1, 12, 513, 0
	setmetatile 2, 11, 512, 0
	setmetatile 2, 12, 512, 0
	setmetatile 3, 11, 512, 0
	setmetatile 3, 12, 512, 0
	special DrawWholeMapView
	playse SE_BREAKABLE_DOOR
	delay 25
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_2, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 1
	goto_if_eq ProtoHideoutB3F_Object_Skip_12
	compare VAR_TEMP_0, 3
	goto_if_eq ProtoHideoutB3F_Object_Skip_13
	compare VAR_TEMP_0, 2
	goto_if_eq ProtoHideoutB3F_Object_Skip_14
ProtoHideoutB3F_Object_Skip_11:
	delay 10
	applymovement 8, ProtoHideoutB3F_KeyUnlock_Movement_6
	applymovement OBJ_EVENT_ID_PLAYER, ProtoHideoutB3F_KeyUnlock_Movement_6
	waitmovement 0
	special SpawnCameraObject
	delay 10
	applymovement OBJ_EVENT_ID_CAMERA, ProtoHideoutB3F_KeyUnlock_CMovement_0
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_3
	applymovement 6, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_4
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_5
	applymovement 5, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_6
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_7
	applymovement 4, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_8
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_9, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 8, Common_Movement_JumpInPlaceRight
	playse SE_BIKE_HOP
	waitse
	waitmovement 0
	applymovement 8, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_10
	closemessage
	delay 5
	applymovement 3, Common_Movement_WalkInPlaceLeft
	applymovement 4, Common_Movement_WalkInPlaceLeft
	applymovement 5, Common_Movement_WalkInPlaceLeft
	applymovement 6, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement 3, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 6, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	delay 15
	applymovement OBJ_EVENT_ID_CAMERA, ProtoHideoutB3F_AdminEvent_CMovement_0
	waitmovement 0
	applymovement 4, ProtoHideoutB3F_AdminEvent_Movement_1
	applymovement 3, ProtoHideoutB3F_AdminEvent_Movement_0
	waitmovement 0
	special RemoveCameraObject
	msgbox ProtoHideoutB3F_Object_Skip_Text_11
	applymovement 8, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_12
	applymovement 3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_13
	msgbox ProtoHideoutB3F_Object_Skip_Text_14
	compare VAR_STARTER_MON, 0
	goto_if_eq ProtoHideoutB3F_Object_Skip_23
	compare VAR_STARTER_MON, 1
	goto_if_eq ProtoHideoutB3F_Object_Skip_24
	multi_fixed_2_vs_2 TRAINER_LEADER_APOLLO_1, ProtoHideoutB3F_Object_Skip_Text_15, TRAINER_ADMIN_CERES_1, ProtoHideoutB3F_Object_Skip_Text_16, TRAINER_SKIP2_GRASS, TRAINER_BACK_PIC_RED
ProtoHideoutB3F_Object_Skip_22:
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq ProtoHideoutB3F_Object_Skip_31
	delay 10
	msgbox ProtoHideoutB3F_Object_Skip_Text_17, MSGBOX_AUTOCLOSE
	delay 10
	fadescreen FADE_TO_BLACK
	removeobject 3
	removeobject 6
	removeobject 4
	removeobject 5
	playse SE_WARP_OUT
	waitse
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement 8, Common_Movement_WalkInPlaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox ProtoHideoutB3F_Object_Skip_Text_18, MSGBOX_AUTOCLOSE
	applymovement 8, ProtoHideoutB3F_AdminEvent_Movement_2
	waitmovement 0
	removeobject 8
	setvar VAR_PROTO_HIDEOUT, 2
	setflag FLAG_PROTO_HIDEOUT_ALL_OBJS
	releaseall
	end

ProtoHideoutB3F_Object_Skip_5:
	applymovement OBJ_EVENT_ID_PLAYER, ProtoHideoutB3F_KeyUnlock_Movement_2
	applymovement 8, ProtoHideoutB3F_KeyUnlock_Movement_0
	waitmovement 0
	goto ProtoHideoutB3F_Object_Skip_4

ProtoHideoutB3F_Object_Skip_6:
	compare VAR_TEMP_1, 10
	goto_if_eq ProtoHideoutB3F_Object_Skip_18
	compare VAR_TEMP_1, 8
	goto_if_eq ProtoHideoutB3F_Object_Skip_19
	goto ProtoHideoutB3F_Object_Skip_4

ProtoHideoutB3F_Object_Skip_12:
	applymovement OBJ_EVENT_ID_PLAYER, ProtoHideoutB3F_KeyUnlock_Movement_3
	waitmovement 0
	goto ProtoHideoutB3F_Object_Skip_11

ProtoHideoutB3F_Object_Skip_13:
	applymovement OBJ_EVENT_ID_PLAYER, ProtoHideoutB3F_KeyUnlock_Movement_4
	waitmovement 0
	goto ProtoHideoutB3F_Object_Skip_11

ProtoHideoutB3F_Object_Skip_14:
	compare VAR_TEMP_1, 8
	goto_if_eq ProtoHideoutB3F_Object_Skip_28
	goto ProtoHideoutB3F_Object_Skip_11

ProtoHideoutB3F_Object_Skip_18:
	applymovement OBJ_EVENT_ID_PLAYER, ProtoHideoutB3F_KeyUnlock_Movement_2
	applymovement 8, ProtoHideoutB3F_KeyUnlock_Movement_1
	waitmovement 0
	goto ProtoHideoutB3F_Object_Skip_4

ProtoHideoutB3F_Object_Skip_19:
	applymovement 8, ProtoHideoutB3F_KeyUnlock_Movement_0
	waitmovement 0
	goto ProtoHideoutB3F_Object_Skip_4

ProtoHideoutB3F_Object_Skip_23:
	multi_fixed_2_vs_2 TRAINER_LEADER_APOLLO_1, ProtoHideoutB3F_Object_Skip_Text_15, TRAINER_ADMIN_CERES_1, ProtoHideoutB3F_Object_Skip_Text_16, TRAINER_SKIP2_FIRE, TRAINER_BACK_PIC_RED
	goto ProtoHideoutB3F_Object_Skip_22

ProtoHideoutB3F_Object_Skip_24:
	multi_fixed_2_vs_2 TRAINER_LEADER_APOLLO_1, ProtoHideoutB3F_Object_Skip_Text_15, TRAINER_ADMIN_CERES_1, ProtoHideoutB3F_Object_Skip_Text_16, TRAINER_SKIP2_WATER, TRAINER_BACK_PIC_RED
	goto ProtoHideoutB3F_Object_Skip_22

ProtoHideoutB3F_Object_Skip_28:
	applymovement OBJ_EVENT_ID_PLAYER, ProtoHideoutB3F_KeyUnlock_Movement_5
	waitmovement 0
	goto ProtoHideoutB3F_Object_Skip_11

ProtoHideoutB3F_Object_Skip_31:
	fadescreen FADE_TO_BLACK
	special SetCB2WhiteOut
	waitstate
	releaseall
	end


ProtoHideoutB3F_KeyUnlock_Movement_0:
	walk_down
	walk_down
	step_end

ProtoHideoutB3F_KeyUnlock_Movement_1:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_down
	step_end

ProtoHideoutB3F_KeyUnlock_Movement_2:
	delay_16
	delay_4
	walk_in_place_down
	step_end

ProtoHideoutB3F_KeyUnlock_Movement_3:
	walk_right
	walk_down
	step_end

ProtoHideoutB3F_KeyUnlock_Movement_4:
	walk_left
	walk_down
	step_end

ProtoHideoutB3F_KeyUnlock_Movement_5:
	walk_down
	walk_down
	step_end

ProtoHideoutB3F_KeyUnlock_Movement_6:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

ProtoHideoutB3F_KeyUnlock_CMovement_0:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ProtoHideoutB3F_AdminEvent_Movement_0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_left
	step_end

ProtoHideoutB3F_AdminEvent_Movement_1:
	walk_down
	walk_left
	step_end

ProtoHideoutB3F_AdminEvent_CMovement_0:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

ProtoHideoutB3F_AdminEvent_Movement_2:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

ProtoHideoutB3F_Trainer_Grunt4_Text_0:
	.string "{COLOR BLUE}A-ha!\p"
	.string "My storage room patrolling was worth it!$"

ProtoHideoutB3F_Trainer_Grunt4_Text_1:
	.string "Aw...$"

ProtoHideoutB3F_Trainer_Grunt4_Text_2:
	.string "{COLOR BLUE}I like it in here, I don't like to\n"
	.string "interact with anyone.$"

ProtoHideoutB3F_Trainer_Scientist7_Text_0:
	.string "{COLOR BLUE}I've been trying to fix these wires here\n"
	.string "for a while, but a little battle wouldn't\l"
	.string "hurt.$"

ProtoHideoutB3F_Trainer_Scientist7_Text_1:
	.string "...\n"
	.string "Now back to work I guess...$"

ProtoHideoutB3F_Trainer_Scientist7_Text_2:
	.string "{COLOR BLUE}I can't figure out where these wires are\n"
	.string "suppose to connect...$"

ProtoHideoutB3F_Object_Skip_Text_0:
	.string "Skip: {COLOR BLUE}Took you long enough to find me!\p"
	.string "This gate is blocking a meeting room it\n"
	.string "seems.\p"
	.string "I've already had to do everything for\n"
	.string "this operation, so go make yourself\l"
	.string "useful and go find a key!\p"
	.string "I'm sure some guard knows where it is.$"

ProtoHideoutB3F_Object_Skip_Text_1:
	.string "Skip: {COLOR BLUE}Wait, you found a key?\p"
	.string "Huh!\n"
	.string "I'm impressed.\p"
	.string "{COLOR DARK_GREY}Skip:{COLOR BLUE} Let's see if this will work...$"

ProtoHideoutB3F_Object_Skip_Text_2:
	.string "Skip: {COLOR BLUE}It opened!\p"
	.string "Now it's time to battle these goons!\p"
	.string "Let's go, you and me!$"

ProtoHideoutB3F_Object_Skip_Text_3:
	.string "???: {COLOR GREEN}Haumea{COLOR BLUE}, did you obtain the\n"
	.string "{COLOR GREEN}Akumutome{COLOR BLUE} from {COLOR GREEN}Alnerwick Library{COLOR BLUE}?$"

ProtoHideoutB3F_Object_Skip_Text_4:
	.string "Haumea: {COLOR BLUE}Yes sir.\p"
	.string "One of our Grunts stole it from the\n"
	.string "library.$"

ProtoHideoutB3F_Object_Skip_Text_5:
	.string "???: {COLOR BLUE}Good.\p"
	.string "{COLOR GREEN}Eris{COLOR BLUE}, what's the status on the\n"
	.string "{COLOR GREEN}Dorimtome{COLOR BLUE}?$"

ProtoHideoutB3F_Object_Skip_Text_6:
	.string "Eris: {COLOR RED}We had to get in a bit of trouble\n"
	.string "with {COLOR GREEN}Professor Cypress{COLOR RED} and another\l"
	.string "trainer, but they shouldn't be a\l"
	.string "problem anymore.$"

ProtoHideoutB3F_Object_Skip_Text_7:
	.string "???: {COLOR BLUE}Hmph. We can't have any more\n"
	.string "interruptions.\p"
	.string "Once both the {COLOR GREEN}Akumutome{COLOR BLUE} and {COLOR GREEN}Dorimtome{COLOR BLUE}\n"
	.string "are fully translated, we can track down\l"
	.string "and summon the legendary {COLOR GREEN}Darkrai{COLOR BLUE}.\p"
	.string "{COLOR DARK_GREY}???: {COLOR BLUE}Then finally, {COLOR GREEN}Ryoko{COLOR BLUE} will respect my\n"
	.string "wishes and fall into my ruling!$"

ProtoHideoutB3F_Object_Skip_Text_8:
	.string "Ceres: {COLOR RED}Sir, I don't mean to interrupt,\n"
	.string "but there have been reports of two\l"
	.string "trainers discovering the hideout.\p"
	.string "We need to leave immediately.$"

ProtoHideoutB3F_Object_Skip_Text_9:
	.string "???: {COLOR BLUE}Another interruption...\p"
	.string "I'd like to confront these trainers.$"

ProtoHideoutB3F_Object_Skip_Text_10:
	.string "Skip: {COLOR BLUE}We're here to talk to you!$"

ProtoHideoutB3F_Object_Skip_Text_11:
	.string "???: {COLOR BLUE}You two.\p"
	.string "You're the ones who are causing us\n"
	.string "trouble?\p"
	.string "{COLOR DARK_GREY}???: {COLOR BLUE}Pathetic.\p"
	.string "Two amatuer Pokémon trainers blocking\n"
	.string "{COLOR GREEN}Team Proto{COLOR BLUE}'s path to glory.$"

ProtoHideoutB3F_Object_Skip_Text_12:
	.string "Skip: {COLOR BLUE}Your cloak wearing grunts are\n"
	.string "weak compared to me!$"

ProtoHideoutB3F_Object_Skip_Text_13:
	.string "???: {COLOR BLUE}Is that so...\p"
	.string "I would like to see for myself.$"

ProtoHideoutB3F_Object_Skip_Text_14:
	.string "Apollo: {COLOR BLUE}My name is {COLOR GREEN}Apollo{COLOR BLUE}, leader of {COLOR GREEN}Team\n"
	.string "Proto{COLOR BLUE}!\p"
	.string "Show me your strength, I want to see\n"
	.string "why you two are such a nuisance!$"

ProtoHideoutB3F_Object_Skip_Text_15:
	.string "It seems I underestimated you two...$"

ProtoHideoutB3F_Object_Skip_Text_16:
	.string "Quite the challenge indeed.$"

ProtoHideoutB3F_Object_Skip_Text_17:
	.string "Apollo: {COLOR BLUE}I'm quite surprised by the\n"
	.string "amount of skill you two displayed in\l"
	.string "that battle.\p"
	.string "I may have been defeated, but this is\n"
	.string "not the last of {COLOR GREEN}Team Proto{COLOR BLUE}.$"

ProtoHideoutB3F_Object_Skip_Text_18:
	.string "Skip: {COLOR BLUE}That guy sure was a little\n"
	.string "terrifying.\p"
	.string "But I beat them!\p"
	.string "Did you see that performance by me?\p"
	.string "Ha!\n"
	.string "I pretty much carried.\p"
	.string "Anyways, I'm out of here.\p"
	.string "I'm going to head over to {COLOR GREEN}Altos City{COLOR BLUE} and\n"
	.string "get my next gym badge!\p"
	.string "{COLOR DARK_GREY}Skip: {COLOR BLUE}See you around slowpoke!$"
