OldaleTown_MapScripts:: @ 81E8EA2
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition: @ 81E8EA8
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	call AlnerwickCity_Mapscript_OfficerLocations
	//call_if_set FLAG_ALNERWICKCITY_OFFICER_1, AlnerwickCity_Mapscript_OfficerLocations
	//call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
	//call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
	//call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
	end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState:: @ 81E8ECC
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_BlockWestEntrance:: @ 81E8ED2
	setobjectxyperm 3, 1, 11
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_MoveMartEmployee:: @ 81E8EDE
	setobjectxyperm 2, 13, 14
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_CitySign:: @ 81E8EEA
	msgbox OldaleTown_Text_CitySign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl:: @ 81E8EF3
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee:: @ 81E8EFC
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	playbgm MUS_TSURETEK, 0
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
	end

OldaleTown_EventScript_GoToMartSouth:: @ 81E8F47
	applymovement 2, OldaleTown_Movement_EmployeeSouth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth:: @ 81E8F5E
	applymovement 2, OldaleTown_Movement_EmployeeNorth
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast:: @ 81E8F75
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement 2, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_ExplainPokemonMart:: @ 81E8F8C
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_EventScript_BagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_ExplainPotion:: @ 81E8FB9
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_BagIsFull:: @ 81E8FC3
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_EmployeeEast: @ 81E8FCE
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_EmployeeSouth: @ 81E8FD7
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_EmployeeNorth: @ 81E8FE2
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_Unknown1: @ 81E8FEB
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_PlayerEast: @ 81E8FF9
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth: @ 81E9001
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth: @ 81E900B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Unknown2: @ 81E9013
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_FootprintsMan:: @ 81E901F
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OldaleTown_EventScript_BlockedPath:: @ 81E903F
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerStepBack
	applymovement 3, OldaleTown_Movement_BackUp
	waitmovement 0
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement 3, OldaleTown_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_NotBlockingPath:: @ 81E9066
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_Rival:: @ 81E9070
	lockall
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger1:: @ 81E9086
	lockall
	applymovement 4, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger2:: @ 81E90A6
	lockall
	applymovement 4, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger3:: @ 81E90C6
	lockall
	applymovement 4, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_ShowRivalMessage:: @ 81E90E6
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq OldaleTown_EventScript_ShowMayMessage
	compare VAR_RESULT, FEMALE
	goto_if_eq OldaleTown_EventScript_ShowBrendanMessage
	end

OldaleTown_EventScript_ShowMayMessage:: @ 81E90FE
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_ShowBrendanMessage:: @ 81E910C
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_RivalFinish:: @ 81E911A
	closemessage
	compare VAR_0x8009, 0
	call_if_eq OldaleTown_EventScript_DoExitMovement1
	compare VAR_0x8009, 1
	call_if_eq OldaleTown_EventScript_DoExitMovement2
	applymovement 4, OldaleTown_Movement_RivalExit
	waitmovement 0
	removeobject 4
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

OldaleTown_EventScript_DoExitMovement1:: @ 81E9148
	compare VAR_FACING, DIR_SOUTH
	goto_if_ne OldaleTown_EventScript_DoExitMovement2
	applymovement 4, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_EventScript_DoExitMovement2:: @ 81E915E
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_WatchRivalExit
	applymovement 4, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_Movement_RivalApproachPlayer1: @ 81E9170
	walk_left
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer2: @ 81E9173
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer3: @ 81E9175
	face_left
	step_end

OldaleTown_Movement_RivalExit: @ 81E9177
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_WatchRivalExit: @ 81E917E
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

OldaleTown_Movement_PlayerStepBack: @ 81E9182
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp: @ 81E9185
	walk_fast_up
	walk_in_place_fastest_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition: @ 81E918B
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress: @ 81E918E
	.string "I want to take a rest, so I'm saving my\n"
	.string "progress.$"

OldaleTown_Text_IWorkAtPokemonMart: @ 81E91C0
	.string "Hi!\n"
	.string "I work at a POKéMON MART.\p"
	.string "Can I get you to come with me?$"

OldaleTown_Text_ThisIsAPokemonMart: @ 81E91FD
	.string "This is a POKéMON MART.\n"
	.string "Just look for our blue roof.\p"
	.string "We sell a variety of goods including\n"
	.string "POKé BALLS for catching POKéMON.\p"
	.string "Here, I'd like you to have this as\n"
	.string "a promotional item.$"

OldaleTown_Text_PotionExplanation: @ 81E92AF
	.string "A POTION can be used anytime, so it's\n"
	.string "even more useful than a POKéMON CENTER\l"
	.string "in certain situations.$"

OldaleTown_Text_WaitDontComeInHere: @ 81E9313
	.string "Aaaaah! Wait!\n"
	.string "Please don't come in here.\p"
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_DiscoveredFootprints: @ 81E939A
	.string "I just discovered the footprints of\n"
	.string "a rare POKéMON!\p"
	.string "Wait until I finish sketching\n"
	.string "them, okay?$"

OldaleTown_Text_FinishedSketchingFootprints: @ 81E93F8
	.string "I finished sketching the footprints of\n"
	.string "a rare POKéMON.\p"
	.string "But it turns out they were only my\n"
	.string "own footprints…$"

OldaleTown_Text_MayLetsGoBack: @ 81E9462
	.string "MAY: {PLAYER}{KUN}!\n"
	.string "Over here!\l"
	.string "Let's hurry home!$"

OldaleTown_Text_BrendanLetsGoBack: @ 81E948A
	.string "BRENDAN: I'm heading back to my dad's\n"
	.string "LAB now.\l"
	.string "{PLAYER}, you should hustle back, too.$"

OldaleTown_Text_CitySign: @ 81E94DA
	.string "OLDALE TOWN\n"
	.string "“Where things start off scarce.”$"

AlnerwickCity_Mapscript_OfficerLocations::
	compare VAR_ALNERWICKLIBRARY_THIEF, 1
	goto_if_ge AlnerwickCity_Mapscript_OfficerLocations_1
	return

AlnerwickCity_Mapscript_OfficerLocations_1:
	setobjectxyperm 6, 9, 23
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_RIGHT
	return


AlnerwickCity_Object_Officer_1::
	msgbox AlnerwickCity_Object_Officer_1_Text_0, MSGBOX_NPC
	end


AlnerwickCity_Object_Officer_2::
	msgbox AlnerwickCity_Object_Officer_2_Text_0, MSGBOX_NPC
	end


AlnerwickCity_Sign_TownSign::
	msgbox AlnerwickCity_Sign_TownSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


AlnerwickCity_Sign_Library::
	msgbox AlnerwickCity_Sign_Library_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


AlnerwickCity_Object_Youngster::
	msgbox AlnerwickCity_Object_Youngster_Text_0, MSGBOX_NPC
	end


AlnerwickCity_Object_Maniac::
	msgbox AlnerwickCity_Object_Maniac_Text_0, MSGBOX_NPC
	end


AlnerwickCity_Object_Girl_1::
	msgbox AlnerwickCity_Object_Girl_1_Text_0, MSGBOX_NPC
	end


AlnerwickCity_Object_Girl_2::
	msgbox AlnerwickCity_Object_Girl_2_Text_0, MSGBOX_NPC
	end


AlnerwickCity_Trigger_PoliceOfficer::
	compare VAR_ALNERWICKLIBRARY_THIEF, 0
	goto_if_eq AlnerwickCity_Trigger_PoliceOfficer_1
	return

AlnerwickCity_Trigger_PoliceOfficer_1:
	lockall
	applymovement 6, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox AlnerwickCity_Trigger_PoliceOfficer_Text_0, MSGBOX_AUTOCLOSE
	delay 10
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 10
	goto_if_eq AlnerwickCity_Trigger_PoliceOfficer_4
	compare VAR_TEMP_0, 11
	goto_if_eq AlnerwickCity_Trigger_PoliceOfficer_5
	compare VAR_TEMP_0, 12
	goto_if_eq AlnerwickCity_Trigger_PoliceOfficer_6
AlnerwickCity_Trigger_PoliceOfficer_3:
	msgbox AlnerwickCity_Trigger_PoliceOfficer_Text_1, MSGBOX_AUTOCLOSE
	compare VAR_TEMP_0, 10
	goto_if_eq AlnerwickCity_Trigger_PoliceOfficer_11
	compare VAR_TEMP_0, 11
	goto_if_eq AlnerwickCity_Trigger_PoliceOfficer_12
	compare VAR_TEMP_0, 12
	goto_if_eq AlnerwickCity_Trigger_PoliceOfficer_13
AlnerwickCity_Trigger_PoliceOfficer_10:
	setvar VAR_ALNERWICKLIBRARY_THIEF, 1
	releaseall
	end

AlnerwickCity_Trigger_PoliceOfficer_4:
	applymovement 6, AlnerwickCity_PoliceOfficer_Movement_0
	waitmovement 0
	goto AlnerwickCity_Trigger_PoliceOfficer_3

AlnerwickCity_Trigger_PoliceOfficer_5:
	applymovement 6, AlnerwickCity_PoliceOfficer_Movement_1
	waitmovement 0
	goto AlnerwickCity_Trigger_PoliceOfficer_3

AlnerwickCity_Trigger_PoliceOfficer_6:
	applymovement 6, AlnerwickCity_PoliceOfficer_Movement_2
	waitmovement 0
	goto AlnerwickCity_Trigger_PoliceOfficer_3

AlnerwickCity_Trigger_PoliceOfficer_11:
	applymovement 6, AlnerwickCity_PoliceOfficer_Movement_0_0
	waitmovement 0
	goto AlnerwickCity_Trigger_PoliceOfficer_10

AlnerwickCity_Trigger_PoliceOfficer_12:
	applymovement 6, AlnerwickCity_PoliceOfficer_Movement_1_0
	waitmovement 0
	goto AlnerwickCity_Trigger_PoliceOfficer_10

AlnerwickCity_Trigger_PoliceOfficer_13:
	applymovement 6, AlnerwickCity_PoliceOfficer_Movement_0_0
	waitmovement 0
	goto AlnerwickCity_Trigger_PoliceOfficer_10


AlnerwickCity_PoliceOfficer_Movement_0:
	walk_down
	walk_down
	walk_in_place_left
	step_end

AlnerwickCity_PoliceOfficer_Movement_1:
	walk_down
	step_end

AlnerwickCity_PoliceOfficer_Movement_2:
	walk_down
	walk_down
	walk_in_place_right
	step_end

AlnerwickCity_PoliceOfficer_Movement_0_0:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_in_place_right
	step_end

AlnerwickCity_PoliceOfficer_Movement_1_0:
	walk_up
	walk_left
	walk_left
	walk_in_place_right
	step_end

AlnerwickCity_Object_Officer_1_Text_0:
	.string "Officer: {COLOR BLUE}If you see anything\n"
	.string "suspicious, please inform an Officer.$"

AlnerwickCity_Object_Officer_2_Text_0:
	.string "Officer: {COLOR BLUE}There's been reports of a\n"
	.string "suspicious man in the city here.\p"
	.string "No one is leaving here until he's been\n"
	.string "reported to an Officer.$"

AlnerwickCity_Sign_TownSign_Text_0:
	.string "{COLOR LIGHT_GREEN}Alnerwick City\p"
	.string "{COLOR DARK_GREY}“A City of History”$"

AlnerwickCity_Sign_Library_Text_0:
	.string "Alnerwick Library$"

AlnerwickCity_Object_Youngster_Text_0:
	.string "{COLOR BLUE}When your Pokémon is low on health, it's\n"
	.string "always good to come to a Pokémon\l"
	.string "Center to heal up your partners.$"

AlnerwickCity_Object_Maniac_Text_0:
	.string "{COLOR BLUE}There are people inside this house...\p"
	.string "But I don't see an entrance...$"

AlnerwickCity_Object_Girl_1_Text_0:
	.string "{COLOR RED}The library in this city is full of\n"
	.string "history!\p"
	.string "You should definitely check it out!$"

AlnerwickCity_Object_Girl_2_Text_0:
	.string "{COLOR GREEN}Ryoko{COLOR RED} is such a beautiful region!\p"
	.string "The biome diversity is immense!$"

AlnerwickCity_Trigger_PoliceOfficer_Text_0:
	.string "Officer: {COLOR BLUE}Hey!$"

AlnerwickCity_Trigger_PoliceOfficer_Text_1:
	.string "Officer: {COLOR BLUE}We've been told that there's\n"
	.string "been some suspicious people around\l"
	.string "town.\p"
	.string "If you see anyone, please tell us\n"
	.string "immediately.$"
