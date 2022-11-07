#include <iostream>
#include "War.h"

using namespace std;

void War::handle(WarEngine* w) {
    vector<int> potentialActions;
    bool currSide = countryArr[i]->getSide();
    
    if(countryArr[i]->getTerritory() > 0)
    {
      potentialActions.push_back(1);
      potentialActions.push_back(2);
      potentialActions.push_back(3);
      potentialActions.push_back(4);
      potentialActions.push_back(5);

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
    else //withdrawal
    {
      potentialActions.push_back(0); 
    }
    

    int action = potentialActions[rand() % (potentialActions.size())];

    switch (action)
    {
      case 0: //Withdraw
      {
        countryArr.erase(countryArr.begin() + i);
        cout << countryArr[i]->getName() << " has withdrawn from the war!" << endl;
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
    
    cout << endl;
  }
}

string War::getPhase() {
    return "War";
}