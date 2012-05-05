//
//  CTString.h
//  craftIk
//
//  Created by Cyrus Hackford on 4/27/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#ifndef _CTSTRING_H_
#define _CTSTRING_H_

#include "CTTypes.h"


typedef struct _CTString CTString;


CTBOOL CTStringCopy(CTString **cloneString, CTString *sourceString);
CTBOOL CTStringInit(CTString **newString, char *sourceString, CTInteger sourceLength);
void CTStringCleanUp(void *existingCTStringObject);

#endif