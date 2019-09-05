//Samuel Barnes
//Lab5
//This program is the same as last week but also runs 
//the queue reversed using recursion
#include <iostream>

using namespace std;


class PayRoll {

                 private:

                   string name;

                   double rate;

                   double hours;

                 public:

                   double getTotal() {

  return rate * hours;

  }
  PayRoll();
  PayRoll(string, double, double);
  


                   double getRate() {

  return rate;

  }

                   double getHours() {

  return hours;

  }

                   void setRate(double r) {

  rate = r;

  }

                   void setName(string n) {

  name = n;

  }

                   void setHours(double hr) {

  hours = hr;

  }

  string getName() {

  return name;

  }
  
  

};
PayRoll::PayRoll() {
    
  }
  PayRoll::PayRoll(string n, double r, double hr) {
   name = n;
   rate = r;
   hours = hr;
  }
  





class PayRollQueue {
private:
  struct QueueNode {
    PayRoll p;
    QueueNode* next;
  };
      QueueNode* recursiveReverse(QueueNode* start);

  QueueNode* head = nullptr;
public:
  void enqueue(PayRoll p);
  void print();
  PayRoll dequeue();
  int length();
  void reverse();
  //void reverse();
  
};

PayRollQueue::QueueNode* PayRollQueue::recursiveReverse(PayRollQueue::QueueNode* start) {
  QueueNode* temp = new QueueNode;
  if(start->next == nullptr || start == nullptr) {
    return start;
  }
  else {
    temp = recursiveReverse(start->next);
    start->next->next = start;
    start ->next = nullptr;
    return temp;
  }
    
    
   
  
  
  
}
void PayRollQueue::reverse() {
  
 head = recursiveReverse(head);
  //recursiveReverse(head);
}



void PayRollQueue::print() {
  QueueNode* cursor = new QueueNode;
  cursor = head;
  
  while(cursor != nullptr) {
  std::cout << "Name: " << cursor->p.getName() << std::endl << "Rate: " << cursor->p.getRate() << std::endl << "Hours: " <<
  cursor->p.getHours() <<std::endl << "Total: $" << cursor->p.getTotal() << std::endl;
  cursor = cursor->next;
}
}
  
  int PayRollQueue::length() {
    QueueNode* cursor = new QueueNode;
    int length = 0;
    cursor = head;
    while(cursor != nullptr) {
      cursor = cursor->next;
      length++;
    }
    return length;
  }
  
  void PayRollQueue::enqueue(PayRoll p) {
    QueueNode* newNode = new QueueNode;
  newNode->p = p;
  newNode->next = nullptr;

  if(head == nullptr){ // List is empty
    head = newNode;
    return;
  }

  QueueNode* cursor = head;
  while (cursor->next) // cursor != nullptr
    cursor = cursor->next;

  cursor->next = newNode;
}

PayRoll PayRollQueue::dequeue() {
 
  QueueNode* temp;
  PayRoll c;
  temp = head;
  head = head->next;
  delete temp;
  return c;
}
  
  
  

int main() { 

PayRoll pay1;
PayRoll pay2;
PayRoll pay3;
PayRoll pay4;
PayRoll pay5;
PayRoll pay6;
PayRoll pay7;
PayRollQueue list;


//PayRollQueue list;


pay1.setName("Samuel");

pay1.setHours(30);

pay1.setRate(12.75);

list.enqueue(pay1);

//pay1.printCheck();


pay2.setName("Joe");

pay2.setHours(20);

pay2.setRate(14.0);

list.enqueue(pay2);

// list.printPayChecks();
//pay2.printCheck();


pay3.setName("Josh");
pay3.setHours(40);

pay3.setRate(17.75);

list.enqueue(pay3);

//pay3.printCheck();

pay4.setName("Ian");

pay4.setHours(35);

pay4.setRate(19.50);

list.enqueue(pay4);

//pay4.printCheck();


pay5.setName("Taylor");

pay5.setHours(30);

pay5.setRate(20.25);

list.enqueue(pay5);

// list.printPayChecks();
//pay5.printCheck();


pay6.setName("Mark");

pay6.setHours(33);

pay6.setRate(25.75);

list.enqueue(pay6);

// list.printPayChecks();
//pay6.printCheck();


pay7.setName("Nicole");

pay7.setHours(37);

pay7.setRate(50.75);

list.enqueue(pay7);

//list.printPayChecks();
//pay7.printCheck();
PayRoll temp;

list.print();
list.reverse();
std::cout << "Function Reversed\n";
std::cout << "====================================\n";
list.print();

while(list.length() > 0) {
  list.dequeue();
}






}