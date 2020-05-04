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

grid:
    string grid_size;
    cout << "Please Input Your Grid Size: (e.g. 2*2)" << endl;
    cin >> grid_size;

    if (grid_size == "1*1")
        grid = new Grid(1, 1);
    else if (grid_size == "2*1")
        grid = new Grid(1, 2);
    else if (grid_size == "1*2")
        grid = new Grid(2, 1);
    else if (grid_size == "2*2")
        grid = new Grid(2, 2);
    else if (grid_size == "3*3")
        grid = new Grid(3, 3);
    else {
        cout << "INVALID INPUT!\n";
        goto grid;
    }
    cout << "Network has been set up!\n";

    cout << "Do you want traffic lights to be synchronized (y/n)?" << endl;
    char ans;
    cin >> ans;
    if(ans == 'y')
        for(int count = 0; count < grid->len * grid->wid; count++) {
            grid->myNetwork[count]->generateIndepSeq();
        }

    thread jThread[grid->len * grid->wid] ;
    for(int count = 0; count < grid->len * grid->wid; count++) {
        jThread[count] = grid->myNetwork[count]->simulate_one_tick();
    }

    cout << "Choose your identity: Car('c') or Pedestrian('p')   ";
    char id;
    cin >> id;

    cout << "Input the path length: ";
    int len;
    cin >> len;

    cout << "Choose Your Path: e.g. 1 \n 2 \n 4 \n 3\n";
    int path[len];
    for (int i = 0; i < len; ++i)
        cin >> path[i];

    cout << "Choose Your Start Road Direction: (e.g. n) ";
    char startRdDir;
    cin >> startRdDir;

    //initiate the User
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

    thread pedThread;
    thread carThread;
    if (id == 'c') {
        RoadUser *car = new RoadUser(*grid->myNetwork[path[0] - 1], grid->myNetwork[path[0] - 1]->roadSeq[startRd]);
        for (int i = 0; i < len; i++)
            cout << path[i];
        for (int juncNo = 1; juncNo < len; juncNo++) {
            car->juncSeq.push_back(grid->myNetwork[path[juncNo] - 1]);
        }
        car->juncSeqPtr = car->juncSeq.begin();
        carThread = car->drive();
    } else if (id = 'p') {
        Pedestrian *ped = new Pedestrian(*grid->myNetwork[path[0] - 1], grid->myNetwork[path[0] - 1]->roadSeq[startRd]);
        for (int i = 0; i < len; i++)
            cout << path[i];
        for (int juncNo = 1; juncNo < len; juncNo++) {
            ped->juncSeq.push_back(grid->myNetwork[path[juncNo] - 1]);
        }
        ped->juncSeqPtr = ped->juncSeq.begin();
        pedThread = ped->walk();
    } else;

    for(int count = 0; count < grid->len * grid->wid; count++) {
        jThread[count].join();
    }
    carThread.join();
    pedThread.join();
}