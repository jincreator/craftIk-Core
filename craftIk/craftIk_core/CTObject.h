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

#ifndef _CTOBJECT_H_
#define _CTOBJECT_H_

#include "CTTypes.h"
#include <stdlib.h>


/*!
 * @typedef CTObjectHeader
 * @discussion Every single object that is designed to run inside craftIk MUST have this structure as the first field. Yes, this structure MUST be the first field in the object! Otherwise, our object management system will break down. :(
 */
typedef struct _CTObjectHeader CTObjectHeader;

/*!
 * Allocates necessary memory space for an object. Every single object MUST use this function.
 *
 * @param objectPosition A pointer that points desired memory location.
 * @param objectSize Required memory amount for an object. 
 * @return This function returns YES upon successful allocation. Otherwise, NO is returned.
 */
CTBOOL CTAllocate(void **objectPosition, size_t objectSize);

/*!
 * Decreases object's internal reference count by 1. If the count after the decrease is equal to 0, the object will be destroyed.
 *
 * @param object An object to process.
 * @param objectCleanUpFunction A pointer to the object-specific wrap up function. This can be NULL.
 *
 * @discussion Upon destroying the given object, if objectCleanUpFunction is not NULL, this function makes call to the function pointed by objectCleanUpFunction before actually destroying the object. So, the parameter is useful when the object requires special protocol to follow before destroying it.
 */
void CTRelease(void *object, void (*objectCleanUpFunction)(void *));

/*!
 * Increases object's internal reference count by 1.
 *
 * @param object An object to process.
 * @return The object that just got retained.
 */
void *CTRetain(void *object);

#endif
