//primarydeal.cpp

#include <iostream>
#include <iomanip>
#include "primarydeal.h"
#include "cardindeck.h"
#include "tools.h"
#include "card.h"
using namespace std;

void primarydeal(card deck[], card cards1[], card cards2[], string player1, string player2,
int &numberofcards){
srand(time(NULL));
string option;
card temp;
for (int i=1; i<=2; i++){
  while(numberofcards<4){
    srand(time(NULL));
    if (i==1){
      cout << player1 <<", Which Color do you want to pick? (B/W): ";
    }
    else{
      cout << player2 <<", Which Color do you want to pick? (B/W): ";
    }
    cin >> option;
    while (true){
      if (option == "W"){
        temp.color = 'W';
        temp.number = rand()%13;
        temp.shown = 0;
        if (cardindeck(deck,temp)>=0 && i==1){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards1[numberofcards].color = temp.color;
          cards1[numberofcards].number = temp.number;
          cards1[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!"<< endl;
          srand(time(NULL));
          break;
        }
        else if (cardindeck(deck,temp)>=0 && i==2){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards2[numberofcards].color = temp.color;
          cards2[numberofcards].number = temp.number;
          cards2[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!"<< endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else if (option == "B"){
        temp.color = 'B';
        temp.number = rand()%13;
        temp.shown = 0;
        if (cardindeck(deck,temp)>=0 && i==1){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards1[numberofcards].color = temp.color;
          cards1[numberofcards].number = temp.number;
          cards1[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!" << endl;
          srand(time(NULL));
          break;
        }
        else if (cardindeck(deck,temp)>=0 && i==2){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards2[numberofcards].color = temp.color;
          cards2[numberofcards].number = temp.number;
          cards2[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!" << endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else {
        cout << "You have put invalid choice! Please put a choice again!" << endl;
        break;
      }
    }
  }
  if (i==1){
    numberofcards=0;
  }
  clrscrn();
}
}
