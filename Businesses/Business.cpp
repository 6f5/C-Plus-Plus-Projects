#include "Business.h"



// statics
int Business::count = 1;
std::string Business::attire = "Casual";

// Using constructor delegation
Business::Business(): Business("Not Set","Not Set"){

}

Business::Business(std::string type,std::string name): Business(type,name, "Not Set"){

}

Business::Business(std::string type,std::string name, std::string ceo): I_Business(type), name {name}, ceo {ceo}, id{count} {
  // increment count
  count++;
}

// Getters
std::string Business::getType() const {
  return type;
}

std::string Business::getName() const{
  return name;
}

std::string Business::getCEO() const{
  return ceo;
}

std::string Business::getAttire() const{
  return attire;
}

int Business::getId() const{
  return id;
}

int Business::getCount() const{
  return count;
}

// Setters
void Business::setName(std::string name) {
  this->name = name;
}

void Business::setCEO(std::string ceo){
  this->ceo = ceo;
}

void Business::setType(std::string type){
  this->type = type;
}

//  An implementation of the virtual method that
// prompts the user for values for each instance
// field (setInfo).

void Business::setInfo() {
  std::string type;
  std::string name;
  std::string ceo;

  std::cout << "\n=== Enter Business Details ===" << std::endl;
  std::cout << "Business type: ";
  std::getline(std::cin, type);


  std::cout << "\nBusiness Name: ";
  std::getline(std::cin, name);
  std::cout << "\nBusiness CEO :  ";
  std::getline(std::cin, ceo);
  std::cout << std::endl;

  // Call methods
  setType(type);
  setName(name);
  setCEO(ceo);
}

// Print data
void Business::printInfo(std::ostream &os) const {
  os << "\n=== Business Details ===" << std::endl;
  os << "ID    : " << id << std::endl;
  os << "Attire: " << attire << std::endl;
  os << "Type  : " << type << std::endl;
  os << "Name  : " << name << std::endl;
  os << "CEO   : " << ceo << std::endl;
}

