/*
 * Debug.h
 *
 *  Created on: Jul 8, 2014
 *      Author: mathias
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "HardwareSerial.h"
//#include <avr/io.h>
#include "Arduino.h"

class Debug {
public:
	Debug();
	virtual ~Debug();
	void dumpState();
	void init();
private:
	uint8_t portb_state;
	uint8_t portd_state;
};

#endif /* DEBUG_H_ */
