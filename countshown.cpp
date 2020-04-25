//countshown.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include "countshown.h"
#include "card.h"
using namespace std;

int countshown(card cards[], int numberofcards){
  int count = 0;
  for (int i=0; i<numberofcards; i++){
    if (cards[i].shown == 1){
      count++;
    }
    else{
      continue;
    }
  }
  return count;
}
