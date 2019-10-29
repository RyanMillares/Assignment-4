#include <iostream>
#include "GenLinkedList.h"
#include "Student.h"

template <class T>
class GenQueue{
  public:
    GenQueue();
    //GenQueue(int maxSize);
    ~GenQueue();
    void insert(T data);
    T remove();
    T peek();
    bool isFull();
    bool isEmpty();
    int getSize();
  private:
    int numElements;
    GenLinkedList<T> *myList;
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
  if(!numElements == 0){
    return myList->removeFront();

  }
  else{
    cout << "Queue is empty, cannot remove." << endl;
    exit(0);
  }
  numElements--;
}

template <class T>
T GenQueue<T>::peek(){
  //nani
  return myList->tail->data;
}
template <class T>
bool GenQueue<T>::isFull(){
  //more nani
}
template <class T>
bool GenQueue<T>::isEmpty(){
  if(numElements == 0){
    return true;
  }
  else{
    return false;

  }
}
template <class T>
int GenQueue<T>::getSize(){
  return numElements;
}
