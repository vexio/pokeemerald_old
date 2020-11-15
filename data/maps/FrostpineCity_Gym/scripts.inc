FrostpineCity_Gym_MapScripts::
	.byte 0


FrostpineGym_Trigger_Button_1::
	lockall
	delay 5
	playse SE_TOY_DANGO
	setmetatile 11, 20, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 11, 21, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 11, 22, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 12, 20, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 12, 21, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 12, 22, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 13, 20, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 13, 21, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 13, 22, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 14, 20, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 14, 21, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 14, 22, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 10, 18, METATILE_FrostpineGym_ButtonActivated, 0
	special DrawWholeMapView
	setvar VAR_TEMP_F, 1
	releaseall
	end


FrostpineGym_Trigger_Button_2::
	lockall
	delay 5
	playse SE_TOY_DANGO
	setmetatile 5, 20, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 5, 21, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 5, 22, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 4, 20, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 4, 21, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 4, 22, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 3, 20, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 3, 21, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 3, 22, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 16, 13, METATILE_FrostpineGym_ButtonActivated, 0
	special DrawWholeMapView
	setvar VAR_TEMP_E, 1
	releaseall
	end


FrostpineGym_Trigger_Button_3::
	lockall
	delay 5
	playse SE_TOY_DANGO
	setmetatile 0, 16, METATILE_FrostpineGym_StoneBridge_Left, 0
	setmetatile 1, 16, METATILE_FrostpineGym_StoneBridge_Horizontal_Middle, 0
	setmetatile 2, 16, METATILE_FrostpineGym_StoneBridge_Right, 0
	setmetatile 0, 15, METATILE_FrostpineGym_StoneBridge_Left, 0
	setmetatile 1, 15, METATILE_FrostpineGym_StoneBridge_Horizontal_Middle, 0
	setmetatile 2, 15, METATILE_FrostpineGym_StoneBridge_Right, 0
	setmetatile 0, 25, METATILE_FrostpineGym_ButtonActivated_Dark, 0
	special DrawWholeMapView
	setvar VAR_TEMP_D, 1
	releaseall
	end


FrostpineGym_Trigger_Button_4::
	lockall
	delay 5
	playse SE_TOY_DANGO
	setmetatile 3, 12, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 3, 13, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 3, 14, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 4, 12, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 4, 13, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 4, 14, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 5, 12, METATILE_FrostpineGym_StoneBridge_Top, 0
	setmetatile 5, 13, METATILE_FrostpineGym_StoneBridge_Vertical_Middle, 0
	setmetatile 5, 14, METATILE_FrostpineGym_StoneBridge_Bottom, 0
	setmetatile 1, 13, METATILE_FrostpineGym_ButtonActivated, 0
	special DrawWholeMapView
	setvar VAR_TEMP_C, 1
	releaseall
	end


FrostpineGym_Trigger_Button_5::
	lockall
	delay 5
	playse SE_TOY_DANGO
	setmetatile 7, 10, METATILE_FrostpineGym_StoneBridge_Left, 0
	setmetatile 8, 10, METATILE_FrostpineGym_StoneBridge_Horizontal_Middle, 0
	setmetatile 9, 10, METATILE_FrostpineGym_StoneBridge_Right, 0
	setmetatile 7, 9, METATILE_FrostpineGym_StoneBridge_Left, 0
	setmetatile 8, 9, METATILE_FrostpineGym_StoneBridge_Horizontal_Middle, 0
	setmetatile 9, 9, METATILE_FrostpineGym_StoneBridge_Right, 0
	setmetatile 7, 8, METATILE_FrostpineGym_StoneBridge_Left, 0
	setmetatile 8, 8, METATILE_FrostpineGym_StoneBridge_Horizontal_Middle, 0
	setmetatile 9, 8, METATILE_FrostpineGym_StoneBridge_Right, 0
	setmetatile 11, 14, METATILE_FrostpineGym_ButtonActivated, 0
	special DrawWholeMapView
	setvar VAR_TEMP_B, 1
	releaseall
	end


FrostpineGym_Sign_GymSign::
	goto_if_set FLAG_BADGE03_GET, FrostpineGym_Sign_GymSign_2
	msgbox FrostpineGym_Sign_GymSign_Text_1, MSGBOX_SIGN, MSGBOX_SUB_METAL
FrostpineGym_Sign_GymSign_1:
	end

FrostpineGym_Sign_GymSign_2:
	msgbox FrostpineGym_Sign_GymSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	goto FrostpineGym_Sign_GymSign_1


FrostpineGym_Object_Man::
	msgbox FrostpineGym_Object_Man_Text_0, MSGBOX_NPC
	end


FrostpineGym_Trainer_Kindler_1::
	trainerbattle_single TRAINER_GYM_KINDLER_ISAI, FrostpineGym_Trainer_Kindler_1_Text_0, FrostpineGym_Trainer_Kindler_1_Text_1
	msgbox FrostpineGym_Trainer_Kindler_1_Text_2, MSGBOX_NPC
	end


FrostpineGym_Trainer_Maniac::
	trainerbattle_single TRAINER_GYM_MANIAC_COREY, FrostpineGym_Trainer_Maniac_Text_0, FrostpineGym_Trainer_Maniac_Text_1
	msgbox FrostpineGym_Trainer_Maniac_Text_2, MSGBOX_NPC
	end


FrostpineGym_Trainer_Ranger_F::
	trainerbattle_single TRAINER_GYM_RANGER_F_AMARI, FrostpineGym_Trainer_Ranger_F_Text_0, FrostpineGym_Trainer_Ranger_F_Text_1
	msgbox FrostpineGym_Trainer_Ranger_F_Text_2, MSGBOX_NPC
	end


FrostpineGym_Trainer_Kindler_2::
	trainerbattle_single TRAINER_GYM_KINDLER_FRANCO, FrostpineGym_Trainer_Kindler_2_Text_0, FrostpineGym_Trainer_Kindler_2_Text_1
	msgbox FrostpineGym_Trainer_Kindler_2_Text_2, MSGBOX_NPC
	end


FrostpineGym_Trainer_Bernie::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE03_GET, FrostpineGym_Trainer_Bernie_2
FrostpineGym_Trainer_Bernie_1:
	msgbox FrostpineGym_Trainer_Bernie_Text_5, MSGBOX_AUTOCLOSE
	release
	end

FrostpineGym_Trainer_Bernie_2:
	msgbox FrostpineGym_Trainer_Bernie_Text_0
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	msgbox FrostpineGym_Trainer_Bernie_Text_1, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_GYM_LEADER_BERNIE, FrostpineGym_Trainer_Bernie_Text_2
	setflag FLAG_BADGE03_GET
	playfanfare MUS_ME_BACHI
	msgbox FrostpineGym_Trainer_Bernie_Text_3
	waitfanfare
	msgbox FrostpineGym_Trainer_Bernie_Text_4
	giveitem ITEM_TM35_FLAMETHROWER, 1
	settrainerflag TRAINER_GYM_KINDLER_ISAI
	settrainerflag TRAINER_GYM_MANIAC_COREY
	settrainerflag TRAINER_GYM_RANGER_F_AMARI
	settrainerflag TRAINER_GYM_KINDLER_FRANCO
	goto FrostpineGym_Trainer_Bernie_1


FrostpineGym_Sign_GymSign_Text_0:
	.string "{COLOR RED}Frostpine Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Fire\n"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Bernie\p"
	.string "{COLOR DARK_GREY}Winning Trainers: {COLOR LIGHT_GREEN}Skip, {PLAYER}$"

FrostpineGym_Sign_GymSign_Text_1:
	.string "{COLOR RED}Frostpine Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Fire\n"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Bernie\p"
	.string "{COLOR DARK_GREY}Winning Trainers: {COLOR LIGHT_GREEN}Skip$"

FrostpineGym_Object_Man_Text_0:
	.string "{COLOR BLUE}Hey there Champ!\p"
	.string "This gym is making me sweat, and not\n"
	.string "because I'm working out!\p"
	.string "This gym's challenge puzzle consists of\n"
	.string "bridges and buttons.\p"
	.string "Use the buttons to activate the\n"
	.string "bridges, and work your way towards\l"
	.string "{COLOR GREEN}Bernie{COLOR BLUE}, the Gym Leader!$"

FrostpineGym_Trainer_Kindler_1_Text_0:
	.string "{COLOR BLUE}Stuck on an island surrounded by lava,\n"
	.string "eh?$"

FrostpineGym_Trainer_Kindler_1_Text_1:
	.string "Sizzling!$"

FrostpineGym_Trainer_Kindler_1_Text_2:
	.string "{COLOR BLUE}These buttons on each island will\n"
	.string "activate it's corresponding bridge.$"

FrostpineGym_Trainer_Maniac_Text_0:
	.string "{COLOR BLUE}Fire-type Pokémon are the best!$"

FrostpineGym_Trainer_Maniac_Text_1:
	.string "Gah!\n"
	.string "Fizzled out...$"

FrostpineGym_Trainer_Maniac_Text_2:
	.string "{COLOR BLUE}Fire-type Pokémon are weak to\n"
	.string "Water-type Pokémon and Ground-type\l"
	.string "Pokémon.$"

FrostpineGym_Trainer_Ranger_F_Text_0:
	.string "{COLOR RED}I've been training my Fire-type Pokémon\n"
	.string "to eventually be a Pokémon Gym\l"
	.string "Trainer!\p"
	.string "Prepare to lose!$"

FrostpineGym_Trainer_Ranger_F_Text_1:
	.string "Wow, you have some strong Pokémon!$"

FrostpineGym_Trainer_Ranger_F_Text_2:
	.string "{COLOR RED}Fire-type Pokémon may be the best, but\n"
	.string "their weaknesses are really powerful\l"
	.string "against them.$"

FrostpineGym_Trainer_Kindler_2_Text_0:
	.string "{COLOR BLUE}I'm the last trainer between you and\n"
	.string "{COLOR GREEN}Bernie{COLOR BLUE}!$"

FrostpineGym_Trainer_Kindler_2_Text_1:
	.string "Ouch!$"

FrostpineGym_Trainer_Kindler_2_Text_2:
	.string "{COLOR GREEN}Bernie{COLOR BLUE} is way better than me!\p"
	.string "Good luck against him!$"

FrostpineGym_Trainer_Bernie_Text_0:
	.string "Bernie: {COLOR BLUE}Hello fellow trainer!\p"
	.string "Er... uh...$"

FrostpineGym_Trainer_Bernie_Text_1:
	.string "Bernie: {COLOR BLUE}Right right!\n"
	.string "We need to battle!\p"
	.string "I hope you have some Burn Heals on you,\n"
	.string "prepare to feel the burn!$"

FrostpineGym_Trainer_Bernie_Text_2:
	.string "I lost again to you blasted young\n"
	.string "trainers!$"

FrostpineGym_Trainer_Bernie_Text_3:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GREY} received the {COLOR GREEN}Fiery Badge$"

FrostpineGym_Trainer_Bernie_Text_4:
	.string "Bernie: {COLOR BLUE}You youngings have gotten a lot\n"
	.string "better at battling, but I won't give up\l"
	.string "on improving!\p"
	.string "This badge will allow you to use {COLOR GREEN}Rock\n"
	.string "Smash{COLOR BLUE} outside of battle.\p"
	.string "As well, take this TM!$"

FrostpineGym_Trainer_Bernie_Text_5:
	.string "Bernie: {COLOR BLUE}Now, your next Gym Challenge is\n"
	.string "in {COLOR GREEN}Bayport City{COLOR BLUE}, which is south of {COLOR GREEN}Myst\l"
	.string "City{COLOR BLUE}.\p"
	.string "I wish you the best of luck on your\n"
	.string "future Gym Challenges!$"
