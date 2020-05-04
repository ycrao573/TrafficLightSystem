//
// Created by RYC on 2020/4/14.
//

#include "Pedestrian.h"

Pedestrian::Pedestrian() {
    setSpeed(2);
    setVelocity(getSpeed());
}

Pedestrian::Pedestrian(Junction junction, Road road) {
    setSpeed(2);
    setVelocity(getSpeed());
    this->currentJunction = &junction;
    this->currentRoad = &road;
    setPt(road.str_x, road.str_y);
    cout << "A PEDESTRIAN GENERATED!" << endl;
}

void Pedestrian::move() {
    while (!reachDestination) {
        //change font color showing the currentRoad color
        if (currentJunction->pedestrianLight->canPass)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        else
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        //if velocity is not 0, show distance to the next Junction
        if (velocity != 0) {
            cout << abs(x + y - (currentJunction->ctr_x + currentJunction->ctr_y))
                 << " to the Light.    Current Direction: " << currentRoad->getDirection() <<
                 "    Location: " << currentRoad->roadName(currentRoad->getDirection()) << " of "
                 << currentJunction->name << endl;
        } else {
            if (!currentJunction->pedestrianLight->canPass)
                cout << "Waiting at junction..." << endl;
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

thread Pedestrian::walk() {
    return thread([this] { this->move(); });
}

void Pedestrian::thruJunction() {
    if (juncSeqPtr == juncSeq.end() && currentJunction->ctr_y == y && currentJunction->ctr_x == x) {
        cout << "You have reached your destination" << endl;
        stop();
        reachDestination = true;
    }
    if (currentJunction->pedestrianLight->canPass) {
        cout << "Pedestrian Crossing the Junction!" << endl;
        setCurrentRoad(nextRoad);
        setCurrentJunction(nextJunction);
        currentJunction->pedestrianLight->isCrossing = true;
        Sleep(currentRoad->getWidth() / getSpeed() * 2000);
        currentJunction->pedestrianLight->isCrossing = false;
        start();
    } else {
        if (getVelocity() != 0)
            stop();
    }
}

bool Pedestrian::isPassJunction() {
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

void Pedestrian::setCurrentJunction(Junction *currentJunction) {
    this->currentJunction = currentJunction;
}

void Pedestrian::setNextJunction(Junction *nextJunction) {
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

void Pedestrian::setCurrentRoad(Road *currentRoad) {
    this->currentRoad = currentRoad;
}

void Pedestrian::setNextRoad(Road *nextRoad) {
    this->nextRoad = nextRoad;
}
