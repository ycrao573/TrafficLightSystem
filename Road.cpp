//
// Created by RYC on 2020/4/14.
//

#include "Road.h"

Road::Road() {
    this->direction = 'n';
    this->length = 50;
    this->width = 20;
    trafficLight = TrafficLight(delayPtr);
}

Road::Road(char direction, int length, int width) {
    this->direction = direction;
    this->length = length;
    this->width = width;
    trafficLight = TrafficLight(delayPtr);
}

char Road::getDirection() const {
    return direction;
}

void Road::setDirection(char direction) {
    Road::direction = direction;
}

int Road::getLength() const {
    return length;
}

void Road::setLength(int length) {
    Road::length = length;
}

int Road::getWidth() const {
    return width;
}

void Road::setWidth(int width) {
    Road::width = width;
}
