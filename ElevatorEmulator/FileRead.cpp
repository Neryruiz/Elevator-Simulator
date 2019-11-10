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

#include "FileRead.h"



FileRead::FileRead()
{
    // cout << "FileRead Constroller Constructor" << endl;
}

FileRead::~FileRead()
{
    // cout << " FileRead Destructor " << endl;
}

void FileRead::readFile(std::string path)
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