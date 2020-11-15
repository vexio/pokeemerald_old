VerdanturfTown_FriendshipRatersHouse_MapScripts:: @ 8203030
	.byte 0

FrostpineCity_Object_FriendshipRater::
	lock
	faceplayer
	msgbox FrostpineCity_Object_FriendshipRater_Text_0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FrostpineCity_Object_FriendshipRater_1
	msgbox FrostpineCity_Object_FriendshipRater_Text_10, MSGBOX_AUTOCLOSE
	release
	end

FrostpineCity_Object_FriendshipRater_1:
	msgbox FrostpineCity_Object_FriendshipRater_Text_1, MSGBOX_AUTOCLOSE
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	delay 20
	bufferleadmonspeciesname 0
	switch VAR_RESULT
	case 0, FrostpineCity_Object_FriendshipRater_6
	case 1, FrostpineCity_Object_FriendshipRater_7
	case 2, FrostpineCity_Object_FriendshipRater_8
	case 3, FrostpineCity_Object_FriendshipRater_9
	case 4, FrostpineCity_Object_FriendshipRater_10
	case 5, FrostpineCity_Object_FriendshipRater_11
	case 6, FrostpineCity_Object_FriendshipRater_12
FrostpineCity_Object_FriendshipRater_4:
	closemessage
	release
	end

FrostpineCity_Object_FriendshipRater_6:
	msgbox FrostpineCity_Object_FriendshipRater_Text_2, MSGBOX_AUTOCLOSE
	goto FrostpineCity_Object_FriendshipRater_4

FrostpineCity_Object_FriendshipRater_7:
	msgbox FrostpineCity_Object_FriendshipRater_Text_3, MSGBOX_AUTOCLOSE
	goto FrostpineCity_Object_FriendshipRater_4

FrostpineCity_Object_FriendshipRater_8:
	msgbox FrostpineCity_Object_FriendshipRater_Text_4, MSGBOX_AUTOCLOSE
	goto FrostpineCity_Object_FriendshipRater_4

FrostpineCity_Object_FriendshipRater_9:
	msgbox FrostpineCity_Object_FriendshipRater_Text_5, MSGBOX_AUTOCLOSE
	goto FrostpineCity_Object_FriendshipRater_4

FrostpineCity_Object_FriendshipRater_10:
	msgbox FrostpineCity_Object_FriendshipRater_Text_6, MSGBOX_AUTOCLOSE
	goto FrostpineCity_Object_FriendshipRater_4

FrostpineCity_Object_FriendshipRater_11:
	msgbox FrostpineCity_Object_FriendshipRater_Text_7, MSGBOX_AUTOCLOSE
	goto FrostpineCity_Object_FriendshipRater_4

FrostpineCity_Object_FriendshipRater_12:
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	playse SE_PIN
	waitse
	msgbox FrostpineCity_Object_FriendshipRater_Text_8
	goto_if_unset FLAG_FROSTPINECITY_TM_RETURN, FrostpineCity_Object_FriendshipRater_13
	goto FrostpineCity_Object_FriendshipRater_4

FrostpineCity_Object_FriendshipRater_13:
	msgbox FrostpineCity_Object_FriendshipRater_Text_9
	giveitem ITEM_TM27_RETURN, 1
	setflag FLAG_FROSTPINECITY_TM_RETURN
	goto FrostpineCity_Object_FriendshipRater_4


FrostpineCity_Object_Pikachu::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, 0
	msgbox FrostpineCity_Object_Pikachu_Text_0
	waitmoncry
	release
	end


FrostpineCity_Object_FriendshipRater_Text_0:
	.string "{COLOR RED}Hello.\n"
	.string "I'm the {COLOR GREEN}Friendship Rater{COLOR RED}.\p"
	.string "I can rate your Pokémon's friendliness\n"
	.string "towards it's trainer.\p"
	.string "Would you like me to see your Pokémon?$"

FrostpineCity_Object_FriendshipRater_Text_1:
	.string "{COLOR RED}Will do.\p"
	.string "Hm...$"

FrostpineCity_Object_FriendshipRater_Text_2:
	.string "{COLOR RED}Oh my...\p"
	.string "Your {COLOR GREEN}{STR_VAR_1}{COLOR RED} simply detests\n"
	.string "you!\p"
	.string "Doesn't that make you uncomfortable?$"

FrostpineCity_Object_FriendshipRater_Text_3:
	.string "{COLOR RED}Your {COLOR GREEN}{STR_VAR_1}{COLOR RED} is very wary.\p"
	.string "It doesn't like you at all.$"

FrostpineCity_Object_FriendshipRater_Text_4:
	.string "{COLOR RED}Your {COLOR GREEN}{STR_VAR_1}{COLOR RED} is not quite used\n"
	.string "to you yet.\p"
	.string "Neither loves or hates you.$"

FrostpineCity_Object_FriendshipRater_Text_5:
	.string "{COLOR RED}Your {COLOR GREEN}{STR_VAR_1}{COLOR RED} seems to be\n"
	.string "getting used to you.$"

FrostpineCity_Object_FriendshipRater_Text_6:
	.string "{COLOR RED}Your {COLOR GREEN}{STR_VAR_1}{COLOR RED} likes you quite a\n"
	.string "lot!\p"
	.string "It wants to be babied a little.$"

FrostpineCity_Object_FriendshipRater_Text_7:
	.string "{COLOR RED}Your {COLOR GREEN}{STR_VAR_1}{COLOR RED} is very happy!\p"
	.string "It likes you quite a lot.$"

FrostpineCity_Object_FriendshipRater_Text_8:
	.string "{COLOR RED}Your {COLOR GREEN}{STR_VAR_1}{COLOR RED} absolutely adores\n"
	.string "you!\p"
	.string "It makes me happy seeing them!$"

FrostpineCity_Object_FriendshipRater_Text_9:
	.string "{COLOR RED}This TM will be very useful for\n"
	.string "{COLOR GREEN}{STR_VAR_1}{COLOR RED}.$"

FrostpineCity_Object_FriendshipRater_Text_10:
	.string "{COLOR RED}Understandable.\p"
	.string "Please treat your Pokémon well!$"

FrostpineCity_Object_Pikachu_Text_0:
	.string "Pika pika!$"
