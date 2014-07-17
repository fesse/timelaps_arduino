/*
 * HardwareAdapter.h
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#ifndef HARDWAREADAPTER_H_
#define HARDWAREADAPTER_H_

#include "Arduino.h"

class HardwareAdapter {
public:
	HardwareAdapter();
	void init();
	void led1(bool on);
	void led1blink();
	void led2(bool on);
	void focus(bool on);
	void shutter(bool on);
	void motor(bool on);
	void motorDirection(bool left);

	long getCurrentOutputState();
	long getCurrentInputState();

private:

	static const int EMERGENCY_STOP = 4;  // Low active
	static const int END_POSITION = 10;

	static const int LED1 = 7;
	static const int LED2 = 8;
	static const int MOTOR_RUN = 5;

	static const int MOTOR_LEFT = 11;
	static const int MOTOR_RIGHT = 6;
	static const int FOCUS = 12;
	static const int SHUTTER = 13;

	unsigned long timeMarker;
	int led1fadeAmount;
	int led1brightness;

	void setTimeMarker();
	bool isTimeElapsed(unsigned long time);
};

#endif /* HARDWAREADAPTER_H_ */
