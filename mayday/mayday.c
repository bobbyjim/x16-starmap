#include <conio.h>
#include <string.h>
#include <cbm.h>
#include <cx16.h>
#include <unistd.h>

#include "ship.h"
#include "map.h"

#define     TO_BANK_1      1
#define     TO_BANK_2      2

#define     TO_MAIN_RAM     0
#define     TO_VERA         2

Ship native, intruder;

int loadFile(char *fname, unsigned char bank)
{
   RAM_BANK = bank;
   memset(BANK_RAM, 0, 8190);
   cbm_k_setnam(fname);
   cbm_k_setlfs(0,8,0);
   cbm_k_load(TO_MAIN_RAM, 0xa000);
   return 0;
}

void main()
{
    int x;

//   cbm_k_bsout(0x8E); // revert to primary case
    cbm_k_setnam("petfont.bin");
    cbm_k_setlfs(0,8,0);
    cbm_k_load(TO_VERA, 0x0f800);

    loadFile("trig.bin", TO_BANK_1);

    ship_beowulf(&native);
    ship_beowulf(&intruder);

    ship_put(&native, 50, 50);
    ship_put(&intruder, 90, 90);

    for(x=0; x<10; ++x)
    {
        sleep(1);
        map_draw(&native);
        map_draw(&intruder);

        ship_move(&native, 1);
    }
}