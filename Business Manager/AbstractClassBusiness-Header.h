//==========================================================
//
// Title: Abstract Class Business - Header
// Description:
//   This C++ header defines the virtual functions 
// implemented in child classes.
//
//==========================================================

// Insure Business class defined once
#ifndef BusinessFlag
#define BusinessFlag

#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
using namespace std;  // So "std::cout" may be abbreviated to "cout", for example.

//----------------------------------------------------------
// Business class
//----------------------------------------------------------
class Business
{

  //--------------------------------------------------------
  // Private members
  //--------------------------------------------------------
  private:

    //------------------------------------------------------
    // Fields
    //------------------------------------------------------
    string type = "(unknown)";

  //--------------------------------------------------------
  // Public members
  //--------------------------------------------------------
  public:

    //------------------------------------------------------
    // Getter and setter prototypes
    //------------------------------------------------------
    string getType() const;
    void setType(string type);

    //------------------------------------------------------
    // Virtual prototypes
    //------------------------------------------------------

    virtual void setInfo() = 0;
    virtual void printInfo(string heading) const = 0;

};

#endif
