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
#define STEPS_H (315*3) //Range for rpm and speed gauges
#define STEPS_L (315*3) //Range for water temp. and fuel gauges
#define STEPS (315*3)

// Four motors with corresponging pins
SwitecX25 rpm(STEPS,5, 4, 3, 2);//5 4 3 2 
SwitecX25 speedo(STEPS,9,8,7,6); // 9 8 7 6
SwitecX25 temp(STEPS,A0,A1,A2,A3); //Using analog pins as digital
SwitecX25 fuel(STEPS,11,12,10,13); 

void setup(void)
{
  // runs the motors against the stops
  rpm.zero();
  speedo.zero();
  temp.zero();
  fuel.zero();
  rpm.setPosition(0);
  speedo.setPosition(0);
  temp.setPosition(0);
  fuel.setPosition(0);
  
  Serial.begin(9600);
  Serial.print("Enter a step position from 0 through ");
  Serial.print(STEPS-1);
  Serial.println(".");
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
    Serial.print((byte)c);
    Serial.print(';');
    if (c==59) {
      switch (counter){
        case 0:
          rpm.setPosition(nextPos);
          break;
        case 1:
          speedo.setPosition(nextPos);
          break;
        case 2:
          temp.setPosition(nextPos);
          break;
        case 3:
          fuel.setPosition(nextPos);
          break;
      }
      nextPos = 0;
      if (counter != 3)
        counter++;
      else
        counter = 0;
      Serial.println();
    } else if (c>='0' && c<='9') {
      nextPos = 10*nextPos + (c-'0');
    } else if (c == 10 || c==13){
      counter = 0;
      nextPos = 0;
    }
  }
}
