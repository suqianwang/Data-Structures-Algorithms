#include "TemplateDoublyLinkedList.h"
#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

using namespace std;

int main () {
    
    string str = string();
    cout << str << endl;
    
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  TemplateDoublyLinkedList<string> dll;
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertLast(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    stringstream ss;
    ss << i;
    dll.insertFirst(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  // Copy to a new list
  cout << "Copy to a new list" << endl;
  TemplateDoublyLinkedList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  // Assign to another new list
  cout << "Assign to another new list" << endl;
  TemplateDoublyLinkedList<string> dll3;
  dll3=dll;
  cout << "list3: " << dll3 << endl << endl;
  
  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << endl;
  
  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

    // more testing...
    // add tests for insertAfter, insertBefore
    cout << "Insert 59 after the 1'th node in list2" << endl;
    dll2.insertAfter(*dll2.getFirst(), "59");
    cout << "list2: " << dll2 << endl << endl;
    
    cout << "Insert 88 before the 1'th node in list2" << endl;
    dll2.insertBefore(*dll2.getFirst(), "88");
    cout << "list2: " << dll2 << endl << endl;
    
    // add tests for removeAfter, removeBefore
    cout << "Remove the node after the 1'th node in list3" << endl;
    dll3.removeAfter(*dll3.getFirst());
    cout << "list3: " << dll3 << endl << endl;
    
    cout << "Remove the node before the last node in list3" << endl;
    dll3.removeBefore(*dll3.getAfterLast()->prev);
    cout << dll3 << endl << endl;
    
    // add tests for DoublyLinkedListLength
    cout << "list: " << dll << endl;
    cout << "The length for list is " << DoublyLinkedListLength(dll) << endl << endl;
    cout << "list2: " << dll2 << endl;
    cout << "The length for list2 is " << DoublyLinkedListLength(dll2) << endl << endl;
    cout << "list3: " << dll3 << endl;
    cout << "The length for list3 is " << DoublyLinkedListLength(dll3) << endl << endl;
    return 0;

}
