//guessing.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "guessing.h"
#include "showcardsback.h"
#include "showmycards.h"
#include "didplayerlose.h"
#include "tools.h"
#include "checkpassword.h"
#include "card.h"
using namespace std;
//guessing for the players
//if the player guesses correctly, he/she reveals his/her opponent's tile
//if not, the recent tile he/she drew will be revealed
void guessing(card opponentcard[], card mycard[], card &newcard, int numberofcards, int opponentcards, string player, int password){
  while(true){
    int position=1000;
    int number=1000;
    //shows current deck of the player and his/her opponent's tiles
    cout << "here is the back of your opponent's cards: " << endl;
    showcardsback(opponentcard, opponentcards);
    cout << endl;
    cout << "which card do you want to pick?(leftmost - 1): ";
    while (!(cin>>position) || opponentcard[position-1].shown == 1 || !(1<=position && position<=opponentcards)){
      cout << "Please input a vaild number.\nPosition?";
      cin.clear();
      while (cin.get() != '\n'){
      }
    }
    cout << "please guess the number of the chosen card (Joker: 12): ";
    while (!(cin>>number)){
      cout << "Please input a vaild number.";
      cin.clear();
      while (cin.get() != '\n'){
      }
    }
    //if the guess is correct
    if (opponentcard[position-1].shown == 0 && number == opponentcard[position-1].number){
      cout << "you have guessed it correctly!" << endl;
      opponentcard[position-1].shown = 1;
      if(!(didplayerlose(mycard,numberofcards)||didplayerlose(opponentcard,opponentcards))){
        //asks whether the player wants go guess more
        cout << "you have guessed it correctly. do you want to guess more? (Y/N): ";
        string choice;
        getline(cin >> ws,choice);
        if (choice == "Y"){
          //guess again
          clrscrn();
          cout << "Here are your cards again:" << endl;
          showmycards(mycard,numberofcards);
          continue;
        }
        //if he/she decides not to guess again
        else if(choice == "N")
          break;
        else{
          while(choice!="Y" && choice!="N"){
            cout << "Please put a valid input.(Y/N)";
            getline(cin >> ws,choice);
          }
          if (choice == "Y")
            continue;
          else if(choice == "N")
            break;
        }
      }
      else{
        break;
      }
    }
    //if the guess is incorrect
    else {
      cout << "oops, you have guessed it wrong!" << endl;
      for (int i=0; i<numberofcards; i++){
        if (mycard[i].color == newcard.color && mycard[i].number == newcard.number){
          mycard[i].shown = 1;
        }
        else
          pass();
      }
      break;
    }
  }
  //confirming the moves before the turn goes to the next player
  cout << "please confirm your moves by putting your password: " << endl;
  checkpassword(player,password);
}
