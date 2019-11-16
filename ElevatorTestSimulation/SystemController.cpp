#include <iostream>
#include <map>
#include <vector>

using  namespace std;


#include "SystemController.h"
#include "TrafficGenerator.h"
#include "StringHelper.h"
#include "Elevators.h"


void SystemController::startElevator()
{
    numberElevator = StringHelper::string_to_int(PData[0][0][1]);
    maxCapacity = StringHelper::string_to_int(PData[0][0][2]);

    // steps
    /*
     * Create Elevator Pointer Array
     * create objects for number of Elevator
     * Set the Direction of Elevator as Going Up
     * Set the low and high Floor
     *
     */

    Elevators *elevator[numberElevator];

    for(int i=0; i<numberElevator; i++)
    {
        elevator[i] = new Elevators();
        elevator[i]->maxCapacity = maxCapacity;
        elevator[i]->elevatorDirection = 'U';
    }

    for(int i=0; i<numberElevator; i++)
    {
        elevator[i]->elevatorIntroduce();
    }


    // Loop for Elevators
    // numberElevator
    for(int i=0;i<1; i++)
    {
        cout << "Id" << elevator[i]->ElevatorId << endl;

        // Each Floor
        for(int j=0;j<Levels.size(); j++){

            elevator[i]->currentFloor = j;
            cout << "\tFloor : " << j << endl;

            for (auto u:Levels.at(j)){
                int temWeiht = elevator[i]->elevatorWeightCounter + u->Weight ;

                if(u->DirectionPassenger == 'U' and temWeiht < maxCapacity and u->CurrentFloor == elevator[i]->currentFloor)
                {
                    // Increase the Weight
                    elevator[i]->elevatorWeightCounter = elevator[i]->elevatorWeightCounter + u->Weight;

                    // Passenger Boarded
                    elevator[i]->Up.push_back(u);

                    cout << "\t\t\t\t\t\t" << "Door Opens :::::" <<
                         elevator[i]->ElevatorId << "Passenger Count ::: "<<
                         elevator[i]->Up.size()<< "Elevator Weight  " << elevator[i]->elevatorWeightCounter << endl;

                    cout << "Dest F  :::" << u->DestinationFloor << endl;
                }
            }
            /*
             * When the Queue is Populated
             * Iterate over Queue
             * Pop and Decrement WeightCounter
             */

            for (int d=0; d<elevator[i]->Up.size(); i++){
                int destfloor = elevator[i]->Up.at(d)->DestinationFloor ;
                int currentFloor = j;
                cout << "Dest ::: "<< destfloor << "Curr::: "<< currentFloor << endl;
            }
        }cout <<"\n";
    }
    cout << "=========================================================" << endl;
    cout << "Levels " << Levels.size() << endl;
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
}

SystemController::~SystemController()
{

}


void SystemController::generateTraffic(int epoch)
{

}