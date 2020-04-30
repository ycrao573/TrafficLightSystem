//
// Created by RYC on 2020/4/14.
//

#include "Pedestrian.h"

Pedestrian::Pedestrian() {
}

Pedestrian::Pedestrian(Junction junction, Road road) {
    this->currentJunction = junction;
    this->currentRoad = road;
}

void Pedestrian::move() {

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