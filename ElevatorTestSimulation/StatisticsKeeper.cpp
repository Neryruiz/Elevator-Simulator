#include <iostream>
#include <string>


#include "StatisticsKeeper.h"

int StatisticsKeeper::totalPassengerCreatedInBatchSize = 0;


StatisticsKeeper::StatisticsKeeper()
{
    totalPassengerCreatedInBatchSize ++;
}

StatisticsKeeper::~StatisticsKeeper()
{
    totalPassengerCreatedInBatchSize -- ;
}