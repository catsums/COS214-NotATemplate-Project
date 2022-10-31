#ifndef WarEngine_h
#define WarEngine_h

class WarEngine {
  public:
	static WarEngine& instance(); 
	void updateWarEngineData();
	void printWarEngineData();
  protected:
	WarEngine();
	WarEngine(const WarEngine&);
	WarEngine& operator=(const WarEngine&);
	~WarEngine();
  private:
    //classes variables
};

#endif