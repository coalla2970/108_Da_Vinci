//newcardinfo.cpp
#include <iostream>
#include "newcardinfo.h"
#include "card.h"
using namespace std;

void newcardinfo(card &newcard, card playercards[], int numberofcards){
  cout << "saving new card info..." << endl;
  newcard.color = playercards[numberofcards-1].color;
  newcard.number = playercards[numberofcards-1].number;
  newcard.shown = playercards[numberofcards-1].shown;
}
