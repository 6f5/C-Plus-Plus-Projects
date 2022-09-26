#include <iostream>
#include "Payment.h"

//==========================================================
//
// Author: Abdulla Saeed
// Date: 10/8/2021
// Description:
// A console application that can be used to track payments
// and check if they're paid or not
//
//==========================================================



int main() {
  //  Creates an object using the two-parameter constructor.
  // After it is created, print all of its values.
  Payment payment {132.50, false};
  payment.print();

  //  For the object, calls the setter and getter methods in
  // sequence for each instance field in the object.
  const double due = payment.getDue();
  const bool isPaid = payment.getPaid();
  payment.setDue(300.50);
  payment.setPaid(true);

  //  Creates and sets a pointer variable to the object.
  Payment *paymentPtr {&payment};

  //  For the object, uses the pointer variable to call the setter
  // and getter methods in
  // sequence for each instance field in the object.
  const double pDue = paymentPtr->getDue();
  const bool pIsPaid = paymentPtr->getPaid();
  paymentPtr->setDue(500.50);
  paymentPtr->setPaid(false);


  //  For the object, uses the pointer variable to:
  //		x Print all of its values.
  //		x Call the method that prompts the user to change values.
  //		x Print all of its values again.
  paymentPtr->print();
  paymentPtr->prompt();
  paymentPtr->print();



  //  Creates an array four objects.
  Payment payments[4] {
      {10.50, false},
      {12.40, true},
      {50.45, false},
      {134.94, true}
  };

  //  For each spot in the array, assigns the pointer variable to that spot,
  // and uses the pointer variable to:
  //		 Print all of its values.
  //		 Call the method that prompts the user to change values.
  //		 Print all of its values again.
  for(int i = 0; i < 4; i++){
    std::cout << "-----------------------" << std::endl;
    (payments+i)->print();
    (payments+i)->prompt();
    (payments+i)->print();
  }

  return 0;
}
