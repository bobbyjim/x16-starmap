#include <stdlib.h>
#include <conio.h>
#include <peekpoke.h>
#include <stdint.h>

#include "common.h"

#define  TITLE_LINE_Y         56
#define  STATUS_LINE_Y        0

#define LOGICAL_FILE_NUM        1
#define IGNORE_LFN              0
#define SD_CARD                 8
#define EMULATOR_FILE_SYSTEM    8
#define HOST_FILE_SYSTEM        1
#define SA_IGNORE_HEADER        0
#define LOAD_FLAG               0

//
// #define X16_R39
// #undef  X16_R38
// and so on

#define  CHARACTER_MAP_ADDRESS_R38    0x0f800
#define  CHARACTER_MAP_ADDRESS_R39    0x0f000
#define  LOAD_SECONDARY_ADDRESS_R38   2
#define  LOAD_SECONDARY_ADDRESS_R39   3

#define  CHARACTER_MAP_ADDRESS         CHARACTER_MAP_ADDRESS_R39
#define  LOAD_SECONDARY_ADDRESS        LOAD_SECONDARY_ADDRESS_R39

void common_clearMainArea()
{
   uint8_t y;
   for(y=11; y<60; ++y)
   {
      cclearxy(0,y,80);
   }
}

void common_redline()
{
   textcolor(COLOR_RED);
   chline(80);
}

void common_greenline()
{
   textcolor(COLOR_GREEN);
   chline(80);
}

void common_titleLine()
{
    textcolor(COLOR_RED);
    chlinexy(0,TITLE_LINE_Y,80);
}


void common_statusLine()
{
   textcolor(COLOR_GRAY2);
   chlinexy(0,STATUS_LINE_Y,80);
   gotoxy(1,STATUS_LINE_Y);
   cputsxy(22,STATUS_LINE_Y," t r a v e l l e r   h i g h   g u a r d   5 ");
}

//void common_toDefaultColor()
//{
  // textcolor(COLOR_LIGHTBLUE);
//}

void common_loadCharacterSet(char* filename)
{
   cbm_k_setnam(filename);
   cbm_k_setlfs(0,8,0);
   cbm_k_load(LOAD_SECONDARY_ADDRESS, CHARACTER_MAP_ADDRESS);
}

