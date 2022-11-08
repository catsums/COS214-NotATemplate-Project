#include <iostream>

#include "WarEngine/WarEngine.h"
#include "Country/Country.h"

using namespace std;

int main() {
  srand(time(0));

  WarEngine::instance().initialiseWar(5, 3, 5);
  
  cout << "The WarEngine has been initialised (Singleton)(Facade)" << endl;
  cout << "Phase changed to: War (State)" << endl;
  //WarEngine::instance().printWarEngineData();

  do
  {
    WarEngine::instance().printWarEngineData();

    cout<<"[Press Enter to continue....]"<<endl;
    cin.get();

    cout << "-----------------------------------" << endl;
    cout << "Turn: " << WarEngine::instance().getCurrTurn() << endl;
    cout << endl;
  }
  while (WarEngine::instance().runTurn() && !WarEngine::instance().speedUp());

  do
  {
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
  cout << "The war lasted " << (WarEngine::instance().getMCnt() / 12) << " years and " << (WarEngine::instance().getMCnt() % 12) << " months";
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