//
//  CTSetting.c
//  craftIk
//
//  Created by Cyrus Hackford on 4/25/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#include "CTSetting.h"
#include "CTObject.h"
#include <string.h>


struct _CTSetting {
	CTBOOL allowFlight;
	CTBOOL allowNether;
	CTBOOL allowPvP;
	CTDifficulty difficulty;
	CTBOOL enableQuery;
	CTBOOL enableRcon;
	CTGameMode gameMode;
	CTBOOL generateStructures;
	CTString *levelName;
	CTULong levelSeed;
	CTLevelType levelType;
	CTShort maxBuildHeight;
	CTShort maxPlayerCount;
	CTBOOL onlineMode;
	CTString *serverDescription;
	CTString *serverIP;
	CTShort serverPort;
	CTBOOL spawnAnimals;
	CTBOOL spawnMonsters;
	CTBOOL spawnNPCs;
	CTBOOL useWhiteList;
	CTByte viewDistance;
};


static CTSetting *CTSettingGlobal(CTSetting *);
static CTULong CTStringHash(char *);


CTBOOL CTSettingGetAllowFlight() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowFlight;
}

CTBOOL CTSettingGetAllowNether() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowNether;
}

CTBOOL CTSettingGetAllowPvP() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowPvP;
}

CTDifficulty CTSettingGetDifficulty() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->difficulty;
}

CTBOOL CTSettingGetEnableQuery() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->enableQuery;
}

CTBOOL CTSettingGetEnableRcon() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->enableRcon;
}

CTGameMode CTSettingGetGameMode() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->gameMode;
}

CTBOOL CTSettingGetGenerateStructures() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->generateStructures;
}

CTString *CTSettingGetLevelName() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->levelName;
}

CTULong CTSettingGetLevelSeed() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->levelSeed;
}

CTLevelType CTSettingGetLevelType() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->levelType;
}

CTShort CTSettingGetMaxBuildHeight() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->maxBuildHeight;
}

CTShort CTSettingGetMaxPlayerCount() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->maxPlayerCount;
}

CTBOOL CTSettingGetOnlineMode() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->onlineMode;
}

CTString *CTSettingGetServerDescription() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->serverDescription;
}

CTString *CTSettingGetServerIP() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->serverIP;
}

CTShort CTSettingGetServerPort() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->serverPort;
}

CTBOOL CTSettingGetSpawnAnimals() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnAnimals;
}

CTBOOL CTSettingGetSpawnMonsters() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnMonsters;
}

CTBOOL CTSettingGetSpawnNPCs() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnNPCs;
}

CTBOOL CTSettingGetUseWhiteList() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->useWhiteList;
}

CTByte CTSettingGetViewDistance() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->viewDistance;
}

void CTSettingReload() {
	//@ Implement me!
}

static CTSetting *CTSettingGlobal(CTSetting *newSetting) {
	static CTBOOL initialized=NO;
	static CTSetting currentSetting;
	
	if(newSetting!=NULL) {
		memcpy(&currentSetting, newSetting, sizeof(CTSetting));
		initialized=YES;
	} else if(initialized==NO)
		CTSettingReload();
	
	return &currentSetting;
}

static CTULong CTStringHash(char *string) {
	CTULong hash=0;
	
	//@ Implement me!
	
	return hash;
}