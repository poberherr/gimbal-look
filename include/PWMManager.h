#ifndef PWM_MANAGER_H
#define PWM_MANAGER_H

#include <Arduino.h>

/*
 * PWM Manager
 * 
 * A class for managing software PWM signals
 */

class PWMManager {
  public:
    PWMManager(int pin, int frequency = 50);
    void setDutyCycle(int dutyCycle);
    void generatePulse();
  
  private:
    int _pin;
    int _dutyCycle;
    int _period;  // in microseconds
};

#endif 