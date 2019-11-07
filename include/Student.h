#include <iostream>
using namespace std;
class Student{
public:
  Student(); //default constructor
  Student(int needs); //overloaded construct. passing in needed time
  void setTime(int time); //mutator for wait time
  int getTime(); //accessor for wait time
  void setCount(int count); //mutator for needed time
  int getCount();//accessor for needed time
private:
  int neededTime; //amount of time needed at window
  int waitTime; //amount of time waiting in queue
};
