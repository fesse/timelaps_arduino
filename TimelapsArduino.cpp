// Do not remove the include below
#include "TimelapsArduino.h"


// BLINK
void blink_setup() {
	DDRB=0xFF; //all pins of PORTB declared as output
}

void blink_loop() {
	PORTB = 0xff;
	_delay_ms(100);
	PORTB = 0x00;
	_delay_ms(500);
}


int led = 13;

// Blink Arduino methods
void blink2_setup() {
	  pinMode(led, OUTPUT);
}

void blink2_loop() {
	  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
	  delay(500);               // wait for a second
	  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
	  delay(100);               // wait for a second
}

// Serial test

int thisByte = 33;

void serial_setup() {
	 //Initialize serial and wait for port to open:
	  Serial.begin(9600);
	  while (!Serial) {
	    ; // wait for serial port to connect. Needed for Leonardo only
	  }
	  Serial.println("ASCII Table ~ Character Map");
}

void serial_loop() {
	  // prints value unaltered, i.e. the raw binary version of the
	  // byte. The serial monitor interprets all bytes as
	  // ASCII, so 33, the first number,  will show up as '!'
	  Serial.write(thisByte);

	  Serial.print(", dec: ");
	  // prints value as string as an ASCII-encoded decimal (base 10).
	  // Decimal is the  default format for Serial.print() and Serial.println(),
	  // so no modifier is needed:
	  Serial.print(thisByte);
	  // But you can declare the modifier for decimal if you want to.
	  //this also works if you uncomment it:

	  // Serial.print(thisByte, DEC);


	  Serial.print(", hex: ");
	  // prints value as string in hexadecimal (base 16):
	  Serial.print(thisByte, HEX);

	  Serial.print(", oct: ");
	  // prints value as string in octal (base 8);
	  Serial.print(thisByte, OCT);

	  Serial.print(", bin: ");
	  // prints value as string in binary (base 2)
	  // also prints ending line break:
	  Serial.println(thisByte, BIN);

	  // if printed last visible character '~' or 126, stop:
	  if(thisByte == 126) {     // you could also use if (thisByte == '~') {
	    // This loop loops forever and does nothing
	    while(true) {
	      continue;
	    }
	  }
	  // go on to the next character
	  thisByte++;
}

void setup() {
//	blink_setup();
	blink2_setup();
	serial_setup();
}

void loop() {
//	blink_loop();
	blink2_loop();
	serial_loop();
}





