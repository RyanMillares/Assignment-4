//#include "GenQueue2.h"
//#include "GenLinkedList.h"
#include "Register.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv){
  string input;
  int windows;
  if(argc > 1){
    input = argv[1];
  }
  else{
    cout << "No command line argument provided, try again." << endl;
    exit(0);
  }
  ifstream check(input);
  if(check){
    string numWindow;
    getline(check, numWindow);
    windows = stoi(numWindow);
    check.close();
    //read in the given file and take in the first line to initialize number of windows



  }
  else{
    cout << "[Error] Could not find file: " << input << endl;
    exit(0);
  }

  Register office(windows, input); //constructor
  office.simulate(); //simulates everything basically






}
