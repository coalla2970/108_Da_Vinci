//problem 6
//A 5-Card Hand
#include <iostream>
#include <cstdlib>

//to print the special shapes
#define SPADE "\xE2\x99\xA0"
#define CLUB "\xE2\x99\xA3"
#define HEART "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"

using namespace std;

//randomly generates 5 integers in [0,51] and stores them to c1~c5
void DealHand (int &c1, int &c2, int &c3, int &c4, int &c5){
  c1 = rand()%52;
  c2 = rand()%52;
  c3 = rand()%52;
  c4 = rand()%52;
  c5 = rand()%52;
}
//subsidary function for "Printhand"
//converts some integer values to special charactes such as "A", "J", "Q", "K".
void Printsub(int a){
  switch(a){
    case(0):
      cout << 'A';
      break;
    case(10):
      cout << 'J';
      break;
    case(11):
      cout << 'Q';
      break;
    case(12):
      cout << 'K';
      break;
    default:
      cout << a+1;
      break;
    }
}
//subsidary function for "Printhand"
//prints a suit of the card given the integer value of the poker card
void Printsub2(int a){
  if (0<=a && a<=12){
    Printsub(a);
    cout << SPADE;
  }
  else if (13<=a && a<=25){
    int check = a-13;
    Printsub(check);
    cout << HEART;
  }
  else if (26<=a && a<=38){
    int check = a-26;
    Printsub(check);
    cout << CLUB;
  }
  else if (39<=a && a<=51){
    int check = a-39;
    Printsub(check);
    cout << DIAMOND;
  }
}
//prints suit and number of card.
void PrintHand (int c1, int c2, int c3, int c4, int c5){
  Printsub2(c1);
  cout << " ";
  Printsub2(c2);
  cout << " ";
  Printsub2(c3);
  cout << " ";
  Printsub2(c4);
  cout << " ";
  Printsub2(c5);
  cout << endl;
}

//gives information about the card's rank
int cardnumber (int a){
  if (0<=a && a<=12)
    return a;
  else if (13<=a && a<=25)
    return (a-13);
  else if (26<=a && a<=38)
    return (a-26);
  else
    return (a-39);
}
//gives all 5 cards' information about their rank
void assigncardnumber(int &a, int &b, int &c, int &d, int &e, int c1, int c2, int c3, int c4, int c5){
  a = cardnumber(c1);
  b = cardnumber(c2);
  c = cardnumber(c3);
  d = cardnumber(c4);
  e = cardnumber(c5);
}
//gives information about the card's suit
//1 if spade, 2 if heart, 3 if club, 4 if diamond
int cardsuit (int a){
  if (0<=a && a<=12)
    return 1;
  else if (13<=a && a<=25)
    return 2;
  else if (26<=a && a<=38)
    return 3;
  else
    return 4;
}
//counts the number of card  of same rank in a hand
void samecount(int a, int b, int c, int d, int e, int i, int &cnt){
  if (i==a)
    cnt++;
  if (i==b)
    cnt++;
  if (i==c)
    cnt++;
  if (i==d)
    cnt++;
  if (i==e)
    cnt++;
}
//checks whether the hand is "Four of a kind"
bool IsFourOfAKind(int c1, int c2, int c3, int c4, int c5){
  int a,b,c,d,e;
  assigncardnumber(a,b,c,d,e,c1,c2,c3,c4,c5);
  for (int i=0; i<=12; i++){
    int count=0;
    samecount(a,b,c,d,e,i,count);
    if (count>=4){
      return true;
      break;
    }
    else
      continue;
  }
  return false;
}
//checks whether the hand is "Full house"
bool IsFullHouse(int c1, int c2, int c3, int c4, int c5){
  if (!(IsFourOfAKind(c1,c2,c3,c4,c5))){
    int a,b,c,d,e;
    assigncardnumber(a,b,c,d,e,c1,c2,c3,c4,c5);
    int threecount=0;
    int twocount=0;
    for (int i=0; i<=12; i++){
      int count=0;
      samecount(a,b,c,d,e,i,count);
      if (count==3){
        threecount++;
        continue;
      }
      else if (count==2){
        twocount++;
        continue;
      }
      else
        continue;
    }
  if (twocount==1 && threecount==1)
    return true;
  else
    return false;
  }
  else
    return false;
}
//checks whether the hand is a "flush"
bool IsFlush(int c1, int c2, int c3, int c4, int c5){
  int a,b,c,d,e;
  assigncardnumber(a,b,c,d,e,c1,c2,c3,c4,c5);
  for (int i=1; i<=4; i++){
    int count=0;
    samecount(a,b,c,d,e,i,count);
    if (count==5){
      return true;
      break;
    }
    else
      continue;
  }
  return false;
}
//checks whether the hand is a "three of a kind"
//"three of a kind" must not be "four of a kind".
bool IsThreeOfAKind(int c1, int c2, int c3, int c4, int c5){
  if (!(IsFourOfAKind(c1,c2,c3,c4,c5)) && !(IsFullHouse(c1,c2,c3,c4,c5))){
    int a,b,c,d,e;
    assigncardnumber(a,b,c,d,e,c1,c2,c3,c4,c5);
    for (int i=0; i<=12; i++){
      int count=0;
      samecount(a,b,c,d,e,i,count);
      if (count==3){
        return true;
        break;
      }
      else
        continue;
    }
    return false;
  }
  else
    return false;
}
//checks whether the hand is a "two of a kind"
//must not be a "Four of a Kind", "Full house", or "Three of a kind"
bool IsTwoPair(int c1, int c2, int c3, int c4, int c5){
  if (!(IsFourOfAKind(c1,c2,c3,c4,c5)) && !(IsFullHouse(c1,c2,c3,c4,c5)) && !(IsThreeOfAKind(c1,c2,c3,c4,c5))){
    int a,b,c,d,e;
    assigncardnumber(a,b,c,d,e,c1,c2,c3,c4,c5);
    int twocount=0;
    for (int i=0; i<=12; i++){
      int count=0;
      samecount(a,b,c,d,e,i,count);
      if (count==2){
        twocount++;
        continue;
      }
      else
        continue;
    }
    if (twocount==2)
      return true;
    else
      return false;
  }
  else
    return false;
}
//checks whether the hand is "one pair"
//must not be other kind of suit such as "Full House", "Three of a kind", ...
bool IsOnePair(int c1, int c2, int c3, int c4, int c5){
  if (!(IsFourOfAKind(c1,c2,c3,c4,c5)) && !(IsFullHouse(c1,c2,c3,c4,c5)) && !(IsThreeOfAKind(c1,c2,c3,c4,c5)) && !(IsTwoPair(c1,c2,c3,c4,c5))){
    int a,b,c,d,e;
    assigncardnumber(a,b,c,d,e,c1,c2,c3,c4,c5);
    for (int i=0; i<=12; i++){
      int count=0;
      samecount(a,b,c,d,e,i,count);
      if (count==2){
        return true;
        break;
      }
      else
        continue;
    }
    return false;
  }
  else
    return false;
}
//main function
//resets the pattern for random numbers by using user-input seed values
//brings together all pre-defined functions
//prints "others" when no suit is found in a hand
int main(){
  int x,c1,c2,c3,c4,c5;
  cin >> x;
  srand(x);
  DealHand(c1,c2,c3,c4,c5);
  PrintHand(c1,c2,c3,c4,c5);
  if(IsFourOfAKind(c1,c2,c3,c4,c5)){
    cout << "four of a kind" << endl;
  }
  if(IsFullHouse(c1,c2,c3,c4,c5)){
    cout << "full house" << endl;
  }
  if(IsFlush(c1,c2,c3,c4,c5)){
    cout << "flush" << endl;
  }
  if(IsThreeOfAKind(c1,c2,c3,c4,c5)){
    cout << "three of a kind" << endl;
  }
  if(IsTwoPair(c1,c2,c3,c4,c5)){
    cout << "two pair" << endl;
  }
  if(IsOnePair(c1,c2,c3,c4,c5)){
    cout << "one pair" << endl;
  }
  if(!(IsFourOfAKind(c1,c2,c3,c4,c5)) && !(IsFullHouse(c1,c2,c3,c4,c5))
      && !(IsFlush(c1,c2,c3,c4,c5)) && !(IsThreeOfAKind(c1,c2,c3,c4,c5))
      && !(IsTwoPair(c1,c2,c3,c4,c5)) && !(IsOnePair(c1,c2,c3,c4,c5))){
    cout << "others" << endl;
  }
  return 0;
}
