#ifndef OBJECTSIGNALHANDLER_CPP
#define OBJECTSIGNALHANDLER_CPP

#include "ObjectSignalHandler.h"

using namespace std;

template<class T>
ObjectSignalEvent<T>::ObjectSignalEvent(string n, T* _data):SignalEvent(n){
	data = _data;
}
template<class T>
ObjectSignalEvent<T>::ObjectSignalEvent(ObjectSignalEvent& other){
	this->data = other.data;
	this->name = other.name;
}
template<class T>
ObjectSignalEvent<T>::~ObjectSignalEvent(){
	data = NULL;
}
template<class T>
SignalEvent* ObjectSignalEvent<T>::clone(){
	return new ObjectSignalEvent(*this);
}
template<class T>
T* ObjectSignalEvent<T>::getData() const{
	return data;
}

template<class T>
ObjectSignalBus<T>::ObjectSignalBus():SignalBus(){
	
}
template<class T>
ObjectSignalBus<T>::~ObjectSignalBus(){
	
}
template<class T>
void ObjectSignalBus<T>::emit(string n){
	if(hasSignal(n)){
		SignalEvent* event = createSignalEvent(n,NULL);

		sendEvent(n, event);
	}
}
template<class T>
void ObjectSignalBus<T>::emit(string n, T* _data){
	if(hasSignal(n)){
		SignalEvent* event = createSignalEvent(n, _data);

		sendEvent(n, event);
	}
}
template<class T>
SignalEvent* ObjectSignalBus<T>::createSignalEvent(string n){
	return new ObjectSignalEvent<T>(n,NULL);
}
template<class T>
SignalEvent* ObjectSignalBus<T>::createSignalEvent(string n, T* _data){
	return new ObjectSignalEvent<T>(n,_data);
}

#endif