//==========================================================
//
// Title: Class Customer - Header
// Description:
//   This C++ header defines the function prototypes for
// the functions implemented in file
// Customer.cpp.
//
//==========================================================

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <iostream>

using namespace std;

class Customer {
public:
  // Constructors

  /*
   * Construct a customer object with default values.
   */
  Customer();

  /*
   * Construct a customer object with given id, items,
   * and items cost.
   * @param id, the id of the customer
   * @param items, the total items in cart
   * @param cost, cost of all items in cart
   */
  Customer(int id, int items, double cost);

  // Mutators

  /*
   * Sets the customer id with given id.
   * @param id, the id of the customer
   */
  void setId(int id);

  /*
   * Sets the number of items items in cart.
   * @param items, the number of items in cart.
   */
  void setItems(int items);

  /*
   * Sets the cost for items in cart.
   * @param cost, the cost of a all items in cart.
   */
  void setCost(double cost);

  /*
   * Sets the next customer in queue.
   * @param ptr, pointer to the next customer
   */
  void setNext(Customer* ptr);

  // Accessors

  /*
   * Retrieves the id of the customer.
   * @return the id of the customer.
   */
  int getId() const;

  /*
   * Retrieves number of items in cart.
   * @return the number of items.
   */
  int getItems() const;

  /*
   * Retrieves the total cost for all items in cart.
   * @return the cost of all items in cart.
   */
  double getCost() const;

  /*
   * Retrieves the next customer.
   * @return pointer to the next customer in queue.
   */
  Customer* getNext() const;

private:
  // Data fields
  int id = -10;
  int items = -10;
  double cost = -10;
  Customer* next = NULL;

};

bool isValid(int num);

#endif
