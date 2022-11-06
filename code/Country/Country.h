#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

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
        
        int getResources();
        int getTerritory();
    private:
        bool side;
        bool coastal;
        string name;
        int resources;
        int territory;
};

#endif