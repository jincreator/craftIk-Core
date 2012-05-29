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
