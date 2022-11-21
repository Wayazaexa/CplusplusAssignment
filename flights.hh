/**
 * @file flights.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the flights class which manages the flights.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <list>
#include "flight.hh"

#ifndef FLIGTHS_CLASS
#define FLIGTHS_CLASS

// Added the start of managing cancelled flights. Will add properly if I have the time.
class Flights
{
private:
    std::list<Flight *> flights;
    //std::list<Flight *> cancelledFlights; 
public:
    Flights(std::string filename);
    ~Flights();
    std::list<Flight *> getFlights() { return this->flights; }
    //std::list<Flight *> getCancelledFlights() { return this->cancelledFlights; }
    void addFlight(Flight *newFlight) { this->flights.push_back(newFlight); }
    //void addCancelledFlight(Flight *newFlight) { this->cancelledFlights.push_back(newFlight); }
    //void cancelFlightFront() { this->cancelledFlights.push_back(this->flights.front()); this->flights.pop_front(); }
};

#endif
