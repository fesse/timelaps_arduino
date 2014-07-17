/*
 * HardwareAdapter.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#include "HardwareAdapter.h"

HardwareAdapter::HardwareAdapter() {
	timeMarker = 0;
	led1brightness = 255;
	led1fadeAmount = 5;
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
}

void HardwareAdapter::led1(bool on) {
	digitalWrite(LED1, on?HIGH:LOW);
}

void HardwareAdapter::led1blink() {
	if (!isTimeElapsed(30)) {
		return;
	}
	setTimeMarker();
	if (led1brightness == 0 || led1brightness == 255) {
		led1fadeAmount = -led1fadeAmount;
	}
	led1brightness += led1fadeAmount;
	analogWrite(LED1, led1brightness);
}

void HardwareAdapter::led2(bool on) {
	digitalWrite(LED2, on?HIGH:LOW);
}

void HardwareAdapter::focus(bool on) {
	digitalWrite(FOCUS, on?HIGH:LOW);
}

void HardwareAdapter::shutter(bool on) {
	digitalWrite(SHUTTER, on?HIGH:LOW);
}

void HardwareAdapter::motor(bool on) {
	digitalWrite(MOTOR_RUN, on?HIGH:LOW);
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

long HardwareAdapter::getCurrentOutputState() {
	return (PORTB & 0x39) << 8 | (PORTD & 0xE0); // 0011 1001 1110 0000
}

long HardwareAdapter::getCurrentInputState() {
	// TODO: implement
	return 0;
}

void HardwareAdapter::setTimeMarker() {
	timeMarker = micros() / 1000;
}

bool HardwareAdapter::isTimeElapsed(unsigned long time) {
	return micros()/1000 - timeMarker > time;
}
