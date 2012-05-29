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
