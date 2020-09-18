EnclavaTower_2F_MapScripts::
	.byte 0


EnclavaTower_2F_Trainer_ExpertM::
	trainerbattle_single TRAINER_EXPERT_TOBIAS, EnclavaTower_2F_Trainer_ExpertM_Text_0, EnclavaTower_2F_Trainer_ExpertM_Text_1
	msgbox EnclavaTower_2F_Trainer_ExpertM_Text_2, MSGBOX_NPC
	end


EnclavaTower_2F_Trainer_ExpertF::
	trainerbattle_single TRAINER_EXPERT_YASMIN, EnclavaTower_2F_Trainer_ExpertF_Text_0, EnclavaTower_2F_Trainer_ExpertF_Text_1
	msgbox EnclavaTower_2F_Trainer_ExpertF_Text_2, MSGBOX_NPC
	end


EnclavaTower_2F_Trainer_HexManiac::
	trainerbattle_single TRAINER_HEXMANIAC_DEJA, EnclavaTower_2F_Trainer_HexManiac_Text_0, EnclavaTower_2F_Trainer_HexManiac_Text_1
	msgbox EnclavaTower_2F_Trainer_HexManiac_Text_2, MSGBOX_NPC
	end


EnclavaTower_2F_Trainer_ExpertM_Text_0:
	.string "{COLOR BLUE}You don't look like a strong trainer...\p"
	.string "Show me your strength!$"

EnclavaTower_2F_Trainer_ExpertM_Text_1:
	.string "Very strong indeed!$"

EnclavaTower_2F_Trainer_ExpertM_Text_2:
	.string "{COLOR BLUE}Your strength definitely shows now\n"
	.string "that I can see the relationship you\l"
	.string "have with your Pokémon.$"

EnclavaTower_2F_Trainer_ExpertF_Text_0:
	.string "{COLOR RED}I can sense the bond you and your\n"
	.string "Pokémon have...\p"
	.string "Show me that bond!$"

EnclavaTower_2F_Trainer_ExpertF_Text_1:
	.string "The strength of your bond is immense!$"

EnclavaTower_2F_Trainer_ExpertF_Text_2:
	.string "{COLOR RED}The bond you and your partner's have is\n"
	.string "strong...\l"
	.string "I can sense it...$"

EnclavaTower_2F_Trainer_HexManiac_Text_0:
	.string "{COLOR RED}Eek!\n"
	.string "Behind you!$"

EnclavaTower_2F_Trainer_HexManiac_Text_1:
	.string "I thought I saw a ghost...$"

EnclavaTower_2F_Trainer_HexManiac_Text_2:
	.string "{COLOR RED}I see things that others don't...$"
