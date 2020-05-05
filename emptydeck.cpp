//emptydeck.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "emptydeck.h"
#include "card.h"
using namespace std;

//checks whether the deck is empty
//important for ending the game if the deck has no more tiles
bool emptydeck(card deck[]){
  bool check = true;
  for (int i=0; i<24; i++){
    if (deck[i].color == 'N'){
      continue;
    }
    else{
      check = false;
      break;
    }
  }
  return check;
}
