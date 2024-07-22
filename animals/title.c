/*

    ANIMAL: an animal generator for Traveller
    Copyright (C) 2022 Robert Eaglestone

    This is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This is distributed in the hope that it will be entertaining,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNEss FOR A PARTICULAR PURPOsE.  see the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with the source code.  If not, see <https://www.gnu.org/licenses/>.

*/

#include <cx16.h>
#include <conio.h>
#include <unistd.h>
#include <stdlib.h>

#include "title.h"

#define     CH_DOWN         17
#define     CH_LEFT         157
#define     CH_REVERsE_ON   18
#define     CH_REVERsE_OFF  146
#define     CH_FILL_ANGLE   169

char petsciiLogo[] = {
    CH_LIGHTBLUE, CH_REVERsE_ON, CH_FILL_ANGLE, ' ', ' ', CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    ' ', CH_REVERsE_OFF, ' ', ' ', CH_REVERsE_ON, ' ', CH_REVERsE_OFF, CH_FILL_ANGLE, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    CH_REVERsE_ON, ' ', CH_REVERsE_OFF, ' ', ' ', CH_RED, CH_REVERsE_ON, 163, 223, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    CH_LIGHTBLUE, CH_REVERsE_OFF, 223, CH_REVERsE_ON, ' ', ' ', CH_REVERsE_OFF
};

void logo(unsigned char x, unsigned char y)
{
    int i;
    gotoxy(x,y);
    for(i=0; i<45; ++i)
          cbm_k_bsout(petsciiLogo[i]);
}

void splash()
{
   unsigned char c = 18;

   clrscr();
   textcolor(COLOR_LIGHTBLUE);

   gotoy(4);
   cputs("      .s_ssss     .s_ssss     .s   .s_sss_s.    .s_ssss    s.        ssss  \r\n");
   cputs("     .ss~sssss   .ss~Ysssb   .ss  .ss~s*s~ss.  .ss~sssss   ss.      d&ssP  \r\n");
   cputs("     sss   ssss  sss   `ssb  sss  sss `Y' sss  sss   ssss  sss     d&s'    \r\n");
   cputs("     sss    sss  sss    sss  sss  sss     sss  sss    sss  sss     s&|     \r\n");
   cputs("     sss ssssss  sss    s&s  s&s  sss     sss  sss ssssss  s&s     s&s     \r\n");
   cputs("     s&s  sssss  s&s    s&s  s&s  s&s     s&s  s&s  sssss  s&s     Y&ss    \r\n");
   cputs("     s&s    s&s  s&s    s&s  s&s  s&s     s&s  s&s    s&s  s&s     `s&&s   \r\n");
   cputs("     s&s    s&s  s&s    s&s  s&s  s&s     s&s  s&s    s&s  s&s       `s*s  \r\n");
   cputs("     s*s    s&s  s*s    s*s  s*s  s*s     s*s  s*s    s&s  s*b        l*s  \r\n");
   cputs("     s*s    s*s  s*s    s*s  s*s  s*s     s*s  s*s    s*s  s*s.      .s*P  \r\n");
   cputs("     s*s    s*s  s*s    s*s  s*s  s*s     s*s  s*s    s*s   sssbs  sss*s   \r\n");
   cputs("     sss    s*s  s*s    sss  s*s  sss     s*s  sss    s*s    YssP  Yss'    \r\n");
   cputs("            sP   sP          sP           sP          sP                   \r\n");
   cputs("            Y    Y           Y            Y           Y                    \r\n");

   logo(5,c+8);
   cputsxy(5,c+5,  "*********************************************************************");
   cputsxy(12,c+7, "system access restriction indigo:  authorized personnel only!!");
   cputsxy(12,c+9, "security key 8769-87011 initialized and armed, code black-355a");
   cputsxy(12,c+11,"authorized personnel only! unauthorized access is a felony per");
   cputsxy(12,c+13,"iiss code 355a by order of emperor artemsus.");
   cputsxy(5,c+15, "*********************************************************************");

   textcolor(COLOR_YELLOW);
   cputsxy(25,c+20,"console initialized. press a key.");
   c = cgetc();
   _randomize();
}
