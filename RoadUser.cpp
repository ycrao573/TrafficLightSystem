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
RoadUser::RoadUser(Junction junction, Road road, string type) {
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
    this->currentJunction = &junction;
    this->currentRoad = &road;
    setPt(road.str_x, road.str_y);
}

//function definition for movement of road user
void RoadUser::move() {
    while (!reachDestination) {
        //change font color showing the currentRoad color
        if (currentRoad->trafficLight->getState() == "R")
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        else if (currentRoad->trafficLight->getState() == "G")
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

        //if velocity is not 0, show distance to the next Junction
        if (velocity != 0)
            cout << abs(x + y - (currentJunction->ctr_x + currentJunction->ctr_y))
                 << " to the Light.    Current Direction: " << currentRoad->getDirection() <<
                 "    Location: " << currentRoad->roadName(currentRoad->getDirection()) << " of "
                 << currentJunction->name << endl;
            //if velocity is 0, car is waiting at the junction
        else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
            if (!currentJunction->pedestrianLight->canPass)
                cout << "Waiting at junction..." << endl;
            else
                cout << "===PEDESTRIAN CROSSING!===" << endl;
        }
        Sleep(1000);
        isPassJunction();
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

thread RoadUser::drive() {
    return thread([this] { this->move(); });
}

bool RoadUser::isPassJunction() {
    if (x == currentJunction->ctr_x && y == currentJunction->ctr_y) {
        thruJunction();
        flag_passed = true;
        return true;
    } else if (flag_passed) {
        setNextJunction(*juncSeqPtr);
        juncSeqPtr++;
        flag_passed = false;
    }
    return false;
}

void RoadUser::thruJunction() {
    if (juncSeqPtr == juncSeq.end() && currentJunction->ctr_y == y && currentJunction->ctr_x == x) {
        cout << "You have reached your destination" << endl;
        stop();
        reachDestination = true;
    } else if (currentRoad->trafficLight->getState() == "G" && !currentJunction->pedestrianLight->isCrossing) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
        cout << "PASSING THE JUNCTION NOW" << endl;
        setCurrentRoad(nextRoad);
        setCurrentJunction(nextJunction);
        start();
    } else {
        if (getVelocity() != 0)
            stop();
    }
}

void RoadUser::setCurrentJunction(Junction *currentJunction) {
    RoadUser::currentJunction = currentJunction;
}

void RoadUser::setNextJunction(Junction *nextJunction) {
    this->nextJunction = nextJunction;
    if (currentJunction->northJunction == nextJunction)
        setNextRoad(&nextJunction->roadSeq[0]);
    else if (currentJunction->eastJunction == nextJunction)
        setNextRoad(&nextJunction->roadSeq[1]);
    else if (currentJunction->southJunction == nextJunction)
        setNextRoad(&nextJunction->roadSeq[2]);
    else if (currentJunction->westJunction == nextJunction)
        setNextRoad(&nextJunction->roadSeq[3]);
}

void RoadUser::setCurrentRoad(Road *currentRoad) {
    RoadUser::currentRoad = currentRoad;
}

void RoadUser::setNextRoad(Road *nextRoad) {
    RoadUser::nextRoad = nextRoad;
}
