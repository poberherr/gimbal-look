#ifndef GPS_VECTOR_H
#define GPS_VECTOR_H

#include <Arduino.h>

/*
 * GPS Vector
 * 
 * A class for handling GPS coordinates and vector calculations
 */

class GPSVector {
  public:
    // Constructor
    GPSVector();
    
    // Set coordinates
    void setOrigin(float latitude, float longitude);
    void setViewpoint(float latitude, float longitude);
    
    // Calculate vector from origin to viewpoint
    void calculateVector();
    
    // Get results
    float getDistance();    // Distance in meters
    float getBearing();     // Bearing in degrees (0-360, where 0 is North)
    
  private:
    // GPS coordinates
    float _originLat;
    float _originLon;
    float _viewpointLat;
    float _viewpointLon;
    
    // Vector results
    float _distance;  // in meters
    float _bearing;   // in degrees
    
    // Helper methods
    float toRadians(float degrees);
    float toDegrees(float radians);
};

#endif 