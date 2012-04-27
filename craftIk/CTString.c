//
//  CTString.c
//  craftIk
//
//  Created by Cyrus Hackford on 4/27/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#include "CTString.h"
#include <stdlib.h>
#include <string.h>


struct _CTString {
	CTInteger length;
	char *body;
};


BOOL CTStringClone(CTString **cloneString, CTString *sourceString) {
	return CTStringCreate(cloneString, sourceString->body, sourceString->length);
}

BOOL CTStringCreate(CTString **newString, char *sourceString, CTInteger sourceLength) {
	if(newString==NULL)
		return NO;
	
	*newString=(CTString *)malloc(sizeof(CTString));
	if(*newString==NULL)
		return NO;
	
	(*newString)->length=(sourceLength<0?strlen(sourceString):sourceLength);
	
	(*newString)->body=(char *)malloc(sizeof(char)*((*newString)->length));
	if((*newString)->body==NULL) {
		free(*newString);
		
		return NO;
	}
	memcpy((*newString)->body, sourceString, (*newString)->length);
	
	return YES;
}