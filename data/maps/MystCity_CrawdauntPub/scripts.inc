MystCity_CrawdauntPub_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CrawdauntPub_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CrawdauntPub_OnFrameTable
	map_script MAP_SCRIPT_ON_LOAD, CrawdauntPub_OnLoad
	.byte 0

CrawdauntPub_OnTransition:
	compare VAR_CYPRESS_PROTO_EVENT_STATE, 6
	call_if_eq CrawdauntPub_Mapscript_LoadPositions6
	compare VAR_CYPRESS_PROTO_EVENT_STATE, 7
	call_if_eq CrawdauntPub_Mapscript_LoadPositions7
	end

CrawdauntPub_OnFrameTable::
	map_script_2 VAR_CYPRESS_PROTO_EVENT_STATE, 6, CrawdauntPub_Mapscript_Investigation
	.2byte 0

CrawdauntPub_OnLoad:
	call_if_set FLAG_CRAWDAUNTPUB_BARTENDER, CrawdauntPub_Mapscript_OnLoad_OpenBarDoor
	end

CrawdauntPub_Mapscript_OnLoad_OpenBarDoor::
	setmetatile 11, 11, 539, 0
	setmetatile 11, 10, 575, 0
	setmetatile 11, 9, 567, 0
	return


CrawdauntPub_Mapscript_LoadPositions6::
	setobjectxyperm 12, 6, 9
	setobjectmovementtype 12, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return


CrawdauntPub_Mapscript_LoadPositions7::
	setobjectxyperm 12, 5, 8
	setobjectmovementtype 12, MOVEMENT_TYPE_LOOK_AROUND
	return


CrawdauntPub_Mapscript_Investigation::
	lockall
	applymovement 12, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox CrawdauntPub_Mapscript_Investigation_Text_0
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox CrawdauntPub_Mapscript_Investigation_Text_1
	applymovement 12, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox CrawdauntPub_Mapscript_Investigation_Text_2
	applymovement 1, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox CrawdauntPub_Mapscript_Investigation_Text_3, MSGBOX_AUTOCLOSE
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 10
	applymovement 12, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox CrawdauntPub_Mapscript_Investigation_Text_4, MSGBOX_AUTOCLOSE
	applymovement 12, CrawdauntPub_Investigation_Movement_0
	waitmovement 0
	msgbox CrawdauntPub_Mapscript_Investigation_Text_5, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 12, CrawdauntPub_Investigation_Movement_1
	waitmovement 0
	setobjectmovementtype 12, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_CYPRESS_PROTO_EVENT_STATE, 7
	releaseall
	end


CrawdauntPub_Investigation_Movement_0:
	walk_left
	walk_down
	walk_down
	step_end

CrawdauntPub_Investigation_Movement_1:
	walk_up
	walk_up
	walk_up
	step_end

CrawdauntPub_Object_Sailor_1::
	msgbox CrawdauntPub_Object_Sailor_1_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Object_Sailor_2::
	goto_if_set FLAG_CRAWDAUNTPUB_SODA_POP_DUDE, CrawdauntPub_Object_Sailor_2_2
	lock
	faceplayer
	msgbox CrawdauntPub_Object_Sailor_2_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq CrawdauntPub_Object_Sailor_2_4
	msgbox CrawdauntPub_Object_Sailor_2_Text_3, MSGBOX_AUTOCLOSE
	giveitem ITEM_SODA_POP, 5
	setflag FLAG_CRAWDAUNTPUB_SODA_POP_DUDE
	release
	end

CrawdauntPub_Object_Sailor_2_2:
	msgbox CrawdauntPub_Object_Sailor_2_Text_0, MSGBOX_NPC
	release
	end

CrawdauntPub_Object_Sailor_2_4:
	msgbox CrawdauntPub_Object_Sailor_2_Text_2, MSGBOX_AUTOCLOSE
	release
	end


CrawdauntPub_Object_Sailor_3::
	compare VAR_CYPRESS_PROTO_EVENT_STATE, 7
	goto_if_eq CrawdauntPub_Object_Sailor_3_1
	msgbox CrawdauntPub_Object_Sailor_3_Text_1, MSGBOX_NPC
	end

CrawdauntPub_Object_Sailor_3_1:
	msgbox CrawdauntPub_Object_Sailor_3_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Object_Man_1::
	msgbox CrawdauntPub_Object_Man_1_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Object_Man_2::
	compare VAR_CYPRESS_PROTO_EVENT_STATE, 7
	goto_if_eq CrawdauntPub_Object_Man_2_1
	msgbox CrawdauntPub_Object_Man_2_Text_1, MSGBOX_NPC
	end

CrawdauntPub_Object_Man_2_1:
	msgbox CrawdauntPub_Object_Man_2_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Object_FatMan::
	msgbox CrawdauntPub_Object_FatMan_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Object_Bartender::
	compare VAR_CYPRESS_PROTO_EVENT_STATE, 7
	goto_if_eq CrawdauntPub_Object_Bartender_1
	msgbox CrawdauntPub_Object_Bartender_Text_6, MSGBOX_NPC
	end

CrawdauntPub_Object_Bartender_1:
	lockall
	faceplayer
	msgbox CrawdauntPub_Object_Bartender_Text_0
	applymovement 7, CrawdauntPub_Bartender_Movement_0
	waitmovement 0
	msgbox CrawdauntPub_Object_Bartender_Text_1, MSGBOX_AUTOCLOSE
	applymovement 12, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement 12, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox CrawdauntPub_Object_Bartender_Text_2, MSGBOX_AUTOCLOSE
	applymovement 12, CrawdauntPub_Bartender_Movement_1
	waitmovement 0
	msgbox CrawdauntPub_Object_Bartender_Text_3, MSGBOX_AUTOCLOSE
	applymovement 7, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox CrawdauntPub_Object_Bartender_Text_4, MSGBOX_AUTOCLOSE
	applymovement 7, CrawdauntPub_Bartender_Movement_2
	waitmovement 0
	playse SE_KAIDAN
	waitse
	applymovement 12, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox CrawdauntPub_Object_Bartender_Text_5, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 12, CrawdauntPub_Bartender_Movement_3
	waitmovement 0
	setmetatile 11, 11, 539, 0
	setmetatile 11, 10, 575, 0
	setmetatile 11, 9, 567, 0
	special DrawWholeMapView
	playse SE_DOOR
	waitse
	applymovement 12, CrawdauntPub_Bartender_Movement_4
	waitmovement 0
	playse SE_KAIDAN
	waitse
	setflag FLAG_CRAWDAUNTPUB_BARTENDER
	setvar VAR_CYPRESS_PROTO_EVENT_STATE, 8
	removeobject 12
	removeobject 7
	releaseall
	end


CrawdauntPub_Bartender_Movement_0:
	face_up
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_left
	step_end

CrawdauntPub_Bartender_Movement_1:
	walk_right
	step_end

CrawdauntPub_Bartender_Movement_2:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end

CrawdauntPub_Bartender_Movement_3:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	step_end

CrawdauntPub_Bartender_Movement_4:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end

CrawdauntPub_Object_Cook_1::
	msgbox CrawdauntPub_Object_Cook_1_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Object_Cook_2::
	msgbox CrawdauntPub_Object_Cook_2_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Object_Cook_3::
	msgbox CrawdauntPub_Object_Cook_3_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Object_Cook_4::
	msgbox CrawdauntPub_Object_Cook_4_Text_0, MSGBOX_NPC
	end


CrawdauntPub_Mapscript_Investigation_Text_0:
	.string "Skip: {COLOR BLUE}Answer my question!\p"
	.string "Have you seen any suspicious people in\n"
	.string "this pub?$"

CrawdauntPub_Mapscript_Investigation_Text_1:
	.string "Sailor: {COLOR BLUE}For the last time kid, I ain't\n"
	.string "tellin' you anything!\p"
	.string "It's better to keep that information to\n"
	.string "yourself.\p"
	.string "You don't know who you're getting\n"
	.string "involved with!$"

CrawdauntPub_Mapscript_Investigation_Text_2:
	.string "Skip: {COLOR BLUE}Are you implying that you know who\n"
	.string "they are?$"

CrawdauntPub_Mapscript_Investigation_Text_3:
	.string "Sailor: {COLOR BLUE}No kid!\n"
	.string "Because I stay out of that business!\p"
	.string "Now scram before I make you!$"

CrawdauntPub_Mapscript_Investigation_Text_4:
	.string "Skip: {COLOR BLUE}There you are slowpoke!$"

CrawdauntPub_Mapscript_Investigation_Text_5:
	.string "Skip: {COLOR BLUE}None of these guys will talk!\p"
	.string "They're all hard-heads who are afraid\n"
	.string "of those {COLOR GREEN}Team Proto{COLOR BLUE} goons.\p"
	.string "We need to try to squeeze the\n"
	.string "information out of someone in here!\p"
	.string "You do some talking for a minute, I need\n"
	.string "to cool off.$"

CrawdauntPub_Object_Sailor_1_Text_0:
	.string "{COLOR BLUE}What's a kid like you doing in {COLOR GREEN}The\n"
	.string "Crawdaunt Pub{COLOR BLUE}?\p"
	.string "Lookin' for trouble?\p"
	.string "Scram kid!$"

CrawdauntPub_Object_Sailor_2_Text_0:
	.string "{COLOR BLUE}How those Soda's tastin'?$"

CrawdauntPub_Object_Sailor_2_Text_1:
	.string "{COLOR BLUE}Hey kid!\n"
	.string "Want a beer?$"

CrawdauntPub_Object_Sailor_2_Text_2:
	.string "{COLOR BLUE}Bahahaha!\p"
	.string "You think you're slick kid?\p"
	.string "I ain't giving you any beer!\p"
	.string "Now get lost!$"

CrawdauntPub_Object_Sailor_2_Text_3:
	.string "{COLOR BLUE}Good answer!\p"
	.string "Here, take these.\n"
	.string "I don't want 'em.$"

CrawdauntPub_Object_Sailor_3_Text_0:
	.string "{COLOR BLUE}Whadda want?\p"
	.string "............\n"
	.string "............\p"
	.string "Bad guys eh?\p"
	.string "Nope.\p"
	.string "I keep my mouth shut around here kid...$"

CrawdauntPub_Object_Sailor_3_Text_1:
	.string "{COLOR BLUE}Urgh...\p"
	.string "Comin' here after working at {COLOR GREEN}Bayport\n"
	.string "Harbour{COLOR BLUE} is always a relief...$"

CrawdauntPub_Object_Man_1_Text_0:
	.string "{COLOR BLUE}Are you a trainer?\p"
	.string "My son just recently left home to take\n"
	.string "on the {COLOR GREEN}Ryoko Pokémon League{COLOR BLUE}.\p"
	.string "I wonder how he's doing...$"

CrawdauntPub_Object_Man_2_Text_0:
	.string "{COLOR BLUE}What kid?\p"
	.string "............\n"
	.string "............\p"
	.string "Kid, I know you're young, but you\n"
	.string "shouldn't be messing with those people.$"

CrawdauntPub_Object_Man_2_Text_1:
	.string "{COLOR BLUE}Will you grab me another beer?$"

CrawdauntPub_Object_FatMan_Text_0:
	.string "Zzzzzzzz...\p"
	.string "The Fat Man is sleeping.$"

CrawdauntPub_Object_Bartender_Text_0:
	.string "Bartender: {COLOR BLUE}Sorry kid, we don't serve\n"
	.string "min--\p"
	.string "Huh?\p"
	.string "Uhh... {COLOR GREEN}Team Proto{COLOR BLUE} you say?$"

CrawdauntPub_Object_Bartender_Text_1:
	.string "Bartender: {COLOR BLUE}Who are you, kid?$"

CrawdauntPub_Object_Bartender_Text_2:
	.string "Skip: {COLOR BLUE}I knew someone would budge!$"

CrawdauntPub_Object_Bartender_Text_3:
	.string "Skip: {COLOR BLUE}What do you know about {COLOR GREEN}Team\n"
	.string "Proto{COLOR BLUE}?\p"
	.string "Spit it out!$"

CrawdauntPub_Object_Bartender_Text_4:
	.string "Bartender: {COLOR BLUE}I-I... uhh...$"

CrawdauntPub_Object_Bartender_Text_5:
	.string "Skip: {COLOR BLUE}He's getting away!\p"
	.string "I'm going after him!$"

CrawdauntPub_Object_Bartender_Text_6:
	.string "{COLOR BLUE}Sorry kid, we don't serve minors here.\p"
	.string "Move along, I got customers to serve.$"

CrawdauntPub_Object_Cook_1_Text_0:
	.string "{COLOR BLUE}Hey hey!\n"
	.string "Watch it kid!\p"
	.string "Make sure to shout when you're coming\n"
	.string "through the kitchen!$"

CrawdauntPub_Object_Cook_2_Text_0:
	.string "{COLOR BLUE}Sleeves up when you're in the kitchen!\p"
	.string "Don't want yourself getting burned, do\n"
	.string "ya?$"

CrawdauntPub_Object_Cook_3_Text_0:
	.string "{COLOR BLUE}Hm?\n"
	.string "The staircase in the corner?\p"
	.string "............\p"
	.string "I don't know what you're talking about...\p"
	.string "Anyways, back to work!$"

CrawdauntPub_Object_Cook_4_Text_0:
	.string "{COLOR BLUE}Hmmm...\p"
	.string "I can't find the lettuce...$"
