#include <iostream>
using namespace std;

int main(){
  unsigned char halfLimit = 150;
  int count=0;
  for (unsigned char i=0; i < (2*halfLimit); ++i){
    count++;
  }
  cout << count;
  return 0;
}

