
#include "student.h"
#include <string>
#include <cstring>
#include <sstream>

Student::Student(const char * const name, int perm) {
  this->name=NULL;
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  perm=permNumber;
}

void Student::setName(const char * const name) {
  if(this->name!=NULL){
    
    delete [] this->name;
  }
  this->name=NULL;
  this->name = new char[strlen(name)+1];
  strcpy(this->name,name);
}


Student::Student(const Student &orig) {
  this->name=NULL;
  this->setName(orig.getName());
  this->setPerm(orig.getPerm());
}

Student::~Student() {
  delete [] name;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this){
    return (*this);
  }

  if(this->name!=NULL)
    delete [] this->name;
    
  this->name=NULL;
  this->setName(right.getName());
  this->setPerm(right.getPerm());

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  std::ostringstream oss;

  oss<<"["
     <<this->getName()<<","
     <<this->getPerm()<<"]";
  return oss.str();
}

