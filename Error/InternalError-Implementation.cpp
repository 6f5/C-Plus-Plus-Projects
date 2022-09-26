
#include "InternalError.h"
#include <iostream>

// Constructors
// one-parameter constructor
InternalError::InternalError(bool isLogged){
  this->isLogged = isLogged;
}

// two-parameter constructor
InternalError::InternalError(bool isLogged, string severity){
  this->isLogged = isLogged;
  this->severity = severity;
}

// zero-parameter constructor
InternalError::InternalError(){
}


// Getters
string InternalError::getSeverity(){
  return severity;
};

bool InternalError::getIsLogged(){
  return isLogged;
};


// Setters
void InternalError::setSeverity(string severity) {
  this->severity = severity;
}

void InternalError::setIsLogged(bool isLogged){
  if(isLogged < 0 || isLogged > 1){
    cerr << "Invalid boolean value. [" << isLogged << "]" << endl;
  } else {
    this->isLogged = isLogged;
  }
};

// Get user input from console
void InternalError::prompt() {
  string severity;
  bool isLogged;

  // Get input and pass to setters
  // to catch invalid inputs
  cout << endl;
  cout << "======= InternalError =======" << endl;
  cout << "Severity [low, medium, high]: ";
  cin >> severity; // no need to get a line
  setSeverity(severity);
  cout << "Is logged? [0 = false, 1 = true]: ";
  cin >> isLogged;
  setIsLogged(isLogged);
  cout << endl;
}

// Print necessary details to console
void InternalError::printDetails() {
  cout << "::Internal Error:" << endl;
  Error::printDetails();
  cout << "Severity: " << severity << endl;
  cout << "Is logged: " << isLogged << endl;
  cout << endl;
}