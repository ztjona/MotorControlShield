#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include "Arduino.h"

// Shift register to motor terminals pinout
enum MOTOR_PIN {
    MOTOR1_A = 2,
    MOTOR1_B = 3,
    MOTOR2_A = 1,
    MOTOR2_B = 4,
    MOTOR3_A = 5,
    MOTOR3_B = 7,
    MOTOR4_A = 0,
    MOTOR4_B = 6,
};

// Arduino PWM pins for motor speed control
enum MOTOR_PWM_PIN {
#ifdef __AVR__
    MOTOR1_PWM = 11,
    MOTOR2_PWM = 3,
    MOTOR3_PWM = 6,
    MOTOR4_PWM = 5,
#elif defined(ESP32)
    MOTOR1_PWM = 23,
    MOTOR2_PWM = 25,
    MOTOR3_PWM = 27,
    MOTOR4_PWM = 16,
#else
// not defined!
#endif
};

// Arduino pins to shift register control lines
enum SHIFTREG_CONTROL_PIN {
#ifdef __AVR__
    MC_LATCH  = 12,
    MC_CLK    = 4,
    MC_ENABLE = 7,
    MC_DATA   = 8,
#elif defined(ESP32)
    MC_LATCH = 19,
    MC_CLK = 17,
    MC_ENABLE = 14,
    MC_DATA = 12,
#else
// not defined!
#endif
};

class MotorControl
{
private:
    /* data */
    byte motorA, motorB;
    byte speed_pin;
    static byte register_output;
    static void update_register();

public:
    MotorControl(byte motor_num);
    static void init();
    void forward();
    void backward();
    void brake();
    void setSpeed(byte speed);
    ~MotorControl() {}
};

#endif  // MOTOR_CONTROL_H
