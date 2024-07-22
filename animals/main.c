

#include <stdio.h>
#include <conio.h>
#include <cbm.h>
#include <6502.h>

#include "title.h"
#include "animals.h"

void setCase() 
{
   cbm_k_bsout(CH_BLACK);
   cbm_k_bsout(0x01);  // #define TO_BACKGROUND	0x01
   clrscr();
   cbm_k_bsout(0x8E); // revert to primary case

}
void set_PET_font()
{
   struct regs fontregs;
   fontregs.a = 4; // PET-like
   fontregs.pc = 0xff62;
   _sys(&fontregs);
}

void main() {

	char uwp[10];

   setCase();
   set_PET_font();

   splash();

   for(;;) {

		printf("enter uwp: ");
		scanf("%s", uwp);
		animals_show( uwp );

   }
}