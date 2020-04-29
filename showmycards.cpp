//showmycards.cpp
#include <iostream>
#include "showmycards.h"
#include "card.h"
using namespace std;

#define WHITE "\xE2\x98\x90"
#define BLACK "\xE2\x96\xA0"

//shows all the information of the player's tiles
void showmycards(card deck[], int numberofcards){
  string choice;
  //used for indicating that a player has fully seen the information of his/her tiles
  int confirmation = 1;
  while(confirmation == 1){
    //upper part of tiles
    for (int n=0; n<2; n++){
      for (int i=0; i<numberofcards; i++){
        if (deck[i].color == 'W'){
          cout << WHITE WHITE WHITE WHITE WHITE WHITE<< "\t";
        }
        else {
          cout << BLACK BLACK BLACK BLACK BLACK BLACK<< "\t";
        }
      }
      cout << endl;
    }
    //middle part of tiles. shows all relevant information such as tile's numbers
    for (int i=0; i<numberofcards; i++){
      if (deck[i].color == 'W'){
        if (deck[i].number >= 1 && deck[i].number <= 9){
          cout << WHITE WHITE << 0 << deck[i].number << WHITE WHITE << "\t";
        }
        else if (deck[i].number == 10 || deck[i].number == 11){
          cout << WHITE WHITE << deck[i].number << WHITE WHITE << "\t";
        }
        else {
          cout << WHITE WHITE << "**" << WHITE WHITE << "\t";
        }
      }
      else {
        if (deck[i].number >= 1 && deck[i].number <= 9){
          cout << BLACK BLACK << 0 << deck[i].number << BLACK BLACK << "\t";
        }
        else if (deck[i].number == 10 || deck[i].number == 11){
          cout << BLACK BLACK << deck[i].number << BLACK BLACK  << "\t";
        }
        else {
          cout << BLACK BLACK << "**" << BLACK BLACK << "\t";
        }
      }
    }
    cout << endl;
    //lower part of tiles
    for (int n=0; n<2; n++){
      for (int i=0; i<numberofcards; i++){
        if (deck[i].color == 'W'){
          cout << WHITE WHITE WHITE WHITE WHITE WHITE << "\t";
        }
        else {
          cout << BLACK BLACK BLACK BLACK BLACK BLACK << "\t";
        }
      }
      cout << endl;
    }
    //for showing whether the card is shown to the opponent or not
    for (int i=0; i<numberofcards; i++){
      if (deck[i].shown == 1){
        cout << "Shown!" << "\t";
      }
      else {
        cout << "     " << "\t";
      }
    }
    cout << endl;
    //asks to confirm that the player has seen the cards. if the answer is no, the tiles will be shown again
    while(true){
      cout << "confirm that you have seen the cards (Y/N): ";
      cin >> choice;
      if (choice == "Y"){
        confirmation = 0;
        break;
      }
      else if (choice == "N"){
        break;
      }
      else
        cout << "invalid input!" << endl;
    }
  }
}
