#ifndef MAP_H
#define MAP_H

#include <vector>

#include "Zone.h"

using namespace std;

class Map
{
    public:
        Map();

        //method to generate randomised map based on:
        //      size(number of zones)
        //      numBodies(number of large bodies of water, comprising of multiple sea zones)
        //      bodyPercentage(percentage of map that should be covered in water i.e. sea zones, divided into bodies for realism)
        //void genRandomMap(int size, int numBodies, double bodyPercentage); 

        void genStandardMap(); //Generates default map

        vector<Zone*> getAdjacent(Zone*); //returns all adjacent

        //accessor methods
        int getZoneCount();

        ///added by Cassim

        Zone* getZone(int x, int y){
            for(int r=0; r<(int)zones.size();r++){
                vector<Zone> row = zones[r];
                for(int c=0; c<(int)zones.size();c++){
                    Zone zone = zones[r][c];
                    return &zone;
                }
            }
            return NULL;
        }

    private:
        vector<vector<Zone>> zones;
        int zoneCount;
};

#endif