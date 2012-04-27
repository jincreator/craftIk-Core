//
//  CTString.h
//  craftIk
//
//  Created by Cyrus Hackford on 4/27/12.
//  Copyright (c) 2012 SI Cyrusian. All rights reserved.
//

#ifndef _CTSTRING_H_
#define _CTSTRING_H_

#include "CTBase.h"


typedef struct _CTString CTString;


BOOL CTStringClone(CTString **, CTString *);
BOOL CTStringCreate(CTString **, char *, CTInteger);

#endif