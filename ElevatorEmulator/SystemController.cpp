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
        std::stringstream ss(line);

        while  (ss >> result)
        {
            Data[counter].push_back(result);
        }
        counter = counter + 1;
    }
}