#include "Army.h"

#include <iostream>

Army::Army(int r)
{
    strength = 0;
    recruit(r);
}

void Army::recruit(int r)
{
    strength += r / 2;
}

void Army::sufferCasualties(double cp)
{
    if(strength * cp < strength)
    {
        strength *= cp;
    }
}

int Army::getStrength()
{
    return strength;
}