#ifndef COUNTRY_H
#define COUNTRY_H

#include <string>

using namespace std;

class Country
{
    public:
        Country(string n, bool s);
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
        string name;
        int resources;
        int territory;
};

#endif