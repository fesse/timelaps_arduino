/*
 * HardwareAdapter.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#include "HardwareAdapter.h"


HardwareAdapter::HardwareAdapter() {
}

void HardwareAdapter::init() {
	// Inputs
	pinMode(EMERGENCY_STOP, INPUT);
	pinMode(END_POSITION, INPUT);

	// Outputs
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(FOCUS, OUTPUT);
	pinMode(SHUTTER, OUTPUT);
	pinMode(MOTOR_RUN, OUTPUT);
	pinMode(MOTOR_LEFT, OUTPUT);
	pinMode(MOTOR_RIGHT, OUTPUT);

	myLed1.init(LED1, 30);
	myLed2.init(LED2, 5);
}

void HardwareAdapter::led1(bool on) {
	if (on) {
		myLed1.on();
	} else {
		myLed1.off();
	}
}

void HardwareAdapter::led1blink() {
	myLed1.blink();
}

void HardwareAdapter::led2blink() {
	myLed2.blink();
}

void HardwareAdapter::led2(bool on) {
	if (on) {
		myLed2.on();
	} else {
		myLed2.off();
	}
}

void HardwareAdapter::focus(bool on) {
	digitalWrite(FOCUS, on?HIGH:LOW);
}

void HardwareAdapter::shutter(bool on) {
	digitalWrite(SHUTTER, on?HIGH:LOW);
}

void HardwareAdapter::motor(int speed) {
	analogWrite(MOTOR_RUN, speed);
}

void HardwareAdapter::motorDirection(bool left) {
	if (left) {
		digitalWrite(MOTOR_LEFT, HIGH);
		digitalWrite(MOTOR_RIGHT, LOW);
	} else {
		digitalWrite(MOTOR_LEFT, LOW);
		digitalWrite(MOTOR_RIGHT, HIGH);
	}
}

bool HardwareAdapter::atEndPosition() {
	return digitalRead(END_POSITION) == HIGH;
}

bool HardwareAdapter::emergencyStop() {
	return digitalRead(EMERGENCY_STOP) == LOW;
}

//long HardwareAdapter::getCurrentOutputState() {
//	return (PORTB & 0x39) << 8 | (PORTD & 0xE0); // 0011 1001 1110 0000
//}

void HardwareAdapter::update() {
	myLed1.update();
	myLed2.update();
}
