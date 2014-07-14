/*
 * State.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */
#include "State.h"

State::State(){
	totalNbrOfPhotos = 0;
	exposureWaitTime = 0;
	speed = 0;
	direction = LEFT;

	runState = STATE_IDLE;
}

void State::setTotalNbrOfPhotos(long nbrOfPhotos) {
	totalNbrOfPhotos = nbrOfPhotos;
}

int State::getTotalNbrOfPhotos() {
	return totalNbrOfPhotos;
}

void State::setExposureWaitTime(long waitTime) {
	exposureWaitTime = waitTime;
}

long State::getExposureWaitTime() {
	return exposureWaitTime;
}

void State::setSpeed(int trolleySpeed) {
	speed = trolleySpeed;
}

int State::getSpeed() {
	return speed;
}

void State::setDirection(int newDirection) {
	direction = newDirection;
}

int State::getDirection() {
	return direction;
}

void State::moveToStartPosition() {
	runState = STATE_MOVETOSTARTPOSITION;
}

void State::start() {
	runState = STATE_RUNNING;
}

void State::stop() {
	runState = STATE_IDLE;
}

int State::getRunState() {
	return runState;
}
