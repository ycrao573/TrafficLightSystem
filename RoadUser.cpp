//
// Created by RYC on 2020/4/14.
//


#include "RoadUser.h"
#include "Windows.h"
#include <iostream>

using namespace std;

RoadUser::RoadUser() {
    setPt(0, 0);
}

RoadUser::RoadUser(Junction junction, Road road) {
    this->currentJunction = &junction;
    this->currentRoad = &road;
    setPt(road.str_x, road.str_y);
    cout << "A CAR GENERATED!" << endl;
}

void RoadUser::move(){
    while(!reachDestination){
        //change font color showing the currentRoad color
        if(currentRoad->trafficLight->getState() == "R")
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        else if(currentRoad->trafficLight->getState() == "G")
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

        //if velocity is not 0, show distance to the next Junction
        if(velocity != 0)
            cout << abs(x + y - (currentJunction->ctr_x + currentJunction->ctr_y)) << " to the next junction.    Current Direction: " << currentRoad->getDirection() << endl;
            //if velocity is 0, meaning car is waiting at junction
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
            if(!currentJunction->pedestrianLight.canPass)
                cout << "Waiting at junction..." << endl;
            else
                cout << "===PEDESTRIAN CROSSING!===" << endl;
        }
        Sleep(1000);
        isPassJunction();
        switch(currentRoad->getDirection()){
            case 'n':
                y-=velocity;   break;
            case 'w':
                x-=velocity;   break;
            case 's':
                y+=velocity;   break;
            case 'e':
                x+=velocity;   break;
            default:
                ;
        }
    }
}

thread RoadUser::drive(){
    return thread( [this] { this->move(); } );
}

void RoadUser::stop() {
    setVelocity(0);
}

void RoadUser::start() {
    setVelocity(speed);
}

int RoadUser::getVelocity() const {
    return velocity;
}

void RoadUser::setVelocity(int velocity) {
    RoadUser::velocity = velocity;
}

bool RoadUser::isPassJunction() {
    if(x == currentJunction->ctr_x && y == currentJunction->ctr_y){
        thruJunction();
        flag_passed = true;
        return true;
    }else if(flag_passed) {
        setNextJunction(*juncSeqPtr);
        juncSeqPtr++;
        flag_passed = false;
    }
    return false;
}

void RoadUser::thruJunction() {

    if(juncSeqPtr == juncSeq.end() && currentJunction->ctr_y == y && currentJunction->ctr_x == x){
        cout << "You have reached your destination" << endl;
        stop();
        reachDestination = true;
    }else if (currentRoad->trafficLight->getState() == "G") {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
        cout << "Passing the junction NOW!!!" << endl;
        setCurrentRoad(nextRoad);
        setCurrentJunction(nextJunction);
        start();
    }else{
        if(velocity != 0)
            stop();
    }
}

void RoadUser::setPt(int x, int y){
    this->x = x;
    this->y = y;
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