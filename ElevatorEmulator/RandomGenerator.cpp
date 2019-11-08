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

#include "RandomGenerator.h"



RandomGenerator::RandomGenerator()
{
    cout  << "Random Generator" << endl;
}

RandomGenerator::~RandomGenerator()
{
    cout << "Destructor called " << endl;
}

int RandomGenerator::generateRandomNumber(int low, int high)
{
    srand(time(0));
    int num = rand() % high;
    return num;
}
