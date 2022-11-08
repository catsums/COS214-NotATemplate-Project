C#ifndef FOBCOMMISSIONER_H
#define FOBCOMMISSIONER_H

#include "Commissioner.h"

class ConcreteCommissioner : public Commissioner { 
    public:
        ConcreteCommissioner(int t); 
        void commission(int ft, bool coastal);
    private:
        int territory;
};

#endif