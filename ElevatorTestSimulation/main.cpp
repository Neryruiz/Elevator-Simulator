#include <iostream>
#include <map>
#include <vector>
#include <deque>


#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "MedicalStaff.h"
#include "SecurityPersonnel.h"
#include "FileRead.h"
#include "TrafficGenerator.h"
#include "SystemController.h"


int main()
    {


    std::string path = "/Users/soumilshah/CLionProjects/ElevatorTestSimulation/input.txt";
    int epoch = 1;

    SystemController *systemcontroller;
    systemcontroller = new SystemController(path , epoch);

    systemcontroller->startElevator();



    return 0;
    }