#ifndef BATTLE_CPP
#define BATTLE_CPP

#include "Battle.h"

using namespace std;

Battle::Battle(Country* aa,Country* bb){
	a = aa; b = bb;
}
Battle::~Battle(){
	a = NULL; b = NULL;
}

bool Battle::commenceBattle(){
	return false;
}

#endif