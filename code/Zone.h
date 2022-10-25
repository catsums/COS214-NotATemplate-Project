#ifndef ZONE_H
#define ZONE_H

using namespace std;

class Zone
{
    public:
        Zone(int x, int y, int pv, bool l); //Parameterised constructor
        
        //accessor methods
        int getX();
        int getY();
        int getPv();
        bool isLand();

    private:
        int x; //x coordinate of zone
        int y; //x coordinate of zone

        int productionValue; //Determines how much money zone produces for occupant

        bool land; //true if land zone, false if sea zone
};












#endif