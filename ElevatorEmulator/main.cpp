/*
 * This is main.cpp file
 * Name: Soumil nitn Shah
 * Email : soushah@my.briodgeport.edu
 * Student ID: 1031686
 * Os: Mac OS
 *
 */

#include <iostream>
#include <random>

using namespace std;

// Declaration of classes

#include "SystemController.h"
#include "TrafficGenerator.h"
#include "Passenger.h"
#include "Visitors.h"
#include "RandomGenerator.h"
#include "DateTime.h"


using namespace std;

int main() {
    std::cout << " Main File " << endl;

    // File Path to read the input Path
    std::string path = "/Users/soumilshah/CLionProjects/ElevatorEmulator/input.txt";

    TrafficGenerator *generator;
    generator = new TrafficGenerator(path);

    generator->generateTraffic();
    generator->generateTraffic();

    generator->populateElevator();


    delete generator;


    return 0;
}