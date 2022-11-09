/**
 * @file flights.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the flights class which contains a list of
 * all flights.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <list>
#include "flight.hh"

#ifndef FLIGTHS_CLASS
#define FLIGHTS_CLASS

class flights
{
private:
    std::list<flight> flightList;
public:
    flights();
    ~flights();
    std::list<flight> getFlights() { return this->flightList; }
    void addFlight(const flight &newFlight);
};

#endif
