#include "Country.h"

static int getRandomInt(int a, int b){
    int max, min;
    if(a>b){
        max = a; min = b;
    }else{
        max = b; min = a;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distr(min, max);

    return (int) distr(gen);
}
static string randomString(int len = 9) {
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLen = sizeof(alphanum) - 1;

    string str;
    for (int i = 0; i < len; i++) {
        int rnd = getRandomInt(0, stringLen);
        str += alphanum[rnd % stringLen];
    }
    return str;
}
Country::Country(string n, bool s, bool c) 
{
    //generate random territory
    //srand(time(0));
    //
    id = randomString(8);
    territory = rand() % 40 + 10;
    freeSpace = 0;

    //assign recources
    resources = territory * (rand() % 5 + 1);

    name = n;
    side = s;
    coastal = c;
    cArmy = new Army(name);
    while(resources>0){
        recruit();
        if(myHelper::coinFlip()==0){
            buildArtillery();
        }
    }
}

int Country::generateResources()
{
    resources += territory * (8 + rand() % 5);
    //check for resource gen buildings

    return resources;
}

void Country::recruit()
{
    //recruit soldiers
    if(resources>0){
        int cost = cArmy->recruit();
        resources -= cost;
    }else{
        cout<<"Cant recruit because resources low"<<endl;
    }

    
}

void Country::buildArtillery()
{
    //recruit machines
    if(resources>0){
        int roll = myHelper::randomInt(0,3);
        int cost = 0;
        switch(roll){
            case 0: cost = cArmy->createAirVehicle();
            case 1: cost = cArmy->createSeaVehicle();
            case 2: cost = cArmy->createLandVehicle();
        }
        resources -= cost;
    }else{
        cout<<"Cant recruit because resources low"<<endl;
    }
}

bool Country::getSide(){
    return side;
}

void Country::setSide(bool s){
    side = s;
}

bool Country::getCoastal(){
    return coastal;
}

string Country::getName(){
    return name;
}

void Country::updateResources(int u)
{
    resources += u;
}

void Country::updateTerritory(int t, int fs)
{
    territory += t;
    freeSpace += fs;
}

void Country::addBases(vector<FOB*> nb)
{
    for(int i = 0; i < nb.size(); i++)
    {
        bases.push_back(nb[i]);
    }
}

void Country::checkBaseCapacity()
{
    while(baseSpace() > territory)
    {
        int b2d = (rand() % bases.size());

        if(bases[b2d]->getSpace() > 0)
        {
            bases[b2d]->removeFacility();
            if(bases[b2d]->getSpace() == 0)
            {
                freeSpace += bases[b2d]->getSpace();
                bases.erase(bases.begin() + b2d);
            }
        }
        
    }
}

int Country::baseSpace()
{
    int n = 0;
    for(int i = 0; i < bases.size(); i++)
    {
        n += bases[i]->getSpace();
    }
    return n;
}

int Country::getResources(){
    return resources;
}

int Country::getTerritory(){
    return territory;
}

int Country::getFreeSpace(){
    return freeSpace;
}

Army* Country::getArmy(){
    return cArmy;
}