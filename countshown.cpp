//countshown.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "countshown.h"
#include "card.h"
using namespace std;

//counts the number of tiles shown to the opponent
//determines the winner if all the tiles in the deck runs out
int countshown(card cards[], int numberofcards){
  int count = 0;
  for (int i=0; i<numberofcards; i++){
    if (cards[i].shown == 1){
      count++;
    }
    else{
      continue;
    }
  }
  return count;
}
