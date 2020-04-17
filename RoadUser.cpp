//
// Created by RYC on 2020/4/14.
//

#include "RoadUser.h"

RoadUser::RoadUser() {
    x = 0;
    y = 0;
}

RoadUser::RoadUser(Junction junction, Road road) {
    this->currentJunction = junction;
    this->currentRoad = road;
}

void RoadUser::move(){
    switch(currentRoad.getDirection()){
        case 'n':
            y-=speed;   break;
        case 'w':
            x-=speed;   break;
        case 's':
            y+=speed;   break;
        case 'e':
            x+=speed;   break;
        default:
            ;
    }
}

void RoadUser::stop() {
    setVelocity(0);
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

void RoadUser::start() {
    setVelocity(speed);
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