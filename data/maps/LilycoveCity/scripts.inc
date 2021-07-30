@LilycoveCity_MapScripts:: @ 81E2B3C
@	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
@	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
@	.byte 0
@
@LilycoveCity_OnTransition: @ 81E2B47
@	setflag FLAG_VISITED_LILYCOVE_CITY
@	setvar VAR_CONTEST_HALL_STATE, 0
@	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
@	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
@	call Common_EventScript_SetupRivalGfxId
@	compare VAR_CYPRESS_PROTO_EVENT_STATE, 5
@	call_if_eq MystCity_Mapscript_RivalCrawdauntPub
@	end
@
@LilycoveCity_OnLoad: @ 81E2B61
@	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
@	end

LilycoveCity_EventScript_SetWailmerMetatiles:: @ 81E2B6B
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, 1
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, 1
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, 1
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, 1
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, 1
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, 1
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, 1
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, 1
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, 1
	return

LilycoveCity_EventScript_BerryGentleman:: @ 81E2BD8
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry:: @ 81E2C18
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3:: @ 81E2C22
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl:: @ 81E2C2B
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone:: @ 81E2C40
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy:: @ 81E2C4A
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2:: @ 81E2C53
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone:: @ 81E2C68
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2:: @ 81E2C72
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone:: @ 81E2C87
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2:: @ 81E2C91
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1:: @ 81E2C9A
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF:: @ 81E2CA3
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2:: @ 81E2CAC
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone:: @ 81E2CC1
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1:: @ 81E2CCB
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan:: @ 81E2CD4
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1:: @ 81E2CDD
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1:: @ 81E2CEE
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign:: @ 81E2CFF
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign:: @ 81E2D08
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign:: @ 81E2D11
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign:: @ 81E2D1A
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings:: @ 81E2D3A
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign:: @ 81E2D44
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady:: @ 81E2D58
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign:: @ 81E2D62
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign:: @ 81E2D6B
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign:: @ 81E2D74
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt:: @ 81E2D7D
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer:: @ 81E2DB0
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1:: @ 81E2DBA
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2:: @ 81E2DC3
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3:: @ 81E2DCC
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4:: @ 81E2DD5
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival:: @ 81E2DDE
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LilycoveCity_EventScript_May
	compare VAR_RESULT, FEMALE
	goto_if_eq LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May:: @ 81E2DF8
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain:: @ 81E2E48
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle:: @ 81E2E51
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle:: @ 81E2E5A
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan:: @ 81E2E6B
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	compare VAR_RESULT, NO
	goto_if_eq LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain:: @ 81E2EBB
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle:: @ 81E2EC4
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle:: @ 81E2ECD
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko:: @ 81E2EDE
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic:: @ 81E2EEE
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip:: @ 81E2EFE
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko:: @ 81E2F0E
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic:: @ 81E2F1E
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip:: @ 81E2F2E
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay:: @ 81E2F3E
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_EventScript_MayCollectBadges
	compare VAR_RESULT, TRUE
	call_if_eq LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge:: @ 81E2F76
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge:: @ 81E2F80
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges:: @ 81E2F86
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague:: @ 81E2F8F
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier:: @ 81E2FA1
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan:: @ 81E2FAA
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	compare VAR_RESULT, FALSE
	call_if_eq LilycoveCity_EventScript_BrendanCollectBadges
	compare VAR_RESULT, TRUE
	call_if_eq LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges:: @ 81E2FE2
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague:: @ 81E2FEB
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier:: @ 81E2FFD
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway:: @ 81E3006
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM:: @ 81E302D
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq LilycoveCity_EventScript_KnowAboutBerryBlender
	compare VAR_RESULT, NO
	call_if_eq LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender:: @ 81E304F
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender:: @ 81E3058
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle: @ 81E3061
	.string "MAY: Oh, hey?\n"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
	.string "I bought a whole bunch of DOLLS and\n"
	.string "POSTERS.\p"
	.string "Of course, I've also caught a lot of\n"
	.string "POKéMON, and I'm raising them\l"
	.string "properly, too.\p"
	.string "Actually, I'm more worried if you're\n"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
	.string "I'll battle with you, so you can show\n"
	.string "me your POKéMON, {PLAYER}{KUN}.$"

LilycoveCity_Text_MayNotRaisingPokemon: @ 81E318D
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
	.string "been raising your POKéMON?\p"
	.string "That's not a very good showing as a\n"
	.string "TRAINER…$"

LilycoveCity_Text_MayBattleMe: @ 81E31F5
	.string "MAY: Come on, battle with me, so I can\n"
	.string "check out your POKéMON!$"

LilycoveCity_Text_MayWontBeBeaten: @ 81E3234
	.string "MAY: The POKéMON I raised won't be\n"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"

LilycoveCity_Text_MayDefeat: @ 81E3275
	.string "… … … … … … … …\p"
	.string "I remember the battle I had with you,\n"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
	.string "That battle helped you become this\n"
	.string "strong, {PLAYER}{KUN}, didn't it?$"

LilycoveCity_Text_MayGoingBackToLittleroot: @ 81E32FB
	.string "MAY: I'm thinking of going back to\n"
	.string "LITTLEROOT soon.\p"
	.string "I've caught a decent group of POKéMON,\n"
	.string "and my POKéDEX is coming along, so\l"
	.string "I'm going home to show my dad.$"

LilycoveCity_Text_MayYouGoingToCollectBadges: @ 81E3398
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Collect all the GYM BADGES and take\n"
	.string "the POKéMON LEAGUE challenge?\p"
	.string "Well, while you're collecting BADGES,\n"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
	.string "POKéDEX. I'll complete it before you!\p"
	.string "See you!$"

LilycoveCity_Text_MayYouGoingToPokemonLeague: @ 81E346D
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the POKéMON LEAGUE\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my POKéDEX before you!\p"
	.string "See you!$"

LilycoveCity_Text_MayYouGoingToBattleFrontier: @ 81E353A
	.string "{PLAYER}{KUN}, what are you going to do?\p"
	.string "Are you taking the BATTLE FRONTIER\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "I might've lost to you in battling,\n"
	.string "but I'll finish my POKéDEX before you!\p"
	.string "See you!$"

LilycoveCity_Text_BrendanShoppingLetsBattle: @ 81E3608
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
	.string "I'm running an errand for my dad.\n"
	.string "No, I'm not buying any DOLLS.\p"
	.string "Anyways, it's been a while.\p"
	.string "Want to have a battle to see who's been\n"
	.string "raising POKéMON better?$"

LilycoveCity_Text_BrendanNoConfidence: @ 81E36BF
	.string "BRENDAN: Oh, what's the matter?\n"
	.string "Don't have the confidence?$"

LilycoveCity_Text_BrendanBattleMe: @ 81E36FA
	.string "BRENDAN: Want to battle to see who's\n"
	.string "been raising POKéMON better?$"

LilycoveCity_Text_BrendanWontBeBeaten: @ 81E373C
	.string "BRENDAN: Aww, but you know I'm not\n"
	.string "going to lose to no {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat: @ 81E3777
	.string "Humph…\n"
	.string "You've done a lot of raising.\p"
	.string "That stings a bit--I had a head start\n"
	.string "on you as a TRAINER…$"

LilycoveCity_Text_BrendanGoingBackToLittleroot: @ 81E37D7
	.string "BRENDAN: I…\n"
	.string "I plan on going home to LITTLEROOT.\p"
	.string "You know I'm helping out my dad on his\n"
	.string "POKéDEX. It's coming together pretty\l"
	.string "decently, so I should go show him.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges: @ 81E3876
	.string "{PLAYER}, what are you going to do?\p"
	.string "Collect all the GYM BADGES and take\n"
	.string "the POKéMON LEAGUE challenge?\p"
	.string "Maybe I'll do that, too…\p"
	.string "Well, anyway, hang in there!$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague: @ 81E390C
	.string "{PLAYER}, what are you going to do?\p"
	.string "Since you're that strong, are you\n"
	.string "taking the POKéMON LEAGUE challenge?\p"
	.string "Heh, even me--if I trained my POKéMON\n"
	.string "a bit more, I should be stronger than\l"
	.string "you, {PLAYER}.\p"
	.string "Well, anyway, hang in there!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier: @ 81E39E3
	.string "{PLAYER}, what are you going to do?\p"
	.string "Are you taking the BATTLE FRONTIER\n"
	.string "challenge?\p"
	.string "Or, are you going to complete your\n"
	.string "POKéDEX?\p"
	.string "Since you're that strong, you should\n"
	.string "consider the BATTLE FRONTIER.\p"
	.string "Heh, if I train my POKéMON a bit more,\n"
	.string "I'll get stronger than you, {PLAYER}.\p"
	.string "Maybe I should go to the BATTLE\n"
	.string "FRONTIER.\p"
	.string "Well, anyway, hang in there!$"

LilycoveCity_Text_MovedLootIntoHideoutToday: @ 81E3B2C
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "HIDEOUT today…\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_ChanceToDoBigThings: @ 81E3B95
	.string "I'm just a GRUNT, so I don't know what\n"
	.string "the BOSS is thinking…\p"
	.string "But being on TEAM AQUA, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "Wh-who are you?!\n"
	.string "I was just talking to myself!$"

LilycoveCity_Text_DontGoNearCaveInCove: @ 81E3C46
	.string "Hey, you!\p"
	.string "Don't go near the cave in the cove!\p"
	.string "Why? You don't need a reason why!\n"
	.string "I'm an adult, so you just listen to me!$"

LilycoveCity_Text_IfWorldBecomesOurs: @ 81E3CBE
	.string "If this whole wide world becomes ours,\n"
	.string "TEAM AQUA's, it will be a happier\l"
	.string "place for POKéMON, too.$"

LilycoveCity_Text_WailmerLeapOutOfWater: @ 81E3D1F
	.string "There! WAILMER!\n"
	.string "Leap out of the water now!$"

LilycoveCity_Text_GetLostMessingUpTraining: @ 81E3D4A
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"

LilycoveCity_Text_ContestHallInTown: @ 81E3D9E
	.string "There's a POKéMON CONTEST HALL\n"
	.string "right in this here town. \p"
	.string "That means well-raised POKéMON will\n"
	.string "come from all over the country.\p"
	.string "My heart swells with excitement!$"

LilycoveCity_Text_StrangeCaveInCove: @ 81E3E3C
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs: @ 81E3E7D
	.string "I'm going to teach my POKéMON some new\n"
	.string "moves for entering a CONTEST.\p"
	.string "So, I'm going to see the MOVE DELETER\n"
	.string "and make it forget HM moves.$"

LilycoveCity_Text_ImFromKanto: @ 81E3F05
	.string "I came from KANTO.\p"
	.string "The HOENN region is beautiful with\n"
	.string "all its water and verdant nature.\p"
	.string "Hunh? Wait a second…\p"
	.string "Could there be rare POKéMON that live\n"
	.string "only in this area?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer: @ 81E3FAB
	.string "TEAM AQUA's been training their\n"
	.string "WAILMER in the cove.\p"
	.string "We SAILORS can't get our boats out\n"
	.string "to sea with them in the way!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut: @ 81E4020
	.string "Ahoy, did you know?\p"
	.string "Someone punted TEAM AQUA out of\n"
	.string "the way for us!\p"
	.string "That got the WAILMER out of the cove,\n"
	.string "so we can get our boats out again.$"

LilycoveCity_Text_SomeoneStoleMyPokemon: @ 81E40AD
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my POKéMON!\p"
	.string "Who's the abductor?\n"
	.string "TEAM AQUA? Is it TEAM AQUA?$"

LilycoveCity_Text_MissingPokemonCameBack: @ 81E4145
	.string "My missing POKéMON…\n"
	.string "It came back without me noticing!$"

LilycoveCity_Text_ImArtDealer: @ 81E417B
	.string "I'm an ART DEALER.\p"
	.string "I am a buyer and seller of fine art,\n"
	.string "especially paintings.\p"
	.string "I've heard that the MUSEUM here has\n"
	.string "magnificent works on exhibit…$"

LilycoveCity_Text_SeaRemainsForeverYoung: @ 81E420B
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed: @ 81E4283
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern: @ 81E42FC
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that TEAM AQUA lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “nature-loving TEAM AQUA”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"

LilycoveCity_Text_TeamAquaLotGoneForGood: @ 81E43FF
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That TEAM AQUA lot, they must\n"
	.string "have gone away for good.$"

LilycoveCity_Text_CitySign: @ 81E448B
	.string "LILYCOVE CITY\p"
	.string "“Where the land ends and the\n"
	.string "sea begins.”$"

LilycoveCity_Text_ContestHallSign: @ 81E44C3
	.string "POKéMON CONTEST HALL\n"
	.string "“The gathering place for TRAINERS!”$"

LilycoveCity_Text_MotelSign: @ 81E44FC
	.string "COVE LILY MOTEL\p"
	.string "“Remember us as COVE LILY of\n"
	.string "LILYCOVE.”$"

LilycoveCity_Text_MuseumSign: @ 81E4534
	.string "LILYCOVE MUSEUM\p"
	.string "“POKéMON Masterpiece Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit: @ 81E4571
	.string "LILYCOVE MUSEUM\p"
	.string "“{PLAYER}'s POKéMON Collection\n"
	.string "on exhibit!”$"

LilycoveCity_Text_HarborSignUnderConstruction: @ 81E45A7
	.string "LILYCOVE CITY HARBOR\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in SLATEPORT CITY.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"

LilycoveCity_Text_HarborSign: @ 81E4624
	.string "LILYCOVE CITY HARBOR\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign: @ 81E466E
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "The names of TRAINERS are scribbled\n"
	.string "all over the sign…$"

LilycoveCity_Text_DepartmentStoreSign: @ 81E46BE
	.string "LILYCOVE DEPARTMENT STORE\p"
	.string "“Overflowing with great merchandise\n"
	.string "and excitement!\p"
	.string "“A great place to find that something\n"
	.string "you need!”$"

LilycoveCity_Text_MoveDeletersHouseSign: @ 81E473D
	.string "MOVE DELETER'S HOUSE\p"
	.string "“Unwanted POKéMON moves deleted.”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender: @ 81E4774
	.string "Do you know about the machine\n"
	.string "BERRY BLENDER?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks: @ 81E47A1
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}S you can get, I've heard.$"

LilycoveCity_Text_ExplainBerryBlender: @ 81E4824
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
	.string "its condition will improve by a lot.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar: @ 81E48A5
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the SKY PILLAR, I hear.$"

LilycoveCity_Text_SawTallTowerOnRoute131: @ 81E4902
	.string "I saw this tall tower somewhere\n"
	.string "around ROUTE 131.\p"
	.string "Could that possibly be…?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon: @ 81E494D
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a DRAGON-type\n"
	.string "POKéMON flying way up in the sky.\p"
	.string "Do cool POKéMON like that live in\n"
	.string "the HOENN region?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon: @ 81E49F4
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare POKéMON as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "POKéMON as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LilycoveCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LilycoveCity_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_LILYCOVE_CITY
	compare VAR_PROTO_HIDEOUT, 2
	goto_if_eq LilycoveCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
LilycoveCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	compare VAR_CYPRESS_PROTO_EVENT_STATE, 5
	goto_if_eq LilycoveCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

LilycoveCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	setobjectxyperm 23, 32, 32
	setobjectxyperm 24, 31, 32
	goto LilycoveCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_1

LilycoveCity_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	setobjectxyperm 21, 15, 42
	setobjectxyperm 22, 15, 39
	return

LilycoveCity_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PROTO_HIDEOUT, 2, MystCity_Mapscript_ExitProtoHideout
	.2byte 0


MystCity_Object_BlackBelt::
	msgbox MystCity_Object_BlackBelt_Text_0, MSGBOX_NPC
	end


MystCity_Object_Officer::
	msgbox MystCity_Object_Officer_Text_0, MSGBOX_NPC
	end


MystCity_Object_PokefanM::
	msgbox MystCity_Object_PokefanM_Text_0, MSGBOX_NPC
	end


MystCity_Object_PokefanF::
	msgbox MystCity_Object_PokefanF_Text_0, MSGBOX_NPC
	end


MystCity_Object_OldWoman::
	msgbox MystCity_Object_OldWoman_Text_0, MSGBOX_NPC
	end


MystCity_Object_OldMan::
	msgbox MystCity_Object_OldMan_Text_0, MSGBOX_NPC
	end


MystCity_Object_SchoolKid::
	msgbox MystCity_Object_SchoolKid_Text_0, MSGBOX_NPC
	end


MystCity_Object_Sailor_1::
	msgbox MystCity_Object_Sailor_1_Text_0, MSGBOX_NPC
	end


MystCity_Object_RichKid::
	msgbox MystCity_Object_RichKid_Text_0, MSGBOX_NPC
	end


MystCity_Object_Woman_1::
	msgbox MystCity_Object_Woman_1_Text_0, MSGBOX_NPC
	end


MystCity_Object_Woman_2::
	msgbox MystCity_Object_Woman_2_Text_0, MSGBOX_NPC
	end


MystCity_Object_Woman_3::
	msgbox MystCity_Object_Woman_3_Text_0, MSGBOX_NPC
	end


MystCity_Object_FatGuy::
	msgbox MystCity_Object_FatGuy_Text_0, MSGBOX_NPC
	end


MystCity_Object_Sailor_2::
	msgbox MystCity_Object_Sailor_2_Text_0, MSGBOX_NPC
	end


MystCity_Object_Man::
	msgbox MystCity_Object_Man_Text_0, MSGBOX_NPC
	end


MystCity_Sign_CitySign::
	msgbox MystCity_Sign_CitySign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


MystCity_Sign_MoveDeletersSign::
	msgbox MystCity_Sign_MoveDeletersSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


MystCity_Sign_CrawdauntPubSign::
	msgbox MystCity_Sign_CrawdauntPubSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


MystCity_Sign_GymSign::
	msgbox MystCity_Sign_GymSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


MystCity_Sign_GymSignClosed::
	msgbox MystCity_Sign_GymSignClosed_Text_0, MSGBOX_SIGN
	end


MystCity_Sign_LabSign::
	msgbox MystCity_Sign_LabSign_Text_0, MSGBOX_SIGN, MSGBOX_SUB_METAL
	end


MystCity_Trigger_CrawdauntPub::
	lockall
	delay 20
	applymovement 21, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	applymovement 21, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	waitse
	playbgm MUS_RG_RIVAL1, 0
	delay 20
	msgbox MystCity_Trigger_CrawdauntPub_Text_0, MSGBOX_AUTOCLOSE
	delay 10
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 14
	goto_if_eq MystCity_Trigger_CrawdauntPub_2
	compare VAR_TEMP_0, 15
	goto_if_eq MystCity_Trigger_CrawdauntPub_3
	compare VAR_TEMP_0, 16
	goto_if_eq MystCity_Trigger_CrawdauntPub_4
MystCity_Trigger_CrawdauntPub_1:
	msgbox MystCity_Trigger_CrawdauntPub_Text_1, MSGBOX_AUTOCLOSE
	compare VAR_STARTER_MON, 0
	goto_if_eq MystCity_Trigger_CrawdauntPub_9
	compare VAR_STARTER_MON, 1
	goto_if_eq MystCity_Trigger_CrawdauntPub_10
	compare VAR_STARTER_MON, 2
	goto_if_eq MystCity_Trigger_CrawdauntPub_11
MystCity_Trigger_CrawdauntPub_8:
	playbgm MUS_RG_RIVAL1, 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_3, MSGBOX_AUTOCLOSE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 14
	goto_if_eq MystCity_Trigger_CrawdauntPub_16
	compare VAR_TEMP_0, 15
	goto_if_eq MystCity_Trigger_CrawdauntPub_17
	compare VAR_TEMP_0, 16
	goto_if_eq MystCity_Trigger_CrawdauntPub_18
MystCity_Trigger_CrawdauntPub_15:
	fadenewbgm MUS_MINAMO
	applymovement 22, MystCity_CrawdauntPub_Movement_1
	waitmovement 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_4
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	compare VAR_TEMP_0, 15
	goto_if_eq MystCity_Trigger_CrawdauntPub_23
	applymovement 21, Common_Movement_WalkInPlaceUp
	waitmovement 0
MystCity_Trigger_CrawdauntPub_22:
	applymovement 22, MystCity_CrawdauntPub_Movement_2
	waitmovement 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_5
	applymovement 21, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_6
	applymovement 22, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_7
	applymovement 21, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_8
	applymovement 22, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_9
	applymovement 21, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_10, MSGBOX_AUTOCLOSE
	delay 10
	applymovement 21, MystCity_CrawdauntPub_Movement_4
	waitmovement 0
	msgbox MystCity_Trigger_CrawdauntPub_Text_11, MSGBOX_AUTOCLOSE
	delay 10
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 14
	goto_if_eq MystCity_Trigger_CrawdauntPub_27
	compare VAR_TEMP_0, 15
	goto_if_eq MystCity_Trigger_CrawdauntPub_28
	compare VAR_TEMP_0, 16
	goto_if_eq MystCity_Trigger_CrawdauntPub_29
MystCity_Trigger_CrawdauntPub_26:
	setflag FLAG_MYSTCITY_LARSSKIP
	removeobject 22
	removeobject 21
	setvar VAR_CYPRESS_PROTO_EVENT_STATE, 6
	releaseall
	end

MystCity_Trigger_CrawdauntPub_2:
	applymovement 21, MystCity_CrawdauntPub_Movement_0_0
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto MystCity_Trigger_CrawdauntPub_1

MystCity_Trigger_CrawdauntPub_3:
	applymovement 21, MystCity_CrawdauntPub_Movement_0_1
	waitmovement 0
	goto MystCity_Trigger_CrawdauntPub_1

MystCity_Trigger_CrawdauntPub_4:
	applymovement 21, MystCity_CrawdauntPub_Movement_0_2
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto MystCity_Trigger_CrawdauntPub_1

MystCity_Trigger_CrawdauntPub_9:
	trainerbattle_no_intro TRAINER_SKIP_FIRE_3, MystCity_Trigger_CrawdauntPub_Text_2
	goto MystCity_Trigger_CrawdauntPub_8

MystCity_Trigger_CrawdauntPub_10:
	trainerbattle_no_intro TRAINER_SKIP_WATER_3, MystCity_Trigger_CrawdauntPub_Text_2
	goto MystCity_Trigger_CrawdauntPub_8

MystCity_Trigger_CrawdauntPub_11:
	trainerbattle_no_intro TRAINER_SKIP_GRASS_3, MystCity_Trigger_CrawdauntPub_Text_2
	goto MystCity_Trigger_CrawdauntPub_8

MystCity_Trigger_CrawdauntPub_16:
	setobjectxy 22, 14, 39
	goto MystCity_Trigger_CrawdauntPub_15

MystCity_Trigger_CrawdauntPub_17:
	setobjectxy 22, 15, 39
	goto MystCity_Trigger_CrawdauntPub_15

MystCity_Trigger_CrawdauntPub_18:
	setobjectxy 22, 16, 39
	goto MystCity_Trigger_CrawdauntPub_15

MystCity_Trigger_CrawdauntPub_23:
	applymovement 21, MystCity_CrawdauntPub_Movement_3
	waitmovement 0
	goto MystCity_Trigger_CrawdauntPub_22

MystCity_Trigger_CrawdauntPub_27:
	applymovement 22, MystCity_CrawdauntPub_Movement_5_0
	waitmovement 0
	goto MystCity_Trigger_CrawdauntPub_26

MystCity_Trigger_CrawdauntPub_28:
	applymovement 22, MystCity_CrawdauntPub_Movement_5_1
	waitmovement 0
	goto MystCity_Trigger_CrawdauntPub_26

MystCity_Trigger_CrawdauntPub_29:
	applymovement 22, MystCity_CrawdauntPub_Movement_5_2
	waitmovement 0
	goto MystCity_Trigger_CrawdauntPub_26


MystCity_CrawdauntPub_Movement_0_0:
	walk_down
	walk_down
	walk_down
	walk_in_place_left
	step_end

MystCity_CrawdauntPub_Movement_0_1:
	walk_down
	walk_down
	step_end

MystCity_CrawdauntPub_Movement_0_2:
	walk_down
	walk_down
	walk_down
	walk_in_place_right
	step_end

MystCity_CrawdauntPub_Movement_1:
	walk_down
	walk_down
	walk_down
	step_end

MystCity_CrawdauntPub_Movement_2:
	walk_down
	walk_down
	step_end

MystCity_CrawdauntPub_Movement_3:
	walk_left
	walk_down
	walk_in_place_up
	step_end

MystCity_CrawdauntPub_Movement_4:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	delay_8
	set_invisible
	step_end

MystCity_CrawdauntPub_Movement_5_0:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

MystCity_CrawdauntPub_Movement_5_1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

MystCity_CrawdauntPub_Movement_5_2:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

MystCity_Mapscript_ExitProtoHideout::
	lockall
	applymovement 24, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_0
	applymovement 23, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_1, MSGBOX_AUTOCLOSE
	delay 20
	applymovement 24, Common_Movement_WalkInPlaceUp
	applymovement 23, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement 24, Common_Movement_ExclamationMark
	applymovement 23, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	delay 15
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_2
	waitmessage
	closemessage
	applymovement 23, Common_Movement_WalkUp
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_3
	delay 10
	closemessage
	fadescreen FADE_TO_BLACK
	delay 120
	applymovement 24, Common_Movement_WalkUp
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	delay 10
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_4
	applymovement 24, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_5
	applymovement 23, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_6
	applymovement 24, Common_Movement_FaceUp
	applymovement 23, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_7
	applymovement 24, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_8, MSGBOX_AUTOCLOSE
	delay 5
	giveitem ITEM_SS_TICKET, 1
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_9
	applymovement 23, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_10, MSGBOX_AUTOCLOSE
	applymovement 23, MystCity_ExitProtoHideout_Movement_0
	waitmovement 0
	removeobject 23
	applymovement 24, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MystCity_Mapscript_ExitProtoHideout_Text_11, MSGBOX_AUTOCLOSE
	applymovement 24, MystCity_ExitProtoHideout_Movement_1
	waitmovement 0
	removeobject 24
	setflag FLAG_MYSTCITY_EXIT_PROTO_HIDEOUT
	setvar VAR_PROTO_HIDEOUT, 3
	releaseall
	end


MystCity_ExitProtoHideout_Movement_0:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MystCity_ExitProtoHideout_Movement_1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MystCity_Object_BlackBelt_Text_0:
	.string "{COLOR BLUE}I want to battle the {COLOR GREEN}Myst City Gym{COLOR BLUE}, but\n"
	.string "the leader is supposedly 'on tour' at\l"
	.string "the moment...\p"
	.string "I don't know when he will come back.$"

MystCity_Object_Officer_Text_0:
	.string "{COLOR BLUE}Hey kid.\p"
	.string "Let me know if you see any sketchy\n"
	.string "activity in the city.\p"
	.string "{COLOR GREEN}Myst City{COLOR BLUE} has had a rise in criminal\n"
	.string "activity, and I'm here to put a stop to\l"
	.string "it!\p"
	.string "Or at least attempt to...$"

MystCity_Object_PokefanM_Text_0:
	.string "{COLOR BLUE}My girlfriend and I are visting the city!\p"
	.string "We're from {COLOR GREEN}Terracot Island{COLOR BLUE}, and the city\n"
	.string "is so different from the island life!$"

MystCity_Object_PokefanF_Text_0:
	.string "{COLOR RED}My boyfriend convinced me to check out\n"
	.string "{COLOR GREEN}Myst City{COLOR RED}, and it's very different from\l"
	.string "the island life.\p"
	.string "I like the quite life on {COLOR GREEN}Terracot Island{COLOR RED}.$"

MystCity_Object_OldWoman_Text_0:
	.string "{COLOR RED}I like waking up every morning and\n"
	.string "walking to the park with my husband.$"

MystCity_Object_OldMan_Text_0:
	.string "{COLOR BLUE}I wake up every morning and walk to the\n"
	.string "park with my wife.\p"
	.string "She likes to get her excersise, and I'm\n"
	.string "not gonna sit at home alone!$"

MystCity_Object_SchoolKid_Text_0:
	.string "{COLOR BLUE}My school is making me do a project on\n"
	.string "nature, so I'm doing it on the park\l"
	.string "here!\p"
	.string "...\p"
	.string "I know...\l"
	.string "It's pretty lame...$"

MystCity_Object_Sailor_1_Text_0:
	.string "{COLOR BLUE}I come from {COLOR GREEN}Bayport City{COLOR BLUE} whenever I get\n"
	.string "a break from the ship and come to my\l"
	.string "favorite resturant in all of {COLOR GREEN}Ryoko{COLOR BLUE}, the\l"
	.string "{COLOR GREEN}“Crawdaunt Pub”{COLOR BLUE}!$"

MystCity_Object_RichKid_Text_0:
	.string "{COLOR BLUE}Where are you from?\p"
	.string "Wait.\n"
	.string "Let me guess...\p"
	.string "You're from {COLOR GREEN}Canvas Town{COLOR BLUE}!\p"
	.string "I can tell by your dirty clothes!$"

MystCity_Object_Woman_1_Text_0:
	.string "{COLOR RED}Are you new to the city?\p"
	.string "There is a lot to see in the city!\p"
	.string "There is {COLOR GREEN}Professor Cypress' Lab{COLOR RED} in the\n"
	.string "southern side of the city, and in the\l"
	.string "northern side is the {COLOR GREEN}Myst City Gym{COLOR RED}.\p"
	.string "If you ever get hungry, you can check\n"
	.string "out the {COLOR GREEN}“Crawdaunt Pub”{COLOR RED}!$"

MystCity_Object_Woman_2_Text_0:
	.string "{COLOR RED}I'm looking to start up a flower shop\n"
	.string "here in {COLOR GREEN}Myst City{COLOR RED}, but there hasn't\l"
	.string "been new development in the city for a\l"
	.string "few months now...$"

MystCity_Object_Woman_3_Text_0:
	.string "{COLOR RED}My favorite part of the city is the\n"
	.string "park...\p"
	.string "It's so peaceful and a great\n"
	.string "distraction from the bustling city.$"

MystCity_Object_FatGuy_Text_0:
	.string "{COLOR BLUE}Me n' my buddy here are just catchin'\n"
	.string "up!\p"
	.string "I stopped workin' at the port a few\n"
	.string "months back.$"

MystCity_Object_Sailor_2_Text_0:
	.string "{COLOR BLUE}My buddy here stopped workin' at the\n"
	.string "port a few months back.\p"
	.string "Between you and me, he stopped working\n"
	.string "because they were asking too much\l"
	.string "from him.$"

MystCity_Object_Man_Text_0:
	.string "{COLOR BLUE}This city may look clean on the surface,\n"
	.string "but I'm skeptical that there is more\l"
	.string "going on underneath the city.\p"
	.string "I've seen a lot of thugs around here,\n"
	.string "and the local pub is extremely\l"
	.string "suspicious.$"

MystCity_Sign_CitySign_Text_0:
	.string "{COLOR LIGHT_GREEN}Myst City\p"
	.string "{COLOR DARK_GREY}“The Hub of Ryoko”$"

MystCity_Sign_MoveDeletersSign_Text_0:
	.string "{COLOR LIGHT_GREEN}Move Deleter's House$"

MystCity_Sign_CrawdauntPubSign_Text_0:
	.string "{COLOR LIGHT_GREEN}The Crawdaunt Pub\n"
	.string "{COLOR DARK_GREY}“The Heart and Soul of Myst City”$"

MystCity_Sign_GymSign_Text_0:
	.string "{COLOR RED}Myst City Pokémon Gym\p"
	.string "{COLOR DARK_GREY}Leader: {COLOR LIGHT_GREEN}Braian\n"
	.string "{COLOR DARK_GREY}Type: {COLOR LIGHT_GREEN}Psychic-Type$"

MystCity_Sign_GymSignClosed_Text_0:
	.string "There is a sign posted on the door.\p"
	.string "“The Gym is temporarily closed while I\n"
	.string "am on tour.” - Braian, Myst City Gym\l"
	.string "Leader$"

MystCity_Sign_LabSign_Text_0:
	.string "{COLOR LIGHT_GREEN}Cypress Laboratory$"

MystCity_Trigger_CrawdauntPub_Text_0:
	.string "Skip: {COLOR BLUE}Just the person I was looking for!$"

MystCity_Trigger_CrawdauntPub_Text_1:
	.string "Skip: {COLOR BLUE}What's up slowpoke!\n"
	.string "Still a few steps behind me?\p"
	.string "Ha!\p"
	.string "I've always been faster than you!\p"
	.string "Say... I haven't seen you battle since\n"
	.string "{COLOR GREEN}Frostpine City{COLOR BLUE}!\p"
	.string "How about we see who the stronger\n"
	.string "trainer is?$"

MystCity_Trigger_CrawdauntPub_Text_2:
	.string "Agh!\n"
	.string "Again?$"

MystCity_Trigger_CrawdauntPub_Text_3:
	.string "Skip: {COLOR BLUE}Agh!\n"
	.string "You always seem to beat me...\l"
	.string "Even at my best...\p"
	.string "I won't let that loss get to me!\p"
	.string "You just got lucky!$"

MystCity_Trigger_CrawdauntPub_Text_4:
	.string "Lars: {COLOR BLUE}Ah!$"

MystCity_Trigger_CrawdauntPub_Text_5:
	.string "Lars: {COLOR BLUE}You made it!$"

MystCity_Trigger_CrawdauntPub_Text_6:
	.string "Skip: {COLOR BLUE}Who are you?\n"
	.string "{COLOR GREEN}{PLAYER}{COLOR BLUE} do you know this dude?$"

MystCity_Trigger_CrawdauntPub_Text_7:
	.string "Lars: {COLOR BLUE}Ah, I sense a little rivalry\n"
	.string "between you two.\p"
	.string "Name's {COLOR GREEN}Lars{COLOR BLUE}.\n"
	.string "I'm a fellow trainer like yourself.$"

MystCity_Trigger_CrawdauntPub_Text_8:
	.string "Skip: {COLOR BLUE}Hpmh.\n"
	.string "Name's {COLOR GREEN}Skip{COLOR BLUE}.$"

MystCity_Trigger_CrawdauntPub_Text_9:
	.string "Lars: {COLOR BLUE}Nice to meet you {COLOR GREEN}Skip{COLOR BLUE}!\p"
	.string "Now, {COLOR GREEN}{PLAYER}{COLOR BLUE}, you need to go in {COLOR GREEN}The\n"
	.string "Crawdaunt Pub{COLOR BLUE} and ask the other\l"
	.string "customers if they've seen any\l"
	.string "suspicious people in the pub.\p"
	.string "Hopefully they'll talk.$"

MystCity_Trigger_CrawdauntPub_Text_10:
	.string "Skip: {COLOR BLUE}Ha!\n"
	.string "{COLOR GREEN}{PLAYER}{COLOR BLUE} doesn't know how to smooth\l"
	.string "talk those types of folk!\p"
	.string "I'll do all the talking {COLOR GREEN}{PLAYER}{COLOR BLUE}.\p"
	.string "Catch ya there slowpoke!$"

MystCity_Trigger_CrawdauntPub_Text_11:
	.string "Lars: {COLOR BLUE}Huh.\n"
	.string "What an interesting fella...\p"
	.string "Anyways, it seems like you and {COLOR GREEN}Skip{COLOR BLUE} got\n"
	.string "this figured out.\p"
	.string "Report back to {COLOR GREEN}Professor Cypress{COLOR BLUE} and\n"
	.string "myself in her lab.\p"
	.string "Good luck kid!$"

MystCity_Mapscript_ExitProtoHideout_Text_0:
	.string "Mom: {COLOR RED}Lars, what is taking them so long?\p"
	.string "I thought you said this was going to be\n"
	.string "quick...$"

MystCity_Mapscript_ExitProtoHideout_Text_1:
	.string "Lars: {COLOR BLUE}They shouldn't be much longer...$"

MystCity_Mapscript_ExitProtoHideout_Text_2:
	.string "Mom: {COLOR RED}There you are {COLOR GREEN}{PLAYER}{COLOR RED}!$"

MystCity_Mapscript_ExitProtoHideout_Text_3:
	.string "Lars: {COLOR BLUE}Well, what information did you\n"
	.string "get?$"

MystCity_Mapscript_ExitProtoHideout_Text_4:
	.string "Lars: {COLOR BLUE}Wow.\p"
	.string "That is a lot to unpack.$"

MystCity_Mapscript_ExitProtoHideout_Text_5:
	.string "Mom: {COLOR RED}Lars, those books they're\n"
	.string "translating contain some very\l"
	.string "dangerous information if in the wrong\l"
	.string "hands.$"

MystCity_Mapscript_ExitProtoHideout_Text_6:
	.string "Lars: {COLOR BLUE}I know.\n"
	.string "This isn't good...\p"
	.string "Of course {COLOR GREEN}Apollo{COLOR BLUE} is behind all of this...$"

MystCity_Mapscript_ExitProtoHideout_Text_7:
	.string "Lars: {COLOR GREEN}{PLAYER}{COLOR BLUE}.\p"
	.string "I know I've already sent you on a wild\n"
	.string "chase for {COLOR GREEN}Team Proto{COLOR BLUE}, but I need you to\l"
	.string "get to {COLOR GREEN}Sunflora Town{COLOR BLUE}, which is south of\l"
	.string "{COLOR GREEN}Altos City{COLOR BLUE}.\p"
	.string "{COLOR DARK_GREY}Lars:{COLOR BLUE} Underneath the town lies the\n"
	.string "{COLOR GREEN}Ryoko Catacombs{COLOR BLUE}.\p"
	.string "I suspect {COLOR GREEN}Team Proto{COLOR BLUE} might be hiding\n"
	.string "out in there to further their agenda.$"

MystCity_Mapscript_ExitProtoHideout_Text_8:
	.string "Mom: {COLOR RED}You're going to need this to cross\n"
	.string "{COLOR GREEN}Cobalt Sea{COLOR RED}.$"

MystCity_Mapscript_ExitProtoHideout_Text_9:
	.string "Mom: {COLOR RED}If you haven't been to {COLOR GREEN}Cobalt Sea{COLOR RED}\n"
	.string "yet, it's to the east of here.$"

MystCity_Mapscript_ExitProtoHideout_Text_10:
	.string "Lars: {COLOR BLUE}Now, make your way over to\n"
	.string "{COLOR GREEN}Sunflora Town{COLOR BLUE}.\p"
	.string "I'll be there waiting for you.$"

MystCity_Mapscript_ExitProtoHideout_Text_11:
	.string "Mom: {COLOR RED}Please stay safe, and keep\n"
	.string "training your Pokémon!\p"
	.string "If you have any questions for me, I'll\n"
	.string "be in my Lab.$"
