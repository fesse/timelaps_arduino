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

void Logic::run() {




	switch (state->getRunState()) {
		case State::STATE_RUNNING : {

			switch (logicState) {
				case LOGIC_MOVE_FORWARD : {
					if (!isTimeElapsed(state->getSpeed() * SPEED_FACTOR)) {
						return;
					}

					setTimeMarker();
					hardwareAdapter.motor(false);
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
					logicState = LOGIC_IDLE;
					return;
			}

			// Done ?
			if (state->getNbrOfPhotosTaken() == state->getTotalNbrOfPhotos()){
				state->stop();
				return;
			}

			// Wait time over ?
			if (!isTimeElapsed(state->getExposureWaitTime())) {
				return;
			}

			// Move forward
			setTimeMarker();
			hardwareAdapter.motor(true);
			logicState = LOGIC_MOVE_FORWARD;
			return;
		}

		case State::STATE_MOVETOSTARTPOSITION : {

		}
	}

	if (state->getRunState() == State::STATE_RUNNING) {

	}

	}


}

void Logic::setTimeMarker() {
	timeMarker = micros() / 1000;
}

bool Logic::isTimeElapsed(unsigned long time) {
	return micros()/1000 - timeMarker > time;
}
