BayportCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BayportGym_SetHoleWarp

BayportGym_SetHoleWarp::
	setholewarp MAP_BAYPORT_CITY_GYM, 255, 9, 29
	end


BayportGym_Sign_GymSign::
	goto_if_set FLAG_BADGE04_GET, BayportGym_Sign_GymSign_2
	msgbox BayportGym_Sign_GymSign_Text_1, MSGBOX_SIGN, MSGBOX_SUB_METAL
BayportGym_Sign_GymSign_1:
	end

BayportGym_Sign_GymSign_2:
	msgbox BayportGym_Sign_GymSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	goto BayportGym_Sign_GymSign_1


BayportGym_Trainer_Lucille::
	trainerbattle_single TRAINER_GYM_HEXMANIAC_LUCILLE, BayportGym_Trainer_Lucille_Text_0, BayportGym_Trainer_Lucille_Text_1
	msgbox BayportGym_Trainer_Lucille_Text_2, MSGBOX_NPC
	end


BayportGym_Trainer_Xzavier::
	trainerbattle_single TRAINER_GYM_EXPERT_XZAVIER, BayportGym_Trainer_Xzavier_Text_0, BayportGym_Trainer_Xzavier_Text_1
	msgbox BayportGym_Trainer_Xzavier_Text_2, MSGBOX_NPC
	end


BayportGym_Trainer_Mireya::
	trainerbattle_single TRAINER_GYM_EXPERT_MIREYA, BayportGym_Trainer_Mireya_Text_0, BayportGym_Trainer_Mireya_Text_1
	msgbox BayportGym_Trainer_Mireya_Text_2, MSGBOX_NPC
	end


BayportGym_Trainer_Haven::
	trainerbattle_single TRAINER_GYM_EXPERT_HAVEN, BayportGym_Trainer_Haven_Text_0, BayportGym_Trainer_Haven_Text_1
	msgbox BayportGym_Trainer_Haven_Text_2, MSGBOX_NPC
	end


BayportGym_Trainer_Amara::
	trainerbattle_single TRAINER_GYM_HEXMANIAC_AMARA, BayportGym_Trainer_Amara_Text_0, BayportGym_Trainer_Amara_Text_1
	msgbox BayportGym_Trainer_Amara_Text_2, MSGBOX_NPC
	end


BayportGym_Trainer_Edgar::
	lockall
	goto_if_unset FLAG_BADGE04_GET, BayportGym_Trainer_Edgar_2
BayportGym_Trainer_Edgar_1:
	msgbox BayportGym_Trainer_Edgar_Text_4, MSGBOX_AUTOCLOSE
	releaseall
	end

BayportGym_Trainer_Edgar_2:
	faceplayer
	msgbox BayportGym_Trainer_Edgar_Text_0, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_GYM_LEADER_EDGAR, BayportGym_Trainer_Edgar_Text_1
	setflag FLAG_BADGE04_GET
	settrainerflag TRAINER_GYM_HEXMANIAC_LUCILLE
	settrainerflag TRAINER_GYM_EXPERT_XZAVIER
	settrainerflag TRAINER_GYM_EXPERT_MIREYA
	settrainerflag TRAINER_GYM_EXPERT_HAVEN
	settrainerflag TRAINER_GYM_HEXMANIAC_AMARA
	setvar VAR_CYPRESS_PROTO_EVENT_STATE, 4
	delay 5
	playfanfare MUS_ME_BACHI
	msgbox BayportGym_Trainer_Edgar_Text_2
	waitfanfare
	msgbox BayportGym_Trainer_Edgar_Text_3
	giveitem ITEM_TM30_SHADOW_BALL
	goto BayportGym_Trainer_Edgar_1


BayportGym_Trigger_EdgeFall::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, BayportGym_Movement_SetInvis
	waitmovement 0
	playse SE_RU_HYUU
	delay 60
	warpsilent MAP_BAYPORT_CITY_GYM, 0, 0, 0
	releaseall
	end


BayportGym_Movement_SetInvis:
	set_invisible
	step_end

BayportGym_Sign_GymSign_Text_0:
	.string "{COLOR RED}Bayport Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Ghost\n"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Edgar\p"
	.string "{COLOR DARK_GREY}Winning Trainers: {COLOR LIGHT_GREEN}Skip, {PLAYER}$"

BayportGym_Sign_GymSign_Text_1:
	.string "{COLOR RED}Bayport Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Ghost\n"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Edgar\p"
	.string "{COLOR DARK_GREY}Winning Trainers: {COLOR LIGHT_GREEN}Skip$"

BayportGym_Trainer_Lucille_Text_0:
	.string "{COLOR RED}Have you seen the spirits that haunt\n"
	.string "this city?$"

BayportGym_Trainer_Lucille_Text_1:
	.string "The spirits...$"

BayportGym_Trainer_Lucille_Text_2:
	.string "{COLOR RED}The spirits haunt this city...$"

BayportGym_Trainer_Xzavier_Text_0:
	.string "{COLOR BLUE}Who goes there?$"

BayportGym_Trainer_Xzavier_Text_1:
	.string "A disruption in the spirits, I sense...$"

BayportGym_Trainer_Xzavier_Text_2:
	.string "{COLOR BLUE}The spirits sense you, trainer.\p"
	.string "You are a welcomed one...\n"
	.string "but not a trusted one.$"

BayportGym_Trainer_Mireya_Text_0:
	.string "{COLOR RED}You have chosen the wrong path,\n"
	.string "trainer.$"

BayportGym_Trainer_Mireya_Text_1:
	.string "You've made a mistake, but you grew\n"
	.string "from your mistake.$"

BayportGym_Trainer_Mireya_Text_2:
	.string "{COLOR RED}Careful to not choose the wrong path.$"

BayportGym_Trainer_Haven_Text_0:
	.string "{COLOR RED}Watch your step!$"

BayportGym_Trainer_Haven_Text_1:
	.string "You almost got me spooked!$"

BayportGym_Trainer_Haven_Text_2:
	.string "{COLOR RED}Watch your step around here!$"

BayportGym_Trainer_Amara_Text_0:
	.string "{COLOR RED}............\n"
	.string "............$"

BayportGym_Trainer_Amara_Text_1:
	.string "............\n"
	.string "............$"

BayportGym_Trainer_Amara_Text_2:
	.string "{COLOR RED}............\n"
	.string ".............$"

BayportGym_Trainer_Edgar_Text_0:
	.string "Edgar: {COLOR BLUE}Nice to meet you, young\n"
	.string "traveller.\p"
	.string "You come to my gym for my knowledge, or\n"
	.string "am I just another check-mark on your\l"
	.string "list?\p"
	.string "Nevertheless, you've come here for a\n"
	.string "challenge, and I shall provide!$"

BayportGym_Trainer_Edgar_Text_1:
	.string "Magnificant!$"

BayportGym_Trainer_Edgar_Text_2:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GREY} received the {COLOR GREEN}Shade Badge$"

BayportGym_Trainer_Edgar_Text_3:
	.string "Edgar: {COLOR BLUE}Might I say, trainer, you have\n"
	.string "impressive battling skills.\p"
	.string "I've only seen a few trainers battle the\n"
	.string "way you do, and it's quite a charming\l"
	.string "way to battle.\p"
	.string "The {COLOR GREEN}Shade Badge{COLOR BLUE} will grant you the\n"
	.string "ability to use {COLOR GREEN}Strength{COLOR BLUE} outside of\l"
	.string "battle.\p"
	.string "As an additional token of graditude,\n"
	.string "please take this.$"

BayportGym_Trainer_Edgar_Text_4:
	.string "Edgar: {COLOR BLUE}Your next gym challenge will be in\n"
	.string "{COLOR GREEN}Altos City{COLOR BLUE}, east of {COLOR GREEN}Myst City{COLOR BLUE} and\l"
	.string "through {COLOR GREEN}Shilou Woods{COLOR BLUE}.\p"
	.string "I wish you the best of luck with the\n"
	.string "rest of your journey.$"
