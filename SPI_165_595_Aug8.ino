#include <SPI.h>
/* Use pin9 to latch 165 data
use pin10 to latch 595 data
connect SCK (d13) to all clock lines
connect MISO (d12) to 165 data out
connect MOSI (d11) to 595 data in */
byte byte1 ;
byte byte2 ;
void setup(){
SPI.begin(); // default speed 4 MHz
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);}
void loop(){
digitalWrite (9, LOW);
digitalWrite (9, HIGH); // capture 165 inputs
byte1 = SPI.transfer(0); // read in 165 #2 data
byte2 = SPI.transfer(0); // read in 165 #1 data
SPI.transfer(byte1); // send data to 595 #1
SPI.transfer(byte2); // send data to 595 #2
digitalWrite (10, LOW);
delayMicroseconds(10);
digitalWrite (10, HIGH); // latch to output of 595s.
}