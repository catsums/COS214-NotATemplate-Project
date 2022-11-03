#ifndef COUNTRY_CPP
#define COUNTRY_CPP

#include "Country.h"

// #include "myHelper.cpp"

using namespace std;

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

Country::Country()
{
    id = randomString(8);
    name = "";
    // reserves = 0;
    
}
Country::Country(string n)
{
    id = randomString(8);
    name = n;
    // reserves = 0;
}
Country::~Country()
{
    
}


vector<Country*>* Country::getAllies()
{
    return &allies;
}
vector<Country*>* Country::getEnemies()
{
    return &enemies;
}
Country** Country::getAlliesAsArray()
{
    return &allies[0];
}
Country** Country::getEnemiesAsArray()
{
    return &enemies[0];
}
void Country::setName(string n)
{
    this->name = n;
}
// void Country::setTotalArmy(int t)
// {
//     this->totalArmy = t;
// }
void Country::setReserves(int r)
{
    this->reserves = r;
}
// void Country::setStrength(double s)
// {
//     this->strength = s;
// }
int Country::getReserves()
{
    return reserves;
}
// double Country::getStrength()
// {
//     return strength;
// }
// int Country::getTotal()
// {
//     return totalArmy;
// }
void Country::print()
{
    cout <<this->name<<" has the following attributes "<<endl;
    // cout <<"Strength = "<<this->strength<<endl;
    // cout <<"Total army = "<<this->totalArmy<<endl;
    cout <<"Total reserves = "<<this->reserves<<endl;
    // other stuff to be implemented later..
    if(allies.empty())
    {
        cout <<"This country has no allies"<<endl;
    }
    else{
        cout << this->getName() <<" has the following allies"<<endl;
        for(int i = 0 ; i < allies.size() ; i++)
        {
            cout <<allies[i]->getName()<<endl;
        }
    }
    if(enemies.empty())
    {
        cout <<this->getName() << " has no enemies"<<endl;
    }
    else{
        cout << this->getName() <<" has the following enemies"<<endl;
        for(int i = 0 ; i < enemies.size() ; i++)
        {
            cout <<enemies[i]->getName()<<endl;
        }
    }
}
void Country::setAllies(Country **a, int size)
{
    vector<Country*> arr;
    cout <<"set allies works"<<endl;
    for(int i = 0 ; i < size ;i++)
    {
        if(a[i]){
            arr.push_back(a[i]);
        }
    }
    allies = arr;
}
void Country::setEnemies(Country **a, int size)
{
    vector<Country*> arr;
    cout <<"set enemies works"<<endl;
    for(int i = 0 ; i < size ;i++)
    {
        if(a[i]){
            arr.push_back(a[i]);
        }
    }
    enemies = arr;
}

/// added by Cassim

bool Country::isAlly(Country* country){
    for(int i=0; i < allies.size(); i++){
        Country* ally = allies[i];
        if(ally == country || ally->getID() == country->getID()){
            return true;
        }
    }
    return false;
}
bool Country::isEnemy(Country* country){
    for(int i=0; i < enemies.size(); i++){
        Country* enemy = enemies[i];
        if(enemy == country || enemy->getID() == country->getID()){
            return true;
        }
    }
    return false;
}

string Country::getID() const{
    return id;
}
string Country::getName() const{
    return name;
}
void Country::setAllies(vector<Country*> v)
{
    vector<Country*> arr;
    cout <<"set allies works"<<endl;
    for(int i = 0 ; i < v.size() ;i++)
    {
        if(v[i]){
            arr.push_back(v[i]);
        }
    }
    allies = arr;
}
void Country::setEnemies(vector<Country*> v)
{
    vector<Country*> arr;
    cout <<"set enemies works"<<endl;
    for(int i = 0 ; i < v.size() ; i++)
    {
        if(v[i]){
            arr.push_back(v[i]);
        }
    }
    enemies = arr;
}

void Country::addAlly(Country* c){
    if(c){
        for(int i = 0 ; i < allies.size() ; i++){
            if(allies[i] && allies[i] == c) return;
        }
        allies.push_back(c);
    }
}
void Country::addEnemy(Country* c){
    if(c){
        for(int i = 0 ; i < enemies.size() ; i++){
            if(enemies[i] && enemies[i] == c) return;
        }
        enemies.push_back(c);
    }
}

int Country::getNumberOfAllies(){
    return (int) allies.size();
}
int Country::getNumberOfEnemies(){
    return (int) enemies.size();
}
// double Country::getStrength() const{
//     return strength;
// }
// int Country::getTotalArmy() const{
//     return totalArmy;
// }
// int Country::getReserveCount() const{
//     return reserves;
// }

void Country::addCitizen(Citizen* ctn){
    if(!hasCitizen(ctn)){
        citizens.push_back(ctn);
        ctn->setCountry(this->name);
    }
}
Citizen* Country::removeCitizen(Citizen* ctn){
    Citizen* _ctn = NULL;
    if(hasCitizen(ctn)){
        for(int i=0; i<(int)citizens.size();i++){
            Citizen* ent = citizens[i];
            if(ent == ctn || ent->getID() == ctn->getID()){
                _ctn = ent;
                ctn->setCountry("");
                citizens.erase(citizens.begin()+i);
                break;
            }
        }
    }
    return _ctn;
}
bool Country::hasCitizen(Citizen* ctn){
    if(ctn){
        for(int i=0; i<(int)citizens.size();i++){
            Citizen* _ctn = citizens[i];
            if(_ctn == ctn || _ctn->getID() == ctn->getID()){
                return true;
            }
        }
    } 
    return false;
}

void Country::addFacility(Facility* fac){
    if(!hasFacility(fac)){
        facilities.push_back(fac);
        fac->setCountry(this->name);
    }
}
Facility* Country::removeFacility(Facility* fac){
    Facility* _fac = NULL;
    if(hasFacility(fac)){
        for(int i=0; i<(int)facilities.size();i++){
            Facility* ent = facilities[i];
            if(ent == fac || ent->getID() == fac->getID()){
                _fac = ent;
                fac->setCountry("");
                facilities.erase(facilities.begin()+i);
                break;
            }
        }
    }
    return _fac;
}
bool Country::hasFacility(Facility* fac){
    if(fac){
        for(int i=0; i<(int)facilities.size();i++){
            Facility* _fac = facilities[i];
            if(_fac == fac || _fac->getID() == fac->getID()){
                return true;
            }
        }
    } 
    return false;
}

void Country::addResource(Resource* reso){
    if(!hasResource(reso)){
        resources.push_back(reso);
        // reso->setCountry(this->name);
    }
}
Resource* Country::removeResource(Resource* reso){
    Resource* _reso = NULL;
    if(hasResource(reso)){
        for(int i=0; i<(int)resources.size();i++){
            Resource* ent = resources[i];
            if(ent == reso){
                _reso = ent;
                // reso->setCountry("");
                resources.erase(resources.begin()+i);
                break;
            }
        }
    }
    return _reso;
}
bool Country::hasResource(Resource* reso){
    if(reso){
        for(int i=0; i<(int)resources.size();i++){
            Resource* _reso = resources[i];
            if(_reso == reso){
                return true;
            }
        }
    } 
    return false;
}

void Country::addZone(Zone* zone){
    if(!hasZone(zone)){
        zones.push_back(zone);
        zone->setCountry(this->name);
    }
}
Zone* Country::removeZone(Zone* zone){
    Zone* _zone = NULL;
    if(hasZone(zone)){
        for(int i=0; i<(int)zones.size();i++){
            Zone* z = zones[i];
            if(z == zone){
                _zone = z;
                zone->setCountry("");
                zones.erase(zones.begin()+i);
                break;
            }
        }
    }
    return _zone;
}
bool Country::hasZone(Zone* zone){
    if(zone){
        for(int i=0; i<(int)zones.size();i++){
            Zone* _zone = zones[i];
            if(_zone == zone){
                return true;
            }
        }
    } 
    return false;
}

///

#endif