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
    this->currentJunction = junction;
    this->currentRoad = road;
    setPt(road.str_x, road.str_y);
}

void RoadUser::move(){
    while(true){
        cout << "(" << x << "," << y << ")";
        Sleep(1000);
        isPassJunction();
        switch(currentRoad.getDirection()){
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

void RoadUser::changeDirection(char nextDirection) {
    this->nextDirection = nextDirection;
}

int RoadUser::getVelocity() const {
    return velocity;
}

void RoadUser::setVelocity(int velocity) {
    RoadUser::velocity = velocity;
}


const Junction &RoadUser::getCurrentJunction() const {
    return currentJunction;
}

const Road &RoadUser::getCurrentRoad() const {
    return currentRoad;
}

char RoadUser::getCurrentDirection() const {
    return currentDirection;
}

char RoadUser::getNextDirection() const {
    return nextDirection;
}

void RoadUser::setNextDirection(char nextDirection) {
    RoadUser::nextDirection = nextDirection;
}

bool RoadUser::isPassJunction() {
    if(x == currentJunction.ctr_x && y == currentJunction.ctr_y){
        thruJunction();
        return true;
    }
    return false;
}

void RoadUser::thruJunction() {
    if (currentRoad.trafficLight->getState() == "G") {
        start();
    } else
        stop();
}

void RoadUser::setPt(int x, int y){
    this->x = x;
    this->y = y;
}

