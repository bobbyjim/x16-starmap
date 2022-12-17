#include <cbm.h>
#include <peekpoke.h>

#include "starmap-api.h"
#include "units.h"

#define LOGICAL_FILE_NUM        1
#define IGNORE_LFN              0
#define SD_CARD                 8
#define EMULATOR_FILE_SYSTEM    8
#define HOST_FILE_SYSTEM        1
#define SA_IGNORE_HEADER        0
#define LOAD_FLAG               0

//
//  Loads a sector into banked RAM.
//
void loadSectorAt(char* filename, unsigned char bank)
{
    POKE(0,bank);
    cbm_k_setnam(filename);
    cbm_k_setlfs(IGNORE_LFN, EMULATOR_FILE_SYSTEM, SA_IGNORE_HEADER);
    cbm_k_load(LOAD_FLAG, 0xa000);
}

void main()
{
    loadSectorAt( "spin.bin", 10 );
    //loadSectorAt( "dene.bin", 12 );
    //loadSectorAt( "tugl.bin", 14 );
    //loadSectorAt( "gvur.bin", 16 );
    //loadSectorAt( "troj.bin", 18 );
    //loadSectorAt( "corr.bin", 20 );
}

