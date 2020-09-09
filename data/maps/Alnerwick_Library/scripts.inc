Alnerwick_Library_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlnerwickLibrary_OnTransition
	.byte 0

AlnerwickLibrary_OnTransition:
    call_if_set FLAG_ALNERWICKLIBRARY_THIEF, AlnerwickLibrary_Mapscript_Librarian
    end

AlnerwickLibrary_Object_Boy::
	msgbox AlnerwickLibrary_Object_Boy_Text_0, MSGBOX_NPC
	end


AlnerwickLibrary_Object_Girl::
	lock
	msgbox AlnerwickLibrary_Object_Girl_Text_0, MSGBOX_AUTOCLOSE
	faceplayer
	delay 5
	msgbox AlnerwickLibrary_Object_Girl_Text_1, MSGBOX_AUTOCLOSE
	applymovement 6, Common_Movement_WalkInPlaceUp
	waitmovement 0
	release
	end


AlnerwickLibrary_Object_FatMan::
	lock
	faceplayer
	msgbox AlnerwickLibrary_Object_FatMan_Text_0, MSGBOX_AUTOCLOSE
	applymovement 3, Common_Movement_WalkInPlaceUp
	waitmovement 0
	release
	end


AlnerwickLibrary_Object_Artist::
	lock
	faceplayer
	msgbox AlnerwickLibrary_Object_Artist_Text_0, MSGBOX_AUTOCLOSE
	applymovement 4, Common_Movement_WalkInPlaceUp
	waitmovement 0
	release
	end


AlnerwickLibrary_Mapscript_Librarian::
	setobjectxyperm 2, 1, 3
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
	return


AlnerwickLibrary_Trigger_Thief::
	compare VAR_ALNERWICKLIBRARY_THIEF, 1
	goto_if_eq AlnerwickLibrary_Trigger_Thief_1
	return

AlnerwickLibrary_Trigger_Thief_1:
	lockall
	special SpawnCameraObject
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 5
	goto_if_eq AlnerwickLibrary_Trigger_Thief_4
	compare VAR_TEMP_1, 6
	goto_if_eq AlnerwickLibrary_Trigger_Thief_5
	compare VAR_TEMP_1, 7
	goto_if_eq AlnerwickLibrary_Trigger_Thief_6
AlnerwickLibrary_Trigger_Thief_3:
	delay 5
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox AlnerwickLibrary_Trigger_Thief_Text_0, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox AlnerwickLibrary_Trigger_Thief_Text_1, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 1, AlnerwickLibrary_Thief_Movement_1
	waitmovement 0
	msgbox AlnerwickLibrary_Trigger_Thief_Text_2, MSGBOX_AUTOCLOSE
	applymovement 1, AlnerwickLibrary_Thief_Movement_0
	applymovement OBJ_EVENT_ID_CAMERA, AlnerwickLibrary_Thief_CMovement_3
	waitmovement 0
	compare VAR_TEMP_1, 6
	goto_if_eq AlnerwickLibrary_Trigger_Thief_11
	applymovement 1, AlnerwickLibrary_Thief_Movement_0_1
	waitmovement 0
	removeobject 1
	playse SE_KAIDAN
AlnerwickLibrary_Trigger_Thief_10:
	compare VAR_TEMP_1, 5
	goto_if_eq AlnerwickLibrary_Trigger_Thief_15
	compare VAR_TEMP_1, 6
	goto_if_eq AlnerwickLibrary_Trigger_Thief_16
	compare VAR_TEMP_1, 7
	goto_if_eq AlnerwickLibrary_Trigger_Thief_17
AlnerwickLibrary_Trigger_Thief_14:
	applymovement 2, AlnerwickLibrary_Thief_Movement_2
	playse SE_PIN
	waitmovement 0
	special RemoveCameraObject
	delay 15
	compare VAR_TEMP_1, 5
	goto_if_eq AlnerwickLibrary_Trigger_Thief_22
	compare VAR_TEMP_1, 6
	goto_if_eq AlnerwickLibrary_Trigger_Thief_23
	compare VAR_TEMP_1, 7
	goto_if_eq AlnerwickLibrary_Trigger_Thief_24
AlnerwickLibrary_Trigger_Thief_21:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	delay 10
	msgbox AlnerwickLibrary_Trigger_Thief_Text_4
	compare VAR_TEMP_1, 5
	goto_if_eq AlnerwickLibrary_Trigger_Thief_29
	compare VAR_TEMP_1, 6
	goto_if_eq AlnerwickLibrary_Trigger_Thief_30
	compare VAR_TEMP_1, 7
	goto_if_eq AlnerwickLibrary_Trigger_Thief_31
AlnerwickLibrary_Trigger_Thief_28:
	setflag FLAG_ALNERWICKLIBRARY_THIEF
	setvar VAR_ALNERWICKLIBRARY_THIEF, 2
	release
	end

AlnerwickLibrary_Trigger_Thief_4:
	applymovement OBJ_EVENT_ID_CAMERA, AlnerwickLibrary_Thief_CMovement_0
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_3

AlnerwickLibrary_Trigger_Thief_5:
	applymovement OBJ_EVENT_ID_CAMERA, AlnerwickLibrary_Thief_CMovement_1
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_3

AlnerwickLibrary_Trigger_Thief_6:
	applymovement OBJ_EVENT_ID_CAMERA, AlnerwickLibrary_Thief_CMovement_2
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_3

AlnerwickLibrary_Trigger_Thief_11:
	msgbox AlnerwickLibrary_Trigger_Thief_Text_3, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, AlnerwickLibrary_Thief_Movement_4
	waitmovement 0
	applymovement 1, AlnerwickLibrary_Thief_Movement_0_1
	waitmovement 0
	removeobject 1
	playse SE_KAIDAN
	goto AlnerwickLibrary_Trigger_Thief_10

AlnerwickLibrary_Trigger_Thief_15:
	applymovement OBJ_EVENT_ID_CAMERA, AlnerwickLibrary_Thief_CMovement_4
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_14

AlnerwickLibrary_Trigger_Thief_16:
	applymovement OBJ_EVENT_ID_CAMERA, AlnerwickLibrary_Thief_CMovement_5
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_14

AlnerwickLibrary_Trigger_Thief_17:
	applymovement OBJ_EVENT_ID_CAMERA, AlnerwickLibrary_Thief_CMovement_5
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_14

AlnerwickLibrary_Trigger_Thief_22:
	applymovement 2, AlnerwickLibrary_Thief_Movement_3_0
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_21

AlnerwickLibrary_Trigger_Thief_23:
	applymovement 2, AlnerwickLibrary_Thief_Movement_3_2
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_21

AlnerwickLibrary_Trigger_Thief_24:
	applymovement 2, AlnerwickLibrary_Thief_Movement_3_2
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_21

AlnerwickLibrary_Trigger_Thief_29:
	applymovement 2, AlnerwickLibrary_Thief_Movement_5_0
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_28

AlnerwickLibrary_Trigger_Thief_30:
	applymovement 2, AlnerwickLibrary_Thief_Movement_5_2
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_28

AlnerwickLibrary_Trigger_Thief_31:
	applymovement 2, AlnerwickLibrary_Thief_Movement_5_2
	waitmovement 0
	goto AlnerwickLibrary_Trigger_Thief_28


AlnerwickLibrary_Thief_Movement_0:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

AlnerwickLibrary_Thief_Movement_0_1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_left
	step_end

AlnerwickLibrary_Thief_Movement_1:
	emote_exclamation_mark
	delay_16
	walk_in_place_down
	step_end

AlnerwickLibrary_Thief_Movement_2:
	walk_in_place_right
	emote_exclamation_mark
	step_end

AlnerwickLibrary_Thief_Movement_3_0:
	walk_right
	walk_right
	step_end

AlnerwickLibrary_Thief_Movement_3_1:
	walk_down
	walk_right
	walk_right
	step_end

AlnerwickLibrary_Thief_Movement_3_2:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

AlnerwickLibrary_Thief_Movement_4:
	walk_fast_down
	walk_in_place_fast_up
	step_end

AlnerwickLibrary_Thief_Movement_5_0:
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

AlnerwickLibrary_Thief_Movement_5_1:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

AlnerwickLibrary_Thief_Movement_5_2:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

AlnerwickLibrary_Thief_CMovement_0:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

AlnerwickLibrary_Thief_CMovement_1:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

AlnerwickLibrary_Thief_CMovement_2:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

AlnerwickLibrary_Thief_CMovement_3:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	step_end

AlnerwickLibrary_Thief_CMovement_4:
	walk_up
	step_end

AlnerwickLibrary_Thief_CMovement_5:
	walk_down
	step_end

AlnerwickLibrary_Object_Boy_Text_0:
	.string "{COLOR BLUE}The {COLOR GREEN}Alnerwick Library{COLOR BLUE} is full of lots of\n"
	.string "information!\p"
	.string "Some of the books here go back over 200\n"
	.string "years!$"

AlnerwickLibrary_Object_Girl_Text_0:
	.string "{COLOR RED}Hmmm...$"

AlnerwickLibrary_Object_Girl_Text_1:
	.string "{COLOR RED}I can't seem to find {COLOR GREEN}The Great Pokémon\n"
	.string "War{COLOR RED} book...\p"
	.string "I think someone checked it out before\n"
	.string "me...$"

AlnerwickLibrary_Object_FatMan_Text_0:
	.string "{COLOR BLUE}To be quite honest, I've never checked\n"
	.string "out a book from here.\p"
	.string "Their return policies are really bad, so\n"
	.string "I usually read the title and consider\l"
	.string "that to be reading.$"

AlnerwickLibrary_Object_Artist_Text_0:
	.string "{COLOR RED}I would personally consider books to be\n"
	.string "art as well.\p"
	.string "Art is just telling a story through\n"
	.string "different mediums.$"

AlnerwickLibrary_Trigger_Thief_Text_0:
	.string "???: {COLOR BLUE}Wha' do ya mean I can't take this\n"
	.string "ol' dusty book?$"

AlnerwickLibrary_Trigger_Thief_Text_1:
	.string "Librarian: {COLOR RED}I'm sorry sir, but this book\n"
	.string "isn't able to be checked out.$"

AlnerwickLibrary_Trigger_Thief_Text_2:
	.string "???: {COLOR BLUE}Checked out!\p"
	.string "Bahaha!\p"
	.string "I'm not checkin' this out!$"

AlnerwickLibrary_Trigger_Thief_Text_3:
	.string "???: {COLOR BLUE}Move it kid!$"

AlnerwickLibrary_Trigger_Thief_Text_4:
	.string "Librarian: {COLOR RED}I'm sorry, about that ruckus.\n"
	.string "That man just stole one of the oldest\l"
	.string "books in this library here.\p"
	.string "That book is an ancient tome that\n"
	.string "describes the Legendary Pokémon\l"
	.string "{COLOR GREEN}Darkrai{COLOR RED}.\p"
	.string "{COLOR DARK_GREY}Librarian: {COLOR GREEN}Darkrai{COLOR RED} is an ancient Pokémon\n"
	.string "who haunts people's dreams, but the\l"
	.string "tome lacks a full translation.\p"
	.string "{COLOR DARK_GREY}Librarian:{COLOR RED} That thug is probably long\n"
	.string "gone at this point, and that tome is a\l"
	.string "loss cause.\p"
	.string "Don't worry, he'll be fined when I get\n"
	.string "that book back.$"
