#include <iostream>

#include "WarEngine/WarEngine.h"
#include "Country/Country.h"

using namespace std;

int main(){
  WarEngine::instance().initialiseWar(5, 3, 10);
  WarEngine::instance().printWarEngineData();
  WarEngine::instance().runTurn();

  /*srand(time(0));
  for (int i = 0; i < 10; i++)
  {
    cout << (8 + rand() % 5) << endl;
    //cout << rand() % 40 + 10 << endl;
  }*/
  
}