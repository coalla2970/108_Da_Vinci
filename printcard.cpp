#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define WHITE "\xE2\x98\x90"
#define BLACK "\xE2\x96\xA0"

void pass(){}
void clrscrn(){
  cout << "\33[2J\33[1;1H" << flush;
}
void showmycards(int cards[][3], int numberofcards){
  for (int n=0; n<2; n++){
    for (int i=0; i<numberofcards; i++){
      if (cards[i][0] == 0){
        cout << WHITE WHITE WHITE WHITE WHITE WHITE<< "\t";
      }
      else if (cards[i][0] == 1){
        cout << BLACK BLACK BLACK BLACK BLACK BLACK<< "\t";
      }
      else
        pass();
    }
    cout << endl;
  }
  for (int i=0; i<numberofcards; i++){
    if (cards[i][0] == 0){
      if (cards[i][1] >= 1 && cards[i][1] <= 9){
        cout << WHITE WHITE << 0 << cards[i][1] << WHITE WHITE << "\t";
      }
      else if (cards[i][1] == 10 || cards[i][1] == 11){
        cout << WHITE WHITE << cards[i][1] << WHITE WHITE << "\t";
      }
      else if (cards[i][1] == 12){
        cout << WHITE WHITE << "**" << WHITE WHITE << "\t";
      }
      else
        pass();
    }
    else if (cards[i][0] == 1){
      if (cards[i][1] >= 1 && cards[i][1] <= 9){
        cout << BLACK BLACK << 0 << cards[i][1] << BLACK BLACK << "\t";
      }
      else if (cards[i][1] == 10 || cards[i][1] == 11){
        cout << BLACK BLACK << cards[i][1] << BLACK BLACK  << "\t";
      }
      else if (cards[i][1] == 12){
        cout << BLACK BLACK << "**" << BLACK BLACK << "\t";
      }
      else
        pass();
    }
    else
      pass();
  }
  cout << endl;
  for (int n=0; n<2; n++){
    for (int i=0; i<numberofcards; i++){
      if (cards[i][0] == 0){
        cout << WHITE WHITE WHITE WHITE WHITE WHITE << "\t";
      }
      else if (cards[i][0] == 1){
        cout << BLACK BLACK BLACK BLACK BLACK BLACK << "\t";
      }
      else
        pass();
    }
    cout << endl;
  }
  for (int i=0; i<numberofcards; i++){
    if (cards[i][2] == 1){
      cout << "Shown!" << "\t";
    }
    else if (cards[i][2] == 0){
      cout << "     " << "\t";
    }
    else
      pass();
  }
  cout << endl;
}
int cardindeck(int deck[][3], int temp[3]){
  int check = -1;
  for (int i=0; i<24; i++){
    if (deck[i][0] == temp[0] && deck[i][1] == temp[1] && deck[i][2] == temp[2]){
      check = i;
      break;
    }
    else
      pass();
  }
  return check;
}
void primarydeal(int deck[][3], int cards[][3], int &numberofcards){
  srand(time(NULL));
  char option;
  int temp[3];
  while(numberofcards<4){
    srand(time(NULL));
    cout << "Which Color do you want to pick? (B/W): ";
    cin >> option;
    while (true){
      if (option == 'W'){
        temp[0] = 0;
        temp[1] = rand()%13;
        temp[2] = 0;
        if (cardindeck(deck,temp)>=0){
          deck[cardindeck(deck,temp)][0] = 100;
          deck[cardindeck(deck,temp)][1] = 100;
          deck[cardindeck(deck,temp)][2] = 100;
          cards[numberofcards][0] = temp[0];
          cards[numberofcards][1] = temp[1];
          cards[numberofcards][2] = temp[2];
          numberofcards++;
          cout << "choice made!"<< endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else if (option == 'B'){
        temp[0] = 1;
        temp[1] = rand()%13;
        temp[2] = 0;
        if (cardindeck(deck,temp)>=0){
          deck[cardindeck(deck,temp)][0] = 100;
          deck[cardindeck(deck,temp)][1] = 100;
          deck[cardindeck(deck,temp)][2] = 100;
          cards[numberofcards][0] = temp[0];
          cards[numberofcards][1] = temp[1];
          cards[numberofcards][2] = temp[2];
          numberofcards++;
          cout << "choice made!" << endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else {
        cout << "You have put invalid choice!" << endl;
        continue;
      }
    }
  }
}
void deal(int deck[][3], int cards[][3], int &numberofcards){
  srand(time(NULL));
  int numcard = numberofcards + 1;
  char option;
  int temp[3];
  while(numberofcards != numcard){
    srand(time(NULL));
    cout << "Which Color do you want to pick? (B/W): ";
    cin >> option;
    while (true){
      if (option == 'W'){
        temp[0] = 0;
        temp[1] = rand()%13;
        temp[2] = 0;
        if (cardindeck(deck,temp)>=0){
          deck[cardindeck(deck,temp)][0] = 100;
          deck[cardindeck(deck,temp)][1] = 100;
          deck[cardindeck(deck,temp)][2] = 100;
          cards[numberofcards][0] = temp[0];
          cards[numberofcards][1] = temp[1];
          cards[numberofcards][2] = temp[2];
          numberofcards++;
          cout << "choice made!"<< endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else if (option == 'B'){
        temp[0] = 1;
        temp[1] = rand()%13;
        temp[2] = 0;
        if (cardindeck(deck,temp)>=0){
          deck[cardindeck(deck,temp)][0] = 100;
          deck[cardindeck(deck,temp)][1] = 100;
          deck[cardindeck(deck,temp)][2] = 100;
          cards[numberofcards][0] = temp[0];
          cards[numberofcards][1] = temp[1];
          cards[numberofcards][2] = temp[2];
          numberofcards++;
          cout << "choice made!" << endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else {
        cout << "You have put invalid choice!" << endl;
        continue;
      }
    }
  }
}

int main(){
  char option1;
  int cards[24][3], numbercards=0;
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
  char option;
  int deck[24][3];
  for (int i=0; i<12; i++){
    deck[i][0] = 0;
  }
  for (int i=12; i<24; i++){
    deck[i][0] = 1;
  }
  for (int k=1; k<13; k++){
    deck[k-1][1] = k;
  }
  for (int k=13; k<25; k++){
    deck[k-1][1] = k-12;
  }
  for (int i=0; i<24; i++){
    deck[i][2] = 0;
  }
  cout << "testing...(printing all possible cards)" << endl;
  showmycards(deck,24);
  cout << "this time, you are going to pick first 4 cards." << endl;
  primarydeal(deck,cards,numbercards);
  cout << "here is your initial cards" << endl;
  showmycards(cards,numbercards);
  cout << "testing draw for one more card?" << endl;
  deal(deck,cards,numbercards);
  cout << "drawn one more card!" << endl;
  showmycards(cards,numbercards);

  cout << "this is what is left in the deck" << endl;
  showmycards(deck,24);

  cout << "hide card?(Y/N): ";
  cin >> option;
  if (option == 'Y'){
      clrscrn();
    }
  }
