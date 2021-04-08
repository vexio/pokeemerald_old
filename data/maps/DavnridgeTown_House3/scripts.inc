DavnridgeTown_House3_MapScripts::
	.byte 0


DavnridgeTown_House3_Object_Little_Girl::
	msgbox DavnridgeTown_House3_Object_Little_Girl_Text_0, MSGBOX_NPC
	end


DavnridgeTown_House3_Object_Skitty::
	lock
	faceplayer
	playmoncry SPECIES_SKITTY, 0
	msgbox DavnridgeTown_House3_Object_Skitty_Text_0
	waitmoncry
	closemessage
	release
	end


DavnridgeTown_House3_Object_Little_Girl_Text_0:
	.string "{COLOR RED}My daddy let me play with his Pokémon\n"
	.string "today!\p"
	.string "My daddy is a hard worker in the mines!$"

DavnridgeTown_House3_Object_Skitty_Text_0:
	.string "Prreow!$"
