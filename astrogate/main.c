/*

    ASTROG: an astrogator's console emulator
    Copyright (C) 2022 Robert Eaglestone

    This is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This is distributed in the hope that it will be entertaining,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with the source code.  If not, see <https://www.gnu.org/licenses/>.

*/

#include <conio.h>
#include <6502.h>

#include "title.h"
#include "cli.h"

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
   cbm_k_bsout(CH_BLACK);
   cbm_k_bsout(0x01);  // #define TO_BACKGROUND	0x01
   clrscr();

   cbm_k_bsout(0x8E); // revert to primary case

   set_PET_font();
   splash();
   clrscr();

   cli();
}
