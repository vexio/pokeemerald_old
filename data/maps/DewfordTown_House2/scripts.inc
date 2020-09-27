DewfordTown_House2_MapScripts:: @ 81FE22D
	.byte 0

DewfordTown_House2_EventScript_Man:: @ 81FE22E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	compare VAR_RESULT, FALSE
	goto_if_eq DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf:: @ 81FE25D
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf:: @ 81FE267
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy:: @ 81FE271
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf: @ 81FE27A
	.string "Gorge your eyes on this!\p"
	.string "It's a SILK SCARF. It's right at the\n"
	.string "cutting edge of fashion, yeah!\p"
	.string "Oh, I can see your eyes twinkling!\n"
	.string "You appreciate my dazzling style!\p"
	.string "Oh, you're a delight!\n"
	.string "Here you go. I want you to have it!$"

DewfordTown_House2_Text_NoRoom: @ 81FE356
	.string "Oh, you don't have room?\p"
	.string "Now, listen tight, this SCARF is a must-\n"
	.string "have! Why, I would sell all my items\l"
	.string "in order to get it!$"

DewfordTown_House2_Text_ExplainSilkScarf: @ 81FE3D1
	.string "The SILK SCARF raises the power of\n"
	.string "NORMAL-type moves.\p"
	.string "It's a marvelous SCARF that will go\n"
	.string "with almost all POKéMON!$"

DewfordTown_House2_Text_BrawlySoCool: @ 81FE444
	.string "Wow, you bothered to cross the sea\n"
	.string "to visit DEWFORD?\p"
	.string "Did you maybe come here because you\n"
	.string "heard about BRAWLY?\p"
	.string "He's so cool…\n"
	.string "Everyone idolizes him.$"

DavnridgeTown_House2_Object_BirdMan::
	msgbox DavnridgeTown_House2_Object_BirdMan_Text_0, MSGBOX_NPC
	end


DavnridgeTown_House2_Object_Boy::
	msgbox DavnridgeTown_House2_Object_Boy_Text_0, MSGBOX_NPC
	end


DavnridgeTown_House2_Object_BirdMan_Text_0:
	.string "{COLOR BLUE}My flying-type Pokémon don't stand a\n"
	.string "chance against {COLOR GREEN}Lilith{COLOR BLUE}.\p"
	.string "She always crushes my poor birds!$"

DavnridgeTown_House2_Object_Boy_Text_0:
	.string "{COLOR BLUE}My friend doesn't realize that\n"
	.string "flying-type Pokémon are weak to\l"
	.string "rock-type moves...\p"
	.string "I don't think these bird keepers know\n"
	.string "there are other types of Pokémon...$"
