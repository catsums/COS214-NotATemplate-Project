#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>
#include <vector>

#include "Country.h"
#include "Army.h"
#include "GroundForce.h"
#include "NavalForce.h"
#include "AirForce.h"

// #include "Citizen.h"
// #include "Army.h"

using namespace std;
//for generating random numbers
int getRandomInt(int a, int b){
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

int main()
{
    unsigned seed = time(0);
    const int max = 3450678;
    const int min = 1000000;
    int r = 0, s = 0 , t = 0;
    cout <<"Welcome to country simulator"<<endl;
    // create a main country
    Country* Zim = new Country();
    Zim->setName("Zimbabwe");
    Zim->setReserves(400000);
    Zim->setStrength(1999.999);
    Zim->setTotalArmy(1000000);
    Zim->setAirTroops(1000000);
    Zim->setGroundTroops(1000000);
    Zim->setNavyTroops(1000000);



    Country **e = new Country*[2];   //enemies
    Country **a = new Country*[3];      //allies
    // enemies
    for(int i=0; i<2;i++){
        e[i] = new Country();
    }
    e[0]->setName("England");
    e[1]->setName("USA");
    // allies
    for(int i=0; i<3;i++){
        a[i] = new Country();
    }
    a[0]->setName("China");
    a[1]->setName("Russia");
    a[2]->setName("Russia");


    for(int i = 0 ; i < 2 ; i++)
    {

    // populating each country's attributes
        e[i]->setStrength(getRandomInt(2999,10000));
        e[i]->setReserves(getRandomInt(100000,450000));
        e[i]->setTotalArmy(getRandomInt(min,max));
    }
    // allies 
    for(int k = 0 ; k < 3 ; k++)
    {

    // populating each country's attributes
        a[k]->setStrength(getRandomInt(min,max));
        a[k]->setReserves(getRandomInt(100000,450000));
        a[k]->setTotalArmy(getRandomInt(2999,10000));
    }
    Zim->setAllies(a, 3);
    Zim->setEnemies(e, 2);
    cout <<"Show country statistics"<<endl;
    Zim->print();
    cout <<"Countries battle it out"<<endl;

    /*Countries lose troops everytime that they are attacked*/
    // Troop types
    // GroundForce ground;
    // NavalForce navy;
    // AirForce air;

    // Army attack;

    cout <<"End of army class"<<endl;


    return 0;
}