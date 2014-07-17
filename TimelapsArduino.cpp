#include "TimelapsArduino.h"

State* state = NULL;
Menu* menu = NULL;

Logic* logic = NULL;
Debug debug;

void setup() {

	SerialAdapter::init();

	state = new State();
	menu = new Menu(state);
	menu->init();

	logic = new Logic(state);
	logic->init();

	debug.init();
}

void loop() {

	menu->parseInput();

	logic->run();

	debug.dumpState();
}
