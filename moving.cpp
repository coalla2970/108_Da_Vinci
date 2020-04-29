//moving.cpp
#include <iostream>
#include "moving.h"
#include "showmycards.h"
#include "tools.h"
#include "card.h"
using namespace std;
//moving function is executed when the user's input is needed to sort the deck of the cards
void moving(card deck[], int numberofcards, int &posanswer){
  int last=numberofcards-1;
  int num;
  char col;
  num = deck[last].number;
  col = deck[last].color;
  showmycards(deck,numberofcards);
  cout << "Please choose a position of a new tile! (leftmost=1):"; 
  while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
    cout << "Please input a vaild number.\nPosition?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }
  //This loop checks whether
  //1.new position is valid when comparing to the cards before the new position in the deck
  //2.new position is valid when comparing to the cards after the new position in the deck
  //Repeat twice to make sure that moving is valid for both situations.
  for (int l=0; l<2; l++){
    //Cheking whether user's input is valid from next cards of new position until the end
    for (int i=posanswer-1; i<last ; i++){
      if ((num > deck[i].number) && deck[i].number!=12){
        cout << "Invalid move. Please consider the tile order! Position? (leftmost=1):";
        while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
          cout << "Please input a vaild number.\nPosition? (leftmost=1)";
          cin.clear();
          while (cin.get() != '\n'){
          }
        }
        i=posanswer-2;
        continue;
      }
      else if(deck[i].number == num){
        if(deck[i].color == 'W' && col == 'B'){
          cout << "Invalid move. Please consider the tile order! Position? (leftmost=1):";
          while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
            cout << "Please input a vaild number.\nPosition? (leftmost=1)";
            cin.clear();
            while (cin.get() != '\n'){
            }
          }
          i=posanswer-2;
          continue;
        }
        else{
          continue;
        }
      }
    }
    //If new position is the start of the deck, it is not needed to consider the cards before the new position.
    if(posanswer==1){
      break;
    }
    else{
      pass();
    }
    //Cheking whether user's input is valid from the first card until the previous card of new position.
    for (int m=0; m<posanswer-1; m++){
      if ((deck[m].number > num && deck[m].number != 12) || deck[posanswer-1].number < num){
        cout << "Invalid move. Please consider the tile order!\n Position? (leftmost=1):";
        while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
          cout << "Please input a vaild number.\nPosition?";
          cin.clear();
          while (cin.get() != '\n'){
          }
        }
        m=-1;
        continue;
      }
      else if (deck[m].number == num){
        if(deck[m].color == 'W' && col == 'B'){
          continue;
        }
        else{
          cout << "Invalid move. Please consider the tile order!\nPosition? (leftmost=1):";
          while (!(cin>>posanswer)||posanswer>numberofcards || posanswer<1){
            cout << "Please input a vaild number.\nPosition?";
            cin.clear();
            while (cin.get() != '\n'){
            }
          }
          m=-1;
          continue;
        }
      }
      else continue;
    }
  }
}
