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
}

void Logic::resetHardware() {
	hardwareAdapter.led1(false);
	hardwareAdapter.led2(false);
	hardwareAdapter.focus(false);
	hardwareAdapter.shutter(false);
	hardwareAdapter.motorDirection(state->getDirection()==State::LEFT);
	hardwareAdapter.motor(false);
}

void Logic::run() {

	switch (state->getRunState()) {

		case State::STATE_START : {
			resetHardware();
			state->setNbrOfPhotosTaken(0);
			state->setRunState(State::STATE_RUNNING);
			return;
		}

		case State::STATE_STOP : {
			resetHardware();
			hardwareAdapter.led1(true);
			state->setRunState(State::STATE_IDLE);
			return;
		}


		case State::STATE_RUNNING : {

			switch (logicState) {
				case LOGIC_MOVE_FORWARD : {
					if (!isTimeElapsed(state->getSpeed() * SPEED_FACTOR)) {
						return;
					}

					setTimeMarker();
					hardwareAdapter.motor(false);
					hardwareAdapter.led2(false);
					logicState = LOGIC_TAKE_PHOTO;
					return;
				}

				case LOGIC_TAKE_PHOTO : {
					// Wait for trolley to settle
					if (!isTimeElapsed(50)) {
						return;
					}

					setTimeMarker();
					hardwareAdapter.shutter(true);
					logicState = LOGIC_TAKING_PHOTO;
					return;
				}

				case LOGIC_TAKING_PHOTO : {
					if (!isTimeElapsed(50)) {
						return;
					}

					setTimeMarker();
					hardwareAdapter.shutter(false);
					state->setNbrOfPhotosTaken(state->getNbrOfPhotosTaken()+1);
					logicState = LOGIC_IDLE;
					return;
				}
			}

			// Done ?
			if (state->getNbrOfPhotosTaken() == state->getTotalNbrOfPhotos()){
				state->setRunState(State::STATE_STOP);
				return;
			}

			// Wait time over ?
			if (!isTimeElapsed(state->getExposureWaitTime())) {
				return;
			}

			// Move forward
			setTimeMarker();
			hardwareAdapter.motor(true);
			hardwareAdapter.led2(true);
			logicState = LOGIC_MOVE_FORWARD;
			return;
		}

		case State::STATE_MOVE_TO_START_POSITION : {

			return;
		}

		case State::STATE_IDLE : {
			hardwareAdapter.led1(true);
			return;
		}
	}
}

void Logic::setTimeMarker() {
	timeMarker = micros() / 1000;
}

bool Logic::isTimeElapsed(unsigned long time) {
	return micros()/1000 - timeMarker > time;
}
