#include <iostream>
#include <vector>
#include <fstream>

#include "WarEngine.h"

using namespace std;

WarEngine::WarEngine() {

}

void WarEngine::initialiseWar(int numCountries, int sSize, int maxTurn){
  state = "war";

  this->maxTurn = maxTurn;
  currTurn = 1;

  string l;
  vector<string> names;
  vector<bool> coastal;

  //srand(time(0));
  ifstream nameFile("Data/countryNames.txt");

  while(getline(nameFile, l))
  {
    names.push_back(l);
    getline(nameFile, l);
    coastal.push_back(stoi(l));
  }

  for(int i = 0; i < numCountries; i++)
  {
    int nId = rand() % names.size();
    if(i < sSize)
    {
      countryArr.push_back(new Country(names[nId], 0, coastal[nId]));
    }
    else
    {
      countryArr.push_back(new Country(names[nId], 1, coastal[nId]));
    }
    names.erase(names.begin() + nId);
    coastal.erase(coastal.begin() + nId);
  }

  nameFile.close();
}

bool WarEngine::runTurn(){
  //srand(time(0));
  
  //each country gets to act
  for(int i = 0; i < countryArr.size(); i++)
  {
    countryArr[i]->generateResources();
    mCnt++;

    vector<int> potentialActions;
    bool currSide = countryArr[i]->getSide();
    
    //if(countryArr[i]->getTerritory() > 0)
    //{
      if(state == "war")
      {
        handleWar(i);
      }
      else if(state == "neg")
      {
        handleNeg(i);
      }
    //}
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

  if(state == "peace")
  {
    return false;
  }

  if(currTurn++ == maxTurn * 5)
  {
    return false;
  }
  else
  {
    return true;
  }
}

void WarEngine::handleWar(int i) 
{
  vector<int> potentialActions;
  bool currSide = getCountryArr()[i]->getSide();
  
  if(countryArr[i]->getTerritory() > 0)
  {
    //decision making
    //Corresponding decisions:
    // 0: Withdraw
    // 1: Land attack
    // 2: Sea attack
    // 3: Air attack
    // 4: Recruit troops
    // 5: Build base
    // 6: Initiate diplomacy
    // 7: Change sides
    // 8: Peace talks
    
    potentialActions.push_back(1);
    potentialActions.push_back(1);
    potentialActions.push_back(1);
    potentialActions.push_back(4);

    if (countryArr[i]->getResources() >= 200 && countryArr[i]->getFreeSpace() >= 5)
    {
      potentialActions.push_back(5);
    }

    if((double) determineSideStrength(currSide) / determineSideStrength(!currSide) <= 0.4) //diplomacy
    {
      potentialActions.push_back(6);
    }

    if((double) determineSideStrength(currSide) / determineSideStrength(!currSide) <= 0.2) //defection
    {
      int cnt = 0;
      for(int i = 0; i < countryArr.size(); i++)
      {
        if(countryArr[i]->getSide() == currSide)
        {
          cnt++;
        }
      }

      if(cnt >= 2)
      {
        potentialActions.push_back(7);
      }
      
    }
  }
  else //withdraw
  {
    potentialActions.push_back(0); 
    potentialActions.push_back(0);
    potentialActions.push_back(0);
  }
  

  int action = potentialActions[rand() % (potentialActions.size())];

  switch (action)
  {
    case 0: //Withdraw
    {
      cout << countryArr[i]->getName() << " has withdrawn from the war!" << endl;
      countryArr.erase(countryArr.begin() + i);
    } 
    break;
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
    /*case 2: //sea attack
    {
      int theatre = 2;
      int targetId = 0;
      do
      {
        targetId = rand() % (countryArr.size());
      } 
      while (countryArr[targetId]->getSide() == countryArr[i]->getSide());
      
      if(!countryArr[i]->getCoastal() || !countryArr[targetId]->getCoastal())
      {
        int theatre = 3;
      }

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
    break;*/
    case 4: //Recruit troops
    {
      countryArr[i]->recruit();
      cout << countryArr[i]->getName() << " is recruiting troops. (Factory Method)(Abstract Factory)" << endl;
    }
    break;
    case 5: //Build base
    {
      Commissioner* machine = new ConcreteCommissioner (20);
      machine->add(new ConcreteCommissioner (15)); 
      machine->add(new ConcreteCommissioner (10)); 
      machine->add(new ConcreteCommissioner (5)); 

      machine->commission(countryArr[i]->getFreeSpace(), countryArr[i]->getCoastal());
      vector<FOB*> facilities;
      machine->getInfo(facilities, machine);
      facilities = machine->getFacilities();

      countryArr[i]->addBases(facilities);

      cout << countryArr[i]->getName() << " is constructing facilites. (Builder)(Chain of Responsibility)(Composite)" << endl;
    }
    break;
    case 6: //Initiate diplomacy
    {
      cout << countryArr[i]->getName() << " is attempting to initiate diplomacy" << endl;
      if(rand() % 10 + 1 == 1)
      {
        cout << countryArr[i]->getName() << " has successfuly initaited diplomacy, peace talks are underway. (State)" << endl;
        state = "neg";
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
  
  cout << endl;
}

void WarEngine::handleNeg(int i)
{
  cout << countryArr[i]->getName() << " is proposing peace terms" << endl;

  if((rand() % 100 + 1) >= 80)
  {
    cout << countryArr[i]->getName() << "'s terms have been agreed to, there will now be peace. (State)" << endl;
    state = "peace";
  }
  else if((rand() % 100 + 1) <= 10)
  {
    cout << countryArr[i]->getName() << " no longer wishes to negotiate, the war will continue. (State)" << endl;
    state = "war";
  }
  else
  {
    cout << countryArr[i]->getName() << "'s terms have been rejected." << endl;
  }

  cout << endl;
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
      t += countryArr[i]->getArmy()->getStrength();
    }
  }

  return t;
}

void WarEngine::printWarEngineData()
{
  cout << "War summary:" << endl;
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

WarEngine::~WarEngine() {
}

WarEngine& WarEngine::instance(){
  static WarEngine onlyInstance_;
  return onlyInstance_;
}

int WarEngine::getCurrTurn()
{
  return currTurn;
}

vector<Country*> WarEngine::getCountryArr()
{
  return countryArr;
}

bool WarEngine::speedUp()
{
  return (currTurn > maxTurn);
}

int WarEngine::getMCnt()
{
  return mCnt;
}