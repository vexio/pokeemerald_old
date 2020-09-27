LavaridgeTown_House_MapScripts:: @ 81FF911
	.byte 0

LavaridgeTown_House_EventScript_OldMan:: @ 81FF912
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon:: @ 81FF91B
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings: @ 81FF92E
	.string "My wife's warming an EGG in the hot\n"
	.string "springs. This is what she told me.\p"
	.string "She left two POKéMON with the DAY CARE.\n"
	.string "And they discovered that EGG!$"

LavaridgeTown_House_Text_Zigzagoon: @ 81FF9BB
	.string "Pshoo!$"

EnclavaTown_House1_Object_OldMan::
	msgbox EnclavaTown_House1_Object_OldMan_Text_0, MSGBOX_NPC
	end


EnclavaTown_House1_Object_Girl::
	msgbox EnclavaTown_House1_Object_Girl_Text_0, MSGBOX_NPC
	end


EnclavaTown_House1_Object_OldMan_Text_0:
	.string "{COLOR BLUE}My granddaughter likes to keep her\n"
	.string "Zigzagoon out of his Pokéball.\p"
	.string "It's irresponsible, but it makes her\n"
	.string "really happy.$"

EnclavaTown_House1_Object_Girl_Text_0:
	.string "{COLOR RED}I like Zigzagoon!\p"
	.string "He is so snuggly and nice to me!$"
