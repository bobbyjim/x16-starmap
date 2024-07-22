#ifndef _common_h_
#define _common_h_


#define		COMMON_COLOR   	COLOR_GRAY3


void common_loadCharacterSet(char* name);       
void common_clearMainArea();
void common_redline();
void common_greenline();
void common_titleLine();
void common_statusLine();
void common_toDefaultColor();

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
