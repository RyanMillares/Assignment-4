#include <iostream>
using namespace std;
class Window{
public:
  Window(); //default (and only) constructor
  //no overloaded needed because no window customization
  ~Window(); //deconstructor

  void updateStatus(bool isFull); //set the window status to the parameter
  bool getStatus(); //return the status
  void setIdle(int t); //set the idle time
  int getIdle(); //return the idletime
  void increment(); //increment the idle time
  //probably should have added an increment() to student...

private:
  int idleTime; 
  bool status; //true if talking with student;
};
