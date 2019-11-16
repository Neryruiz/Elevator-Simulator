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

//    deque <int> tem ;
//    tem.push_back(11);
//    tem.push_back(22);
//    tem.push_back(33);
//
//    cout << "==" << endl;
//
//        cout << "=="<< endl;
//        for (int i=0; i <tem.size(); i++)
//        {
//            cout << tem[i] << endl;
//
//        }
//
//    for (int i=0; i <tem.size(); i++)
//    {
//
//        if (tem[i] == 22)
//        {
//            tem.erase(tem.begin()+i);
//        }
//    }
//        cout << "=="<< endl;
//        for (int i=0; i <tem.size(); i++)
//        {
//            cout << tem[i] << endl;
//
//        }
//



    return 0;
    }