/**
 * @file tickets.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the main cpp-file for the tickets system.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <iterator>
#include "flights.hh"
#include "bookings.hh"

int main(int argc, char **argv)
{
    std::cout << "Ticket system!\n--------------\n";
    // TODO: set to read from the big files, later on set to read from argv[1] and argv[2].
    flights *flightList = new flights("flightsTest.csv");
    bookings *bookingList = new bookings("bookingsTest.csv");
    

    delete flightList;
    delete bookingList;
    return 0;
}
