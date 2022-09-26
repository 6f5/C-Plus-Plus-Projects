
#include <iostream>
#include "Error.h"

using namespace std;

// Constructors
// zero-parameter constructor
Error::Error(){
  // Increment static instances by 1
  count++;
  id++;
}

// multi-params constructor
Error::Error(string name, string message, int code, bool intercepted){
  // Initialize variables to user input
  this->name = name;
  this->message = message;
  this->code = code;
  this->intercepted = intercepted;
  Error(); // Call zero-parameter constructor to increment static props
};

// Getters
string Error::getName(){
  return name;
}

string Error::getMessage(){
  return message;
}

int Error::getCode(){
  return code;
}

int Error::getCount(){
  return count;
}

int Error::getId(){
  return id;
}

// Setters
void Error::setName(string name){
  this->name = name;
}

void Error::setMessage(string message){
  this->message = message;
}

void Error::setCode(int code){
  // Max = 500
  if(code > 500 || code < 0){
    cerr << "RangeError: Invalid error code. " << code << endl;
  } else {
    this->code = code;
  }
}

void Error::setIntercepted(bool intercepted){
  if(intercepted < 0 || intercepted > 1){
    cerr << "Invalid boolean value. [" << intercepted << "]" << endl;
   } else {
    this->intercepted = intercepted;
  }
}


// Print necessary data to console
void Error::printDetails(){
  cout << endl;
  cout << boolalpha;
  cout << "ID: "<< getId() << endl;
  cout << "Count: "<< getCount() << endl;
  cout << "Name: " << name << endl;
  cout << "Message: " << message << endl;
  cout << "Code: " << code << endl;
  cout << "Intercepted: " << intercepted << endl;
}


// Accept user input from console
void Error::prompt() {
  string name, message;
  int code {};
  bool intercepted {false};

  // Get input and pass to setters
  // to catch invalid inputs
  cout << endl;
  cout << "======= Error =======" << endl;
  cout << "Enter error name: ";
  getline(cin, name);
  setName(name);
  cout << "Enter message: ";
  getline(cin, message);
  setMessage(message);
  cout << "Enter code (int): ";
  cin >> code;
  setCode(code);
  cout << "Intercepted (0 = false, 1 = true): ";
  cin >> intercepted;
  setIntercepted(intercepted);
  cout << endl;

}


// Static props
int Error::count = 0;
int Error::id = 0;

// flush buffer
void Error::clearCin()
{
  string t;
  getline(cin, t);
}