BayportCity_LarsHouse_MapScripts::
	.byte 0


BayportCity_LarsHouse_Object_Woman::
	msgbox BayportCity_LarsHouse_Object_Woman_Text_0, MSGBOX_NPC
	end


BayportCity_LarsHouse_Trigger_LarsEvent::
	lockall
	getplayerxy VAR_TEMP_1, VAR_TEMP_0
	special SpawnCameraObject
	fadescreen FADE_TO_BLACK
	compare VAR_TEMP_0, 8
	goto_if_eq BayportCity_LarsHouse_Trigger_LarsEvent_2
	compare VAR_TEMP_0, 7
	goto_if_eq BayportCity_LarsHouse_Trigger_LarsEvent_3
BayportCity_LarsHouse_Trigger_LarsEvent_1:
	fadescreen FADE_FROM_BLACK
	delay 20
	msgbox BayportCity_LarsHouse_Trigger_LarsEvent_Text_0, MSGBOX_AUTOCLOSE
	delay 15
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox BayportCity_LarsHouse_Trigger_LarsEvent_Text_1, MSGBOX_AUTOCLOSE
	delay 20
	compare VAR_TEMP_0, 8
	goto_if_eq BayportCity_LarsHouse_Trigger_LarsEvent_7
	compare VAR_TEMP_0, 7
	goto_if_eq BayportCity_LarsHouse_Trigger_LarsEvent_8
BayportCity_LarsHouse_Trigger_LarsEvent_6:
	special RemoveCameraObject
	delay 20
	msgbox BayportCity_LarsHouse_Trigger_LarsEvent_Text_2, MSGBOX_AUTOCLOSE
	delay 15
	applymovement 1, Common_Movement_QuestionMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox BayportCity_LarsHouse_Trigger_LarsEvent_Text_3, MSGBOX_AUTOCLOSE
	delay 10
	compare VAR_TEMP_0, 8
	goto_if_eq BayportCity_LarsHouse_Trigger_LarsEvent_12
	compare VAR_TEMP_0, 7
	goto_if_eq BayportCity_LarsHouse_Trigger_LarsEvent_13
BayportCity_LarsHouse_Trigger_LarsEvent_11:
	removeobject 1
	playse SE_EXIT
	waitse
	setflag FLAG_BAYPORTCITY_LARSHOUSE_LARSEVENT
	setflag FLAG_BAYPORTCITY_WINGULL
	setvar VAR_CYPRESS_PROTO_EVENT_STATE, 3
	releaseall
	end

BayportCity_LarsHouse_Trigger_LarsEvent_2:
	applymovement OBJ_EVENT_ID_CAMERA, BayportCity_LarsHouse_Movement_0
	waitmovement 0
	goto BayportCity_LarsHouse_Trigger_LarsEvent_1

BayportCity_LarsHouse_Trigger_LarsEvent_3:
	applymovement OBJ_EVENT_ID_CAMERA, BayportCity_LarsHouse_Movement_1
	waitmovement 0
	goto BayportCity_LarsHouse_Trigger_LarsEvent_1

BayportCity_LarsHouse_Trigger_LarsEvent_7:
	applymovement 1, BayportCity_LarsHouse_Movement_2
	applymovement OBJ_EVENT_ID_CAMERA, BayportCity_LarsHouse_Movement_2_C
	waitmovement 0
	goto BayportCity_LarsHouse_Trigger_LarsEvent_6

BayportCity_LarsHouse_Trigger_LarsEvent_8:
	applymovement 1, BayportCity_LarsHouse_Movement_3
	applymovement OBJ_EVENT_ID_CAMERA, BayportCity_LarsHouse_Movement_3_C
	waitmovement 0
	goto BayportCity_LarsHouse_Trigger_LarsEvent_6

BayportCity_LarsHouse_Trigger_LarsEvent_12:
	applymovement 1, BayportCity_LarsHouse_Movement_4
	waitmovement 0
	goto BayportCity_LarsHouse_Trigger_LarsEvent_11

BayportCity_LarsHouse_Trigger_LarsEvent_13:
	applymovement 1, BayportCity_LarsHouse_Movement_5
	waitmovement 0
	goto BayportCity_LarsHouse_Trigger_LarsEvent_11


BayportCity_LarsHouse_Movement_0:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

BayportCity_LarsHouse_Movement_1:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fastest_down
	step_end

BayportCity_LarsHouse_Movement_2:
	walk_right
	walk_right
	walk_right
	step_end

BayportCity_LarsHouse_Movement_2_C:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BayportCity_LarsHouse_Movement_3:
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

BayportCity_LarsHouse_Movement_3_C:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

BayportCity_LarsHouse_Movement_4:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

BayportCity_LarsHouse_Movement_5:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

BayportCity_LarsHouse_Object_Woman_Text_0:
	.string "{COLOR RED}I'm {COLOR GREEN}Lars' Assistant{COLOR RED}.\p"
	.string "I help him keep the Villa clean whenever\n"
	.string "he stays here…\p"
	.string "He's naturally not a very clean person\n"
	.string "and likes to leave all of his research\l"
	.string "around the villa.$"

BayportCity_LarsHouse_Trigger_LarsEvent_Text_0:
	.string "Lars: {COLOR BLUE}……………………\p"
	.string "These police reports seem to line up\n"
	.string "with the ritualistic events for\l"
	.string "summoning {COLOR GREEN}Darkrai{COLOR BLUE} and {COLOR GREEN}Cresselia{COLOR BLUE}…$"

BayportCity_LarsHouse_Trigger_LarsEvent_Text_1:
	.string "Lars: {COLOR GREEN}{PLAYER}{COLOR BLUE}!\n"
	.string "I'm glad to see you right now!$"

BayportCity_LarsHouse_Trigger_LarsEvent_Text_2:
	.string "Lars: {COLOR BLUE}I know you're a busy kid right now,\n"
	.string "challenging all of the Pokémon Gyms in\l"
	.string "{COLOR GREEN}Ryoko{COLOR BLUE} -- but I just connected some\l"
	.string "dots with things going on in the region.\p"
	.string "There has been a surge in criminal\n"
	.string "activity throughout {COLOR GREEN}Ryoko{COLOR BLUE}, and\l"
	.string "coincidentally all crimes commited by a\l"
	.string "group known as {COLOR GREEN}Team Proto{COLOR BLUE} have been at\l"
	.string "locations that pertain information on\l"
	.string "summoning the Legendary Lunar Duo\l"
	.string "{COLOR GREEN}Darkrai{COLOR BLUE} and {COLOR GREEN}Cresselia{COLOR BLUE}.\p"
	.string "{COLOR DARK_GREY}Lars: {COLOR BLUE}That book you delivered to\n"
	.string "{COLOR GREEN}Professor Cypress{COLOR BLUE} is even more\l"
	.string "powerful than I thought.\p"
	.string "That {COLOR GREEN}Dorimtome{COLOR BLUE} cannot fall in the wrong\n"
	.string "hands!$"

BayportCity_LarsHouse_Trigger_LarsEvent_Text_3:
	.string "Lars: {COLOR BLUE}What?!\p"
	.string "{COLOR GREEN}Team Proto{COLOR BLUE} stole the {COLOR GREEN}Dorimtome{COLOR BLUE} from\n"
	.string "{COLOR GREEN}Professor Cypress{COLOR BLUE}?\p"
	.string "Oh no, this can't be good.\p"
	.string "We need to do something about this.\p"
	.string "I'm going to go talk to the Police to see\n"
	.string "if I can find further information on\l"
	.string "{COLOR GREEN}Team Proto's{COLOR BLUE} whereabouts.\p"
	.string "I'll be seeing you soon, {COLOR GREEN}{PLAYER}{COLOR BLUE}!$"
