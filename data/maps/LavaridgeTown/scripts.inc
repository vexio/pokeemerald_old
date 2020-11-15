LavaridgeTown_MapScripts:: @ 81EA4D3
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition: @ 81EA4DE
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call EnclavaTown_Mapscripts_LarsLocation
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_CheckSetRivalPos
	compare VAR_LAVARIDGE_TOWN_STATE, 1
	call_if_eq LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut:: @ 81EA514
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos:: @ 81EA518
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 9
	goto_if_eq LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos:: @ 81EA529
	setobjectxyperm 8, 11, 9
	setobjectxyperm 7, 9, 8
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers:: @ 81EA53F
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup:: @ 81EA543
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame: @ 81EA547
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	map_script_2 VAR_ENCLAVATOWER_STATE, 1, EnclavaTown_Mapscript_Lars
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles:: @ 81EA551
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalNoticePlayer
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LavaridgeTown_EventScript_PlayMayMusic
	compare VAR_RESULT, FEMALE
	call_if_eq LavaridgeTown_EventScript_PlayBrendanMusic
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalApproachPlayer1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LavaridgeTown_EventScript_MayGiveGoGoggles
	compare VAR_RESULT, FEMALE
	goto_if_eq LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles:: @ 81EA5B5
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles:: @ 81EA5DA
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit:: @ 81EA5FF
	closemessage
	removeobject 8
	addobject 7
	delay 30
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_RivalExit1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_RivalExit2
	removeobject 7
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic:: @ 81EA630
	playbgm MUS_GIRL_SUP, 1
	return

LavaridgeTown_EventScript_PlayBrendanMusic:: @ 81EA635
	playbgm MUS_BOY_SUP, 1
	return

LavaridgeTown_EventScript_RivalNoticePlayer:: @ 81EA63A
	applymovement 8, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop:: @ 81EA65C
	opendoor 12, 15
	waitdooranim
	addobject 8
	applymovement 8, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement 8, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1:: @ 81EA6A1
	applymovement 8, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2:: @ 81EA6AC
	applymovement 8, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1:: @ 81EA6B7
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement 7, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2:: @ 81EA6C9
	applymovement 7, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2: @ 81EA6D4
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit: @ 81EA6DF
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LavaridgeTown_Movement_RivalExit1: @ 81EA6E3
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2: @ 81EA6ED
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1: @ 81EA6F4
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop: @ 81EA6F8
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger:: @ 81EA6FA
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings:: @ 81EA70B
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM:: @ 81EA70E
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan:: @ 81EA717
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin:: @ 81EA720
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1:: @ 81EA729
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2:: @ 81EA732
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF:: @ 81EA73B
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman:: @ 81EA744
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_FANFA4
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg:: @ 81EA787
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg:: @ 81EA791
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg:: @ 81EA79B
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign:: @ 81EA7A5
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign:: @ 81EA7AE
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign:: @ 81EA7B7
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis: @ 81EA7C0
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
	.string "Oh? While I visited the hot springs,\n"
	.string "you got the LAVARIDGE GYM BADGE.\p"
	.string "You must have collected\n"
	.string "good POKéMON…\l"
	.string "No, I believe you raised some.\p"
	.string "I guess it would be okay for you to\n"
	.string "have this.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad: @ 81EA897
	.string "MAY: With those GO-GOGGLES, you'll\n"
	.string "have no trouble getting through the\l"
	.string "desert near ROUTE 111.\p"
	.string "But, wow, {PLAYER}{KUN}…\n"
	.string "Challenging GYMS…\p"
	.string "You're trying hard because you don't\n"
	.string "want to lose to me, I bet!\p"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
	.string "your dad in PETALBURG GYM.\p"
	.string "See you again!$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis: @ 81EA9A2
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
	.string "How's it going?\p"
	.string "Hmm…\n"
	.string "That's a decent collection of BADGES.\p"
	.string "All right, then.\n"
	.string "You may as well have this.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad: @ 81EAA2E
	.string "BRENDAN: Keep those with you if you're\n"
	.string "planning on going into that desert near\l"
	.string "ROUTE 111.\p"
	.string "There should be some POKéMON that\n"
	.string "are exclusively desert-dwellers.\l"
	.string "You might look around for those.\p"
	.string "As for me…\n"
	.string "I'm considering challenging NORMAN,\l"
	.string "the GYM LEADER of PETALBURG.\p"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
	.string "he really is tough.\p"
	.string "See you around!$"

LavaridgeTown_Text_HaveEggWillYouTakeIt: @ 81EAB80
	.string "I have here an EGG.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with POKéMON and\l"
	.string "carried about.\p"
	.string "You are a TRAINER, yes?\n"
	.string "And your POKéMON radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this EGG to hatch?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg: @ 81EACC0
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here EGG!$"

LavaridgeTown_Text_ReceivedTheEgg: @ 81EACF4
	.string "{PLAYER} received the EGG.$"

LavaridgeTown_Text_NoRoomForThisEgg: @ 81EAD09
	.string "Oh? You've too many POKéMON.\n"
	.string "There's no room for this EGG…$"

LavaridgeTown_Text_AsYouWishThen: @ 81EAD44
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this EGG, I will be here.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare: @ 81EAD9E
	.string "Every so often, an EGG will be found at\n"
	.string "the POKéMON DAY CARE.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_Text_HotSpringsNeverRunDry: @ 81EAE03
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"

LavaridgeTown_Text_PokemonNippedBackside: @ 81EAEE1
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A POKéMON nipped my backside!$"

LavaridgeTown_Text_OhYouLikeHotSprings: @ 81EAF4E
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay: @ 81EAF9B
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "GYM LEADER like FLANNERY.$"

LavaridgeTown_Text_IfPokemonInHotSprings: @ 81EB003
	.string "If people put POKéMON in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"

LavaridgeTown_Text_HotSpringsClaims: @ 81EB092
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"

LavaridgeTown_Text_TownSign: @ 81EB12B
	.string "LAVARIDGE TOWN\p"
	.string "“POKéMON CENTER HOT SPRINGS\n"
	.string "An excellent place for relaxing!”$"

LavaridgeTown_Text_GymSign: @ 81EB178
	.string "LAVARIDGE TOWN POKéMON GYM\n"
	.string "LEADER: FLANNERY\l"
	.string "“One with a fiery passion that burns!”$"

LavaridgeTown_Text_HerbShopSign: @ 81EB1CB
	.string "POKéMON HERB SHOP\n"
	.string "“Bitter taste--better cure!”$"

EnclavaTown_Mapscripts_LarsLocation::
	compare VAR_ENCLAVATOWER_STATE, 1
	goto_if_eq EnclavaTown_Mapscripts_LarsLocation_1
	return

EnclavaTown_Mapscripts_LarsLocation_1:
	setobjectxyperm 8, 38, 10
	return


EnclavaTown_Mapscript_Lars::
	lockall
	applymovement 8, EnclavaTown_Lars_Movement_0
	waitmovement 0
	playse SE_PIN
	delay 15
	applymovement 8, EnclavaTown_Lars_Movement_1
	waitmovement 0
	delay 5
	msgbox EnclavaTown_Mapscript_Lars_Text_0
	closemessage
	delay 25
	applymovement 8, Common_Movement_QuestionMark
	playse SE_PIN
	waitmovement 0
	delay 15
	msgbox EnclavaTown_Mapscript_Lars_Text_1
	closemessage
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 10
	applymovement 8, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	delay 15
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EnclavaTown_Mapscript_Lars_2
	compare VAR_RESULT, FEMALE
	goto_if_eq EnclavaTown_Mapscript_Lars_3
EnclavaTown_Mapscript_Lars_1:
	msgbox EnclavaTown_Mapscript_Lars_Text_4, MSGBOX_YESNO
EnclavaTown_Mapscript_Lars_7:
	compare VAR_RESULT, 1
	goto_if_ne EnclavaTown_Mapscript_Lars_8
	msgbox EnclavaTown_Mapscript_Lars_Text_6, MSGBOX_AUTOCLOSE
	delay 5
	applymovement 8, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 15
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 10
	removeobject 8
	waitfieldeffect FLDEFF_NPCFLY_OUT
	delay 5
	setvar VAR_ENCLAVATOWER_STATE, 2
	setobjectxyperm 8, 35, 5
	releaseall
	end

EnclavaTown_Mapscript_Lars_2:
	msgbox EnclavaTown_Mapscript_Lars_Text_2
	goto EnclavaTown_Mapscript_Lars_1

EnclavaTown_Mapscript_Lars_3:
	msgbox EnclavaTown_Mapscript_Lars_Text_3
	goto EnclavaTown_Mapscript_Lars_1

EnclavaTown_Mapscript_Lars_8:
	msgbox EnclavaTown_Mapscript_Lars_Text_5, MSGBOX_YESNO
	goto EnclavaTown_Mapscript_Lars_7


EnclavaTown_Lars_Movement_0:
	walk_in_place_down
	delay_16
	walk_in_place_right
	delay_16
	walk_in_place_up
	delay_8
	emote_exclamation_mark
	step_end

EnclavaTown_Lars_Movement_1:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

EnclavaTown_Sign_TownSign::
	msgbox EnclavaTown_Sign_TownSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


EnclavaTown_Sign_EnclavaTower::
	msgbox EnclavaTown_Sign_EnclavaTower_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


EnclavaTown_Sign_GymSign::
	msgbox EnclavaTown_Sign_GymSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


EnclavaTown_Sign_Rock::
	msgbox EnclavaTown_Sign_Rock_Text_0, MSGBOX_SIGN
	end


EnclavaTown_Object_TowerMan::
	lock
	msgbox EnclavaTown_Object_TowerMan_Text_0
	goto_if_set FLAG_BADGE02_GET, EnclavaTown_Object_TowerMan_2
	msgbox EnclavaTown_Object_TowerMan_Text_2, MSGBOX_AUTOCLOSE
EnclavaTown_Object_TowerMan_1:
	release
	end

EnclavaTown_Object_TowerMan_2:
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	delay 15
	msgbox EnclavaTown_Object_TowerMan_Text_1, MSGBOX_AUTOCLOSE
	delay 5
	applymovement 2, EnclavaTown_TowerMan_Movement_0
	waitmovement 0
	removeobject 2
	playse SE_DOOR
	setflag FLAG_ENCLAVATOWN_TOWERMAN
	goto EnclavaTown_Object_TowerMan_1


EnclavaTown_TowerMan_Movement_0:
	walk_up
	step_end

EnclavaTown_Object_OldWoman_1::
	msgbox EnclavaTown_Object_OldWoman_1_Text_0, MSGBOX_NPC
	end


EnclavaTown_Object_OldWoman_2::
	msgbox EnclavaTown_Object_OldWoman_2_Text_0, MSGBOX_NPC
	end


EnclavaTown_Object_Hiker::
	msgbox EnclavaTown_Object_Hiker_Text_0, MSGBOX_NPC
	end


EnclavaTown_Object_LittleGirl::
	msgbox EnclavaTown_Object_LittleGirl_Text_0, MSGBOX_NPC
	end


EnclavaTown_Object_BlackBelt::
	msgbox EnclavaTown_Object_BlackBelt_Text_0, MSGBOX_NPC
	end


EnclavaTown_Object_OldMan::
	msgbox EnclavaTown_Object_OldMan_Text_0, MSGBOX_NPC
	end


EnclavaTown_Trigger_EnclavaTower::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq EnclavaTown_Trigger_EnclavaTower_2
	release
	end

EnclavaTown_Trigger_EnclavaTower_2:
	lock
	special SpawnCameraObject
	delay 5
	applymovement OBJ_EVENT_ID_CAMERA, EnclavaTown_EnclavaTower_Movement_0
	waitmovement 0
	delay 20
	special RemoveCameraObject
	warp MAP_ENCLAVA_TOWER, 0, 8, 16
	return


EnclavaTown_EnclavaTower_Movement_0:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EnclavaTown_Sign_HerbShop::
	msgbox EnclavaTown_Sign_HerbShop_Text_0, MSGBOX_SIGN, MSGBOX_SUB_WOOD
	end


EnclavaTown_Mapscript_Lars_Text_0:
	.string "???: {COLOR BLUE}Hey there champ!\n"
	.string "You look like a freshie!\p"
	.string "{COLOR DARK_GREY}Lars: {COLOR BLUE}Name's {COLOR GREEN}Lars{COLOR BLUE}.\n"
	.string "What's yours?$"

EnclavaTown_Mapscript_Lars_Text_1:
	.string "Lars: {COLOR BLUE}Alright... not much of a talker I\n"
	.string "see...\p"
	.string "Lemme see your Trainer Card!$"

EnclavaTown_Mapscript_Lars_Text_2:
	.string "Lars: {COLOR BLUE}Whoa!\n"
	.string "You're {COLOR GREEN}Prof. Cypress'{COLOR BLUE} son!\p"
	.string "That's perfect!$"

EnclavaTown_Mapscript_Lars_Text_3:
	.string "Lars: {COLOR BLUE}Whoa!\n"
	.string "You're {COLOR GREEN}Prof. Cypress'{COLOR BLUE} daughter!\p"
	.string "That's perfect!$"

EnclavaTown_Mapscript_Lars_Text_4:
	.string "Lars: {COLOR BLUE}There's this fancy book that\n"
	.string "{COLOR GREEN}Cypress{COLOR BLUE} told me to get at the top of\l"
	.string "{COLOR GREEN}Enclava Tower{COLOR BLUE} and bring it back to her.\p"
	.string "Do you think you could do that for me?$"

EnclavaTown_Mapscript_Lars_Text_5:
	.string "{COLOR BLUE}Ah com'on... I'm really busy...$"

EnclavaTown_Mapscript_Lars_Text_6:
	.string "Lars: {COLOR BLUE}Alright sweet!\p"
	.string "All you need to do is get to the top of\n"
	.string "the tower and tell {COLOR GREEN}Master Fijo{COLOR BLUE} that\l"
	.string "{COLOR GREEN}Cypress{COLOR BLUE} sent you.\p"
	.string "Sound good?\n"
	.string "Sweet!\p"
	.string "I'll see you on the flip side!$"

EnclavaTown_Sign_TownSign_Text_0:
	.string "{COLOR LIGHT_GREEN}Enclava Town\p"
	.string "{COLOR DARK_GREY}“A Town of History”$"

EnclavaTown_Sign_EnclavaTower_Text_0:
	.string "{COLOR LIGHT_GREEN}Enclava Tower$"

EnclavaTown_Sign_GymSign_Text_0:
	.string "{COLOR RED}Enclava Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Bruce\n"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Normal-Type$"

EnclavaTown_Sign_Rock_Text_0:
	.string "It's a rock.$"

EnclavaTown_Object_TowerMan_Text_0:
	.string "{COLOR GREEN}Enclava Tower{COLOR BLUE} is a tower only for\n"
	.string "skilled trainers.$"

EnclavaTown_Object_TowerMan_Text_1:
	.string "{COLOR BLUE}Is that the {COLOR GREEN}Plain Badge{COLOR BLUE}?\p"
	.string "My apologizes, please feel free to\n"
	.string "enter.$"

EnclavaTown_Object_TowerMan_Text_2:
	.string "{COLOR BLUE}I can sense you are not yet strong\n"
	.string "enough to enter this tower.$"

EnclavaTown_Object_OldWoman_1_Text_0:
	.string "{COLOR GREEN}Enclava Tower{COLOR RED} is an ancient tower that\n"
	.string "has existed in {COLOR GREEN}Ryoko{COLOR RED} for centuries.\p"
	.string "It's main use nowadays is to store\n"
	.string "historical books, art and technology\l"
	.string "from centuries past.$"

EnclavaTown_Object_OldWoman_2_Text_0:
	.string "{COLOR RED}Back in my day, we use to have seperate\n"
	.string "buildings for the Pokémon Center.\p"
	.string "It use to just be the Pokémon Center,\n"
	.string "and usually nearby there would be a\l"
	.string "building called a Pokémart.\p"
	.string "But the region officials ordered the\n"
	.string "two buildings to be combined for ease\l"
	.string "of access.$"

EnclavaTown_Object_Hiker_Text_0:
	.string "{COLOR BLUE}Did you know that {COLOR GREEN}Davnridge Mines{COLOR BLUE}\n"
	.string "connects up with {COLOR GREEN}Victory Canyon{COLOR BLUE}?\p"
	.string "The old route to the {COLOR GREEN}Ryoko League{COLOR BLUE} use\n"
	.string "to go over {COLOR GREEN}Mt. Hood{COLOR BLUE}, but they\l"
	.string "discovered a cave that goes right\l"
	.string "through!$"

EnclavaTown_Object_LittleGirl_Text_0:
	.string "{COLOR RED}This rock is special to this town.\p"
	.string "I'm not quite sure why...$"

EnclavaTown_Object_BlackBelt_Text_0:
	.string "{COLOR BLUE}I've been training for the the Gym\n"
	.string "Leader {COLOR GREEN}Bruce{COLOR BLUE}.\p"
	.string "He specializes in Normal type Pokémon,\n"
	.string "so it should be an easy win for me!$"

EnclavaTown_Object_OldMan_Text_0:
	.string "{COLOR BLUE}Myself and {COLOR GREEN}Bruce{COLOR BLUE}, the local Gym Leader,\n"
	.string "use to be training buddies.\p"
	.string "I stopped about 5 years ago, but {COLOR GREEN}Bruce{COLOR BLUE}\n"
	.string "kept on training, and now he's the Gym\l"
	.string "Leader here!$"

EnclavaTown_Sign_HerbShop_Text_0:
	.string "{COLOR LIGHT_GREEN}Herb Shop\p"
	.string "{COLOR DARK_GREY}“Enclava's Local All-Natural Medicine”$"
