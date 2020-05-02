#include "TJunction.h"
#include <iostream>
using namespace std;

TJunction::TJunction() {

    //n: 100, 150 e: 50, 100 , s: 100, 50  , w 150, 100

    //set start point for all the roads in junction

    roadSeq[1].setStrPt(ctr_x - roadSeq[1].getLength(), ctr_y);

    roadSeq[2].setStrPt(ctr_x, ctr_y - roadSeq[2].getLength());

    roadSeq[3].setStrPt(ctr_x + roadSeq[3].getLength(), ctr_y);

    currentRoad = roadSeq.begin();

}

TJunction::TJunction(int ctr_x, int ctr_y) {

    this->ctr_y = ctr_y;

    this->ctr_x = ctr_x;

    //n: 100, 150 e: 50, 100 , s: 100, 50  , w 150, 100

    //set start point for all the roads in junction

    roadSeq[1].setStrPt(ctr_x - roadSeq[1].getLength() + 5, ctr_y);

    roadSeq[2].setStrPt(ctr_x, ctr_y - roadSeq[2].getLength() + 5);

    roadSeq[3].setStrPt(ctr_x + roadSeq[3].getLength() - 5, ctr_y);

    currentRoad = roadSeq.begin();

}


void TJunction::setCloseJunctions(Junction* west, Junction* east, Junction* south) {

    westJunction = west;

    eastJunction = east;

    southJunction = south;

    if (west)

        west->eastJunction = this;

    if (east)

        east->westJunction = this;

    if (south)

        south->northJunction = this;

}
