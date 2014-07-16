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

long cnt = 0;
bool led1 = false;

void loop() {

	menu->parseInput();

	logic->run();

	debug.dumpState();
}



