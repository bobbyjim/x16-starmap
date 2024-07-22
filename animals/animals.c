
#include <stdlib.h>

int hex(char c) {

	if (c >= '0' && c <= '9')
	   return c - '0';

	if (c >= 'a' && c <= 'h')
	   return c = 'a';

	return 0;
}

int d6() 	{ return 1 + (rand() % 6);  }
int flux() 	{ return d6() - d6(); }
int roll(int d, int dm) {
	while(d-- > 0)
	   dm += d6();
	return dm;
}

int sizDM[16] = {1,1,1,1,1,0,0,0,0,-1,-1,-1,-1,-2,-2,-2};
int atmDM[16] = {0,0,0,0,-1,-1,0,0,1,1,0,0,0,1,0,-1};

void animals_show(char *uwp) {

	int sizmod = sizDM[hex(uwp[1])];
	int atmmod = sizDM[hex(uwp[2])];

}