SeaspreyBeach_Cave_MapScripts::
	.byte 0


SeaspreyBeachCave_Trainer_Ranger::
	trainerbattle_single TRAINER_RANGER_NIKOLAI, SeaspreyBeachCave_Trainer_Ranger_Text_0, SeaspreyBeachCave_Trainer_Ranger_Text_1
	msgbox SeaspreyBeachCave_Trainer_Ranger_Text_2, MSGBOX_NPC
	end


SeaspreyBeachCave_Trainer_Hiker::
	trainerbattle_single TRAINER_HIKER_RODRIGO, SeaspreyBeachCave_Trainer_Hiker_Text_0, SeaspreyBeachCave_Trainer_Hiker_Text_1
	msgbox SeaspreyBeachCave_Trainer_Hiker_Text_2, MSGBOX_NPC
	end


SeaspreyBeachCave_Trainer_Ranger_Text_0:
	.string "{COLOR BLUE}A-ha! Caught you red-handed!$"

SeaspreyBeachCave_Trainer_Ranger_Text_1:
	.string "After seeing this battle, I can tell you\n"
	.string "are a good trainer!$"

SeaspreyBeachCave_Trainer_Ranger_Text_2:
	.string "{COLOR BLUE}If I ever catch a trainer not treating\n"
	.string "their Pokémon well, I would give them a\l"
	.string "battle of their lives!$"

SeaspreyBeachCave_Trainer_Hiker_Text_0:
	.string "{COLOR BLUE}Ho ho!\p"
	.string "I battle you'd like, I presume!$"

SeaspreyBeachCave_Trainer_Hiker_Text_1:
	.string "Ho ho!\n"
	.string "Great battle!$"

SeaspreyBeachCave_Trainer_Hiker_Text_2:
	.string "{COLOR BLUE}Ho ho!\p"
	.string "I love me a good battle once in a while.$"
