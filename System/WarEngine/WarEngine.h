#ifndef WarEngine_h
#define WarEngine_h

#include <vector>
#include "../Country/Country.h"
#include "../Battle/Battle.h"
#include "../Commissioner/ConcreteCommissioner.h"

using namespace std;

class WarEngine 
{
  public:
	static WarEngine& instance();
	void printWarEngineData();
	void printSide(bool side);

	void initialiseWar(int c, int ss, int maxTurn);
	bool runTurn();
	void handleWar(int i);
	void handleNeg(int i);

	bool determineCurrentVictor();
	int determineSideStrength(bool s);

	int getCurrTurn();
	vector<Country*> getCountryArr();
	int getMCnt();

	bool speedUp();

  protected:
	WarEngine();
	WarEngine(const WarEngine&);
	WarEngine& operator=(const WarEngine&);
	~WarEngine();

  private:
    //classes variables
	vector<Country*> countryArr;
	int currTurn;
	int maxTurn;
	string state;
	int mCnt;
};

#endif