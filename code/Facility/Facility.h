#ifndef FACILITY_H
#define FACILITY_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <map>

// #include "../NewResource/Resource.h"
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

    string getType(){
        return types.back();
    }
    vector<string> getTypes(){
        return types;
    }
    bool isType(string type){
        for(int i=0;i<(int)types.size();i++){
            if(types[i]==type){
                return true;
            }
        }
        return false;
    }
    string setType(string t){
        string temp = types.back();
        types.pop_back();
        types.push_back(t);
        return temp;
    }

    void setCountry(string c){
        country = c;
    }
    string getCountry(){
        return country;
    }

    bool isOnLand(){
        return land;
    }
    bool isOnSea(){
        return sea;
    }

    virtual void displayFacility() = 0;

    // virtual vector<Resource*> generateResources() = 0;

    virtual string printInfo(){
        stringstream ss;

        ss << "FACILITY-" << getID() << "{" << getInfo() << "}";

        return ss.str();
    }
    virtual string getInfo(){
        stringstream ss;

        ss << " Type: " << getType() << "|";

        return ss.str();
    }

private:
    string id;
    string country;
    vector<string> types;
    Position zone; //coords for zone
    bool land;
    bool sea;
};

#endif