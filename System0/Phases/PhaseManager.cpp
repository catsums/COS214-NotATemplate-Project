#include "PhaseManager.h"

using namespace std;

PhaseManager::PhaseManager(WarEngine* wIn) : w(wIn)
{
    this->phase = new War();
}

PhaseManager::~PhaseManager()
{
    delete this->phase;
}

void PhaseManager::DecideAction(vector<Country*> countryArr, int i)
{
    phase->handle(this, countryArr, i);
}

void PhaseManager::setPhase(Phase* p)
{
    delete this->phase;
    this->phase = p;
}