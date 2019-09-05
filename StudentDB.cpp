#include<iostream>

class NumberList {
  private:
    struct ListNode{
	    std::string first;
	    std::string last;
	    std::string major;
	    std::string DOB;
      struct ListNode *next;
    };

    ListNode *head;
  
  public:
    NumberList(){ head = nullptr; }
    ~NumberList(){ };

    ListNode* findHead(){
      return head;
    }
    void appendNode(std::string,std::string, std::string, std::string);
    void insertNode(std::string, std::string);
    void deleteNode(std::string);
    bool contains(std::string);
    void displayList() const;
 };

void NumberList::deleteNode(std::string bye){
  ListNode* tmp;
  ListNode* cursor = this->head;

  if ( contains(bye) ){
    if ( this->head->first == bye ){
      tmp = head;
      head = head->next;
      delete tmp;
      return;
    }
    
    cursor = head->next;

    while ( cursor && cursor->first != bye ){
      tmp = cursor;
      cursor = cursor->next;
    }
    
    tmp->next = cursor->next;
    delete cursor;
  } 
  else {
    std::cout << bye << " is not in the list!" << std::endl;
  }
}

void NumberList::insertNode(std::string pre, std::string post){
  ListNode* tmp;
  ListNode* cursor;

  ListNode *newNode = new ListNode;
  newNode->first = post;
  newNode->last = post;
  newNode->major = post;
  newNode->next = nullptr;

  if ( this->contains(pre) ){
    cursor = this->head;
    while ( cursor && cursor->first != pre )
      cursor = cursor->next;

    tmp = cursor->next;
    cursor->next = newNode;
    newNode->next = tmp;
  } else {
    std::cout << pre << " is not an element of the list" << std::endl;
  }
}

bool NumberList::contains(std::string x){
  ListNode* cursor = this->head;

  // Scan the list one at a time
  while (cursor != nullptr){
    // Check if current node has value x
    if ( cursor->first == x ){
	   // std::cout << "Yes!, " << x << " is in the list!\n";
      return true;
    }
    cursor = cursor->next;
  }

  return false;
}

void NumberList::displayList() const{
  ListNode *cursor = this->head;

  std::cout << "=====================" << std::endl;
  while ( cursor != nullptr ){
	   std::cout << cursor->first;
		  std::cout << " " <<cursor->last << std::endl;
		  std::cout <<  cursor->major << std::endl;
		  std::cout << "DOB: " << cursor->DOB << std::endl;
		  std::cout << "==================" << std::endl;

	  cursor = cursor->next;
  }
}

void NumberList::appendNode(std::string firstName, std::string lastName, std::string degree, std::string date){
  ListNode* node = new ListNode;
  node->first = firstName;
  node->last = lastName;
  node->major = degree;
  node->DOB = date;
  node->next = nullptr;

  ListNode* cursor = this->head;
  
  // Check if list is empty
  if ( head == nullptr ){
    this->head = node;
  } else {
    while ( cursor->next != nullptr ){
      cursor = cursor->next;
    }
    // cursor->next points at nullptr
    cursor->next = node;
  } 
}

int main(int argc, char* argv[]){
  NumberList list;
  std::cout << "Welcome to the program!\n";
  if ( false) {
	  printf("%d\n", argc);

	  for( int i=0; i < argc; i++ ){
	    std::cout << argv[i] << std::endl;
	  }
  }
  int menu = 0;
   std::string firstNamee = " ";
	  std::string lastNamee = " ";
	  std::string degree = " ";
	  std::string dob = " ";

  while(menu != 6) {
	  std::cout << "Please choose from the following:\n1. Create a Student\n2. Update a Student\n3. Delete a Student\n4. Display the List\n5. Search the List\n6. Quit the Program\n";
  std::string answer = "YES";
  std::cin >> menu;
 
  if(menu == 1) {
	   std::cout << "Enter the first name of the student you wish to add " << std::endl;
 getline(std::cin, firstNamee);
 getline(std::cin, firstNamee);
 std::cout << "Now enter the last name of the student you wish to add " << std::endl;
 getline(std::cin, lastNamee);
 std::cout << "Now enter the student's date of birth " << std::endl;
 getline(std::cin, dob);
 std::cout << "Finally, enter " << firstNamee << "'s major" << std::endl;
 getline(std::cin, degree);
  list.appendNode(firstNamee,lastNamee, degree, dob);
  list.displayList();
  std::cout << "======================" << std::endl;


  
  }
  else if(menu == 2) {
	  std::cout << "Please enter the first name of the student you wish to update\n";
	  std::string f = " ";
	  std::string lorst = " ";
	  std::string dob = " ";
	  std::string deg = " ";
	  getline(std::cin, f);
	  getline(std::cin, f);
	  list.deleteNode(f);
	  std::string forst = " ";
	  std::cout << "Now enter the new information:\n";
	  std::cout << "Enter the new first name: ";
	  getline(std::cin, forst);
	  std::cout << "How about the last name: ";
	 getline(std::cin, lorst); 
	 std::cout << "Now enter the students degree: ";
	 getline(std::cin, deg);
	 std::cout << "Finally enter the date of birth for the student(mm/dd/yyyy): ";
	 getline(std::cin, dob);
	 list.appendNode(forst, lorst, deg, dob);
	 list.displayList();


	 
	  
  }
  else if(menu == 3) {
	    std::cout << list.findHead() << std::endl;

	  std::cout << "Please enter the first name of the student you want to remove\n";
	  std::string name = " ";
	  getline(std::cin, name);
	  getline(std::cin, name);
	  list.deleteNode(name);
	  

  }
  else if(menu == 4) {
	  list.displayList();
  }
  else if(menu == 5) {
	  std::cout << "Please enter the first name of the student you would wish to search for\n";
	  std::string fName = " ";
	  getline(std::cin, fName);
	  getline(std::cin, fName);

          if(list.contains(fName))
		  std::cout << "Yes!, " << fName << " was found in the list!!!\n";
	  else
		  std::cout << "Nobody by that name exists :(\n";
	 // std::cout << ( list.contains(fName) ? "YES" : "NO" ) <<std::endl;
  }
   else if(menu == 6) {
	  break;
  }
 else {
	  std::cout << "That was not an option from the menu you idiot!\nTRY AGAIN\n";
  }
	  
  }

  return 0;
}
