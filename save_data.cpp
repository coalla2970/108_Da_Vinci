//save_data.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include "save_data.h"
#include "card.h"
using namespace std;

void save_data(card cards1[], card cards2[], card deck[], int numbercards1, int numbercards2,
int password1, int password2, string player1, string player2, int joker1[], int joker2[], int turn, char &save){
  while(true){
    if (save=='Y'){
      ofstream fout;
      fout.open("player1previnfo.txt");
      if (fout.fail()){
        cout<< "Error in opening file!" <<endl;
      }
      fout << player1;
      fout << endl;
      fout << password1;
      fout << endl;
      fout << numbercards1;
      fout << endl;
      for (int i=0;i<3;i++){
        for(int j=0;j<numbercards1;j++){
          if(i==0){
              fout << cards1[j].color << " ";
          }
          else if(i==1){
              fout << cards1[j].number << " ";
          }
          else if(i==2){
              fout << cards1[j].shown<< " ";
          }
        }
        fout << endl;
      }
      fout.close();
      fout.open("player2previnfo.txt");
      if (fout.fail()){
        cout<< "Error in opening file!" <<endl;
      }
      fout << player2;
      fout << endl;
      fout << password2;
      fout << endl;
      fout << numbercards2;
      fout << endl;
      for (int i=0;i<3;i++){
        for(int j=0;j<numbercards2;j++){
          if(i==0){
              fout << cards2[j].color << " ";
          }
          else if(i==1){
              fout << cards2[j].number << " ";
          }
          else if(i==2){
              fout << cards2[j].shown<< " ";
          }
        }
        fout << endl;
      }
      fout.close();
      fout.open("deckandturnprevinfo.txt");
      if (fout.fail()){
        cout<< "Error in opening file!" <<endl;
      }
      fout << turn;
      fout << endl;
      for (int k=0;k<3;k++){
        for(int l=0;l<24;l++){
          if(k==0){
              fout << deck[l].color << " ";
          }
          else if(k==1){
              fout << deck[l].number << " ";
          }
          else if(k==2){
              fout << deck[l].shown << " ";
          }
        }
        fout << endl;
      }
      for (int m=0;m<4;m++){
        fout << joker1[m] <<" ";
      }
      fout << endl;
      for (int n=0;n<4;n++){
        fout << joker2[n] <<" ";
      }
      break;
    }
    else if (save=='N'){
      cout<< "Please continue the game!" << endl;
      break;
    }
    else{
      cout << "Please put valid input"<<endl;
      cout << "Do you want to save this game and end this game? (Y/N):";
      cin >> save;
      continue;
    }
  }
}
