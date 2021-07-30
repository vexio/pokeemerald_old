.set LOCALID_RIVAL, 1

LittlerootTown_BrendansHouse_2F_MapScripts:: @ 81F83E3
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
    map_script MAP_SCRIPT_ON_FRAME_TABLE, PlayersHouse_Mapscript2_Init
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_OnWarp
	.byte 0

LittlerootTown_BrendansHouse_2F_OnTransition: @ 81F83EE
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	call_if_lt LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	call_if_ge LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	call_if_eq PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckShouldUpdateBrendanPos:: @ 81F841A
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos
	compare VAR_BIRCH_LAB_STATE, 2
	goto_if_ge LittlerootTown_BrendansHouse_2F_EventScript_Ret
	goto LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos

LittlerootTown_BrendansHouse_2F_EventScript_TryUpdateBrendanPos:: @ 81F8433
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_Ret
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 2
	goto_if_ge LittlerootTown_MaysHouse_2F_EventScript_Ret  @ Odd that the MaysHouse equivalent was used here instead
	setobjectxyperm LOCALID_RIVAL, 0, 2
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_2F_EventScript_Ret:: @ 81F8456
	return

LittlerootTown_BrendansHouse_2F_EventScript_CheckSetReadyToMeetBrendan:: @ 81F8457
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan
	return

LittlerootTown_BrendansHouse_2F_EventScript_SetReadyToMeetBrendan:: @ 81F8464
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_BrendansHouse_2F_OnWarp: @ 81F846A
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_BrendansHouse_2F_EventScript_CheckInitDecor:: @ 81F8474
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq SecretBase_EventScript_InitDecorations
	end

LittlerootTown_BrendansHouse_2F_EventScript_RivalsPokeBall:: @ 81F8481
	lockall
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendan:: @ 81F8497
	delay 10
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	compare VAR_FACING, DIR_NORTH
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth
	compare VAR_FACING, DIR_SOUTH
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth
	compare VAR_FACING, DIR_WEST
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest
	compare VAR_FACING, DIR_EAST
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanNorth:: @ 81F8507
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanSouth:: @ 81F8536
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanWest:: @ 81F8565
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_MeetBrendanEast:: @ 81F8594
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox RivalsHouse_2F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_Movement_BrendanEnters: @ 81F85BC
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerNorth: @ 81F85C0
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCNorth: @ 81F85C6
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanNorth: @ 81F85CF
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerSouth: @ 81F85D7
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCSouth: @ 81F85DB
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanSouth: @ 81F85E2
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerWest: @ 81F85E8
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCWest: @ 81F85ED
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanWest: @ 81F85F6
	delay_8
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanApproachPlayerEast: @ 81F85FD
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_BrendanWalkToPCEast: @ 81F8604
	walk_up
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_BrendansHouse_2F_Movement_PlayerWatchBrendanEast: @ 81F8609
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_EventScript_PC:: @ 81F860D
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckPlayersPC:: @ 81F8626
	setvar VAR_0x8004, 1
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC:: @ 81F863F
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_CheckRivalsPC:: @ 81F864C
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

PlayersHouse_2F_EventScript_Notebook:: @ 81F8656
	msgbox PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

PlayersHouse_2F_EventScript_GameCube:: @ 81F865F
	msgbox PlayersHouse_2F_Text_ItsAGameCube, MSGBOX_SIGN
	end

PlayersHouse_2F_Text_ClockIsStopped: @ 81F8668
	.string "The clock is stopped…\p"
	.string "Better set it and start it!$"

PlayersHouse_2F_Text_HowDoYouLikeYourRoom: @ 81F869A
	.string "MOM: {PLAYER}, how do you like your\n"
	.string "new room?\p"
	.string "Good! Everything's put away neatly!\p"
	.string "They finished moving everything in\n"
	.string "downstairs, too.\p"
	.string "POKéMON movers are so convenient!\p"
	.string "Oh, you should make sure that\n"
	.string "everything's all there on your desk.$"

PlayersHouse_2F_Text_Notebook: @ 81F877F
	.string "{PLAYER} flipped open the notebook.\p"
	.string "ADVENTURE RULE NO. 1\n"
	.string "Open the MENU with START.\p"
	.string "ADVENTURE RULE NO. 2\n"
	.string "Record your progress with SAVE.\p"
	.string "The remaining pages are blank…$"

Common_Text_LookCloserAtMap: @ 81F8820
	.string "{PLAYER} took a closer look at the\n"
	.string "HOENN region map.$"

PlayersHouse_2F_Text_ItsAGameCube: @ 81F884F
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"

PlayersHouse_Mapscript2_Init::
	map_script_2 VAR_PLAYERSHOUSE_DADENTERSROOM, 0, PlayersHouse_Mapscript_DadEnterRoom
	.2byte 0

PlayersHouse_Mapscript_DadEnterRoom::
	compare VAR_PLAYERSHOUSE_DADENTERSROOM, 0
	goto_if_eq PlayersHouse_Mapscript_DadEnterRoom_1
	return

PlayersHouse_Mapscript_DadEnterRoom_1:
	lockall
	delay 40
	setobjectxy 1, 7, 3
	playse SE_KAIDAN
	applymovement 1, PlayersHouse_DadEnterRoom_Movement_0
	waitmovement 0
	playse SE_PIN
	delay 10
	msgbox PlayersHouse_Mapscript_DadEnterRoom_Text_0
	closemessage
	delay 10
	applymovement 1, PlayersHouse_DadEnterRoom_Movement_1
	waitmovement 0
	playse SE_KAIDAN
	removeobject 1
	setflag FLAG_PLAYERSHOUSE_DADENTERSROOM
	setvar VAR_PLAYERSHOUSE_DADENTERSROOM, 1
	setvar VAR_PLAYERSHOUSE_GETPOKEMON, 1
	setflag FLAG_CANVASTOWN_GETPOKEMON
	setflag FLAG_CANVASTOWN_DAD
	setflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end


PlayersHouse_DadEnterRoom_Movement_0:
	walk_in_place_slow_right
	delay_16
	walk_in_place_left
	delay_8
	emote_exclamation_mark
	step_end

PlayersHouse_DadEnterRoom_Movement_1:
	walk_in_place_slow_left
	step_end

PlayersHouse_Trigger_HasPlayerEmailed::
	compare VAR_PLAYERSHOUSE_HASPLAYEREMAILED, 0
	goto_if_eq PlayersHouse_Trigger_HasPlayerEmailed_1
	return

PlayersHouse_Trigger_HasPlayerEmailed_1:
	lockall
	delay 5
	msgbox PlayersHouse_Trigger_HasPlayerEmailed_Text_0
	closemessage
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, PlayersHouse_HasPlayerEmailed_Movement_0
	waitmovement 0
	releaseall
	end


PlayersHouse_HasPlayerEmailed_Movement_0:
	walk_down
	step_end

PlayersHouse_Script_PlayerEmail::
	lockall
	msgbox PlayersHouse_Script_PlayerEmail_Text_0
	delay 10
	playse SE_PC_ON
	setmetatile 0, 2, 639, 1
	special DrawWholeMapView
	msgbox PlayersHouse_Script_PlayerEmail_Text_1
	compare VAR_PLAYERSHOUSE_HASPLAYEREMAILED, 0
	goto_if_eq PlayersHouse_Script_PlayerEmail_1
	special BedroomPC
	waitstate
	releaseall
	end

PlayersHouse_Script_PlayerEmail_1:
	msgbox PlayersHouse_Script_PlayerEmail_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq PlayersHouse_Script_PlayerEmail_4
	closemessage
	delay 10
	playse SE_SEIKAI
	delay 5
	msgbox PlayersHouse_Script_PlayerEmail_Text_4
	setvar VAR_PLAYERSHOUSE_HASPLAYEREMAILED, 1
	delay 5
	msgbox PlayersHouse_Script_PlayerEmail_Text_5, MSGBOX_AUTOCLOSE
	delay 10
	closemessage
	playse SE_PC_OFF
	setmetatile 0, 2, 602, 1
	special DrawWholeMapView
	releaseall
	end

PlayersHouse_Script_PlayerEmail_4:
	msgbox PlayersHouse_Script_PlayerEmail_Text_3, MSGBOX_AUTOCLOSE
	delay 10
	closemessage
	playse SE_PC_OFF
	setmetatile 0, 2, 602, 1
	special DrawWholeMapView
	releaseall
	end


PlayersHouse_Mapscript_DadEnterRoom_Text_0:
	.string "Dad: {COLOR BLUE}Good morning {PLAYER}!\p"
	.string "{COLOR DARK_GREY}Dad: {COLOR BLUE}Today is the big day!\n"
	.string "Today is the day that the {COLOR GREEN}Ryoko\l"
	.string "Pokémon League{COLOR BLUE} is open for trainers!\p"
	.string "{COLOR DARK_GREY}Dad: {COLOR BLUE}And... I have a surprise for you and\n"
	.string "your friend, {COLOR GREEN}Skip{COLOR BLUE}!\p"
	.string "Send him a little message on your\n"
	.string "computer and come outside!$"

PlayersHouse_Trigger_HasPlayerEmailed_Text_0:
	.string "Dad: {COLOR BLUE}Have you emailed your friend, {COLOR GREEN}Skip{COLOR BLUE},\n"
	.string "yet?$"

PlayersHouse_Script_PlayerEmail_Text_0:
	.string "BOOTING UP PERSONAL COMPUTER...$"

PlayersHouse_Script_PlayerEmail_Text_1:
	.string "WELCOME {PLAYER}!$"

PlayersHouse_Script_PlayerEmail_Text_2:
	.string "EMAIL {COLOR GREEN}SKIP{COLOR DARK_GREY}?$"

PlayersHouse_Script_PlayerEmail_Text_3:
	.string "SHUTTING DOWN PERSONAL COMPUTER.\n"
	.string "GOODBYE.$"

PlayersHouse_Script_PlayerEmail_Text_4:
	.string "SENT EMAIL TO {COLOR GREEN}SKIP{COLOR DARK_GREY}.$"

PlayersHouse_Script_PlayerEmail_Text_5:
	.string "NO OTHER TASKS LEFT.\p"
	.string "SHUTTING DOWN PERSONAL COMPUTER.\n"
	.string "GOODBYE.$"
