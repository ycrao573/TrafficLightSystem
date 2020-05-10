//
// Created by RYC on 2020/4/14.
//

#include "RoadUser.h"
//allows user to input and output to the system
#include <iostream>
using namespace std;

//function definition for constructor - no data provided
RoadUser::RoadUser() {
    setPt(0, 0);
    setSpeed(10);
    setVelocity(getSpeed());
}

//function definition for constructor - data provided
RoadUser::RoadUser(Junction& junction, Road& road, string type) {
    //generate and set different speeds for each road user type
    if(type == "c"){
        setSpeed(10);
        cout << "A CAR GENERATED!" << endl;
    }else if(type == "b"){
        setSpeed(2);
        cout << "A BIKE GENERATED!" << endl;
    }else if(type == "m"){
        setSpeed(5);
        cout << "A MOTORCYCLE GENERATED!" << endl;
    }
    setVelocity(getSpeed());
    //to ensure road user is in the junction
    //address of current junction is assigned to instance of junction passed by ref
    this->currentJunction = &junction;
    this->currentRoad = &road;
    setPt(road.str_x, road.str_y);
}

//function definition for movement of road user
void RoadUser::move() {
    while (!reachDestination) {
        //change font colour to show the state of the traffic light of the currrent road
        if (currentRoad->trafficLight->getState() == "R")
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        else if (currentRoad->trafficLight->getState() == "G")
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        else if (currentRoad->trafficLight->getState() == "RA")
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x46);
        else if (currentRoad->trafficLight->getState() == "A")
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        //if velocity is not 0, show distance to the next Junction
        if (velocity != 0)
            cout << abs(x + y - (currentJunction->ctr_x + currentJunction->ctr_y))
                 << " m to the Light.    Current Direction of travel: " << currentRoad->getDirection() <<
                 "    Location: " << currentRoad->roadName(currentRoad->getDirection()) << " of "
                 << currentJunction->name << endl;
            //if velocity is 0, car is waiting at the junction
        else {
            //sets font colour back to default
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            if (!currentJunction->pedestrianLight->canPass)
                cout << "Waiting at " << currentRoad->roadName(currentRoad->getDirection()) <<" of " << currentJunction->name << "..." << endl;
            else
                cout << "===PEDESTRIAN CROSSING!===" << endl;
        }
        //generates 1 second time interval
        Sleep(1000);
        //need to check each second, if user has reached junction
        isPassJunction();
        //movement according to direction chosen by user
        switch (currentRoad->getDirection()) {
            case 'n':
                y -= velocity;
                break;
            case 'w':
                x -= velocity;
                break;
            case 's':
                y += velocity;
                break;
            case 'e':
                x += velocity;
                break;
            default:;
        }
    }
}

//function definition for executing road user's movement simultaneously
//with the rest of the system
thread RoadUser::drive() {
    return thread([this] { this->move(); });
}

//function definition to check if user has reached junction
bool RoadUser::isPassJunction() {
    //if user has reached junction, user turns (direction depends on user path)
    //junction is then passed 
    if (x == currentJunction->ctr_x && y == currentJunction->ctr_y) {
        thruJunction();
        flag_passed = true;
        return true;
    //as user has already passed junction, next junction is set 
    } else if (flag_passed) {
        if (juncSeqPtr != juncSeq.end()) {
            setNextJunction(*juncSeqPtr);
            juncSeqPtr++;
        }
        else
            reachLastJunction = true;
        flag_passed = false;
    }
    return false;
}

//function definition for changing user direction once they have reached junction
void RoadUser::thruJunction() {  
    //if destination has been reached, stop program
    if (juncSeq.back()->ctr_y == y && juncSeq.back()->ctr_x == x && reachLastJunction) {
        cout << "You have reached your destination" << endl;
        stop();
        reachDestination = true;
        exit(0);
    }
    //road user can pass junction if no pedstrian is crossing the road and current road's traffic light is green
     if (currentRoad->trafficLight->getState() == "G" && !currentJunction->pedestrianLight->isCrossing) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "TRAFFIC LIGHT IS GREEN - PASSING " << currentJunction->name << " NOW" << endl;
        setCurrentRoad(nextRoad);
        setCurrentJunction(nextJunction);
        start();
    } else {
        //road user cannot pass junction as a pedstrian is crossing the road and current road's traffic light is red
        if (getVelocity() != 0)
            stop();
    }
}

//function definition for setting current junction
void RoadUser::setCurrentJunction(Junction *currentJunction) {
    RoadUser::currentJunction = currentJunction;
}

//function definition for setting next junction
void RoadUser::setNextJunction(Junction *nextJunction) {
    this->nextJunction = nextJunction;
    //if next junction is north of the current junction
    //road of next junction set to south road
    if (currentJunction->northJunction == nextJunction)
        setNextRoad(&nextJunction->roadSeq[0]);
    else if (currentJunction->eastJunction == nextJunction)
        setNextRoad(&nextJunction->roadSeq[1]);
    else if (currentJunction->southJunction == nextJunction)
        setNextRoad(&nextJunction->roadSeq[2]);
    else if (currentJunction->westJunction == nextJunction)
        setNextRoad(&nextJunction->roadSeq[3]);
}

//function definition for setting current road
void RoadUser::setCurrentRoad(Road *currentRoad) {
    RoadUser::currentRoad = currentRoad;
}

//function definition for setting next road
void RoadUser::setNextRoad(Road *nextRoad) {
    RoadUser::nextRoad = nextRoad;
}
