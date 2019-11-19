#include <iostream>
#include <map>
#include <vector>

using  namespace std;


#include "SystemController.h"
#include "TrafficGenerator.h"
#include "StringHelper.h"
#include "Elevators.h"
#include "Display.h"

void SystemController::startElevator()
{
    numberElevator = StringHelper::string_to_int(PData[0][0][1]);
    maxCapacity = StringHelper::string_to_int(PData[0][0][2]);
    cout << "MMMAXX" << maxFloor << endl;
    // steps
    /*
     * Create Elevator Pointer Array
     * create objects for number of Elevator
     * Set the Direction of Elevator as Going Up
     * Set the low and high Floor
     *
     */

    // Reverse Map
    map<int , vector<Passenger *>> LevelDest;
    for (int i=0; i<Levels.size(); i++)
    {
        for(auto x: Levels[i])
        {
            LevelDest[x->DestinationFloor].push_back(x);
        }
    }

    Display::displayDestinationFloors(LevelDest);

    Elevators *elevator[numberElevator];

    for(int i=0; i<numberElevator; i++)
    {
        elevator[i] = new Elevators();
        elevator[i]->maxCapacity = maxCapacity;
        elevator[i]->elevatorDirection = 'U';
//        elevator[i]->higestFloor = Levels.size();            // max floor
    }

    for(int i=0; i<numberElevator; i++)
    {
        elevator[i]->elevatorIntroduce();
    }

    int uindex = 0;
    int temWeiht = 0;

    // Loop for Elevators
    // numberElevator
    for(int i=0;i<1; i++)
    {
        temWeiht = 0;
        cout << "Id: \t" << elevator[i]->ElevatorId << endl;

        // Each Floor
        for(int j=0;j<Levels.size(); j++){

            elevator[i]->currentFloor = j;
            cout << "Floor :\t" << j << endl;

            uindex = 0;
            for (auto u:Levels.at(j))
            {
                if(Levels[j].size() > 0)
                {
                     temWeiht = elevator[i]->elevatorWeightCounter + (u)->Weight ;

                    if((u)->DirectionPassenger == 'U' and temWeiht < maxCapacity and (u)->CurrentFloor == elevator[i]->currentFloor)
                    {
                        // Increase the Weight
                        elevator[i]->elevatorWeightCounter = elevator[i]->elevatorWeightCounter + (u)->Weight;

                        // Passenger Boarded    Deque Data Structure
                        elevator[i]->Up.push_back((u));

                        cout << "\t\t\t\t\t\t" << "Door Opens :\t"
                             << "Elevator Weight: \t" << elevator[i]->elevatorWeightCounter << "\t" << (u)->PassengerId
                             << " Dest: \t" <<  (u)->DestinationFloor << endl;


                        // Passenger should be removed from Levels once served
                        try{

                            cout << Levels.at(j).size() << " : " <<   uindex << endl;
                            if(Levels.at(j).size() < uindex){
                                throw 999;
                            }else{
                                Levels.at(j).erase(Levels[j].begin() + uindex);
                            }
                            }catch (int e)
                            {
                                cout << "error :  "<< e << endl;
                            }


                    }else{
                        uindex = uindex + 1;
                    }
                }
                // uindex = uindex + 1;
            }


        }cout <<"\n";
    }
    cout << "=========================================================" << endl;

    cout << "Levels " << Levels.size() << endl;

    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Floor Summary   " << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";

    // LEVEL DATA STRUCTURE
    for(int j = 0; j< Levels.size(); j++)
    {
        cout << "Floor : " << j << "  Passenger : " ;

        for (auto x: Levels[j])
        {
            cout << x->PassengerId << " " << x->DirectionPassenger << " " << " W: " << x->Weight << " "  ;
        }cout << "\n";

    }



    cout << "\n";
    cout << "\t\t==============================================="<< endl;
    cout << "\t\t\t\t\t" << "Dest levels   " << endl;
    cout << "\t\t==============================================="<< endl;
    cout << "\n";


    // LEVEL DATA STRUCTURE
    for(int j = 0; j< LevelDest.size(); j++)
    {
        cout << "Floor : " << j << "  Passenger : " ;

        for (auto x: LevelDest[j])
        {
            cout << x->PassengerId << " " << x->DirectionPassenger << " " << " W: " << x->Weight << " "  ;
        }cout << "\n";

    }cout << "\n";




    cout << "========" << endl;
//
//    for (int i =1; i < PData.size();i++ )
//    {
//
//        for (auto x:PData[i][1] )
//        {
//            cout << x << " ";
//        }cout << "\n";
//
//    }


}


SystemController::SystemController(std::string p, int epoch):path{p},epoch{epoch}
{

    // create  a  object of Traffic Generator
    TrafficGenerator *generate;
    generate = new TrafficGenerator(path);

    for(int i=0; i<epoch; i++)
    {
        generate->generatePassengers();
    }

    Levels = generate->Levels;
    PData= generate->PData;
    generate->displayPassenger();
    cout << " MAX FLOOR " << StringHelper::string_to_int(PData[0][0][0]) << endl;
    maxFloor = StringHelper::string_to_int(PData[0][0][0]);

}

SystemController::~SystemController()
{

}


void SystemController::generateTraffic(int epoch)
{

}