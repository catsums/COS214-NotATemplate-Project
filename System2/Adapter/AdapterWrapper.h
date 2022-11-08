#ifndef ADAPTERWRAPPER_H
#define ADAPTERWRAPPER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <initializer_list>

#include <functional>

#include "EntityAdapter.h"
#include "CitizenAdapter.h"
// #include "AdapterManager.h"

/*	
	Singleton that allows for any object to create an adapter based on the type of object it is
	without clashing with the dependancies
*/

class AdapterWrapper{
public:
	AdapterWrapper(){}
	~AdapterWrapper(){}
	/*creates an adapter from an Entity object*/
	static EntityAdapter* getAdapter(Entity* ent){
		return new EntityAdapter(ent);
	}
	/*creates an adapter from a Citizen object*/
	static CitizenAdapter* getAdapter(Citizen* ent){
		return new CitizenAdapter(ent);
	}

	//still gotta be implemented
	// TransportVehicleAdapter* getAdapter(TransportVehicle* ent){
	// 	return new TransportVehicleAdapter(ent);
	// }
	// BattleVehicleAdapter* getAdapter(BattleVehicleAdapter* ent){
	// 	return new BattleVehicleAdapter(ent);
	// }

	// ForceAdapter* getAdapter(ArmyForce* ent){
	// 	return new ForceAdapter(ent);
	// }

};

#endif
