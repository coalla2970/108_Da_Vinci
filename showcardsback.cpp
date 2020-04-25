//showcardsback.cpp
#include <iostream>
#include "tools.h"
#include "showcardsback.h"
#include "card.h"
using namespace std;

#define WHITE "\xE2\x98\x90"
#define BLACK "\xE2\x96\xA0"

void showcardsback(card deck[], int numberofcards){
for (int n=0; n<2; n++){
  for (int i=0; i<=numberofcards-1; i++){
    if (deck[i].color == 'W'){
      cout << WHITE WHITE WHITE WHITE WHITE WHITE<< "\t";
    }
    else if (deck[i].color == 'B'){
      cout << BLACK BLACK BLACK BLACK BLACK BLACK<< "\t";
    }
    else
      pass();
  }
  cout << endl;
}
for (int i=0; i<=numberofcards-1; i++){
  if (deck[i].color == 'W' && deck[i].shown == 0){
    cout << WHITE WHITE WHITE WHITE WHITE WHITE<< "\t";
  }
  else if (deck[i].color == 'B' && deck[i].shown == 0){
    cout << BLACK BLACK BLACK BLACK BLACK BLACK<< "\t";
  }
  else if (deck[i].color == 'W' && deck[i].shown == 1){
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
  else if (deck[i].color == 'B' && deck[i].shown == 1){
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
  else
    pass();
}
cout << endl;
for (int n=0; n<2; n++){
  for (int i=0; i<=numberofcards-1; i++){
    if (deck[i].color == 'W'){
      cout << WHITE WHITE WHITE WHITE WHITE WHITE<< "\t";
    }
    else if (deck[i].color == 'B'){
      cout << BLACK BLACK BLACK BLACK BLACK BLACK<< "\t";
    }
    else
      pass();
  }
  cout << endl;
}
}
