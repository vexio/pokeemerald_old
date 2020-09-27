OldaleTown_House2_MapScripts:: @ 81FBF5A
	.byte 0

OldaleTown_House2_EventScript_Woman:: @ 81FBF5B
	msgbox OldaleTown_House2_Text_PokemonLevelUp, MSGBOX_NPC
	end

OldaleTown_House2_EventScript_Man:: @ 81FBF64
	msgbox OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon, MSGBOX_NPC
	end

OldaleTown_House2_Text_PokemonLevelUp: @ 81FBF6D
	.string "When POKéMON battle, they eventually\n"
	.string "level up and become stronger.$"

OldaleTown_House2_Text_YoullGoFurtherWithStrongPokemon: @ 81FBFB0
	.string "If the POKéMON with you become\n"
	.string "stronger, you'll be able to go farther\l"
	.string "away from here.$"

AlnerwickCity_House2_Object_Woman::
	msgbox AlnerwickCity_House2_Object_Woman_Text_0, MSGBOX_NPC
	end


AlnerwickCity_House2_Object_Man::
	msgbox AlnerwickCity_House2_Object_Man_Text_0, MSGBOX_NPC
	end


AlnerwickCity_House2_Object_Woman_Text_0:
	.string "{COLOR RED}The more you level up your Pokémon, the\n"
	.string "stronger they will become!$"

AlnerwickCity_House2_Object_Man_Text_0:
	.string "{COLOR BLUE}If you evolve your Pokémon, they will\n"
	.string "become ever stronger than before!\p"
	.string "Although, not all Pokémon have\n"
	.string "evolutions...$"
