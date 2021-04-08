DavnridgeTown_House4_MapScripts::
	.byte 0


DavnridgeTown_House4_Object_Woman::
	msgbox DavnridgeTown_House4_Object_Woman_Text_0, MSGBOX_NPC
	end


DavnridgeTown_House4_Object_Man::
	lock
	faceplayer
	msgbox DavnridgeTown_House4_Object_Man_Text_0
	switch VAR_DAVNRIDGETOWN_COLLECTOR_STATE
	case 0, DavnridgeTown_House4_Object_Man_2
	msgbox DavnridgeTown_House4_Object_Man_Text_6, MSGBOX_AUTOCLOSE
	release
	end

DavnridgeTown_House4_Object_Man_2:
	msgbox DavnridgeTown_House4_Object_Man_Text_1
	checkitem ITEM_RAZOR_CLAW, 1
	compare VAR_RESULT, TRUE
	goto_if_eq DavnridgeTown_House4_Object_Man_4
	msgbox DavnridgeTown_House4_Object_Man_Text_5, MSGBOX_AUTOCLOSE
	release
	end

DavnridgeTown_House4_Object_Man_4:
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 20
	msgbox DavnridgeTown_House4_Object_Man_Text_2, MSGBOX_YESNO
	compare VAR_RESULT, TRUE
	goto_if_eq DavnridgeTown_House4_Object_Man_7
	msgbox DavnridgeTown_House4_Object_Man_Text_4, MSGBOX_AUTOCLOSE
	release
	end

DavnridgeTown_House4_Object_Man_7:
	msgbox DavnridgeTown_House4_Object_Man_Text_3, MSGBOX_AUTOCLOSE
	removeitem ITEM_RAZOR_CLAW, 1
	addmoney 8000, 0x00
	setvar VAR_DAVNRIDGETOWN_COLLECTOR_STATE, 1
	return


DavnridgeTown_House4_Object_Woman_Text_0:
	.string "{COLOR RED}My husband collects rare items.\p"
	.string "He scavenges around the {COLOR GREEN}Davnridge\n"
	.string "Mines{COLOR RED} looking for rare items.$"

DavnridgeTown_House4_Object_Man_Text_0:
	.string "{COLOR BLUE}Hello!\n"
	.string "I'm a collector!\p"
	.string "I collect rare items, and I'll buy them\n"
	.string "off you!$"

DavnridgeTown_House4_Object_Man_Text_1:
	.string "{COLOR BLUE}I'm currently looking for a {COLOR GREEN}Razor Claw{COLOR BLUE}.$"

DavnridgeTown_House4_Object_Man_Text_2:
	.string "{COLOR BLUE}Is that a {COLOR GREEN}Razor Claw{COLOR BLUE}?\p"
	.string "I'll give you {COLOR GREEN}¥8,000{COLOR BLUE} for that {COLOR GREEN}Razor Claw{COLOR BLUE}!$"

DavnridgeTown_House4_Object_Man_Text_3:
	.string "{COLOR BLUE}Yes!\n"
	.string "I've been looking for this!\p"
	.string "Thank you!$"

DavnridgeTown_House4_Object_Man_Text_4:
	.string "{COLOR BLUE}Aw... okay.\p"
	.string "If you ever change your mind, please\n"
	.string "come talk to me!$"

DavnridgeTown_House4_Object_Man_Text_5:
	.string "{COLOR BLUE}Hmmm...\n"
	.string "I guess you don't have a {COLOR GREEN}Razor Claw{COLOR BLUE}...$"

DavnridgeTown_House4_Object_Man_Text_6:
	.string "{COLOR BLUE}I'm currently not looking for anything...$"
