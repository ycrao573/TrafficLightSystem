//
// Created by RYC on 2020/4/14.
//

#include "RoadUser.h"

const Junction &RoadUser::getCurrentJunction() const {
    return currentJunction;
}

void RoadUser::setCurrentJunction(const Junction &currentJunction) {
    RoadUser::currentJunction = currentJunction;
}

const Road &RoadUser::getCurrentRoad() const {
    return currentRoad;
}

void RoadUser::setCurrentRoad(const Road &currentRoad) {
    RoadUser::currentRoad = currentRoad;
}

char RoadUser::getCurrentDirection() const {
    return currentDirection;
}

void RoadUser::setCurrentDirection(char currentDirection) {
    RoadUser::currentDirection = currentDirection;
}

char RoadUser::getNextDirection() const {
    return nextDirection;
}

void RoadUser::setNextDirection(char nextDirection) {
    RoadUser::nextDirection = nextDirection;
}

RoadUser::RoadUser() {
    TODO
    x = y = 0;
}

RoadUser::RoadUser(Junction junction, Road road) {
    this->currentJunction = junction;
    this->currentRoad = road;
}

void RoadUser::moveNorth() {
    y -= speed;
}

void RoadUser::moveSouth() {
    y+=speed;
}

void RoadUser::moveEast() {
    x+=speed;
}

void RoadUser::moveWest() {
    x-=speed;
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
