#include <Stepper.h>
/*
Currently The code will simply do a single rotation clockwise then counterclockwise in a loop. Based on the simple example codes from the stepper library.
*/

const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
const int rpm = 17;         // Adjustable range of 28BYJ-48 stepper is 0~17 rpm

// initialize the stepper library on pins 8 through 11:
Stepper StepperScrew(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  StepperScrew.setSpeed(rpm);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {  
  // step one revolution  in one direction:
  Serial.println("clockwise");
  StepperScrew.step(stepsPerRevolution);
  delay(1000);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  StepperScrew.step(-stepsPerRevolution);
  delay(500);
}
