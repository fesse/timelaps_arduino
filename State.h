/*
 * State.h
 *
 *  Created on: Jul 1, 2014
 *      Author: mathias
 */

#ifndef STATE_H_
#define STATE_H_

class State {
public:
	State();
	void setTotalNbrOfPhotos(long nbrOfPhotos);
	int getTotalNbrOfPhotos();
	void setExposureWaitTime(long waitTime);
	long getExposureWaitTime();
	void setSpeed(int trolleySpeed);
	int getSpeed();
	void setDirection(int newDirection);
	int getDirection();

	int getRunState();
	void setRunState(int runState);

	void setNbrOfPhotosTaken(int nbr);
	int getNbrOfPhotosTaken();


	static const int RIGHT = 0;
	static const int LEFT = 1;

	static const int STATE_IDLE = 0;
	static const int STATE_MOVE_TO_START_POSITION = 1;
	static const int STATE_MOVING_TO_START_POSITION = 2;
	static const int STATE_START = 3;
	static const int STATE_RUNNING = 4;
	static const int STATE_STOP = 5;

private:
	long totalNbrOfPhotos;
	long exposureWaitTime; // [ms]
	int speed; // [cm/h]
	int direction; // LEFT|RIGHT

	int runState;

	int nbrOfPhotosTaken;
};

#endif /* STATE_H_ */
