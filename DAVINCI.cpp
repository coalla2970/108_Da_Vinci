//DAVINCI.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include "welcomemsg.h"
#include "tools.h"
#include "checkpassword.h"
#include "primarysort.h"
#include "showmycards.h"
#include "showcardsback.h"
#include "cardindeck.h"
#include "countshown.h"
#include "didplayerlose.h"
#include "deal.h"
#include "emptydeck.h"
#include "guessing.h"
#include "moving.h"
#include "naturalsort.h"
#include "newcardinfo.h"
#include "primarydeal.h"
#include "recall_data.h"
#include "save_data.h"
#include "sorting.h"
#include "subsort.h"
#include "card.h"
using namespace std;

#define WHITE "\xE2\x98\x90"
#define BLACK "\xE2\x96\xA0"
//main function plays the game.
int main(){
  string recall;
  string save;
  char option1;
  string player1,player2;
  int password[3];
  int joker1[4]={0,0,-1,-1};
  int joker2[4]={0,0,-1,-1};
  card newcardplayer1;
  card newcardplayer2;
  int turn=1;
  int dataexist=0;
  int numbercards=0;
  int numbercards1=4;
  int numbercards2=4;
  card *cards1=new card[24];
  card *cards2=new card[24];
  card *deck=new card[24];
  //Adjustment of screen for playing.
  cout << "Please adjust the screen until you see only one line:" << endl;
  for (int i=0; i<190; i++){
    cout << "-";
  }
  cout << endl;
  cout << "Done?(Y/N): ";
  cin >> option1;
  if (option1 == 'Y'){
    clrscrn();
  }
  //Initializing the deck of cards
  for (int i=0; i<12; i++){
    deck[i].color = 'W';
  }
  for (int i=12; i<24; i++){
    deck[i].color = 'B';
  }
  for (int k=1; k<13; k++){
    deck[k-1].number = k;
  }
  for (int k=13; k<25; k++){
    deck[k-1].number = k-12;
  }
  for (int i=0; i<24; i++){
    deck[i].shown = 0;
  }
  //opening saved files
  ifstream fin;
  fin.open("player1previnfo.txt");
  //if file does not exist,
  if(fin.fail()){
    cout<<"Starting new game!" <<endl;
    welcomemsg(player1,player2,password);
    cout << "You are going to pick first 4 tiles." << endl;
    //primary deal which involves 4 initial tiles for each player
    primarydeal(deck,cards1,cards2,player1,player2,numbercards);
    cout << player1 << "'s initial tiles" << endl;
    checkpassword(player1,password[1]);
    primarysort(cards1,numbercards1);
    sorting(cards1,numbercards1,joker1);
    showmycards(cards1,numbercards1);
    clrscrn();
    cout << player2 << "'s initial tiles" << endl;
    checkpassword(player2,password[2]);
    primarysort(cards2,numbercards2);
    sorting(cards2,numbercards2,joker2);
    showmycards(cards2,numbercards2);
    clrscrn();
  }
  else{
    cout << "Do you want to recall the previous game that you saved? (Y/N)";
    cin >> recall;
    while(true){
      if (recall == "Y"){
        recall_data(cards1,cards2,deck,numbercards1,numbercards2,password[1],password[2],player1,player2,joker1,joker2,turn,recall);
        break;
      }
      //if user wants to start a new game,
      else if(recall=="N"){
        cout << "Starting new game!" << endl;
        welcomemsg(player1,player2,password);
        cout << "You are going to pick first 4 tiles." << endl;
        primarydeal(deck,cards1,cards2,player1,player2,numbercards);
        cout << player1 << "'s initial tiles" << endl;
        checkpassword(player1,password[1]);
        primarysort(cards1,numbercards1);
        sorting(cards1,numbercards1,joker1);
        showmycards(cards1,numbercards1);
        clrscrn();
        cout << player2 << "'s initial tiles" << endl;
        checkpassword(player2,password[2]);
        primarysort(cards2,numbercards2);
        sorting(cards2,numbercards2,joker2);
        showmycards(cards2,numbercards2);
        clrscrn();
        break;
      }
      else{
        cout << "Please put a valid input.\nDo you want to recall the previous game that you saved?(Y/N)";
        cin >>recall;
      }
    }
  }
  //Start dealing
  while(!(didplayerlose(cards1,numbercards1)||didplayerlose(cards2,numbercards2)) && !(emptydeck(deck))){
    if (turn == 1){
      cout << player1 << ", it's your turn!" << endl;
      checkpassword(player1,password[1]);
      cout << "The remaining tiles are:" << endl;
      showcardsback(deck,24);
      cout << "Please draw one more tile!" << endl;
      deal(deck,cards1,numbercards1);
      newcardinfo(newcardplayer1,cards1,numbercards1);
      cout << endl;
      cout << "Your new tile is: " << endl;
      //shows the information of the new card
      if (newcardplayer1.color == 'W'){
        cout << "Color: White" << endl;
      }
      else if (newcardplayer1.color == 'B'){
        cout << "Color: Black" << endl;
      }
      else{
        pass();
      }
      if (newcardplayer1.number < 12 && newcardplayer1.number > 0){
        cout << "Number: " << newcardplayer1.number << endl;
      }
      else{
        cout << "Joker" << endl;
      }
      sorting(cards1,numbercards1,joker1);
      cout << "Here is your tile: " << endl;
      showmycards(cards1,numbercards1);
      cout << endl;
      //guessing the card
      guessing(cards2,cards1,newcardplayer1,numbercards1,numbercards2,player1,password[1]);
      if (!(didplayerlose(cards1,numbercards1)||didplayerlose(cards2,numbercards2)) && !(emptydeck(deck))){
        turn = 2;
        //Saving data to the external file.
        char save;
        cout << "Do you want to save this game and end this game? (Y/N)";
        cin >> save;
        save_data(cards1, cards2, deck, numbercards1, numbercards2, password[1], password[2], player1, player2, joker1, joker2, turn, save);
        if(save=='Y'){
          exit(1);
        }
      }
      else{
        break;
      }
      clrscrn();
    }
    else{
      cout << player2 << ", it's your turn!" << endl;
      checkpassword(player2,password[2]);
      cout << "The remaining tiles are:" << endl;
      showcardsback(deck,24);
      cout << "Please draw one more tile!" << endl;
      deal(deck,cards2,numbercards2);
      newcardinfo(newcardplayer2,cards2,numbercards2);
      cout << endl;
      cout << "your new tile is: " << endl;
      if (newcardplayer2.color == 'W'){
        cout << "Color: White" << endl;
      }
      else if (newcardplayer2.color == 'B'){
        cout << "Color: Black" << endl;
      }
      else{
        pass();
      }
      if (newcardplayer2.number < 12 && newcardplayer2.number > 0){
        cout << "Number: " << newcardplayer2.number << endl;
      }
      else{
        cout << "Joker" << endl;
      }
      sorting(cards2,numbercards2,joker2);
      cout << "Here is your tile: " << endl;
      showmycards(cards2,numbercards2);
      cout << endl;
      guessing(cards1,cards2,newcardplayer2,numbercards2,numbercards1,player2,password[2]);
      if (!(didplayerlose(cards1,numbercards1)||didplayerlose(cards2,numbercards2)) && !(emptydeck(deck))){
        turn = 1;
        char save;
        //Saving data to the external file.
        cout << "Do you want to save this game and end this game? (Y/N)";
        cin >> save;
        save_data(cards1, cards2, deck, numbercards1, numbercards2, password[1], password[2], player1, player2, joker1, joker2, turn, save);
        if(save=='Y'){
          exit(1);
        }
      }
      else{
        break;
      }
      clrscrn();
    }
  }
  clrscrn();
  //End of game and winner is announced.
  cout << "Game Ended!" << endl;
  if (didplayerlose(cards1,numbercards1)){
    cout << player2 << " Won!" << endl;
    cout << player2 << ", CONGRATULATIONS :)" << endl;
  }
  //if the deck runs out of tiles before a player reveals all of his/her opponent's tile
  else if(didplayerlose(cards2,numbercards2)){
    cout << player1 << " Won!" << endl;
    cout << player1 << ", CONGRATULATIONS :)" << endl;
  }
  else if (countshown(cards1,numbercards1) > countshown(cards2,numbercards2)){
    cout << "Since there are no more tiles in the deck, a player with less shown tiles will be the winner." << endl;
    cout << player2 << " Won!" << endl;
    cout << player2 << ", CONGRATULATIONS :)" << endl;
  }
  else if (countshown(cards1,numbercards1) < countshown(cards2,numbercards2)){
    cout << "Since there are no more tiles in the deck, a player with less shown tiles will be the winner." << endl;
    cout << player1 << " Won!" << endl;
    cout << player1 << ", CONGRATULATIONS :)" << endl;
  }
  // If all the tiles are drawn and the number of shown cards are equal,
  else{
    cout << "Draw!" << endl;
  }
  delete [] cards1;
  delete [] cards2;
  delete [] deck;
}
