#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include "../Country/Country.h"

using namespace std;

class Battle
{
    public:
        Battle(Country* c1, Country* c2, int t);
        ~Battle();

        void commence();

        void determineOutcome();
    private:
        Country* c1;
        Country* c2;
        int theatre;
};

#endif