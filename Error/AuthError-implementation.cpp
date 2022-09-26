
#include "AuthError.h"

// Constructors
// zero-parameter constructor
AuthError::AuthError() {
}

// one-parameter constructor
AuthError::AuthError(string name){
  this->name = name;
}

// two-parameter constructor
AuthError::AuthError(string message, int code) {
  this->message = message;
  this->code = code;
}

// Getters
string AuthError::getLogLevel() {
  return logLevel;
}

string AuthError::getSource(){
  return source;
};

// Setters
void AuthError::setLogLevel(string logLevel){
  this->logLevel = logLevel;
}

void AuthError::setSource(string source){
  this->source = source;
};

// Get user input from console
void AuthError::prompt() {
  string logLevel;
  string source;

  // Get input and pass to setters
  // to catch invalid inputs
  cout << endl;
  cout << "======= AuthError =======" << endl;
  cout << "Log level [debug, info, error]: ";
  getline(cin, logLevel);
  setLogLevel(logLevel);
  Error::clearCin();
  cout << "Source? (source of error): ";
  getline(cin, source);
  setSource(source);

  cout << endl;
}

// Log details
void AuthError::printDetails() {
  cout << "::Auth Error:" << endl;
  Error::printDetails();
  cout << "Log level: " << logLevel << endl;
  cout << "Source: " << source << endl;
  cout << endl;
}