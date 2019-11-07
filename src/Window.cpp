#include "Window.h"
#include <iostream>
using namespace std;
Window::Window(){
  status = false;
  idleTime = 0;
}
Window::~Window(){

}

void Window::updateStatus(bool isFull){
  /**
  if(status){
    status = false;
  }
  else{
    status = true;
  }
  **/
  status = isFull;

}
bool Window::getStatus(){
  return status;
}

void Window::setIdle(int t){
  idleTime = 0;
}
void Window::increment(){
  idleTime++;
}
int Window::getIdle(){
  return idleTime;
}
