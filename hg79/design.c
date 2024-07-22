#include <conio.h>
#include <stdio.h>

#include "design.h"
#include "radio.h"
#include "mission.h"
#include "menu.h"
#include "test.h"
#include "common.h"

#define	 MENU_Y		3

// #define	HORIZ_BAR	192
// #define HORIZ_BAR2	195
// #define VERT_BAR_R	221
// #define VERT_BAR_L  194

// #define NW_CORNER   172
// #define NE_CORNER	187
// #define SW_CORNER	188
// #define SE_CORNER	190

// #define NW_CURVE	213
// #define NE_CURVE 	201
// #define SW_CURVE	202
// #define SE_CURVE	203

// #define	MAIN_LIST_SIZE	5
// #define COMPONENT_MAX 	18


// char *componentName[COMPONENT_LIST_SIZE] = {
// 	"datacaster",
// 	"missile",
// 	"pa",
// 	"meson",
// 	"inducer",
// 	"tractor",
// 	"disruptor",
// 	"beams",
// 	"sand",
// 	"screens",
// 	"scramblers",
// 	"globes",
// 	"maneuver",
// 	"jump",
// 	"hop",
// 	"fighters",
// 	"troops",
// 	"marines"
// };

char ehex[] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k',
	'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'u', 'v',
	'w', 'x', 'y', 'z'
};

// char topRow[] = {
// 	192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 192, 0
// };
// char bottomRow[] = {
// 	195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 195, 0
// };

// extern PickList missionTypes[];
// extern PickList configTypes[];
// extern PickList techlevels[];

ShipDesign ship;
unsigned char fitness = 0;
char spineContent[ 15 ] = "";

// char mission;
// char tl;
// char tons;
// char computer;
// char maneuver;
// char jump;
// char power;
// char sand, screen, damper, globe, repulsor;
// char laser, energy, pa, meson, missile;
// char armor    = 1;  // = yes
// char refinery = 12; // = 12 hours
// char scoops   = 1;  // = yes

// char usp[30];

// char prompt(uint8_t x, uint8_t y, char* msg)
// {
//    cputsxy(0,y,msg);
//    gotox(x);
//    return cgetc();
// }

// char promptEhex(uint8_t x, uint8_t y, char* msg)
// {
//    for(;;)
//    {
//       char c = prompt(x, y, msg);
//       if (c >= 'a' && c <= 'z' && c != 'i' && c != 'o')
//          return c;
//    }
//    return 0;
// }

// int prompt06(uint8_t x, uint8_t y, char* msg)
// {
//    for(;;)
//    {
//       char c = prompt(x, y, msg);
//       if (c >= '0' && c <= '6')
//          return (int) (c - '0');
//    }
//    return 0;
// }

// void design_setSize( char sizeCode )
// {
//    ship.sizeCode = sizeCode; // 65 thru whatever.
// }

// long design_getTons()
// {
// 	return ship.tons;

// //    switch(ship.sizeCode)
// //    {
// //       case 'a': return 2400L;    
// //       case 'b': return 3600L;    
// //       case 'c': return 4800L;    
// // 	  case 'd': return 6000L;    
// //       case 'e': return 7200L;    
// //       case 'f': return 8400L;    
// //       case 'g': return 9600L;    
// //       case 'h': return 20000L;   
// //       case 'j': return 35000L;   
// //       case 'k': return 50000L;   
// //       case 'l': return 75000L;   
// //       case 'm': return 100000L;  
// //       case 'n': return 200000L;  
// //       case 'p': return 300000L;  
// //       case 'q': return 400000L;  
// //       case 'r': return 500000L;  
// //       case 's': return 600000L;  
// //       case 't': return 700000L;  
// //       case 'u': return 800000L;  
// //       case 'v': return 900000L;  
// //       case 'w': return 1000000L; 
// //       case 'x': return 2000000L; 
// //       case 'y': return 4000000L; 

// // 	  default:
// //       case 'z': return 200000L; 	  
// //    }
// }

// void design_initShip()
// {
//    uint8_t y = 12;
//    uint8_t x = 50;
   
//    uint8_t tl_index;
//    uint8_t mission_index;
//    uint8_t config_index;
   
//    design_setSize( 'n' );

//    clrscr();

//    textcolor(COLOR_YELLOW);
//    tl_index      = picklist( 25, 14, "select tech level", techlevels, NUM_OF_TLS);
//    ship.tl = tl_index + 9;

//    common_clearMainArea();
//    mission_index = picklist( 25, 14, "select mission", missionTypes, NUM_OF_MISSIONS);
   
//    ship.mission[0] = missionTypes[ mission_index ].code[0];
//    ship.mission[1] = missionTypes[ mission_index ].code[1];

//    common_clearMainArea();
//    config_index    = picklist( 25, 14, "select configuration: ", configTypes, NUM_OF_CONFIGURATIONS);

//    ship.config = configTypes[ config_index ].code[0];

//    common_clearMainArea();
//    ship.computer = '1';
//    if (ship.tl > 'g') ship.computer = '9';
//    if (ship.tl > 'f') ship.computer = '8';
//    if (ship.tl > 'e') ship.computer = '7'; 
//    if (ship.tl > 'd') ship.computer = '6'; // up from 'c'
//    if (ship.tl > 'c') ship.computer = '5'; // up from 'b'
//    if (ship.tl > 'b') ship.computer = '4'; // up from 'a'
//    if (ship.tl > 'a') ship.computer = '3'; // up from '9'
//    if (ship.tl > '9') ship.computer = '2'; // up from nowhere

//    if (ship.tl == 'f') ship.armor = '9';
//    if (ship.tl == 'e') ship.armor = '8';
//    if (ship.tl == 'd') ship.armor = '7';
//    if (ship.tl == 'c') ship.armor = '6';
//    if (ship.tl == 'b') ship.armor = '5';
//    if (ship.tl == 'a') ship.armor = '4';
//    if (ship.tl == '9') ship.armor = '3';

//    ship.armor = '9'; // why not

//    ship.designList[INDEX_OF_MANEUVER].rating = prompt06(x, y+6, "please type the ship's maneuver rating [0-6]: ");
//    ship.designList[INDEX_OF_JUMP].rating     = prompt06(x, y+8, "please type the ship's jump rating [0-6]: ");
//    ship.power = ship.designList[INDEX_OF_MANEUVER].rating > ship.designList[INDEX_OF_JUMP].rating? 
// 			ship.designList[INDEX_OF_MANEUVER].rating 
// 			: ship.designList[INDEX_OF_JUMP].rating;
// }

void design_initShip()
{
	ship.armor = 1;
	ship.spine = 0;
	sprintf(spineContent, "spine %c", ehex[ ship.spine + 10 ]); // 0 = A
}

void design_pickSpine()
{
    textcolor(COLOR_YELLOW);
    menu_drawPanel( 0,  MENU_Y, 80, 5, "select spine letter [not i,o]", spineContent );

	ship.spine = cgetc();

	if (ship.spine < 'a' || ship.spine > 'z')
	   ship.spine = 'a';

	if (ship.spine > 'h') --ship.spine;
	if (ship.spine > 'n') --ship.spine;

    ship.spine -= 'a';

	sprintf(spineContent, "spine %c", ehex[ ship.spine + 10 ]);
}

void design_showScreen()
{
	textcolor(COMMON_COLOR);
//	cputsxy(0,0,"    A  B  C  D  E  F  G  H  J  K  L  M  N  P  Q  R  S  T  U  V  W  X  Y  Z");
	cputsxy(0,0,"                                                    s  t                  ");
	
    menu_drawPanel( 0,  MENU_Y, 80, 5, "s:spine", spineContent );

	menu_drawPanel( 29, 19+MENU_Y, 23, 23, "fitness", "");
	menu_drawIntersection( 40, 30+MENU_Y, 11, 11 );

    textcolor(COLOR_LIGHTRED);
	cputcxy( 40 + fitness / 16, 
	         30+ MENU_Y + fitness % 16, 
		     209); // 209 or 215 are the balls
}

void design_determineFitness()
{
    fitness = test_runTest(&ship);
}

// long getTonnageOf( int indexOfComponent )
// {
// 	int rating = ship.designList[ indexOfComponent ].rating;

// 	if (indexOfComponent == INDEX_OF_MANEUVER)
// 	{
// 		return 0; // percentage
// 	}
// 	else if (indexOfComponent == INDEX_OF_JUMP)
// 	{
// 		return 0; // percentage
// 	}

// 	if (rating > 9) // 4000 tons and up.
// 		return rating * 1000 - 6000; // A = 4,000t

//     // this is very very very very very sloppy
// 	switch(rating)
// 	{
// 		default:
// 		case 0: return 0;
// 		case 1: return 5;
// 		case 2: return 10;
// 		case 3: return 30;
// 		case 4: return 100;
// 		case 5: return 300;
// 		case 6: return 750;
// 		case 7: return 2250;
// 		case 8: return 7000;
// 		case 9: return 20000;
// 	}

// 	return 0;
// }

// void printIfWeHaveOne( FILE* fp, int indexOfComponent )
// {
//    if (ship.designList[ indexOfComponent ].rating == 0 
//     || ship.designList[ indexOfComponent ].rating > 9)
//       return;

//    // valid component
//    cprintf( "%10s-%c ", componentName[ indexOfComponent ], ehex[ ship.designList[ indexOfComponent ].rating ]);
//    fprintf( fp, "%10s-%c ", componentName[ indexOfComponent ], ehex[ ship.designList[ indexOfComponent ].rating ]);
// }

// void printIfWeHaveSpine( FILE* fp, int indexOfComponent )
// {
// 	if (ship.designList[ indexOfComponent ].rating < 10)
// 	   return;

// 	// valid spine
//    cprintf( "%10s-%c ", componentName[ indexOfComponent ], ehex[ ship.designList[ indexOfComponent ].rating ]);
//    fprintf( fp, "%10s-%c ", componentName[ indexOfComponent ], ehex[ ship.designList[ indexOfComponent ].rating ]);
// }

// void printCharacteristic( FILE *fp, char* label, unsigned value )
// {
//    cprintf( "\r\n   %s (%u). ", label, value);
//    fprintf( fp, "\n   %s (%u). ", label, value);
// }

// void design_dumpShipProfile()
// {
// 	char line[80];
// 	FILE *fp = fopen( "ship.txt", "w" );

// 	textcolor(COLOR_LIGHTBLUE);
// 	sprintf( line, "\r\n%s  %c%c-%c%c%d%d-%c.    %lu tons   tl-%d\r\n", 
// 			ship.name, 
// 			ship.mission[0], 
// 			ship.mission[1], 
// 			ship.sizeCode,
// 			ship.config,
// 			ship.designList[ INDEX_OF_MANEUVER ].rating,
// 			ship.designList[ INDEX_OF_JUMP ].rating,
// 			ship.armor,
// 			design_getTons(),
// 			ship.tl
// 			);
 
//     cprintf(line);
// 	fprintf(fp, line);

// 	printCharacteristic(fp, "ops", ship.ops);
// 	printIfWeHaveOne( fp, INDEX_OF_DATACASTER );
// 	printCharacteristic(fp, "sec", ship.sec);
// 	printIfWeHaveOne( fp, INDEX_OF_MISSILES );
// 	printIfWeHaveOne( fp, INDEX_OF_MESON );
// 	printIfWeHaveOne( fp, INDEX_OF_PA );
// 	printIfWeHaveOne( fp, INDEX_OF_INDUCER );
// 	printIfWeHaveOne( fp, INDEX_OF_TRACTOR );
// 	printIfWeHaveOne( fp, INDEX_OF_DISRUPTOR );
// 	printCharacteristic( fp, "def", ship.def);
// 	printIfWeHaveOne( fp, INDEX_OF_BEAMS );
// 	printIfWeHaveOne( fp, INDEX_OF_SAND );
// 	printIfWeHaveOne( fp, INDEX_OF_SCRAMBLERS );
// 	printIfWeHaveOne( fp, INDEX_OF_SCREENS );
// 	printIfWeHaveOne( fp, INDEX_OF_GLOBES );
// 	printCharacteristic( fp, "eng", ship.eng);
// 	printCharacteristic( fp, "car", ship.car);
// 	printIfWeHaveOne( fp, INDEX_OF_FIGHTERS );
// 	printCharacteristic( fp, "boa", ship.boa);
// 	printIfWeHaveOne( fp, INDEX_OF_MARINES );
// 	printIfWeHaveOne( fp, INDEX_OF_TROOPS );
// 	printCharacteristic( fp, "lin", ship.lin);
// 	printIfWeHaveSpine( fp, INDEX_OF_MESON );
// 	printIfWeHaveSpine( fp, INDEX_OF_PA );
// 	printIfWeHaveSpine( fp, INDEX_OF_MISSILES );
// 	printIfWeHaveSpine( fp, INDEX_OF_FIGHTERS );

//     fclose(fp);
// }

// int getPoints() 
// {
// 	long t = ship.tons;

// 	if (t>999999L) return 31;
// 	if (t>799999L) return 30;
// 	if (t>699999L) return 29;
// 	if (t>619999L) return 28;
// 	if (t>539999L) return 27;
// 	if (t>449999L) return 26;
// 	if (t>399999L) return 25;
// 	if (t>349999L) return 24;
// 	if (t>299999L) return 23;
// 	if (t>249999L) return 22;
// 	if (t>199999L) return 21;
// 	if (t>159999L) return 20;
// 	if (t>129999L) return 19;
// 	if (t>99999L) return 18;
// 	if (t>79999L) return 17;
// 	if (t>64999L) return 16;
// 	if (t>49999L) return 15;
// 	if (t>39999L) return 14;
// 	if (t>29999L) return 13;
// 	if (t>19999L) return 12;
// 	if (t>14999L) return 11;
// 	if (t>9999L) return 10;
// 	if (t>6499L) return 9;
// 	if (t>3999L) return 8;
// 	if (t>2399L) return 7;
// 	if (t>1199L) return 6;
// 	if (t>699L) return 5;
// 	if (t>299L) return 4;
// 	return 3;
// }

// void design_adjustShipPoints()
// {
// 	int points = getPoints();
// 	int avg    = points/7;
// 	int rad    = points%7; // how many get a +1 ?

// 	ship.ops = avg;
// 	ship.sec = avg;
// 	if (rad > 6) ++ship.sec;
// 	ship.def = avg;
// 	if (rad > 5) ++ship.def;
// 	ship.eng = avg;
// 	if (rad > 4) ++ship.eng;
// 	ship.car = avg;
// 	if (rad > 3) ++ship.car;
// 	ship.boa = avg;
// 	if (rad > 2) ++ship.boa;
// 	ship.lin = avg;
// 	if (rad > 1) ++ship.lin;

// }

// void adjustTonnage()
// {
// 	long payload = 0;
// 	unsigned percentage = 20; // bridge
//     uint8_t i;

//     //
//     // sum tonnage of components
// 	//
// 	for(i=0; i<COMPONENT_LIST_SIZE; ++i)
// 	   payload += getTonnageOf( i );

//     //
// 	// sum percentage of variable components
// 	//
// 	percentage +=   20 * ship.designList[ INDEX_OF_MANEUVER ].rating;
//     //cprintf("percentage = %u", percentage);

// 	percentage += 125 * ship.designList[ INDEX_OF_JUMP ].rating;
//     //cprintf(", %u", percentage);

// 	percentage += 25 * ship.power;
//     //cprintf(", %u", percentage);

// 	percentage =  (percentage * 112) / 100; // crew
//     //cprintf(", %u", percentage);

//     percentage = percentage / 10;
//     //cprintf(", %u", percentage);

//     //cgetc();
// 	//
// 	// ship.tons = payload / ( 1 - percentage )
// 	//
// 	ship.tons = payload * 100 / (100 - percentage);
  
//     design_adjustShipPoints();
// }

// void design_adjustSupportElements()
// {
// 	char c;
// 	int  item_index;

// 	gotoxy(0,5);
// 	cputs("                    adjust support elements:\r\n\r\n\r\n");
// 	cputs("                    (h) beams\r\n\r\n");
// 	cputs("                    (a) datacasters\r\n\r\n");
// 	cputs("                    (g) disruptors\r\n\r\n");
// 	cputs("                    (p) fighters\r\n\r\n");
// 	cputs("                    (l) globes\r\n\r\n");
// 	cputs("                    (o) hop\r\n\r\n");
// 	cputs("                    (e) inducer\r\n\r\n");
// 	cputs("                    (n) jump\r\n\r\n");
// 	cputs("                    (m) maneuver\r\n\r\n");
// 	cputs("                    (r) marines\r\n\r\n");
// 	cputs("                    (d) meson gun\r\n\r\n");
// 	cputs("                    (b) missiles\r\n\r\n");
// 	cputs("                    (c) particle accelerator\r\n\r\n");
// 	cputs("                    (i) sand\r\n\r\n");
// 	cputs("                    (j) screens\r\n\r\n");
// 	cputs("                    (k) scramblers\r\n\r\n");
// 	cputs("                    (f) tractor/pressors\r\n\r\n");
// 	cputs("                    (q) troops\r\n\r\n");

// 	//
// 	//  TODO!!!
// 	//
// 	//  Implement a "slider" for all of these:
// 	//  * use the cursor up/down keys to scroll to the component you want
// 	//  * use the cursor left/right keys to "SLIDE" the factor indicator up/down.
// 	//
// 	//  Have ball characters show the current values.
// 	//  Indicate the current ball value in the extreme right.

// 	//
// 	//  Maybe better than a bare slider against all these components
// 	//  is an item list and an item editor per component.
// 	//  Make it feel more interesting than a pile of switches.
// 	//

// 	while (!kbhit() );
// 	c = cgetc();

//     if (c > 192) // shift-letter
// 	{
//        item_index = c - 193;
// 	   ship.designList[ item_index ].rating--;
// 	}
// 	else
// 	{
//        item_index = c - 65;
// 	   ship.designList[ item_index ].rating++;
// 	}

// 	if (item_index == INDEX_OF_JUMP || item_index == INDEX_OF_MANEUVER)
// 	{
// 	   if (ship.designList[ item_index ].rating > 9)
// 	      ship.designList[ item_index ].rating = 0;
// 	   else if (ship.designList[ item_index ].rating < 0)
// 	      ship.designList[ item_index ].rating = 0;

// 	   if (ship.power < ship.designList[ item_index ].rating)
// 	      ship.power = ship.designList[ item_index ].rating;
// 	}
// 	else
// 	{
//        if (ship.designList[ item_index ].rating > 33)
// 	      ship.designList[ item_index ].rating = 0;
// 	   else if (ship.designList[ item_index ].rating < 0)
// 	      ship.designList[ item_index ].rating = 0;
// 	}

// 	adjustTonnage();
// }
