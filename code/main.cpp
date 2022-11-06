#include <iostream>

#include "WarEngine/WarEngine.h"
#include "Country/Country.h"

using namespace std;

int main() {
  WarEngine::instance().initialiseWar(5, 3, 10);
  WarEngine::instance().printWarEngineData();
  WarEngine::instance().runTurn();
}