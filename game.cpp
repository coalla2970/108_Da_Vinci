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
void welcomemsg(string &player1, string &player2, int password[]){
  int password1,password2;
  string playername;
  cout << "< The Da Vinci Code Game >\nWELCOME!" << endl;
  for (int i=1; i<=2; i++){
    int pass=0, confirmpass=1;
    cout << "Player " << i << ", What is your name?" << endl;
    cin>>playername;
    if(i==1){
      player1=playername;
    }
    else{
      player2=playername;
    }
    while (pass!=confirmpass){
      cout << playername <<", please set your own password!(0000-9999)" << endl;
      while (!(cin>>pass)){
        cout << "You can only use integer 0000-9999.\nPassword:\n ";
        cin.clear();
        while (cin.get() != '\n'){
        }
      }
      while (pass>9999 || pass<0){
        cout << "You can only use integer 0000-9999.\nPassword:\n ";
        cin.clear();
        while (!(cin>>pass)){
          cout << "You can only use integer 0000-9999.\nPassword:\n ";
          cin.clear();
          while (cin.get() != '\n'){
          }
        }
      }
      if (i==1){
        password1=pass;
      }
      else{
        password2=pass;
      }
      clrscrn();
      cout << "To confirm, please put your password again!" << endl;
      cin >> confirmpass;
      if (pass!=confirmpass){
        cout << "The password is wrong. Please set your password again." << endl;
      }
      else{
        password[i]=pass;
      }
    }
    clrscrn();
  }
}
void checkpassword(string player,int password){
  int inpass;
  cout << "Enter "<< player << "'s password:";
  while (!(cin>>inpass)){
    cout << "Please input a vaild number.\nPassword?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }
  while(inpass!=password){
    cout << "Wrong password, try again\nEnter the password:";
    cin >> inpass;
  }
}

void primarysort(int cards[][3], int numberofcards){
  int bigger,switchcolor;
  for (int i=0; i<numberofcards; i++){
    for (int j=i+1; j<numberofcards; j++){
      if (cards[i][1] > cards[j][1]){
        bigger=cards[i][1];
        cards[i][1]=cards[j][1];
        cards[j][1]=bigger;
        switchcolor=cards[i][0];
        cards[i][0]=cards[j][0];
        cards[j][0]=switchcolor;
      }
      else if (cards[i][1] == cards[j][1]){
        if (cards[i][0] == 1 && cards[j][0] == 0){
          cards[i][0]=0;
          cards[j][0]=1;
        }
      }
    }
  }
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
void showcardsback(int cards[][3], int numberofcards){
  for (int n=0; n<5; n++){
    for (int i=numberofcards-1; i>=0; i--){
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
}
void subsort(int last, int newpos, int cards[][3],int n,int num, int col){
  showmycards(cards,last+1);
  if (n==0){
    cout << "Where do you want to put a white joker tile? (leftmost =1)" << endl;
  }
  else{
    cout << "Where do you want to put a black joker tile? (leftmost =1)" << endl;
  }
  while (!(cin>>newpos)){
    cout << "Please input a vaild number.\nPosition?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }
  for (int i=last; i>newpos-1; i--){
    cards[i][1]=cards[i-1][1];
    cards[i][0]=cards[i-1][0];
  }
  cards[newpos-1][1]=num;
  cards[newpos-1][0]=col;
  cout << "Sorted!" <<endl;
}
void sorting(int cards[][3],int numberofcards,int joker[]){
  int newpos,n=0;
  int posanswer;
  int last=numberofcards-1;
  int num,col;
  num=cards[last][1];
  col=cards[last][0];
  if (num==12){
    if (col==0 && joker[0]==0){
      n=0;
      subsort(last,newpos,cards,n,num,col);
      joker[0]=1;
    }
    else if(col==1 && joker[1]==0){
      if(cards[last-1][1]!=12 || joker[0]==1){
        n=1;
        subsort(last,newpos,cards,n,num,col);
        joker[1]=1;
      }
      else if (cards[last-1][1]==12 && cards[last-1][0]==0 && joker[0]==0){
        n=0;
        subsort(last,newpos,cards,n,num,col);
        joker[0]=1;
        n=1;
        subsort(last,newpos,cards,n,num,col);
        joker[1]=1;
      }
    }
  }
  else{
    if(joker[0]==0 && joker[1]==0){
      for (int i=0; i<=last; i++){
        if (cards[i][1]>num){
          posanswer=i;
          break;
        }
        else if (cards[i][1]==num){
          if(cards[i][0]==1 && col==0){
            posanswer=i;
            break;
          }
          else{
            posanswer=i+1;
            break;
          }
        }
        else {
          posanswer=i;
          continue;
        }
      }
    }
    else if (joker[0]==1 || joker[1]==1){
      showmycards(cards,numberofcards);
      cout << "Please choose a position of a new tile! (leftmost=1):";
      while (!(cin>>posanswer)){
        cout << "Please input a vaild number.\nPosition?";
        cin.clear();
        while (cin.get() != '\n'){
        }
      }
      for (int l=0; l<2; l++){
        for (int i=posanswer-1; i<=last ; i++){
          if ((num > cards[i][1]) && cards[i][1]!=12){
            cout << "Error1 Invalid move. Please consider the tile order! Position? (leftmost=1):";
            while (!(cin>>posanswer)){
              cout << "Please input a vaild number.\nPosition?";
              cin.clear();
              while (cin.get() != '\n'){
              }
            }
            i=posanswer-2;
            continue;
          }
          else if(cards[i][1] == num){
            if(cards[i][0]==1 && col==0){
              break;
            }
            else if ((i==last && cards[i][0]==0 && col==0)||(i==last && cards[i][0]==1 && col==1)){
              if (cards[i-1][1]>num){
                break;
              }
              else{
                cout << "Error 2 Invalid move. Please consider the tile order! Position? (leftmost=1):";
                while (!(cin>>posanswer)){
                  cout << "Please input a vaild number.\nPosition?";
                  cin.clear();
                  while (cin.get() != '\n'){
                  }
                }
                i=posanswer-2;
                continue;
              }
            }
            else{
              cout << "Error 3 Invalid move. Please consider the tile order! Position? (leftmost=1):";
              while (!(cin>>posanswer)){
                cout << "Please input a vaild number.\nPosition?";
                cin.clear();
                while (cin.get() != '\n'){
                }
              }
              i=posanswer-2;
              continue;
            }
          }
          else continue;
        }
        if(posanswer==1){
          break;
        }
        else{
          pass();
        }
        for (int m=0; m<posanswer-1; m++){
          if ((cards[m][1] > num && cards[m][1]!=12)|| cards[posanswer-1][1]<num){
            cout << "Error 4 Invalid move. Please consider the tile order! Position? (leftmost=1):";
            while (!(cin>>posanswer)){
              cout << "Please input a vaild number.\nPosition?";
              cin.clear();
              while (cin.get() != '\n'){
              }
            }
            m=-1;
            continue;
          }
          else if (cards[posanswer-2][1]==num){
            if(cards[posanswer-2][0]==1 && col==0){
              break;
            }
            else{
              cout << "Error 5 Invalid move. Please consider the tile order! Position? (leftmost=1):";
              while (!(cin>>posanswer)){
                cout << "Please input a vaild number.\nPosition?";
                cin.clear();
                while (cin.get() != '\n'){
                }
              }
              m=-1;
              continue;
            }
          }
          else continue;
        }
      }
      posanswer=posanswer-1;
    }
    for (int k=last; k>posanswer-1; k--){
      cards[k][1]=cards[k-1][1];
      cards[k][0]=cards[k-1][0];
      }
    cards[posanswer][1]=num;
    cards[posanswer][0]=col;
    cout << "Sorted!"<<endl;
  }
}
void newcardinfo(int newcard[],int cards[][3],int numberofcards){
  newcard[0]=cards[numberofcards-1][0];
  newcard[1]=cards[numberofcards-1][1];
  cout << "New card's number is " << newcard[1] << endl;
  cout << "New card's color is " << newcard[0] << endl;
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
void primarydeal(int deck[][3], int cards1[][3], int cards2[][3],string player1, string player2,
  int &numberofcards){
  srand(time(NULL));
  char option;
  int temp[3];
  for (int i=1; i<=2; i++){
    while(numberofcards<4){
      srand(time(NULL));
      if (i==1){
        cout << player1 <<", Which Color do you want to pick? (B/W): ";
      }
      else{
        cout << player2 <<", Which Color do you want to pick? (B/W): ";
      }
      cin >> option;
      while (true){
        if (option == 'W'){
          temp[0] = 0;
          temp[1] = rand()%13;
          temp[2] = 0;
          if (cardindeck(deck,temp)>=0 && i==1){
            deck[cardindeck(deck,temp)][0] = 100;
            deck[cardindeck(deck,temp)][1] = 100;
            deck[cardindeck(deck,temp)][2] = 100;
            cards1[numberofcards][0] = temp[0];
            cards1[numberofcards][1] = temp[1];
            cards1[numberofcards][2] = temp[2];
            numberofcards++;
            cout << "choice made!"<< endl;
            srand(time(NULL));
            break;
          }
          else if (cardindeck(deck,temp)>=0 && i==2){
            deck[cardindeck(deck,temp)][0] = 100;
            deck[cardindeck(deck,temp)][1] = 100;
            deck[cardindeck(deck,temp)][2] = 100;
            cards2[numberofcards][0] = temp[0];
            cards2[numberofcards][1] = temp[1];
            cards2[numberofcards][2] = temp[2];
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
          if (cardindeck(deck,temp)>=0 && i==1){
            deck[cardindeck(deck,temp)][0] = 100;
            deck[cardindeck(deck,temp)][1] = 100;
            deck[cardindeck(deck,temp)][2] = 100;
            cards1[numberofcards][0] = temp[0];
            cards1[numberofcards][1] = temp[1];
            cards1[numberofcards][2] = temp[2];
            numberofcards++;
            cout << "choice made!" << endl;
            srand(time(NULL));
            break;
          }
          else if (cardindeck(deck,temp)>=0 && i==2){
            deck[cardindeck(deck,temp)][0] = 100;
            deck[cardindeck(deck,temp)][1] = 100;
            deck[cardindeck(deck,temp)][2] = 100;
            cards2[numberofcards][0] = temp[0];
            cards2[numberofcards][1] = temp[1];
            cards2[numberofcards][2] = temp[2];
            numberofcards++;
            cout << "choice made!" << endl;
            srand(time(NULL));
            break;
          }
          else
            continue;
        }
        else {
          cout << "You have put invalid choice! Please put a choice again!" << endl;
          break;
        }
      }
    }
    if (i==1){
      numberofcards=0;
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
        cout << "You have put invalid choice! Please put a choice again!" << endl;
        break;
      }
    }
  }
}

int main(){
  char option1;
  string player1,player2;
  int password[3],joker1[2],joker2[2],newcard1[2],newcard2[2];
  int numbercards=0, cards1[24][3],cards2[24][3];
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
  welcomemsg(player1,player2,password);
  cout << "testing...(printing all possible cards)" << endl;
  showmycards(deck,24);
  cout << "You are going to pick first 4 cards." << endl;
  primarydeal(deck,cards1,cards2,player1,player2,numbercards);
  cout << player1 << "'s initial cards" << endl;
  checkpassword(player1,password[1]);
  primarysort(cards1,numbercards);
  sorting(cards1,numbercards,joker1);
  showmycards(cards1,numbercards);
  cout << player2 << "'s initial cards" << endl;
  checkpassword(player2,password[2]);
  primarysort(cards2,numbercards);
  sorting(cards2,numbercards,joker2);
  showmycards(cards2,numbercards);
  cout << "The remaining cards are:" << endl;
  showcardsback(deck,24);
  cout << "testing draw for one more card?" << endl;
  deal(deck,cards1,numbercards);
  newcardinfo(newcard1,cards1,numbercards);
  cout << "drawn one more card!" << endl;
  showmycards(cards1,numbercards);
  sorting(cards1,numbercards,joker1);
  showmycards(cards1,numbercards);
  cout << "hide card?(Y/N): ";
  cin >> option;
  if (option == 'Y'){
      clrscrn();
    }
  }
