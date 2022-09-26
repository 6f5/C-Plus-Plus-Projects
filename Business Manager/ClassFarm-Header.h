//==========================================================
//
// Title: Class Farm - Header
// Description:
//   This C++ header defines the function prototypes 
// implemented in file ClassFarm-Implementation.cpp.
//
//==========================================================

// Insure Farm class defined once
#ifndef FarmFlag
#define FarmFlag

#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include "AbstractClassBusiness-Header.h"
using namespace std;  // So "std::cout" may be abbreviated to "cout", for example.

//----------------------------------------------------------
// Farm class
//----------------------------------------------------------
class Farm: public Business
{

  //--------------------------------------------------------
  // Private members
  //--------------------------------------------------------
  private:

    //------------------------------------------------------
    // Fields
    //------------------------------------------------------
    string mainCrop = "(unknown)";
    int acres = 0;
    static int count;
    static int totalAcres;

  //--------------------------------------------------------
  // Public members
  //--------------------------------------------------------
  public:

    //------------------------------------------------------
    // Constructor and destructor prototypes
    //------------------------------------------------------

    Farm();
    Farm(string mainCrop);
    Farm(string mainCrop, int acres);
    ~Farm();

    //------------------------------------------------------
    // Getter prototypes
    //------------------------------------------------------
    string getMainCrop() const;
    int getAcres() const;
    int getCount() const;
    int getTotalAcres() const;

    //------------------------------------------------------
    // Setter prototypes
    //------------------------------------------------------
    void setMainCrop(string mainCrop);
    void setAcres(int acres);
    void setCount();
    void setTotalAcres(int acres);

    //------------------------------------------------------
    // Other prototypes
    //------------------------------------------------------
    void setInfo();
    void printInfo(string heading) const;

};

#endif
