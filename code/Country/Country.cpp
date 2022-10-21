#include "Country.h"
#include <iostream>

using namespace std;

Country** Country::getAllies()
{
    return allies;
}
void Country::setName(string n)
{
    this->name = n;
}
void Country::setTotalArmy(int t)
{
    this->totalArmy = t;
}
void Country::setReserves(int r)
{
    this->reserves = r;
}
void Country::setStrength(double s)
{
    this->strength = s;
}
int Country::getReserves()
{
    return reserves;
}
double Country::getStrength()
{
    return strength;
}
int Country::getTotal()
{
    return totalArmy;
}
void Country::print()
{
    cout <<this->name<<" has the following attributes "<<endl;
    cout <<"Strength = "<<this->strength<<endl;
    cout <<"Total army = "<<this->totalArmy<<endl;
    cout <<"Total reserves = "<<this->reserves<<endl;
    // other stuff to be implemented later..
}
void Country::setAllies(Country **a, int size)
{
    cout <<"set allies works"<<endl;
    for(int i = 0 ; i < size ;i++)
    {
        enemies[i] = a[i]; 
    }
}
void Country::setEnemies(Country **a, int size)
{
    cout <<"set enemies works"<<endl;
    for(int i = 0 ; i < size ;i++)
    {
        allies[i] = a[i]; 
    }
}
Country::Country()
{
    // cout<<"Country made"<<endl;
    enemies = new Country*[2];
    allies = new Country*[3];
}
Country::~Country()
{
    enemies =  NULL;
    allies = NULL;
}

/// 
