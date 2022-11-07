#ifndef BASEBUILDER_H
#define BASEBUILDER_H

#include <string>
#include "../Facility/FOB.h"
#include "../Facility/Airfield.h"
#include "../Facility/Depot.h"
#include "../Facility/Fortification.h"
#include "../Facility/Hospital.h"
#include "../Facility/Port.h"

using namespace std;

class BaseBuilder
{
    public:
        BaseBuilder(int baseN, bool c);
        FOB* getResult();
    private:
        int baseN;
        FOB* newBase;
        
};

#endif