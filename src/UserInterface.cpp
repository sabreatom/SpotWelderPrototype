#include "UserInterface.h"


//----------------------------------------
//User interface constructor:
//----------------------------------------

UserInterface::UserInterface(int pinPedal, int pinKnob)
{
	_pinPedal = pinPedal;
	_pinKnob = pinKnob;

	pinMode(_pinPedal, INPUT);
}

//----------------------------------------
//User interface destructor:
//----------------------------------------

UserInterface::~UserInterface(void)
{

}

//----------------------------------------
//Get current pedal state:
//----------------------------------------

PedalState_t UserInterface::UI_getPedalState()
{
	if (digitalRead(_pinPedal) == LOW) { //pedal is active low
		return PEDAL_PRESSED;
	}
	else {
		return PEDAL_UNPRESSED;
	}
}

//----------------------------------------
//Get pulse width knob current value:
//----------------------------------------

int UI_getPulseWidthKnobValue()
{
	return analogRead(_pinKnob);
}

//----------------------------------------
