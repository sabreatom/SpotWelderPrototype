#include "Arduino.h"
#include "PowerElectronics.h"
#include "UserInterface.h"
#include "hw_config.h"

PowerElectronics power_electronics(MOSFET_PIN, 12V_ADC_PIN, 5V_ADC_PIN);

UserInterface user_interface(PEDAL_PIN, KNOB_ADC_PIN);

void setup() {
	Serial.begin(115200); //init serial interface
	Serial.write("Initialization done.");
}

void loop() {
	int _pwm_width = 0;
	PedalState_t _prev_pedal_state = PEDAL_UNPRESSED;
	PedalState_t _pedal_state;

	//get pulse width knob value:
	_pwm_width = user_interface.UI_getPulseWidthKnobValue();

	//check for pedal:
	_pedal_state = user_interface.UI_getPedalState();

	if (_pedal_state == PEDAL_PRESSED) &&
	(_prev_pedal_state == PEDAL_UNPRESSED) {
		power_electronics.PE_setMosfetState(MOSFET_ON);
		delay(100);
		power_electronics.PE_setMosfetState(MOSFET_OFF);
	}

	_prev_pedal_state = _pedal_state;

	delay(500);
}
