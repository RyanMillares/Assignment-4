#include <iostream>
#include "Student.h"
#include "Window.h"
#include "GenQueue2.h"
using namespace std;
class Register{
public:

  Register();
  Register(int num, string fileName);
  ~Register();

  void simulate();
  void printData();
  //void newStudents();
  void incrementWait();
  void incrementIdle();
  void removeAndDrop();
  void fillWindows();
  //lol
  bool stillStudents();
  void storeVals();

  double meanWait();
  double medianWait();
  int longestWait();
  int waitOverTen();

  double meanIdle();
  int longestIdle();
  int idleOverFive();

private:
  GenQueue2<Student> *myQueue;
  GenQueue2<int> *idleTimes;
  GenQueue2<int> *waitTimes;

  Window* windowArray;
  int* studentArray;
  int* waitCalcs;
  int* idleCalcs;

  int totalStudents;
  int totalWindows;
  string file;
  int state;
  int time;
  int nextTime;



};
