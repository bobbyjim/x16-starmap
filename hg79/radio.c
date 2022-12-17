#include <conio.h>

#include "radio.h"

#define OPEN_CIRCLE   215
#define CLOSED_CIRCLE 209

//
//  returns selected INDEX
//
uint8_t radioButtons( uint8_t num, char* opts[])
{
	uint8_t i;
	uint8_t x = wherex();
	uint8_t y = wherey();

	for (i=0; i<num; ++i)
	{
		gotoxy( x, y + i*2 );
		cprintf("(%c) %-16s", i+65, opts[i]);
	}

	i=0;
	while(1)
	{
		int v = cgetc() - 65;
		if (v >= 0 && v < num) 
		   return (uint8_t) v;
	}
	return 0;
}

//
//  returns selected INDEX
//
uint8_t picklist( uint8_t x, uint8_t y, char* title, PickList selections[], uint8_t num_of_selections)
{
	uint8_t i;
	cputsxy(x,y,title);

    for (i=0; i<num_of_selections; ++i)
	{
		gotoxy( x, y + i * 2 + 2 );
		cprintf("(%c) %s", i+65, /*selections[i].code,*/ selections[i].label);
	}

	i=0;
	while(1)
	{
		int v = cgetc() - 65;
		if (v >= 0 && v < num_of_selections)
		   return (uint8_t) v;
	}
	return '0';
}