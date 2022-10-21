#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Country.h"
// #include "Citizen.h"
// #include "Army.h"


using namespace std;

int main()
{
    unsigned seed = time(0);
    const int max = 3450678;
    const int min = 1000000;
    int r = 0, s = 0 , t = 0;
    cout <<"Welcome to country simulator"<<endl;
    // create a main country
    Country Zim;
    Zim.setName("Zimbabwe");
    Zim.setReserves(400000);
    Zim.setStrength(1999.999);
    Zim.setTotalArmy(1000000);

    // Country** arr = new Country*[3];
    // for(int i=0; i<3;i++){
    //     arr[i] = new Country();
    // }

    // arr[0]->setName("Deez");
    // arr[1]->setName("Deez");
    // arr[2]->setName("Deez");

    // Country *e = new Country[2];
    // Country *a = new Country[3];
    // // enemies
    // for(int i=0; i<2;i++){
    //     Country temp;
    //     e[i] = temp;
    // }
    // for(int i=0; i<3;i++){
    //     Country temp;
    //     a[i] = temp;
    // }
    // e[0].setName("England");
    // e[1].setName("USA");
    // // allies
    // a[0].setName("China");
    // a[1].setName("Russia");
    // a[2].setName("Russia");


    // for(int i = 0 ; i < 2 ; i++)
    // {
    //     t = (rand() % (max - min + 1) + min);
    //     r = (rand() % (450000 - 100000) + 100000);
    //     s = (rand() % (10000 - 2999) + 2999);
    // // populating each country's attributes
    //     e[i].setStrength(s);
    //     e[i].setReserves(r);
    //     e[i].setTotalArmy(t);
    // }
    // // allies 
    // for(int k = 0 ; k < 3 ; k++)
    // {
    //     t = (rand() % (max - min + 1) + min);
    //     r = (rand() % (450000 - 100000) + 100000);
    //     s = (rand() % (10000 - 2999) + 2999);
    // // populating each country's attributes
    //     e[k].setStrength(s);
    //     e[k].setReserves(r);
    //     e[k].setTotalArmy(t);
    // }
    // Zim.setAllies(a, 3);
    // Zim.setEnemies(e, 2);
    cout <<"Show country statistics"<<endl;
    // Zim.print();

    return 0;
}