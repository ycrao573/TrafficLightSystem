//
// Created by RYC on 2020/4/14.
//

#include "Pedestrian.h"

Pedestrian::Pedestrian() {
    x = 0;
    y = 0;
}

Pedestrian::Pedestrian(Junction junction, Road road) {
    this->currentJunction = junction;
    this->currentRoad = road;
}

void Pedestrian::move() {
    if(needUpdateJunction()){
        updateJunction();
    } else
        updateRoad();
}

bool Pedestrian::needUpdateJunction() {
//    if (x,y) is out of range, then setNextJunction = xxxJunction return true
}

void Pedestrian::updateJunction() {
//    setNextJunction(xxxxx)
    this->currentJunction = nextJunction;
    updateRoad();
}

void Pedestrian::updateRoad() {
    //if xxxx
    //setNextRoad(xxx->xxxxRoad) road[]
    this->currentRoad = nextRoad;
}

const Road &Pedestrian::getNextRoad() const {
    return nextRoad;
}

void Pedestrian::setNextRoad(const Road &nextRoad) {
    Pedestrian::nextRoad = nextRoad;
}

const Junction &Pedestrian::getNextJunction() const {
    return nextJunction;
}

void Pedestrian::setNextJunction(const Junction &nextJunction) {
    Pedestrian::nextJunction = nextJunction;
}