#ifndef ZONE_H
#define ZONE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <sstream>

#include "../Structs.h"
#include "../NewEntity/Entity.h"
#include "../Facility/Facility.h"

using namespace std;

class Zone
{
	public:
		Zone(int x, int y, bool l); //Parameterised constructor
		Zone(int x, int y, bool l, string c); //Parameterised constructor
		~Zone();
		//accessor methods
		int getX();
		int getY();
		bool isLand();

	protected:
		Position pos;

		string country;

		// int productionValue; //Determines how much money zone produces for occupant

		bool land; //true if land zone, false if sea zone
	public:
///added by cassim

		void setCountry(string c){
			country = c;
		}
		string getCountry(){
			return country;
		}

		Position getPosition(){
			return pos;
		}

		bool addFacility(Facility* fac);
		Facility* removeFacility(Facility* fac);
		bool hasFacility(Facility* fac);

		vector<Facility*> getFacilities(){
			vector<Facility*> list;
			for(auto fac:facilities){
				list.push_back(fac.second);
			}
			return list;
		}

		virtual string printInfo(){
			stringstream ss;

			ss << "ZONE - "<<pos.x<<","<<pos.y;
			ss << "\n";
			ss << " Country: " << getCountry() << " | ";
			if(isLand()){
				ss<<" IsLand";
			}else{
				ss<<" IsSea";
			}
			ss << " | ";

			ss << "\n[";
			ss << getInfo();
			ss << "\n]";

			return ss.str();
		}

		virtual string getInfo(){
			stringstream ss;

			ss<<"\n\t Facilities:"<<"\n";
			for(auto const&[id,fac]:facilities){
				if(fac){
					ss << fac->printInfo() << endl;
				}
			}
			

			return ss.str();
		}

	protected:
///by Cassim

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