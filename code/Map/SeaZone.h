#ifndef SEAZONE_H
#define SEAZONE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>

#include "Zone.h"

class SeaZone: public Zone{
public:
	SeaZone(int x,int y, int pv):Zone(x,y,false){

	}
	~SeaZone(){}
};

#endif