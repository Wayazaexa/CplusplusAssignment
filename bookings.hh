/**
 * @file bookings.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the bookings class which contains a list of
 * all bookings.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <list>
#include "booking.hh"

#ifndef BOOKINGS_CLASS
#define BOOKINGS_CLASS

class bookings
{
private:
    std::list<booking> bookingsList;
public:
    bookings(/* args */);
    ~bookings();
};

#endif
