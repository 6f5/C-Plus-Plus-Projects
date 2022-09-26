//==========================================================
//
// Title: Class Customer - Implementation
// Description:
//   This C++ implementation implements the functions for the
// prototypes defined in file Customer.h.
//
//==========================================================

#include "Customer.h"


// Constructors

Customer::Customer()
{
  // No need to reinitialize data fields
  // since they've been already
  // initialized
}

Customer::Customer(int id, int items, double cost)
// Constructor list initialization
: id(id), items(items), cost(cost)
{

}


// Mutators
void Customer::setNext(Customer *ptr) {
  next = ptr;
}

void Customer::setId(int id) {
  if(isValid(id)){
    this->id = id;
    return;
  }

  cout << "Please enter a valid id greater than "
  << id << endl;

}

void Customer::setCost(double cost) {
  if(isValid(cost)){
    this->cost = cost;
    return;
  }
  cout << "The cost must be greater than 0." << endl;
}

void Customer::setItems(int items) {
  if(isValid(items)){
    this->items = items;
    return;
  }
  cout << "The items must be greater than zero" << endl;
}


// Accessors
int Customer::getId() const {
  return id;
}

double Customer::getCost() const {
  return cost;
}

int Customer::getItems() const {
  return items;
}


Customer* Customer::getNext() const {
  return next;
}

/*
 * Checks if a number is greater than zero.
 * @param num, the number to validate
 * @return true if the number is greater
 * than zero.
 */
bool isValid(int num){
  return num > 0;
}

