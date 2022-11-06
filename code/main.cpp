#include <iostream>

#include "WarEngine/WarEngine.h"
#include "Country/Country.h"

using namespace std;

int main() {
  WarEngine::instance().initialiseWar(5, 3, 5);
  cout << "The war has started" << endl;
  cout << "The WarEngine has been initialised (Singleton, Facade)" << endl;

  WarEngine::instance().printWarEngineData();

  do
  {
    cout << "-----------------------------------" << endl;
    cout << "Turn: " << WarEngine::instance().getCurrTurn() << endl;
  }
  while (WarEngine::instance().runTurn());

  cout << "-----------------------------------" << endl;
  cout << "The war has come to an end" << endl;
  if(WarEngine::instance().determineCurrentVictor() == 0)
  {
    cout << "Side A is the victor" << endl;
  }
  else
  {
    cout << "Side B is the victor" << endl;
  }
}

void test()
{
  srand(time(0));
  for (int i = 0; i < 10; i++)
  {
    cout << (8 + rand() % 5) << endl;
    cout << rand() % 40 + 10 << endl;
    cout << rand() % 10 + 1 << endl;
    cout << (rand() % 10 + 1) << endl;
  }
}