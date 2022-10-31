#ifndef POLITICIAN_H
#define POLITICIAN_H

#include "Citizen.h"

class Politician : public Citizen
{
private:
    /* data */
public:
    Politician(int, string, string);
    ~Politician();
};

#endif
