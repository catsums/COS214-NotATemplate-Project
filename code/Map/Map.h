#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <vector>

#include "Zone.h"

using namespace std;

class Map
{
    public:
        Map();
        Map(int w, int h);
        ~Map();

        //method to generate randomised map based on:
        //      size(number of zones)
        //      numBodies(number of large bodies of water, comprising of multiple sea zones)
        //      bodyPercentage(percentage of map that should be covered in water i.e. sea zones, divided into bodies for realism)
        //void genRandomMap(int size, int numBodies, double bodyPercentage); 

        void genStandardMap(); //Generates default map

        vector<Zone*> getAdjacent(Zone*); //returns all adjacent

        ZoneCircle getZoneCircle(Zone*);

        //accessor methods
        int getZoneCount(){
            return (mapSize.x * mapSize.y);
        }

        int getMapWidth(){
            return mapSize.x;
        }
        int getMapHeight(){
            return mapSize.y;
        }

        ///added by Cassim

        Zone* getZone(int x, int y){
            for(int r=0; r<(int)zones.size();r++){
                vector<Zone*>* row = zones[r];
                for(int c=0; c<(int)row->size();c++){
                    Zone* zone = (*row)[c];
                    return zone;
                }
            }
            return NULL;
        }

    protected:
        void initialiseRows();

        vector<vector<Zone*>*> zones;
        Position mapSize;
};

#endif