#include <iostream>
using namespace std;
class Window{
public:
  Window();
  ~Window();

  void updateStatus(bool isFull);
  bool getStatus();
  void setIdle(int t);
  int getIdle();
  void increment();

private:
  int idleTime;
  bool status; //true if talking with student;
};
