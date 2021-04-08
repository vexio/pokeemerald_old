Route108_MapScripts:: @ 81EE689
	.byte 0

Route108_EventScript_Jerome:: @ 81EE68A
	trainerbattle_single TRAINER_JEROME, Route108_Text_JeromeIntro, Route108_Text_JeromeDefeated
	msgbox Route108_Text_JeromePostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Matthew:: @ 81EE6A1
	trainerbattle_single TRAINER_MATTHEW, Route108_Text_MatthewIntro, Route108_Text_MatthewDefeated
	msgbox Route108_Text_MatthewPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Tara:: @ 81EE6B8
	trainerbattle_single TRAINER_TARA, Route108_Text_TaraIntro, Route108_Text_TaraDefeated
	msgbox Route108_Text_TaraPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Missy:: @ 81EE6CF
	trainerbattle_single TRAINER_MISSY, Route108_Text_MissyIntro, Route108_Text_MissyDefeated
	msgbox Route108_Text_MissyPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Carolina:: @ 81EE6E6
	trainerbattle_single TRAINER_CAROLINA, Route108_Text_CarolinaIntro, Route108_Text_CarolinaDefeated
	msgbox Route108_Text_CarolinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route108_EventScript_Cory:: @ 81EE6FD
	trainerbattle_single TRAINER_CORY_1, Route108_Text_CoryIntro, Route108_Text_CoryDefeated, Route108_EventScript_CoryRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route108_EventScript_CoryRematch
	msgbox Route108_Text_CoryPostBattle, MSGBOX_DEFAULT
	release
	end

Route108_EventScript_CoryRegisterMatchCallAfterBattle:: @ 81EE729
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route108_Text_CoryRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CORY_1
	release
	end

Route108_EventScript_CoryRematch:: @ 81EE748
	trainerbattle_rematch TRAINER_CORY_1, Route108_Text_CoryRematchIntro, Route108_Text_CoryRematchDefeated
	msgbox Route108_Text_CoryRematchPostBattle, MSGBOX_AUTOCLOSE
	end

SeaspreyBeach_Trainer_Sailor1::
	trainerbattle_single TRAINER_SAILOR_SANTIAGO, SeaspreyBeach_Trainer_Sailor1_Text_0, SeaspreyBeach_Trainer_Sailor1_Text_1
	msgbox SeaspreyBeach_Trainer_Sailor1_Text_2, MSGBOX_NPC
	end


SeaspreyBeach_Trainer_Woman1::
	trainerbattle_single TRAINER_PARASOL_JUNE, SeaspreyBeach_Trainer_Woman1_Text_0, SeaspreyBeach_Trainer_Woman1_Text_1
	msgbox SeaspreyBeach_Trainer_Woman1_Text_2, MSGBOX_NPC
	end


SeaspreyBeach_Trainer_TuberF::
	trainerbattle_single TRAINER_TUBER_IZZIE, SeaspreyBeach_Trainer_TuberF_Text_0, SeaspreyBeach_Trainer_TuberF_Text_1
	msgbox SeaspreyBeach_Trainer_TuberF_Text_2, MSGBOX_NPC
	end


SeaspreyBeach_Trainer_Sailor2::
	trainerbattle_single TRAINER_SAILOR_LEE, SeaspreyBeach_Trainer_Sailor2_Text_0, SeaspreyBeach_Trainer_Sailor2_Text_1
	msgbox SeaspreyBeach_Trainer_Sailor2_Text_2, MSGBOX_NPC
	end


SeaspreyBeach_Sign_RouteSign::
	msgbox SeaspreyBeach_Sign_RouteSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


SeaspreyBeach_Trainer_Sailor1_Text_0:
	.string "{COLOR BLUE}The sea breeze!\p"
	.string "Take a deep breath...\n"
	.string "and let's batttle!$"

SeaspreyBeach_Trainer_Sailor1_Text_1:
	.string "A breezy battle for you!$"

SeaspreyBeach_Trainer_Sailor1_Text_2:
	.string "{COLOR GREEN}Seasprey Beach{COLOR BLUE} is my favorite place to\n"
	.string "relax.\p"
	.string "A really nice breeze and a beautiful\n"
	.string "view of {COLOR GREEN}Azure Bay{COLOR BLUE}.$"

SeaspreyBeach_Trainer_Woman1_Text_0:
	.string "{COLOR RED}A beautiful day on the beach, and a\n"
	.string "beautiful day for a battle!$"

SeaspreyBeach_Trainer_Woman1_Text_1:
	.string "Oh my!\n"
	.string "What a strong trainer you are!$"

SeaspreyBeach_Trainer_Woman1_Text_2:
	.string "{COLOR RED}A truly beautiful day!$"

SeaspreyBeach_Trainer_TuberF_Text_0:
	.string "{COLOR RED}Hi there!\p"
	.string "Do you wanna see my Pokémon friends?$"

SeaspreyBeach_Trainer_TuberF_Text_1:
	.string "My friends sure put up a fight!$"

SeaspreyBeach_Trainer_TuberF_Text_2:
	.string "{COLOR RED}I made those friends on the beach!\p"
	.string "They're really nice to me!$"

SeaspreyBeach_Trainer_Sailor2_Text_0:
	.string "{COLOR BLUE}Tryna take a lil' shortcut, eh?$"

SeaspreyBeach_Trainer_Sailor2_Text_1:
	.string "Hoho!$"

SeaspreyBeach_Trainer_Sailor2_Text_2:
	.string "{COLOR BLUE}Shortcuts may seem beneficial, but\n"
	.string "they can backfire sometimes!$"

SeaspreyBeach_Sign_RouteSign_Text_0:
	.string "{COLOR LIGHT_GREEN}Seasprey Bach\p"
	.string "{COLOR DARK_GREY}{UP_ARROW} {COLOR LIGHT_GREEN}Myst City\n"
	.string "{COLOR DARK_GREY}{DOWN_ARROW} {COLOR LIGHT_GREEN}Bayport City$"
