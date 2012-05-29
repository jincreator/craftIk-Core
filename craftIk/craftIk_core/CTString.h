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

#ifndef _CTSTRING_H_
#define _CTSTRING_H_

#include "CTTypes.h"


typedef struct _CTString CTString;


CTBOOL CTStringCopy(CTString **cloneString, CTString *sourceString);
CTBOOL CTStringInitWithCString(CTString **newString, char *sourceString, CTShort sourceLength);
void CTStringDealloc(void *existingCTStringObject);

#endif
