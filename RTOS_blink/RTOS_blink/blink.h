// blink.h

#ifndef _BLINK_h
#define _BLINK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
void blink(void);
void blink_task(void *pvParameter);

#endif

