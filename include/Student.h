#include <iostream>
using namespace std;
class Student{
public:
  Student();
  Student(int time);
  int getTime();
private:
  int neededTime;
  int waitTime;
};
