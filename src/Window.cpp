#include "Window.h"
#include <iostream>
using namespace std;
Window::Window(){
  status = false;
  idleTime = 0;
}
Window::~Window(){
  //idk what goes here, nothing to delete
}

void Window::updateStatus(bool isFull){

  status = isFull;

}
bool Window::getStatus(){
  return status;
}

void Window::setIdle(int t){
  idleTime = 0;
}
int Window::getIdle(){
  return idleTime;
}
//All basic accessor/mutator fuctions

//increments the idle time
void Window::increment(){
  idleTime++;
}
