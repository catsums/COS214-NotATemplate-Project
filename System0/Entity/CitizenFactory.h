/** @file CitizenFactory.h
 *  @brief This is the header file to create many citizen.
 *
 *  An abstract factory that creates many entities that will be used as citizens or vehicles
 * 
 */

#ifndef CITIZENFACTORY_H
#define CITIZENFACTORY_H

#include <string>
#include "Citizen.h"
#include "Soldier.h"
#include "Medic.h"
#include "Politician.h"
#include "Informant.h"
#include "EntityFactory.h"

using namespace std; 

class CitizenFactory: public EntityFactory
{


public: 

	/** Default constructor for citizen
    */
	CitizenFactory();
	
	/** Destructor 
    */
	virtual ~CitizenFactory(); 

	/** This function instantiates new citizen entities 
	*	and returns a refernce to it. A virtual 
	*	function inherets from Entity factory.
	*/
	virtual Citizen* createCitizen(){
		return new Citizen();
	}
	
	/** This function instantiates new soldier from a given citizen
	*	and returns a refernce to it.
	*/
	virtual Citizen* createSoldier(Citizen* ent){
		Soldier* soldier = new Soldier(*ent);
		cout<<"Soldier created from "<<ent->getTitle()<<endl<<endl;
		return soldier;
	}
	virtual Citizen* createMedic(Citizen* ent){
		Medic* medic = new Medic(*ent);
		cout<<"Medic created from "<<ent->getTitle()<<endl<<endl;
		return medic;
	}
	virtual Citizen* createInformant(Citizen* ent){
		Informant* inform = new Informant(*ent);
		cout<<"Informant created from "<<ent->getTitle()<<endl<<endl;
		return inform;
	}
	virtual Citizen* createPolitician(Citizen* ent){
		Politician* polit = new Politician(*ent);
		cout<<"Politician created from "<<ent->getTitle()<<endl<<endl;
		return polit;
	}
	
	
	
};

#endif