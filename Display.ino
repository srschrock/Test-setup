/*
   Controlling the 7segment Serial Display
   For counting test cycles
   SparkFun Electronics 7-Segment Serial Display
*/

#include <SoftwareSerial.h> //library for serial display control

// These are the Arduino pins required to create a software seiral
//  instance. We'll actually only use the TX pin.
const int softwareTx = 8; //the white wire on the serial display
const int softwareRx = 7; //no need to wire this one, just leave as is.

SoftwareSerial s7s(softwareRx, softwareTx);

unsigned int counter = 0;  // This variable will count up to 65k
char tempString[10];  // Will be used with sprintf to create strings


void displaysetup() {
  s7s.begin(9600); //initiate baud rate to match
  clearDisplay();  // Clears display, resets cursor
  s7s.print("-HI~");  // Show "HI" to verify proper startup
  setDecimals(0b111111);  // Turn on all decimals, colon, apos
  setBrightness(255);  // Highest brightness
  delay(50);

  // Clear the display before jumping into loop
  clearDisplay();
}

void displayloop() {
  // Magical sprintf creates a string for us to send to the s7s.
  //  The %4d option creates a 4-digit integer.
  sprintf(tempString, "%4d", counter);

  // This will output the tempString to the S7S
  s7s.print(tempString);
  setDecimals(0b00000100);  // Sets digit 3 decimal on

  counter++;  // Increment the counter
  delay(50);
}


void clearDisplay() {
  s7s.write(0x76);  // Clear display command
}

// Brightness: 0=dimmest, 255=brightest
void setBrightness(byte value) {
  s7s.write(0x7A);  // Set brightness command byte
  s7s.write(value);  // brightness data byte
}

// Turn on any, none, or all of the decimals.
//  The six lowest bits in the decimals parameter sets a decimal
//  (or colon, or apostrophe) on or off. A 1 indicates on, 0 off.
//  [MSB] (X)(X)(Apos)(Colon)(Digit 4)(Digit 3)(Digit2)(Digit1)
void setDecimals(byte decimals) {
  s7s.write(0x77);
  s7s.write(decimals);
}
