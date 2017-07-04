/*
 * Simple Drive test
 * By: Greg Armstrong
 * June 2017
 * 
 * This program makes use of the TEC Bot drive functions to test the drive motors and a servo.
 * 
 * available functions
 * 
 * setDrive(leftPower, rightPower)
 * Sets the speed of both drive motors at once. Assumes the motors are connected to ports 0 and 1
 * on the PWM driver board. leftPower and rightPower are numbers between -100 and 100
 * 
 * setMotor(num, power)
 * Sets a single motor (attached to port "num") to a speed.
 * power is an integer between -100 and 100
 * 
 * setServo(num, position)
 * Sets a servo attached to port "num" to an angle defined by position.
 * position is an integer between 0 and 180
 */

#include <TECBot_PWMServoDriver.h>

TECBot_PWMServoDriver drive = TECBot_PWMServoDriver();

void setup() {
  Serial.begin(9600);

  //Initialize the PWM controller
  drive.begin();
  drive.setPWMFreq(60);

  //Arm the ESC's by sending a "neutral" signal for 1.5 seconds
  drive.setDrive(0,0);
  delay(1500);
}

void loop() {
  //Ramp the drive motors up and down in both directions
  //The robot should spin around in a circle
  for (int i=0; i<100; i++) {
    drive.setDrive(i, -i);
    Serial.print("Drive: "); Serial.println(i);
    delay(10);
  }
  for (int i=100; i>-100; i--) {
    drive.setDrive(i, -i);
    Serial.print("Drive: "); Serial.println(i);
    delay(10);
  }
  for (int i=-100; i<0; i++) {
    drive.setDrive(i, -i);
    Serial.print("Drive: "); Serial.println(i);
    delay(10);
  }

  //Move one of the servos back and forth accross its whole range
  for (int i=0; i<180; i++) {
    drive.setServo(4, i);
    Serial.print("Servo: "); Serial.println(i);
    delay(10);
  }
  for (int i=180; i>0; i--) {
    drive.setServo(4, i);
    Serial.print("Servo: "); Serial.println(i);
    delay(10);
  }
}
