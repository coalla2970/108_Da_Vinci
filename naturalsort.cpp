//naturalsort.cpp
#include <iostream>
#include "naturalsort.h"
#include "card.h"
using namespace std;

void naturalsort(card deck[], int first, int last, int &posnew, int numberofcards){
  int num;
  char col;
  num=deck[numberofcards-1].number;
  col=deck[numberofcards-1].color;
  for (int i=first; i<=last; i++){
    if (deck[i].number > num){
      posnew=i;
      break;
    }
    else if (deck[i].number == num){
      if(col == 'W'){
        posnew=i;
        break;
      }
      else{
        posnew=i+1;
        break;
      }
    }
    else {
      continue;
    }
  }
}
