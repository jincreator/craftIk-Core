//
//  CTSetting.c
//  craftIk
//
//  Created by Cyrus Hackford on 4/25/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#include "CTSetting.h"
#include <string.h>


struct _CTSetting {
	BOOL allowFlight;
	BOOL allowNether;
	BOOL allowPvP;
	CTDifficulty difficulty;
	BOOL enableQuery;
	BOOL enableRcon;
	CTGameMode gameMode;
	BOOL generateStructures;
	CTString *levelName;
	CTULong levelSeed;
	CTLevelType levelType;
	CTShort maxBuildHeight;
	CTShort maxPlayerCount;
	BOOL onlineMode;
	CTString *serverDescription;
	CTString *serverIP;
	CTShort serverPort;
	BOOL spawnAnimals;
	BOOL spawnMonsters;
	BOOL spawnNPCs;
	BOOL useWhiteList;
	CTByte viewDistance;
};


static CTSetting *CTSettingGlobal(CTSetting *);
static CTULong CTStringHash(char *);


BOOL CTSettingGetAllowFlight() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowFlight;
}

BOOL CTSettingGetAllowNether() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowNether;
}

BOOL CTSettingGetAllowPvP() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowPvP;
}

CTDifficulty CTSettingGetDifficulty() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->difficulty;
}

BOOL CTSettingGetEnableQuery() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->enableQuery;
}

BOOL CTSettingGetEnableRcon() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->enableRcon;
}

CTGameMode CTSettingGetGameMode() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->gameMode;
}

BOOL CTSettingGetGenerateStructures() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->generateStructures;
}

CTString *CTSettingGetLevelName() {
	CTSetting *setting=CTSettingGlobal(NULL);
	CTString *levelName=NULL;
	
	CTStringClone(&levelName, setting->levelName);
	
	return levelName;
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

BOOL CTSettingGetOnlineMode() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->onlineMode;
}

CTString *CTSettingGetServerDescription() {
	CTSetting *setting=CTSettingGlobal(NULL);
	CTString *serverDescription=NULL;
	
	CTStringClone(&serverDescription, setting->serverDescription);
	
	return serverDescription;
}

CTString *CTSettingGetServerIP() {
	CTSetting *setting=CTSettingGlobal(NULL);
	CTString *serverIP=NULL;
	
	CTStringClone(&serverIP, setting->serverIP);
	
	return serverIP;
}

CTShort CTSettingGetServerPort() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->serverPort;
}

BOOL CTSettingGetSpawnAnimals() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnAnimals;
}

BOOL CTSettingGetSpawnMonsters() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnMonsters;
}

BOOL CTSettingGetSpawnNPCs() {
	CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnNPCs;
}

BOOL CTSettingGetUseWhiteList() {
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
	static BOOL initialized=NO;
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