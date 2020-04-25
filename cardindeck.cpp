//cardindeck.cpp
#include <iostream>
#include "cardindeck.h"
#include "tools.h"
#include "card.h"
using namespace std;

int cardindeck(card deck[], card temp){
  int check = -1;
  for (int i=0; i<24; i++){
    if (deck[i].color == temp.color && deck[i].number == temp.number && deck[i].shown == temp.shown){
      check = i;
      break;
    }
    else
      pass();
  }
  return check;
}
