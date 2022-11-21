/**
 * @file bookings.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the bookings class which manage the bookings.
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

class Bookings
{
private:
    std::list<Booking *> bookingList;
public:
    Bookings(std::string filename);
    ~Bookings();
    std::list<Booking *> getBookings() { return this->bookingList; }
    void addBooking(Booking *newBooking);
};

#endif
