
#ifndef HOMEWORK2_ERROR_H
#define HOMEWORK2_ERROR_H

#include <iostream>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

class Error {
  static int count;
  static int id;
protected:
  string name {"undefined"};
  string message {"undefined"};
  int code {404};
  bool intercepted {false};


public:
  Error(string name, string message, int code, bool intercepted);
  Error();

  // Getters - prototypes
  string getName();
  string getMessage();
  int getCode();
  int getCount();
  int getId();

  // Setters - prototypes
  void setName(string name);
  void setMessage(string message);
  void setCode(int code);
  void setIntercepted(bool intercepted);


  void printDetails();
  void prompt();

  void clearCin();
};

#endif //HOMEWORK2_ERROR_H
