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

void debug_setup() {
	  Serial.begin(9600);
	  Serial.println("Debug Arduino");
	  pinMode(13, OUTPUT);
	  pinMode(8, OUTPUT);
	  pinMode(7, OUTPUT);
}

long cnt = 0;
bool d13on = false;
bool d8on = true;
bool d7on = false;

uint8_t portb_state = 0;
uint8_t portd_state = 0;

void debug_loop() {
	cnt++;
	if (cnt == 500000) {
		cnt = 0;
		digitalWrite(13, d13on?LOW:HIGH);
		digitalWrite(8, d8on?LOW:HIGH);
		digitalWrite(7, d7on?LOW:HIGH);
		d13on = !d13on;
		d8on = !d8on;
		d7on = !d7on;
	}

	if (PORTD != portd_state || (PORTB & 0x63) != portb_state) {
		portd_state = PORTD;
		portb_state = PORTB & 0x63;

		// Print state of all the digital pins
		Serial.print(((PORTB) >> (PORTD5)) & 0x01);
		Serial.print(((PORTB) >> (PORTD4)) & 0x01);
		Serial.print(' ');
		Serial.print(((PORTB) >> (PORTB3)) & 0x01);
		Serial.print(((PORTB) >> (PORTB2)) & 0x01);
		Serial.print(((PORTB) >> (PORTB1)) & 0x01);
		Serial.print(((PORTB) >> (PORTB0)) & 0x01);
		Serial.print(' ');
		Serial.print(((PORTD) >> (PORTD7)) & 0x01);
		Serial.print(((PORTD) >> (PORTD6)) & 0x01);
		Serial.print(((PORTD) >> (PORTD5)) & 0x01);
		Serial.print(((PORTD) >> (PORTD4)) & 0x01);
		Serial.print(' ');
		Serial.print(((PORTD) >> (PORTD3)) & 0x01);
		Serial.print(((PORTD) >> (PORTD2)) & 0x01);
		Serial.print(((PORTD) >> (PORTD1)) & 0x01);
		Serial.print(((PORTD) >> (PORTD0)) & 0x01);
		Serial.println();
	}




}

void setup() {
//	blink_setup();
//	blink2_setup();
//	serial_setup();
	debug_setup();
}

void loop() {
//	blink_loop();
//	blink2_loop();
//	serial_loop();
	debug_loop();
}





