/*
 * This is main.cpp file
 * Name: Soumil nitn Shah
 * Email : soushah@my.briodgeport.edu
 * Student ID: 1031686
 * Os: Mac OS
 *
 */

#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <random>
#include <ctime>


using namespace std;

// Declaration of classes
#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "SecurityPersonnel.h"
#include "MedicalStaff.h"
#include "SystemController.h"
#include "RandomGenerator.h"
#include "DateTime.h"
#include "Elevators.h"
using namespace std;

int main() {
    std::cout << " Main File " << endl;

    // File Path to read the input Path
    std::string path = "/Users/soumilshah/CLionProjects/ElevatorEmulator/input.txt";

    // Create a object of Controller

    SystemController *controller;
    controller = new SystemController();
    controller->readFile(path);

    // ROw 1
    string floor = controller->Data[1].at(0);
    cout << "Floor " << floor << endl;


    // Row 2
    string totalNumberElevator = controller->Data[2].at(0);
    string capacity = controller->Data[2].at(1);
    cout << "Total Elevator : "<< totalNumberElevator << endl;
    cout << "Capacity  " << capacity << endl;

    // Row 3  Visitors
    vector<string> visitor = controller->Data[3];
    for(auto x:visitor){cout << x << " " ;}cout <<"\n";

    // Row 4 Patients
    vector<string> patient = controller->Data[4];
    for(auto x:patient){cout << x << " " ;}cout <<"\n";

    // Row 5 Support Staff
    vector<string> supportstaff = controller->Data[5];
    for(auto x:supportstaff){cout << x << " " ;}cout <<"\n";


    vector<string> medicalstaff = controller->Data[6];
    for(auto x:medicalstaff){cout << x << " " ;}cout <<"\n";

    vector<string> securitystaff = controller->Data[7];
    for(auto x:securitystaff){cout << x << " " ;}cout <<"\n";



    return 0;
}