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

#define     REVERSE_ON      0x12
#define     REVERSE_OFF     0x92

#define     CH_DOWN         17
#define     CH_LEFT         157
#define     CH_REVERSE_ON   18
#define     CH_REVERSE_OFF  146
#define     CH_FILL_ANGLE   169

char petsciiLogo[] = {
    CH_LIGHTBLUE, CH_REVERSE_ON, CH_FILL_ANGLE, ' ', ' ', CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    ' ', CH_REVERSE_OFF, ' ', ' ', CH_REVERSE_ON, ' ', CH_REVERSE_OFF, CH_FILL_ANGLE, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    CH_REVERSE_ON, ' ', CH_REVERSE_OFF, ' ', ' ', CH_RED, CH_REVERSE_ON, 163, 223, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_LEFT, CH_DOWN,
    CH_LIGHTBLUE, REVERSE_OFF, 223, REVERSE_ON, ' ', ' ', REVERSE_OFF
};

void logo(unsigned char x, unsigned char y)
{
    int i;
    gotoxy(x,y);
    for(i=0; i<45; ++i)
          cbm_k_bsout(petsciiLogo[i]);
}

void clearMainArea()
{
   uint8_t y;
   for(y=11; y<60; ++y)
   {
      cclearxy(0,y,80);
   }
}

void redline()
{
   textcolor(COLOR_RED);
   chline(80);
}

void greenline()
{
   textcolor(COLOR_GREEN);
   chline(80);
}

void titleLine()
{
    textcolor(COLOR_RED);
    chlinexy(0,TITLE_LINE_Y,80);
}


void statusLine()
{
   textcolor(COLOR_GRAY2);
   chlinexy(0,STATUS_LINE_Y,80);
   gotoxy(1,STATUS_LINE_Y);
   cputsxy(22,STATUS_LINE_Y," t r a v e l l e r   h i g h   g u a r d   5 ");
}

void toDefaultColor()
{
   textcolor(COLOR_LIGHTBLUE);
}

void common_loadCharacterSet(char* filename)
{
   cbm_k_setnam(filename);
   cbm_k_setlfs(0,8,0);
   cbm_k_load(LOAD_SECONDARY_ADDRESS, CHARACTER_MAP_ADDRESS);
}

