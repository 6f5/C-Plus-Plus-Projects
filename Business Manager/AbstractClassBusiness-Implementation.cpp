//==========================================================
//
// Title: Abstract Class Business - Implementation
// Description:
//   This C++ implementation defines the functions for
// prototypes in file AbstractClassBusiness-Header.h.
//
//==========================================================
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include "AbstractClassBusiness-Header.h"
using namespace std;  // So "std::cout" may be abbreviated to "cout", for example.

//----------------------------------------------------------
// Function implementations
//----------------------------------------------------------

//--------------------------------------------------------
// Getters
//--------------------------------------------------------

// getType
string Business::getType() const
{
  return type;
}

//--------------------------------------------------------
// Setters
//--------------------------------------------------------

// setType
void Business::setType(string type)
{
  this->type = type;
}
