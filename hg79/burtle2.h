#ifndef __BURTLE2__
#define __BURTLE2__

typedef struct ranctx2 
{ 
	unsigned long a; 
	unsigned long b; 
	unsigned long c; 
	unsigned long d; 
} ranctx2;

void burtle2_srand(unsigned long seed);
unsigned long burtle2_rand();

#endif
