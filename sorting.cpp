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
//sorting function replaces the new cards.
//When the card can be naturally sorted, it does not ask the new position of the tile to the player
//If there are alternative choices that players can choose, it asks the new position of the tile to the player
void sorting(card deck[], int numberofcards, int joker[]){
  //Since the jokers make exception to the sorting, joker's existence and its position is saved in joker[].
  int newpos;
  int n=0;
  int posanswer,posnew;
  int last=numberofcards-1;
  int num;
  int sho;
  char col;
  //num,col,sho is the information about the new card
  num= deck[last].number;
  col= deck[last].color;
  sho= deck[last].shown;
  //When the new card is a joker.
  if (num==12){
    //If the new card is a white joker and black joker does not exist in the player's deck
    if (col=='W' && joker[1]==0){
      n=0;
      subsort(last,newpos,deck,n,num,col,sho,joker);
      joker[0]=1;
      joker[2]=newpos-1;
    }
    //If the new card is a black joker and white joker does not exist in the player's deck
    else if(col=='B' && joker[0]==0){
      //Ifthey are not primary drawn tiles,
      if(deck[last-1].number != 12){
        n=1;
        subsort(last,newpos,deck,n,num,col,sho,joker);
        joker[1]=1;
        joker[3]=newpos-1;;
      }
      //If they are primary drawn tiles and a white joker and a black joker tiles both exist
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
      }
    }
    //If the new card is a white joker and a black joker exists in the player's deck
    else if (col == 'W' && joker[1] == 1){
      n=0;
      subsort(last,newpos,deck,n,num,col,sho,joker);
      joker[0]=1;
      joker[2]=newpos-1;
    }
    //If the new card is a black joker and a white joker exists in the player's deck
    else if (col == 'B' && joker[0] == 1){
      n=1;
      subsort(last,newpos,deck,n,num,col,sho,joker);
      joker[1]=1;
      joker[3]=newpos-1;
    }
  }
  //If the new card is not a joker
  else{
    //If there are no jokers in the player's deck
    if(joker[0] == 0 && joker[1]==0){
      naturalsort(deck,0,last,posnew,numberofcards);
    }
    //If there are both white joker and black joker in the player's deck
    else if (joker[0]==1 && joker[1]==1){
      //Defining the position of jokers
      int firstj=min(joker[2],joker[3]);
      int secondj=max(joker[2],joker[3]);
      //If first joker is at the first position and second joker is not at the end and both jokers are not adjacent to each other.
      if(firstj==0 && secondj!=last-1 && joker[2]-joker[3]!=-1 && joker[2]-joker[3]!=1){
        if (deck[secondj+1].number < num){
          naturalsort(deck,secondj+1,last,posnew,numberofcards);
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
        }
      }
      // If first joker is at the first and the second joker is at the end and they are not adjacent to each other
      else if (firstj==0 && secondj==last-1 && joker[2]-joker[3]!=-1 &&joker[2]-joker[3]!=1){
        if (deck[firstj+1].number <num && deck[secondj-1].number>num){
          naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
        }
        else if (deck[firstj+1].number==num){
          if (deck[firstj+1].number=='W'){
            naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
          }
          else{
            moving(deck,numberofcards,posanswer);
            posnew=posanswer-1;
          }
        }
        else if (deck[secondj-1].number==num){
          if (deck[secondj-1].number=='B'){
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
        }
      }
      //If second joker is at the end and both jokers are not adjacent to each other.
      else if (secondj==last-1 && joker[2]-joker[3]!=-1 &&joker[2]-joker[3]!=1){
        if (deck[firstj-1].number > num){
          naturalsort(deck,0,firstj-1,posnew,numberofcards);
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
        }
      }
      //If both jokers are adjacent to each other
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
        }
        else if(num > deck[secondj+1].number){
          naturalsort(deck,secondj+1,last,posnew,numberofcards);
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
        }
      }
      //Other general possibilities
      else{
        if (num < deck[firstj-1].number){
          naturalsort(deck,0,firstj-1,posnew,numberofcards);
        }
        else if(num > deck[secondj+1].number){
          naturalsort(deck,secondj+1,last,posnew,numberofcards);
        }
        else if(num > deck[firstj+1].number && num < deck[secondj-1].number){
          naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
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
        }
      }
    }
    //If there are no jokers in the player's deck
    else{
      int posj;
      //Defining the position of joker
      if (joker[0]==0){
        posj=joker[3];
      }
      else{
        posj=joker[2];
      }
      if(posj==0){
        if (deck[posj+1].number < num){
          naturalsort(deck,posj+1,last,posnew,numberofcards);
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
        }
      }
      else if (posj==last-1){
        if (deck[posj-1].number > num){
          naturalsort(deck,0,posj-1,posnew,numberofcards);
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
        }
      }
      else if (num < deck[posj-1].number){
        naturalsort(deck,0,posj-1,posnew,numberofcards);
      }
      else if(num > deck[posj+1].number){
        naturalsort(deck,posj+1,last,posnew,numberofcards);
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
      }
    }
    //Replacing the cards and updating the position of the joker
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
