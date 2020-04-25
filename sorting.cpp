//sorting.cpp
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include "sorting.h"
#include "subsort.h"
#include "naturalsort.h"
#include "moving.h"
#include "card.h"
using namespace std;

void sorting(card deck[], int numberofcards, int joker[]){
  int newpos;
  int n=0;
  int posanswer,posnew;
  int last=numberofcards-1;
  int num;
  int sho;
  char col;
  num= deck[last].number;
  col= deck[last].color;
  sho= deck[last].shown;
  if (num==12){
    cout<<"Cp0"<<endl;
    if (col=='W' && joker[1]==0){
      n=0;
      subsort(last,newpos,deck,n,num,col,sho,joker);
      joker[0]=1;
      joker[2]=newpos-1;
      cout << "cp1" << endl;
    }
    else if(col=='B' && joker[0]==0){
      if(deck[last-1].number != 12){
        n=1;
        subsort(last,newpos,deck,n,num,col,sho,joker);
        joker[1]=1;
        joker[3]=newpos-1;
        cout << "cp2"<<endl;
        cout<< joker[0] << joker[1] << endl;;
      }
      else if (deck[last-1].number == 12 && deck[last-1].color == 'W'){
        int whitejnum=12, whitejcol = 'W';
        n=0;
        subsort(last,newpos,deck,n,whitejnum,whitejcol,sho,joker);
        joker[0]=1;
        joker[2]=newpos-1;
        n=1;
        deck[last].number = num;
        deck[last].color = col;
        deck[last].shown = sho;
        subsort(last,newpos,deck,n,num,col,sho,joker);
        joker[1]=1;
        joker[3]=newpos-1;
        cout << "cp3"<<endl;
        cout << joker[0] << joker[1] <<endl;
      }
    }
    else if (col == 'W' && joker[1] == 1){
      n=0;
      subsort(last,newpos,deck,n,num,col,sho,joker);
      joker[0]=1;
      joker[2]=newpos-1;
    }
    else if (col == 'B' && joker[0] == 1){
      n=1;
      subsort(last,newpos,deck,n,num,col,sho,joker);
      joker[1]=1;
      joker[3]=newpos-1;
    }
  }
  else{
    if(joker[0] == 0 && joker[1]==0){
      naturalsort(deck,0,last,posnew,numberofcards);
      cout << "cp4" << endl;
    }
    else if (joker[0]==1 && joker[1]==1){
      int firstj=min(joker[2],joker[3]);
      int secondj=max(joker[2],joker[3]);
      if(firstj==0 && secondj!=last-1 && joker[2]-joker[3]!=-1 && joker[2]-joker[3]!=1){
        if (deck[secondj+1].number < num){
          naturalsort(deck,secondj+1,last,posnew,numberofcards);
          cout << "cp5" << endl;
        }
        else if(deck[secondj-1].number > num && deck[firstj+1].number <num){
          naturalsort(deck,1,secondj-1,posnew,numberofcards);
        }
        else if (deck[firstj+1].number == num){
          if (deck[firstj+1].color == 'W' && deck[secondj-1].number > num){
            naturalsort(deck,1,secondj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards, posanswer);
            posnew=posanswer-1;
          }
        }
        else if(deck[secondj-1].number ==num){
          if(deck[secondj-1].color=='W'){
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
          else{
            naturalsort(deck,1, secondj-1,posnew,numberofcards);
          }
        }
        else if(deck[secondj+1].number == num ){
          if(deck[secondj+1].color=='W'){
            naturalsort(deck,secondj+1,last,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else{
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
          cout << "cp6" << endl;
        }
      }
      else if (secondj==last-1 && joker[2]-joker[3]!=-1 &&joker[2]-joker[3]!=1){
        if (deck[firstj-1].number > num){
          naturalsort(deck,0,firstj-1,posnew,numberofcards);
          cout << "cp7" << endl;
        }
        else if(deck[firstj+1].number<num && deck[secondj-1].number >num){
          naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
        }
        else if(deck[secondj-1].number==num){
          if(deck[secondj-1].color=='B'&& deck[firstj+1].number < num){
            naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if(deck[firstj-1].number==num){
          if(deck[firstj-1].color=='B'){
            naturalsort(deck,0,firstj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if(deck[firstj+1].number==num){
          if(deck[firstj+1].color=='W' && deck[secondj-1].number >num){
            naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else{
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
          cout << "cp8" << endl;
        }
      }
      else if (joker[2]-joker[3]==-1 || joker[2]-joker[3]==1){
        if(secondj==last-1){
          if(num < deck[firstj-1].number){
            naturalsort(deck,0,firstj-1,posnew,numberofcards);
          }
          else if(num==deck[firstj-1].number){
            if(deck[firstj-1].color=='B'){
              naturalsort(deck,0,firstj-1,posnew,numberofcards);
            }
            else{
              moving(deck,numberofcards,posanswer);
              posnew=posanswer-1;
            }
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if(firstj==0){
          if(num > deck[secondj+1].number){
            naturalsort(deck,secondj+1,last,posnew,numberofcards);
          }
          else if(num==deck[secondj+1].number){
            if(deck[secondj+1].color=='W'){
              naturalsort(deck,secondj+1,last,posnew,numberofcards);
            }
            else{
              moving(deck,numberofcards,posanswer);
              posnew=posanswer-1;
            }
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if (num < deck[firstj-1].number){
          naturalsort(deck,0,firstj-1,posnew,numberofcards);
          cout << "cp9" << endl;
        }
        else if(num > deck[secondj+1].number){
          naturalsort(deck,secondj+1,last,posnew,numberofcards);
          cout << "cp10" << endl;
        }
        else if(num == deck[firstj-1].number){
          if(deck[firstj-1].color=='B'){
            naturalsort(deck,0,firstj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if(num== deck[secondj+1].number){
          if(deck[secondj+1].color=='W'){
            naturalsort(deck,secondj+1,last,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else{
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
          cout << "cp11" << endl;
        }
      }
      else{
        if (num < deck[firstj-1].number){
          naturalsort(deck,0,firstj-1,posnew,numberofcards);
          cout << "cp12" << endl;
        }
        else if(num > deck[secondj+1].number){
          naturalsort(deck,secondj+1,last,posnew,numberofcards);
          cout << "cp13" << endl;
        }
        else if(num > deck[firstj+1].number && num < deck[secondj-1].number){
          naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
          cout << "cp14" << endl;
        }
        else if(num == deck[firstj-1].number){
          if(deck[firstj-1].color == 'B'){
            naturalsort(deck,0,firstj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if(num == deck[secondj+1].number){
          if(deck[secondj+1].color == 'W'){
            naturalsort(deck,secondj+1,last,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if(num == deck[firstj+1].number){
          if(deck[firstj+1].color=='W' && deck[secondj-1].number >num){
            naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if(num==deck[secondj-1].number){
          if(deck[firstj+1].color=='B'&& deck[firstj+1].number <num){
            naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else{
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
          cout << "cp15" << endl;
        }
      }
    }
    else{
      int posj;
      cout<< joker[0] << joker[1] << posj <<endl;
      if (joker[0]==0){
        posj=joker[3];
      }
      else{
        posj=joker[2];
      }
      if(posj==0){
        if (deck[posj+1].number < num){
          naturalsort(deck,posj+1,last,posnew,numberofcards);
          cout << "cp16" << endl;
        }
        else if(deck[posj+1].number == num){
          if(deck[posj+1].color=='B'){
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
          else{
            naturalsort(deck,posj+1,last,posnew,numberofcards);
          }
        }
        else{
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
          cout << "cp17" << endl;
        }
      }
      else if (posj==last-1){
        if (deck[posj-1].number > num){
          naturalsort(deck,0,posj-1,posnew,numberofcards);
          cout << "cp18" << endl;
        }
        else if(deck[posj-1].number==num){
          if(deck[posj-1].color=='B'){
            naturalsort(deck,0,posj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else{
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
          cout << "cp19" << endl;
        }
      }
      else if (num < deck[posj-1].number){
        naturalsort(deck,0,posj-1,posnew,numberofcards);
        cout << "cp20" << endl;
      }
      else if(num > deck[posj+1].number){
        naturalsort(deck,posj+1,last,posnew,numberofcards);
        cout << "cp21" << endl;
      }
      else if (num == deck[posj-1].number){
        if(deck[posj-1].color == 'W'){
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
        }
        else{
          naturalsort(deck,0,posj-1,posnew,numberofcards);
        }
      }
      else if(num == deck[posj+1].number){
        if (deck[posj+1].color == 'W'){
          naturalsort(deck,posj+1,last,posnew,numberofcards);
        }
        else{
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
        }
      }
      else{
        moving(deck,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp22" << endl;
      }
    }
    for (int k=last; k>posnew-1; k--){
      if (joker[2]==k){
        joker[2]=joker[2]+1;
      }
      if (joker[3]==k){
        joker[3]=joker[3]+1;
      }
      deck[k].number = deck[k-1].number;
      deck[k].color = deck[k-1].color;
      deck[k].shown = deck[k-1].shown;
    }
    deck[posnew].number = num;
    deck[posnew].color = col;
    deck[posnew].shown = sho;
  }
}
