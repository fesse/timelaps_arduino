#include "TimelapsArduino.h"

State* state = NULL;
Menu* menu = NULL;

HardwareAdapter hardwareAdapter;
Debug debug;

void setup() {

	SerialAdapter::init();
	state = new State();
	menu = new Menu(state);
	menu->init();

	hardwareAdapter.init();

	debug.init();
}

long cnt = 0;
bool led1 = false;

void loop() {
	menu->parseInput();
	cnt++;
	if (cnt == 50000) {
		led1 = !led1;
		cnt = 0;
		hardwareAdapter.led1(led1);
	}

	debug.dumpState();
}

