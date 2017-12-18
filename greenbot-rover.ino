/*
   rover code for green bot
*/

#include "setup.h"
#include "pwm.h"
#include "encoders.h"
#include "rovertalk.h"

void setup() {
  Wire.begin(I2C_ROVER_ADDRESS);
  MOTOR.begin();    // initialize hercules
  Serial.begin(115200);
  setupPWM();
  setupEncoders();
  setupRovertalk();
  pinMode(11, OUTPUT); digitalWrite(11, LOW);
  pinMode(12, OUTPUT); digitalWrite(12, LOW);
  pinMode(13, OUTPUT); digitalWrite(13, LOW);

}



