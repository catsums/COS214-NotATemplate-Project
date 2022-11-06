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

  string l;
  vector<string> names;

  srand(time(0));
  ifstream nameFile("countryNames.txt");

  while(getline(nameFile, l))
  {
    names.push_back(l);
  }

  for(int i = 0; i < numCountries; i++)
  {
    int nId = rand() % names.size();
    if(i < sSize)
    {
      countryArr.push_back(new Country(names[nId], 0));
    }
    else
    {
      countryArr.push_back(new Country(names[nId], 1));
    }
    names.erase(names.begin() + nId);
  }

  nameFile.close();
}

bool WarEngine::runTurn(){
  currTurn++;
  srand(time(0));
  
  //each country gets to act
  for(int i = 0; i < countryArr.size(); i++)
  {
    cout << endl;
    
    countryArr[i]->generateResources();

    //decision making
    //Corresponding decisions:
    // 0: Idle
    // 1: Land attack
    // 2: Sea attack
    // 3: Air attack
    // 4: Recruit troops
    // 5: Build base
    // 6: Initiate diplomacy
    // 7: Change sides
    // 8: Peace talks
    
    vector<int> potentialActions;
    bool currSide = countryArr[i]->getSide();
    
    potentialActions.push_back(1);
    potentialActions.push_back(2);
    potentialActions.push_back(3);
    potentialActions.push_back(4);
    potentialActions.push_back(5);

    if((double) determineSideStrength(currSide) / determineSideStrength(!currSide) <= 0.4)
    {
      potentialActions.push_back(6);
    }

    if((double) determineSideStrength(currSide) / determineSideStrength(!currSide) <= 0.2)
    {
      potentialActions.push_back(7);
    }

    int action = potentialActions[rand() % (potentialActions.size())];

    switch (action)
    {
      case 1: //land attack
      {
        int theatre = 1;
        int targetId = 0;

        do
        {
          targetId = rand() % (countryArr.size());
        } 
        while (countryArr[targetId]->getSide() == countryArr[i]->getSide());
        
        Country* target = countryArr[targetId];

        Battle* b = new Battle(countryArr[i], target, theatre);
        b->commence();
      } 
      break;
      case 2: //sea attack
      {
        int theatre = 2;
        int targetId = 0;

        do
        {
          targetId = rand() % (countryArr.size());
        } 
        while (countryArr[targetId]->getSide() == countryArr[i]->getSide());
        
        Country* target = countryArr[targetId];

        Battle* b = new Battle(countryArr[i], target, theatre);
        b->commence();
      }
      break;
      case 3: //air attack
      {
        int theatre = 3;
        int targetId = 0;

        do
        {
          targetId = rand() % (countryArr.size());
        } 
        while (countryArr[targetId]->getSide() == countryArr[i]->getSide());
        
        Country* target = countryArr[targetId];

        Battle* b = new Battle(countryArr[i], target, theatre);
        b->commence();
      }
      break;
      case 4: //Recruit troops
      {
        cout << countryArr[i]->getName() << " is recruiting troops" << endl;
      }
      break;
      case 5: //Build base
      {
        cout << countryArr[i]->getName() << " is building a Forward Operating Base" << endl;
      }
      break;
      case 6: //Initiate diplomacy
      {
        cout << countryArr[i]->getName() << " is attempting to initiate diplomacy" << endl;
        if(rand() % 10 + 1 == 1)
        {
          cout << countryArr[i]->getName() << " has successfuly initaited diplomacy, peace talks are underway." << endl;
        }
        else
        {
          cout << countryArr[i]->getName() << " was unable to initiate diplomacy" << endl;
        }
      }
      break;
      case 7: //Change sides
      {
        cout << countryArr[i]->getName() << " is defecting! The traitors now fight for side ";
        if(countryArr[i]->getSide() == 0)
        {
          countryArr[i]->setSide(1);
          cout << "B" << endl;
        }
        else
        {
          countryArr[i]->setSide(0);
          cout << "A" << endl;
        }
      }
      break;
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

bool WarEngine::determineCurrentVictor()
{
  int tA = determineSideStrength(0);
  int tB = determineSideStrength(1);

  return (tA >= tB) ? (0) : (1);
}

int WarEngine::determineSideStrength(bool s)
{
  int t = 0;

  for(int i = 0; i < countryArr.size(); i++)
  {
    if(countryArr[i]->getSide() == s)
    {
      t += countryArr[i]->getTerritory();
    }
  }

  return t;
}

void WarEngine::printWarEngineData()
{
  cout << "Countries participating in the war:" << endl;
  cout << "-----------------------------------" << endl;
  cout << "Side A:" << endl;
  printSide(0);
  cout << "-----------------------------------" << endl;
  cout << "Side B:" << endl;
  printSide(1);
  cout << "-----------------------------------" << endl;

  cout << "Total strength of side A: " << determineSideStrength(0) << endl;
  cout << "Total strength of side B: " << determineSideStrength(1) << endl;
  if(determineCurrentVictor() == 0)
  {
    cout << "Side A is currently winning the war" << endl;
  }
  else
  {
    cout << "Side B is currently winning the war" << endl;
  }
  cout << "-----------------------------------" << endl << endl;
}

void WarEngine::printSide(bool side)
{
  for(int i = 0; i < countryArr.size(); i++)
  {
    if(countryArr[i]->getSide() == side)
    {
      cout << countryArr[i]->getName();
      cout << " | t: " << countryArr[i]->getTerritory();
      cout << " | r: " << countryArr[i]->getResources();
      cout << endl;
    }
  }
}

WarEngine::~WarEngine(){}

WarEngine& WarEngine::instance(){
  static WarEngine onlyInstance_;
  return onlyInstance_;
}

int WarEngine::getCurrTurn()
{
  return currTurn;
}