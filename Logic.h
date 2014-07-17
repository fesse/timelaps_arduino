/*
 * Logic.h
 *
 *  Created on: Jul 16, 2014
 *      Author: mathias
 */

#ifndef LOGIC_H_
#define LOGIC_H_

#include "State.h"
#include "HardwareAdapter.h"

class Logic {
public:
	Logic(State* currentState);
	void init();
	void run();
private:
	State* state;
	HardwareAdapter hardwareAdapter;
	unsigned long timeMarker;

	int logicState;

	bool hasTimeElapsed(unsigned long time);
	void setTimeMarker();
	void resetHardware();

	static const int LOGIC_IDLE = 0;
	static const int LOGIC_MOVE_FORWARD = 1;
	static const int LOGIC_TAKE_PHOTO = 2;
	static const int LOGIC_TAKING_PHOTO = 3;
	static const int LOGIC_WAITING = 4;
	static const int LOGIC_MOVE_BACKWARD = 5;

	static const int SPEED_FACTOR = 10; // cm/h -> time
};

#endif /* LOGIC_H_ */
