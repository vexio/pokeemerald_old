TeamProtoHideout_B2F_MapScripts::
	.byte 0


ProtoHideoutB2F_Trainer_Grunt3::
	trainerbattle_single TRAINER_GRUNT_HIDEOUT_3, ProtoHideoutB2F_Trainer_Grunt3_Text_0, ProtoHideoutB2F_Trainer_Grunt3_Text_1
	msgbox ProtoHideoutB2F_Trainer_Grunt3_Text_2, MSGBOX_NPC
	end


ProtoHideoutB2F_Trainer_Scientist4::
	trainerbattle_single TRAINER_SCIENTIST_HIDEOUT_4, ProtoHideoutB2F_Trainer_Scientist4_Text_0, ProtoHideoutB2F_Trainer_Scientist4_Text_1
	msgbox ProtoHideoutB2F_Trainer_Scientist4_Text_2, MSGBOX_NPC
	end


ProtoHideoutB2F_Trainer_Scientist5::
	trainerbattle_single TRAINER_SCIENTIST_HIDEOUT_5, ProtoHideoutB2F_Trainer_Scientist5_Text_0, ProtoHideoutB2F_Trainer_Scientist5_Text_1
	msgbox ProtoHideoutB2F_Trainer_Scientist5_Text_2, MSGBOX_NPC
	end


ProtoHideoutB2F_Trainer_Scientist6::
	trainerbattle_single TRAINER_SCIENTIST_HIDEOUT_6, ProtoHideoutB2F_Trainer_Scientist6_Text_0, ProtoHideoutB2F_Trainer_Scientist6_Text_1
	msgbox ProtoHideoutB2F_Trainer_Scientist6_Text_2, MSGBOX_NPC
	end


ProtoHideoutB2F_Object_Scientist1::
	lock
	faceplayer
	msgbox ProtoHideoutB2F_Object_Scientist1_Text_0, MSGBOX_AUTOCLOSE
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	release
	end


ProtoHideoutB2F_Object_Scientist2::
	lock
	faceplayer
	msgbox ProtoHideoutB2F_Object_Scientist2_Text_0, MSGBOX_AUTOCLOSE
	applymovement 2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	release
	end


ProtoHideoutB2F_Trainer_Grunt3_Text_0:
	.string "{COLOR RED}You!\n"
	.string "You're the intruder!$"

ProtoHideoutB2F_Trainer_Grunt3_Text_1:
	.string "Blasted!$"

ProtoHideoutB2F_Trainer_Grunt3_Text_2:
	.string "{COLOR RED}You are quite the strong trainer, but\n"
	.string "you wouldn't stand a chance against\l"
	.string "{COLOR GREEN}Apollo{COLOR RED}!$"

ProtoHideoutB2F_Trainer_Scientist4_Text_0:
	.string "{COLOR BLUE}According to my calculations, you're\n"
	.string "not going to win this battle!$"

ProtoHideoutB2F_Trainer_Scientist4_Text_1:
	.string "I guess my numbers were slightly off...$"

ProtoHideoutB2F_Trainer_Scientist4_Text_2:
	.string "{COLOR BLUE}My margin of error was very minimal, but\n"
	.string "alas it caused my downfall.$"

ProtoHideoutB2F_Trainer_Scientist5_Text_0:
	.string "{COLOR BLUE}Your lack of IQ will not be able to beat\n"
	.string "my 200 IQ battle-strategy!$"

ProtoHideoutB2F_Trainer_Scientist5_Text_1:
	.string "What?\n"
	.string "Have I been out-smarted?$"

ProtoHideoutB2F_Trainer_Scientist5_Text_2:
	.string "{COLOR BLUE}No one has out-smarted me in a Pokémon\n"
	.string "battle...$"

ProtoHideoutB2F_Trainer_Scientist6_Text_0:
	.string "{COLOR BLUE}I caught you in the corner of my eye!\p"
	.string "Now scram!$"

ProtoHideoutB2F_Trainer_Scientist6_Text_1:
	.string "What a drag!$"

ProtoHideoutB2F_Trainer_Scientist6_Text_2:
	.string "{COLOR BLUE}I wasn't blocking you from anything\n"
	.string "crazy important, just a simple revive I\l"
	.string "use to bait the other grunts into a\l"
	.string "quick battle!$"

ProtoHideoutB2F_Object_Scientist1_Text_0:
	.string "{COLOR BLUE}Hm?\n"
	.string "Oh no, I don't own any Pokémon.\p"
	.string "I just enjoy researching them.\p"
	.string "Now please, let me get back to work.$"

ProtoHideoutB2F_Object_Scientist2_Text_0:
	.string "{COLOR BLUE}These formulas tend to get more and\n"
	.string "more complex...\p"
	.string "Oh, I doubt you know anything about\n"
	.string "them.$"
