#include <iostream>
using namespace std;
template <class T>
class GenQueue2{
  public:
    GenQueue2();
    GenQueue2(int maxSize);
    ~GenQueue2();
    void insert(T data);
    T remove();
    T peek();
    bool isFull();
    bool isEmpty();
    int getSize();
    
    int head;
    int tail;
    int mSize;
    int numElements;
    T *myQueue;

  private:


};

template <class T>
GenQueue2<T>::GenQueue2(){
  myQueue = new T[25];
  mSize = 25;
  numElements = 0;
  head = 0;
  tail = -1;

}
template <class T>
GenQueue2<T>::GenQueue2(int maxSize){
  myQueue = new T[maxSize];
  mSize = maxSize;
  numElements = 0;
  head = 0;
  tail = -1;

}
template <class T>
GenQueue2<T>::~GenQueue2(){
  delete myQueue;

}
template <class T>
void GenQueue2<T>::insert(T data){
  if(isFull()){
    T* newArr = new T[2*mSize];
    for(int i = 0; i < mSize; ++i){
      newArr[i] = myQueue[i];
    }
    mSize *= 2;
    delete myQueue;
    myQueue = newArr;
  }
  myQueue[++tail] = data;
  ++numElements;
}
template <class T>
T GenQueue2<T>::remove(){
  if(numElements > 0){
    T c;
    c = myQueue[head];
    ++head;
    --numElements;
    return c;
  }

  else{
    cout << "Queue is empty. Remove failed." << endl;
    exit(0);

  }
}

template <class T>
T GenQueue2<T>::peek(){
  if(numElements > 0){
    return myQueue[head];

  }
  else{
    cout << "Queue is empty. Peek failed." << endl;
    exit(0);

  }
}

template <class T>
bool GenQueue2<T>::isFull(){
  return (numElements == mSize);
}
template <class T>
bool GenQueue2<T>::isEmpty(){
  return (numElements == 0);
}

template <class T>
int GenQueue2<T>::getSize(){
  return numElements;
}
