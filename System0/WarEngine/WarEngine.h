/** @file WarEngine.h
 *  @brief Header for the WarEngine class.
 *
 *  War engine maintains and facilitates the core loop of the program
 */

#ifndef WarEngine_h
#define WarEngine_h

#include <vector>
#include "../Country/Country.h"
#include "../Battle/Battle.h"
#include "../Commissioner/Commissioner.h"
#include "../Commissioner/ConcreteCommissioner.h"

using namespace std;

class WarEngine 
{
  public:
  	/** Singleton instance function
	*/
	static WarEngine& instance();

	/** Prints out data related to warengine
	*/
	void printWarEngineData();

	/** Prints data related to a single alliance
	 * @param bool used to pass which side to print
	*/
	void printSide(bool side);

	/** Function to start the war and initalise its variables
	 * @param int represents countries in the war
	 * @param int represents countries on one side (other side calculated automatically)
	 * @param int determines how many turns the program will wait for use input for and when it will ultimatley terminate
	*/
	void initialiseWar(int c, int ss, int maxTurn);

	/** Runs one cycle of a turn, this includes all countries turns
	*/
	bool runTurn();

	/** Determines actions that a country can do during the war phase
	 * @param int used to input the current turn
	*/
	void handleWar(int i);

	/** Determines actions that a country can do during the negotiations phase
	 * @param int used to input the current turn
	*/
	void handleNeg(int i);

	/** Calculates which side is currently winning the war
	*/
	bool determineCurrentVictor();

	/** Calculates the strength of a particular side
	 * @param bool used to input the side to be calculated
	*/
	int determineSideStrength(bool s);

	/** accessor methods
	*/
	int getCurrTurn();
	vector<Country*> getCountryArr();
	int getMCnt();
	bool speedUp();

  protected:
  	/** Constructor
	*/
	WarEngine();

	/** Copy constructor
	*/
	WarEngine(const WarEngine&);

	/** = overload
	*/
	WarEngine& operator=(const WarEngine&);

	/** Destructor
	*/
	~WarEngine();

  private:
    //classes variables
	vector<Country*> countryArr; /**<vector stores countries*/
	int currTurn; /**<int currently active turn*/
	int maxTurn; /**<int maximum turn to run to*/
	string state; /**<string stores current state*/
	int mCnt; /**<int stores all actions done by countries*/
};

#endif