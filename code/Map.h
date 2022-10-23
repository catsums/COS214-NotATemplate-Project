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

        int getZoneCount();

    private:
        vector<vector<Zone>> zones;
        int zoneCount;
};












#endif