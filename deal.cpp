//deal.cpp

#include <iostream>
#include <iomanip>
#include "deal.h"
#include "cardindeck.h"
#include "card.h"
using namespace std;
//this if for giving one tile for a player
//random assignment of number is used to distribute a tile to a player
void deal(card deck[], card cards[], int &numberofcards){
  srand(time(NULL));
  int numcard = numberofcards + 1;
  string option;
  card temp;
  bool deckhaswhite;
  bool deckhasblack;
  //check whether the deck has white/black tiles
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
    //asks for option for color
    cout << "Which Color do you want to pick? (B/W): ";
    cin >> option;
    while (true){
      //if choice is white tile
      if (option == "W"){
        temp.color = 'W';
        //random number generation
        temp.number = rand()%13;
        temp.shown = 0;
        if (deckhaswhite){
          if (cardindeck(deck,temp)>=0){
            //removes the chosen tile from deck
            deck[cardindeck(deck,temp)].color = 'N';
            deck[cardindeck(deck,temp)].number = 100;
            deck[cardindeck(deck,temp)].shown = 100;
            //adds the chosen tile to player's set of tiles
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
        //if the deck has no more white
        else{
          cout << "deck has no more white!" << endl;
          break;
        }
      }
      //if choice is black tile
      else if (option == "B"){
        temp.color = 'B';
        //random number generation
        temp.number = rand()%13;
        temp.shown = 0;
        if (deckhasblack){
          if (cardindeck(deck,temp)>=0){
            //removes the chosen tile from deck
            deck[cardindeck(deck,temp)].color = 'N';
            deck[cardindeck(deck,temp)].number = 100;
            deck[cardindeck(deck,temp)].shown = 100;
            //adds the chosen tile to player's set of tiles
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
        //if the deck has no more black
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
