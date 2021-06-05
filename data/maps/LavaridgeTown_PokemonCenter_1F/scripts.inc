LavaridgeTown_PokemonCenter_1F_MapScripts:: @ 81FFAFA
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnTransition: @ 81FFB05
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
LavaridgeTown_PokemonCenter_1F_EventScript_Nurse:: @ 81FFB0E
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Youngster:: @ 81FFB1C
	msgbox LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Woman:: @ 81FFB25
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_EventScript_Gentleman:: @ 81FFB2E
	msgbox LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo, MSGBOX_NPC
	end

LavaridgeTown_PokemonCenter_1F_Text_TrainersPokemonSpendTimeTogether: @ 81FFB37
	.string "I think POKéMON get closer to their\n"
	.string "TRAINERS if they spend time together.\p"
	.string "The longer the better.\n"
	.string "That's what I think.$"

LavaridgeTown_PokemonCenter_1F_Text_HotSpringCanInvigorate: @ 81FFBAD
	.string "It's sort of magical how just sitting\n"
	.string "in a hot-spring pool can invigorate.\p"
	.string "I wish I could let my POKéMON\n"
	.string "soak, too.$"

LavaridgeTown_PokemonCenter_1F_Text_TrainersShouldRestToo: @ 81FFC21
	.string "Hohoho! Hey, kid, you can reach\n"
	.string "the hot springs from here.\p"
	.string "If POKéMON are getting rest, so too\n"
	.string "should their TRAINERS.$"

EnclavaTown_PC_Object_HexManiac::
	lock
	faceplayer
	msgbox EnclavaTown_PC_Object_HexManiac_Text_0
	goto_if_set FLAG_ITEM_ENCLAVA_PC_LINK_CABLE, EnclavaTown_PC_Object_HexManiac_1
	checkpartymon SPECIES_HAUNTER
	compare VAR_RESULT, TRUE
	goto_if_eq EnclavaTown_PC_Object_HexManiac_4
	checkpartymon SPECIES_GASTLY
	compare VAR_RESULT, TRUE
	goto_if_eq EnclavaTown_PC_Object_HexManiac_7
	applymovement 6, Common_Movement_WalkInPlaceUp
	waitmovement 0
	closemessage
	release
	end

EnclavaTown_PC_Object_HexManiac_1:
	applymovement 6, Common_Movement_WalkInPlaceUp
	waitmovement 0
	closemessage
	release
	end

EnclavaTown_PC_Object_HexManiac_4:
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	delay 16
	msgbox EnclavaTown_PC_Object_HexManiac_Text_1
	giveitem ITEM_LINK_CABLE, 1
	msgbox EnclavaTown_PC_Object_HexManiac_Text_2, MSGBOX_AUTOCLOSE
	applymovement 6, Common_Movement_WalkInPlaceUp
	waitmovement 0
	setflag FLAG_ITEM_ENCLAVA_PC_LINK_CABLE
	release
	end

EnclavaTown_PC_Object_HexManiac_7:
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	delay 16
	msgbox EnclavaTown_PC_Object_HexManiac_Text_3, MSGBOX_AUTOCLOSE
	applymovement 6, Common_Movement_WalkInPlaceUp
	waitmovement 0
	release
	end


EnclavaTown_PC_Object_Woman::
	msgbox EnclavaTown_PC_Object_Woman_Text_0, MSGBOX_NPC
	end


EnclavaTown_PC_Object_RuinManiac::
	msgbox EnclavaTown_PC_Object_RuinManiac_Text_0, MSGBOX_NPC
	end


EnclavaTown_PC_Object_Youngster::
	msgbox EnclavaTown_PC_Object_Youngster_Text_0, MSGBOX_NPC
	end


EmoteTest::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_HeartEmote
	waitmovement 0
	delay 16
	release
	end


HaunterEvolutionTest_Script::
	lock
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	givemon SPECIES_HAUNTER, 30, ITEM_POTION
	giveitem ITEM_LINK_CABLE
	playse SE_PIN
	release
	end


EnclavaTown_PC_Object_HexManiac_Text_0:
	.string "{COLOR RED}...$"

EnclavaTown_PC_Object_HexManiac_Text_1:
	.string "{COLOR RED}Is that a Haunter?\p"
	.string "Haunter is a unique Pokémon, as it can\n"
	.string "only evolve through the usage of a\l"
	.string "{COLOR GREEN}Link Cable{COLOR RED}.\p"
	.string "Here, take one.$"

EnclavaTown_PC_Object_HexManiac_Text_2:
	.string "{COLOR RED}That can be used on more than Haunter,\n"
	.string "some other Pokémon can only evolve\l"
	.string "through the {COLOR GREEN}Link Cable{COLOR RED}.$"

EnclavaTown_PC_Object_HexManiac_Text_3:
	.string "{COLOR RED}Oh...\p"
	.string "That's a Gastly...$"

EnclavaTown_PC_Object_Woman_Text_0:
	.string "{COLOR RED}I think Pokémon get closer to their\n"
	.string "trainers if they spend time together.\p"
	.string "The longer, the better!$"

EnclavaTown_PC_Object_RuinManiac_Text_0:
	.string "{COLOR BLUE}Ohoho!\n"
	.string "It feels nice to finally sit down after\l"
	.string "hiking!$"

EnclavaTown_PC_Object_Youngster_Text_0:
	.string "{COLOR BLUE}Look!\n"
	.string "It's the region map!\p"
	.string "You can find out where you are in\n"
	.string "relation to other landmarks and cities!$"
