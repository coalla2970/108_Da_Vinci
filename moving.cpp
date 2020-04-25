//moving.cpp
#include <iostream>
#include "moving.h"
#include "showmycards.h"
#include "tools.h"
#include "card.h"
using namespace std;

void moving(card deck[], int numberofcards, int &posanswer){
  int last=numberofcards-1;
  int num;
  char col;
  num = deck[last].number;
  col = deck[last].color;
  showmycards(deck,numberofcards);
  cout << "Please choose a position of a new tile! (leftmost=1):";
  while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
    cout << "Please input a vaild number.\nPosition?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }

  for (int l=0; l<2; l++){
    for (int i=posanswer-1; i<last ; i++){
      if ((num > deck[i].number) && deck[i].number!=12){
        cout << "Error1 Invalid move. Please consider the tile order! Position? (leftmost=1):";
        while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
          cout << "Please input a vaild number.\nPosition?";
          cin.clear();
          while (cin.get() != '\n'){
          }
        }
        i=posanswer-2;
        continue;
      }
      else if(deck[i].number == num){
        if(deck[i].color == 'W' && col == 'B'){
          cout << "Error 2 Invalid move. Please consider the tile order! Position? (leftmost=1):";
          while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
            cout << "Please input a vaild number.\nPosition?";
            cin.clear();
            while (cin.get() != '\n'){
            }
          }
          i=posanswer-2;
          continue;
        }
        else{
          continue;
        }
      }
    }
    if(posanswer==1){
      break;
    }
    else{
      pass();
    }
    for (int m=0; m<posanswer-1; m++){
      if ((deck[m].number > num && deck[m].number != 12) || deck[posanswer-1].number < num){
        cout << "Error 3 Invalid move. Please consider the tile order! Position? (leftmost=1):";
        while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
          cout << "Please input a vaild number.\nPosition?";
          cin.clear();
          while (cin.get() != '\n'){
          }
        }
        m=-1;
        continue;
      }
      else if (deck[m].number == num){
        if(deck[m].color == 'W' && col == 'B'){
          continue;
        }
        else{
          cout << "Error 4 Invalid move. Please consider the tile order! Position? (leftmost=1):";
          while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
            cout << "Please input a vaild number.\nPosition?";
            cin.clear();
            while (cin.get() != '\n'){
            }
          }
          m=-1;
          continue;
        }
      }
      else continue;
    }
  }
}
