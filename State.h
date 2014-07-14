/*
 * State.h
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#ifndef STATE_H_
#define STATE_H_

class State {
	bool led1;
	bool led2;

public:
	bool isEqual(State otherState);
	void toggleLed1(bool on);
	void toggleLed2(bool on);

	bool getLed1State();
	bool getLed2State();

	void updateFrom(State newState);
};

#endif /* STATE_H_ */
