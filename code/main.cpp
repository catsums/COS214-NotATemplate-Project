#include <iostream>

#include "WarEngine/WarEngine.h"
#include "Country/Country.h"

using namespace std;

int main() {
  srand(time(0));

  WarEngine::instance().initialiseWar(5, 3, 10);
  cout << "The war has started" << endl;
  cout << "The WarEngine has been initialised (Singleton, Facade)" << endl;

  //WarEngine::instance().printWarEngineData();

  do
  {
    WarEngine::instance().printWarEngineData();
    cout << "-----------------------------------" << endl;
    cout << "Turn: " << WarEngine::instance().getCurrTurn() << endl;
    cout << endl;
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
  cout << endl;
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