#include <stdlib.h>

#include "design.h"
#include "test.h"

#define     TEST_UNFIT              0
#define     TEST_LOW_FITNESS        10
#define     TEST_MOD_FITNESS        30
#define     TEST_HIGH_FITNESS       75

//
//  This is where we launch random ships against the design 
//  until it is killed.  This means we need a bank of well-designed
//  ships ranging from small to large.
//
//  Of course, we start the proving ground based on your ship's
//  weapons capacity.  Say we total the possible damage from your
//  ship and divide by two.  That's where we start testing your
//  design.
//
//  THAT means our bank of test ships are ranked by damage capability?
//
unsigned char test_runTest(ShipDesign* ship)
{
    unsigned char opponentSpine = 0;
    unsigned char opponentArmor = 1;
    unsigned char fitness = TEST_UNFIT;

    _randomize();

    for(opponentSpine = 0; opponentSpine < 24; ++opponentSpine) // A to Z
    {
        if (fitness < 245)
           if (ship->spine > opponentArmor) fitness += 10;

        if (fitness > 10)
           if (opponentSpine > ship->armor) fitness--;
    }

    return fitness;
}


void test_showStatus()
{

}

void test_selectWeapon()
{

}

void test_selectDefense()
{

}

void test_attackShip()
{

}

void test_defendShip()
{

}


