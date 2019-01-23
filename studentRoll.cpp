#include <string>
#include "studentRoll.h"
#include <sstream>
StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *q=new Node();
  q->s=new Student(s);
  q->next=NULL;
  if(head==NULL && tail==NULL){
    head=q;
    tail=q;
  }
  else{
    tail->next=q;
    tail=q;
  }
  q=NULL;
  delete q;
}

std::string StudentRoll::toString() const {
  std::ostringstream oss;
  Node* q=head;
  oss<<"[";
  while (q!=NULL){
    oss<<q->s->toString();
    if(q->next!=NULL)
      oss<<",";
    q=q->next;
  }
  oss<<"]";
  return oss.str();
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head=tail=NULL;
  Node *q=orig.head;
  while(q!=NULL){
    insertAtTail(*(q->s));
    q=q->next;
  }
  delete q;
}

StudentRoll::~StudentRoll() {
  while(head){
    Node* x=head;
    head=head->next;
    delete x;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);
  head=tail=NULL;
  Node *q=right.head;
  while(q!=NULL){
    insertAtTail(*(q->s));
    q=q->next;
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





