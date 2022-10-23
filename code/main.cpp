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

	Country* zim = new Country("Zimbabwe");

	zim->addAlly(new Country("Phillipines"));

	zim->print();

	return 0;
}