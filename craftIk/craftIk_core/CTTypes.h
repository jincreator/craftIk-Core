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

#ifndef _CTTYPES_H_
#define _CTTYPES_H_

#include <stdint.h>


typedef signed char CTBOOL;
#define YES ((CTBOOL)1)
#define NO ((CTBOOL)0)

typedef int8_t CTByte;
typedef uint8_t CTUByte;
typedef int16_t CTShort;
typedef uint16_t CTUShort;
typedef int32_t CTInteger;
typedef uint32_t CTUInteger;
typedef int64_t CTLong;
typedef uint64_t CTULong;

#endif
