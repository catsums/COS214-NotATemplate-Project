#ifndef WarEngine_h
#define WarEngine_h

#include <vector>
#include "../Country/Country.h"

using namespace std;

class WarEngine {
  public:
	static WarEngine& instance();
	void printWarEngineData();

	void initialiseWar(int c, int ss);
	bool runTurn();
  protected:
	WarEngine();
	WarEngine(const WarEngine&);
	WarEngine& operator=(const WarEngine&);
	~WarEngine();
  private:
    //classes variables
	vector<Country*> countryArr;
	int numCountries;
	int aSize;
};

#endif