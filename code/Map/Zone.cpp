#include "Zone.h"

//Parameterised constructor
Zone::Zone(int x, int y, int pv, bool l)
{
	this->x = x;
	this->y = y;
	this->productionValue = pv;
	this->land = l;
}

//accessor methods
int Zone::getX(){ return x; }
int Zone::getY(){ return y; }
int Zone::getPv(){ return productionValue; }
bool Zone::isLand(){ return land; }