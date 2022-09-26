
#include <iostream>
#include "Error.h"
#include "AuthError.h"
#include "InternalError.h"



//==========================================================
//
// Author: Abdulla Saeed
// Date: 9/28/2021
// Description:
// A console application to create custom errors and print their
// details to the console for debugging.
//
//==========================================================


using namespace std;


int main() {

  // two objects from parent class
  Error error1("Error1", "Error one object", 500, false);
  Error error2;

  // three objects from each child classes

  AuthError authError;
  AuthError authError1("Auth");
  AuthError authError2("Auth error", 400);

  InternalError internalError;
  InternalError internalError1(true);
  InternalError internalError2(false, "high");

  // After each one is created, print all of its values
  error1.printDetails();
  error2.printDetails();

  authError.printDetails();
  authError1.printDetails();
  authError2.printDetails();

  internalError.printDetails();
  internalError1.printDetails();
  internalError2.printDetails();


  // For one of the child objects, call the setter and getter
  // methods in sequence for each field in the object.
  internalError.setIsLogged(true);
  internalError.setSeverity("high");


  // For one of the parent objects, prints all of its values
  error1.printDetails();

  // calls the method that prompts the user to change values
  error1.prompt();

  // then prints all of its values again
  error1.printDetails();

  // For one of the child objects, prints all of its values
  internalError.printDetails();

  // calls the method that prompts the user to change values
  internalError.prompt();

  // then prints all of its values again
  internalError.printDetails();


  // For one of the child objects, prints all of its values
  authError.printDetails();

  // calls the method that prompts the user to change values
  authError.prompt();

  // then prints all of its values again
  authError.printDetails();

  return 0;
}

