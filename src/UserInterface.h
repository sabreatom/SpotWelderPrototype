#ifndef _USER_INTERFACE_H
#define _USER_INTERFACE_H

#include "Arduino.h"

//pedal states:
typedef enum {
	PEDAL_UNPRESSED = 0,
	PEDAL_PRESSED
} PedalState_t;

//User interface class:
class UserInterface {
	public:
		PedalState_t UI_getPedalState();
		int UI_getPulseWidthKnobValue();
		UserInterface(int pinPedal, int pinKnob);
		~UserInterface();
	private:
		int _pinPedal;
		int _pinKnob;
};

#endif
