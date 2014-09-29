/*
 * State.cpp
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */
#include "State.h"

State::State(){
	totalNbrOfPhotos = 1000;
	exposureWaitTime = 1000;
	motorRunTime = 100;
	direction = LEFT;

	runState = STATE_IDLE;

	nbrOfPhotosTaken = 0;
}

void State::setTotalNbrOfPhotos(long nbrOfPhotos) {
	totalNbrOfPhotos = nbrOfPhotos;
}

long State::getTotalNbrOfPhotos() {
	return totalNbrOfPhotos;
}

void State::setExposureWaitTime(long waitTime) {
	exposureWaitTime = waitTime;
}

long State::getExposureWaitTime() {
	return exposureWaitTime;
}

void State::setMotorRunTime(long motorRunTime) {
	this->motorRunTime = motorRunTime;
}

long State::getMotorRunTime() {
	return motorRunTime;
}

void State::setDirection(int newDirection) {
	direction = newDirection;
}

int State::getDirection() {
	return direction;
}

int State::getRunState() {
	return runState;
}

void State::setRunState(int newRunState) {
	runState = newRunState;
}

long State::getNbrOfPhotosTaken() {
	return nbrOfPhotosTaken;
}

void State::setNbrOfPhotosTaken(int nbr) {
	nbrOfPhotosTaken = nbr;
}
