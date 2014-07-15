/*
 * SerialAdapter.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: mathias
 */

#include <SerialAdapter.h>

namespace SerialAdapter {

	bool initialized = false;

	void init() {
		if (initialized) {
			return;
		}
		Serial.begin(9600);
		initialized = true;
	}
}
