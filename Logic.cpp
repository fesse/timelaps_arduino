/*
 * Logic.cpp
 *
 *  Created on: Jul 16, 2014
 *      Author: mathias
 */

#include <Logic.h>

Logic::Logic(State* currentState) {
	state = currentState;
	logicState = LOGIC_IDLE;
	timeMarker = 0;
}

void Logic::init() {
	hardwareAdapter.init();
	resetHardware();
	hardwareAdapter.led1blink();
}

void Logic::resetHardware() {
	hardwareAdapter.led1(false);
	hardwareAdapter.led2(false);
	hardwareAdapter.focus(false);
	hardwareAdapter.shutter(false);
	hardwareAdapter.motorDirection(state->getDirection());
	hardwareAdapter.motor(0);
}

void Logic::run() {

	hardwareAdapter.update();

	// Check emergency stop
	if (hardwareAdapter.emergencyStop()) {
		state->setRunState(State::STATE_STOP);
	}

	switch (state->getRunState()) {

		case State::STATE_IDLE : {
			return;
		}

		case State::STATE_START : {
			resetHardware();

			state->setNbrOfPhotosTaken(0);
			state->setRunState(State::STATE_RUNNING);
			logicState = LOGIC_IDLE;

			return;
		}

		case State::STATE_STOP : {
			resetHardware();
			state->setRunState(State::STATE_IDLE);
			hardwareAdapter.led1blink();
			logicState = LOGIC_IDLE;
			return;
		}


		case State::STATE_MOVE_TO_START_POSITION : {
			resetHardware();

			state->setRunState(State::STATE_MOVING_TO_START_POSITION);
			logicState = LOGIC_IDLE;

			return;
		}

		case State::STATE_RUNNING : {

			if (hardwareAdapter.atEndPosition()) {
				state->setRunState(State::STATE_STOP);
				return;
			}

			switch (logicState) {
				case LOGIC_MOVE_FORWARD : {

					if (!hasTimeElapsed(state->getSpeed() * SPEED_FACTOR)) {
						return;
					}

					setTimeMarker();
					hardwareAdapter.motor(0);
					hardwareAdapter.led2(false);
					logicState = LOGIC_TAKE_PHOTO;
					return;
				}

				case LOGIC_TAKE_PHOTO : {
					// Wait for trolley to settle
					if (!hasTimeElapsed(500)) {
						return;
					}

					setTimeMarker();
					hardwareAdapter.shutter(true);
					logicState = LOGIC_TAKING_PHOTO;
					return;
				}

				case LOGIC_TAKING_PHOTO : {
					if (!hasTimeElapsed(50)) {
						return;
					}

					setTimeMarker();
					hardwareAdapter.shutter(false);
					state->setNbrOfPhotosTaken(state->getNbrOfPhotosTaken()+1);
					logicState = LOGIC_WAITING;
					return;
				}

				case LOGIC_WAITING : {
					if (!hasTimeElapsed(state->getExposureWaitTime())) {
						return;
					}

					setTimeMarker();
					hardwareAdapter.motor(100);
					hardwareAdapter.led2(true);
					logicState = LOGIC_MOVE_FORWARD;

					// Done ?
					if (state->getNbrOfPhotosTaken() == state->getTotalNbrOfPhotos()){
						state->setRunState(State::STATE_STOP);
					}
					return;
				}

				case LOGIC_IDLE : {
					logicState = LOGIC_MOVE_FORWARD;
					return;
				}
			}

			return;
		}

		case State::STATE_MOVING_TO_START_POSITION : {


			switch(logicState) {

				case LOGIC_IDLE : {

					// Check so that we don't have a signal from an end relay
					if (hardwareAdapter.atEndPosition()) {
						state->setRunState(State::STATE_STOP);
						return;
					}

					// Move the opposite direction
					hardwareAdapter.led2blink();
					hardwareAdapter.motorDirection(!state->getDirection());
					hardwareAdapter.motor(255);

					logicState = LOGIC_MOVE_BACKWARD;
					return;
				}

				case LOGIC_MOVE_BACKWARD : {
					// Check so that we don't have a signal from an end relay
					if (!hardwareAdapter.atEndPosition()) {
						return;
					}

					hardwareAdapter.motor(0);
					setTimeMarker();
					logicState = LOGIC_WAITING;;
					return;
				}

				case LOGIC_WAITING : {
					if (!hasTimeElapsed(300)) {
						return;
					}

					// Move the opposite direction until we don't get the signal anymore
					hardwareAdapter.motorDirection(state->getDirection());
					hardwareAdapter.motor(100);
					logicState = LOGIC_MOVE_FORWARD;
					return;
				}

				case LOGIC_MOVE_FORWARD : {
					if (hardwareAdapter.atEndPosition()) {
						return;
					}
					state->setRunState(State::STATE_STOP);
					return;
				}
			}

			return;
		}
	}
}


void Logic::setTimeMarker() {
	timeMarker = micros() / 1000;
}

bool Logic::hasTimeElapsed(unsigned long time) {
	return micros()/1000 - timeMarker > time;
}
