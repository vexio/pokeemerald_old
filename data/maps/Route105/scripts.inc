Route105_MapScripts:: @ 81EE1DB
	map_script MAP_SCRIPT_ON_LOAD, Route105_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_OnFrame
	.byte 0

Route105_OnLoad: @ 81EE1EB
	call_if_unset FLAG_REGI_DOORS_OPENED, Route105_CloseRegiEntrance
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute105North
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute105South
	end

Route105_CloseRegiEntrance:: @ 81EE20B
	@setmetatile 9, 19, METATILE_General_RockWall_RockBase, 1
	@setmetatile 9, 20, METATILE_General_RockWall_SandBase, 1
	return

Route105_OnTransition: @ 81EE21E
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_NORTH
	call_if_eq AbnormalWeather_StartKyogreWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_105_SOUTH
	call_if_eq AbnormalWeather_StartKyogreWeather
	end

Route105_OnFrame: @ 81EE240
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route105_EventScript_Foster:: @ 81EE24A
	trainerbattle_single TRAINER_FOSTER, Route105_Text_FosterIntro, Route105_Text_FosterDefeated
	msgbox Route105_Text_FosterPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Luis:: @ 81EE261
	trainerbattle_single TRAINER_LUIS, Route105_Text_LuisIntro, Route105_Text_LuisDefeated
	msgbox Route105_Text_LuisPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Dominik:: @ 81EE278
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_DominikIntro, Route105_Text_DominikDefeated
	msgbox Route105_Text_DominikPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Beverly:: @ 81EE28F
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_BeverlyIntro, Route105_Text_BeverlyDefeated
	msgbox Route105_Text_PostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Imani:: @ 81EE2A6
	trainerbattle_single TRAINER_IMANI, Route105_Text_ImaniIntro, Route105_Text_ImaniDefeated
	msgbox Route105_Text_ImaniPostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Josue:: @ 81EE2BD
	trainerbattle_single TRAINER_JOSUE, Route105_Text_JosueIntro, Route105_Text_JosueDefeated
	msgbox Route105_Text_JosuePostBattle, MSGBOX_AUTOCLOSE
	end

Route105_EventScript_Andres:: @ 81EE2D4
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_AndresIntro, Route105_Text_AndresDefeated, Route105_EventScript_AndresRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, TRUE
	goto_if_eq Route105_EventScript_AndresRematch
	msgbox Route105_Text_AndresPostBattle, MSGBOX_DEFAULT
	release
	end

Route105_EventScript_AndresRegisterMatchCallAfterBattle:: @ 81EE300
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route105_Text_AndresRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANDRES_1
	release
	end

Route105_EventScript_AndresRematch:: @ 81EE31F
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_AndresRematchIntro, Route105_Text_AndresRematchDefeated
	msgbox Route105_Text_AndresRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route104_Text_DadPokenavCall: @ 81EE336
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "DAD: Oh, {PLAYER}?\p"
	.string "… … … … … …\n"
	.string "Where are you now?\l"
	.string "It sounds windy wherever you are.\p"
	.string "I just heard from DEVON's MR. STONE\n"
	.string "about your POKéNAV, so I decided\l"
	.string "to give you a call.\p"
	.string "It sounds like you're doing fine,\n"
	.string "so that's fine with me.\p"
	.string "You take care now.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

Route104_Text_RegisteredDadInPokenav: @ 81EE463
	.string "Registered DAD NORMAN\n"
	.string "in the POKéNAV.$"

EnclavaPass_Object_Youngster::
	compare VAR_PROTOGRUNTS_ENCLAVAGORGE, 0
	goto_if_eq EnclavaPass_Object_Youngster_1
	msgbox EnclavaPass_Object_Youngster_Text_1, MSGBOX_NPC
	end

EnclavaPass_Object_Youngster_1:
	msgbox EnclavaPass_Object_Youngster_Text_0, MSGBOX_NPC
	end


EnclavaPass_Trigger_NoPass::
	lockall
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 8
	msgbox EnclavaPass_Trigger_NoPass_Text_0, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end


EnclavaPass_Object_Officer::
	msgbox EnclavaPass_Trigger_NoPass_Text_0, MSGBOX_NPC
	end


EnclavaPass_Trigger_Grunts_0::
	lock
	delay 10
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	msgbox EnclavaPass_Trigger_Grunts_0_Text_0, MSGBOX_AUTOCLOSE
	applymovement 3, Common_Movement_WalkInPlaceUp
	applymovement 4, Common_Movement_WalkInPlaceUp
	applymovement 5, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement 3, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	delay 15
	msgbox EnclavaPass_Trigger_Grunts_0_Text_1, MSGBOX_AUTOCLOSE
	applymovement 3, Common_Movement_WalkInPlaceDown
	applymovement 4, Common_Movement_WalkInPlaceRight
	applymovement 5, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 5
	applymovement OBJ_EVENT_ID_PLAYER, EnclavaPass_Grunts_Movement_0
	waitmovement 0
	release
	end


EnclavaPass_Grunts_Movement_0:
	walk_up
	step_end

EnclavaPass_Trigger_Grunts_1::
	lock
	delay 5
	special SpawnCameraObject
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 12
	goto_if_eq EnclavaPass_Trigger_Grunts_1_2
	compare VAR_TEMP_0, 13
	goto_if_eq EnclavaPass_Trigger_Grunts_1_3
	compare VAR_TEMP_0, 14
	goto_if_eq EnclavaPass_Trigger_Grunts_1_4
EnclavaPass_Trigger_Grunts_1_1:
	delay 10
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	msgbox EnclavaPass_Trigger_Grunts_1_Text_0
	applymovement 4, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 10
	msgbox EnclavaPass_Trigger_Grunts_1_Text_1
	applymovement 5, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	msgbox EnclavaPass_Trigger_Grunts_1_Text_2
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	msgbox EnclavaPass_Trigger_Grunts_1_Text_3
	applymovement 5, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	msgbox EnclavaPass_Trigger_Grunts_1_Text_4
	applymovement 4, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	msgbox EnclavaPass_Trigger_Grunts_1_Text_5
	applymovement 5, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox EnclavaPass_Trigger_Grunts_1_Text_6
	applymovement 4, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox EnclavaPass_Trigger_Grunts_1_Text_7, MSGBOX_AUTOCLOSE
	delay 5
	applymovement 3, EnclavaPass_Grunts_Movement_1
	applymovement 4, EnclavaPass_Grunts_Movement_1
	applymovement 5, EnclavaPass_Grunts_Movement_1
	waitmovement 0
	removeobject 3
	removeobject 4
	removeobject 5
	compare VAR_TEMP_0, 12
	goto_if_eq EnclavaPass_Trigger_Grunts_1_9
	compare VAR_TEMP_0, 13
	goto_if_eq EnclavaPass_Trigger_Grunts_1_10
	compare VAR_TEMP_0, 14
	goto_if_eq EnclavaPass_Trigger_Grunts_1_11
EnclavaPass_Trigger_Grunts_1_8:
	delay 5
	special RemoveCameraObject
	setvar VAR_PROTOGRUNTS_ENCLAVAGORGE, 2
	setflag FLAG_ENCLAVAPASS_GRUNTS
	release
	end

EnclavaPass_Trigger_Grunts_1_2:
	applymovement OBJ_EVENT_ID_CAMERA, EnclavaPass_Grunts_CMovement_0_2
	waitmovement 0
	goto EnclavaPass_Trigger_Grunts_1_1

EnclavaPass_Trigger_Grunts_1_3:
	applymovement OBJ_EVENT_ID_CAMERA, EnclavaPass_Grunts_CMovement_0_1
	waitmovement 0
	goto EnclavaPass_Trigger_Grunts_1_1

EnclavaPass_Trigger_Grunts_1_4:
	applymovement OBJ_EVENT_ID_CAMERA, EnclavaPass_Grunts_CMovement_0_3
	waitmovement 0
	goto EnclavaPass_Trigger_Grunts_1_1

EnclavaPass_Trigger_Grunts_1_9:
	applymovement OBJ_EVENT_ID_CAMERA, EnclavaPass_Grunts_CMovement_1_2
	waitmovement 0
	goto EnclavaPass_Trigger_Grunts_1_8

EnclavaPass_Trigger_Grunts_1_10:
	applymovement OBJ_EVENT_ID_CAMERA, EnclavaPass_Grunts_CMovement_1_1
	waitmovement 0
	goto EnclavaPass_Trigger_Grunts_1_8

EnclavaPass_Trigger_Grunts_1_11:
	applymovement OBJ_EVENT_ID_CAMERA, EnclavaPass_Grunts_CMovement_1_3
	waitmovement 0
	goto EnclavaPass_Trigger_Grunts_1_8


EnclavaPass_Grunts_CMovement_0_1:
	walk_down
	walk_down
	walk_down
	step_end

EnclavaPass_Grunts_CMovement_0_2:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

EnclavaPass_Grunts_CMovement_0_3:
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnclavaPass_Grunts_Movement_1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EnclavaPass_Grunts_CMovement_1_1:
	walk_up
	walk_up
	walk_up
	step_end

EnclavaPass_Grunts_CMovement_1_2:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

EnclavaPass_Grunts_CMovement_1_3:
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

EnclavaPass_Object_Youngster_Text_0:
	.string "{COLOR BLUE}I wonder what those thugs are doing\n"
	.string "down there...$"

EnclavaPass_Object_Youngster_Text_1:
	.string "{COLOR BLUE}Looks like they finally opened up the\n"
	.string "path!\p"
	.string "Now you can go through {COLOR GREEN}Triad Gorge{COLOR BLUE}!$"

EnclavaPass_Trigger_NoPass_Text_0:
	.string "{COLOR BLUE}Hey there pal!\p"
	.string "This is the end of the first Beta of\n"
	.string "{COLOR GREEN}Pokémon Chroma{COLOR BLUE}.\p"
	.string "If you'd like to use your same save in a\n"
	.string "future version, please save inside of a\l"
	.string "{COLOR GREEN}Pokémon Center{COLOR BLUE}.\p"
	.string "Thank you so much for playing my game!\p"
	.string "Please feel free to join the {COLOR GREEN}Official\n"
	.string "Pokémon Chroma Discord{COLOR BLUE} to give\l"
	.string "feedback on the game.\p"
	.string "The link can be found on the official\n"
	.string "{COLOR GREEN}PokéCommunity{COLOR BLUE} thread.\p"
	.string "Once again, thank you for playing.\p"
	.string "- vxo, Lead Developer$"

EnclavaPass_Trigger_Grunts_0_Text_0:
	.string "Grunt 1: {COLOR BLUE}...then we need to-$"

EnclavaPass_Trigger_Grunts_0_Text_1:
	.string "Grunt 3: {COLOR RED}Hey kid!\n"
	.string "Nothing going on here.\p"
	.string "Now leave before I give you a reason to!$"

EnclavaPass_Trigger_Grunts_1_Text_0:
	.string "Grunt 1: {COLOR BLUE}Why are you still carrying\n"
	.string "around that dusty old book?$"

EnclavaPass_Trigger_Grunts_1_Text_1:
	.string "Grunt 2: {COLOR BLUE}Boss sent me t' get tha book!\p"
	.string "I was jus' followin' orders!$"

EnclavaPass_Trigger_Grunts_1_Text_2:
	.string "Grunt 3: {COLOR RED}Will you two shut up?\p"
	.string "We need to focus on the task at hand!$"

EnclavaPass_Trigger_Grunts_1_Text_3:
	.string "Grunt 1: {COLOR BLUE}If I may ask...\n"
	.string "What even is our task?$"

EnclavaPass_Trigger_Grunts_1_Text_4:
	.string "Grunt 3: {COLOR RED}We need to meetup with {COLOR GREEN}Haumea{COLOR RED},\n"
	.string "where he will give us more information\l"
	.string "on what we need to do.$"

EnclavaPass_Trigger_Grunts_1_Text_5:
	.string "Grunt 2: {COLOR GREEN}Haumea{COLOR BLUE}!\n"
	.string "He won' show up for a while!$"

EnclavaPass_Trigger_Grunts_1_Text_6:
	.string "Grunt 3: {COLOR RED}Just be patient...\p"
	.string "I think we can head further into {COLOR GREEN}Triad\n"
	.string "Gorge{COLOR RED} and see if we can meet with him\l"
	.string "faster.$"

EnclavaPass_Trigger_Grunts_1_Text_7:
	.string "Grunt 2: {COLOR BLUE}Soun's good t' me!\n"
	.string "Let's go!$"
