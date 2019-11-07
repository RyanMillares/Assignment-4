#include <iostream>
#include "ListNode.h"
using namespace std;

template <class T>
class GenLinkedList{
private:

  unsigned int size;
public:
  GenLinkedList();
  ~GenLinkedList();
  //to make peek() easier maybe
  ListNode<T> *front;
  ListNode<T> *tail;

  void insertFront(T d);
  void insertBack(T d);
  T removeFront();
  T removeBack();
  T deletePos(int pos);
  int find(T d);

  bool isEmpty();
  void printList();
  unsigned int getSize();

};

template <class T>
GenLinkedList<T>::GenLinkedList(){
  front = NULL; //nullptr
  tail = NULL;
  size = 0;
}
template <class T>
GenLinkedList<T>::~GenLinkedList(){
  if(front == NULL){
    delete front;
    delete tail;
  }

}
template <class T>
unsigned int GenLinkedList<T>::getSize(){
  return size;
}
template <class T>
bool GenLinkedList<T>::isEmpty(){
  return (size == 0);
}
template <class T>
void GenLinkedList<T>::printList(){

  ListNode<T> *curr = new ListNode<T>();
  curr = front;
  while(curr != NULL){
    cout << curr->data << endl;
    //cout << curr->next->data << endl;
    curr = curr->next;
  }

}
template <class T>
void GenLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);

  node->next = front;
  front = node;
  if(tail == NULL){
    tail = node;
  }
  size++;
}
template <class T>
void GenLinkedList<T>::insertBack(T d){
  if(tail == NULL){
    insertFront(d);
  }
  else{
    ListNode<T> *node = new ListNode<T>(d);
    node->prev = tail;
    tail->next = node;
    tail = node;

  }
  size++;

}
template <class T>
T GenLinkedList<T>::removeFront(){
  if(size > 0){
    int tap = front->data;
    ListNode<T> *replace = front;
    front = front->next;
    front->prev = NULL;
    replace->next = NULL;
    delete replace;
    size--;
    return tap;
  }
  else{
    cout << "List is empty." << endl;
    exit(0);
  }


}
template <class T>
T GenLinkedList<T>::removeBack(){
  if(size > 0){
    int tap = tail->data;
    ListNode<T> *replace = tail;
    tail = tail->prev;
    cout << "lol" << endl;
    //tail->next = NULL;
    replace->prev = NULL;
    delete replace;
    size--;
    return tap;
  }
  else{
    cout << "List is empty." << endl;
    exit(0);
  }

}
template <class T>
T GenLinkedList<T>::deletePos(int pos){
  if(pos >= size){
    cout << "Error: Tried accessing item at position " << pos << " and available positions are 0-" << (size-1) << endl;
    exit(0);
  }
  int idx = 0;
  ListNode<T> *curr = front;
  ListNode<T> *prev = front;
  while(idx != pos){
    prev = curr;
    curr = curr->next;
    idx++;
  }
  //add checks for valid poss and curr != nullptr
  if(curr == tail){
    tail = prev;
    curr->next = NULL;
    curr->prev = NULL;
  }
  else{
    prev->next = curr->next;

    curr->next->prev = prev;
    curr->next = NULL;
    curr->prev = NULL;
  }

  int temp = curr->data;
  delete curr;
  size--;
  return temp;
}
template <class T>
int GenLinkedList<T>::find(T d){
  int idx = 0;
  ListNode<T> *curr = front;

  while(curr != NULL){
    if(curr->data == d){
      return idx;
      //break
    }

    idx++;
    curr = curr->next;
  }
  if(curr == NULL){
    idx = -1;
  }
  return idx;
}
