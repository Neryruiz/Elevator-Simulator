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

#include "SystemController.h"




SystemController::SystemController()
{
    cout << "System Constroller Constructor" << endl;
}

SystemController::~SystemController()
{
    cout << "Destructor " << endl;
}

void SystemController::readFile(std::string path)
{

    std::ifstream in_file (path);
    std::stringstream ss(line);


    // Stores the Data in Data Structure
    while (std::getline(in_file, line))
    {
        // cout << "="<<line<<"="<< endl;
        std::stringstream ss(line);
        // cout << "length" << line.size()<< endl;

            while  (ss >> result)
            {

                // cout << "*"<<result<<"*"<< endl;
                Data[counter].push_back(result);
            }


        // cout << "\n";
        counter = counter + 1;
    }
}