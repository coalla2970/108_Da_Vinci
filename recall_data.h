//recall_data.h

#ifndef RECALL_DATA_H
#define RECALL_DATA_H
#include "card.h"
#include <iostream>
using namespace std;

void recall_data(card cards1[], card cards2[], card deck[],int &numbercards1, int &numbercards2,
int &password1, int &password2, string &player1, string &player2, int joker1[], int joker2[], int &turn, string &recall);

#endif
