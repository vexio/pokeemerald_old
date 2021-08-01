ShilouWoods_Deep_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ShilouWoods_Deep_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ShilouWoods_Deep_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflashradius 2
	return


ShilouWoodsDeep_Trigger_LittleBoy_Event::
	lock
	fadeoutbgm 3
	delay 150
	playse SE_M_PERISH_SONG
	waitse
	applymovement 1, ShilouWoodsDeep_LittleBoyEvent_Movement_0
	waitmovement 0
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 7
	goto_if_eq ShilouWoodsDeep_Trigger_LittleBoy_Event_2
	compare VAR_TEMP_0, 6
	goto_if_eq ShilouWoodsDeep_Trigger_LittleBoy_Event_3
ShilouWoodsDeep_Trigger_LittleBoy_Event_1:
	msgbox ShilouWoodsDeep_Trigger_LittleBoy_Event_Text_0
	giveitem ITEM_SPELL_TAG, 1
	delay 20
	fadescreen FADE_TO_BLACK
	delay 15
	playse SE_M_NIGHTMARE
	waitse
	delay 15
	removeobject 1
	setflag FLAG_SHILOUWOODS_GHOST_BOY
	fadescreen FADE_FROM_BLACK
	setvar VAR_SHILOUWOODS_GHOST_BOY, 2
	delay 20
	fadenewbgm MUS_RG_POKE_TOWER
	release
	end

ShilouWoodsDeep_Trigger_LittleBoy_Event_2:
	applymovement 1, ShilouWoodsDeep_LittleBoyEvent_Movement_2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto ShilouWoodsDeep_Trigger_LittleBoy_Event_1

ShilouWoodsDeep_Trigger_LittleBoy_Event_3:
	applymovement 1, ShilouWoodsDeep_LittleBoyEvent_Movement_1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto ShilouWoodsDeep_Trigger_LittleBoy_Event_1


ShilouWoodsDeep_Trigger_HaventTalkedToLittleGirl::
	lock
	playse SE_M_NIGHTMARE
	waitse
	msgbox ShilouWoodsDeep_Trigger_HaventTalkedToLittleGirl_Text_0, MSGBOX_AUTOCLOSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	release
	end


ShilouWoodsDeep_LittleBoyEvent_Movement_0:
	face_down
	step_end

ShilouWoodsDeep_LittleBoyEvent_Movement_1:
	walk_slow_down
	walk_slow_left
	walk_slow_down
	walk_slow_down
	walk_in_place_slow_left
	step_end

ShilouWoodsDeep_LittleBoyEvent_Movement_2:
	walk_slow_down
	walk_slow_left
	walk_slow_left
	walk_slow_down
	walk_slow_down
	walk_in_place_slow_right
	step_end

ShilouWoodsDeep_Trigger_LittleBoy_Event_Text_0:
	.string "{COLOR BLUE}{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.\n"
	.string "{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.{PAUSE 20}.$"

ShilouWoodsDeep_Trigger_HaventTalkedToLittleGirl_Text_0:
	.string "A mysterious force prevents you from\n"
	.string "going further...$"
