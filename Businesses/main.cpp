#include <iostream>
#include "Business.h"

//==========================================================
//
// Author: Abdulla Saeed
// Date: 10/28/2021
// Description:
// Console application that manages businesses.
//
//==========================================================


using namespace std;

int main() {

  // Creating business object
  Business business {"ecommerce", "Business Buddies"};

  // Printing its data
  cout << business << endl;

  // Print its data again
  cout << business << endl;

  // Prompt user for object data
  business.setInfo();

  // Print its data again
  cout << business << endl;

  // Dynamic array
  Business *businesses = new Business[5];

  // pointer variable
  Business *businessesPtr = businesses;

  for(int i = 0; i < 5; i++){
    //  Uses the pointer variable to print all of its values.
    // using overloaded insertion operator
    cout << *businessesPtr << endl;

    // Uses the pointer variable to call the method that prompts
    // the user to change values
    businessesPtr->setInfo();

    // Uses the pointer variable to print all of its values again.
    cout << *businessesPtr << endl;

    // Increments the pointer variable.
    businessesPtr++;
  };



  // free memory
  delete [] businesses;

  return 0;
}
