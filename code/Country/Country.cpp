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
    // strength = 0;
    // totalArmy = 0;
    reserves = 0;
    // cout<<"Country made"<<endl;
    // enemies = vector
    // allies = new Country*[3];
}
Country::Country(string n)
{
    id = randomString(8);
    name = n;
    // strength = 0;
    // totalArmy = 0;
    reserves = 0;
}
Country::~Country()
{
    // enemies = NULL;
    // allies = NULL;
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

#endif