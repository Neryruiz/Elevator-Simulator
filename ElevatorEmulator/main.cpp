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
using namespace std;

int main() {
    std::cout << " Main File " << endl;

    // File Path to read the input Path
    std::string path = "/Users/soumilshah/CLionProjects/ElevatorEmulator/input.txt";

    TrafficGenerator *generator;
    generator = new TrafficGenerator(path);

    generator->generateTraffic();

//
//    for (int i=0; i<8;i++)
//    {
//        std::random_device dev;
//        std::mt19937 rng(dev());
//        std::uniform_int_distribution<std::mt19937::result_type> dist6(0,6); // distribution in range [0, 6]
//
//        cout << "Random : " << dist6(rng) << endl;
//    }


    delete generator;


    return 0;
}