#include <iostream>
#include <vector>
#include <fstream>

#include "WarEngine.h"
#include "../Country/Country.h"

using namespace std;

WarEngine::WarEngine(){

}

void WarEngine::initialiseWar(int numCountries, int aSize){

  string cName;
  ifstream ifile("countryNames.txt");

  for(int i = 0; i < numCountries; i++)
  {
    getline (ifile, cName);

    if(i < aSize)
    {
      countries.push_back(new Country(cName, 0));
    }
    else
    {
      countries.push_back(new Country(cName, 1));
    }
    
  }

  ifile.close();
}

bool WarEngine::runTurn(){
  
}

WarEngine::~WarEngine(){}

WarEngine& WarEngine::instance(){
  static WarEngine onlyInstance_;
  return onlyInstance_;
}
