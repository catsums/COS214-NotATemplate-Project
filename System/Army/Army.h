#ifndef ARMY_H
#define ARMY_H

#include <string>

using namespace std;

class Army
{
    public:
        Army(int r);
        void recruit(int r);
        void sufferCasualties(double cp);

        int getStrength();
    private:
        int strength;
};

#endif