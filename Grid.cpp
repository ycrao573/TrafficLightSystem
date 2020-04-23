//
// Created by RYC on 2020/4/14.
//

#include <iostream>
#include "Grid.h"


Grid::Grid() {

}

void Grid::doNext() {
    for(;currentJunction!=myNetwork.end();currentJunction++){
        currentJunction->simulate_one_tick();
    }
    cout << "New Network" << endl;
}

void Grid::restart() {

}

void Grid::sync(bool) {

}
