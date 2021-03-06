//
// Created by RYC on 2020/4/14.
//

#include "Pedestrian.h"

//function definition for constructor - no data provided
Pedestrian::Pedestrian() {
    setSpeed(1);
    setVelocity(getSpeed());
}

//function definition for constructor - data provided
Pedestrian::Pedestrian(Junction junction, Road road) {
    //set pedestrian starting position to user defined junction and road
    setSpeed(1);
    setVelocity(getSpeed());
    this->currentJunction = &junction;
    this->currentRoad = &road;
    setPt(road.str_x, road.str_y);
    cout << "A PEDESTRIAN GENERATED!" << endl;
}

//function definition for pedestrian movement
void Pedestrian::move() {
    while (!reachDestination) {
        //change font colour showing the traffic light state of the current road
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
            //display waiting message when pedestrain is unable to cross
            if (!currentJunction->pedestrianLight->canPass)
                cout << "Waiting at junction..." << endl;
        }
        //generates 1 second time interval
        Sleep(1000);
        //check each second if pedestrian has reached the junction
        isPassJunction();
        //set pedestrian's direction of movement to user chosen direction
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

//function definition for executing pedestrian functionality simultaneously to the rest of the system
thread Pedestrian::walk() {
    return thread([this] { this->move(); });
}

//function definition to execute pedestrian crossing the junction
void Pedestrian::thruJunction() {
    //once the destination has been reached, program is stopped
    if (juncSeqPtr == juncSeq.end() && currentJunction->ctr_y == y && currentJunction->ctr_x == x) {
        cout << "You have reached your destination" << endl;
        stop();
        reachDestination = true;
    }
    //initiates pedestrian crossing the junction
    if (currentJunction->pedestrianLight->canPass) {
        cout << "Pedestrian Crossing the Junction!" << endl;
        setCurrentRoad(nextRoad);
        setCurrentJunction(nextJunction);
        //true while pedestrian is crossing
        currentJunction->pedestrianLight->isCrossing = true;
        //generates time interval taken for pedestrain to cross road
        Sleep(currentRoad->getWidth() / getSpeed() * 1000);
        //false when pedestrian has crossed
        currentJunction->pedestrianLight->isCrossing = false;
        start();
    } else {
        //pedestrian has to remain stationary as traffic light of current road is red
        if (getVelocity() != 0)
            stop();
    }
}

//function definition for pedestrain passing junction
bool Pedestrian::isPassJunction() {
    //checks whether pedestrian has reached the junction
    if (x == currentJunction->ctr_x && y == currentJunction->ctr_y) {
        thruJunction();
        //true when pedestrian has passed the junction
        flag_passed = true;
        return true;
    } else if (flag_passed) {
        //when pedestrian has passed the junctio, next junction generated
        setNextJunction(*juncSeqPtr);
        juncSeqPtr++;
        flag_passed = false;
    }
    return false;
}

//function definition for setting current junction
void Pedestrian::setCurrentJunction(Junction *currentJunction) {
    this->currentJunction = currentJunction;
}

//function definition for setting next junction
void Pedestrian::setNextJunction(Junction *nextJunction) {
    //connects junction to adjacent junction
    //if next junction is north, next road is set to south road
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

//function definition for setting current road
void Pedestrian::setCurrentRoad(Road *currentRoad) {
    this->currentRoad = currentRoad;
}

//function definition for setting next road
void Pedestrian::setNextRoad(Road *nextRoad) {
    this->nextRoad = nextRoad;
}
