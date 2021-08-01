FrostpineCity_House_3_MapScripts::
	.byte 0


FrostpineCity_House_3_Object_Painter::
	goto_if_set FLAG_FROSTPINECITY_SMEARGLE, FrostpineCity_House_3_Object_Painter_1
	lock
	faceplayer
	msgbox FrostpineCity_House_3_Object_Painter_Text_1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FrostpineCity_House_3_Object_Painter_4
	msgbox FrostpineCity_House_3_Object_Painter_Text_5, MSGBOX_AUTOCLOSE
	release
	end

FrostpineCity_House_3_Object_Painter_1:
	lock
	faceplayer
	msgbox FrostpineCity_House_3_Object_Painter_Text_0, MSGBOX_AUTOCLOSE
	release
	end

FrostpineCity_House_3_Object_Painter_4:
	getpartysize
	compare VAR_RESULT, 6
	goto_if_ne FrostpineCity_House_3_Object_Painter_7
	msgbox FrostpineCity_House_3_Object_Painter_Text_4, MSGBOX_AUTOCLOSE
	release
	end

FrostpineCity_House_3_Object_Painter_7:
	givemon SPECIES_SMEARGLE, 10, ITEM_LEFTOVERS
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	msgbox FrostpineCity_House_3_Object_Painter_Text_2
	waitfanfare
	msgbox FrostpineCity_House_3_Object_Painter_Text_3, MSGBOX_AUTOCLOSE
	setflag FLAG_FROSTPINECITY_SMEARGLE
	release
	end


FrostpineCity_House_3_Object_Painter_Text_0:
	.string "{COLOR BLUE}Thank you for taking care of my\n"
	.string "{COLOR GREEN}Smeargle{COLOR BLUE}.\p"
	.string "I hope you utilize them properly!$"

FrostpineCity_House_3_Object_Painter_Text_1:
	.string "{COLOR BLUE}Hm?\p"
	.string "Who are you?\p"
	.string "...\p"
	.string "Ah, you're a Pokémon Trainer aren't\n"
	.string "you...\p"
	.string "I use to be a trainer like you, but now I\n"
	.string "live for art.\p"
	.string "My poor {COLOR GREEN}Smeargle{COLOR BLUE} doesn't get to have\n"
	.string "much battle time anymore...\p"
	.string "Would you like to take care of it for\n"
	.string "me?$"

FrostpineCity_House_3_Object_Painter_Text_2:
	.string "{PLAYER} received a {COLOR GREEN}Smeargle!$"

FrostpineCity_House_3_Object_Painter_Text_3:
	.string "{COLOR BLUE}Please take care of my {COLOR GREEN}Smeargle{COLOR BLUE}!$"

FrostpineCity_House_3_Object_Painter_Text_4:
	.string "{COLOR BLUE}Oh...\n"
	.string "It seems your party is full.$"

FrostpineCity_House_3_Object_Painter_Text_5:
	.string "{COLOR BLUE}Completely understandable.\p"
	.string "{COLOR GREEN}Smeargle{COLOR BLUE} is a difficult Pokémon to\n"
	.string "utilize properly.\p"
	.string "If you ever change your mind, come talk\n"
	.string "to me.$"
