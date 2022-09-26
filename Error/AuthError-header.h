
#ifndef HOMEWORK2_AUTHERROR_H
#define HOMEWORK2_AUTHERROR_H

#include <iostream>
#include "Error.h"

using namespace std;

class AuthError: public Error {
private:
  string logLevel {"debug"};
  string source {"undefined"};
public:
  // Constructors prototypes
  AuthError();
  AuthError(string name);
  AuthError(string message, int code);


  // Getters & setters prototypes
  void setLogLevel(string logLevel);
  string getLogLevel();
  void setSource(string source);
  string getSource();

  // Prompt user for input
  void prompt();

  // Log details
  void printDetails();
};

#endif //HOMEWORK2_AUTHERROR_H
