//subsort.cpp
#include <iostream>
#include "subsort.h"
#include "showmycards.h"
#include "card.h"
using namespace std;
//subsort function replaces the joker
void subsort(int last, int &newpos, card deck[], int n, int num, char col, int sho, int joker[]){
  showmycards(deck,last+1);
  if (n==0){
    cout << "Where do you want to put a white joker tile? (leftmost =1)" << endl;
  }
  else{
    cout << "Where do you want to put a black joker tile? (leftmost =1)" << endl;
  }
  while (!(cin>>newpos)|| newpos>last+1 || newpos<1){
    cout << "Please input a vaild number.\nPosition?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }

  for (int i=last; i>=newpos-1; i--){
    if (joker[2]==i){
      joker[2]=joker[2]+1;
    }
    if (joker[3]==i){
      joker[3]=joker[3]+1;
    }
    deck[i].number = deck[i-1].number;
    deck[i].color = deck[i-1].color;
    deck[i].shown = deck[i-1].shown;
  }
  deck[newpos-1].number = num;
  deck[newpos-1].color = col;
  deck[newpos-1].shown = sho;
}
