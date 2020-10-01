DewfordTown_PokemonCenter_1F_MapScripts:: @ 81FC523
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition: @ 81FC52E
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

@ VAR_0x800B is the Nurse's object event id
DewfordTown_PokemonCenter_1F_EventScript_Nurse:: @ 81FC537
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

DewfordTown_PokemonCenter_1F_EventScript_PokefanF:: @ 81FC545
	msgbox DewfordTown_PokemonCenter_1F_Text_StoneCavern, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_EventScript_Man:: @ 81FC54E
	msgbox DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM, MSGBOX_NPC
	end

DewfordTown_PokemonCenter_1F_Text_StoneCavern: @ 81FC557
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.$"

DewfordTown_PokemonCenter_1F_Text_FaintedMonCanUseHM: @ 81FC5AE
	.string "Even if a POKéMON faints and can't\n"
	.string "battle, it can still use a move learned\l"
	.string "from a HIDDEN MACHINE (HM).$"

DavnridgeTown_PC_Object_Pokefan::
	msgbox DavnridgeTown_PC_Object_Pokefan_Text_0, MSGBOX_NPC
	end


DavnridgeTown_PC_Object_Man::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_DAVNRIDGE_PC_KINGS_ROCK, DavnridgeTown_PC_Object_Man_1
	goto_if_set FLAG_BADGE01_GET, DavnridgeTown_PC_Object_Man_4
	msgbox DavnridgeTown_PC_Object_Man_Text_1
	msgbox DavnridgeTown_PC_Object_Man_Text_3, MSGBOX_AUTOCLOSE
	release
	end

DavnridgeTown_PC_Object_Man_1:
	msgbox DavnridgeTown_PC_Object_Man_Text_0, MSGBOX_NPC
	release
	end

DavnridgeTown_PC_Object_Man_4:
	msgbox DavnridgeTown_PC_Object_Man_Text_1
	msgbox DavnridgeTown_PC_Object_Man_Text_2, MSGBOX_AUTOCLOSE
	giveitem ITEM_KINGS_ROCK, 1
	setflag FLAG_ITEM_DAVNRIDGE_PC_KINGS_ROCK
	release
	end


DavnridgeTown_PC_Object_Pokefan_Text_0:
	.string "{COLOR GREEN}Davnridge Mines{COLOR RED} connects up to {COLOR GREEN}Mt.\n"
	.string "Hood{COLOR RED}.\p"
	.string "{COLOR GREEN}Mt. Hood{COLOR RED} has a tunnel that connects up\n"
	.string "to {COLOR GREEN}Victory Canyon{COLOR RED}, but you can also\l"
	.string "climb to the top of {COLOR GREEN}Mt. Hood{COLOR RED}!$"

DavnridgeTown_PC_Object_Man_Text_0:
	.string "{COLOR BLUE}King's Rock is a really useful battle\n"
	.string "item!\p"
	.string "If one of your Pokémon is holding it,\n"
	.string "they have a chance to flinch the\l"
	.string "opponent!$"

DavnridgeTown_PC_Object_Man_Text_1:
	.string "{COLOR BLUE}Have you defeated {COLOR GREEN}Lilith{COLOR RED}?$"

DavnridgeTown_PC_Object_Man_Text_2:
	.string "{COLOR BLUE}Oh wow!\n"
	.string "Is that the {COLOR GREEN}Gem Badge{COLOR BLUE}?\p"
	.string "Here, you should have this!$"

DavnridgeTown_PC_Object_Man_Text_3:
	.string "{COLOR BLUE}Oh... you haven't?\p"
	.string "Once you beat {COLOR GREEN}Lilith{COLOR BLUE}, come talk to me!$"
