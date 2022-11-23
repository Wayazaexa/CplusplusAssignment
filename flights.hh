/**
 * @file flightsList.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the flightsList class which manages the flightsList.
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

/**
 * @brief This is the definition of the Flights class.
 * 
 */
class Flights
{
private:
    std::list<Flight *> flightsList;
public:
    Flights() {}
    Flights(std::string filename);
    ~Flights();
    std::list<Flight *> getFlights() { return this->flightsList; }
    void addFlight(Flight *newFlight) { this->flightsList.push_back(newFlight); }
    void cancelFlights(Flights *cancelledFlights, std::string filename);
    void createSeatingMap(std::string filename);
    // Add a function here to remove an object and return it, needed for cancelling flights.
};

#endif
