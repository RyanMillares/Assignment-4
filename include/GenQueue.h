#include "GenLinkedList.h"
#include <iostream>
using namespace std;

template <class T>
class GenQueue{
public:
  GenQueue();
  ~GenQueue();

  void insert(T data);
  T remove();
  T peek();
  bool isEmpty();
  int getSize();

  GenLinkedList<T> *myList;
private:
  int numElements;
};

template <class T>
GenQueue<T>::GenQueue(){
  myList = new GenLinkedList<T>();
  numElements = 0;
}

template <class T>
GenQueue<T>::~GenQueue(){
  delete myList;
}

template <class T>
void GenQueue<T>::insert(T data){
  myList->insertBack(data);
  numElements++;

}
template <class T>
T GenQueue<T>::remove(){
  numElements--;
  return myList->removeFront();
}
template <class T>
T GenQueue<T>::peek(){
  return myList->front;
}
template <class T>
bool GenQueue<T>::isEmpty(){
  return (numElements==0);
}
template <class T>
int GenQueue<T>::getSize(){
  return numElements;
}
