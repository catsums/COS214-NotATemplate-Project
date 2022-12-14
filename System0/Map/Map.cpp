#include "Map.h"

using namespace std;

Map::Map() //default constructor
{
    mapSize.x = 3;
    mapSize.y = 3;

    genStandardMap();
}
Map::Map(int w, int h) //default constructor
{
    mapSize.x = abs(w);
    mapSize.y = abs(h);

    genStandardMap();
}
Map::~Map(){
    
}

void Map::setSize(int w, int h){
    mapSize.x = abs(w);
    mapSize.y = abs(h);

    genStandardMap();
}

// void Map::initialiseRows(){
//     vector<vector<Zone*>*> initZones;
//     for(int r=0; r<mapSize.x; r++){
//         vector<Zone*>* row = new vector<Zone*>();
//         for(int c=0; c<mapSize.y; c++){
//             row->push_back(NULL);
//         }
//         initZones.push_back(row);
//     }

//     zones = initZones;
// }

vector<Zone*> Map::getAdjacent(Zone* zone) //********UNFINISHED********
{
    vector<Zone*> adj;
    Position pos = zone->getPosition();
    int x = pos.x;
    int y = pos.y;

    if(x > 0) //check for left zone
    {
        adj.push_back(getZone(x-1,y));
        if(y > 0){
            //check topleft zone
            adj.push_back(getZone(x-1,y-1));
        }
        if(y < mapSize.y-1){
            //check bottomleft zone
            adj.push_back(getZone(x-1,y+1));
        }
    }

    if(x < mapSize.x-1) //check for right zone
    {
        adj.push_back(getZone(x+1,y));

        if(y >= 0){
            //check topright zone
            adj.push_back(getZone(x+1,y-1));
        }
        if(y < mapSize.y-1){
            //check topright zone
            adj.push_back(getZone(x+1,y+1));
        }
    }

    if(y > 0) //check for top zone
    {
        adj.push_back(getZone(x,y-1));
    }

    if(y < mapSize.y-1) //check for bottom zone
    {
        adj.push_back(getZone(x,y+1));
    }

    return adj;

}

ZoneCircle Map::getZoneCircle(Zone* zone){
    ZoneCircle circ;
    Position pos = zone->getPosition();
    int x = pos.x;
    int y = pos.y;

    circ.curr = getZone(x,y);

    circ.top = getZone(x,y-1);
    circ.bottom = getZone(x,y+1);

    circ.left = getZone(x-1,y);
    circ.right = getZone(x+1,y);


    circ.topLeft = getZone(x-1,y-1);
    circ.bottomLeft = getZone(x-1,y+1);
    
    circ.topRight = getZone(x+1,y-1);
    circ.bottomRight = getZone(x+1,y+1);

    return circ;
}