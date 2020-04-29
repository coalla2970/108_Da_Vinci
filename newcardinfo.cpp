//newcardinfo.cpp
#include <iostream>
#include "newcardinfo.h"
#include "card.h"
using namespace std;

//sending new tile's information for use
//this will be used for revealing a player's card if his/her guess is not correct
void newcardinfo(card &newcard, card playercards[], int numberofcards){
  newcard.color = playercards[numberofcards-1].color;
  newcard.number = playercards[numberofcards-1].number;
  newcard.shown = playercards[numberofcards-1].shown;
}
