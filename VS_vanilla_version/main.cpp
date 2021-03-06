#include "Grid.h"
#include "RoadUser.h"
#include "Pedestrian.h"
#include <iostream>
#include <thread>

using namespace std;

int main() {
//Welcome panel
    cout << "==================================================" << endl
         << "Welcome to Traffic Light System Emulator!" << endl
         << "Created by Group 31: Logan Clark & Yuchen Rao" << endl
         << "==================================================" << endl;
    Grid *grid = nullptr;

//show "press any key to continue..." message
    system("pause");

    cout << "\n==================================================" << endl
         << "                    Map Setting                   " << endl
         << "==================================================" << endl;

//input grid size
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
     
    cout << "\n\n==================================================" << endl
         << "                Traffic Light Setting             " << endl
         << "==================================================" << endl;

//user decides if traffic lights are syncronised or working independently
syncronize:
    string ans;
    cout << "Do you want the traffic lights at each junction to be synchronised (y/n)?" << endl;
    cin >> ans;
    if (ans == "n")
        //iterates through traffic lights in grid and ensures they work independently 
        for (int count = 0; count < grid->len * grid->wid; count++) {
            grid->myNetwork[count]->generateIndepSeq();
        }
    else if (ans == "y");
    else
        goto syncronize;

//User chooses the role and path
    string Type, RoadUserType;
    do {
        cout << "\nChoose your role: Road User(r) or Pedestrian(p): \n";
        cin >> Type;
        //user has to decide if they are a bike, car or motorcycle
        if (Type == "r")
            do {
                cout << "\nPlease specify your road user role: Car(c) or Bike(b) or Motorcycle(m) : \n";
                cin >> RoadUserType;
            } while (RoadUserType != "c" && RoadUserType != "b" && RoadUserType != "m");
    } while (Type != "r" && Type != "p");

    int len = 1;
    if (grid_size != "1*1") {
        //while loop will execute while invalid input defined in condition is not met
        do {
            cout << "\nEnter the number of junctions in the route: \n";
            cin >> len;
        } while (len <= 1 || len > 20);
    }
    else
//for the virtual junction in special case: grid size = 1*1
        len = 2;

//choose the path traversal sequence    
path:
    vector<int> path;
    if (grid_size != "1*1") {
        cout << "\nChoose Your route: (e.g. 1 2 4) (Use Enter Key To Separate the Numbers)\n";
        for (int i = 0; i < len; ++i) {
            int temp;
            cin >> temp;
            path.push_back(temp);
            //ensures that path cannot be negative or greater than grid dimensions
            if (path[i] < 1 || path[i] > grid->len * grid->wid) {
                cout << "\nInvalid Input!\n";
                goto path;
            }
        }
    }
    else
//for the virtual junction in special case: grid size = 1*1
        path = {1, 2};

//make sure the path is valid (e.g. the path can't be diagonal or no u-turn path)
    for (int i = 0; i < len - 1; i++) {
        //check the centre point and if distance does not equal 50, the junctions are not adjacent
        if(abs((grid->myNetwork[path[i]-1]->ctr_x + grid->myNetwork[path[i]-1]->ctr_y)
            - (grid->myNetwork[path[i+1]-1]->ctr_x + grid->myNetwork[path[i+1]-1]->ctr_y)) != 50){
            cout << "\nYou can only go to adjacent junctions! Please enter the route again!" << endl;
            goto path;
        }
    }
    for (int i = 0; i + 2 < len; i++) {
        if (path[i] == path[i + 2]) {
            cout << "You cannot do U-turn here\n";
            goto path;
        }
    }

startRd:
    //user decides which road they start in within the grid
    cout << "\nChoose the Initial Direction in which you want to move: (e.g. n) ";
    string startRdDir;
    do {
        cin >> startRdDir;
    }
    //condition to ensure correct start road is associated with user input
    while (startRdDir != "n" && startRdDir != "e" && startRdDir != "s" && startRdDir != "w");
    if (len > 1) {
        //make sure u-turn is invalid for the first junction
        bool u_turn = false;
        if (grid->myNetwork[path[0] - 1]->northJunction == grid->myNetwork[path[1] - 1])
            u_turn = (startRdDir[0] == 's');
        else if (grid->myNetwork[path[0] - 1]->eastJunction == grid->myNetwork[path[1] - 1])
            u_turn = (startRdDir[0] == 'w');
        else if (grid->myNetwork[path[0] - 1]->southJunction == grid->myNetwork[path[1] - 1])
            u_turn = (startRdDir[0] == 'n');
        else if (grid->myNetwork[path[0] - 1]->westJunction == grid->myNetwork[path[1] - 1])
            u_turn = (startRdDir[0] == 'e');
        if (u_turn) {
            cout << "You cannot do U-turn here\n";
            goto startRd;
        }
    }
    int startRd = 0;
    switch (startRdDir[0]) {
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

//create thread array for junction light sequence
    vector<thread> jThread;
    for (int count = 0; count < grid->len * grid->wid; count++) {
        jThread.push_back(grid->myNetwork[count]->simulate_one_tick());
    }
//create thread for pedestrian or roadUser
    thread pedThread;
    thread roadUserThread;
    //if the user chooses a particular type, an object of that type is first created 
    //their starting position in the network is also defined

    if (Type == "p") {
        Pedestrian *ped = new Pedestrian(*grid->myNetwork[path[0] - 1], grid->myNetwork[path[0] - 1]->roadSeq[startRd]);
        //itertes through junctions in grid allowing the pedestrian to follow path defined by user 
        for (int juncNo = 1; juncNo < len; juncNo++) {
            // as the index of myNetwork starts from 0, as juncNo is 1
            //it needs to be changed to 0 to access first element of myNetwork
            ped->juncSeq.push_back(grid->myNetwork[path[juncNo] - 1]);
        }
        //pedestrian junction sequence set to initial element
        ped->juncSeqPtr = ped->juncSeq.begin();
        //executes pedestrian movement simultaneously with the functionality of the rest of the system
        pedThread = ped->walk();
        pedThread.join();
    } else{
        if (RoadUserType == "c") {
            RoadUser *car = new RoadUser(*grid->myNetwork[path[0] - 1], grid->myNetwork[path[0] - 1]->roadSeq[startRd], RoadUserType);
            for (int juncNo = 1; juncNo < len; juncNo++) {
                car->juncSeq.push_back(grid->myNetwork[path[juncNo] - 1]);
            } //itertes through junctions in grid allowing the car to follow path defined by user 
            car->juncSeqPtr = car->juncSeq.begin();
            //executes car movement simultaneously with the functionality of the rest of the system
            roadUserThread = car->drive();
        }else if (RoadUserType == "b") {
            RoadUser *bike = new RoadUser(*grid->myNetwork[path[0] - 1], grid->myNetwork[path[0] - 1]->roadSeq[startRd], RoadUserType);
            //itertes through junctions in grid allowing the bike to follow path defined by user 
            for (int juncNo = 1; juncNo < len; juncNo++) {
                bike->juncSeq.push_back(grid->myNetwork[path[juncNo] - 1]);
            }
            bike->juncSeqPtr = bike->juncSeq.begin();
            //executes bike movement simultaneously with the functionality of the rest of the system
            roadUserThread = bike->drive();
        }else if (RoadUserType == "m") {
            RoadUser *motorcycle = new RoadUser(*grid->myNetwork[path[0] - 1],
                                                grid->myNetwork[path[0] - 1]->roadSeq[startRd], RoadUserType);
            //itertes through junctions in grid allowing the motorcycle to follow path defined by user 
            for (int juncNo = 1; juncNo < len; juncNo++) {
                motorcycle->juncSeq.push_back(grid->myNetwork[path[juncNo] - 1]);
            }
            motorcycle->juncSeqPtr = motorcycle->juncSeq.begin();
            //executes motorcycle movement simultaneously with the functionality of the rest of the system
            roadUserThread = motorcycle->drive();
        }
        roadUserThread.join();
    }
    //joins road user and pedestrian threads, ensuring they are executed simultaneously        
}
