// Only modify this file to include
// - function definitions (prototypes)
// - include files
// - extern variable definitions
// In the appropriate section

#ifndef TimelapsArduino_H_
#define TimelapsArduino_H_
//add your includes for the project TimelapsArduino here

#include <avr/io.h>
#include <util/delay.h>

#include "HardwareSerial.h"
#include "Arduino.h"

#include "Debug.h"
#include "Menu.h"
#include "State.h"
#include "HardwareAdapter.h"
#include "SerialAdapter.h"

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif

//add your function definitions for the project TimelapsArduino here




//Do not add code below this line
#endif /* TimelapsArduino_H_ */
