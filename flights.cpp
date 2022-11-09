/**
 * @file flights.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the cpp-file for the flights class which contains a list of
 * all flights.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "flights.hh"

flights::flights()
{
}

flights::~flights()
{
    this->flightList.clear();
}

void flights::addFlight(const flight &newFlight)
{
    this->flightList.push_back(newFlight);
}
