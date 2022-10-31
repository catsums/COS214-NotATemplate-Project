#include "Map.h"

using namespace std;

Map::Map() //default constructor
{
    zoneCount = 400;
}

vector<Zone*> Map::getAdjacent(Zone* curr) //********UNFINISHED********
{
    vector<Zone*> adj;
    int x = curr->getX();
    int y = curr->getY();

    if(x > 0) //check for left zone
    {
        adj.push_back(&zones[y][x-1]);
    }

    if(x < zones[y].size() - 1) //check for right zone
    {
        adj.push_back(&zones[y][x+1]);
    }

    if(y > 0) //check for top zones
    {
        if(y % 2 == 0) //check if normal row...
        {
            if(x > 0) //check for top left zone
            {
                adj.push_back(&zones[y-1][x-1]);
            }
            if(x < zones[y].size() - 1) //check for top right zone
            {
                adj.push_back(&zones[y][x+1]);
            }
        }
        else //..or offset row
        {

        }

    }
}

//accessor methods
int Map::getZoneCount(){ return zoneCount; }