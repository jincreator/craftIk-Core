//
//  CTSetting.h
//  craftIk
//
//  Created by Cyrus Hackford on 4/25/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#ifndef _CTSETTING_H_
#define _CTSETTING_H_

#include "CTBase.h"
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


BOOL CTSettingGetAllowFlight();
BOOL CTSettingGetAllowNether();
BOOL CTSettingGetAllowPvP();
CTDifficulty CTSettingGetDifficulty();
BOOL CTSettingGetEnableQuery();
BOOL CTSettingGetEnableRcon();
CTGameMode CTSettingGetGameMode();
BOOL CTSettingGetGenerateStructures();
CTString *CTSettingGetLevelName();
CTULong CTSettingGetLevelSeed();
CTLevelType CTSettingGetLevelType();
CTShort CTSettingGetMaxBuildHeight();
CTShort CTSettingGetMaxPlayerCount();
BOOL CTSettingGetOnlineMode();
CTString *CTSettingGetServerDescription();
CTString *CTSettingGetServerIP();
CTShort CTSettingGetServerPort();
BOOL CTSettingGetSpawnAnimals();
BOOL CTSettingGetSpawnMonsters();
BOOL CTSettingGetSpawnNPCs();
BOOL CTSettingGetUseWhiteList();
CTByte CTSettingGetViewDistance();

void CTSettingReload();

#endif