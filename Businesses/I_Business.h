
#ifndef HW4_I_BUSINESS_H
#define HW4_I_BUSINESS_H

#include <iostream>

class I_Business {
  friend std::ostream &operator<<(std::ostream &os, const I_Business &obj);
protected:
  std::string type;
public:
  I_Business(std::string type = "Not Set");
  virtual std::string getType() const = 0;
  virtual void setType(std::string) = 0;
  virtual void setInfo() = 0;
  virtual void printInfo(std::ostream &os) const = 0;
  virtual ~I_Business() = default;
};



#endif //HW4_I_BUSINESS_H
