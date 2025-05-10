#ifndef EXAMPLE_LIBRARY_H
#define EXAMPLE_LIBRARY_H

#include <Arduino.h>

/*
 * Example Arduino Library
 * 
 * This demonstrates how to create a custom library for Arduino
 */

class ExampleLibrary {
  public:
    ExampleLibrary();
    void begin();
    void doSomething();
  
  private:
    int _privateVariable;
};

#endif 