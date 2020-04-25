//deal.cpp

#include <iostream>
#include <iomanip>
#include "deal.h"
#include "cardindeck.h"
#include "card.h"
using namespace std;

void deal(card deck[], card cards[], int &numberofcards){
  srand(time(NULL));
  int numcard = numberofcards + 1;
  string option;
  card temp;
  bool deckhaswhite;
  bool deckhasblack;
  for (int i=0; i<24; i++){
    if (deck[i].color == 'W'){
      deckhaswhite = true;
      break;
    }
  }
  for (int i=0; i<24; i++){
    if (deck[i].color == 'B'){
      deckhasblack = true;
      break;
    }
  }
  while(numberofcards != numcard){
    srand(time(NULL));
    cout << "Which Color do you want to pick? (B/W): ";
    cin >> option;
    while (true){
      if (option == "W"){
        temp.color = 'W';
        temp.number = rand()%13;
        temp.shown = 0;
        if (deckhaswhite){
          if (cardindeck(deck,temp)>=0){
            deck[cardindeck(deck,temp)].color = 'N';
            deck[cardindeck(deck,temp)].number = 100;
            deck[cardindeck(deck,temp)].shown = 100;
            cards[numberofcards].color = temp.color;
            cards[numberofcards].number = temp.number;
            cards[numberofcards].shown = temp.shown;
            numberofcards++;
            cout << "choice made!"<< endl;
            srand(time(NULL));
            break;
          }
          else
            continue;
        }
        else{
          cout << "deck has no more white!" << endl;
          break;
        }
      }
      else if (option == "B"){
        temp.color = 'B';
        temp.number = rand()%13;
        temp.shown = 0;
        if (deckhasblack){
          if (cardindeck(deck,temp)>=0){
            deck[cardindeck(deck,temp)].color = 'N';
            deck[cardindeck(deck,temp)].number = 100;
            deck[cardindeck(deck,temp)].shown = 100;
            cards[numberofcards].color = temp.color;
            cards[numberofcards].number = temp.number;
            cards[numberofcards].shown = temp.shown;
            numberofcards++;
            cout << "choice made!" << endl;
            srand(time(NULL));
            break;
          }
          else
            continue;
        }
        else{
          cout << "deck has no more black!" << endl;
          break;
        }
      }
      else {
        cout << "You have put invalid choice! Please put a choice again!" << endl;
        break;
      }
    }
  }
}
