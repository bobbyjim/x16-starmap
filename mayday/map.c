#include <conio.h>
#include "map.h"
#include "ship.h"

#define     MAX_COLS    80/1000
#define     MAX_ROWS    60/1000

void map_erase(Ship *ship)
{
   cputcxy(ship->x * MAX_COLS, ship->y * MAX_ROWS, ' ');
}

void map_draw(Ship *ship)
{
   cputcxy(ship->x * MAX_COLS, ship->y * MAX_ROWS, '@');
}
