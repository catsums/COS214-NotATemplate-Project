#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <functional>
#include <map>

#include "../Country/Country.h"
#include "../SignalHandler/SignalBus.h"
#include "../ActionManager/ActionManager.h"

using namespace std;

class Battle{
public:
	Battle(Country* a, Country* b);
	~Battle();

	bool commenceBattle();
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
	ActionManager* actionManager;
	SignalBus* signalBus;

	Country* a;
	Country* b;

	Country* winner;
	bool finished;

	int balance = 0;
};