#ifndef _DESIGN_H_
#define _DESIGN_H_

#define	INDEX_OF_DATACASTER		0
#define	INDEX_OF_MISSILES		1
#define	INDEX_OF_PA				2
#define INDEX_OF_MESON			3
#define INDEX_OF_INDUCER		4
#define INDEX_OF_TRACTOR		5
#define INDEX_OF_DISRUPTOR		6
#define INDEX_OF_BEAMS			7
#define INDEX_OF_SAND			8
#define INDEX_OF_SCREENS		9
#define INDEX_OF_SCRAMBLERS		10
#define INDEX_OF_GLOBES			11
#define	INDEX_OF_MANEUVER		12
#define INDEX_OF_JUMP			13
#define INDEX_OF_HOP			14
#define INDEX_OF_FIGHTERS		15
#define INDEX_OF_TROOPS			16
#define INDEX_OF_MARINES		17
#define	COMPONENT_LIST_SIZE		18

typedef struct {

	char     id;
	char     label[16];
	int      rating;  // or factor
	unsigned tons;

} Component;

typedef struct {

	char mission[2];
	char name[16];

	char sizeCode;
	long tons;

	char config;
	char tl;
	char armor;
	char computer;
	char purifiers;
	char bridge;
	unsigned mcr;
	int power;

	unsigned char ops, sec, def, eng, car, boa, lin;

	Component designList[20];

} ShipDesign;

void initShip();
void showScreen();
void adjustSupportElements();
void dumpShipProfile();

#endif