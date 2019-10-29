#include "GenQueue.h"
//#include "GenLinkedList.h"
#include <iostream>
using namespace std;

int main(){
  /**
  GenLinkedList<int> myList;
  myList.insertBack(1);
  myList.insertBack(2);
  myList.insertBack(3);
  cout << myList.removeFront() << endl;

  cout << myList.removeFront() << endl;
  myList.printList();
  **/


  GenQueue<int> myQueue;
  myQueue.insert(1);
  myQueue.insert(2);
  myQueue.insert(3);
  
  cout << myQueue.remove() << endl;
  cout << myQueue.remove() << endl;
  cout << myQueue.remove() << endl;


}
