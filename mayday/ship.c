#include <cx16.h>

#include "ship.h"

void ship_beowulf(Ship *ship)
{
    int x;

    ship->potentials[POWERPLANT]    = 2;
    ship->potentials[MANEUVER]      = 2;
    ship->potentials[JUMP]          = 2;
    ship->potentials[FUEL]          = 100;
    ship->potentials[HULL]          = 2;
    ship->potentials[HOLD]          = 80;
    ship->potentials[COMPUTER]      = 1;
    ship->potentials[TURRET1]       = 7;
    ship->potentials[TURRET2]       = 7;

    for(x=0; x<TOTAL_FEATURES; ++x)
       ship->damage[x] = 0;
}

void ship_put(Ship *ship, int x, int y)
{
    ship->x = x/10;
    ship->y = y/10;
}

void ship_turn(Ship *ship, int angloid)
{
   ship->heading += angloid;
}

//
//  This code uses the trig tables stored in bank 1
//
void ship_move(Ship *ship, int accel)
{
    int sin, cos;

    RAM_BANK = 1; // trig table is here
    sin = TRIG_RAM[ ship->heading ];
    cos = TRIG_RAM[ ship->heading + 64 ];

    if (ship->heading > 128)
    {
        sin %= 128;
        sin = -sin;
        cos %= 128;
        cos = -cos;
    }

    ship->dx += accel * cos;
    ship->dy += accel * sin;

    ship->x += ship->dx;
    ship->y += ship->dy;
}