
#include <iostream>
#include "Payment.h"


// statics
double Payment::total = 0.0;
int Payment::count = 0;

// Constructors
// using constructor initializer list
Payment::Payment(): due {0.0}, paid {false}{
  // Increment count
  count++;
};

// Constructor delegation
Payment::Payment(const double due): Payment(due, false){
};

Payment::Payment(const double due, const bool paid):due {due}, paid {paid} {

  // increment total
  total += due;

  // Increment count
  count++;
};

// Getters
const double Payment::getDue(){
  return due;
};
const bool Payment::getPaid(){
  return paid;
};

// Setters
void Payment::setDue(const double due){

  // check if it over 500
  if(due > 500.0){

    // show error
    std::cout << "Payment due cannot exceed $500" << std::endl;
    return;
  }

  // set payment due
  this->due = due;
};
void Payment::setPaid(const bool paid){
  this->paid = paid;
};

// Prompt
void Payment::prompt(){

  // ask for for payment due and if is paid
  double paymentDue;
  bool paid;
  std::cout << std::endl;
  std::cout << "Payment Due: ";
  std::cin >> paymentDue;
  std::cout << "Is Paid: (0 = false, 1 = true): ";
  std::cin >> paid;
  std::cout << std::endl;

  // calling setters
  setDue(paymentDue);
  setPaid(paid);
};

// Display data
void Payment::print(){
  std::cout << std::boolalpha;
  std::cout << std::endl;
  std::cout << "======= Payment Details ======= "<< std::endl;
  std::cout << "Payment Due: " << due << std::endl;
  std::cout << "Is Paid: " << paid << std::endl;
  std::cout << std::endl;
};