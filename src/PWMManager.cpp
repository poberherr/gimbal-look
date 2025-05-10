#include "../include/PWMManager.h"

PWMManager::PWMManager(int pin, int frequency) {
  _pin = pin;
  _dutyCycle = 0;
  
  // Calculate period in microseconds from frequency in Hz
  _period = 1000000 / frequency;
  
  pinMode(_pin, OUTPUT);
}

void PWMManager::setDutyCycle(int dutyCycle) {
  // Clamp duty cycle between 0 and 100
  _dutyCycle = constrain(dutyCycle, 0, 100);
}

void PWMManager::generatePulse() {
  // Calculate high and low times based on duty cycle
  int highTime = _period * _dutyCycle / 100;
  int lowTime = _period - highTime;
  
  // Generate the PWM pulse
  digitalWrite(_pin, HIGH);
  delayMicroseconds(highTime);
  
  digitalWrite(_pin, LOW);
  delayMicroseconds(lowTime);
} 