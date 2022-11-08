#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <functional>
#include <sstream>
#include <map>

#include "../Country/Country.h"
#include "../Entity/Entity.h"
#include "../Entity/Medic.h"
#include "../Entity/Soldier.h"
#include "../SignalHandler/SignalBus.h"
#include "../ActionManager/ActionManager.h"

using namespace std;

class Battle{
public:
	Battle(Country* a, Country* b);
	~Battle();

	void commenceBattle();
	void preparationPhase();
	int executionPhase();
	void evaluationPhase();

	Country* getWinner(){
		return winner;
	}
	bool isFinished(){
		return finished;
	}

protected:
	void shiftBalance(string side);
	void lowerBalance(string side);

	ActionRequest* requestAttack(Entity* currEnt, Entity* targetEnt);
	ActionRequest* requestHeal(Entity* currEnt, Entity* targetEnt);
	ActionRequest* requestTakeover(Entity* currEnt);


	ActionManager* actionManager;
	SignalBus* signalBus;

	Country* a;
	Country* b;

	Country* winner;
	bool finished;

	int balance = 0;
};

#endif