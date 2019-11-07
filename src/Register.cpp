#include "Register.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
Register::Register(){
  myQueue = new GenQueue<Student>();
  windowArray = NULL;
  studentArray = NULL;
  totalWindows = 0;
  totalStudents = 0;

  file = " ";
}
Register::Register(int num, string fileName){
  myQueue = new GenQueue<Student>();
  waitTimes = new GenQueue<int>();


  windowArray = new Window[num];
  for(int i = 0; i < num; ++i){
    windowArray[i] = Window();
  }

  studentArray = new int[num];
  totalWindows = num;
  totalStudents = 0;
  file = fileName;

}
Register::~Register(){
  delete[] windowArray;
  delete[] studentArray;
  delete waitTimes;
  delete myQueue;

}

void Register::simulate(){
  //Student temp;
  bool hasAdded = false;
  string currentLine;
  int num, hold;

  ifstream stream(file);
  if(stream){
    getline(stream, currentLine);
    //skip over first line, already read in main
    while((getline(stream,currentLine))){
      //read in the current line
      num = stoi(currentLine);
      //store int conversion
      while(time != num){
        time++;

        removeAndDrop();

        //increment all remaining students
        fillWindows();
        incrementIdle();
        incrementWait();


        //once the time matches, add the students to queue
        if(time == num){

          getline(stream,currentLine);
          hold = stoi(currentLine);
          for(int i = 0; i < hold; i++){
            getline(stream,currentLine);

            myQueue->insert(Student(stoi(currentLine)));


          }
        }
        //windowArray[2].setIdle(3);
      }
    }


  }
  else{
    cout << "[Error] Could not find file: " << file << endl;
    exit(0);
  }
  storeVals();
  printData();

  /**
  cout << "\nTotal window idle times: " << endl;
  for(int i = 0; i < totalWindows; ++i){
    cout << "Window " << i << ": "<< windowArray[i].getIdle() << endl;
  }


  cout << "Student Wait Times:" << endl;
  for(int j = 0; j < totalStudents; ++j){
    cout << waitCalcs[j] << endl;
  }
  **/
}

void Register::incrementWait(){

  Student temp;
  for(int i = 0; i < myQueue->getSize(); ++i){
    temp = myQueue->remove();
    temp.setTime((temp.getTime()) + 1);
    myQueue->insert(temp);
  }
  //increment the wait time of all students in the Queue
  //by removing each one, incrementing its waittime,
  //then re-inserting them at the back; this is
  //repeated as many times as the size.
}

void Register::incrementIdle(){
  for(int i = 0; i < totalWindows; ++i){
    if(windowArray[i].getStatus()){
      windowArray[i].increment();
    }
    //incrememnt the idle time of any open window
  }
}

void Register::removeAndDrop(){
  for(int i = 0; i < totalWindows; ++i){
    if(studentArray[i] == 0){
      windowArray[i].updateStatus(false);
      //if a getCount in the studentarray is 0, open the window up
    }
    else{
      studentArray[i]--;
      //else, decrement the amount of time needed
    }

  }

}

void Register::fillWindows(){

  for(int i = 0; i < totalWindows; ++i){
    if(!windowArray[i].getStatus()){
      if(!myQueue->isEmpty()){

        Student temp = myQueue->remove();
        studentArray[i] = temp.getCount();
        waitTimes->insert(temp.getTime());
        windowArray[i].updateStatus(true);
        totalStudents++;
        //removes a student from Queue
        //stores wait time into a queue of wait times
        //puts time needed into an array of ints
        //updates any now occupied window to have true getStatus
        //increments number of students present
      }
    }
  }
}

void Register::printData(){

  cout << "Mean student wait time: " << meanWait() << " minutes"<< endl;
  cout << "Median student wait time: " << medianWait() << " minutes" <<endl;
  cout << "Longest student wait time: " << longestWait() << " minutes" << endl;
  cout << "Number of students waiting over ten minutes: " << waitOverTen() << endl;
  cout << endl;
  cout << "Mean window idle time: " << meanIdle() << " minutes" << endl;
  cout << "Longest window idle time: " << longestIdle() << " minutes" << endl;
  cout << "Number of windows idle for over five minutes: " << idleOverFive() << endl;

  /**
  cout << " " << endl;

  for(int i = 0; i < totalWindows; ++i){
    cout << "Window " << i << ": ";
    if(!windowArray[i].getStatus()){
      cout << "Open" << endl;
    }
    else{
      cout << "Full - Time remaining: " << studentArray[i] <<endl;

    }
  }
  **/

}
//experiment function
bool Register::stillStudents(){
  for(int i = 0; i < totalWindows; ++i){
    if(windowArray[i].getStatus()){
      return true;
    }
  }
  if(!myQueue->isEmpty()){
    return true;
  }
  return false;
  //meant to return true if the queue is occupied or any window is occupied
}

void Register::storeVals(){
  waitCalcs = new int[totalStudents]; //new int array of length
  //equal to number of students
  for(int i = 0; i < totalStudents; ++i){
    waitCalcs[i] = waitTimes->remove();
  }
  sort(waitCalcs, waitCalcs+totalStudents);
  //puts all the wait times into an array and sorts it
  idleCalcs = new int[totalWindows];
  for(int i = 0; i < totalWindows; ++i){
    idleCalcs[i] = windowArray[i].getIdle();
  }
  sort(idleCalcs, idleCalcs+totalWindows);
  //puts all the idle times into an array and sorts it
}

int Register::longestWait(){ //returns last element of sorted array
  //
  return waitCalcs[totalStudents-1];
}

int Register::longestIdle(){
  return idleCalcs[totalWindows-1];
}

double Register::meanWait(){
  double sum1 = 0;
  for(int i = 0; i < totalStudents; ++i){
    sum1 += waitCalcs[i];
  } //total all the values then divide by total amount
  cout << sum1 << endl;
  cout << totalStudents << endl;
  return sum1/totalStudents;
}

double Register::meanIdle(){
  double sum2 = 0;
  for(int i = 0; i < totalWindows; ++i){
    sum2 += idleCalcs[i];
  }
  //total all the values then divide by total amount
  return sum2/totalWindows;
}

double Register::medianWait(){
  int idx;
  if(totalStudents%2 == 0){
    idx = totalStudents/2;
    return (((double)waitCalcs[idx] + waitCalcs[idx + 1])/2);
    //if even, return avg of two middle values

  }
  else{
    return (double)waitCalcs[(idx + 1)/2];
    //if odd number, return the middle
  }
}
int Register::waitOverTen(){
  int count = 0;
  for(int i = 0; i < totalStudents; ++i){
    if(waitCalcs[i] > 10){
      count++; //increment if wait time was over 10min
    }
  }
  return count;
}
int Register::idleOverFive(){
  int count = 0;
  for(int i = 0; i < totalWindows; ++i){
    if(idleCalcs[i] > 5){
      count++; //increment if idle time was over 5min
    }
  }
  return count;
}
