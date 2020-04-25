//emptydeck.cpp

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include "emptydeck.h"
#include "card.h"
using namespace std;

bool emptydeck(card deck[]){
  bool check = true;
  for (int i=0; i<24; i++){
    if (deck[i].color == 'N'){
      continue;
    }
    else{
      check = false;
      break;
    }
  }
  return check;
}
