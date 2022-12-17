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

#include "fairuse.h"

void disclaim_page()
{
   bgcolor(COLOR_BLACK);
   clrscr();                                                                                                                                                                                                                                                                                             

   gotoxy(0,6);
   textcolor(COLOR_GRAY3);
   cputs("                         F A I R   U S E   P O L I C Y\r\n\r\n\r\n\r\n\r\n");
   cputs("      The Traveller game in all forms is owned by Far Future Enterprises.\r\n\r\n");
   cputs("                 Copyright 1977 - 2022 Far Future Enterprises. \r\n\r\n\r\n");
   cputs("     Traveller is a registered  trademark  of  Far Future Enterprises.  Far\r\n\r\n");
   cputs("     Future permits short programs,  web sites and  fanzines for this game,\r\n\r\n");
   cputs("     provided it contains this notice,  that  Far  Future  is notified, and\r\n\r\n");
   cputs("     subject to a withdrawal of permission on 90 days notice.  The contents\r\n\r\n");
   cputs("     of this program are for personal, non-commercial use only.  Any use of\r\n\r\n");
   cputs("     Far Future Enterprises's  copyrighted material or trademarks  anywhere\r\n\r\n");
   cputs("     on this program  and its files  should not be viewed as a challenge to\r\n\r\n");
   cputs("     those copyrights or trademarks. In addition, any program/articles/file\r\n\r\n");
   cputs("     in this resource  cannot  be  republished  or  distributed without the\r\n\r\n");
   cputs("     consent of the author who contributed it. \r\n");

   gotoxy(0,42);
   textcolor(COLOR_RED);
   chline(80);
   textcolor(COLOR_GRAY3);
   cputs("     TRAVELLER");

   revers(1);
   cputsxy(35,50, "press any key");
   revers(0);

   cgetc();
}