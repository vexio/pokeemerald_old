.set LOCALID_NURSE, 1

LilycoveCity_PokemonCenter_1F_MapScripts:: @ 821C5B2
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LilycoveCity_PokemonCenter_1F_OnTransition: @ 821C5BD
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx
	end

@ SetLilycoveLadyGfx returns TRUE if its the Contest Lady
LilycoveCity_PokemonCenter_1F_EventScript_SetLilycoveLadyGfx:: @ 821C5C6
	special SetLilycoveLadyGfx
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon
	compare VAR_RESULT, TRUE
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon
	end

LilycoveCity_PokemonCenter_1F_EventScript_HideContestLadyMon:: @ 821C5E0
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_ShowContestLadyMon:: @ 821C5E4
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_CONTEST_LADY_MON
	end

LilycoveCity_PokemonCenter_1F_EventScript_Nurse:: @ 821C5E8
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_Boy:: @ 821C5F6
	msgbox LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon, MSGBOX_NPC
	end

LilycoveCity_PokemonCenter_1F_EventScript_Maniac:: @ 821C5FF
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone
	msgbox LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_ManiacBadTeamGone:: @ 821C614
	msgbox LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels, MSGBOX_DEFAULT
	release
	end

LilycoveCity_PokemonCenter_1F_Text_HowManyKindsOfPokemon: @ 821C61E
	.string "I wonder how many kinds of POKéMON\n"
	.string "there are in the world.\p"
	.string "It'd be great to cross seas and\n"
	.string "trade POKéMON with people far away.$"

LilycoveCity_PokemonCenter_1F_Text_HeardAboutRottenScoundrels: @ 821C69D
	.string "I've been hearing about some rotten\n"
	.string "scoundrels who steal POKéMON and rip\l"
	.string "off METEORITES.$"

LilycoveCity_PokemonCenter_1F_Text_HaventSeenRottenScoundrels: @ 821C6F6
	.string "Those rotten scoundrels who steal\n"
	.string "POKéMON and rip off METEORITES…\p"
	.string "I haven't seen them around recently.$"

MystCity_PokemonCenter_LarsEvent::
	lock
	msgbox MystCity_PokemonCenter_LarsEvent_Text_0, MSGBOX_AUTOCLOSE
	delay 10
	faceplayer
	delay 10
	applymovement 4, Common_Movement_ExclamationMark
	playse SE_PIN
	waitse
	waitmovement 0
	msgbox MystCity_PokemonCenter_LarsEvent_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq MystCity_PokemonCenter_LarsEvent_2
	msgbox MystCity_PokemonCenter_LarsEvent_Text_3, MSGBOX_AUTOCLOSE
MystCity_PokemonCenter_LarsEvent_1:
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq MystCity_PokemonCenter_LarsEvent_6
	compare VAR_RESULT, DIR_WEST
	goto_if_eq MystCity_PokemonCenter_LarsEvent_7
	compare VAR_RESULT, DIR_EAST
	goto_if_eq MystCity_PokemonCenter_LarsEvent_8
MystCity_PokemonCenter_LarsEvent_5:
	removeobject 4
	playse SE_EXIT
	waitse
	delay 10
	applymovement 5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MystCity_PokemonCenter_LarsEvent_Text_4, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 5, MystCity_PokemonCenter_LarsEvent_Movement_2
	waitmovement 0
	removeobject 5
	playse SE_EXIT
	waitse
	setflag FLAG_MYSTCITY_POKEMONCENTER_LARSEVENT
	setvar VAR_CYPRESS_PROTO_EVENT_STATE, 1
	setflag FLAG_BAYPORTCITY_LARSHOUSE_LARSEVENT
	release
	end

MystCity_PokemonCenter_LarsEvent_2:
	msgbox MystCity_PokemonCenter_LarsEvent_Text_2, MSGBOX_AUTOCLOSE
	goto MystCity_PokemonCenter_LarsEvent_1

MystCity_PokemonCenter_LarsEvent_6:
	applymovement 4, MystCity_PokemonCenter_LarsEvent_Movement_0
	waitmovement 0
	goto MystCity_PokemonCenter_LarsEvent_5

MystCity_PokemonCenter_LarsEvent_7:
	applymovement 4, MystCity_PokemonCenter_LarsEvent_Movement_1
	waitmovement 0
	goto MystCity_PokemonCenter_LarsEvent_5

MystCity_PokemonCenter_LarsEvent_8:
	applymovement 4, MystCity_PokemonCenter_LarsEvent_Movement_1
	waitmovement 0
	goto MystCity_PokemonCenter_LarsEvent_5


MystCity_PokemonCenter_LarsEvent_Movement_0:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

MystCity_PokemonCenter_LarsEvent_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MystCity_PokemonCenter_LarsEvent_Movement_2:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	step_end

MystCity_PokemonCenter_Object_Grunt::
	lock
	faceplayer
	msgbox MystCity_PokemonCenter_Object_Grunt_Text_0, MSGBOX_AUTOCLOSE
	applymovement 5, Common_Movement_WalkInPlaceUp
	waitmovement 0
	release
	end


MystCity_PokemonCenter_LarsEvent_Text_0:
	.string "Lars: {COLOR BLUE}Thank you Nurse Joy!\n"
	.string "Have a good day!$"

MystCity_PokemonCenter_LarsEvent_Text_1:
	.string "Lars: {COLOR BLUE}Hey there champ!\p"
	.string "Nice seeing you again!\p"
	.string "Thought I would just stop by good old\n"
	.string "{COLOR GREEN}Myst City{COLOR BLUE}!\p"
	.string "Did you end up getting that book from\n"
	.string "{COLOR GREEN}Enclava Tower{COLOR BLUE}?$"

MystCity_PokemonCenter_LarsEvent_Text_2:
	.string "Lars: {COLOR BLUE}Sweet!\n"
	.string "I'm glad you got it champ!\p"
	.string "I'm sure {COLOR GREEN}Professor Cypress{COLOR BLUE} would love\n"
	.string "to see that book.\p"
	.string "You should definitely drop off that\n"
	.string "book at her lab in {COLOR GREEN}the southern side of\l"
	.string "the city{COLOR BLUE}.\p"
	.string "Anyways, I gotta go deal with some\n"
	.string "business stuff -- yadda yadda you\l"
	.string "know the boring old stuff.\p"
	.string "I'll see you on the flip side!$"

MystCity_PokemonCenter_LarsEvent_Text_3:
	.string "Lars: {COLOR BLUE}Ah you jokester!\p"
	.string "I know you got that book!\p"
	.string "I'm sure {COLOR GREEN}Professor Cypress{COLOR BLUE} would love\n"
	.string "to see that book.\p"
	.string "You should definitely drop off that\n"
	.string "book at her lab in {COLOR GREEN}the southern side of\l"
	.string "the city{COLOR BLUE}.\p"
	.string "Anyways, I gotta go deal with some\n"
	.string "business stuff -- yadda yadda you\l"
	.string "know the boring old stuff.\p"
	.string "I'll see you on the flip side!$"

MystCity_PokemonCenter_LarsEvent_Text_4:
	.string "Grunt: {COLOR BLUE}So {COLOR GREEN}Cypress' Lab{COLOR BLUE} is where the\n"
	.string "{COLOR GREEN}Dorimtome{COLOR BLUE} will be...$"

MystCity_PokemonCenter_Object_Grunt_Text_0:
	.string "Grunt: {COLOR BLUE}Hmmm?\p"
	.string "Don't talk to me!\p"
	.string "I'm...\n"
	.string "ummm...\p"
	.string "Looking at the region map!$"
