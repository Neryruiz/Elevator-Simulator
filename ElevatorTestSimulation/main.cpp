#include <iostream>
#include <map>
#include <vector>

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
    int epoch = 4;

    SystemController *systemcontroller;
    systemcontroller = new SystemController(path , epoch);

    
    return 0;
    }