
// #include <TM1638plus.h>

  
int d4096 = 0;
int d256 = 0;
int d16 = 0;
int d0  = 0;

/*
// GPIO I/O pins on the Arduino connected to strobe, clock, data,
//pick on any I/O you want.
#define  STROBE_TM 27 // strobe = GPIO connected to strobe line of module
#define  CLOCK_TM 28  // clock = GPIO connected to clock line of module
#define  DIO_TM 29 // data = GPIO connected to data line of module
bool high_freq = false; //default false,, If using a high freq CPU > ~100 MHZ set to true.

//Constructor object (GPIO STB , GPIO CLOCK , GPIO DIO, use high freq MCU)
TM1638plus tm(STROBE_TM, CLOCK_TM , DIO_TM, high_freq);
int i= 0;


int digit0 = 0;
int digit1 = 0;
int digit2 = 0;
int digit3 = 0;


// Some vars and defines for the tests.
#define myTestDelay 100

void Test0()
{
  // Test 0 reset test
  tm.setLED(0, 1);
  delay(myTestDelay);
  tm.reset();
}


void DisplayHexAddress() {
   tm.brightness(7);
  


  d4096 = i/4096;
  d256 =  (i-(4096 *d4096))/256;
  d16  =  (i-((4096 *d4096)+(256*d256)))/16;
  d0   =  i-(((4096 *d4096)+(256*d256)+(16*d16)));


  tm.displayHex(0, d4096);
  tm.displayHex(1, d256);
  tm.displayHex(2, d16);
  tm.displayHex(3, d0);

 
  delay(100);
 

  i++;

}

/*

void Test13()
{
  //Test 13 LED display
  uint8_t LEDposition = 0;

  // Test 13A Turn on redleds one by one, left to right, with setLED where 0 is L1 and 7 is L8 (L8 RHS of display)
  for (LEDposition = 0; LEDposition < 8; LEDposition++) {
    tm.setLED(LEDposition, 1);
    delay(500);
    tm.setLED(LEDposition, 0);
  }

  // TEST 13b test setLEDs function (0xLEDXX) ( L8-L1 , XX )
  // NOTE passed L8-L1 and on display L8 is on right hand side. i.e. 0x01 turns on L1. LXXX XXXX
  // For model 1 just use upper byte , lower byte is is used by model3 for bi-color leds leave at 0x00 for model 1.
  tm.setLEDs(0xFF00); //  all LEDs on
  delay(myTestDelay3);
   tm.setLEDs(0x0100); // Displays as LXXX XXXX (L1-L8) , NOTE on display L8 is on right hand side.
  delay(myTestDelay3);
  tm.setLEDs(0xF000); //  Displays as XXXX LLLL (L1-L8) , NOTE on display L8 is on right hand side.
  delay(myTestDelay3);
  tm.setLEDs(0x0000); // all off
  delay(myTestDelay3);

}


  //Test 14 buttons and LED test, press switch number S-X to turn on LED-X, where x is 1-8.
  //The HEx value of switch is also sent to Serial port.
  tm.displayText("buttons ");
  delay(myTestDelay3);
  

  void Buttons() {
  while (1) // Loop here forever
  {
    uint8_t buttons = tm.readButtons();
       buttons contains a byte with values of button s8s7s6s5s4s3s2s1
       HEX  :  Switch no : Binary
       0x01 : S1 Pressed  0000 0001
       0x02 : S2 Pressed  0000 0010
       0x04 : S3 Pressed  0000 0100
       0x08 : S4 Pressed  0000 1000
       0x10 : S5 Pressed  0001 0000
       0x20 : S6 Pressed  0010 0000
       0x40 : S7 Pressed  0100 0000
       0x80 : S8 Pressed  1000 0000
      
    Serial.println(buttons, HEX);
    doLEDs(buttons);
    tm.displayIntNum(buttons, true, TMAlignTextLeft);
    delay(250);
  }
}

// scans the individual bits of value sets a LED based on which button pressed
void doLEDs(uint8_t value) {
  for (uint8_t LEDposition = 0; LEDposition < 8; LEDposition++) {
    tm.setLED(LEDposition, value & 1);
    value = value >> 1;
  }
}

*/


  int ROM_address = 0;

  int RM15 = 0;
  int RM14 = 0;
  int RM13 = 0;
  int RM12 = 0;
  int RM11 = 0;
  int RM10 = 0;
  int RM9 = 0;
  int RM8 = 0;
  int RM7 = 0;
  int RM6 = 0;
  int RM5 = 0;
  int RM4 = 0;
  int RM3 = 0;
  int RM2 = 0;
  int RM1 = 0;
  int RM0 = 0;



void setup() {

Serial.begin(115200);

  // initialize digital pins 15:0 as input 
  pinMode(0, INPUT);
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  pinMode(14, INPUT);
  pinMode(15, INPUT);

   
  // Test 0 reset
  // Test0();


}

// the loop function runs over and over again forever
void loop() {

    RM15 = digitalRead(0);
    RM14 = digitalRead(1);
    RM13 = digitalRead(2);
    RM12 = digitalRead(3);
    RM11 = digitalRead(3);
    RM10 = digitalRead(5);
    RM9 = digitalRead(6);
    RM8 = digitalRead(7);
    RM7 = digitalRead(8);
    RM6 = digitalRead(9);
    RM5 = digitalRead(10);
    RM4 = digitalRead(11);
    RM3 = digitalRead(12);
    RM2 = digitalRead(13);
    RM1 = digitalRead(14);
    RM0 = digitalRead(15);
  ROM_address = ((32768 * RM15)+(16384 * RM14)+(8192 * RM13)+(4096 * RM12)+(2048 * RM11)+(1024 * RM10)+(512 * RM9)+(256 * RM8)+(128 * RM7)+(64 * RM6)+(32* RM5)+(16 * RM4)+(8 * RM3)+(4 * RM2)+(2 * RM1)+(1 * RM0)); 
    ;
    Serial.print(millis());
    Serial.print("   ");
    Serial.println(ROM_address); 


/*
  tm.brightness(7);
  i = ROM_address;


  d4096 = i/4096;
  d256 =  (i-(4096 *d4096))/256;
  d16  =  (i-((4096 *d4096)+(256*d256)))/16;
  d0   =  i-(((4096 *d4096)+(256*d256)+(16*d16)));

  tm.displayHex(0, d4096);
  tm.displayHex(1, d256);
  tm.displayHex(2, d16);
  tm.displayHex(3, d0);

  */


  delay(100);
}
