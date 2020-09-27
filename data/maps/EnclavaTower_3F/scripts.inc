EnclavaTower_3F_MapScripts::
	.byte 0


EnclavaTower_3F_Object_Fijo::
	compare VAR_ENCLAVATOWER_STATE, 2
	goto_if_eq EnclavaTower_3F_Object_Fijo_1
	msgbox EnclavaTower_3F_Object_Fijo_Text_3, MSGBOX_NPC
	compare VAR_PROTOGRUNTS_ENCLAVAGORGE, 0
	goto_if_eq EnclavaTower_3F_Object_Fijo_14
EnclavaTower_3F_Object_Fijo_13:
	end

EnclavaTower_3F_Object_Fijo_1:
	lock
	faceplayer
	msgbox EnclavaTower_3F_Object_Fijo_Text_0, MSGBOX_AUTOCLOSE
	delay 25
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 16
	msgbox EnclavaTower_3F_Object_Fijo_Text_1, MSGBOX_AUTOCLOSE
	delay 10
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq EnclavaTower_3F_Object_Fijo_5
	compare VAR_RESULT, DIR_EAST
	goto_if_eq EnclavaTower_3F_Object_Fijo_6
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq EnclavaTower_3F_Object_Fijo_7
	compare VAR_RESULT, DIR_WEST
	goto_if_eq EnclavaTower_3F_Object_Fijo_8
EnclavaTower_3F_Object_Fijo_4:
	delay 16
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 12
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 16
	applymovement 1, EnclavaTower_3F_Fijo_Movement_2
	waitmovement 0
	delay 8
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 16
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 14
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq EnclavaTower_3F_Object_Fijo_17
	applymovement 1, EnclavaTower_3F_Fijo_Movement_3
	waitmovement 0
EnclavaTower_3F_Object_Fijo_16:
	faceplayer
	delay 5
	msgbox EnclavaTower_3F_Object_Fijo_Text_2, MSGBOX_AUTOCLOSE
	giveitem ITEM_RUBY, 1
	msgbox EnclavaTower_3F_Object_Fijo_Text_3, MSGBOX_AUTOCLOSE
	setvar VAR_ENCLAVATOWER_STATE, 3
	setvar VAR_PROTOGRUNTS_ENCLAVAGORGE, 1
	release
	end

EnclavaTower_3F_Object_Fijo_5:
	applymovement 1, EnclavaTower_3F_Fijo_Movement_0
	waitmovement 0
	goto EnclavaTower_3F_Object_Fijo_4

EnclavaTower_3F_Object_Fijo_6:
	applymovement 1, EnclavaTower_3F_Fijo_Movement_0
	waitmovement 0
	goto EnclavaTower_3F_Object_Fijo_4

EnclavaTower_3F_Object_Fijo_7:
	applymovement 1, EnclavaTower_3F_Fijo_Movement_0
	waitmovement 0
	goto EnclavaTower_3F_Object_Fijo_4

EnclavaTower_3F_Object_Fijo_8:
	applymovement 1, EnclavaTower_3F_Fijo_Movement_1
	waitmovement 0
	goto EnclavaTower_3F_Object_Fijo_4

EnclavaTower_3F_Object_Fijo_14:
	setvar VAR_PROTOGRUNTS_ENCLAVAGORGE, 1
	goto EnclavaTower_3F_Object_Fijo_13

EnclavaTower_3F_Object_Fijo_17:
	applymovement 1, EnclavaTower_3F_Fijo_Movement_4
	waitmovement 0
	goto EnclavaTower_3F_Object_Fijo_16


EnclavaTower_3F_Fijo_Movement_0:
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

EnclavaTower_3F_Fijo_Movement_1:
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

EnclavaTower_3F_Fijo_Movement_2:
	walk_right
	walk_in_place_up
	step_end

EnclavaTower_3F_Fijo_Movement_3:
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

EnclavaTower_3F_Fijo_Movement_4:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

EnclavaTower_3F_Object_Man1::
	msgbox EnclavaTower_3F_Object_Man1_Text_0, MSGBOX_NPC
	end


EnclavaTower_3F_Object_Man2::
	msgbox EnclavaTower_3F_Object_Man2_Text_0, MSGBOX_NPC
	end


EnclavaTower_3F_Object_Woman1::
	msgbox EnclavaTower_3F_Object_Woman1_Text_0, MSGBOX_NPC
	end


EnclavaTower_3F_Object_Woman2::
	msgbox EnclavaTower_3F_Object_Woman2_Text_0, MSGBOX_NPC
	end


EnclavaTower_3F_Object_Fijo_Text_0:
	.string "Fijo: {COLOR BLUE}Hello child.\n"
	.string "What brings you here?$"

EnclavaTower_3F_Object_Fijo_Text_1:
	.string "Fijo: {COLOR BLUE}Ah, you're the trainer that {COLOR GREEN}Prof.\n"
	.string "Cypress{COLOR BLUE} sent to get {COLOR GREEN}The Dorimtome{COLOR BLUE}...\l"
	.string "I see...\p"
	.string "I'll get that for you.$"

EnclavaTower_3F_Object_Fijo_Text_2:
	.string "Fijo: {COLOR BLUE}This book, {COLOR GREEN}The Dorimtome{COLOR BLUE}, is an\n"
	.string "ancient tome from 100 years ago.\p"
	.string "It contains many scriptures describing\n"
	.string "the legendary Pokémon {COLOR GREEN}Cresselia{COLOR BLUE}.\p"
	.string "The author of this book claims that\n"
	.string "{COLOR GREEN}Cresselia{COLOR BLUE} has psychic-powers that can\l"
	.string "put anyone to sleep instantly, and\l"
	.string "bring them happy dreams.\p"
	.string "These dreams bring the slumbered\n"
	.string "recovery and good health.\p"
	.string "{COLOR GREEN}Cresselia{COLOR BLUE}, however, has never been\n"
	.string "discovered or recorded using modern\l"
	.string "technology, so she remains a myth.\p"
	.string "I don't know what {COLOR GREEN}Prof. Cypress{COLOR BLUE} wants\n"
	.string "to do with this book, but I respect her\l"
	.string "needs.$"

EnclavaTower_3F_Object_Fijo_Text_3:
	.string "Fijo: {COLOR BLUE}Please be careful with that book.\p"
	.string "That book contains a lot of secret\n"
	.string "techniques that only wise individuals\l"
	.string "know how to utilize.\p"
	.string "Make good choices until you deliver\n"
	.string "that book to {COLOR GREEN}Prof. Cypress{COLOR BLUE} in {COLOR GREEN}Myst\l"
	.string "City{COLOR BLUE}.$"

EnclavaTower_3F_Object_Man1_Text_0:
	.string "{COLOR BLUE}I come here to study the art of\n"
	.string "Fighting-type Pokémon.$"

EnclavaTower_3F_Object_Man2_Text_0:
	.string "{COLOR BLUE}I practice karate with {COLOR GREEN}Master Fijo{COLOR BLUE} to\n"
	.string "help my team's synergy.\p"
	.string "He's a really great trainer!$"

EnclavaTower_3F_Object_Woman1_Text_0:
	.string "{COLOR RED}I've been trying to find this book\n"
	.string "forever now...$"

EnclavaTower_3F_Object_Woman2_Text_0:
	.string "{COLOR GREEN}Enclava Tower{COLOR RED} is a great place to train\n"
	.string "your team, although not the best if\l"
	.string "you're training your Fighting-typed\l"
	.string "Pokémon.$"
