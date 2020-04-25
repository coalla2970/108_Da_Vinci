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
  ifstream fin;
  fin.open("player1previnfo.txt");
  if(fin.fail()){
    cout<<"Starting new game!" <<endl;
    welcomemsg(player1,player2,password);
    cout << "testing...(printing all possible cards)" << endl;
    cout << "You are going to pick first 4 cards." << endl;
    primarydeal(deck,cards1,cards2,player1,player2,numbercards);
    cout << player1 << "'s initial cards" << endl;
    checkpassword(player1,password[1]);
    primarysort(cards1,numbercards1);
    sorting(cards1,numbercards1,joker1);
    showmycards(cards1,numbercards1);
    clrscrn();
    cout << player2 << "'s initial cards" << endl;
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
      else if(recall=="N"){
        welcomemsg(player1,player2,password);
        cout << "testing...(printing all possible cards)" << endl;
        cout << "You are going to pick first 4 cards." << endl;
        primarydeal(deck,cards1,cards2,player1,player2,numbercards);
        cout << player1 << "'s initial cards" << endl;
        checkpassword(player1,password[1]);
        primarysort(cards1,numbercards1);
        sorting(cards1,numbercards1,joker1);
        showmycards(cards1,numbercards1);
        clrscrn();
        cout << player2 << "'s initial cards" << endl;
        checkpassword(player2,password[2]);
        primarysort(cards2,numbercards2);
        sorting(cards2,numbercards2,joker2);
        showmycards(cards2,numbercards2);
        clrscrn();
        break;
      }
      else{
        cout << "Please put a valid input.(Y/N)";
        cin >>recall;
      }
    }
    cout<< cards1[0].color << endl;
    cout<<cards1[1].color<<endl;
    cout << cards2[0].color<<endl;
    cout<< cards2[1].color<<endl;
    cout <<player1 <<endl;
    cout<<player2<<endl;
    cout << joker1[0] <<endl;
    cout<< joker1[1]<<endl;
    cout << joker2[0]<<endl;
    cout << joker2[1]<<endl;
    cout << password[1]<<endl;
    cout << password[2]<<endl;
  }
  while(!(didplayerlose(cards1,numbercards1)||didplayerlose(cards2,numbercards2)) && !(emptydeck(deck))){
    if (turn == 1){
      cout << player1 << ", it's your turn!" << endl;
      checkpassword(player1,password[1]);
      cout << "The remaining cards are:" << endl;
      showcardsback(deck,24);
      cout << "Please draw one more card!" << endl;
      deal(deck,cards1,numbercards1);
      newcardinfo(newcardplayer1,cards1,numbercards1);
      cout << endl;
      cout << "your new card is: " << endl;
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
      cout << joker1[0] << joker1[1] << endl;
      cout << endl;
      cout << "here is your card: " << endl;
      showmycards(cards1,numbercards1);
      cout << endl;
      guessing(cards2,cards1,newcardplayer1,numbercards1,numbercards2,player1,password[1]);
      if (!(didplayerlose(cards1,numbercards1)||didplayerlose(cards2,numbercards2)) && !(emptydeck(deck))){
        turn = 2;
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
      cout << "The remaining cards are:" << endl;
      showcardsback(deck,24);
      cout << "Please draw one more card!" << endl;
      deal(deck,cards2,numbercards2);
      newcardinfo(newcardplayer2,cards2,numbercards2);
      cout << endl;
      cout << "your new card is: " << endl;
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
      cout << joker2[0] << joker2[1] << endl;
      cout << endl;
      cout << "here is your card: " << endl;
      showmycards(cards2,numbercards2);
      cout << endl;
      guessing(cards1,cards2,newcardplayer2,numbercards2,numbercards1,player2,password[2]);
      if (!(didplayerlose(cards1,numbercards1)||didplayerlose(cards2,numbercards2)) && !(emptydeck(deck))){
        turn = 1;
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
  }
  cout << "game ended!" << endl;
  if (didplayerlose(cards1,numbercards1)){
    cout << player2 << " won!" << endl;
  }
  else if(didplayerlose(cards2,numbercards2)){
    cout << player1 << " won!" << endl;
  }
  else if (countshown(cards1,numbercards1) > countshown(cards2,numbercards2)){
    cout << "since there are no more cards in the deck, a player with less shown cards will be winner." << endl;
    cout << player2 << " won!" << endl;
  }
  else if (countshown(cards1,numbercards1) < countshown(cards2,numbercards2)){
    cout << "since there are no more cards in the deck, a player with less shown cards will be winner." << endl;
    cout << player1 << " won!" << endl;
  }
  else{
    cout << "draw!" << endl;
  }
}
