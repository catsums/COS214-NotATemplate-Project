#ifndef WARPHASE_H
#define WARPHASE_H

#include <string>
#include "../Country/Country.h"

using namespace std;

class WarPhase{
public:
	virtual void handle(vector<Country*>* a, vector<Country*>* b) = 0;
	WarPhase(string s);
	~WarPhase();

	string getState();
private:
	string state;
};

class PhaseNeutral: public WarPhase{
public:
	PhaseNeutral();
	~PhaseNeutral();
	void handle(vector<Country*>* a, vector<Country*>* b);

};

class PhasePeace: public WarPhase{
public:
	PhasePeace();
	~PhasePeace();
	void handle(vector<Country*>* a, vector<Country*>* b);

};

class PhaseOpenConflict: public WarPhase{
public:
	PhaseOpenConflict();
	~PhaseOpenConflict();
	void handle(vector<Country*>* a, vector<Country*>* b);
};

class PhaseCrisis: public WarPhase{
public:
	PhaseCrisis();
	~PhaseCrisis();
	void handle(vector<Country*>* a, vector<Country*>* b);
};

class PhaseWar: public WarPhase{
public:
	PhaseWar();
	~PhaseWar();
	void handle(vector<Country*>* a, vector<Country*>* b);
};

class PhaseNegotiations: public WarPhase{
public:
	PhaseNegotiations();
	~PhaseNegotiations();
	void handle(vector<Country*>* a, vector<Country*>* b);
};

#endif