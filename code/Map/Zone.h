#ifndef ZONE_H
#define ZONE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "../Structs.h"
#include "../NewEntity/Entity.h"
#include "../Facility/Facility.h"

using namespace std;

class Zone
{
	public:
		Zone(int x, int y, int pv, bool l); //Parameterised constructor
		
		//accessor methods
		int getX();
		int getY();
		int getPv();
		bool isLand();

		

	private:
		int x; //x coordinate of zone
		int y; //x coordinate of zone

		int productionValue; //Determines how much money zone produces for occupant

		bool land; //true if land zone, false if sea zone
	public:
///added by cassim
		int getProductionValue(){
			return productionValue;
		}

		bool addEntity(Entity* ent){
			if(!hasEntity(ent)){
				entities[ent->getID()] = ent;
				return true;
			}
			return false; //entity already in the zone
			
		}
		Entity* removeEntity(Entity* ent){
			Entity* _ent = NULL;
			if(hasEntity(ent)){
				_ent = entities[ent->getID()];
				entities.erase(ent->getID());
			}
			return _ent;
		}

		bool hasEntity(Entity* ent){
			if(!ent) return false;
			if(entities.count(ent->getID())>0){
				return (entities[ent->getID()]==ent);
			}
			return false;
		}

		bool addFacility(Facility* fac){
			if(!hasFacility(fac)){
				facilities[fac->getID()] = fac;
				return true;
			}
			return false; /
			
		}
		Facility* removeFacility(Facility* fac){
			Facility* _fac = NULL;
			if(hasFacility(fac)){
				_fac = facilities[fac->getID()];
				facilities.erase(fac->getID());
			}
			return _ent;
		}

		bool hasFacility(Facility* fac){
			if(!fac) return false;
			if(facilities.count(fac->getID())>0){
				return (facilities[fac->getID()]==fac);
			}
			return false;
		}


	protected:
///by Cassim

		map<string, Entity*> entities;
		map<string, Facility*> facilities;
};












#endif