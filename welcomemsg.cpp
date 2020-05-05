//welcomemsg.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "tools.h"
#include "welcomemsg.h"
#include "card.h"
using namespace std;
//welcomemsg function asks player's name and password and confirm them
void welcomemsg(string &player1, string &player2, int password[]){
  string playername;
  cout << "< The Da Vinci Code Game >\nWELCOME!" << endl;
  for (int i=1; i<=2; i++){
    int pass=0, confirmpass=1;
    cout << "Player " << i << ", What is your name?" << endl;
    cin.ignore();
    getline(cin,playername);
    if(i==1){
      player1=playername;
    }
    else{
      player2=playername;
    }
    while (pass!=confirmpass){
      cout << playername <<", please set your own password!(0000-9999)" << endl;
      while (!(cin>>pass)){
        cout << "You can only use integer 0000-9999.\nPassword:\n ";
        cin.clear();
        while (cin.get() != '\n'){
        }
      }
      while (pass>9999 || pass<0){
        cout << "You can only use integer 0000-9999.\nPassword:\n ";
        cin.clear();
        while (!(cin>>pass)){
          cout << "You can only use integer 0000-9999.\nPassword:\n ";
          cin.clear();
          while (cin.get() != '\n'){
          }
        }
      }
      clrscrn();
      cout << "To confirm, please put your password again!" << endl;
      cin >> confirmpass;
      if (pass!=confirmpass){
        cout << "The password is wrong. Please set your password again." << endl;
      }
      else{
        password[i]=pass;
      }
    }
    clrscrn();
  }
}
