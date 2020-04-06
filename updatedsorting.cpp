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
string choice;
int confirmation = 1;
while(confirmation == 1){
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
void showcardsback(int cards[][3], int numberofcards){
for (int n=0; n<2; n++){
  for (int i=0; i<=numberofcards-1; i++){
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
for (int i=0; i<=numberofcards-1; i++){
  if (cards[i][0] == 0 && cards[i][2] == 0){
    cout << WHITE WHITE WHITE WHITE WHITE WHITE<< "\t";
  }
  else if (cards[i][0] == 1 && cards[i][2] == 0){
    cout << BLACK BLACK BLACK BLACK BLACK BLACK<< "\t";
  }
  else if (cards[i][0] == 0 && cards[i][2] == 1){
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
  else if (cards[i][0] == 1 && cards[i][2] == 1){
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
  else
    pass();
}
cout << endl;
for (int n=0; n<2; n++){
  for (int i=0; i<=numberofcards-1; i++){
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
void subsort(int last, int &newpos, int cards[][3],int n,int num, int col){
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
}
void naturalsort(int cards[][3], int first, int last,int &posnew){
  int num,col;
  num=cards[last][1];
  col=cards[last][0];
  for (int i=first; i<=last; i++){
    if (cards[i][1]>num){
      posnew=i;
      break;
    }
    else if (cards[i][1]==num){
      if(cards[i][0]==1 && col==0){
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
void moving(int cards[][3], int numberofcards, int &posanswer){
  int last=numberofcards-1;
  int num,col;
  num=cards[last][1];
  col=cards[last][0];
  showmycards(cards,numberofcards);
  cout << "Please choose a position of a new tile! (leftmost=1):";
  while (!(cin>>posanswer)){
    cout << "Please input a vaild number.\nPosition?";
    cin.clear();
    while (cin.get() != '\n'){
    }
  }
  for (int l=0; l<2; l++){
    for (int i=posanswer-1; i<last ; i++){
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
        if(cards[i][0]==0 && col==1){
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
      if ((cards[m][1] > num && cards[m][1]!=12)|| cards[posanswer-1][1]<num){
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
      else if (cards[posanswer-2][1]==num){
        if(cards[posanswer-2][0]==0 && col==1){
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
void sorting(int cards[][3],int numberofcards,int joker[]){
int newpos,n=0;
int posanswer,posnew;
int last=numberofcards-1;
int num,col;
num=cards[last][1];
col=cards[last][0];
if (num==12){
  cout<<"Cp0"<<endl;
  if (col==0 && joker[1]==0){
    n=0;
    subsort(last,newpos,cards,n,num,col);
    joker[0]=1;
    joker[2]=newpos-1;
    cout << "cp1" << endl;
  }
  else if(col==1 && joker[0]==0){
    if(cards[last-1][1]!=12){
      n=1;
      subsort(last,newpos,cards,n,num,col);
      joker[1]=1;
      joker[3]=newpos-1;
      cout << "cp2"<<endl;
      cout<< joker[0] <<joker[1]<<endl;;
    }
    else if (cards[last-1][1]==12 && cards[last-1][0]==0){
      int whitejnum=12, whitejcol=0;
      n=0;
      subsort(last,newpos,cards,n,whitejnum,whitejcol);
      joker[0]=1;
      joker[2]=newpos-1;
      n=1;
      subsort(last,newpos,cards,n,num,col);
      joker[1]=1;
      joker[3]=newpos-1;
      cout << "cp3"<<endl;
      cout<< joker[0] <<joker[1]<<endl;
    }
  }
  else if (col==0 && joker[1]==1){
    n=0;
    subsort(last,newpos,cards,n,num,col);
    joker[0]=1;
    joker[2]=newpos-1;
  }
  else if (col==1 && joker[0]==1){
    n=1;
    subsort(last,newpos,cards,n,num,col);
    joker[1]=1;
    joker[3]=newpos-1;
  }
}
else{
  if(joker[0]==0 && joker[1]==0){
    naturalsort(cards,0,last,posnew);
    cout << "cp4" << endl;
  }
  else if (joker[0]==1 && joker[1]==1){
    int firstj=min(joker[2],joker[3]);
    int secondj=max(joker[2],joker[3]);
    if(firstj==0){
      if (cards[secondj+1][1]<num){
        naturalsort(cards,secondj+1,last,posnew);
        cout << "cp5" << endl;
      }
      else{
        moving(cards,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp6" << endl;
      }
    }
    else if (secondj==last-1){
      if (cards[firstj-1][1]>num){
        naturalsort(cards,0,firstj-1,posnew);
        cout << "cp7" << endl;
      }
      else{
        moving(cards,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp8" << endl;
      }
    }
    else if (joker[2]-joker[3]==-1 || joker[2]-joker[3]==1){
      if (num<cards[firstj-1][1]){
        naturalsort(cards,0,firstj-1,posnew);
        cout << "cp9" << endl;
      }
      else if(num>cards[secondj+1][1]){
        naturalsort(cards,secondj+1,last,posnew);
        cout << "cp10" << endl;
      }
      else{
        moving(cards,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp11" << endl;
      }
    }
    else{
      if (num<cards[firstj-1][1]){
        naturalsort(cards,0,firstj-1,posnew);
        cout << "cp12" << endl;
      }
      else if(num>cards[secondj+1][1]){
        naturalsort(cards,secondj+1,last,posnew);
        cout << "cp13" << endl;
      }
      else if(num>cards[firstj-1][1] && num<cards[secondj-1][1]){
        naturalsort(cards,firstj+1,secondj-1,posnew);
        cout << "cp14" << endl;
      }
      else{
        moving(cards,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp15" << endl;
      }
    }
  }
  else{
    int posj;
    cout<< joker[0] <<joker[1]<<posj<<endl;
    if (joker[0]==0){
      posj=joker[3];
    }
    else{
      posj=joker[2];
    }
    if(posj==0){
      if (cards[posj+1][1]<num){
        naturalsort(cards,posj+1,last,posnew);
        cout << "cp16" << endl;
      }
      else{
        moving(cards,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp17" << endl;
      }
    }
    else if (posj==last-1){
      if (cards[posj-1][1]>num){
        naturalsort(cards,0,posj-1,posnew);
        cout << "cp18" << endl;
      }
      else{
        moving(cards,numberofcards,posanswer);
        posnew=posanswer-1;
        cout << "cp19" << endl;
      }
    }
    else if (num<cards[posj-1][1]){
      naturalsort(cards,0,posj-1,posnew);
      cout << "cp20" << endl;
    }
    else if(num>cards[posj+1][1]){
      naturalsort(cards,posj+1,last,posnew);
      cout << "cp21" << endl;
    }
    else{
      moving(cards,numberofcards,posanswer);
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
    cards[k][1]=cards[k-1][1];
    cards[k][0]=cards[k-1][0];
  }
  cards[posnew][1]=num;
  cards[posnew][0]=col;
}
}
void newcardinfo(int newcard[],int cards[][3],int numberofcards){
newcard[0]=cards[numberofcards-1][0];
newcard[1]=cards[numberofcards-1][1];
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
  clrscrn();
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
void guessing(int opponentcard[][3], int mycard[][3], int newcard[], int numberofcards, int opponentcards, string player, int password){
while(true){
  char choice;
  int position=1000;
  int number=1000;
  cout << "here is the back of your opponent's cards: " << endl;
  showcardsback(opponentcard, opponentcards);
  cout << "which card do you want to pick?(leftmost - 1): ";
  cin >> position;
  cout << "please guess the number of the chosen card: ";
  cin >> number;
  if (number == opponentcard[position-1][1]){
    cout << "you have guessed it correctly!" << endl;
    opponentcard[position-1][2] = 1;
    cout << "you have guessed it correctly. do you want to guess more? (Y/N): ";
    cin >> choice;
    if (choice == 'Y')
      continue;
    else
      break;
  }
  else{
    cout << "oops, you have guessed it wrong!" << endl;
    for (int i=0; i<numberofcards; i++){
      if (mycard[i][0] == newcard[0] && mycard[i][1] == newcard[1]){
        mycard[i][2] = 1;
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
bool didsomebodylose(int playercard[][3], int numberofcards){
int decision = 0;
for (int i=0; i<numberofcards; i++){
  if (playercard[i][2] == 0){
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
int main(){
char option1;
string player1,player2;
int password[3],joker1[4]={0,0,0,0},joker2[4]={0,0,0,0},newcardplayer1[3],newcardplayer2[3], turn=1;
int numbercards=0,numbercards1=4,numbercards2=4,cards1[24][3],cards2[24][3];
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
while((didsomebodylose(cards1,numbercards1)||didsomebodylose(cards2,numbercards2))){
  if (turn == 1){
    cout << player1 << ", it's your turn!" << endl;
    checkpassword(player1,password[1]);
    cout << "The remaining cards are:" << endl;
    showcardsback(deck,24);
    cout << "Please draw one more card!" << endl;
    deal(deck,cards1,numbercards1);
    cout << endl;
    newcardinfo(newcardplayer1,cards1,numbercards1);
    sorting(cards1,numbercards1,joker1);
    cout << joker1[0] << joker1[1] << endl;
    cout << endl;
    cout << "here is your card: " << endl;
    showmycards(cards1,numbercards1);
    cout << endl;
    guessing(cards2,cards1,newcardplayer1,numbercards1,numbercards2,player1,password[1]);
    turn = 2;
    clrscrn();
  }
  else{
    cout << player2 << ", it's your turn!" << endl;
    checkpassword(player2,password[2]);
    cout << "The remaining cards are:" << endl;
    showcardsback(deck,24);
    cout << "Please draw one more card!" << endl;
    deal(deck,cards2,numbercards2);
    cout << endl;
    newcardinfo(newcardplayer2,cards2,numbercards2);
    sorting(cards2,numbercards2,joker2);
    cout << joker2[0] << joker2[1] << endl;
    cout << endl;
    cout << "here is your card: " << endl;
    showmycards(cards2,numbercards2);
    cout << endl;
    guessing(cards1,cards2,newcardplayer2,numbercards2,numbercards1,player2,password[2]);
    turn = 1;
    clrscrn();
  }
}
cout << "game ended!" << endl;
}
