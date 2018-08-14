#include "PowerElectronics.h"

//------------------------------------------
//Constructore:
//------------------------------------------

PowerElectronics::PowerElectronics(int pinMosfetGate, int pin12V, int pin5V)
{
	_pinMosfetGate = pinMosfetGate;
	_pin12V = pin12V;
	_pin5V = pin5V;
	
	pinMode(_pinMosfetGate, OUTPUT);
	digitalWrite(_pinMosfetGate, LOW); //default state MosFet is off
}

//------------------------------------------
//Destructore:
//------------------------------------------

PowerElectronics::~PowerElectronics()
{

}

//------------------------------------------
//Set MosFet transistor state:
//------------------------------------------

PowerElectronics::void PE_setMosfetState(PE_MosfetState_t val)
{
	if (val == MOSFET_ON) {
		digitalWrite(_pinMosfetGate, HIGH);
	}
	else {
		digitalWrite(_pinMosfetGate, LOW);
	}
}

//------------------------------------------
//Get 12V MosFet gate driver voltage:
//------------------------------------------

PowerElectronics::long PE_get12V()
{
	long _tmp;

	_tmp = analogRead(_pin12V);
	_tmp = 5000 * _tmp / 1023; mV

	return _tmp;
}

//------------------------------------------
//Get 5V welding voltage:
//------------------------------------------

PowerElectronics::long PE_get5V()
{
	long _tmp;

        _tmp = analogRead(_pin5V);
        _tmp = 5000 * _tmp / 1023; mV

        return _tmp;
}

//------------------------------------------
