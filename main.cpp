#include "User.h"
#include "Grid.h"
#include "RoadUser.h"
#include "Pedestrian.h"
#include <iostream>
#include <thread>

using namespace std;

int main() {
    cout << "==================================================" << endl
         << "Welcome to Traffic Light System Emulator!" << endl
         << "Created by Group 31: Logan Clark & Yuchen Rao" << endl
         << "==================================================" << endl;
    Grid *grid;
    do {
        cout << '\n' << "Press 'Enter' Key to continue..." << endl;
    } while (cin.get() != '\n');

    string grid_size;
    cout << "Please Input Your Grid Size: (e.g. 2*2)" << endl;
    cin >> grid_size;

    if (grid_size == "1*1")
        grid = new Grid(1, 1);
    else if (grid_size == "2*2")
        grid = new Grid(2, 2);
    else;


    cout << "Input the path length: ";
    int len;
    cin >> len;

    cout << "Choose Your Path: e.g. 1 \n 2 \n 4 \n 3";
    int path[len];
    for (int i = 0; i < len; ++i)
    {
        cin >> path[i];
    }

    cout << "Choose Your Start Road Direction: (e.g. n)";
    char startRdDir;
    cin >> startRdDir;

    //initiate the roadUser

    int startRd;
    switch (startRdDir) {
        case 'n':
            startRd = 0;
            break;
        case 'e':
            startRd = 1;
            break;
        case 's':
            startRd = 2;
            break;
        case 'w':
            startRd = 3;
            break;

        default:;
    }
    RoadUser *logan = new RoadUser(*grid->myNetwork[path[0]-1], grid->myNetwork[path[0]-1]->roadSeq[startRd]);
//    logan->juncSeq = {grid->myNetwork[2], grid->myNetwork[3], grid->myNetwork[1], grid->myNetwork[0]};
//    logan->juncSeqPtr = logan->juncSeq.begin();
    //update the junction sequence
    for(int i = 0; i < len; i++)
        cout<<path[i];

    for(int juncNo = 1; juncNo < len; juncNo++){
        logan->juncSeq.push_back(grid->myNetwork[path[juncNo]-1]);
        cout << "logan" << endl;
    }
    logan->juncSeqPtr = logan->juncSeq.begin();

//    Junction *junction1 = new Junction(100, 100);
//    Junction *junction2 = new Junction(150, 100);
//    Junction *junction3 = new Junction(100, 150);
//    Junction *junction4 = new Junction(150, 150);
//    junction1->setCloseJunctions(nullptr, junction2, nullptr, junction3);
//    junction4->setCloseJunctions(junction3, nullptr, junction2, nullptr);


//    logan->setNextJunction(junction3);
////    add all timing traffic light simultaneously
////    and road user
////
//    thread j1 = junction1->simulate_one_tick();
//    thread j2 = junction2->simulate_one_tick();
//    thread j3 = junction3->simulate_one_tick();
//    thread j4 = junction4->simulate_one_tick();

    //All the junction light will start
//    for(grid->currentJuncThread = grid->junctionThread.begin();
//        grid->currentJuncThread != grid->junctionThread.end(); grid->currentJuncThread++){
//        grid->currentJuncThread->join();
//    }

    thread j1 = grid->myNetwork[0]->simulate_one_tick();
    thread j2 = grid->myNetwork[1]->simulate_one_tick();
    thread j3 = grid->myNetwork[2]->simulate_one_tick();
    thread j4 = grid->myNetwork[3]->simulate_one_tick();
    thread loganCar = logan->drive();

    j1.join();
    j2.join();
    j3.join();
    j4.join();
    loganCar.join();
//    j1.join();
//    j2.join();
//    j3.join();
//    j4.join();
//    loganCar.join();
}