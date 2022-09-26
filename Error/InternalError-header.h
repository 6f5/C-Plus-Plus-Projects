
#ifndef HOMEWORK2_INTERNALERROR_H
#define HOMEWORK2_INTERNALERROR_H

#include <iostream>
#include "Error.h"

using namespace std;


class InternalError: Error {
private:
  bool isLogged {false};
  string severity {"low"};
public:
  InternalError(bool isLogged);
  InternalError(bool isLogged, string severity);
  InternalError();

  string getSeverity();
  void setSeverity(string severity);

  bool getIsLogged();
  void setIsLogged(bool isLogged);

  void prompt();

  void printDetails();

};

#endif //HOMEWORK2_INTERNALERROR_H
