/** @file PhaseManager.h
 *  @brief Header for the PhaseManager class.
 *
 *  PhaseManager is the context participant of the state pattern. 
 *  It controls and maintains the phases.
 */

#ifndef PHASEMANAGER_H
#define PHASEMANAGER_H

#include <iostream>

#include "../WarEngine/WarEngine.h"
#include "Peace.h"
#include "Negotiations.h"
#include "War.h"

using namespace std;

class PhaseManager { 
    public: 
        /** Constructor
         * @param WarEngine reference to warEngine
        */
        PhaseManager(WarEngine* w);

        /** Destructor
        */
        ~PhaseManager();
        
        /** Decides action based on how the state handles it
         * @param WarEngine country array
         * @param int current country being worked on
        */
        void DecideAction(vector<Country*> countryArr, int i);

        /** Changes the state
         * @param Phase state to change to
        */
        void setPhase(Phase* p);

        WarEngine* w; /**<WarEngine Holds reference to WarEngine*/
    private: 
        Phase* phase; /**<Phase holds current phase*/
};

#endif