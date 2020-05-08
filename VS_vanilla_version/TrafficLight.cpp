#include "TrafficLight.h"    
//iostream required for inputting and outtputting data into system
#include <iostream>
//Windows.h required for sleep functionality
#include "Windows.h"

//function definiton for constructor - no data provided
TrafficLight::TrafficLight() {
    //sets traffic light to initial state of R with hard coded delays
    lastUpdate = 0;
    current_state = state_pair.begin();
    setDelays(this->delayPtr);
}

//function definiton for constructor - no data provided
TrafficLight::TrafficLight(int *delayPtr) {
    //sets traffic light to initial state of R with user defined delays
    lastUpdate = 0;
    current_state = state_pair.begin();
    setDelays(delayPtr);
}

//function definiton for checking if update of states is required
bool TrafficLight::needsUpdate(int current_time) {
    //checks whether time has exceeded delay time of current state
    //true if it has, false if it hasn't
    if ((current_time - lastUpdate) >= current_state->second) {
        return true;
    }
    return false;
}

//function definiton for updating of states
void TrafficLight::doUpdate(int current_time) {
    //iterates through traffic light states
    //once end of seq has been reached, sets state back to initial state
    ++current_state;
    if (current_state == state_pair.end()) {
        current_state = state_pair.begin();
    }
    lastUpdate = current_time;
}

//function definiton for running one light sequence
void TrafficLight::run_one_cycle() {
    //iterates through traffic light states until reached the end of the period of seq
    while (true) {
        ++time;
        //sleep pauses the execution for 1 second
        //implements 1 second time interval between iterations
        Sleep(1000);
        if (time % period == 0) {
            current_state = state_pair.begin();
            break;
        }
        //updates state if time has elapsed delay time of current state
        if (needsUpdate(time))
            doUpdate(time);
    }
}

//function definiton for returning current state
string TrafficLight::getState() {
    return current_state->first;
}

//function definiton for setting delays and calculating period
void TrafficLight::setDelays(int *delayPtr) {
    Rtime = state_pair[0].second = delayPtr[0];
    RAtime = state_pair[1].second = delayPtr[1];
    Gtime = state_pair[2].second = delayPtr[2];
    Atime = state_pair[3].second = delayPtr[3];
    period = Rtime + RAtime + Gtime + Atime;
}
