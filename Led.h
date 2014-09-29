/*
 * HardwareAdapter.h
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#ifndef LED_H_
#define LED_H_

#include "Arduino.h"

class Led {
public:
	Led();
	void init(int ledNumber, int waitTimeMs);
	void blink();
	void on();
	void off();
	void update();

private:
	int pinNumber;
	unsigned long timeMarker;
	int fadeAmount;
	int brightness;
	int waitTime;
	bool isBlinking;
	bool longWait;

	void setTimeMarker();
	bool hasTimeElapsed(unsigned long time);
};

#endif /* LED_H_ */
