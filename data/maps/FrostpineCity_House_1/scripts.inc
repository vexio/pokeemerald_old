FrostpineCity_House_1_MapScripts::
	.byte 0


FrostpineCity_House_1_Object_Woman::
	lock
	faceplayer
	msgbox FrostpineCity_House_1_Object_Woman_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FrostpineCity_House_1_Object_Woman_1
	msgbox FrostpineCity_House_1_Object_Woman_Text_2, MSGBOX_AUTOCLOSE
	release
	end

FrostpineCity_House_1_Object_Woman_1:
	msgbox FrostpineCity_House_1_Object_Woman_Text_1, MSGBOX_AUTOCLOSE
	release
	end


FrostpineCity_House_1_Object_Woman_Text_0:
	.string "{COLOR RED}Have you heard about the legendary\n"
	.string "Pokémon that reside here in the {COLOR GREEN}Ryoko{COLOR RED}\l"
	.string "region?$"

FrostpineCity_House_1_Object_Woman_Text_1:
	.string "{COLOR RED}Oh, you already know about {COLOR GREEN}Darkrai{COLOR RED} and\n"
	.string "{COLOR GREEN}Cresselia{COLOR RED}...$"

FrostpineCity_House_1_Object_Woman_Text_2:
	.string "{COLOR RED}There is a duo of legendary Pokémon\n"
	.string "known as the {COLOR GREEN}Lunar Duo{COLOR RED}.\p"
	.string "The legendary Pokémon {COLOR GREEN}Darkrai{COLOR RED} is a\n"
	.string "Pokémon darker than a new moon.\l"
	.string "He is also known to haunt people's\l"
	.string "nightmares and put them into a\l"
	.string "never-ending sleep.\p"
	.string "The other half of the {COLOR GREEN}Lunar Duo{COLOR RED} is\n"
	.string "{COLOR GREEN}Cresselia{COLOR RED}.\p"
	.string "She is as bright as a full moon, and she\n"
	.string "is known for bringing people happy\l"
	.string "dreams and dispel nightmares.\l"
	.string "She, however, hasn't been recorded by a\l"
	.string "Pokédex yet, but I believe she is real.$"
