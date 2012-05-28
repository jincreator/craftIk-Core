//
//  CTString.h
//  craftIk-Core
//
//  Created by Cyrus Hackford on 5/29/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#ifndef _CTSTRING_H_
#define _CTSTRING_H_

#include "CTTypes.h"


typedef struct _CTString CTString;


CTBOOL CTStringCopy(CTString **cloneString, CTString *sourceString);
CTBOOL CTStringInitWithCString(CTString **newString, char *sourceString, CTShort sourceLength);
void CTStringDealloc(void *existingCTStringObject);

#endif