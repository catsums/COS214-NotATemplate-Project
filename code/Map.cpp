#include "Map.h"

using namespace std;

Map::Map() //default constructor
{
    zoneCount = 400;
}

//accessor methods

int Map::getZoneCount()
{
    return zoneCount;
}