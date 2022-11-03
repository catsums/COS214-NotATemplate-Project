#ifndef WARPHASE_CPP
#define WARPHASE_CPP

#include <vector>
#include "War.h"

using namespace std;

WarPhase::WarPhase(War* _war, string s):BaseWarPhase(s){
		war = _war;
	}
WarPhase::~WarPhase(){
	war = NULL;
}

void WarPhase::handle(vector<Country*>* a, vector<Country*>* b){
	for(int i=0; i<(int)a->size(); i++){
		Country* curr = (*a)[i];
		for(int j=0; i<(int)b->size(); i++){
			Country* other = (*b)[i];

			if(curr->isAlly(other)){
				//other is ally of curr
				cout<<"Handling allies"<<endl;
				//try to interact with the country

			}else if(curr->isEnemy(other)){
				//other is enemy of curr
				cout<<"Handling enemies"<<endl;
				//avoid the country as much as possible

			}else{
				//other and curr have no relation
				cout<<"Handling others"<<endl;
				//dont mind country unless they interact with you

			}
		}
	}
}