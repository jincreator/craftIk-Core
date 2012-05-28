//
//  CTString.c
//  craftIk
//
//  Created by Cyrus Hackford on 4/27/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

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