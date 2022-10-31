#ifndef SOLDIER_H
#define SOLDIER_H

#include "Citizen.h"

class Soldier : public Citizen
{
private:
    /* data */
public:
    Soldier(int, string, string);
    ~Soldier();
};

#endif
