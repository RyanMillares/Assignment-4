#include <iostream>
#include "Student.h"
#include "Window.h"
#include "GenQueue2.h"
using namespace std;
class Register{
public:

  Register(); //default constructor
  Register(int num, string fileName); //overloaded,takes number of windows and fileName
  ~Register(); //deconstructor

  void simulate(); //runs whole simulation loop
  void printData(); //prints all statistics at end
  //void newStudents();
  void incrementWait(); //increments wait time of all students in queue
  void incrementIdle(); //increments idle time of all open windows
  void removeAndDrop(); //opens up windows that are done with students
  void fillWindows(); //fills any open windows students in queue
  //lol
  bool stillStudents(); //experiment
  void storeVals(); //moves all values from queues/object arrays to int arrays and sorts them


  double meanWait(); //returns mean wait time
  double medianWait(); //returns median wait time
  int longestWait(); //returns longest wait time
  int waitOverTen(); //returns number of students who waited over ten minutes

  double meanIdle(); //returns mean window idle time
  int longestIdle(); //returns longest window idle time
  int idleOverFive(); //returns number of windows idle for over 5 minutes


private:
  GenQueue2<Student> *myQueue; //queue that holds new studends
  GenQueue2<int> *waitTimes; //queue that stores final wait time of students

  Window* windowArray; //array storing each Window object
  int* studentArray; //array that stores the remaining time needed for students at fillWindows
  //is parallel to windowArray
  int* waitCalcs; //array that the waitTimes pushes data to for sorting
  int* idleCalcs; //array that all idle times are pushed to for sorting

  int totalStudents; //total number of students passed through
  int totalWindows; //total number of windows initialized
  string file; //passed in string for filena,me
  int time; //represents clock ticks



};
