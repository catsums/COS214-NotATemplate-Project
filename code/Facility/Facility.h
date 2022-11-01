#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

#include "../Structs.h"

using namespace std;

class Facility{
public:
    Facility();
    Facility(string c);
    ~Facility();

    void setPosition(int x, int y){
        zone.x = x;
        zone.y = y;
    }

    void setPosition(Position pos){
        zone.x = pos.x;
        zone.y = pos.y;
    }

    Position getPosition(){
        return zone;
    }

    string getID(){
        return id;
    }

    void setCountry(string c){
        country = c;
    }
    string getCountry(){
        return country;
    }

    virtual void displayFacility() = 0;

private:
    string id;
    string country;
    Position zone; //coords for zone
    bool land;
    bool sea;
};

#endif