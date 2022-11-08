#ifndef RESOURCE_CPP
#define RESOURCE_CPP

#include "Resource.h"

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

Resource::Resource(){
	id = randomString(8);
	used = false;

	types.push_back("Resource");
}
Resource::Resource(Resource& r){
	id = randomString(8);
	used = r.used;

	types.push_back("Resource");
}
Resource::~Resource(){

}

bool Resource::isUsed(){
	return used;
}

#endif