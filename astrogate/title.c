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

#include <cx16.h>
#include <conio.h>
#include <unistd.h>

#include "title.h"

#define     CH_DOWN         17
#define     CH_LEFT         157
#define     CH_REVERSE_ON   18
#define     CH_REVERSE_OFF  146
#define     CH_FILL_ANGLE   169

char petsciiLogo[] = {
    CH_LIGHTBLUE, CH_REVERSE_ON, CH_FILL_ANGLE, ' ', ' ', CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    ' ', CH_REVERSE_OFF, ' ', ' ', CH_REVERSE_ON, ' ', CH_REVERSE_OFF, CH_FILL_ANGLE, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    CH_REVERSE_ON, ' ', CH_REVERSE_OFF, ' ', ' ', CH_RED, CH_REVERSE_ON, 163, 223, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    CH_LIGHTBLUE, CH_REVERSE_OFF, 223, CH_REVERSE_ON, ' ', ' ', CH_REVERSE_OFF
};

void logo(unsigned char x, unsigned char y)
{
    int i;
    gotoxy(x,y);
    for(i=0; i<45; ++i)
          cbm_k_bsout(petsciiLogo[i]);
}

void showTitle()
{
   cputs("                                                          \r\n");
   cputs("                  eeeee eeeee ee   e                      \r\n");
   cputs("                  8   8 8   8 88   8                      \r\n");
   cputs("                  8e  8 8eee8 88  e8                      \r\n");
   cputs("                  88  8 88  8  8  8                       \r\n");
   cputs("                  88  8 88  8  8ee8                       \r\n");
   cputs("                                                          \r\n");
   cputs("                                                          \r\n");
   cputs("                  eeee eeeee eeeee eeeee eeeee e     eeee \r\n");
   cputs("                  8  8 8  88 8   8 8   \" 8  88 8     8    \r\n");
   cputs("                  8e   8   8 8e  8 8eeee 8   8 8e    8eee \r\n");
   cputs("                  88   8   8 88  8    88 8   8 88    88   \r\n");
   cputs("                  88e8 8eee8 88  8 8ee88 8eee8 88eee 88ee \r\n");
   cputs("                                                          \r\n");    
}

void showTitle2()
{
   cputs("        eeeee eeeee ee   e      eeee eeeee eeeee eeeee eeeee e     eeee \r\n");
   cputs("        8   8 8   8 88   8      8  8 8  88 8   8 8   \" 8  88 8     8   \r\n");
   cputs("        8e  8 8eee8 88  e8      8e   8   8 8e  8 8eeee 8   8 8e    8eee \r\n");
   cputs("        88  8 88  8  8  8       88   8   8 88  8    88 8   8 88    88   \r\n");
   cputs("        88  8 88  8  8ee8       88e8 8eee8 88  8 8ee88 8eee8 88eee 88ee \r\n");
}


void splash()
{
   unsigned char c;

   titleBlock();
//   gotoxy(0,54); 
//   textcolor(COLOR_LIGHTBLUE);
//   showTitle2();
//   cputsxy(0,52, "********************************************************************************");

   c = 18;
   logo(5,c+8);
   //textcolor(COLOR_LIGHTBLUE);
   //chlinexy(0,35,80);
   cputsxy(5,c+5,  "*********************************************************************");
   cputsxy(12,c+7, "system access restriction indigo:  authorized personnel only!!");
   cputsxy(12,c+9, "security key 8769-87011 initialized and armed, code black-355a");
   cputsxy(12,c+11,"authorized personnel only! unauthorized access is a felony per");
   cputsxy(12,c+13,"iiss code 355a by order of emperor artemsus.");
   cputsxy(5,c+15, "*********************************************************************");
   //chlinexy(0,45,80);

   textcolor(COLOR_YELLOW);
   //revers(1);
   cputsxy(25,c+18,"console initialized. press a key.");
   c = cgetc();
   //revers(0);

}

void titleBlock()
{
   gotoxy(0,54); 
   textcolor(COLOR_LIGHTBLUE);
   showTitle2();
   cputsxy(0,52, "********************************************************************************");
   gotoxy(0,1);
}

/*
char* splasha[13] = { // font style: "Block"
" _|_|_|      _|_|_|    _|_|_|                                              ",
" _|    _|  _|        _|                                                    ",
" _|_|_|    _|          _|_|                                                ",
" _|    _|  _|              _|                                              ",
" _|_|_|      _|_|_|  _|_|_|                                                ",
"                                                                           ",
"   _|_|_|  _|        _|                                                _|  ",
" _|        _|_|_|        _|_|_|    _|    _|    _|_|_|  _|  _|_|    _|_|_|  ",
"   _|_|    _|    _|  _|  _|    _|  _|    _|  _|    _|  _|_|      _|    _|  ",
"       _|  _|    _|  _|  _|    _|  _|    _|  _|    _|  _|        _|    _|  ",
" _|_|_|    _|    _|  _|  _|_|_|      _|_|_|    _|_|_|  _|          _|_|_|  ",
"                         _|              _|                                ",
"                         _|          _|_|                                  "
};
*/

   // font style: Banner3-D
//   cputs("::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
//   cputs(":::::::::::::::::::::'########:::'######:::'######::::::::::::::::::::::::::::::");
//   cputs("::::::::::::::::::::: ##.... ##:'##... ##:'##... ##:::::::::::::::::::::::::::::");
//   cputs("::::::::::::::::::::: ##:::: ##: ##:::..:: ##:::..::::::::::::::::::::::::::::::");
//   cputs("::::::::::::::::::::: ########:: ##:::::::. ######::::::::::::::::::::::::::::::");
//   cputs("::::::::::::::::::::: ##.... ##: ##::::::::..... ##:::::::::::::::::::::::::::::");
//   cputs("::::::::::::::::::::: ##:::: ##: ##::: ##:'##::: ##:::::::::::::::::::::::::::::");
//   cputs("::::::::::::::::::::: ########::. ######::. ######::::::::::::::::::::::::::::::");
//   cputs(":::::::::::::::::::::........::::......::::......:::::::::::::::::::::::::::::::");
//   cputs(":'######::'##::::'##:'####:'########::'##:::'##::::'###::::'########::'########:");
//   cputs("'##... ##: ##:::: ##:. ##:: ##.... ##:. ##:'##::::'## ##::: ##.... ##: ##.... ##");
//   cputs(" ##:::..:: ##:::: ##:: ##:: ##:::: ##::. ####::::'##:. ##:: ##:::: ##: ##:::: ##");
//   cputs(". ######:: #########:: ##:: ########::::. ##::::'##:::. ##: ########:: ##:::: ##");
//   cputs(":..... ##: ##.... ##:: ##:: ##.....:::::: ##:::: #########: ##.. ##::: ##:::: ##");
//   cputs("'##::: ##: ##:::: ##:: ##:: ##::::::::::: ##:::: ##.... ##: ##::. ##:: ##:::: ##");
//   cputs(". ######:: ##:::: ##:'####: ##::::::::::: ##:::: ##:::: ##: ##:::. ##: ########:");
//   cputs(":......:::..:::::..::....::..::::::::::::..:::::..:::::..::..:::::..::........::");
 
   // font style: Colossal
 //  cputs("888888b.    .d8888b.   .d8888b.                                                 ");
 //  cputs("888  \"88b  d88P  Y88b d88P  Y88b                                                ");
 //  cputs("888  .88P  888    888 Y88b.                                                     ");
 //  cputs("8888888K.  888         \"Y888b.                                                  ");
 //  cputs("888  \"Y88b 888            \"Y88b.                                                ");
 //  cputs("888    888 888    888       \"888                                                ");
 //  cputs("888   d88P Y88b  d88P Y88b  d88P                                                ");
 //  cputs("8888888P\"   \"Y8888P\"   \"Y8888P\"                                                 ");
 //  cputs("                                                                                ");
 //  cputs("                                                                                ");
 //  cputs("                                                                                ");
 //  cputs(" .d8888b.  888      d8b                                        888              ");
 //  cputs("d88P  Y88b 888      Y8P                                        888              ");
 //  cputs("Y88b.      888                                                 888              ");
 //  cputs(" \"Y888b.   88888b.  888 88888b.  888  888  8888b.  888d888 .d88888              ");
 //  cputs("    \"Y88b. 888 \"88b 888 888 \"88b 888  888     \"88b 888P\"  d88\" 888              ");
 //  cputs("      \"888 888  888 888 888  888 888  888 .d888888 888    888  888              ");
 //  cputs("Y88b  d88P 888  888 888 888 d88P Y88b 888 888  888 888    Y88b 888              ");
 //  cputs(" \"Y8888P\"  888  888 888 88888P\"   \"Y88888 \"Y888888 888     \"Y88888              ");
 //  cputs("                        888           888                                       ");
 //  cputs("                        888      Y8b d88P                                       ");
 //  cputs("                        888       \"Y88P\"                                        ");

   
//   for (i=0; i<13; ++i)
//   {
//      for (j=0; j<strlen(splasha[i]); ++j)
//      {
//         if (splasha[i][j] == ' ') cputc(' ');
//         if (splasha[i][j] == '_') cputc( LOW_LINE );
//         if (splasha[i][j] == '|') cputc( LEFT_VERTICAL_LINE );
//      }
//      cputs("\r\n");
//   }

//   font style: alpha
//           _____                    _____                    _____                                                                                                                                   
//          /\    \                  /\    \                  /\    \                                                                                                                                  
//         /::\    \                /::\    \                /::\    \                                                                                                                                 
//        /::::\    \              /::::\    \              /::::\    \                                                                                                                                
//       /::::::\    \            /::::::\    \            /::::::\    \                                                                                                                               
//      /:::/\:::\    \          /:::/\:::\    \          /:::/\:::\    \                                                                                                                              
//     /:::/__\:::\    \        /:::/  \:::\    \        /:::/__\:::\    \                                                                                                                             
//    /::::\   \:::\    \      /:::/    \:::\    \       \:::\   \:::\    \                                                                                                                            
//   /::::::\   \:::\    \    /:::/    / \:::\    \    ___\:::\   \:::\    \                                                                                                                           
//  /:::/\:::\   \:::\ ___\  /:::/    /   \:::\    \  /\   \:::\   \:::\    \                                                                                                                          
// /:::/__\:::\   \:::|    |/:::/____/     \:::\____\/::\   \:::\   \:::\____\                                                                                                                         
// \:::\   \:::\  /:::|____|\:::\    \      \::/    /\:::\   \:::\   \::/    /                                                                                                                         
//  \:::\   \:::\/:::/    /  \:::\    \      \/____/  \:::\   \:::\   \/____/                                                                                                                          
//   \:::\   \::::::/    /    \:::\    \               \:::\   \:::\    \                                                                                                                              
//    \:::\   \::::/    /      \:::\    \               \:::\   \:::\____\                                                                                                                             
//     \:::\  /:::/    /        \:::\    \               \:::\  /:::/    /                                                                                                                             
//      \:::\/:::/    /          \:::\    \               \:::\/:::/    /                                                                                                                              
//       \::::::/    /            \:::\    \               \::::::/    /                                                                                                                               
//        \::::/    /              \:::\____\               \::::/    /                                                                                                                                
//         \::/____/                \::/    /                \::/    /                                                                                                                                 
//          ~~                       \/____/                  \/____/                                                                                                                                  
                                                                                                                                                                                                    



// font style: Georgi16
//cputs("     ________      ____     ____                                                ");
//cputs("     `MMMMMMMM.   /MMMMM/  /MMMMM\\                                              ");
//cputs("      MM    `MM  /P    YM /M'    `                                              ");
//cputs("      MM     MM /M      Y MM                                                    ");
//cputs("      MM    .M/ MM        YM.                                                   ");
//cputs("      MMMMMMM(  MM         YMMMMM                                               ");
//cputs("      MM    `MM MM             `MM                                              ");
//cputs("      MM     MM MM              MM                                              ");
//cputs("      MM     MM YM      /       MM                                              ");
//cputs("      MM    .M/  \\M    // L    ,M/                                              ");
//cputs("     _MMMMMMM/'   YMMMM/  MYMMMM/                                               ");
//cputs("                                                                                ");
//cputs("                                                                                ");
//cputs("       ____  ___                                                    ___         ");
//cputs("      /MMMMM\\`MM      /MM                                           `MM         ");
//cputs("     /M'    ` MM      YMM                                            MM         ");
//cputs("     MM       MM  __  ___ __ ____  ____    ___   ___   ___  __   ____MM         ");
//cputs("     YM.      MM /MMM `MM `MMMMMMM `MM(    )M' /MMMMM  `MM /MM  /MMMMMM         ");
//cputs("      YMMMMM  MMM/ `MM MM  MM'  `MM `MM    /' /M'  `MM  MM// ' /M'  `MM         ");
//cputs("          `MM MM'   MM MM  MM    MM  YM.  ,P      ,/MM  MM'    MM    MM         ");
//cputs("           MM MM    MM MM  MM    MM   MM  M   ,/MM/'MM  MM     MM    MM         ");
//cputs("           MM MM    MM MM  MM    MM   `MM/'   MM'   MM  MM     MM    MM         ");
//cputs("     L    ,M/ MM    MM MM  MM.  ,M/    YMP    MM.  ,MM  MM     YM.  ,MM         ");
//cputs("     MYMMMM/ _MM_  _MM_MM_ MMYMMM/      M     `YMMM/'YM_MM_     YMMMMMM_        ");
//cputs("                           MM          /'                                       ");
//cputs("                           MM      (M),P                                        ");
//cputs("                          _MM_      YMM                                         ");
   
