#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <cmath>
#include <math.h>

#include <functional>

#include "Country/Country.h"
#include "SignalHandler/SignalHandler.h"
#include "War/War.h"
#include "myHelper.cpp"

using namespace std;

int main(){

	War* war = new War(new PhaseNeutral());

	Country* c0 = new Country("NewZealand");
	Country* c1 = new Country("Russia");
	Country* c2 = new Country("Zimbabwe");
	Country* c3 = new Country("USA");

	war->addCountry(c0,0);
	war->addCountry(c1,0);
	war->addCountry(c2,1);
	war->addCountry(c3,1);

	war->printSides();

	war->removeCountry(c0,0);

	war->printSides();

	return 0;
}