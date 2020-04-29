//recall_data.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include "recall_data.h"
#include "card.h"
using namespace std;
//recall_data function recalls saved data from external file and update users' information to the current variable
void recall_data(card cards1[], card cards2[], card deck[],int &numbercards1, int &numbercards2,
int &password1, int &password2, string &player1, string &player2, int joker1[], int joker2[], int &turn, string &recall){
  int linecount = 1;
  string tempno = " ";
  int idx = 0;
  string player1line;
  string player2line;
  string deckline;
  string tempstr = "";
  char tempchar;

  while (true){
    if (recall=="Y"){
      ifstream fin;
      fin.open("player1previnfo.txt");
      if (fin.fail()){
        cout<< "Error in opening file!" <<endl;
        exit(1);
      }
      //recalling player1's information
      while(getline(fin,player1line)){
        stringstream player1data(player1line);
        if (linecount==1){
          while (player1data >> tempstr){
            player1 = tempstr;
          }
          linecount++;
        }
        else if (linecount==2){
          while (player1data >> tempno){
            password1 = stoi(tempno,nullptr,10);
          }
          linecount++;
        }
        else if (linecount==3){
          while (player1data >> tempno){
            numbercards1 = stoi(tempno,nullptr,10);
          }
          linecount++;
        }
        else if (linecount==4){
          while (player1data >> tempchar){
            cards1[idx].color = tempchar;
            idx++;
          }
          idx=0;
          linecount++;
        }
        else if (linecount==5){
          while (player1data >> tempno){
            cards1[idx].number = stoi(tempno,nullptr,10);
            idx++;
          }
          idx=0;
          linecount++;
        }
        else if (linecount==6){
          while (player1data >> tempno){
            cards1[idx].shown = stoi(tempno,nullptr,10);
            idx++;
          }
          idx=0;
          linecount++;
        }
        else{
          linecount = 1;
          break;
        }
      }
      linecount = 1;
      fin.close();
      fin.open("player2previnfo.txt");
      if (fin.fail()){
        cout<< "Error in opening file!" <<endl;
        exit(1);
      }
      //recalling player2's information
      while(getline(fin,player2line)){
        stringstream player2data(player2line);
        if (linecount==1){
          while (player2data >> tempstr){
            player2 = tempstr;
          }
          linecount++;
        }
        else if (linecount==2){
          while (player2data >> tempno){
            password2 = stoi(tempno,nullptr,10);
          }
          linecount++;
        }
        else if (linecount==3){
          while (player2data >> tempno){
            numbercards2 = stoi(tempno,nullptr,10);
          }
          linecount++;
        }
        else if (linecount==4){
          while (player2data >> tempchar){
            cards2[idx].color = tempchar;
            idx++;
          }
          idx=0;
          linecount++;
        }
        else if (linecount==5){
          while (player2data >> tempno){
            cards2[idx].number = stoi(tempno,nullptr,10);
            idx++;
          }
          idx=0;
          linecount++;
        }
        else if (linecount==6){
          while (player2data >> tempno){
            cards2[idx].shown = stoi(tempno,nullptr,10);
            idx++;
          }
          idx=0;
          linecount++;
        }
        else{
          linecount = 1;
          break;
        }
      }
      linecount = 1;
      fin.close();
      fin.open("deckandturnprevinfo.txt");
      if (fin.fail()){
        cout<< "Error in opening file!" <<endl;
        exit(1);
      }
      //recalling cards deck's information
      while(getline(fin,deckline)){
        stringstream deckdata(deckline);
        if (linecount==1){
          while (deckdata >> tempno){
            turn = stoi(tempno,nullptr,10);
          }
          linecount++;
        }
        else if (linecount==2){
          while (deckdata >> tempchar){
            deck[idx].color = tempchar;
            idx++;
          }
          idx=0;
          linecount++;
        }
        else if (linecount==3){
          while (deckdata >> tempno){
            deck[idx].number = stoi(tempno,nullptr,10);
            idx++;
          }
          idx=0;
          linecount++;
        }
        else if (linecount==4){
          while (deckdata >> tempno){
            deck[idx].shown = stoi(tempno,nullptr,10);
            idx++;
          }
          idx=0;
          linecount++;
        }
        else if (linecount==5){
          while (deckdata >> tempno){
            joker1[idx] = stoi(tempno,nullptr,10);
            idx++;
          }
          idx=0;
          linecount++;
        }
        else if (linecount==6){
          while (deckdata >> tempno){
            joker2[idx] = stoi(tempno,nullptr,10);
            idx++;
          }
          idx=0;
          linecount++;
        }
        else{
          linecount = 1;
          break;
        }
      }
      break;
    }
    else if(recall=="N"){
      break;
    }
    else{
      cout << "Please put a valid input"<<endl;
      cout << "Do you want to recall previous data? (Y/N):";
      cin >> recall;
      continue;
    }
  }
}
