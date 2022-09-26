
#ifndef HW4_BUSINESS_H
#define HW4_BUSINESS_H

#include "I_Business.h"

class Business: public I_Business {
  //  At least two static fields that contain
  // information shared across all objects created for your business.
  static int count;
  static std::string attire;
private:
  //  At least two instance fields that contain
  // information about your business.
  std::string name;
  std::string ceo;
  int id {0};
public:
  //  At least three constructors, including a zero-parameter
  // constructor.
  Business();
  Business(std::string type,std::string name);
  Business(std::string type,std::string name, std::string ceo);

  //  Getter methods for each field.
  virtual std::string getType() const override;
  std::string getName() const;
  std::string getCEO() const;
  int getId() const;
  std::string getAttire() const;
  int getCount() const;

  //  Setter methods for each field, including validation
  // logic for each numeric field.  If the incoming value is
  // invalid, print an error message and don't change the field's value.
  void setName(std::string name);
  void setCEO(std::string ceo);
  virtual void setType(std::string type) override;

  // Prompt user for data
  virtual void setInfo() override;

  // Print data
  virtual void printInfo(std::ostream &os) const override;

  // Make compiler generate default destructor
  virtual ~Business() = default;
};


#endif //HW4_BUSINESS_H
