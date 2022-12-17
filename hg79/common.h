#ifndef _common_h_
#define _common_h_

void logo(unsigned char x, unsigned char y);

void common_loadCharacterSet(char* name);       
void clearMainArea();
void redline();
void greenline();
void titleLine();
void statusLine();
void toDefaultColor();

typedef struct 
{
	char code[3];
	char label[27];
} PickList;

typedef struct
{
	long tons;
	char label[16];
} ComponentList;

#endif
