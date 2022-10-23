#ifndef SIGNALHANDLER_CPP
#define SIGNALHANDLER_CPP

#include "SignalHandler.h"
#include "../myHelper.cpp"

/////SignalEvent
SignalEvent::SignalEvent(){
	name = "";
}
SignalEvent::SignalEvent(string n){
	name = n;
}
SignalEvent::~SignalEvent(){

}
string SignalEvent::getEventName() const{
	return name;
}

static int CALLCOUNT = 0;

SignalDefaultEvent::SignalDefaultEvent(string n):SignalEvent(n){
	// name = n;
	callTime = time(0);
	callCount = CALLCOUNT++;
}
SignalDefaultEvent::SignalDefaultEvent(SignalDefaultEvent& other){
	name = other.name;
	callTime = other.callTime;
	callCount = other.callCount;
}
SignalDefaultEvent::~SignalDefaultEvent(){

}
SignalEvent* SignalDefaultEvent::clone(){
	return new SignalDefaultEvent(*this);
}
/////SignalHandler
SignalHandler::SignalHandler(){
	id = myHelper::randomString(8);
}
SignalHandler::~SignalHandler(){
	
}
string SignalHandler::getID() const{
	return id;
}

FunctionHandler::FunctionHandler(function<void(SignalEvent*)> newFunc){
	func = newFunc;
}
FunctionHandler::~FunctionHandler(){
	func = NULL;
}
void FunctionHandler::handle(SignalEvent* event){
	//run function
	func(event);
}
/////SignalBus
SignalBus::SignalBus(){

}
SignalBus::~SignalBus(){
	
}
bool SignalBus::hasSignal(string n){
	return (signals.count(n)>0);
}
void SignalBus::subscribe(string n, SignalHandler* listener){
	if(!hasSignal(n)){
		signals[n] = new vector<SignalHandler*>();
	}
	vector<SignalHandler*>* listeners = signals[n];

	listeners->push_back(listener);
}
void SignalBus::unsubscribe(string n, SignalHandler* listener){
	if(hasSignal(n)){
		vector<SignalHandler*>* listeners = signals[n];

		for(int i=0; i<listeners->size(); i++){
			SignalHandler* handler = (*listeners)[i];
			if(listener == handler || listener->getID() == handler->getID()){
				listeners->erase(listeners->begin()+i);
				i--; //just to retain index
			}
		}
	}
}
void SignalBus::emit(string n){
	if(hasSignal(n)){
		SignalEvent* event = createSignalEvent(n);

		sendEvent(n, event);
	}
}
void SignalBus::sendEvent(string n, SignalEvent* event){
	if(hasSignal(n)){
		// cout<<"- sending event..."<<endl;
		vector<SignalHandler*>* listeners = signals[n];
		// cout<<"- NumOfListeners..."<<listeners->size()<<endl;
		for(int i=0; i<listeners->size(); i++){
			SignalHandler* handler = (*listeners)[i];
			handler->handle(event);
		}
	}
}

SignalEvent* SignalBus::createSignalEvent(string n){
	SignalEvent* event = new SignalDefaultEvent(n);

	return event;
}


#endif