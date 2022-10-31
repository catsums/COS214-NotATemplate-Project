#include <iostream>

#include "WarEngine.h"

using namespace std;

void WarEngine::updateWarEngineData(){
  //update other classes
}

WarEngine::WarEngine(){
  //create other classes
}

WarEngine::~WarEngine(){}

WarEngine& WarEngine::instance(){
  static WarEngine onlyInstance_;
  return onlyInstance_;
}
