#ifndef _SHIP_H_
#define _SHIP_H_

#define POWERPLANT  0
#define MANEUVER    1
#define JUMP        2
#define FUEL        3
#define HULL        4
#define HOLD        5
#define COMPUTER    6
#define TURRET1     7
#define TURRET2     8
#define TURRET3     9
#define TURRET4     10

#define TOTAL_FEATURES  11

#define TRIG_RAM        ((unsigned char *) 0xa000)

//
//  Heading is based on a 256-degree circle.
//  This is also what the trig table uses in Bank 1.
//
typedef struct {

    int heading : 8;
    int x       : 10;
    int y       : 10;
    int dx      : 7;
    int dy      : 7;

    unsigned char potentials[TOTAL_FEATURES];
    unsigned char damage[TOTAL_FEATURES];

} Ship;

void ship_beowulf(Ship *ship);
void ship_put(Ship *ship, int x, int y);
void ship_turn(Ship *ship, int angloid);
void ship_move(Ship *ship, int accel);

#endif
