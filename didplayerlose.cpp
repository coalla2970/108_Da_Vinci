//didplayerlose.cpp

#include <iostream>
#include "didplayerlose.h"
#include "card.h"
using namespace std;
//checks whether the player lost (has shown all the tiles to his/her opponent)
bool didplayerlose(card playercard[], int numberofcards){
  bool decision = true;
  for (int i=0; i<numberofcards; i++){
    if (playercard[i].shown == 0){
      decision = false;
      break;
    }
    else
      continue;
  }
  return decision;
}
