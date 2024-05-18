/*
    Error message implementation of the Cobalt Compiler
    Copyright (C) 2023  Andy Shen

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include "Frontend/Lexer/errormsg.h"

int EM_tokpos = 0;

#define TEST 1

/* The code below is only for TEST, DO NOT COMPILE IT INTO RELEASE VERSION */
#if TEST

void LOG_ERRORMSG(int pos, char* s)
{
    printf("Error:%d,%s", pos, s);
}

#else

extern void LOG_ERRORMSG();

#endif
