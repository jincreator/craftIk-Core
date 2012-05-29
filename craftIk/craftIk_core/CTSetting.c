/*
	craftIk - A custom Minecraft server written in C.
	Copyright (C) 2012, SI Cyrusian. All Rights Reserved.
	Minecraft is a trademark of Mojang AB.

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CTSetting.h"
#include "CTObject.h"
#include <stdio.h>
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


static struct _CTSetting *CTSettingGlobal(struct _CTSetting *);
static CTULong CTStringHash(char *);


CTBOOL CTSettingGetAllowFlight() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowFlight;
}

CTBOOL CTSettingGetAllowNether() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowNether;
}

CTBOOL CTSettingGetAllowPvP() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->allowPvP;
}

CTDifficulty CTSettingGetDifficulty() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->difficulty;
}

CTBOOL CTSettingGetEnableQuery() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->enableQuery;
}

CTBOOL CTSettingGetEnableRcon() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->enableRcon;
}

CTGameMode CTSettingGetGameMode() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->gameMode;
}

CTBOOL CTSettingGetGenerateStructures() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->generateStructures;
}

CTString *CTSettingGetLevelName() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return CTRetain(setting->levelName);
}

CTULong CTSettingGetLevelSeed() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->levelSeed;
}

CTLevelType CTSettingGetLevelType() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->levelType;
}

CTShort CTSettingGetMaxBuildHeight() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->maxBuildHeight;
}

CTShort CTSettingGetMaxPlayerCount() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->maxPlayerCount;
}

CTBOOL CTSettingGetOnlineMode() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->onlineMode;
}

CTString *CTSettingGetServerDescription() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return CTRetain(setting->serverDescription);
}

CTString *CTSettingGetServerIP() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return CTRetain(setting->serverIP);
}

CTShort CTSettingGetServerPort() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->serverPort;
}

CTBOOL CTSettingGetSpawnAnimals() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnAnimals;
}

CTBOOL CTSettingGetSpawnMonsters() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnMonsters;
}

CTBOOL CTSettingGetSpawnNPCs() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->spawnNPCs;
}

CTBOOL CTSettingGetUseWhiteList() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->useWhiteList;
}

CTByte CTSettingGetViewDistance() {
	struct _CTSetting *setting=CTSettingGlobal(NULL);
	
	return setting->viewDistance;
}

void CTSettingReload() {
	FILE *settingFile=NULL;
	
	settingFile=fopen("server.cfg", "r"); //@ file location?!?!?!
	
	//@ Implement me!
	
	fclose(settingFile);
	settingFile=NULL;
}

static struct _CTSetting *CTSettingGlobal(struct _CTSetting *newSetting) {
	static CTBOOL initialized=NO;
	static struct _CTSetting currentSetting;
	
	if(newSetting!=NULL) {
		memcpy(&currentSetting, newSetting, sizeof(struct _CTSetting));
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
