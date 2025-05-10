# Arduino Project

A standard Arduino project template with LED blink, software PWM functionality, and GPS vector calculations.

## Hardware Requirements

- Arduino board (Uno, Nano, Mega, etc.)
- LED (connected to pin 13)
- Resistor for LED (220-330Ω)
- Device to be controlled by PWM signal (connected to pin 9)
- Optional: GPS module (for real-time coordinates)

## Setup Instructions

1. Connect the LED to pin 13 and GND through a resistor
2. Connect your PWM device to pin 9
3. Upload the sketch to your Arduino board
4. The LED should blink with a 1-second interval
5. Pin 9 will output a 50Hz PWM signal with 10% duty cycle
6. GPS vector calculation will be displayed in the Serial Monitor

## Project Structure

- `ArduinoProject.ino`: Main Arduino sketch file
- `src/`: Source files for additional functionality
  - `PWMManager.cpp`: Implementation of PWM functionality
  - `GPSVector.cpp`: Implementation of GPS vector calculations
- `include/`: Header files
  - `PWMManager.h`: Definition of PWM manager class
  - `GPSVector.h`: Definition of GPS vector calculations class
- `libraries/`: Optional folder for custom libraries

## Features

- LED blink demonstration
- Software PWM generation at 50Hz
- Configurable duty cycle (currently set to 10%)
- GPS vector calculations:
  - Distance between two GPS coordinates
  - Bearing/direction from origin to viewpoint
