#ifndef WarEngine_h
#define WarEngine_h

#include <vector>
#include "../Country/Country.h"
#include "../Battle/Battle.h"

using namespace std;

class WarEngine 
{
  public:
	static WarEngine& instance();
	void printWarEngineData();
	void printSide(bool side);

	void initialiseWar(int c, int ss, int maxTurn);
	bool runTurn();

	bool determineCurrentVictor();
	int determineSideStrength(bool s);

	int getCurrTurn();

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
};

#endif