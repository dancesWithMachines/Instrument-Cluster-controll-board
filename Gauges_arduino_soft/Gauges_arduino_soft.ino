//----------------------------------------------------------------------
// https://github.com/clearwater/SwitecX25
// 
// This is an example of using the SwitchX25 library.
// It zero's the motor, sets the position to mid-range
// and waits for serial input to indicate new motor positions.
// 
// Open the serial monitor and try entering values 
// between 0 and 944.
// 
// Note that the maximum speed of the motor will be determined
// by how frequently you call update().  If you put a big slow
// serial.println() call in the loop below, the motor will move
// very slowly!
//----------------------------------------------------------------------

#include <SwitecX25.h>

// standard X25.168 range 315 degrees at 1/3 degree steps
#define STEPS (315*3) //Range of motors

// Four motors with corresponging pins
SwitecX25 rpm(STEPS,5,4,3,2); 
SwitecX25 speedo(STEPS,9,8,7,6);
SwitecX25 temp(STEPS,A0,A1,A2,A3); //Using analog pins as digital
SwitecX25 fuel(STEPS,11,12,10,13); 

//Multpiers for gauges
const float rpmMultiplier = 0.135;
const float speedoMultiplier = 2.8125;
const float fuelMultiplier = 2.7;
const float tempMultiplier = 2.25;

void setup(void)
{
  // runs the motors against the stops
  rpm.zero();
  speedo.zero();
  temp.zero();
  fuel.zero();
  
  Serial.begin(9600);
  Serial.println("Data feed pattern: rmp;speed(km/h);temp(*C 120 max); fuel (max 100)");
}

void loop(void)
{
  static int nextPos = 0;
  static byte counter = 0;
  // the motor only moves when you call update
  rpm.update();
  speedo.update();
  temp.update();
  fuel.update();
  
  if (Serial.available()) {
    char c = Serial.read();
    //Serial.print((byte)c);
    //Serial.print(';');
    if (c==59) {
      switch (counter){
        case 0:
          rpm.setPosition(nextPos * rpmMultiplier);
          break;
        case 1:
          speedo.setPosition(nextPos * speedoMultiplier);
          break;
        case 2:
          temp.setPosition(nextPos * tempMultiplier);
          break;
        case 3:
          fuel.setPosition(nextPos * fuelMultiplier);
          break;
      }
      nextPos = 0;
      if (counter != 3)
        counter++;
      else
        counter = 0;
      //Serial.println();
    } else if (c>='0' && c<='9') {
      nextPos = 10*nextPos + (c-'0');
    } else if (c == 10 || c==13){
      counter = 0;
      nextPos = 0;
    }
  }
}
