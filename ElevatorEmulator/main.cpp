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


using namespace std;

// Declaration of classes
#include "Passenger.h"
#include "Visitors.h"
#include "Patients.h"
#include "SupportStaff.h"
#include "SecurityPersonnel.h"
#include "MedicalStaff.h"


using namespace std;

int main() {
    std::cout << " Main File " << endl;

    std::string path = "/Users/soumilshah/CLionProjects/ElevatorEmulator/input.txt";
    std::string line;
    string result {};
    int counter = 1;

    std::ifstream in_file (path);
    std::stringstream ss(line);

    // Data Structure
    map<int, vector<std::string>> Data;

    // Stores the Data in Data Structure
    while (std::getline(in_file, line))
    {
        std::stringstream ss(line);

        while  (ss >> result)
        {
            Data[counter].push_back(result);
        }
        counter = counter + 1;
    }

    cout << Data[3].size() << endl;
    cout << "============" << endl;
    for(auto x: Data[3])
    {
        cout << x << endl;
    }

//
//    Passenger *Passenger[16];
//    Passenger[0] = new Visitors();
//    Passenger[1] = new Patients();
//    Passenger[2] = new SupportStaff();
//    Passenger[3] = new SecurityPersonnel();
//    Passenger[4] = new MedicalStaff();
//    Passenger[5] = new MedicalStaff();
//
//    cout << "\n";
//    cout << "\n";
//
//    for (int i = 0; i < 6; i++)
//    {   cout << "==================================================" << endl;
//        Passenger[i]->introduce(); // polymorphic method displays id
//        cout << "\n";
//    }
//
//    for (int i = 0; i < 6; i++)
//    {
//        delete Passenger[i];
//    }


    return 0;
}