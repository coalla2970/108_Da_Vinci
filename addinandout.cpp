#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

#define WHITE "\xE2\x98\x90"
#define BLACK "\xE2\x96\xA0"

struct card{
  char color;
  int number;
  int shown;
};
//0 - white, 1 - Black
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
void primarysort(card deck[], int numberofcards){
int bigger,switchcolor;
for (int i=0; i<numberofcards; i++){
  for (int j=i+1; j<numberofcards; j++){
    if (deck[i].number > deck[j].number){
      bigger=deck[i].number;
      deck[i].number=deck[j].number;
      deck[j].number=bigger;
      switchcolor=deck[i].color;
      deck[i].color=deck[j].color;
      deck[j].color=switchcolor;
    }
    else if (deck[i].number == deck[j].number){
      if (deck[i].color == 'B' && deck[j].color == 'W'){
        deck[i].color = 'W';
        deck[j].color = 'B';
      }
    }
  }
}
}
void showmycards(card deck[], int numberofcards){
string choice;
int confirmation = 1;
while(confirmation == 1){
  for (int n=0; n<2; n++){
    for (int i=0; i<numberofcards; i++){
      if (deck[i].color == 'W'){
        cout << WHITE WHITE WHITE WHITE WHITE WHITE<< "\t";
      }
      else {
        cout << BLACK BLACK BLACK BLACK BLACK BLACK<< "\t";
      }
    }
    cout << endl;
  }
  for (int i=0; i<numberofcards; i++){
    if (deck[i].color == 'W'){
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
    else {
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
  }
  cout << endl;
  for (int n=0; n<2; n++){
    for (int i=0; i<numberofcards; i++){
      if (deck[i].color == 'W'){
        cout << WHITE WHITE WHITE WHITE WHITE WHITE << "\t";
      }
      else {
        cout << BLACK BLACK BLACK BLACK BLACK BLACK << "\t";
      }
    }
    cout << endl;
  }
  for (int i=0; i<numberofcards; i++){
    if (deck[i].shown == 1){
      cout << "Shown!" << "\t";
    }
    else {
      cout << "     " << "\t";
    }
  }
  cout << endl;
  while(true){
    cout << "confirm that you have seen the cards (Y/N): ";
    cin >> choice;
    if (choice == "Y"){
      confirmation = 0;
      break;
    }
    else if (choice == "N"){
      break;
    }
    else
      cout << "invalid input!" << endl;
  }
}
}
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
void subsort(int last, int &newpos, card deck[], int n, int num, char col, int sho, int joker[]){
showmycards(deck,last+1);
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
  if (joker[2]==i){
    joker[2]=joker[2]+1;
  }
  if (joker[3]==i){
    joker[3]=joker[3]+1;
  }
  deck[i].number = deck[i-1].number;
  deck[i].color = deck[i-1].color;
  deck[i].shown = deck[i-1].shown;
}
deck[newpos-1].number = num;
deck[newpos-1].color = col;
deck[newpos-1].shown = sho;
}
void naturalsort(card deck[], int first, int last, int &posnew, int numberofcards){
  int num;
  char col;
  num=deck[numberofcards-1].number;
  col=deck[numberofcards-1].color;
  for (int i=first; i<=last; i++){
    if (deck[i].number > num){
      posnew=i;
      break;
    }
    else if (deck[i].number == num){
      if(col == 'W'){
        posnew=i;
        break;
      }
      else{
        posnew=i+1;
        break;
      }
    }
    else {
      continue;
    }
  }
}
void moving(card deck[], int numberofcards, int &posanswer){
  int last=numberofcards-1;
  int num;
  char col;
  num = deck[last].number;
  col = deck[last].color;
  showmycards(deck,numberofcards);
  cout << "Please choose a position of a new tile! (leftmost=1):";
  while (!(cin>>posanswer)){
    cout << "Please input a vaild number.\nPosition?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }
  for (int l=0; l<2; l++){
    for (int i=posanswer-1; i<last ; i++){
      if ((num > deck[i].number) && deck[i].number!=12){
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
      else if(deck[i].number == num){
        if(deck[i].color == 0 && col == 'B'){
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
        else{
          break;
        }
      }
    }
    if(posanswer==1){
      break;
    }
    else{
      pass();
    }
    for (int m=0; m<posanswer-1; m++){
      if ((deck[m].number > num && deck[m].number != 12) || deck[posanswer-1].number < num){
        cout << "Error 3 Invalid move. Please consider the tile order! Position? (leftmost=1):";
        while (!(cin>>posanswer)){
          cout << "Please input a vaild number.\nPosition?";
          cin.clear();
          while (cin.get() != '\n'){
          }
        }
        m=-1;
        continue;
      }
      else if (deck[posanswer-2].number == num){
        if(deck[posanswer-2].color == 'W' && col == 'B'){
          break;
        }
        else{
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
      }
      else continue;
    }
  }
}
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
      subsort(last,newpos,deck,n,whitejnum,whitejcol,0,joker);
      joker[0]=1;
      joker[2]=newpos-1;
      n=1;
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
    if(firstj==0){
      if (deck[secondj+1].number < num){
        naturalsort(deck,secondj+1,last,posnew,numberofcards);
        cout << "cp5" << endl;
      }
      else{
        moving(deck,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp6" << endl;
      }
    }
    else if (secondj==last-1){
      if (deck[firstj-1].number > num){
        naturalsort(deck,0,firstj-1,posnew,numberofcards);
        cout << "cp7" << endl;
      }
      else{
        moving(deck,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp8" << endl;
      }
    }
    else if (joker[2]-joker[3]==-1 || joker[2]-joker[3]==1){
      if (num < deck[firstj-1].number){
        naturalsort(deck,0,firstj-1,posnew,numberofcards);
        cout << "cp9" << endl;
      }
      else if(num > deck[secondj+1].number){
        naturalsort(deck,secondj+1,last,posnew,numberofcards);
        cout << "cp10" << endl;
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
      else if(num > deck[firstj-1].number && num < deck[secondj+1].number){
        naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
        cout << "cp14" << endl;
      }
      else if(num == deck[firstj-1].number){
        if(deck[firstj-1].color == 'W'){
          naturalsort(deck,firstj+1,secondj-1,posnew,numberofcards);
        }
        else{
          moving(deck,numberofcards,posanswer);
          posnew=posanswer-1;
        }
      }
      else if(num == deck[secondj+1].number){
        if(deck[secondj+1].color == 'B'){
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
void newcardinfo(card &newcard, card playercards[], int numberofcards){
  cout << "saving new card info..." << endl;
  newcard.color = playercards[numberofcards-1].color;
  newcard.number = playercards[numberofcards-1].number;
  newcard.shown = playercards[numberofcards-1].shown;
}
int cardindeck(card deck[], card temp){
int check = -1;
for (int i=0; i<24; i++){
  if (deck[i].color == temp.color && deck[i].number == temp.number && deck[i].shown == temp.shown){
    check = i;
    break;
  }
  else
    pass();
}
return check;
}
void primarydeal(card deck[], card cards1[], card cards2[], string player1, string player2,
int &numberofcards){
srand(time(NULL));
char option;
card temp;
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
        temp.color = 'W';
        temp.number = rand()%13;
        temp.shown = 0;
        if (cardindeck(deck,temp)>=0 && i==1){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards1[numberofcards].color = temp.color;
          cards1[numberofcards].number = temp.number;
          cards1[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!"<< endl;
          srand(time(NULL));
          break;
        }
        else if (cardindeck(deck,temp)>=0 && i==2){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards2[numberofcards].color = temp.color;
          cards2[numberofcards].number = temp.number;
          cards2[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!"<< endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else if (option == 'B'){
        temp.color = 'B';
        temp.number = rand()%13;
        temp.shown = 0;
        if (cardindeck(deck,temp)>=0 && i==1){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards1[numberofcards].color = temp.color;
          cards1[numberofcards].number = temp.number;
          cards1[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!" << endl;
          srand(time(NULL));
          break;
        }
        else if (cardindeck(deck,temp)>=0 && i==2){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards2[numberofcards].color = temp.color;
          cards2[numberofcards].number = temp.number;
          cards2[numberofcards].shown = temp.shown;
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
  clrscrn();
}
}
void deal(card deck[], card cards[], int &numberofcards){
srand(time(NULL));
int numcard = numberofcards + 1;
char option;
card temp;
bool deckhaswhite;
bool deckhasblack;
for (int i=0; i<24; i++){
  if (deck[i].color == 'W'){
    deckhaswhite = true;
    break;
  }
}
for (int i=0; i<24; i++){
  if (deck[i].color == 'B'){
    deckhasblack = true;
    break;
  }
}
while(numberofcards != numcard){
  srand(time(NULL));
  cout << "Which Color do you want to pick? (B/W): ";
  cin >> option;
  while (true){
    if (option == 'W'){
      temp.color = 'W';
      temp.number = rand()%13;
      temp.shown = 0;
      if (deckhaswhite){
        if (cardindeck(deck,temp)>=0){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards[numberofcards].color = temp.color;
          cards[numberofcards].number = temp.number;
          cards[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!"<< endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else{
        cout << "deck has no more white!" << endl;
        break;
      }
    }
    else if (option == 'B'){
      temp.color = 'B';
      temp.number = rand()%13;
      temp.shown = 0;
      if (deckhasblack){
        if (cardindeck(deck,temp)>=0){
          deck[cardindeck(deck,temp)].color = 'N';
          deck[cardindeck(deck,temp)].number = 100;
          deck[cardindeck(deck,temp)].shown = 100;
          cards[numberofcards].color = temp.color;
          cards[numberofcards].number = temp.number;
          cards[numberofcards].shown = temp.shown;
          numberofcards++;
          cout << "choice made!" << endl;
          srand(time(NULL));
          break;
        }
        else
          continue;
      }
      else{
        cout << "deck has no more black!" << endl;
        break;
      }
    }
    else {
      cout << "You have put invalid choice! Please put a choice again!" << endl;
      break;
    }
  }
}
}
void guessing(card opponentcard[], card mycard[], card &newcard, int numberofcards, int opponentcards, string player, int password){
while(true){
  char choice;
  int position=1000;
  int number=1000;
  cout << "here is the back of your opponent's cards: " << endl;
  showcardsback(opponentcard, opponentcards);
  cout << endl;
  cout << "which card do you want to pick?(leftmost - 1): ";
  while (!(cin>>position)){
    cout << "Please input a vaild number.\nPosition?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }
  cout << "please guess the number of the chosen card (Joker: 12): ";
  while (!(cin>>number)){
    cout << "Please input a vaild number.\nPosition?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }
  if (opponentcard[position-1].shown == 0 && number == opponentcard[position-1].number){
    cout << "you have guessed it correctly!" << endl;
    opponentcard[position-1].shown = 1;
    cout << "you have guessed it correctly. do you want to guess more? (Y/N): ";
    cin >> choice;
    if (choice == 'Y')
      continue;
    else
      break;
  }
  else if (opponentcard[position-1].shown == 1 && number == opponentcard[position-1].number){
    cout << "This is already shown! please consider other choice.";
    cout << endl;
  }
  else {
    cout << "oops, you have guessed it wrong!" << endl;
    for (int i=0; i<numberofcards; i++){
      if (mycard[i].color == newcard.color && mycard[i].number == newcard.number){
        mycard[i].shown = 1;
      }
      else
        pass();
    }
    break;
  }
}
cout << "please confirm your moves by putting your password: " << endl;
checkpassword(player,password);
}
bool didsomebodylose(card playercard[], int numberofcards){
int decision = 0;
for (int i=0; i<numberofcards; i++){
  if (playercard[i].shown == 0){
    decision = 1;
    break;
  }
  else
    continue;
}
if (decision == 0)
  return false;
else
  return true;
}
void recall_data(card cards[],card deck[],int &numbercards,int &numberofcards,
int joker[],int password[],int &turn,string &player,char &recall){
  ifstream fin;
  fin.open("previousinfo.txt");
  if (recall=='Y'){
    for (int i=0;i<3;i++){
      for(int j=0;j<numberofcards;j++){
        if(i==0){
          fin>> cards[j].color ;
        }
        else if(i==1){
          fin>> cards[j].number;
        }
        else if(i==2){
          fin>> cards[j].shown ;
        }
      }
    }
    for (int k=0;k<3;k++){
      for(int l=0;l<numbercards;l++){
        if(k==0){
          fin>> deck[l].color;
        }
        else if(k==1){
          fin>> deck[l].number ;
        }
        else if(k==2){
          fin>>deck[l].shown ;
        }
      }
    }
    fin>> numbercards ;
    fin>> numberofcards;
    for (int m=0;m<4;m++){
      fin>> joker[m] ;
    }
    for (int n=0; n<3;n++){
      fin>>password[n];
    }
    fin>>turn;
    fin>>player;
  }
  else if(recall=='N'){
    cout << "Starting new game!" << endl;
  }
  else{
    cout << "Please put valid input"<<endl;
  }
}
void save_data(card cards[],card deck[],int &numbercards,int &numberofcards,
int joker[],int password[],int &turn,string &player,char save){
  if (save=='Y'){
    ofstream fout;
    fout.open("previousinfo.txt",ios::app);
    if (fout.fail()){
      cout<<"Error in opening file!" <<endl;
    }
    for (int i=0;i<3;i++){
      for(int j=0;j<numberofcards;j++){
        if(i==0){
            fout << cards[j].color << " ";
        }
        else if(i==1){
            fout << cards[j].number << " ";
        }
        else if(i==2){
            fout << cards[j].shown<< " ";
        }
      }
    }
    for (int k=0;k<3;k++){
      for(int l=0;l<numbercards;l++){
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
    }
    fout << numbercards << " ";
    fout << numberofcards <<" ";
    for (int m=0;m<4;m++){
        fout << joker[m] <<" ";

    }
    for (int n=0; n<3;n++){
        fout << password[n] <<" ";
    }
    fout<<turn <<" ";
    fout<<player<< " ";
    fout.close();
  }
  else if (save=='N'){
    cout<< "Please continue the game!" << endl;
  }
  else{
    cout << "Please put valid input"<<endl;
  }
}
int main(){
char recall;
char option1;
string player1,player2;
int password[3];
int joker1[4]={0,0,0,0};
int joker2[4]={0,0,0,0};
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
fin.open("previousinfo.txt");
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
  recall_data(cards1,deck,numbercards,numbercards1,joker1,password,turn,player1,recall);
  recall_data(cards2,deck,numbercards,numbercards2,joker2,password,turn,player2,recall);
  fin.close();
  cout<< cards1[0].color << endl;
  cout<<cards1[1].color<<endl;
  cout << cards2[0].color<<endl;
  cout<< cards2[1].color<<endl;
  cout <<player1 <<endl;
  cout << password[1]<<endl;
  if(recall!='Y'){
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
}
while((didsomebodylose(cards1,numbercards1)||didsomebodylose(cards2,numbercards2))){
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
    turn = 2;
    char save;
    cout << "Do you want to save this game and end this game? (Y/N)";
    cin >> save;
    save_data(cards1, deck, numbercards, numbercards1, joker1, password, turn, player1,save);
    save_data(cards2, deck, numbercards, numbercards2, joker2, password, turn, player2,save);
    if(save=='Y'){
      exit(1);
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
    turn = 1;
    char save;
    cout << "Do you want to save this game and end this game? (Y/N)";
    cin >> save;
    save_data(cards1, deck, numbercards, numbercards1, joker1, password, turn, player1,save);
    save_data(cards2, deck, numbercards, numbercards2, joker2, password, turn, player2,save);
    if(save=='Y'){
      exit(1);
    }
    clrscrn();
  }
}
cout << "game ended!" << endl;
}
