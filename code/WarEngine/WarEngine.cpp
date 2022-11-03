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
    int action = 0;
    // switch (action)
    // {
    //   case 1: //land attack
    //   {
    //     int theatre = 1;
    //     Country* target;
    //     int targetId = rand() % countryArr.size();

    //     Battle* b = new Battle(countryArr[i], target, theatre);
    //     b->commence();
    //   } 
    //   break;
    //   case 2: //sea attack
    //   {
    //     int theatre = 2;
    //     Country* target;
    //     int targetId = rand() % countryArr.size();

    //     Battle* b = new Battle(countryArr[i], target, theatre);
    //     b->commence();
    //   }
    //   break;
    // }
    
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

bool WarEngine::determineCurrentVictor()
{
  int tA = 0;
  int tB = 0;
  for(int i = 0; i < countryArr.size(); i++)
  {
    if(countryArr[i]->getSide() == 0)
    {
      tA += countryArr[i]->getTerritory();
    }
    else
    {
      tB += countryArr[i]->getTerritory();
    }
  }

  return (tA >= tB) ? (true) : (false);
}

void WarEngine::printWarEngineData()
{
  cout << "Countries participating in the war:" << endl;

  cout << "Side A:" << endl;
  printSide(0);

  cout << "Side B:" << endl;
  printSide(1);
}

void WarEngine::printSide(bool side)
{
  for(int i = 0; i < countryArr.size(); i++)
  {
    if(countryArr[i]->getSide() == side)
    {
      cout << countryArr[i]->getName() << endl;
    }
  }
}

WarEngine::~WarEngine(){}

WarEngine& WarEngine::instance(){
  static WarEngine onlyInstance_;
  return onlyInstance_;
}
