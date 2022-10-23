#ifndef WARPHASE_CPP
#define WARPHASE_CPP

#include <iostream>
#include <string>
#include <vector>
#include "WarPhase.h"

using namespace std;

WarPhase::WarPhase(string s){
	state = s;
}
WarPhase::~WarPhase(){

}

string WarPhase::getState(){
	return state;
}

PhaseNeutral::PhaseNeutral():WarPhase("neutral"){

}
PhaseNeutral::~PhaseNeutral(){

}
void PhaseNeutral::handle(vector<Country*> a, vector<Country*> b){
	for(int i=0; i<a.size(); i++){
		Country* curr = a[i];

		for(int j=0; i<b.size(); i++){
			Country* other = b[i];

			if(curr->isAlly(other)){
				//other is ally of curr

				//try to interact with the country

			}else if(curr->isEnemy(other)){
				//other is enemy of curr

				//avoid the country as much as possible

			}else{
				//other and curr have no relation

				//dont mind country unless they interact with you

			}
		}
	}
}

PhasePeace::PhasePeace():WarPhase("peace"){

}
PhasePeace::~PhasePeace(){

}
void PhasePeace::handle(vector<Country*> a, vector<Country*> b){

}


PhaseOpenConflict::PhaseOpenConflict():WarPhase("openConflict"){

}
PhaseOpenConflict::~PhaseOpenConflict(){
	
}
void PhaseOpenConflict::handle(vector<Country*> a, vector<Country*> b){

}

PhaseCrisis::PhaseCrisis():WarPhase("crisis"){

}
PhaseCrisis::~PhaseCrisis(){
	
}
void PhaseCrisis::handle(vector<Country*> a, vector<Country*> b){
	
}

PhaseWar::PhaseWar():WarPhase("war"){

}
PhaseWar::~PhaseWar(){
	
}
void PhaseWar::handle(vector<Country*> a, vector<Country*> b){
	
}

PhaseNegotiations::PhaseNegotiations():WarPhase("negotiations"){

}
PhaseNegotiations::~PhaseNegotiations(){
	
}
void PhaseNegotiations::handle(vector<Country*> a, vector<Country*> b){
	
}

#endif