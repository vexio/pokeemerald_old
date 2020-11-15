Route106_MapScripts:: @ 81EE489
	.byte 0

Route106_EventScript_TrainerTipsSign:: @ 81EE48A
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas:: @ 81EE493
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla:: @ 81EE4AA
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot:: @ 81EE4C1
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle:: @ 81EE4ED
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch:: @ 81EE50C
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned:: @ 81EE523
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_Text_TrainerTips: @ 81EE53A
	.string "TRAINER TIPS\p"
	.string "Advice on catching POKéMON with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

TriadGorge_Trigger_ProtoGrunts::
	lockall
	fadescreen FADE_TO_BLACK
	cleartrainerflag TRAINER_GRUNT_TRIAD_GORGE_1
	cleartrainerflag TRAINER_GRUNT_TRIAD_GORGE_2
	cleartrainerflag TRAINER_GRUNT_TRIAD_GORGE_3
	cleartrainerflag TRAINER_ADMIN_HAUMEA_1
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 20
	goto_if_eq TriadGorge_Trigger_ProtoGrunts_2
	compare VAR_TEMP_1, 22
	goto_if_eq TriadGorge_Trigger_ProtoGrunts_3
	compare VAR_TEMP_1, 23
	goto_if_eq TriadGorge_Trigger_ProtoGrunts_4
TriadGorge_Trigger_ProtoGrunts_1:
	delay 5
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, TriadGorge_ProtoGrunts_CMovement_0
	waitmovement 0
	playbgm MUS_AJITO, 0
	fadescreen FADE_FROM_BLACK
	delay 10
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_0
	applymovement 3, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_1
	applymovement 3, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_2, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 5, Common_Movement_JumpInPlaceRight
	applymovement 4, Common_Movement_JumpInPlaceRight
	playse SE_JITE_PYOKO
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceRight
	applymovement 4, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 16
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_3, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 3, Common_Movement_WalkInPlaceRight
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_4, MSGBOX_AUTOCLOSE
	delay 5
	applymovement 4, Common_Movement_QuestionMark
	waitmovement 0
	playse SE_PIN
	delay 16
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_5
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_6
	applymovement 4, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_7
	applymovement 3, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_8, MSGBOX_AUTOCLOSE
	applymovement 4, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 5
	applymovement 3, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 20
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_9
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_10
	applymovement 4, Common_Movement_WalkInPlaceRight
	applymovement 3, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_11
	applymovement 5, Common_Movement_WalkInPlaceRight
	applymovement 4, Common_Movement_WalkInPlaceRight
	applymovement 3, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_12, MSGBOX_AUTOCLOSE
	delay 15
	applymovement 5, Common_Movement_WalkInPlaceLeft
	applymovement 4, Common_Movement_WalkInPlaceLeft
	applymovement 3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 16
	applymovement 4, Common_Movement_JumpInPlaceLeft
	waitmovement 0
	playse SE_JITE_PYOKO
	delay 5
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_13
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_14, MSGBOX_AUTOCLOSE
	delay 10
	applymovement OBJ_EVENT_ID_CAMERA, TriadGorge_ProtoGrunts_CMovement_1
	waitmovement 0
	special RemoveCameraObject
	delay 10
	applymovement 5, TriadGorge_ProtoGrunts_Movement_1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_15
	trainerbattle_no_intro TRAINER_GRUNT_TRIAD_GORGE_1, TriadGorge_Trigger_ProtoGrunts_Text_16
	playbgm MUS_AJITO, 0
	delay 5
	applymovement 4, TriadGorge_ProtoGrunts_Movement_2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_17
	trainerbattle_no_intro TRAINER_GRUNT_TRIAD_GORGE_2, TriadGorge_Trigger_ProtoGrunts_Text_18
	playbgm MUS_AJITO, 0
	delay 5
	applymovement 3, TriadGorge_ProtoGrunts_Movement_3
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_19
	trainerbattle_no_intro TRAINER_GRUNT_TRIAD_GORGE_3, TriadGorge_Trigger_ProtoGrunts_Text_20
	playbgm MUS_AJITO, 0
	delay 5
	applymovement 4, TriadGorge_ProtoGrunts_Movement_4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement 2, TriadGorge_ProtoGrunts_Movement_5
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_21
	trainerbattle_no_intro TRAINER_ADMIN_HAUMEA_1, TriadGorge_Trigger_ProtoGrunts_Text_22
	playbgm MUS_AJITO, 0
	delay 5
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_23
	delay 10
	playmoncry SPECIES_ABRA, 0
	waitmoncry
	delay 10
	fadescreen FADE_TO_BLACK
	closemessage
	setvar VAR_PROTOGRUNTS_ENCLAVAGORGE, 3
	removeobject 5
	removeobject 4
	removeobject 3
	removeobject 2
	playse SE_TK_WARPOUT
	setobjectxy 15, 36, 21
	delay 15
	fadescreen FADE_FROM_BLACK
	delay 20
	applymovement 15, TriadGorge_ProtoGrunts_Movement_6
	waitmovement 0
	applymovement 15, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	playbgm MUS_RG_RIVAL1, 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_24, MSGBOX_AUTOCLOSE
	applymovement 15, TriadGorge_ProtoGrunts_Movement_7
	waitmovement 0
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_25
	giveitem ITEM_HM01_CUT, 1
	msgbox TriadGorge_Trigger_ProtoGrunts_Text_26, MSGBOX_AUTOCLOSE
	applymovement 15, TriadGorge_ProtoGrunts_Movement_8
	playbgm MUS_NEXTROAD, 0
	waitmovement 0
	removeobject 15
	setflag FLAG_TRIAD_GORGE_GRUNTS
	release
	end

TriadGorge_Trigger_ProtoGrunts_2:
	applymovement OBJ_EVENT_ID_PLAYER, TriadGorge_ProtoGrunts_Movement_0_0
	waitmovement 0
	goto TriadGorge_Trigger_ProtoGrunts_1

TriadGorge_Trigger_ProtoGrunts_3:
	applymovement OBJ_EVENT_ID_PLAYER, TriadGorge_ProtoGrunts_Movement_0_1
	waitmovement 0
	goto TriadGorge_Trigger_ProtoGrunts_1

TriadGorge_Trigger_ProtoGrunts_4:
	applymovement OBJ_EVENT_ID_PLAYER, TriadGorge_ProtoGrunts_Movement_0_2
	waitmovement 0
	goto TriadGorge_Trigger_ProtoGrunts_1


TriadGorge_ProtoGrunts_Movement_0_0:
	walk_fastest_down
	walk_in_place_fastest_right
	step_end

TriadGorge_ProtoGrunts_Movement_0_1:
	walk_fastest_up
	walk_in_place_fastest_right
	step_end

TriadGorge_ProtoGrunts_Movement_0_2:
	walk_fastest_up
	walk_fastest_up
	walk_in_place_fastest_right
	step_end

TriadGorge_ProtoGrunts_CMovement_0:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	step_end

TriadGorge_ProtoGrunts_CMovement_1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TriadGorge_ProtoGrunts_Movement_1:
	walk_left
	walk_left
	walk_in_place_down
	step_end

TriadGorge_ProtoGrunts_Movement_2:
	walk_left
	step_end

TriadGorge_ProtoGrunts_Movement_3:
	walk_left
	walk_left
	walk_in_place_up
	step_end

TriadGorge_ProtoGrunts_Movement_4:
	walk_up
	walk_in_place_down
	step_end

TriadGorge_ProtoGrunts_Movement_5:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TriadGorge_ProtoGrunts_Movement_6:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

TriadGorge_ProtoGrunts_Movement_7:
	walk_left
	walk_left
	walk_left
	step_end

TriadGorge_ProtoGrunts_Movement_8:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

TriadGorge_Trainer_BirdKeeper::
	trainerbattle_single TRAINER_BIRDKEEP_KEITH, TriadGorge_Trainer_BirdKeeper_Text_0, TriadGorge_Trainer_BirdKeeper_Text_1
	msgbox TriadGorge_Trainer_BirdKeeper_Text_2, MSGBOX_NPC
	end


TriadGorge_Trainer_BugCatcher::
	trainerbattle_single TRAINER_BUGCATCHER_DEVEN, TriadGorge_Trainer_BugCatcher_Text_0, TriadGorge_Trainer_BugCatcher_Text_1
	msgbox TriadGorge_Trainer_BugCatcher_Text_2, MSGBOX_NPC
	end


TriadGorge_Trainer_RuinManiac::
	trainerbattle_single TRAINER_RUINMANIAC_WAYNE, TriadGorge_Trainer_RuinManiac_Text_0, TriadGorge_Trainer_RuinManiac_Text_1
	msgbox TriadGorge_Trainer_RuinManiac_Text_2, MSGBOX_NPC
	end


TriadGorge_Trainer_PokefanF::
	trainerbattle_single TRAINER_POKEFAN_F_ALENA, TriadGorge_Trainer_PokefanF_Text_0, TriadGorge_Trainer_PokefanF_Text_1
	msgbox TriadGorge_Trainer_PokefanF_Text_2, MSGBOX_NPC
	end


TriadGorge_Trainer_Hiker::
	trainerbattle_single TRAINER_HIKER_DAMON, TriadGorge_Trainer_Hiker_Text_0, TriadGorge_Trainer_Hiker_Text_1
	msgbox TriadGorge_Trainer_Hiker_Text_2, MSGBOX_NPC
	end


TriadGorge_Sign_RouteSignLeft::
	msgbox TriadGorge_Sign_RouteSignLeft_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	return


TriadGorge_Sign_RouteSignRight::
	msgbox TriadGorge_Sign_RouteSignRight_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	return


TriadGorge_Sign_RouteSignMiddle::
	msgbox TriadGorge_Sign_RouteSignMiddle_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	return


TriadGorge_Object_RockSmashHiker::
	lock
	faceplayer
	msgbox TriadGorge_Object_RockSmashHiker_Text_0
	goto_if_set FLAG_BADGE03_GET, TriadGorge_Object_RockSmashHiker_1
	closemessage
	release
	end

TriadGorge_Object_RockSmashHiker_1:
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox TriadGorge_Object_RockSmashHiker_Text_1
	giveitem ITEM_HM06_ROCK_SMASH, 1
	msgbox TriadGorge_Object_RockSmashHiker_Text_2, MSGBOX_AUTOCLOSE
	delay 10
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 66
	goto_if_eq TriadGorge_Object_RockSmashHiker_5
	applymovement 14, TriadGorge_RockSmashHiker_Movement_0
	waitmovement 0
TriadGorge_Object_RockSmashHiker_4:
	removeobject 14
	setflag FLAG_TRIADGORGE_ROCKSMASH
	release
	end

TriadGorge_Object_RockSmashHiker_5:
	applymovement 14, TriadGorge_RockSmashHiker_Movement_1
	waitmovement 0
	goto TriadGorge_Object_RockSmashHiker_4


TriadGorge_RockSmashHiker_Movement_0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TriadGorge_RockSmashHiker_Movement_1:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TriadGorge_Trigger_ProtoGrunts_Text_0:
	.string "Haumea: {COLOR BLUE}You three!\n"
	.string "Where have you been?$"

TriadGorge_Trigger_ProtoGrunts_Text_1:
	.string "Grunt 3: {COLOR RED}Sorry {COLOR GREEN}Haumea{COLOR RED}, won't happen\n"
	.string "again!$"

TriadGorge_Trigger_ProtoGrunts_Text_2:
	.string "{COLOR RED}Right boys?$"

TriadGorge_Trigger_ProtoGrunts_Text_3:
	.string "Grunt 1: {COLOR BLUE}Yes {COLOR GREEN}Haumea{COLOR BLUE} sir!\n"
	.string "{COLOR DARK_GREY}Grunt 2: {COLOR BLUE}Yes {COLOR GREEN}Haumea{COLOR BLUE} sir!$"

TriadGorge_Trigger_ProtoGrunts_Text_4:
	.string "Haumea: {COLOR BLUE}Good.\p"
	.string "Now, do you guys have those dusty old\n"
	.string "books?$"

TriadGorge_Trigger_ProtoGrunts_Text_5:
	.string "Grunt 2: {COLOR BLUE}Uhhh...\n"
	.string "Books? As in multipl'?$"

TriadGorge_Trigger_ProtoGrunts_Text_6:
	.string "Haumea: {COLOR BLUE}Yes as in multiple!\p"
	.string "We need the {COLOR GREEN}Dorimtome{COLOR BLUE} and the\n"
	.string "{COLOR GREEN}Akumutome{COLOR BLUE}!$"

TriadGorge_Trigger_ProtoGrunts_Text_7:
	.string "Grunt 2: {COLOR BLUE}...\n"
	.string "Whic' one do I hav' here?$"

TriadGorge_Trigger_ProtoGrunts_Text_8:
	.string "Grunt 3: {COLOR RED}Let me see that!$"

TriadGorge_Trigger_ProtoGrunts_Text_9:
	.string "Grunt 3: {COLOR RED}...\p"
	.string "It looks like it's the {COLOR GREEN}Akumutome{COLOR BLUE}.$"

TriadGorge_Trigger_ProtoGrunts_Text_10:
	.string "Grunt 2: {COLOR BLUE}That's th' one I got from\n"
	.string "{COLOR GREEN}Alnerwick Library{COLOR BLUE}.$"

TriadGorge_Trigger_ProtoGrunts_Text_11:
	.string "Haumea: {COLOR BLUE}Did anyone see you steal that\n"
	.string "book?\p"
	.string "{COLOR DARK_GREY}Grunt 2: {COLOR BLUE}Only the librarian and some kid.\p"
	.string "{COLOR DARK_GREY}Haumea: {COLOR BLUE}Good.\n"
	.string "Now you three need to go get that\l"
	.string "{COLOR GREEN}Dorimtome{COLOR BLUE} in {COLOR GREEN}Enclava Tower{COLOR BLUE}!$"

TriadGorge_Trigger_ProtoGrunts_Text_12:
	.string "Grunts: {COLOR BLUE}Yes sir!$"

TriadGorge_Trigger_ProtoGrunts_Text_13:
	.string "Grunt 2: {COLOR BLUE}That's th' kid from {COLOR GREEN}Alnerwick\n"
	.string "Library{COLOR BLUE}!$"

TriadGorge_Trigger_ProtoGrunts_Text_14:
	.string "Haumea: {COLOR BLUE}So you've been eaves dropping,\n"
	.string "eh kid?\p"
	.string "Grunts!\n"
	.string "Take care of that nuisance!\p"
	.string "I don't plan on getting my hands dirty.$"

TriadGorge_Trigger_ProtoGrunts_Text_15:
	.string "Grunt 1: {COLOR BLUE}You're gonna regret messing\n"
	.string "with {COLOR GREEN}Team Proto{COLOR BLUE}!$"

TriadGorge_Trigger_ProtoGrunts_Text_16:
	.string "Gah!$"

TriadGorge_Trigger_ProtoGrunts_Text_17:
	.string "Grunt 2: {COLOR BLUE}You're th' kid from {COLOR GREEN}Alnerwick\n"
	.string "Library{COLOR BLUE}eh?\p"
	.string "Stay outta our busines'!$"

TriadGorge_Trigger_ProtoGrunts_Text_18:
	.string "Stay outta it kid!$"

TriadGorge_Trigger_ProtoGrunts_Text_19:
	.string "Grunt 3: {COLOR RED}Those two bafoons don't know\n"
	.string "how to represent {COLOR GREEN}Team Proto{COLOR RED}!$"

TriadGorge_Trigger_ProtoGrunts_Text_20:
	.string "Running out of energy?$"

TriadGorge_Trigger_ProtoGrunts_Text_21:
	.string "Haumea: {COLOR BLUE}These idiots don't know how to\n"
	.string "do anything right!\p"
	.string "Listen, kid.\n"
	.string "I know you're trying to be the hero, and\l"
	.string "trying to get that book back to\l"
	.string "{COLOR GREEN}Alnerwick Library{COLOR BLUE}, but that ideology\l"
	.string "won't work here.\p"
	.string "Now, time to teach you a valuable lesson\n"
	.string "here, kid!$"

TriadGorge_Trigger_ProtoGrunts_Text_22:
	.string "What?\p"
	.string "A kid beat me?$"

TriadGorge_Trigger_ProtoGrunts_Text_23:
	.string "Haumea: {COLOR BLUE}You're a strong trainer, I can\n"
	.string "see that...\p"
	.string "But {COLOR GREEN}Team Proto{COLOR BLUE} won't be stopped by a\n"
	.string "child!\p"
	.string "This won't be the last you see of {COLOR GREEN}Team\n"
	.string "Proto{COLOR BLUE}!\p"
	.string "Abra, use Teleport!$"

TriadGorge_Trigger_ProtoGrunts_Text_24:
	.string "Skip: {COLOR BLUE}There you are slowpoke!$"

TriadGorge_Trigger_ProtoGrunts_Text_25:
	.string "Skip: {COLOR BLUE}Did you just deal with those robed\n"
	.string "people?\p"
	.string "They looked weak, I'm surprised you\n"
	.string "stood a chance against them!\p"
	.string "I've been training for the {COLOR GREEN}Fiery Badge{COLOR BLUE}\n"
	.string "up north here on {COLOR GREEN}Frostpine Climb{COLOR BLUE}, and\l"
	.string "now my team is stronger than ever!\p"
	.string "I'm not gonna take it out on you, since\n"
	.string "you and your team just took a beating\l"
	.string "from those {COLOR GREEN}Team Proto{COLOR BLUE} goons.\p"
	.string "I also just ran into this white haired\n"
	.string "dude, and he told me to give you this.$"

TriadGorge_Trigger_ProtoGrunts_Text_26:
	.string "Skip: {COLOR BLUE}Anyways, I'm gonna head up north\n"
	.string "to get the third badge!\p"
	.string "I'm going to continue training until I\n"
	.string "become the strongest trainer in all of\l"
	.string "Ryoko!$"

TriadGorge_Trainer_BirdKeeper_Text_0:
	.string "{COLOR BLUE}I've been trying to train my Pokémon,\n"
	.string "and you look like just enough\l"
	.string "experience!$"

TriadGorge_Trainer_BirdKeeper_Text_1:
	.string "Back to battling Wild Pokémon...$"

TriadGorge_Trainer_BirdKeeper_Text_2:
	.string "{COLOR BLUE}I've been training my Pokémon by\n"
	.string "battling Wild Pokémon, but battling\l"
	.string "trainers seems to give me more\l"
	.string "experience.$"

TriadGorge_Trainer_BugCatcher_Text_0:
	.string "{COLOR BLUE}Buzz, buzz!$"

TriadGorge_Trainer_BugCatcher_Text_1:
	.string "Buzz, buzz...$"

TriadGorge_Trainer_BugCatcher_Text_2:
	.string "{COLOR BLUE}Buzz, buzz!\p"
	.string "I like to hunt for Combee's!$"

TriadGorge_Trainer_RuinManiac_Text_0:
	.string "{COLOR BLUE}Hoho!\p"
	.string "Do you have any Rock-type Pokémon?$"

TriadGorge_Trainer_RuinManiac_Text_1:
	.string "Hoho!\n"
	.string "Good battle champ!$"

TriadGorge_Trainer_RuinManiac_Text_2:
	.string "{COLOR BLUE}Rock-type Pokémon are the best, but\n"
	.string "the best Rock-type Pokémon are Fossil\l"
	.string "Pokémon!$"

TriadGorge_Trainer_PokefanF_Text_0:
	.string "{COLOR RED}What Pokémon do you have?\p"
	.string "Let me see!$"

TriadGorge_Trainer_PokefanF_Text_1:
	.string "Wow!\n"
	.string "You have some cool Pokémon!$"

TriadGorge_Trainer_PokefanF_Text_2:
	.string "{COLOR RED}If you ever find any cool Pokémon, come\n"
	.string "show me!$"

TriadGorge_Trainer_Hiker_Text_0:
	.string "{COLOR BLUE}Whew!\p"
	.string "I just got done with my hike down\n"
	.string "{COLOR GREEN}Frostpine Clime{COLOR BLUE}!\p"
	.string "How about a little battle, eh?$"

TriadGorge_Trainer_Hiker_Text_1:
	.string "A great way to wind down from a hike.$"

TriadGorge_Trainer_Hiker_Text_2:
	.string "{COLOR BLUE}A Pokémon battle is always a great way\n"
	.string "to wind down!$"

TriadGorge_Sign_RouteSignLeft_Text_0:
	.string "{COLOR LIGHT_GREEN}Triad Gorge\p"
	.string "{COLOR DARK_GREY}{UP_ARROW} {COLOR LIGHT_GREEN}Enclava Town\n"
	.string "{COLOR DARK_GREY}{RIGHT_ARROW}{UP_ARROW} {COLOR LIGHT_GREEN}Frostpine Climb\l"
	.string "{COLOR DARK_GREY}{RIGHT_ARROW} {COLOR LIGHT_GREEN}Myst City$"

TriadGorge_Sign_RouteSignRight_Text_0:
	.string "{COLOR LIGHT_GREEN}Triad Gorge\p"
	.string "{COLOR DARK_GREY}{RIGHT_ARROW} {COLOR LIGHT_GREEN}Myst City\n"
	.string "{COLOR DARK_GREY}{LEFT_ARROW}{UP_ARROW} {COLOR LIGHT_GREEN}Frostpine Climb\l"
	.string "{COLOR DARK_GREY}{LEFT_ARROW} {COLOR LIGHT_GREEN}Enclava Town$"

TriadGorge_Sign_RouteSignMiddle_Text_0:
	.string "{COLOR LIGHT_GREEN}Triad Gorge\p"
	.string "{COLOR DARK_GREY}{UP_ARROW} {COLOR LIGHT_GREEN}Frostpine Climb\n"
	.string "{COLOR DARK_GREY}{LEFT_ARROW} {COLOR LIGHT_GREEN}Enclava Town\l"
	.string "{COLOR DARK_GREY}{RIGHT_ARROW} {COLOR LIGHT_GREEN}Myst City$"

TriadGorge_Object_RockSmashHiker_Text_0:
	.string "{COLOR BLUE}These rocks are lookin' like they're\n"
	.string "blocking the way to {COLOR GREEN}Myst City{COLOR BLUE}.\p"
	.string "If I had the {COLOR GREEN}Fiery Badge{COLOR BLUE} I could smash\n"
	.string "these rocks!$"

TriadGorge_Object_RockSmashHiker_Text_1:
	.string "{COLOR BLUE}Is that the {COLOR GREEN}Fiery Badge{COLOR BLUE}?\p"
	.string "Wowza!\n"
	.string "You must be a strong trainer!\p"
	.string "Here, take this!$"

TriadGorge_Object_RockSmashHiker_Text_2:
	.string "{COLOR BLUE}With that HM, you can remove these\n"
	.string "rocks and similar looking ones without\l"
	.string "a problem!\p"
	.string "I'm going to go get myself the {COLOR GREEN}Fiery\n"
	.string "Badge{COLOR BLUE} as well so I can use Rock Smash\l"
	.string "too!$"
