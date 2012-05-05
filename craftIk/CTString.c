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
	CTInteger length;
	char *body;
};


CTBOOL CTStringCopy(CTString **cloneString, CTString *sourceString) {
	return CTStringInit(cloneString, sourceString->body, sourceString->length);
}

CTBOOL CTStringInit(CTString **newString, char *sourceString, CTInteger sourceLength) {
	if(newString==NULL)
		return NO;
	
	if(CTAllocate((void **)newString, sizeof(CTString))==NO)
		return NO;
	
	(*newString)->length=(sourceLength<0?strlen(sourceString):sourceLength);
	
	(*newString)->body=(char *)malloc((*newString)->length);
	if((*newString)->body==NULL) {
		free(*newString);
		
		return NO;
	}
	memmove((*newString)->body, sourceString, (*newString)->length);
	
	return YES;
}

void CTStringCleanUp(void *existingCTStringObject) {
	free(((CTString *)existingCTStringObject)->body);
}