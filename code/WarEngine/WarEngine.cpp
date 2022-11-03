#include <iostream>
#include <vector>
#include <fstream>

#include "WarEngine.h"

using namespace std;

WarEngine::WarEngine(){

}

void WarEngine::initialiseWar(int numCountries, int sSize){

  string cName;
  ifstream ifile("countryNames.txt");

  for(int i = 0; i < numCountries; i++)
  {
    getline (ifile, cName);

    if(i < aSize)
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
  
}

void WarEngine::printWarEngineData()
{
  cout << "Countries participating in the war:" << endl;
  for(int i = 0; i < countryArr.size(); i++)
  {
    if(countryArr[i]->getSide())
    cout << "Countries participating in the war:" << endl;
  }
}

WarEngine::~WarEngine(){}

WarEngine& WarEngine::instance(){
  static WarEngine onlyInstance_;
  return onlyInstance_;
}
