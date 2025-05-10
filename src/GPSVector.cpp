#include "../include/GPSVector.h"
#include <math.h>

GPSVector::GPSVector() {
  _originLat = 0.0;
  _originLon = 0.0;
  _viewpointLat = 0.0;
  _viewpointLon = 0.0;
  _distance = 0.0;
  _bearing = 0.0;
}

void GPSVector::setOrigin(float latitude, float longitude) {
  _originLat = latitude;
  _originLon = longitude;
}

void GPSVector::setViewpoint(float latitude, float longitude) {
  _viewpointLat = latitude;
  _viewpointLon = longitude;
}

void GPSVector::calculateVector() {
  // Convert latitude and longitude from degrees to radians
  float lat1 = toRadians(_originLat);
  float lon1 = toRadians(_originLon);
  float lat2 = toRadians(_viewpointLat);
  float lon2 = toRadians(_viewpointLon);
  
  // Calculate distance using the Haversine formula
  float R = 6371000.0; // Earth radius in meters
  float dLat = lat2 - lat1;
  float dLon = lon2 - lon1;
  
  float a = sin(dLat/2) * sin(dLat/2) +
            cos(lat1) * cos(lat2) * 
            sin(dLon/2) * sin(dLon/2);
  float c = 2 * atan2(sqrt(a), sqrt(1-a));
  _distance = R * c;
  
  // Calculate initial bearing
  float y = sin(lon2 - lon1) * cos(lat2);
  float x = cos(lat1) * sin(lat2) - 
           sin(lat1) * cos(lat2) * cos(lon2 - lon1);
  float initialBearing = atan2(y, x);
  
  // Convert bearing from radians to degrees
  _bearing = toDegrees(initialBearing);
  
  // Normalize bearing to 0-360
  _bearing = fmod((_bearing + 360.0), 360.0);
}

float GPSVector::getDistance() {
  return _distance;
}

float GPSVector::getBearing() {
  return _bearing;
}

float GPSVector::toRadians(float degrees) {
  return degrees * M_PI / 180.0;
}

float GPSVector::toDegrees(float radians) {
  return radians * 180.0 / M_PI;
} 