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
		~Zone();
		//accessor methods
		int getX();
		int getY();
		int getPv();
		bool isLand();

	protected:
		Position pos;

		int productionValue; //Determines how much money zone produces for occupant

		bool land; //true if land zone, false if sea zone
	public:
///added by cassim
		int getProductionValue(){
			return productionValue;
		}
		Position getPosition(){
			return pos;
		}

		bool moveEntity(Entity* ent);
		
		bool addEntity(Entity* ent);
		Entity* removeEntity(Entity* ent);
		bool hasEntity(Entity* ent);

		bool addFacility(Facility* fac);
		Facility* removeFacility(Facility* fac);
		bool hasFacility(Facility* fac);


	protected:
///by Cassim

		map<string, Entity*> entities;
		map<string, Facility*> facilities;
};

struct ZoneCircle{
	Zone* curr;

	Zone* left;
	Zone* right;
	Zone* top;
	Zone* bottom;

	Zone* topLeft;
	Zone* topRight;
	Zone* bottomLeft;
	Zone* bottomRight;
};

#endif