/*
 * Debug.cpp
 *
 *  Created on: Jul 8, 2014
 *      Author: mathias
 */

#include <Debug.h>

Debug::Debug() {
	portb_state = 0;
	portd_state = 0;
}

Debug::~Debug() {
}

void Debug::init() {
	Serial.begin(9600);
	Serial.println("Timelaps Arduino debug console");
}

void Debug::dumpState() {
	if (PORTD != portd_state || (PORTB & 0x63) != portb_state) {
		portd_state = PORTD;
		portb_state = PORTB & 0x63;

		// Print state of all the digital pins
		Serial.print(((PORTB) >> (PORTD5)) & 0x01);
		Serial.print(((PORTB) >> (PORTD4)) & 0x01);
		Serial.print(' ');
		Serial.print(((PORTB) >> (PORTB3)) & 0x01);
		Serial.print(((PORTB) >> (PORTB2)) & 0x01);
		Serial.print(((PORTB) >> (PORTB1)) & 0x01);
		Serial.print(((PORTB) >> (PORTB0)) & 0x01);
		Serial.print(' ');
		Serial.print(((PORTD) >> (PORTD7)) & 0x01);
		Serial.print(((PORTD) >> (PORTD6)) & 0x01);
		Serial.print(((PORTD) >> (PORTD5)) & 0x01);
		Serial.print(((PORTD) >> (PORTD4)) & 0x01);
		Serial.print(' ');
		Serial.print(((PORTD) >> (PORTD3)) & 0x01);
		Serial.print(((PORTD) >> (PORTD2)) & 0x01);
		Serial.print(((PORTD) >> (PORTD1)) & 0x01);
		Serial.print(((PORTD) >> (PORTD0)) & 0x01);
		Serial.println();
	}

}
