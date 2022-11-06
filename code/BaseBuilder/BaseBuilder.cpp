#include "BaseBuilder.h"

BaseBuilder::BaseBuilder(int baseN, bool c)
{
    newBase = new FOB();

    vector<int> options {1,2,3,4,5};
    if(!c)
    {
        options.pop_back();
    }

    for(int i = 0; i < baseN; i++)
    {
        int n = (rand() % options.size());
        
        switch(options[n])
        {
            case 1:
            {
                Facility* newFac = new Airfield(10 - i * 2);
                newBase->addFacility(newFac);
                options.erase(options.begin() + n);
            }
            break;
            case 2:
            {
                Facility* newFac = new Depot(10 - i * 2);
                newBase->addFacility(newFac);
                options.erase(options.begin() + n);
            }
            break;
            case 3:
            {
                Facility* newFac = new Fortification(10 - i * 2);
                newBase->addFacility(newFac);
                options.erase(options.begin() + n);
            }
            break;
            case 4:
            {
                Facility* newFac = new Hospital(10 - i * 2);
                newBase->addFacility(newFac);
                options.erase(options.begin() + n);
            }
            break;
            case 5:
            {
                Facility* newFac = new Port(10 - i * 2);
                newBase->addFacility(newFac);
                options.erase(options.begin() + n);
            }
            break;
        }
    }
}

FOB* BaseBuilder::getResult()
{
    return newBase;
}