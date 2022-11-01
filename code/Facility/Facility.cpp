#ifndef FACILITY_CPP
#define FACILITY_CPP

#include "Facility.h"

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

Facility::Facility(){
	id = randomString(8);
	land = false;
	sea = false;
}
Facility::Facility(string c){
	id = randomString(8);
	country = c;
	land = false;
	sea = false;
}
Facility::~Facility(){

}


#endif