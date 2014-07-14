/*
 * State.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */
#include "State.h"

void State::toggleLed1(bool on) {
	led1 = on;
}

void State::toggleLed2(bool on) {
	led2 = on;
}

bool State::isEqual(State otherState) {
	if (led1 != otherState.led1) {
		return false;
	}
	if (led2 != otherState.led2) {
		return false;
	}

	return true;
}


void State::updateFrom(State otherState) {
	led1 = otherState.getLed1State();
	led2 = otherState.getLed2State();
}

bool State::getLed1State() {
	return led1;
}

bool State::getLed2State() {
	return led2;
}
