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

/**
 * @brief This is the definition of the Bookings class.
 * 
 */
class Bookings
{
private:
    std::list<Booking *> bookingsList;
public:
    Bookings(std::string filename);
    ~Bookings();
    std::list<Booking *> getBookings() { return this->bookingsList; }
    void addBooking(Booking *newBooking) { this->bookingsList.push_back(newBooking); }
};

#endif
