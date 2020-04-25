//save_data.h

#ifndef SAVE_DATA_H
#define SAVE_DATA_H
#include "card.h"
#include <iostream>
using namespace std;

void save_data(card cards1[], card cards2[], card deck[], int numbercards1, int numbercards2,
int password1, int password2, string player1, string player2, int joker1[], int joker2[], int turn, char &save);

#endif
