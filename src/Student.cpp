#include "Student.h"
#include <iostream>
using namespace std;
Student::Student(){
  waitTime = 0;
  neededTime = 0; //default both to 0
}
Student::Student(int needs){
  neededTime = needs;
  waitTime = 0; //set needed time to param. and wait to zero
}
void Student::setTime(int time){
  waitTime = time; //update the wait time
}

int Student::getTime(){
  return waitTime; //return wait time
}
void Student::setCount(int count){
  neededTime = count; //update needed time
}

int Student::getCount(){
  return neededTime; //literally what the line says
}
