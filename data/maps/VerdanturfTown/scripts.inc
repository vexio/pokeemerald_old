VerdanturfTown_MapScripts:: @ 81EB566
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition: @ 81EB56C
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin:: @ 81EB575
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen:: @ 81EB594
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement 2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man:: @ 81EB5A8
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper:: @ 81EB5B1
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy:: @ 81EB5BA
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen:: @ 81EB5CF
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign:: @ 81EB5D9
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign:: @ 81EB5E2
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign:: @ 81EB5EB
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign:: @ 81EB5F4
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel: @ 81EB5FD
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid POKéMON.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"

VerdanturfTown_Text_ManDugTunnelForLove: @ 81EB6E0
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"

VerdanturfTown_Text_AirCleanHere: @ 81EB736
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"

VerdanturfTown_Text_MakeBattleTentDebut: @ 81EB7E2
	.string "My POKéMON and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my BATTLE TENT\n"
	.string "debut in this town.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave: @ 81EB854
	.string "Did you see the cave next to the\n"
	.string "POKéMON MART?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow: @ 81EB935
	.string "That cave next to the POKéMON MART\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new DEVON products in RUSTBORO now.$"

VerdanturfTown_Text_TownSign: @ 81EB9C4
	.string "VERDANTURF TOWN\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"

VerdanturfTown_Text_WandasHouse: @ 81EBA11
	.string "WANDA'S HOUSE$"

VerdanturfTown_Text_BattleTentSign: @ 81EBA1F
	.string "BATTLE TENT VERDANTURF SITE\n"
	.string "“Feast Your Eyes on Battles!”$"

VerdanturfTown_Text_RusturfTunnelSign: @ 81EBA59
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

FrostpineCity_Sign_FriendshipRater::
	msgbox FrostpineCity_Sign_FriendshipRater_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


FrostpineCity_Sign_CitySign::
	msgbox FrostpineCity_Sign_CitySign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


FrostpineCity_Sign_GymSign::
	msgbox FrostpineCity_Sign_GymSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


FrostpineCity_Sign_IronwoodForest::
	msgbox FrostpineCity_Sign_IronwoodForest_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


FrostpineCity_Object_IronwoodForestTrees::
	msgbox FrostpineCity_Object_IronwoodForestTrees_Text_0, MSGBOX_SIGN
	end


FrostpineCity_Object_Ranger::
	msgbox FrostpineCity_Object_Ranger_Text_0, MSGBOX_NPC
	end


FrostpineCity_Object_Kindler::
	msgbox FrostpineCity_Object_Kindler_Text_0, MSGBOX_NPC
	end


FrostpineCity_Object_LittleGirl::
	msgbox FrostpineCity_Object_LittleGirl_Text_0, MSGBOX_NPC
	end


FrostpineCity_Object_Boy::
	msgbox FrostpineCity_Object_Boy_Text_0, MSGBOX_NPC
	end


FrostpineCity_Trigger_RivalEvent::
	lockall
	delay 15
	opendoor 40, 28
	waitdooranim
	applymovement 9, FrostpineCity_RivalEvent_Movement_0
	waitmovement 0
	closedoor 40, 28
	applymovement 9, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	delay 16
	playbgm MUS_RG_ENCOUNTER_RIVAL, 0
	msgbox FrostpineCity_Trigger_RivalEvent_Text_0, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 29
	goto_if_eq FrostpineCity_Trigger_RivalEvent_2
	compare VAR_TEMP_1, 30
	goto_if_eq FrostpineCity_Trigger_RivalEvent_3
	compare VAR_TEMP_1, 30
	goto_if_eq FrostpineCity_Trigger_RivalEvent_4
FrostpineCity_Trigger_RivalEvent_1:
	delay 20
	msgbox FrostpineCity_Trigger_RivalEvent_Text_1, MSGBOX_AUTOCLOSE
	fadescreen FADE_TO_BLACK
	special HealPlayerParty
	playse SE_USE_ITEM
	waitse
	fadescreen FADE_FROM_BLACK
	delay 16
	msgbox FrostpineCity_Trigger_RivalEvent_Text_2, MSGBOX_AUTOCLOSE
	compare VAR_STARTER_MON, 0
	goto_if_eq FrostpineCity_Trigger_RivalEvent_9
	compare VAR_STARTER_MON, 1
	goto_if_eq FrostpineCity_Trigger_RivalEvent_10
	compare VAR_STARTER_MON, 2
	goto_if_eq FrostpineCity_Trigger_RivalEvent_11
FrostpineCity_Trigger_RivalEvent_8:
	playbgm MUS_RG_RIVAL_EXIT, 0
	delay 5
	msgbox FrostpineCity_Trigger_RivalEvent_Text_4, MSGBOX_AUTOCLOSE
	compare VAR_TEMP_1, 29
	goto_if_eq FrostpineCity_Trigger_RivalEvent_16
	compare VAR_TEMP_1, 30
	goto_if_eq FrostpineCity_Trigger_RivalEvent_17
	compare VAR_TEMP_1, 30
	goto_if_eq FrostpineCity_Trigger_RivalEvent_18
FrostpineCity_Trigger_RivalEvent_15:
	removeobject 9
	setflag FLAG_FROSTPINE_RIVAL_EVENT
	setvar VAR_FROSTPINE_CITY_RIVAL_EVENT, 1
	fadenewbgm MUS_RG_MYSTERY_GIFT
	releaseall
	end

FrostpineCity_Trigger_RivalEvent_2:
	applymovement 9, FrostpineCity_RivalEvent_Movement_1_0
	waitmovement 0
	goto FrostpineCity_Trigger_RivalEvent_1

FrostpineCity_Trigger_RivalEvent_3:
	applymovement 9, FrostpineCity_RivalEvent_Movement_1_1
	waitmovement 0
	goto FrostpineCity_Trigger_RivalEvent_1

FrostpineCity_Trigger_RivalEvent_4:
	applymovement 9, FrostpineCity_RivalEvent_Movement_1_2
	waitmovement 0
	goto FrostpineCity_Trigger_RivalEvent_1

FrostpineCity_Trigger_RivalEvent_9:
	trainerbattle_no_intro TRAINER_SKIP_FIRE_2, FrostpineCity_Trigger_RivalEvent_Text_3
	goto FrostpineCity_Trigger_RivalEvent_8

FrostpineCity_Trigger_RivalEvent_10:
	trainerbattle_no_intro TRAINER_SKIP_WATER_2, FrostpineCity_Trigger_RivalEvent_Text_3
	goto FrostpineCity_Trigger_RivalEvent_8

FrostpineCity_Trigger_RivalEvent_11:
	trainerbattle_no_intro TRAINER_SKIP_GRASS_2, FrostpineCity_Trigger_RivalEvent_Text_3
	goto FrostpineCity_Trigger_RivalEvent_8

FrostpineCity_Trigger_RivalEvent_16:
	applymovement 9, FrostpineCity_RivalEvent_Movement_2_0
	waitmovement 0
	goto FrostpineCity_Trigger_RivalEvent_15

FrostpineCity_Trigger_RivalEvent_17:
	applymovement 9, FrostpineCity_RivalEvent_Movement_2_1
	waitmovement 0
	goto FrostpineCity_Trigger_RivalEvent_15

FrostpineCity_Trigger_RivalEvent_18:
	applymovement 9, FrostpineCity_RivalEvent_Movement_2_2
	waitmovement 0
	goto FrostpineCity_Trigger_RivalEvent_15


FrostpineCity_RivalEvent_Movement_0:
	walk_down
	walk_down
	step_end

FrostpineCity_RivalEvent_Movement_1_0:
	walk_left
	step_end

FrostpineCity_RivalEvent_Movement_1_1:
	walk_down
	walk_left
	step_end

FrostpineCity_RivalEvent_Movement_1_2:
	walk_down
	walk_down
	walk_left
	step_end

FrostpineCity_RivalEvent_Movement_2_0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FrostpineCity_RivalEvent_Movement_2_1:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FrostpineCity_RivalEvent_Movement_2_2:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

FrostpineCity_Sign_Gate::
	msgbox FrostpineCity_Sign_Gate_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	return


FrostpineCity_Sign_FriendshipRater_Text_0:
	.string "{COLOR LIGHT_GREEN}The Friendship Rater\n"
	.string "{COLOR DARK_GREY}“Test your partner's friendliness!”$"

FrostpineCity_Sign_CitySign_Text_0:
	.string "{COLOR LIGHT_GREEN}Frostpine City\p"
	.string "{COLOR DARK_GREY}“The White Forest of the East”$"

FrostpineCity_Sign_GymSign_Text_0:
	.string "{COLOR RED}Frostpine City Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Bernie\n"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Fire$"

FrostpineCity_Sign_IronwoodForest_Text_0:
	.string "{COLOR LIGHT_GREEN}Ironwood Forest$"

FrostpineCity_Object_IronwoodForestTrees_Text_0:
	.string "This tree seems sturdier than others...\p"
	.string "Looks like this tree isn't cuttable\n"
	.string "using {COLOR GREEN}Cut{COLOR DARK_GREY}.$"

FrostpineCity_Object_Ranger_Text_0:
	.string "{COLOR BLUE}It's really cold up here!\p"
	.string "I bet it's even colder at the peak of {COLOR GREEN}Mt.\n"
	.string "Hood{COLOR BLUE}!$"

FrostpineCity_Object_Kindler_Text_0:
	.string "{COLOR BLUE}My Fire-type Pokémon keep me nice and\n"
	.string "warm in this freezing weather.$"

FrostpineCity_Object_LittleGirl_Text_0:
	.string "{COLOR RED}I like to play in the ice pond!\p"
	.string "It's fun sliding around on the ice!$"

FrostpineCity_Object_Boy_Text_0:
	.string "{COLOR BLUE}The forest up ahead is {COLOR GREEN}Ironwood Forest{COLOR BLUE},\n"
	.string "which connects to {COLOR GREEN}Ironwood Town{COLOR BLUE}.\p"
	.string "But I can't seem to get past these\n"
	.string "trees...\p"
	.string "They look just like the other cuttable\n"
	.string "trees, but they are sturdier.\p"
	.string "If you wanted to cut those down, you\n"
	.string "would need a stronger cut move.$"

FrostpineCity_Trigger_RivalEvent_Text_0:
	.string "Skip: {COLOR BLUE} What's up Slowpoke!$"

FrostpineCity_Trigger_RivalEvent_Text_1:
	.string "Skip: {COLOR BLUE}Are you shivering?\n"
	.string "It's freezing up here!\p"
	.string "You look pretty beat up from that climb,\n"
	.string "let me heal your Pokémon.$"

FrostpineCity_Trigger_RivalEvent_Text_2:
	.string "Skip: {COLOR BLUE}I'm all warmed up from my Gym\n"
	.string "Battle against {COLOR GREEN}Bernie{COLOR BLUE}!\p"
	.string "He wasn't too difficult, but I've been\n"
	.string "training quickly!\p"
	.string "I still got some steam left from that\n"
	.string "battle, let me burn the rest of it off\l"
	.string "with you!$"

FrostpineCity_Trigger_RivalEvent_Text_3:
	.string "I barely even broke a sweat!$"

FrostpineCity_Trigger_RivalEvent_Text_4:
	.string "Skip: {COLOR BLUE}Hmph.\p"
	.string "You still managed to win...\p"
	.string "I'll be on my way to {COLOR GREEN}Bayport City{COLOR BLUE} for our\n"
	.string "next Gym Challenge, which is just south\l"
	.string "of {COLOR GREEN}Myst City{COLOR BLUE}.$"

FrostpineCity_Sign_Gate_Text_0:
	.string "{COLOR LIGHT_GREEN}Frostpine Gate$"
