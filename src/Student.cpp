#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(){
  waitTime = 0;
  neededTime = 0;
}
Student::Student(int needs){
  neededTime = needs;
  waitTime = 0;
}
void Student::setTime(int time){
  waitTime = time;
}

int Student::getTime(){
  return waitTime;
}
void Student::setCount(int count){
  neededTime = count;
}

int Student::getCount(){
  return neededTime;
}
