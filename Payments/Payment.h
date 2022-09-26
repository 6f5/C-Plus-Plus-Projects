#ifndef HW3_PAYMENT_H
#define HW3_PAYMENT_H


class Payment {
private:
  static double total;
  static int count;

  double due;
  bool paid;
public:
  // Constructors
  Payment();
  Payment(const double due);
  Payment(const double due, const bool paid);

  // Getters
  const double getDue();
  const bool getPaid();

  // Setters
  void setDue(const double due);
  void setPaid(const bool paid);

  // Prompt
  void prompt();

  // Display data
  void print();
};


#endif //HW3_PAYMENT_H
