#ifndef _RADIO_H_
#define _RADIO_H_

#include <stdint.h>
#include "common.h"

uint8_t radioButtons(uint8_t count, char* opts[]);
uint8_t picklist( uint8_t x, uint8_t y, char* title, PickList selections[], uint8_t num_of_selections);

#endif
