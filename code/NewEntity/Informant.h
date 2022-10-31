#ifndef INFORMANT_H
#define INFORMANT_H

#include "Citizen.h"

class Informant : public Citizen
{
private:
    /* data */
public:
    Informant(int, string, string);
    ~Informant();
};

#endif
