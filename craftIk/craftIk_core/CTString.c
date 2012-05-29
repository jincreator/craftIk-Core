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

#include "CTString.h"
#include "CTObject.h"
#include <string.h>


struct _CTString {
	CTObjectHeader *header;
	CTShort length; // JString compatible
	char *body;
};


CTBOOL CTStringCopy(CTString **cloneString, CTString *sourceString) {
	return CTStringInitWithCString(cloneString, sourceString->body, sourceString->length);
}

CTBOOL CTStringInitWithCString(CTString **newString, char *sourceString, CTShort sourceLength) {
	if(newString==NULL)
		return NO;
	
	if(CTAllocate((void **)newString, sizeof(CTString))==NO)
		return NO;
	
	(*newString)->length=(sourceLength<0?(CTShort)strlen(sourceString):sourceLength);
	
	(*newString)->body=(char *)malloc((*newString)->length);
	if((*newString)->body==NULL) {
		CTRelease(*newString, NULL);
		
		return NO;
	}
	memmove((*newString)->body, sourceString, (*newString)->length);
	
	return YES;
}

void CTStringDealloc(void *existingCTStringObject) {
	free(((CTString *)existingCTStringObject)->body);
}
