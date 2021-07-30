MystCity_CypressLab_MapScripts::
	.byte 0


MystCity_CypressLab_Sign_FossilRoom::
	msgbox MystCity_CypressLab_Sign_FossilRoom_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


MystCity_CypressLab_Sign_ResearchRoom::
	msgbox MystCity_CypressLab_Sign_ResearchRoom_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


MystCity_CypressLab_Sign_StorageRoom::
	msgbox MystCity_CypressLab_Sign_StorageRoom_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


MystCity_CypressLab_Sign_FossilMachine::
	msgbox MystCity_CypressLab_Sign_FossilMachine_Text_0, MSGBOX_SIGN
	end


MystCity_CypressLab_Sign_PokemonMachine::
	msgbox MystCity_CypressLab_Sign_PokemonMachine_Text_0, MSGBOX_SIGN
	end


MystCity_CypressLab_Object_Scientist_1::
	msgbox MystCity_CypressLab_Object_Scientist_1_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_Object_Man::
	msgbox MystCity_CypressLab_Object_Man_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_Object_Woman::
	msgbox MystCity_CypressLab_Object_Woman_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_Object_Scientist_2::
	msgbox MystCity_CypressLab_Object_Scientist_2_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_Object_Scientist_3::
	msgbox MystCity_CypressLab_Object_Scientist_3_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_Object_Scientist_4::
	msgbox MystCity_CypressLab_Object_Scientist_4_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_Object_SchoolKid::
	msgbox MystCity_CypressLab_Object_SchoolKid_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_Object_Janitor::
	msgbox MystCity_CypressLab_Object_Janitor_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_Object_FossilScientist::
	lock
	faceplayer
	setvar VAR_FOSSILREVIVE_FOSSIL_TYPE, 12
	msgbox MystCity_CypressLab_Object_FossilScientist_Text_0
	checkitem ITEM_ARMOR_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MystCity_CypressLab_Object_FossilScientist_2
MystCity_CypressLab_Object_FossilScientist_1:
	checkitem ITEM_SKULL_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MystCity_CypressLab_Object_FossilScientist_5
MystCity_CypressLab_Object_FossilScientist_4:
	checkitem ITEM_HELIX_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MystCity_CypressLab_Object_FossilScientist_8
MystCity_CypressLab_Object_FossilScientist_7:
	checkitem ITEM_DOME_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MystCity_CypressLab_Object_FossilScientist_11
MystCity_CypressLab_Object_FossilScientist_10:
	checkitem ITEM_ROOT_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MystCity_CypressLab_Object_FossilScientist_14
MystCity_CypressLab_Object_FossilScientist_13:
	checkitem ITEM_CLAW_FOSSIL, 1
	compare VAR_RESULT, TRUE
	goto_if_eq MystCity_CypressLab_Object_FossilScientist_16
	return

MystCity_CypressLab_Object_FossilScientist_2:
	setvar VAR_FOSSILREVIVE_FOSSIL_TYPE, 1
	goto MystCity_CypressLab_Object_FossilScientist_1

MystCity_CypressLab_Object_FossilScientist_5:
	setvar VAR_FOSSILREVIVE_FOSSIL_TYPE, 2
	goto MystCity_CypressLab_Object_FossilScientist_4

MystCity_CypressLab_Object_FossilScientist_8:
	setvar VAR_FOSSILREVIVE_FOSSIL_TYPE, 3
	goto MystCity_CypressLab_Object_FossilScientist_7

MystCity_CypressLab_Object_FossilScientist_11:
	setvar VAR_FOSSILREVIVE_FOSSIL_TYPE, 4
	goto MystCity_CypressLab_Object_FossilScientist_10

MystCity_CypressLab_Object_FossilScientist_14:
	setvar VAR_FOSSILREVIVE_FOSSIL_TYPE, 5
	goto MystCity_CypressLab_Object_FossilScientist_13

MystCity_CypressLab_Object_FossilScientist_16:
	setvar VAR_FOSSILREVIVE_FOSSIL_TYPE, 1
	return


MystCity_CypressLab_Object_FossilScientist_Temp::
	msgbox MystCity_CypressLab_Object_FossilScientist_Temp_Text_0, MSGBOX_NPC
	end


MystCity_CypressLab_ProfessorCypress::
	goto_if_unset FLAG_MYSTCITY_CYPRESSLAB_PROTO_EVENT, MystCity_CypressLab_ProfessorCypress_1
	compare VAR_PROTO_HIDEOUT, 3
	goto_if_eq MystCity_CypressLab_ProfessorCypress_7
	compare VAR_CYPRESS_PROTO_EVENT_STATE, 6
	goto_if_eq MystCity_CypressLab_ProfessorCypress_8
	compare VAR_CYPRESS_PROTO_EVENT_STATE, 2
	goto_if_eq MystCity_CypressLab_ProfessorCypress_9
	msgbox MystCity_CypressLab_ProfessorCypress_Text_18, MSGBOX_NPC
	end

MystCity_CypressLab_ProfessorCypress_1:
	lockall
	faceplayer
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox MystCity_CypressLab_ProfessorCypress_Text_0, MSGBOX_AUTOCLOSE
	msgbox MystCity_CypressLab_ProfessorCypress_Text_1, MSGBOX_AUTOCLOSE
	delay 10
	closemessage
	delay 10
	setobjectxy 11, 25, 12
	playse SE_KAIDAN
	waitse
	playbgm MUS_AJITO, 0
	applymovement 6, MystCity_CypressLab_Movement_0
	playse SE_PIN
	applymovement 7, MystCity_CypressLab_Movement_0
	playse SE_PIN
	applymovement 8, MystCity_CypressLab_Movement_0
	playse SE_PIN
	applymovement 9, MystCity_CypressLab_Movement_0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, MystCity_CypressLab_Movement_0
	playse SE_PIN
	waitse
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 24
	goto_if_eq MystCity_CypressLab_ProfessorCypress_5
MystCity_CypressLab_ProfessorCypress_4:
	delay 10
	applymovement 11, MystCity_CypressLab_Movement_1
	waitmovement 0
	setobjectxy 12, 25, 12
	playse SE_KAIDAN
	applymovement 12, MystCity_CypressLab_Movement_2
	delay 10
	setobjectxy 13, 25, 12
	playse SE_KAIDAN
	applymovement 13, MystCity_CypressLab_Movement_3
	waitmovement 0
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_2
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_3
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_4
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_5
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_6
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_7, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 11, MystCity_CypressLab_Movement_6
	waitmovement 0
	applymovement 13, MystCity_CypressLab_Movement_7
	waitmovement 0
	applymovement 13, MystCity_CypressLab_Movement_8
	waitmovement 0
	applymovement 12, MystCity_CypressLab_Movement_9
	waitmovement 0
	delay 20
	applymovement 13, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_8, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_GRUNT_CYPRESS_LAB_1, MystCity_CypressLab_ProfessorCypress_Text_9
	playbgm MUS_AJITO, 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement 12, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_10, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_GRUNT_CYPRESS_LAB_2, MystCity_CypressLab_ProfessorCypress_Text_11
	playbgm MUS_AJITO, 0
	delay 20
	applymovement 11, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_12, MSGBOX_AUTOCLOSE
	closemessage
	delay 10
	msgbox MystCity_CypressLab_ProfessorCypress_Text_13, MSGBOX_AUTOCLOSE
	playmoncry SPECIES_ALAKAZAM, 0
	waitmoncry
	fadescreen FADE_TO_BLACK
	playse SE_TK_WARPOUT
	waitse
	removeobject 11
	removeobject 12
	removeobject 13
	applymovement 6, Common_Movement_WalkInPlaceLeft
	applymovement 7, Common_Movement_WalkInPlaceLeft
	applymovement 8, Common_Movement_WalkInPlaceRight
	waitmovement 0
	setflag FLAG_MYSTCITY_CYPRESSLAB_PROTO_EVENT
	delay 10
	fadescreen FADE_FROM_BLACK
	delay 15
	playbgm MUS_ODAMAKI, 0
	applymovement 9, Common_Movement_WalkInPlaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MystCity_CypressLab_ProfessorCypress_Text_14, MSGBOX_AUTOCLOSE
	applymovement 9, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	setflag FLAG_MYSTCITY_CYPRESSLAB_PROTO_EVENT
	setflag FLAG_MYSTCITY_POKEMONCENTER_LARSEVENT
	setvar VAR_CYPRESS_PROTO_EVENT_STATE, 2
	clearflag FLAG_BAYPORTCITY_LARSHOUSE_LARSEVENT
	removeitem ITEM_RUBY, 1
	releaseall
	end

MystCity_CypressLab_ProfessorCypress_5:
	compare VAR_TEMP_1, 9
	goto_if_eq MystCity_CypressLab_ProfessorCypress_14
	compare VAR_TEMP_1, 8
	goto_if_eq MystCity_CypressLab_ProfessorCypress_15
	goto MystCity_CypressLab_ProfessorCypress_4

MystCity_CypressLab_ProfessorCypress_7:
	msgbox MystCity_CypressLab_ProfessorCypress_Text_15, MSGBOX_NPC
	end

MystCity_CypressLab_ProfessorCypress_8:
	msgbox MystCity_CypressLab_ProfessorCypress_Text_16, MSGBOX_NPC
	end

MystCity_CypressLab_ProfessorCypress_9:
	msgbox MystCity_CypressLab_ProfessorCypress_Text_17, MSGBOX_NPC
	end

MystCity_CypressLab_ProfessorCypress_14:
	applymovement OBJ_EVENT_ID_PLAYER, MystCity_CypressLab_Movement_4
	waitmovement 0
	goto MystCity_CypressLab_ProfessorCypress_4

MystCity_CypressLab_ProfessorCypress_15:
	applymovement OBJ_EVENT_ID_PLAYER, MystCity_CypressLab_Movement_5
	waitmovement 0
	goto MystCity_CypressLab_ProfessorCypress_4


MystCity_CypressLab_Movement_0:
	walk_in_place_down
	delay_8
	emote_exclamation_mark
	step_end

MystCity_CypressLab_Movement_1:
	walk_up
	walk_up
	step_end

MystCity_CypressLab_Movement_2:
	walk_up
	walk_right
	walk_up
	step_end

MystCity_CypressLab_Movement_3:
	walk_up
	walk_left
	walk_up
	step_end

MystCity_CypressLab_Movement_4:
	walk_right
	walk_up
	walk_in_place_down
	step_end

MystCity_CypressLab_Movement_5:
	walk_right
	walk_down
	step_end

MystCity_CypressLab_Movement_6:
	walk_up
	walk_left
	walk_in_place_up
	step_end

MystCity_CypressLab_Movement_7:
	walk_right
	walk_in_place_up
	step_end

MystCity_CypressLab_Movement_8:
	walk_up
	step_end

MystCity_CypressLab_Movement_9:
	walk_up
	walk_up
	walk_in_place_left
	step_end

MystCity_CypressLab_Sign_FossilRoom_Text_0:
	.string "Fossil Revival and Reanimation$"

MystCity_CypressLab_Sign_ResearchRoom_Text_0:
	.string "Research and Development$"

MystCity_CypressLab_Sign_StorageRoom_Text_0:
	.string "Storage$"

MystCity_CypressLab_Sign_FossilMachine_Text_0:
	.string "It's a complex looking machine with an\n"
	.string "input for a fossil.$"

MystCity_CypressLab_Sign_PokemonMachine_Text_0:
	.string "It's a container for storing Pokémon.$"

MystCity_CypressLab_Object_Scientist_1_Text_0:
	.string "{COLOR BLUE}I'm currently working on an algorithm to\n"
	.string "calculate how old a fossil is.$"

MystCity_CypressLab_Object_Man_Text_0:
	.string "{COLOR BLUE}Hello there!\p"
	.string "Welcome to {COLOR GREEN}Professor Cypress'\n"
	.string "Laboratory{COLOR BLUE}.\p"
	.string "Down the hall to your right is where the\n"
	.string "observable rooms are located.\p"
	.string "The first room is our {COLOR GREEN}Fossil Revival and\n"
	.string "Reanimation{COLOR BLUE} room.\p"
	.string "The second room is our {COLOR GREEN}Research and\n"
	.string "Development{COLOR BLUE} room, where {COLOR GREEN}Professor\l"
	.string "Cypress{COLOR BLUE} herself is located.\p"
	.string "The last room is our {COLOR GREEN}Storage Room{COLOR BLUE}.\p"
	.string "Please feel free to visit and talk with\n"
	.string "our scientists.$"

MystCity_CypressLab_Object_Woman_Text_0:
	.string "{COLOR RED}I'm an assistant to all of the\n"
	.string "scientists here.\p"
	.string "I run errands all the time for them, just\n"
	.string "so they can work harder!$"

MystCity_CypressLab_Object_Scientist_2_Text_0:
	.string "{COLOR BLUE}I'm very busy at the moment.\p"
	.string "No time to chit-chat.$"

MystCity_CypressLab_Object_Scientist_3_Text_0:
	.string "{COLOR BLUE}Us scientists are very important in\n"
	.string "today's society!\p"
	.string "We should be treated with the highest\n"
	.string "respect.\p"
	.string "Now, could you go get me a coffee?$"

MystCity_CypressLab_Object_Scientist_4_Text_0:
	.string "{COLOR BLUE}I love working under {COLOR GREEN}Professor Cypress{COLOR BLUE}.\p"
	.string "She's a real sweetheart and really loves\n"
	.string "working with Pokémon!$"

MystCity_CypressLab_Object_SchoolKid_Text_0:
	.string "{COLOR BLUE}I just started my internship here.\p"
	.string "They just have me sit in this room and\n"
	.string "sort out books and files...$"

MystCity_CypressLab_Object_Janitor_Text_0:
	.string "{COLOR BLUE}Aye watch it bub!\p"
	.string "I'm cleaning the floor right here!\p"
	.string "You can wait until I'm done to go in\n"
	.string "here…$"

MystCity_CypressLab_Object_FossilScientist_Text_0:
	.string "{COLOR BLUE}Hi there!\p"
	.string "I am an important scientist.\n"
	.string "Yes, very much so, indeed.\p"
	.string "Here, I can revive fossilized Pokémon\n"
	.string "and return them to their former glory!$"

MystCity_CypressLab_Object_FossilScientist_Temp_Text_0:
	.string "{COLOR BLUE}Hiya!\p"
	.string "I am in important scientist.\n"
	.string "Yes, very much so, indeed.\p"
	.string "However, I cannot do what I do best,\n"
	.string "revive Fossil Pokémon.\p"
	.string "My machine has stopped working, and I\n"
	.string "need time to fix it.$"

MystCity_CypressLab_ProfessorCypress_Text_0:
	.string "Mom: {COLOR GREEN}{PLAYER}{COLOR RED}!\p"
	.string "I'm glad you were able to make it!\p"
	.string "Is there anything you need from me?\p"
	.string "............\n"
	.string "...........\p"
	.string "{COLOR GREEN}Lars{COLOR RED} sent you to get the {COLOR GREEN}Dorimtome{COLOR RED}?\p"
	.string "That lazy man...\n"
	.string "He'll always find a way out of a simple\l"
	.string "task.\p"
	.string "Regardless, thank you {COLOR GREEN}{PLAYER}{COLOR RED}!$"

MystCity_CypressLab_ProfessorCypress_Text_1:
	.string "{PLAYER} handed Mom the {COLOR GREEN}Dorimtome{COLOR DARK_GREY}.$"

MystCity_CypressLab_ProfessorCypress_Text_2:
	.string "Mom: {COLOR RED}What is going on here?\n"
	.string "Who are you?$"

MystCity_CypressLab_ProfessorCypress_Text_3:
	.string "Eris: {COLOR RED}It's quite a honor to finally meet\n"
	.string "you, {COLOR GREEN}Professor Cypress{COLOR RED}.\p"
	.string "My name is {COLOR GREEN}Eris{COLOR RED}, Head Admin for {COLOR GREEN}Team\n"
	.string "Proto{COLOR RED}.\p"
	.string "I've come to personally obtain the\n"
	.string "{COLOR GREEN}Dorimtome{COLOR RED} myself, since my colleagues\l"
	.string "seem to not be able to do it\l"
	.string "themselves.$"

MystCity_CypressLab_ProfessorCypress_Text_4:
	.string "Mom: {COLOR RED}What are your intentions for the\n"
	.string "{COLOR GREEN}Dorimtome{COLOR RED}?\p"
	.string "I'm not quite familiar your {COLOR GREEN}Team Proto{COLOR RED}\n"
	.string "organization...$"

MystCity_CypressLab_ProfessorCypress_Text_5:
	.string "Eris: {COLOR RED}Oh my!\p"
	.string "{COLOR GREEN}Team Proto{COLOR RED} does not have any ill\n"
	.string "intentions!\p"
	.string "Our organization would like to research\n"
	.string "the tome for our knowledge.$"

MystCity_CypressLab_ProfessorCypress_Text_6:
	.string "Mom: {COLOR RED}I'm sorry, but the {COLOR GREEN}Dorimtome{COLOR RED} needs\n"
	.string "to be in trusted hands.\p"
	.string "Your {COLOR GREEN}Team Proto{COLOR RED} does not seem\n"
	.string "trustworthy...$"

MystCity_CypressLab_ProfessorCypress_Text_7:
	.string "Eris: {COLOR RED}I'd hate to start drama here...\p"
	.string "But I won't take no for an answer.\p"
	.string "Grunts, take care of the kid.\p"
	.string "I'll converse with the Professor.$"

MystCity_CypressLab_ProfessorCypress_Text_8:
	.string "Grunt: {COLOR GREEN}Team Proto{COLOR BLUE} never takes no for an\n"
	.string "answer!$"

MystCity_CypressLab_ProfessorCypress_Text_9:
	.string "That Dorimtome means more to us than\n"
	.string "you know!$"

MystCity_CypressLab_ProfessorCypress_Text_10:
	.string "Grunt: {COLOR BLUE}We're gonna get that book, no\n"
	.string "matter what happens!$"

MystCity_CypressLab_ProfessorCypress_Text_11:
	.string "Haha!\p"
	.string "Distraction!$"

MystCity_CypressLab_ProfessorCypress_Text_12:
	.string "Eris snatches the {COLOR GREEN}Dorimtome{COLOR DARK_GREY} from Mom.$"

MystCity_CypressLab_ProfessorCypress_Text_13:
	.string "Eris: {COLOR RED}Thank you, {COLOR GREEN}Professor Cypress{COLOR RED}, for\n"
	.string "your cooperation.\p"
	.string "Alakazam, use Teleport!$"

MystCity_CypressLab_ProfessorCypress_Text_14:
	.string "Mom: {COLOR RED}I'm sorry {COLOR GREEN}{PLAYER}{COLOR RED}, {COLOR GREEN}Eris{COLOR RED} had some\n"
	.string "really strong Pokémon that mine did\l"
	.string "not stand a chance against.\p"
	.string "Hopefully they won't be able to do much\n"
	.string "with the {COLOR GREEN}Dorimtome{COLOR RED}...\p"
	.string "I need to talk with {COLOR GREEN}Lars{COLOR RED}, he might have\n"
	.string "an idea on what to do about this\l"
	.string "situation.\p"
	.string "{COLOR GREEN}{PLAYER}{COLOR RED}.\p"
	.string "Will you do me a favor and visit {COLOR GREEN}Lars'\n"
	.string "House{COLOR RED} in {COLOR GREEN}Bayport City{COLOR RED}?\p"
	.string "Your next Gym Challenge will also be\n"
	.string "there, so you may as well visit {COLOR GREEN}Lars{COLOR RED}\l"
	.string "there.\p"
	.string "I'll also tell the local Police about\n"
	.string "what just happened here.\p"
	.string "Thank you for your help, now go get {COLOR GREEN}Lars{COLOR RED}\n"
	.string "in {COLOR GREEN}Bayport City{COLOR RED}.$"

MystCity_CypressLab_ProfessorCypress_Text_15:
	.string "Mom: {COLOR RED}Lars said he would be waiting for\n"
	.string "you in {COLOR GREEN}Sunflora Town{COLOR BLUE}.$"

MystCity_CypressLab_ProfessorCypress_Text_16:
	.string "Mom: {COLOR RED}Lars told me that you and {COLOR GREEN}Skip{COLOR RED} are\n"
	.string "doing an investigation for him at the\l"
	.string "{COLOR GREEN}Crawdaunt Pub{COLOR RED}.\p"
	.string "Be safe!$"

MystCity_CypressLab_ProfessorCypress_Text_17:
	.string "Mom: {COLOR RED}Go talk to {COLOR GREEN}Lars{COLOR RED} in {COLOR GREEN}Bayport City{COLOR RED}, he\n"
	.string "will know what to do.$"

MystCity_CypressLab_ProfessorCypress_Text_18:
	.string "Mom: {COLOR RED}Hey honey!\p"
	.string "Just doing some research.\p"
	.string "I hope you're keeping up with the\n"
	.string "Pokémon League Gym Challenges, I'd\l"
	.string "love to see you compete at the Ryoko\l"
	.string "League!$"
