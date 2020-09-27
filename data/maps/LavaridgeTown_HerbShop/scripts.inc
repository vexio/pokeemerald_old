LavaridgeTown_HerbShop_MapScripts:: @ 81FE4D6
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk:: @ 81FE4D7
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart: @ 81FE4F0
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_ExpertM:: @ 81FE4FC
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan:: @ 81FE505
	lock
	faceplayer
	goto_if_set FLFLAG_RECEIVED_CHARCOAL, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLFLAG_RECEIVED_CHARCOAL
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal:: @ 81FE534
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop: @ 81FE53E
	.string "{COLOR RED}Welcome to the {COLOR GREEN}Herb Shop{COLOR RED}, home of\n"
	.string "effective and inexpensive medicine!$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine: @ 81FE584
	.string "You've come to look at herbal medicine\n"
	.string "in LAVARIDGE?\p"
	.string "That's rather commendable.\p"
	.string "I like you! Take this!$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal: @ 81FE5EB
	.string "That CHARCOAL I gave you, it's used\n"
	.string "for making herbal medicine.\p"
	.string "It also does wonders when held by\n"
	.string "a POKéMON.\p"
	.string "It intensifies the power of FIRE-type\n"
	.string "moves.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike: @ 81FE685
	.string "Herbal medicine works impressively well.\n"
	.string "But your POKéMON will dislike you for it.\l"
	.string "It must be horribly bitter!$"

EnclavaTown_HerbShop_Object_Expert::
	msgbox EnclavaTown_HerbShop_Object_Expert_Text_0, MSGBOX_NPC
	end


EnclavaTown_HerbShop_Object_OldMan::
	msgbox EnclavaTown_HerbShop_Object_OldMan_Text_0, MSGBOX_NPC
	end


EnclavaTown_HerbShop_Object_Expert_Text_0:
	.string "{COLOR BLUE}Herbs are a very powerful items that\n"
	.string "can be used on your Pokémon to help\l"
	.string "give you an advantage in battle.$"

EnclavaTown_HerbShop_Object_OldMan_Text_0:
	.string "{COLOR BLUE}Herbs may be an affordable way to heal\n"
	.string "your Pokémon, but they don't like the\l"
	.string "bitter taste of them.$"
