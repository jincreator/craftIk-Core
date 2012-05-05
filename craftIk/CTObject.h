//
//  CTObject.h
//  craftIk
//
//  Created by Cyrus Hackford on 5/5/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#ifndef _CTOBJECT_H_
#define _CTOBJECT_H_

#include "CTTypes.h"
#include <stdlib.h>


/*!
 * @typedef CTObjectHeader
 * @discussion Every single object that is designed to run inside craftIk MUST have this structure as the first field. Yes, this structure MUST be the first field in the object! Otherwise, this reference counting system will broke. :(
 */
typedef struct _CTObjectHeader CTObjectHeader;

CTBOOL CTAllocate(void **objectPosition, size_t objectSize);

/*!
 * Decreases object's internal reference count by 1. If the count after the decrease is equal to 0, the object will be destroyed.
 *
 * @param object An object to process.
 * @param objectCleanUpFunction A pointer to the object-specific wrap up function. This can be NULL.
 *
 * @discussion Upon destroying the given object, if wrapUpFunc is not NULL, this function makes call to the function pointed by wrapUpFunc before actually destroying the object. So, the parameter is useful when the object requires special protocol to follow before destroying it.
 */
void CTRelease(void *object, void (*objectCleanUpFunction)(void *));

/*!
 * Increases object's internal reference count by 1.
 *
 * @param object An object to process.
 */
void CTRetain(void *object);

#endif