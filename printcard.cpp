#include <iostream>
#include <string>

using namespace std;

#define WHITE "\xE2\x98\x90"
#define BLACK "\xE2\x96\xA0"

void clrscrn(){
  cout << "\33[2J\33[1;1H" << flush;
}
void showmycards(int cards[][3], int numberofcards){
  for (int n=0; n<2; n++){
    for (int i=0; i<numberofcards; i++){
      if (cards[i][0] == 0){
        cout << WHITE WHITE WHITE WHITE WHITE WHITE<< "\t";
      }
      else {
        cout << BLACK BLACK BLACK BLACK BLACK BLACK<< "\t";
      }
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
      else {
        cout << WHITE WHITE << "**" << WHITE WHITE << "\t";
      }
    }
    else {
      if (cards[i][1] >= 1 && cards[i][1] <= 9){
        cout << BLACK BLACK << 0 << cards[i][1] << BLACK BLACK << "\t";
      }
      else if (cards[i][1] == 10 || cards[i][1] == 11){
        cout << BLACK BLACK << cards[i][1] << BLACK BLACK  << "\t";
      }
      else {
        cout << BLACK BLACK << "**" << BLACK BLACK << "\t";
      }
    }
  }
  cout << endl;
  for (int n=0; n<2; n++){
    for (int i=0; i<numberofcards; i++){
      if (cards[i][0] == 0){
        cout << WHITE WHITE WHITE WHITE WHITE WHITE << "\t";
      }
      else {
        cout << BLACK BLACK BLACK BLACK BLACK BLACK << "\t";
      }
    }
    cout << endl;
  }
  for (int i=0; i<numberofcards; i++){
    if (cards[i][2] == 1){
      cout << "Shown!" << "\t";
    }
    else {
      cout << "     " << "\t";
    }
  }
  cout << endl;
}

int main(){
  char option;
  int cards[24][3], numbercards=3;
  cards[0][0] = 0;
  cards[1][0] = 1;
  cards[0][1] = 8;
  cards[1][1] = 7;
  cards[0][2] = 0;
  cards[1][2] = 0;
  showmycards(cards,numbercards);

  cout << "hide card?(Y/N): ";
  cin >> option;
  if (option == 'Y'){
    clrscrn();
  }
}
