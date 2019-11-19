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
#import <algorithm>
#import <chrono>


using namespace std;

#include "RandomGenerator.h"
#include "StringHelper.h"



RandomGenerator::RandomGenerator()
{
    cout  << "Random Generator" << endl;
}

RandomGenerator::~RandomGenerator()
{
    cout << "Destructor called " << endl;
}

int RandomGenerator::generateRandomNumber(int low, int high){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(low,high);
    return dist6(rng);
}

char RandomGenerator::generatCall(vector<std::string> &rates)
{


    for (auto x: rates){
        cout << x << endl;
    }
    cout << "SIZE  "<< rates.size() << endl;


//    vector<char> Spawnrange;
//    cout << "RATES "<< rates.size() << endl;
//
//    for(int i =1; i <rates.size(); i++)
//    {
//
//        for(int j=0; j<StringHelper::string_to_int(rates.at(i)); j ++)
//        {
//            if(i == 1)
//            {
//                Spawnrange.push_back('R');
//            } else if (i==2)
//            {
//                Spawnrange.push_back('P');
//            } else if (i == 3)
//            {
//                Spawnrange.push_back('E');
//            } else
//                {
//                    cout << "Something Went Wrong " << endl;
//                }
//
//        }
//        unsigned  seed = chrono::system_clock::now().time_since_epoch().count();
//        shuffle(Spawnrange.begin(), Spawnrange.end(), default_random_engine(seed));
//
//        cout << "SIZE" << Spawnrange.size() << endl;
//
//
//        return Spawnrange.at(RandomGenerator::generateRandomNumber(0,99));

    return 'C';




}
