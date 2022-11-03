#include <iostream>
#include <vector>
#include <fstream>

#include "WarEngine.h"

using namespace std;

WarEngine::WarEngine(){

}

void WarEngine::initialiseWar(int numCountries, int sSize, int maxTurn){
  this->maxTurn = maxTurn;
  currTurn = 0;
  string cName;
  ifstream ifile("countryNames.txt");

  for(int i = 0; i < numCountries; i++)
  {
    getline (ifile, cName);

    if(i < sSize)
    {
      countryArr.push_back(new Country(cName, 0));
    }
    else
    {
      countryArr.push_back(new Country(cName, 1));
    }
    
  }

  ifile.close();
}

bool WarEngine::runTurn(){
  currTurn++;
  
  //each country gets to act
  for(int i = 0; i < countryArr.size(); i++)
  {
    countryArr[i]->generateResources();

    //decision making
    int action;
    switch (action)
    {
      case 1: //land attack
        Country* target;
        int targetId = rand() % countryArr.size();

        //Battle b = new Battle(countryArr[i], target);

        break;
      default:
        //idle
    }
    
  }

  //end condition
  int cA = 0;
  int cB = 0;
  for(int i = 0; i < countryArr.size(); i++)
  {
    if(countryArr[i]->getSide() == 0)
    {
      cA++;
    }
    else
    {
      cB++;
    }
  }

  if(cA <= 0 || cB <= 0)
  {
    return false;
  }
  if(currTurn == maxTurn)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void WarEngine::printWarEngineData()
{
  cout << "Countries participating in the war:" << endl;

  cout << "Side A:" << endl;
  for(int i = 0; i < countryArr.size(); i++)
  {
    if(countryArr[i]->getSide() == 0)
    {
      cout << countryArr[i]->getName() << endl;
    }
    cout << endl;
  }

  cout << "Side B:" << endl;
  for(int i = 0; i < countryArr.size(); i++)
  {
    if(countryArr[i]->getSide() == 1)
    {
      cout << countryArr[i]->getName() << endl;
    }
    cout << endl;
  }
}

WarEngine::~WarEngine(){}

WarEngine& WarEngine::instance(){
  static WarEngine onlyInstance_;
  return onlyInstance_;
}
