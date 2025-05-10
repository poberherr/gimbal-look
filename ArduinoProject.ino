/*
 * ArduinoProject
 * 
 * A standard Arduino project template
 * 
 */

#include "include/PWMManager.h"
#include "include/GPSVector.h"

// Global variables and constants
const int LED_PIN = 13;
const int PWM_PIN = 9;      // Output pin for PWM
int dutyCycle = 10;        // Duty cycle in percent (0 - 100)

// Create a PWM manager for pin 9 at 50Hz
PWMManager pwm(PWM_PIN, 50);

// Create a GPS vector calculator
GPSVector gpsVector;

// Example GPS coordinates (San Francisco and Los Angeles)
float originLat = 51.099857563262084;       // Home
float originLon = 6.417410825796639;

float viewpointLat = 51.09822018891613;     // Playground
float viewpointLon = 6.416295546823446;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize pins
  pinMode(LED_PIN, OUTPUT);
  
  // Set the initial duty cycle
  pwm.setDutyCycle(dutyCycle);
  
  // Calculate GPS vector
  gpsVector.setOrigin(originLat, originLon);
  gpsVector.setViewpoint(viewpointLat, viewpointLon);
  gpsVector.calculateVector();
  
  // Print results
  Serial.println("GPS Vector Calculation:");
  Serial.print("Distance: ");
  Serial.print(gpsVector.getDistance());
  Serial.println(" meters");
  Serial.print("Bearing: ");
  Serial.print(gpsVector.getBearing());
  Serial.println(" degrees");
  
  Serial.println("Setup complete");
}

void loop() {
  // Blink the LED
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  
  // Generate software PWM signal
  pwm.generatePulse();
  
  // Example: You can change duty cycle dynamically
  // dutyCycle = (dutyCycle + 1) % 100;
  // pwm.setDutyCycle(dutyCycle);
} 