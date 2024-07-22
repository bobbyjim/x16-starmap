
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#include "cli.h"
#include "title.h"
#include "timer.h"
#include "bcs.h"

unsigned char indent = 4;
int ttySpeed = 3;

void tty(char* msg, unsigned char pause)
{
	gotox(indent);
	while(*msg)
	{
		cputc(*msg);
		++msg;
		pause_jiffies(ttySpeed);
		if (rand() < 10000)
		{
			ttySpeed = 1 + rand() % 5;
		}
	}
	cputs("\r\n\r\n");
	pause_jiffies(pause);
}

char *string_yesno[] = { "no", "yes" };

unsigned char getYN()
{
	unsigned char v = 0;
	char yn;
	
	while(1)
	{
		if (kbhit())
		{
			yn = cgetc();
			if (yn == 'y') { v = 1; break; }
			if (yn == 'n') break;
		}
	}
	cprintf("%s\r\n",string_yesno[v]);
	return v;
}

char menu()
{
	titleBlock();

	tty("realvilanic(tm) astrogation system 335-818r73",1);
	tty("reset system?",1);
    if (getYN()) 
	{
		pause_jiffies(50);
		tty("reset complete",50);
	}

	tty("use extended processes?",1);
    if (getYN())
	{
		pause_jiffies(50);
		tty("allocated",100);
	}	
    pause_jiffies(100);
	tty("initialization complete",100);   
	tty("connecting to sensors",100);
	tty("retrieving coordinates",100);
	
	tty("define bcs",100);
	if (getYN()) bcs_define();
//	tty(" 5 --- input destination coordinates" );
//	tty(" 6 --- enter interstellar density");
//	tty(" 7 --- enter jump entry window" );

	return '1';
}

void cli() 
{
	char c = menu();
}