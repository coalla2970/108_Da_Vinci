//checkpassword.cpp
#include <iostream>
#include "checkpassword.h"
#include "card.h"
using namespace std;
//checkpassword function checks whether user's input is same as his/her password.
void checkpassword(string player,int password){
  int inpass;
  cout << "Enter "<< player << "'s password:";
  while (!(cin>>inpass)){
    cout << "Please input a vaild number.\nPassword?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }
  while(inpass!=password){
    cout << "Wrong password, try again\nEnter the password:";
    while (!(cin>>inpass)){
      cout << "Please input a vaild number.\nPassword?";
      cin.clear();
      while (cin.get() != '\n'){
      }
    }
  }
}
