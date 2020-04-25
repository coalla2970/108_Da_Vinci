//primarysort.cpp
#include <iostream>
#include "primarysort.h"
#include "card.h"
using namespace std;

void primarysort(card deck[], int numberofcards){
  int bigger,switchcolor;
  for (int i=0; i<numberofcards; i++){
    for (int j=i+1; j<numberofcards; j++){
      if (deck[i].number > deck[j].number){
        bigger=deck[i].number;
        deck[i].number=deck[j].number;
        deck[j].number=bigger;
        switchcolor=deck[i].color;
        deck[i].color=deck[j].color;
        deck[j].color=switchcolor;
      }
      else if (deck[i].number == deck[j].number){
        if (deck[i].color == 'B' && deck[j].color == 'W'){
          deck[i].color = 'W';
          deck[j].color = 'B';
        }
      }
    }
  }
}
