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
void welcomemsg(string &player1,string &player2,int password[]){
  int password1,password2;
  string playername;
  cout << "<The Da Vinci Code Game>\nWELCOME!" << endl;
  for (int i=1; i<=2; i++){
    int pass=0,confirmpass=1;
    cout << "Player " << i << ", What is your name?" << endl;
    cin >> playername;
    if (i==1){
      player1 = playername;
    }
    else{
      player2 = playername;
    }
    while(pass!=confirmpass){
      cout << playername <<", please set your own password!(only integer)"<< endl;
      cin >> pass;
      if (i==1){
        password1=pass;
      }
      else{
        password2=pass;
      }
      cout << "To confirm, please put your password again!" << endl;
      cin >> confirmpass;
      if (pass != confirmpass){
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
  cin >> inpass;
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
void replacejoker(int &jokerpoint,int cards[][3],int numberofcards){
  int newpos;
  for (int i=0; i<numberofcards; i++){
    if (cards[i][0]==0 && cards[i][1]==12 && jokerpoint<10){
      jokerpoint+=10;
      cout << "Where do you want to replace white joker? (leftmost=1)";
      cin >> newpos;
      for (int j=i+1; j<newpos; j++){
        if (cards[j][1]==12 && cards[j][0]==1){
          while(j<=newpos-1){
          cout << "Invalid moving. Please choose other position."<<endl;
          cout << "Where do you want to replace white joker? (leftmost=1)";
          cin >> newpos;
          }
        }
      }
      for (int k=numberofcards-1; k>=newpos-1; k--){
        cards[k][1]=cards[k-1][1];
        cards[k][0]=cards[k-1][0];
      }
      cards[newpos-1][1]=12;
      cards[newpos-1][0]=0;
      cout << "Replaced!" <<endl;
      showmycards(cards,numberofcards);
    }
    else if (cards[i][0]==1 && cards[i][1]==12 && jokerpoint!=1 && jokerpoint<11){
      jokerpoint+=1;
      cout << "Where do you want to replace black joker? (leftmost=1)";
      cin >> newpos;
      for (int j=i+1; j<newpos; j++){
        if (cards[j][1]==12 && cards[j][0]==0){
          while(j>newpos-1){
          cout << "Invalid moving. Please choose other position."<<endl;
          cout << "Where do you want to replace black joker? (leftmost=1)";
          cin >> newpos;
          }
        }
      }
      for (int k=numberofcards-1; k>=newpos-1; k--){
        cards[k][1]=cards[k-1][1];
        cards[k][0]=cards[k-1][0];
      }
      cards[newpos-1][1]=12;
      cards[newpos-1][0]=1;
      cout << "Replaced!" <<endl;
      showmycards(cards,numberofcards);
    }
  }
}
void sorting(int cards[][3], int numberofcards, int &jokerpoint){
  int newpos;
  int num,col;
  char answer;
  num=cards[numberofcards-1][1];
  col=cards[numberofcards-1][0];
  for (int i=0; i<numberofcards-1; i++){
    if (num < cards[i][1]){
      if(cards[i][1]==12){
        if((cards[i+1][1] > num)&& (i<numberofcards-2)){
          cout << "The last tile is a new tile."<< endl;
          showmycards(cards,numberofcards);
          cout << "Do you want to put a new tile before or after the joker tile? (B/A)";
          cin >> answer;
          if (answer=='B'){
            newpos=i;
            break;
          }
          else if (answer=='A'){
            newpos=i+1;
            break;
          }
        }
        else if (cards[i+1][1]==num){
          if (cards[i+1][0]==1 & col==0){
            newpos=i+1;
            break;
          }
          else{
            newpos=i+2;
            break;
          }
        }
      }
      else{
        newpos=i;
        break;
      }
    }
    else if (cards[numberofcards-1][1] == cards[i][1]){
      if(cards[numberofcards-1][1]==12 && cards[i][1]==12){
        replacejoker(jokerpoint, cards, numberofcards);
        }
      else if(cards[numberofcards-1][0]==1 && cards[i][0]==0){
        newpos=i+1;
        break;
      }
      else if(cards[numberofcards-1][0]==0 && cards[i][0]==1){
        newpos=i;
        break;
      }
    }
    else{
      newpos=i;
    }
  }
  for (int j=numberofcards-1;j>=newpos+1;j--){
    cards[j][1]=cards[j-1][1];
    cards[j][0]=cards[j-1][0];
  }
  cards[newpos][1]=num;
  cards[newpos][0]=col;
}


int main(){
  char option1;
  string player1,player2;
  int jokerpoint1=0,jokerpoint2=0;
  int password[3]={0,0,0};
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
  showmycards(cards1,numbercards);
  replacejoker(jokerpoint1,cards1,numbercards);
  cout << player2 << "'s initial cards" << endl;
  checkpassword(player2,password[2]);
  primarysort(cards2,numbercards);
  showmycards(cards2,numbercards);
  replacejoker(jokerpoint2,cards2,numbercards);
  cout << "The remaining cards are:" << endl;
  showcardsback(deck,24);
  cout << "testing draw for one more card?" << endl;
  deal(deck,cards1,numbercards);
  cout << "drawn one more card!" << endl;
  sorting(cards1,numbercards,jokerpoint1);
  showmycards(cards1,numbercards);
  replacejoker(jokerpoint1,cards1,numbercards);
  cout << "hide card?(Y/N): ";
  cin >> option;
  if (option == 'Y'){
      clrscrn();
    }
  }
