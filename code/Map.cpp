#include "Map.h"

using namespace std;

Map::Map() //default constructor
{
    zoneCount = 400;
}

vector<Zone*> Map::getAdjacent(Zone*)
{
    
}

//accessor methods
int Map::getZoneCount(){ return zoneCount; }