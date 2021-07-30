TeamProtoHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TeamProtoHideout_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TeamProtoHideout_B1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

TeamProtoHideout_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_PROTO_HIDEOUT, 1
	goto_if_eq TeamProtoHideout_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

TeamProtoHideout_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	setobjectxyperm 4, 16, 7
	setobjectxyperm 8, 17, 7
	return

TeamProtoHideout_B1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PROTO_HIDEOUT, 0, ProtoHideoutB1F_Object_FrontDoorGrunt
	.2byte 0


ProtoHideoutB1F_Object_FrontDoorGrunt::
	lockall
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox ProtoHideoutB1F_Object_FrontDoorGrunt_Text_0, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 4, ProtoHideoutB1F_Movement_0
	waitmovement 0
	removeobject 4
	applymovement 8, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox ProtoHideoutB1F_Object_FrontDoorGrunt_Text_1, MSGBOX_AUTOCLOSE
	applymovement 8, ProtoHideoutB1F_Movement_1
	waitmovement 0
	removeobject 8
	setflag FLAG_PROTO_HIDEOUT_B1F_OBJ
	setvar VAR_PROTO_HIDEOUT, 1
	releaseall
	end


ProtoHideoutB1F_Movement_0:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	step_end

ProtoHideoutB1F_Movement_1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	set_invisible
	step_end

ProtoHideoutB1F_Trainer_Grunt1::
	trainerbattle_single TRAINER_GRUNT_HIDEOUT_1, ProtoHideoutB1F_Trainer_Grunt1_Text_0, ProtoHideoutB1F_Trainer_Grunt1_Text_1
	msgbox ProtoHideoutB1F_Trainer_Grunt1_Text_2, MSGBOX_NPC
	end


ProtoHideoutB1F_Trainer_Grunt2::
	trainerbattle_single TRAINER_GRUNT_HIDEOUT_2, ProtoHideoutB1F_Trainer_Grunt2_Text_0, ProtoHideoutB1F_Trainer_Grunt2_Text_1
	msgbox ProtoHideoutB1F_Trainer_Grunt2_Text_2, MSGBOX_NPC
	end


ProtoHideoutB1F_Trainer_Scientist1::
	trainerbattle_single TRAINER_SCIENTIST_HIDEOUT_1, ProtoHideoutB1F_Trainer_Scientist1_Text_0, ProtoHideoutB1F_Trainer_Scientist1_Text_1
	msgbox ProtoHideoutB1F_Trainer_Scientist1_Text_2, MSGBOX_NPC
	end


ProtoHideoutB1F_Trainer_Scientist2::
	trainerbattle_single TRAINER_SCIENTIST_HIDEOUT_2, ProtoHideoutB1F_Trainer_Scientist2_Text_0, ProtoHideoutB1F_Trainer_Scientist2_Text_1
	msgbox ProtoHideoutB1F_Trainer_Scientist2_Text_2, MSGBOX_NPC
	end


ProtoHideoutB1F_Trainer_Scientist3::
	trainerbattle_single TRAINER_SCIENTIST_HIDEOUT_3, ProtoHideoutB1F_Trainer_Scientist3_Text_0, ProtoHideoutB1F_Trainer_Scientist3_Text_1
	msgbox ProtoHideoutB1F_Trainer_Scientist3_Text_2, MSGBOX_NPC
	end


ProtoHideoutB1F_Object_FrontDoorGrunt_Text_0:
	.string "Bartender: {COLOR BLUE}Y-You followed!$"

ProtoHideoutB1F_Object_FrontDoorGrunt_Text_1:
	.string "Skip: {COLOR BLUE}What is this place?\p"
	.string "This seems like some sort of hideout\n"
	.string "for {COLOR GREEN}Team Proto{COLOR BLUE}...\p"
	.string "Time to show these proto losers whose\n"
	.string "the better trainer!$"

ProtoHideoutB1F_Trainer_Grunt1_Text_0:
	.string "{COLOR BLUE}Hey!\n"
	.string "You're not suppose to be here!$"

ProtoHideoutB1F_Trainer_Grunt1_Text_1:
	.string "Gah!$"

ProtoHideoutB1F_Trainer_Grunt1_Text_2:
	.string "{COLOR BLUE}How did a kid like you find yourself\n"
	.string "down here?$"

ProtoHideoutB1F_Trainer_Grunt2_Text_0:
	.string "{COLOR RED}Trying to sneak in?$"

ProtoHideoutB1F_Trainer_Grunt2_Text_1:
	.string "Sneaky, sneaky...$"

ProtoHideoutB1F_Trainer_Grunt2_Text_2:
	.string "{COLOR RED}Scram!\n"
	.string "This is our operation!$"

ProtoHideoutB1F_Trainer_Scientist1_Text_0:
	.string "{COLOR BLUE}I can't get this machine to work...\p"
	.string "How about a quick battle?$"

ProtoHideoutB1F_Trainer_Scientist1_Text_1:
	.string "Well executed!$"

ProtoHideoutB1F_Trainer_Scientist1_Text_2:
	.string "{COLOR BLUE}I-I don't actually work for {COLOR GREEN}Team Proto{COLOR BLUE},\n"
	.string "I'm just a contracted hire to research\l"
	.string "whatever they give me.$"

ProtoHideoutB1F_Trainer_Scientist2_Text_0:
	.string "{COLOR BLUE}Don't interrupt my work!$"

ProtoHideoutB1F_Trainer_Scientist2_Text_1:
	.string "Now, let me get back to work!$"

ProtoHideoutB1F_Trainer_Scientist2_Text_2:
	.string "{COLOR BLUE}I'm trying to work, leave me be!$"

ProtoHideoutB1F_Trainer_Scientist3_Text_0:
	.string "{COLOR BLUE}According to my findings, {COLOR GREEN}Team Proto{COLOR BLUE}\n"
	.string "shall be successful!$"

ProtoHideoutB1F_Trainer_Scientist3_Text_1:
	.string "Team Proto will rise!$"

ProtoHideoutB1F_Trainer_Scientist3_Text_2:
	.string "{COLOR GREEN}Team Proto{COLOR BLUE} will use the powers of the\n"
	.string "mythical {COLOR GREEN}Darkrai{COLOR BLUE} and {COLOR GREEN}Cresselia{COLOR BLUE}!$"
