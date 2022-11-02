#ifndef WarEngine_h
#define WarEngine_h

class WarEngine {
  public:
	static WarEngine& instance();
	void printWarEngineData();

	void initialiseWar(int c, int st);
	bool runTurn();
  protected:
	WarEngine();
	WarEngine(const WarEngine&);
	WarEngine& operator=(const WarEngine&);
	~WarEngine();
  private:
    //classes variables
	vector<Country*> countries;
	int numCountries;
	int aSize;
};

#endif