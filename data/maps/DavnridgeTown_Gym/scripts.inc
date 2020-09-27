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


DavnridgeGym_Object_Man::
	msgbox DavnridgeGym_Object_Man_Text_0, MSGBOX_NPC
	end


DavnridgeGym_Trainer_Lilith::
	lockall
	goto_if_unset FLAG_BADGE01_GET, DavnridgeGym_Trainer_Lilith_2
DavnridgeGym_Trainer_Lilith_1:
	msgbox DavnridgeGym_Trainer_Lilith_Text_4, MSGBOX_AUTOCLOSE
	releaseall
	end

DavnridgeGym_Trainer_Lilith_2:
	playse SE_MU_PACHI
	animateflash 2
	delay 10
	msgbox DavnridgeGym_Trainer_Lilith_Text_0, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_GYM_LEADER_LILITH, DavnridgeGym_Trainer_Lilith_Text_1
	animateflash 2
	setflag FLAG_BADGE01_GET
	settrainerflag TRAINER_GYM_HIKER_TYSON
	settrainerflag TRAINER_GYM_MINER_HEATH
	setvar VAR_DAVNRIDGEMINES_STATE, 2
	delay 5
	playfanfare MUS_ME_BACHI
	msgbox DavnridgeGym_Trainer_Lilith_Text_2
	waitfanfare
	msgbox DavnridgeGym_Trainer_Lilith_Text_3
	giveitem ITEM_TM39_ROCK_TOMB, 1
	goto DavnridgeGym_Trainer_Lilith_1


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

DavnridgeGym_Object_Man_Text_0:
	.string "{COLOR BLUE}Hey there champ!\p"
	.string "I take it that this is your first Gym\n"
	.string "Challenge, yes?\p"
	.string "This Gym's puzzle is a simple maze, but\n"
	.string "your vision is limited!\p"
	.string "Find your way through the maze and\n"
	.string "battle {COLOR GREEN}Lilith{COLOR BLUE}!$"

DavnridgeGym_Trainer_Lilith_Text_0:
	.string "Lilith: {COLOR RED}Glad to see you made it back from\n"
	.string "the mines!\p"
	.string "I believe in the sturdiness and defense\n"
	.string "of Rock-type Pokémon!\p"
	.string "That's why my team is made up of\n"
	.string "Rock-type Pokémon.\p"
	.string "You think I'm gonna go easy on you?\p"
	.string "Show me what you got!$"

DavnridgeGym_Trainer_Lilith_Text_1:
	.string "Well played!\p"
	.string "{PLAYER}...\n"
	.string "You outplayed me and my team!\p"
	.string "Take this badge!$"

DavnridgeGym_Trainer_Lilith_Text_2:
	.string "{COLOR GREEN}{PLAYER}{COLOR DARK_GREY} received the {COLOR GREEN}Gem Badge$"

DavnridgeGym_Trainer_Lilith_Text_3:
	.string "Lilith: {COLOR RED}That's an official {COLOR GREEN}Ryoko Pokémon\n"
	.string "League Badge{COLOR RED}!\p"
	.string "The technique {COLOR GREEN}Cut{COLOR RED} can now be used\n"
	.string "outside of battle!\p"
	.string "Take this TM as well!$"

DavnridgeGym_Trainer_Lilith_Text_4:
	.string "Lilith: {COLOR RED}Your next challenge will be in\n"
	.string "{COLOR GREEN}Enclava Town{COLOR RED}, which can be accessed\l"
	.string "through the {COLOR GREEN}Davnridge Mines{COLOR RED}.\p"
	.string "Go further you and your team's skill!$"
