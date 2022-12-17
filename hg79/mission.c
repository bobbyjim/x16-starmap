#include "common.h"
#include "mission.h"

PickList missionTypes[NUM_OF_MISSIONS] = 
{
   { "bb", "battleship"   },
   { "cb", "cruiser"      },
   { "gg", "frigate"      },
   { "de", "destroyer"    },
   { "ec", "escort"       },
   { "rb", "battle rider" }
};

PickList configTypes[NUM_OF_CONFIGURATIONS] =
{
   { "c", "cluster" },
   { "b", "braced"  },
   { "p", "planetoid" },
   { "u", "unstreamlined" },
   { "s", "streamlined" },
   { "a", "airframe" },
   { "l", "lift body" }
};

PickList techlevels[NUM_OF_TLS] =
{
   { "9", "tl-9 (early interstellar)" },
   { "a", "tl-10 (early interstellar)" },
   { "b", "tl-11 (interstellar)" },
   { "c", "tl-12 (interstellar)" },
   { "d", "tl-13 (interstellar)" },
   { "e", "tl-14 (interstellar)" },
   { "f", "tl-15 (high interstellar)" },
   { "g", "tl-16 (high interstellar)" },
   { "h", "tl-17 (high interstellar)" },
   { "j", "tl-18 (vhigh interstellar)" },
   { "k", "tl-19 (vhigh interstellar)" },
   { "l", "tl-20 (vhigh interstellar)" },
   { "m", "tl-21 (xhigh interstellar)" }
};
