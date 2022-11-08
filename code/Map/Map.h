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

        void genStandardMap(){
            vector<vector<Zone*>*> initZones;
            for(int r=0; r<mapSize.x; r++){
                vector<Zone*>* row = new vector<Zone*>();
                for(int c=0; c<mapSize.y; c++){
                    // cout<<"> "<<r<<" "<<c<<endl;
                    Zone* z = new LandZone(r,c,100);
                    // cout<<"***"<<z->printInfo()<<endl;
                    row->push_back(z);
                }
                initZones.push_back(row);
            }

            zones = initZones;
        }

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

        Position getMapSize(){
            return mapSize;
        }

        Zone* getZone(Position pos){
            return getZone(pos.x,pos.y);
        }
        Zone* getZone(int x, int y){
            if(x>=0 && x<mapSize.x){
                vector<Zone*>* row = zones[x];
                if(y>=0 && y<mapSize.y){
                    Zone* zone = (*row)[y];
                    return zone;
                }
            }
            return NULL;
        }

        vector<Zone*> getAllZones(){
            vector<Zone*> allZones;
            for(int r=0; r<mapSize.x; r++){
                for(int c=0; c<mapSize.y; c++){
                    Zone* z = zones[r]->at(c);
                    if(z){
                        allZones.push_back(z);
                    }
                }
            }
        }

        void setSize(int w, int h);

    protected:
        // void initialiseRows();

        vector<vector<Zone*>*> zones;
        Position mapSize;
};

#endif