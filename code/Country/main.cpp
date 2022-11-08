#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>

#include <functional>

#include "Country.h"
#include "../myHelper.cpp"
// #include "Citizen.h"
// #include "Army.h"

using namespace std;

int getRandomInt(int a, int b){
    return myHelper::uniformDistribution<int>(a,b);
}

void countryTest()
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

    // for(int i=0; i<3;i++){
    //     arr[i] = new Country();
    // }

    // arr[0]->setName("Deez");
    // arr[1]->setName("Deez");
    // arr[2]->setName("Deez");

    Country **e = new Country*[2];
    Country **a = new Country*[3];
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
    a[2]->setName("Mongolia");


    for(int i = 0 ; i < 2 ; i++)
    {

    // populating each country's attributes
        e[i]->setStrength(getRandomInt(min,max));
        e[i]->setReserves(getRandomInt(100000,450000));
        e[i]->setTotalArmy(getRandomInt(2999,10000));
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

    cout<<"Show Country allies"<<endl;
    for(int i=0;i<3;i++){
        a[i]->print();
        cout<<endl;
    }
    cout<<"Show Country enemies"<<endl;
    for(int i=0;i<2;i++){
        e[i]->print();
        cout<<endl;
    }

}

// int main(){
//     countryTest();

//     return 0;
// }