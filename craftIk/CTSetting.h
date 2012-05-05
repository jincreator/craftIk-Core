//
//  CTSetting.h
//  craftIk
//
//  Created by Cyrus Hackford on 4/25/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#ifndef _CTSETTING_H_
#define _CTSETTING_H_

#include "CTTypes.h"
#include "CTString.h"


enum {
	CTGameModeSurvival=0,
	CTGameModeCreative
};
typedef CTUByte CTGameMode;

enum {
	CTDifficultyPeaceful=0,
	CTDifficultyEasy,
	CTDifficultyNormal,
	CTDifficultyHard
};
typedef CTUByte CTDifficulty;

enum {
	CTLevelTypeDefault=0,
	CTLevelTypeFlat
};
typedef CTUByte CTLevelType;

typedef struct _CTSetting CTSetting;


CTBOOL CTSettingGetAllowFlight();
CTBOOL CTSettingGetAllowNether();
CTBOOL CTSettingGetAllowPvP();
CTDifficulty CTSettingGetDifficulty();
CTBOOL CTSettingGetEnableQuery();
CTBOOL CTSettingGetEnableRcon();
CTGameMode CTSettingGetGameMode();
CTBOOL CTSettingGetGenerateStructures();
CTString *CTSettingGetLevelName();
CTULong CTSettingGetLevelSeed();
CTLevelType CTSettingGetLevelType();
CTShort CTSettingGetMaxBuildHeight();
CTShort CTSettingGetMaxPlayerCount();
CTBOOL CTSettingGetOnlineMode();
CTString *CTSettingGetServerDescription();
CTString *CTSettingGetServerIP();
CTShort CTSettingGetServerPort();
CTBOOL CTSettingGetSpawnAnimals();
CTBOOL CTSettingGetSpawnMonsters();
CTBOOL CTSettingGetSpawnNPCs();
CTBOOL CTSettingGetUseWhiteList();
CTByte CTSettingGetViewDistance();

void CTSettingReload();

#endif