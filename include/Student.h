#include <iostream>
using namespace std;
class Student{
public:
  Student();
  Student(int needs);
  void setTime(int time);
  int getTime();
  void setCount(int count);
  int getCount();
private:
  int neededTime;
  int waitTime;
};
