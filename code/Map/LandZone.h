#ifndef LANDZONE_H
#define LANDZONE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "Zone.h"

class LandZone: public Zone{
public:
	LandZone(int x,int y, int pv):Zone(x,y,true){

	}
	~LandZone(){}
};

#endif