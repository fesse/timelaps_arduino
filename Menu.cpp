/*
 * Menu.cpp
 *
 *  Created on: Jul 14, 2014
 *      Author: mathias
 */

#include <Menu.h>

Menu::Menu(State* currentState) {
	state = currentState;
	currentMenuChoice = MENU_NONE;
}

void Menu::init() {
	SerialAdapter::init();
	printMenu();
}

void Menu::printMenu() {
	Serial.println("Time laps - menu");
	Serial.println("0. Print menu");
	Serial.println("1. Set number of photos");
	Serial.println("2. Set exposure wait time");
	Serial.println("3. Set speed");
	Serial.println("4. Set trolley direction");
	Serial.println("5. Move trolley to start position");
	Serial.println("6. Start");
	Serial.println("7. Stop");
	Serial.println("9. Print status");
}

bool Menu::hasInput() {
	return Serial.available();
}

void Menu::parseInput() {
	if (!hasInput()) {
		return;
	}
	String data = Serial.readString();
	if (currentMenuChoice != MENU_NONE) {
		handleSubInput(data);
		return;
	}
	switch (data.toInt()) {
		case 0:
			printMenu();
			break;
		case MENU_SET_NBR_PHOTOS:
			Serial.println("Enter number of photos");
			currentMenuChoice = MENU_SET_NBR_PHOTOS;
			break;
		case MENU_SET_EXPOSURE_TIME:
			Serial.println("Enter wait time per photo [ms]");
			currentMenuChoice = MENU_SET_EXPOSURE_TIME;
			break;
		case MENU_SET_SPEED:
			Serial.println("Enter trolley speed [cm/h]");
			currentMenuChoice = MENU_SET_SPEED;
			break;
		case MENU_SET_DIRECTION:
			Serial.println("Enter trolley direction [L/R]");
			currentMenuChoice = MENU_SET_DIRECTION;
			break;
		case 5:
			resetTrolley();
			break;
		case 6:
			start();
			break;
		case 7:
			stop();
			break;
		case 9:
			printStatus();
			break;
		default:
			printMenu();
			break;
	}
}

void Menu::handleSubInput(String data){
	switch(currentMenuChoice) {
		case MENU_SET_NBR_PHOTOS:
			setNbrPhotos(data);
			break;
		case MENU_SET_EXPOSURE_TIME:
			setExposureWaitTime(data);
			break;
		case MENU_SET_SPEED:
			setSpeed(data);
			break;
		case MENU_SET_DIRECTION:
			setDirection(data);
			break;
	}
	currentMenuChoice = MENU_NONE;
}

void Menu::setNbrPhotos(String data) {
	state->setTotalNbrOfPhotos(data.toInt());
}

void Menu::setExposureWaitTime(String data) {
	state->setExposureWaitTime(data.toInt());
}

void Menu::setSpeed(String data) {
	state->setSpeed(data.toInt());
}

void Menu::setDirection(String data) {
	data = data.substring(0,1);
	if (data.equalsIgnoreCase("L")) {
		state->setDirection(State::LEFT);
	} else if (data.equalsIgnoreCase("R")) {
		state->setDirection(State::RIGHT);
	}
}

void Menu::resetTrolley() {
	state->setRunState(State::STATE_MOVE_TO_START_POSITION);
}

void Menu::start() {
	state->setRunState(State::STATE_START);
}

void Menu::stop() {
	state->setRunState(State::STATE_STOP);
}

void Menu::printStatus() {
	Serial.println("Current state");
	Serial.println("-------------");
	Serial.print("Total nbr of photos: ");
	Serial.println(state->getTotalNbrOfPhotos());
	Serial.print("Exposure wait time: ");
	Serial.print(state->getExposureWaitTime());
	Serial.println(" [ms]");
	Serial.print("Trolley speed: ");
	Serial.print(state->getSpeed());
	Serial.println(" [cm/h]");
	Serial.print("Trolley direction: ");
	Serial.println(state->getDirection() == State::LEFT ? "Left":"Right");
	Serial.print("Run state: ");
	Serial.println(state->getRunState());
	Serial.print("Nbr of photos taken: ");
	Serial.println(state->getNbrOfPhotosTaken());
}
