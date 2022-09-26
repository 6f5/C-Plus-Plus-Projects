//==========================================================
//
// Title: Class Farm - Implementation
// Description:
//   This C++ implementation defines the functions for
// prototypes in file ClassFarm-Header.h.
//
//==========================================================
#include <cstdlib>  // For several general-purpose functions
#include <fstream>  // For file handling
#include <iomanip>  // For formatted output
#include <iostream>  // For cin, cout, and system
#include <string>  // For string data type
#include "ClassFarm-Header.h"
using namespace std;  // So "std::cout" may be abbreviated to "cout", for example.

//----------------------------------------------------------
// Constants
//----------------------------------------------------------

const int COLFMT = 20;

//----------------------------------------------------------
// Function implementations
//----------------------------------------------------------

//----------------------------------------------------------
// Constructors and destructor
//----------------------------------------------------------

// Zero-parameter constructor
Farm::Farm()
{
  Business::setType("Farm");
  mainCrop = "(not set)";
  acres = 0;
  setCount();
  totalAcres = totalAcres + acres;
}

// One-parameter constructor
Farm::Farm(string mainCrop)
{
  Business::setType("Farm");
  this->mainCrop = mainCrop;
  acres = 0;
  setCount();
  totalAcres = totalAcres + acres;
}

// Two-parameter constructor
Farm::Farm(string mainCrop, int acres)
{
  Business::setType("Farm");
  this->mainCrop = mainCrop;
  this->acres = acres;
  setCount();
  totalAcres = totalAcres + acres;
}

// Destructor
Farm::~Farm()
{
}

//--------------------------------------------------------
// Getters
//--------------------------------------------------------

// getMainCrop
string Farm::getMainCrop() const
{
  return mainCrop;
}

// getAcres
int Farm::getAcres() const
{
  return acres;
}

// getCount
int Farm::getCount() const
{
  return count;
}

// getTotalAcres
int Farm::getTotalAcres() const
{
  return totalAcres;
}

//--------------------------------------------------------
// Setters
//--------------------------------------------------------

// setMainCrop
void Farm::setMainCrop(string mainCrop)
{
  this->mainCrop = mainCrop;
}

// setAcres
void Farm::setAcres(int acres)
{
  setTotalAcres(acres);
}

// setCount
void Farm::setCount()
{
  count = count + 1;
}

// setTotalAcres
void Farm::setTotalAcres(int acres)
{
  if (acres < 1)
    cout << "Error: number of acres must be >= 1."
    << endl;
  else
  {
    totalAcres = totalAcres - this->acres;
    this->acres = acres;
    totalAcres = totalAcres + this->acres;
  }
}

//--------------------------------------------------------
// Other functions
//--------------------------------------------------------

// setInfo
void Farm::setInfo()
{

  // Declare variables
  int newAcres;

  // Prompt for and get inputs
  cout << "\nEnter the main crop: ";
  cin >> mainCrop;
  cout << "Enter the number of acres: ";
  cin >> newAcres;
  setTotalAcres(newAcres);

}

// printInfo
void Farm::printInfo(string heading) const
{

  // Print business info
  cout << endl << heading << endl;
  cout << setw(COLFMT) << left << "Business type:"
    << setw(COLFMT) << right << Business::getType() << endl;
  cout << setw(COLFMT) << left << "Main crop:"
    << setw(COLFMT) << right << mainCrop << endl;
  cout << setw(COLFMT) << left << "Acres:"
    << setw(COLFMT) << right << acres << endl;
  cout << "\nTotal farms: " << count << endl;
  cout << "Total acres: " << totalAcres << endl;

}
