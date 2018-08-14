#ifndef POWER_ELECTRONICS_H

#define POWER_ELECTRONICS_H

#include "Arduino.h"

typedef enum {
	MOSFET_OFF = 0,
	MOSFET_ON
} PE_MosfetState_t;

class PowerElectronics {
	public:
		PowerElectronics(int pinMosfetGate, int pin12V, int pin5V);
		~PowerElectronics();
		void PE_setMosfetState(PE_MosfetState_t val);
		long PE_get12V();
		long PE_get5V();
	private:
		int _pinMosfetGate;
		int _pin12V;
		int _pin5V;
};

#endif
