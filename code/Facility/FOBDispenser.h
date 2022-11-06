#ifndef FOBDISPENSER_H
#define FOBDISPENSER_H

#include "Dispenser.h"

class ConcreteDispenser : public Dispenser { 
    public:
        ConcreteDispenser(int t); 
        void dispense(int ft);
    private:
        int territory;
};

#endif