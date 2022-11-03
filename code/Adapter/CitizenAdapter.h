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

/*	
	An adapter that wraps around the citizen entity
*/

class CitizenAdapter: public EntityAdapter{
public:
	CitizenAdapter(Citizen* ent);
	~CitizenAdapter();

	virtual void action(map<string,string> _data);

	virtual void onHandle(SignalEvent* e);
	virtual void onFulFilled(SignalEvent* e);

	//gets the citizen's influence
	virtual string getInfluence(){
		Citizen* ctn = getEntityAsCitizen();
		if(ctn){
			return ctn->getInfluence();
		}
		return "";
	}
	//gets the adaptee as a citizen
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