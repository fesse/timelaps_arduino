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
	void moveToStartPosition();
	void start();
	void stop();
	int getRunState();

	int getNbrOfPhotosTaken();

	static const int LEFT = 0;
	static const int RIGHT = 1;

	static const int STATE_IDLE = 0;
	static const int STATE_MOVETOSTARTPOSITION = 1;
	static const int STATE_RUNNING = 2;

private:
	long totalNbrOfPhotos;
	long exposureWaitTime; // [ms]
	int speed; // [cm/h]
	int direction; // LEFT|RIGHT

	int runState;

	int nbrOfPhotosTaken;
};

#endif /* STATE_H_ */
