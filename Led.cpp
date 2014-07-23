/*
 * Led.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#include "Led.h"

Led::Led() {
	pinNumber = -1;
	waitTime = 30;
	timeMarker = 0;
	brightness = 255;
	fadeAmount = 5;
	isBlinking = false;
}

void Led::init(int ledNumber, int waitTimeMs){
	pinNumber = ledNumber;
	waitTime = waitTimeMs;
}
void Led::on() {
	isBlinking = false;
	digitalWrite(pinNumber, HIGH);
}

void Led::off() {
	isBlinking = false;
	digitalWrite(pinNumber, LOW);
}

void Led::blink() {
	isBlinking = true;
}

void Led::setTimeMarker() {
	timeMarker = micros() / 1000;
}

bool Led::hasTimeElapsed(unsigned long time) {
	return micros()/1000 - timeMarker > time;
}

void Led::update() {
	if (!isBlinking) {
		return;
	}

	if (!hasTimeElapsed(waitTime)) {
		return;
	}
	setTimeMarker();
	if (brightness == 0 || brightness == 255) {
		fadeAmount = -fadeAmount;
	}
	brightness += fadeAmount;
	analogWrite(pinNumber, brightness);

}

