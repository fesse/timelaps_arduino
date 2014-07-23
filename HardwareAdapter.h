/*
 * HardwareAdapter.h
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#ifndef HARDWAREADAPTER_H_
#define HARDWAREADAPTER_H_

#include "Arduino.h"
#include "Led.h"

class HardwareAdapter {
public:
	HardwareAdapter();
	void init();
	void led1(bool on);
	void led1blink();
	void led2(bool on);
	void led2blink();
	void focus(bool on);
	void shutter(bool on);
	void motor(int speed);
	void motorDirection(bool left);

	bool atEndPosition();
	bool emergencyStop();

	void update();

//	long getCurrentOutputState();

private:

	static const int EMERGENCY_STOP = 4;  // Low active
	static const int END_POSITION = 10;

	static const int LED1 = 3;
	static const int LED2 = 9;
	static const int MOTOR_RUN = 5;

	static const int MOTOR_LEFT = 11;
	static const int MOTOR_RIGHT = 6;
	static const int FOCUS = 12;
	static const int SHUTTER = 13;

	Led myLed1;
	Led myLed2;


};

#endif /* HARDWAREADAPTER_H_ */
