#ifndef DISPENSER_H
#define DISPENSER_H

class Dispenser { 
    public :
        Dispenser();
        void add(Dispenser *n);
        virtual void dispense(int i);
        int getleftOver();
    private : 
        Dispenser* next;
        int leftOver;
};

#endif