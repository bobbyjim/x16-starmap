/*

    High Guard 1979: a starship construction program
    Copyright (C) 2022 Robert Eaglestone

    This file is part of High Guard 1.

    High Guard 1 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    High Guard 1  is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with High Guard 1 .  If not, see <https://www.gnu.org/licenses/>.

*/

#include <cx16.h>
#include <conio.h>
#include <string.h>

#include "menu.h"

#define     CORNER_NW       213
#define     CORNER_SW       202
#define     CORNER_NE       201
#define     CORNER_SE       203
#define     HORIZ           192
#define     VERT            221

#define     CROSS           219
#define     T_DOWN          178
#define     T_UP            177
#define     T_RIGHT         171
#define     T_LEFT          179

void menu_drawIntersection( int x, int y, int width, int height )
{
    cputcxy(x, y, CROSS);
    cputcxy(x+width, y, T_LEFT);
    cputcxy(x-width, y, T_RIGHT);
    cputcxy(x, y+height, T_UP);
    cputcxy(x, y-height, T_DOWN);
    
    while(--width)
    {
        cputcxy(x+width, y, HORIZ);
        cputcxy(x-width, y, HORIZ);
    }
    while(--height)
    {
        cputcxy(x, y+height, VERT);
        cputcxy(x, y-height, VERT);
    }
}

void menu_drawPanel( int x, int y, int width, int height, char* label, char* content )
{
	int tmp;

    --width;
    --height;

    cputcxy(x,       y,        CORNER_NW);
    cputcxy(x+width, y,        CORNER_NE);
    cputcxy(x,       y+height, CORNER_SW);
    cputcxy(x+width, y+height, CORNER_SE);

    for(tmp=x+1; tmp<x+width; ++tmp)
    {
        cputcxy(tmp,y,       HORIZ);
        cputcxy(tmp,y+height,HORIZ);
    }

    if (strcmp(label,""))
       cputsxy(x+2,y,label);

    while(--height)
    {
        cputcxy(x,      y+height,VERT);
        cputcxy(x+width,y+height,VERT);
    }

    cputsxy( x+2, y+2, content );
}