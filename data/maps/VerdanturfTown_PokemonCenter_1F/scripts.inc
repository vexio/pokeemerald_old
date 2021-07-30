.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts:: @ 8202726
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition: @ 8202731
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse:: @ 820273A
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman:: @ 8202748
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM:: @ 8202751
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon: @ 820275A
	.string "You can't consider yourself a real\n"
	.string "TRAINER if you don't have faith\l"
	.string "in your POKéMON.\p"
	.string "Only those people who can believe\n"
	.string "in their battling POKéMON can win\l"
	.string "through to the very end.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent: @ 820280B
	.string "The reason why anyone would visit\n"
	.string "VERDANTURF…\p"
	.string "It's the BATTLE TENT. It goes without\n"
	.string "saying.\p"
	.string "Or is there somebody here that you\n"
	.string "came to see?$"

FrostpineCity_PokemonCenter_Object_OldWoman::
	msgbox FrostpineCity_PokemonCenter_Object_OldWoman_Text_0, MSGBOX_NPC
	end


FrostpineCity_PokemonCenter_Object_OldMan::
	msgbox FrostpineCity_PokemonCenter_Object_OldMan_Text_0, MSGBOX_NPC
	end


FrostpineCity_PokemonCenter_Object_Kid::
	msgbox FrostpineCity_PokemonCenter_Object_Kid_Text_0, MSGBOX_NPC
	end


FrostpineCity_PokemonCenter_Object_OldWoman_Text_0:
	.string "{COLOR RED}I can tell you are a young trainer.\p"
	.string "I can see the hope and courage in your\n"
	.string "eyes.\p"
	.string "Just remember, real trainers have faith\n"
	.string "in their Pokémon, and only those who\l"
	.string "have faith will win through the very\l"
	.string "end.$"

FrostpineCity_PokemonCenter_Object_OldMan_Text_0:
	.string "{COLOR BLUE}I wonder why so many people vist\n"
	.string "{COLOR GREEN}Frostpine City{COLOR BLUE}...\p"
	.string "This city rests at one of the peaks of\n"
	.string "{COLOR GREEN}Mt. Hood{COLOR BLUE} and it not an easy climb for\l"
	.string "some trainers!\p"
	.string "However, at {COLOR GREEN}Mt. Hood's{COLOR BLUE} tallest peak sits\n"
	.string "a shrine for the Legendary {COLOR GREEN}Cresselia{COLOR BLUE},\l"
	.string "but no one knows if {COLOR GREEN}Cresselia{COLOR BLUE} really\l"
	.string "exists.$"

FrostpineCity_PokemonCenter_Object_Kid_Text_0:
	.string "{COLOR BLUE}My grandpa likes to tell me old tales\n"
	.string "about a Moon Pokémon!\p"
	.string "Her name is {COLOR GREEN}Cresselia{COLOR BLUE}...\n"
	.string "I think...$"
