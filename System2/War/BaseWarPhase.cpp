#ifndef BASEWARPHASE_CPP
#define BASEWARPHASE_CPP

#include <iostream>
#include <string>
#include <vector>
#include "BaseWarPhase.h"

using namespace std;

BaseWarPhase::BaseWarPhase(string s){
	state = s;
}
BaseWarPhase::~BaseWarPhase(){

}

string BaseWarPhase::getState(){
	return state;
}

#endif