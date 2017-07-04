/***************************************************
  This is a library for our Adafruit 16-channel PWM & Servo driver

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution

  Modified by Greg Armstrong for the TEC-Bot 4.2
  June 2017
  Added functions to convert motor speed to PWM values and eliminate
  deadband.
 ****************************************************/

#ifndef _TECBOT_PWMServoDriver_H
#define _TECBOT_PWMServoDriver_H

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define PWM_CENTER 320
#define PWM_MIN 180
#define PWM_MAX 560
#define DEADBAND 20

#define PCA9685_SUBADR1 0x2
#define PCA9685_SUBADR2 0x3
#define PCA9685_SUBADR3 0x4

#define PCA9685_MODE1 0x0
#define PCA9685_PRESCALE 0xFE

#define LED0_ON_L 0x6
#define LED0_ON_H 0x7
#define LED0_OFF_L 0x8
#define LED0_OFF_H 0x9

#define ALLLED_ON_L 0xFA
#define ALLLED_ON_H 0xFB
#define ALLLED_OFF_L 0xFC
#define ALLLED_OFF_H 0xFD


class TECBot_PWMServoDriver {
 public:
  TECBot_PWMServoDriver(uint8_t addr = 0x40);
  void begin(void);
  void reset(void);
  void setPWMFreq(float freq);
  void setPWM(uint8_t num, uint16_t on, uint16_t off);
  void setPin(uint8_t num, uint16_t val, bool invert=false);
  void armESC(uint8_t num, uint16_t pwmCenter = PWM_CENTER);
  void setDrive(int leftSpeed, int rightSpeed);
  void setMotor(uint8_t num, int speed);
  void setServo(uint8_t num, uint8_t position);

 private:
  uint8_t _i2caddr;

  uint16_t eliminateDeadband(int speed);
  uint8_t read8(uint8_t addr);
  void write8(uint8_t addr, uint8_t d);
};

#endif
