/** @file CitizenAdapter.h
*	@brief An example of how we incorporated the adapter pattern into our war simulator 
*/


#ifndef CITIZENADAPTER_H
#define CITIZENADAPTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "../NewEntity/Citizen.h"
#include "EntityAdapter.h"

using namespace std;

/**	
*	An adapter that wraps around the citizen entity
*/

class CitizenAdapter: public EntityAdapter{
public:
	/** Parameter constructor that takes in a citizen pointer
	*	@param citizen pointer 
	*/
	CitizenAdapter(Citizen* ent);
	///Destructor 
	~CitizenAdapter();

	/** virtual function that determines the action that will take place on the map
	*	@param data passed through from the postion on the map	
	*/
	virtual void action(map<string,string> _data);
	///on handle event
	virtual void onHandle(SignalEvent* e);

	///handle to handle the succession of an event
	virtual void onFulFilled(SignalEvent* e);

	///gets the citizen's influence
	virtual string getInfluence(){
		Citizen* ctn = getEntityAsCitizen();
		if(ctn){
			return ctn->getInfluence();
		}
		return "";
	}
	///gets the adaptee as a citizen
	virtual Citizen* getEntityAsCitizen(){
		if(entity){
			try{
				Citizen* ctn = static_cast<Citizen*>(entity);
				return ctn;
			}catch(const exception& err){

			}
		}
		return NULL;
	}
protected:
};

#endif