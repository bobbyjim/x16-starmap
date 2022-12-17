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

#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <cx16.h>
#include <unistd.h>

#include "fairuse.h"
#include "init.h"
#include "common.h"
#include "design.h"

void initFont()
{
   cbm_k_bsout(CH_BLACK);
   cbm_k_bsout(0x01);  // #define TO_BACKGROUND	0x01
   clrscr();

   cbm_k_bsout(0x8E); // revert to primary case

   // load PET font
   common_loadCharacterSet("petfont.bin");
}

//
//   print splash screen
//
#define  LOW_LINE             164
#define  LEFT_VERTICAL_LINE   165

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

void commodore()
{

}

void splash()
{
   int i, j;

   gotoxy(0,0); 
   textcolor(COLOR_BLUE);

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
                                                                                                                                                                                                    

                                                                                                                                               
// font style: Doh    
cputs("\r\n\r\n\r\n\r\n");                                                                                                                                           
cputs("         bbbbbbbbbbbbbbbbb           ccccccccccccc   sssssssssssssss    \r\n");
cputs("         b::::::::::::::::b       ccc::::::::::::c ss:::::::::::::::s   \r\n");
cputs("         b::::::bbbbbb:::::b    cc:::::::::::::::cs:::::ssssss::::::s   \r\n");
cputs("         bb:::::b     b:::::b  c:::::cccccccc::::cs:::::s     sssssss   \r\n");
cputs("           b::::b     b:::::b c:::::c       ccccccs:::::s               \r\n");
cputs("           b::::b     b:::::bc:::::c              s:::::s               \r\n");
cputs("           b::::bbbbbb:::::b c:::::c               s::::ssss            \r\n");
cputs("           b:::::::::::::bb  c:::::c                ss::::::sssss       \r\n");
cputs("           b::::bbbbbb:::::b c:::::c                  sss::::::::ss     \r\n");
cputs("           b::::b     b:::::bc:::::c                     ssssss::::s    \r\n");
cputs("           b::::b     b:::::bc:::::c                          s:::::s   \r\n");
cputs("           b::::b     b:::::b c:::::c       cccccc            s:::::s   \r\n");
cputs("         bb:::::bbbbbb::::::b  c:::::cccccccc::::csssssss     s:::::s   \r\n");
cputs("         b:::::::::::::::::b    cc:::::::::::::::cs::::::ssssss:::::s   \r\n");
cputs("         b::::::::::::::::b       ccc::::::::::::cs:::::::::::::::ss    \r\n");
cputs("         bbbbbbbbbbbbbbbbb           ccccccccccccc sssssssssssssss      \r\n");
cputs("\r\n\r\n");

textcolor(COLOR_RED);
cputs("           b a t t l e - c l a s s   s h i p s  *  s h i p y a r d \r\n\r\n");
textcolor(COLOR_CYAN);
// font style: Cricket
cputs("          _______   __      __                                     __ \r\n");
cputs("         |   _   | |  |--. |__| .-----. .--.--. .---.-. .----. .--|  |\r\n");
cputs("         |   1___| |     | |  | |  _  | |  |  | |  _  | |   _| |  _  |\r\n");
cputs("         |____   | |__|__| |__| |   __| |___  | |___._| |__|   |_____|\r\n");
cputs("         |:  1   |              |__|    |_____|                       \r\n");
cputs("         |::.. . |                                                    \r\n");
cputs("         `-------'                                                    \r\n");
                                                              

// font style: Alligator2
//cputs(" ::::::::  :::    ::: ::::::: ::::::::  :::   :::   :::     ::::::::  :::::::: \r\n");
//cputs(":+:    :+: :+:    :+:   :+:   :+:   :+: :+:   :+: :+: :+:   :+:   :+: :+:   :+:\r\n");
//cputs("+:+        +:+    +:+   +:+   +:+   +:+  +:+ +:+ +:+   +:+  +:+   +:+ +:+   +:+\r\n");
//cputs("+#++:++#++ +#++:++#++   +#+   +#+:++#+    +#++: +#++:++#++: +#++:+#:  +#+   +:+\r\n");
//cputs("       +#+ +#+    +#+   +#+   +#+          +#+  +#+     +#+ +#+   +#+ +#+   +#+\r\n");
//cputs("#+#    #+# #+#    #+#   #+#   #+#          #+#  #+#     #+# #+#   #+# #+#   #+#\r\n");
//cputs(" ########  ###    ### ####### ###          ###  ###     ### ###   ### ######## \r\n");


//textcolor(COLOR_RED);
//cputs("\r\n\r\n");
//
//cputs("===============================================================================\r\n");
//cputs("====      ===  ====  ==    ==       ===  ====  =====  =====       ===       ===\r\n");
//cputs("===  ====  ==  ====  ===  ===  ====  ==   ==   ====    ====  ====  ==  ====  ==\r\n");
//cputs("===  ====  ==  ====  ===  ===  ====  ===  ==  ====  ==  ===  ====  ==  ====  ==\r\n");
//cputs("====  =======  ====  ===  ===  ====  ===  ==  ===  ====  ==  ===   ==  ====  ==\r\n");
//cputs("======  =====        ===  ===       =====    ====  ====  ==      ====  ====  ==\r\n");
//cputs("========  ===  ====  ===  ===  ===========  =====        ==  ====  ==  ====  ==\r\n");
//cputs("===  ====  ==  ====  ===  ===  ===========  =====  ====  ==  ====  ==  ====  ==\r\n");
//cputs("===  ====  ==  ====  ===  ===  ===========  =====  ====  ==  ====  ==  ====  ==\r\n");
//cputs("====      ===  ====  ==    ==  ===========  =====  ====  ==  ====  ==       ===\r\n");
//cputs("===============================================================================\r\n");

// font style: 3D Diagonal
//cputs("    ,---,.   ,----..    .--.--.      \r\n");
//cputs("  ,'  .'  \\ /   /   \\  /  /    '.  \r\n");
//cputs(",---.' .' ||   :     :|  :  /`. /    \r\n");
//cputs("|   |  |: |.   |  ;. /;  |  |--`     \r\n");
//cputs(":   :  :  /.   ; /--` |  :  ;_       \r\n");
//cputs(":   |    ; ;   | ;     \\  \\    `.  \r\n");
//cputs("|   :     \\|   : |      `----.   \\ \r\n");
//cputs("|   |   . |.   | '___   __ \\  \\  | \r\n");
//cputs("'   :  '; |'   ; : .'| /  /`--'  /   \r\n");
//cputs("|   |  | ; '   | '/  :'--'.     /    \r\n");
//cputs("|   :   /  |   :    /   `--'---'     \r\n");
//cputs("|   | ,'    \\   \\ .'               \r\n");
//cputs("`----'       `---`                   \r\n");


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
   
   

   logo(5,38);
   textcolor(COLOR_LIGHTBLUE);
   chlinexy(0,35,80);
   //cputsxy(5,35, "*********************************************************************");
   cputsxy(12,37,"welcome to the bcs ship design application.  with this system,");
   cputsxy(12,39,"you can  quickly  design battle-class ships -- bcs -- for the ");
   cputsxy(12,41,"traveller pencil-and-paper role-playing game, old-school style");
   cputsxy(12,43,"-- the way it's supposed to be done!");
   //cputsxy(5,45, "*********************************************************************");
   chlinexy(0,45,80);


   sleep(1);
   textcolor(COLOR_YELLOW);
   revers(1);
   cputsxy(30,51,"press a key to start");
   revers(0);
   cgetc();
}

void main() 
{
   disclaim_page();
   initFont();
   splash();

   initShip();
   for(;;)
   {
      clearMainArea();
      showScreen();
      adjustSupportElements();
   }
}
