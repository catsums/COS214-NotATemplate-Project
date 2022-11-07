#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include "../Facility/FOB.h"

using namespace std;

class Country
{
    public:
        Country(string n, bool s, bool c);
        ~Country();
        int generateResources();
        bool getSide();
        void setSide(bool s);
        string getName();

        void updateResources(int u);
        void updateTerritory(int u);
        
        bool getCoastal();
        int getResources();
        int getTerritory();
    private:
        Army* cArmy;
        vector<FOB*> bases;
        bool side;
        bool coastal;
        string name;
        int resources;
        int territory;
};

#endif