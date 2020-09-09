DavnridgeTown_Gym_MapScripts::
	.byte 0


DavnridgeGym_Sign_GymSign::
	goto_if_set FLAG_BADGE01_GET, DavnridgeGym_Sign_GymSign_2
	msgbox DavnridgeGym_Sign_GymSign_Text_1, MSGBOX_SIGN, MSGBOX_SUB_METAL
DavnridgeGym_Sign_GymSign_1:
	end

DavnridgeGym_Sign_GymSign_2:
	msgbox DavnridgeGym_Sign_GymSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	goto DavnridgeGym_Sign_GymSign_1


DavnridgeGym_Trainer_Hiker::
	trainerbattle_single TRAINER_GYM_HIKER_TYSON, DavnridgeGym_Trainer_Hiker_Text_0, DavnridgeGym_Trainer_Hiker_Text_1
	msgbox DavnridgeGym_Trainer_Hiker_Text_2, MSGBOX_NPC
	end


DavnridgeGym_Trainer_Miner::
	trainerbattle_single TRAINER_GYM_MINER_HEATH, DavnridgeGym_Trainer_Miner_Text_0, DavnridgeGym_Trainer_Miner_Text_1
	msgbox DavnridgeGym_Trainer_Miner_Text_2, MSGBOX_NPC
	end


DavnridgeGym_Trainer_Lilith::
	lockall
	playse SE_MU_PACHI
	animateflash 2
	msgbox DavnridgeGym_Trainer_Lilith_Text_0, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_GYM_LEADER_LILITH, DavnridgeGym_Trainer_Lilith_Text_1
	delay 10
	msgbox DavnridgeGym_Trainer_Lilith_Text_2
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DavnridgeGym_Trainer_Lilith_Text_3
	giveitem ITEM_TM39_ROCK_TOMB, 1
	msgbox DavnridgeGym_Trainer_Lilith_Text_4, MSGBOX_AUTOCLOSE
	setflag FLAG_BADGE01_GET
	settrainerflag TRAINER_GYM_HIKER_TYSON
	settrainerflag TRAINER_GYM_MINER_HEATH
	setvar VAR_DAVNRIDGEMINES_STATE, 2
	releaseall
	end


DavnridgeGym_Sign_GymSign_Text_0:
	.string "{COLOR RED}Davnridge Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Rock\n"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Lilith\p"
	.string "{COLOR DARK_GREY}Winning Trainers: {COLOR LIGHT_GREEN}Skip, {PLAYER}$"

DavnridgeGym_Sign_GymSign_Text_1:
	.string "{COLOR RED}Davnridge Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Rock\n"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Lilith\p"
	.string "{COLOR DARK_GREY}Winning Trainers: {COLOR LIGHT_GREEN}Skip$"

DavnridgeGym_Trainer_Hiker_Text_0:
	.string "{COLOR BLUE}Wrong way!$"

DavnridgeGym_Trainer_Hiker_Text_1:
	.string "You'll never beat Lilith!$"

DavnridgeGym_Trainer_Hiker_Text_2:
	.string "{COLOR BLUE}Lilith perfers to use Rock Type\n"
	.string "Pokémon, she's really strong!$"

DavnridgeGym_Trainer_Miner_Text_0:
	.string "{COLOR BLUE}You're not getting past me!$"

DavnridgeGym_Trainer_Miner_Text_1:
	.string "Wow!\n"
	.string "You're strong!$"

DavnridgeGym_Trainer_Miner_Text_2:
	.string "{COLOR BLUE}Lilith is much stronger than I am!$"

DavnridgeGym_Trainer_Lilith_Text_0:
	.string "Lilith: {COLOR RED}Nice to see you here!\p"
	.string "I will be your first official {COLOR GREEN}Ryoko\n"
	.string "Pokémon League{COLOR RED} Gym battle!\p"
	.string "Don't think I'm going to be going easy\n"
	.string "on you!$"

DavnridgeGym_Trainer_Lilith_Text_1:
	.string "Well played!\p"
	.string "{PLAYER}...\n"
	.string "I can tell you're a strong trainer!\p"
	.string "Take this badge!$"

DavnridgeGym_Trainer_Lilith_Text_2:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GREY} received the {COLOR GREEN}Plain Badge$"

DavnridgeGym_Trainer_Lilith_Text_3:
	.string "Lilith: {COLOR RED}The {COLOR GREEN}Plain Badge{COLOR RED} is your official\n"
	.string "certification of beating me.\p"
	.string "Take this as well!$"

DavnridgeGym_Trainer_Lilith_Text_4:
	.string "Lilith: {COLOR RED}Your next challenge will be in\n"
	.string "{COLOR GREEN}Enclava Town{COLOR RED}, which can be access\l"
	.string "through the {COLOR GREEN}Davnridge Mines{COLOR RED}.\p"
	.string "I wish you the best of luck on your\n"
	.string "journey!$"
