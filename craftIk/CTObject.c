//
//  CTObject.c
//  craftIk
//
//  Created by Cyrus Hackford on 5/5/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#include "CTObject.h"
#include <pthread.h>


struct _CTObjectHeader {
	CTShort referenceCount;
	/*
	pthread_mutex_t *lock;
	pthread_mutexattr_t *lockAttributes;
	//*/
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
	/*
	pthread_mutexattr_init(rawHeader->lockAttributes);
	pthread_mutexattr_settype(rawHeader->lockAttributes, PTHREAD_MUTEX_ERRORCHECK);
	pthread_mutex_init(rawHeader->lock, rawHeader->lockAttributes);
	//*/
	rawObject->header=rawHeader;
	
	*objectPosition=rawObject;
	
	return YES;
}

void CTRelease(void *object, void (*objectCleanUpFunction)(void *)) {
	struct _CTObjectTemplate *standardObject=(struct _CTObjectTemplate *)object;
	
	//pthread_mutex_lock(standardObject->header->lock);
	--(standardObject->header->referenceCount);
	if(standardObject->header->referenceCount==0) {
		if(objectCleanUpFunction!=NULL)
			objectCleanUpFunction(object);
		/*
		pthread_mutex_unlock(standardObject->header->lock);
		pthread_mutex_destroy(standardObject->header->lock);
		pthread_mutexattr_destroy(standardObject->header->lockAttributes);
		//*/
		free(standardObject->header);
	}// else
		//pthread_mutex_unlock(standardObject->header->lock);
}

void *CTRetain(void *object) {
	//struct _CTObjectTemplate *standardObject=(struct _CTObjectTemplate *)object;
	
	//pthread_mutex_lock(standardObject->header->lock);
	//++(standardObject->header->referenceCount);
	//pthread_mutex_unlock(standardObject->header->lock);
	++(((struct _CTObjectTemplate *)object)->header->referenceCount);
	
	return object;
}