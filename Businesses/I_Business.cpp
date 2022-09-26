
#include "I_Business.h"

// Constructor
I_Business::I_Business(std::string type): type {type} {}


// Overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const I_Business &obj) {
  obj.printInfo(os);
  return os;
}
