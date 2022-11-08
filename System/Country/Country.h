#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>
#include "../Facility/FOB.h"
#include "../Army/Army.h"

using namespace std;

class Country
{
    public:
        Country(string n, bool s, bool c);
        ~Country();
        int generateResources();
        void recruit();
        
        void updateResources(int u);
        void updateTerritory(int t, int fs);
        void addBases(vector<FOB*> nb);
        void checkBaseCapacity();
        int baseSpace();
        
        bool getSide();
        string getName();
        bool getCoastal();
        int getResources();
        int getTerritory();
        int getFreeSpace();
        Army* getArmy();

        void setSide(bool s);
    private:
        Army* cArmy;
        vector<FOB*> bases;
        bool side;
        bool coastal;
        string name;
        int resources;
        int territory;
        int freeSpace;
};

#endif