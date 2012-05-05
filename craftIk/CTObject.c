//
//  CTObject.c
//  craftIk
//
//  Created by Cyrus Hackford on 5/5/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#include "CTObject.h"


struct _CTObjectHeader {
	CTShort referenceCount;
};

struct _CTObjectTemplate {
	CTObjectHeader *header;
	char data[];
};


CTBOOL CTAllocate(void **objectPosition, size_t objectSize) {
	if(objectPosition==NULL)
		return NO;
	
	char *rawMemory=(char *)malloc(sizeof(CTObjectHeader)+objectSize);
	if(rawMemory==NULL)
		return NO;
	
	CTObjectHeader *rawHeader=(CTObjectHeader *)rawMemory;
	struct _CTObjectTemplate *rawObject=(struct _CTObjectTemplate *)(rawMemory+sizeof(CTObjectHeader));
	rawHeader->referenceCount=1;
	rawObject->header=rawHeader;
	
	*objectPosition=rawObject;
	
	return YES;
}

void CTRelease(void *object, void (*objectCleanUpFunction)(void *)) {
	struct _CTObjectTemplate *stdObj=(struct _CTObjectTemplate *)object;
	
	--(stdObj->header->referenceCount);
	if(stdObj->header->referenceCount==0) {
		if(objectCleanUpFunction!=NULL)
			objectCleanUpFunction(object);
		free(stdObj->header);
	}
}

void CTRetain(void *object) {
	++(((struct _CTObjectTemplate *)object)->header->referenceCount);
}