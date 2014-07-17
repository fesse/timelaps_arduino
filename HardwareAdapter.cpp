/*
 * HardwareAdapter.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#include "HardwareAdapter.h"

HardwareAdapter::HardwareAdapter() {
	timeMarker1 = 0;
	timeMarker2 = 0;
	led1brightness = 255;
	led1fadeAmount = 5;
	led2brightness = 255;
	led2fadeAmount = 5;
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
	if (!hasTimeElapsed(1, 30)) {
		return;
	}
	setTimeMarker(1);
	if (led1brightness == 0 || led1brightness == 255) {
		led1fadeAmount = -led1fadeAmount;
	}
	led1brightness += led1fadeAmount;
	analogWrite(LED1, led1brightness);
}

void HardwareAdapter::led2blink() {
	if (!hasTimeElapsed(2, 10)) {
		return;
	}
	setTimeMarker(2);
	if (led2brightness == 0 || led2brightness == 255) {
		led2fadeAmount = -led2fadeAmount;
	}
	led2brightness += led2fadeAmount;
	analogWrite(LED2, led2brightness);
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

bool HardwareAdapter::atEndPosition() {
	return digitalRead(END_POSITION) == HIGH;
}

bool HardwareAdapter::emergencyStop() {
	return digitalRead(EMERGENCY_STOP) == LOW;
}

//long HardwareAdapter::getCurrentOutputState() {
//	return (PORTB & 0x39) << 8 | (PORTD & 0xE0); // 0011 1001 1110 0000
//}

void HardwareAdapter::setTimeMarker(int ledNumber) {
	if (ledNumber == 1) {
		timeMarker1 = micros() / 1000;
	} else if (ledNumber == 2) {
		timeMarker2 = micros() / 1000;
	}
}

bool HardwareAdapter::hasTimeElapsed(int ledNumber, unsigned long time) {
	if (ledNumber == 1) {
		return micros()/1000 - timeMarker1 > time;
	} else if (ledNumber == 2) {
		return micros()/1000 - timeMarker2 > time;
	}

	// Should never happen
	return true;
}

