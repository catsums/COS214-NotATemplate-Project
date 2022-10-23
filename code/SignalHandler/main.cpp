#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>

#include <functional>

#include "Country.h"
#include "SignalHandler.h"
#include "myHelper.cpp"
// #include "Citizen.h"
// #include "Army.h"


using namespace std;

class SillyEvent: public SignalEvent{
public:
    SillyEvent(string n, string msg):SignalEvent(n){
        message = msg;
    }
    SillyEvent(SillyEvent& other){
        name = other.name;
        other.message = other.message;
    }
    ~SillyEvent(){}

    SignalEvent* clone(){
        return new SillyEvent(*this);
    }

    string getMessage() const{
        return message;
    }
protected:
    string message;
};

// class SillyHandler: public SignalHandler{
//     friend class myContext;
// public:
//     SillyHandler(function<void(SillyEvent*)> f){
//         func = f;
//     }
//     ~SillyHandler(){

//     }
// protected:
//     function<void(SillyEvent*)> func;

//     virtual void handle(SignalEvent* event){
//         SillyEvent* e = static_cast<SillyEvent*>(event);

//         cout<<"Message is being set to "<<e->getMessage()<<endl;
//         func(e);
//     }
// };

class SillySignalBus: public SignalBus{
public:
    SillySignalBus(){}
    ~SillySignalBus(){}

    virtual void emit(string n, string p){
        if(hasSignal(n)){
            vector<SignalHandler*> listeners = (*signals[n]);

            SignalEvent* event = createSignalEvent(n, p);
            sendEvent(n, event);
        }
    }
    int getListenerCount(string n){
        if(hasSignal(n)){
            vector<SignalHandler*>* listeners = signals[n];
            return listeners->size();
        }
        return 0;
    }
protected:
    virtual SignalEvent* createSignalEvent(string n){
        return new SillyEvent(n, myHelper::randomString(10));
    }
    virtual SignalEvent* createSignalEvent(string n, string p){
        return new SillyEvent(n, p);
    }
};

class myContext{
public:
    myContext(){
        function<void(SignalEvent*)> f = [this](SignalEvent* e){
            handle(e);
        };
        handler = new FunctionHandler(f);
    }
    ~myContext(){}

    SignalHandler* handler;
protected:
    void handle(SignalEvent* _e){
        SillyEvent* e = static_cast<SillyEvent*>(_e);

        cout<<"Message: "<<e->getMessage()<<endl;
    }
};

void signalTest(){
   SillySignalBus* bus = new SillySignalBus();

   myContext context;
   bus->subscribe("set", context.handler);

   for(int i=0; i<4; i++){
        if(i%2==0){
            bus->emit("set", "Mishka is old");
        }else{
            cout<<"Nothing at "<<i<<endl;
        }
   }

   bus->unsubscribe("set", context.handler);
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

int main(){
    signalTest();

    return 0;
}