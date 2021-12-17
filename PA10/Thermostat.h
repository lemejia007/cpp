
// Specification file for Thermostat class
#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include <iostream>

/**********************************************************
*                    Class Declaration
*/
class Thermostat { // The following class represents the thermostate
  
  // Public enums
  public: 
    enum  Status {OFF, HEAT, COOL}; // States that thermostat can assume
    enum  Day    {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
  
  // Private class members
  private:
    const float TEMP_MIN     =   0.0;      // Lowest temperature (degrees)
    const float TEMP_MAX     = 110.0;      // Maximum temperature (degrees)
    const float TEMP_DEFAULT =  71.0;      // Default temperature (degrees)
    struct ThermState {
      float  setTemperature;  // Target temperature
      Status currentMode;     // Current thermostat status
      float  realTemperature; // Ambient temperature
    };
    ThermState* thermPtr = nullptr; // Pointer to a ThermState structure

  // Public class members
  public:
    Thermostat();              // Constructor 
    Thermostat(float setTemp, Status mode); // Overloaded constructor
   ~Thermostat();              // Destructor
    void   setSetTemperature (float temp);
    void   setMode           (Status mode);
    Status getCurrentMode    () const;
    float  getSetTemperature () const;
    float  getRealTemperature() const;
    void   showStatus        ();
    void   reset             ();      
};

#endif