#ifndef ZONE_H
#define ZONE_H

#include <vector>

using namespace std;

class Zone
{
    public:
        Zone(int x_in, int y_in, int pv_in, bool l_in); //Parameterised constructor

    private:
        int x; //x coordinate of zone
        int y; //x coordinate of zone

        int productionValue; //Determines how much money zone produces for occupant

        bool land; //true if land zone, false if sea zone
};












#endif