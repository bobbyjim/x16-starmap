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

#include <conio.h>
#include <6502.h>

#include "fairuse.h"
#include "title.h"
#include "common.h"
#include "design.h"

#define  DESIGN_MODE 0
#define  TEST_MODE   1

void set_PET_font()
{
   struct regs fontregs;
   fontregs.a = 4; // PET-like
   fontregs.pc = 0xff62;
   _sys(&fontregs);
}

void main() 
{
   unsigned char column = 29;
   unsigned int  counter = 0;
   fairuse_page();
   set_PET_font();

   clrscr();
   splash();
   clrscr();

   design_initShip();
   common_clearMainArea();
   design_showScreen();

   for(;;)
   {
      if (kbhit()) {
         switch(cgetc())
         {
            case 's': // spine
               design_pickSpine();
               break;
      
            case 't': // test design!
               design_determineFitness();
               break;
         }
         common_clearMainArea();
         design_showScreen();
      }
      ++counter;
      if (counter > 900)
      {
         counter = 0;
         ++column;
         if (column > 49)
            column = 29;
         gotoxy(29,45);
         cclear(20);
         gotox(column);
         cputc(32); // 209 = ball
      }
   }
}
