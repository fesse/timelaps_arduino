/*
 * Menu.h
 *
 *  Created on: Jul 14, 2014
 *      Author: mathias
 */

#ifndef MENU_H_
#define MENU_H_

#include "HardwareSerial.h"
#include "Arduino.h"
#include <State.h>

class Menu {
public:
	Menu(State* state);
	void init();
	bool hasInput();
	void parseInput();
private:
	void printMenu();
	void setNbrPhotos(String data);
	void setExposureWaitTime(String data);
	void setSpeed(String data);
	void setDirection(String data);
	void resetTrolley();
	void printStatus();
	void start();
	void stop();
	void handleSubInput(String data);

	State* state;
	int currentMenuChoice;

	static const int MENU_NONE = -1;
	static const int MENU_SET_NBR_PHOTOS = 1;
	static const int MENU_SET_EXPOSURE_TIME = 2;
	static const int MENU_SET_SPEED = 3;
	static const int MENU_SET_DIRECTION = 4;
};

#endif /* MENU_H_ */