//#include "GenQueue2.h"
//#include "GenLinkedList.h"
#include "Register.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv){
  string input;
  int windows;
  if(argc > 1){
    input = argv[1];
  }
  else{
    cout << "No command line argument provided, try again." << endl;
    exit(0);
  }
  ifstream check(input);
  if(check){
    string numWindow;
    getline(check, numWindow);
    windows = stoi(numWindow);
    check.close();



  }
  else{
    cout << "[Error] Could not find file: " << input << endl;
    exit(0);
  }

  Register office(windows, input);
  office.simulate();

  //ask user for


  /** //for linked list testing
  GenLinkedList<int> myList;
  myList.insertBack(1);
  myList.insertBack(2);
  myList.insertBack(3);
  cout << myList.removeFront() << endl;

  cout << myList.removeFront() << endl;
  myList.printList();
  **/

  /** //for array-based queue testing
  GenQueue2<int> *myQueue = new GenQueue2<int>(10);
  myQueue->insert(1);
  myQueue->insert(2);
  myQueue->insert(3);

  cout << myQueue->peek() << endl;
  while(!myQueue->isEmpty()){
    cout << myQueue->remove() << endl;

  }
  //cout << myQueue->remove() << endl;
  //cout << myQueue->remove() << endl;
**/

}
