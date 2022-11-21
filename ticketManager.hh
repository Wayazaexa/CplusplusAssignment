/**
 * @file ticketManager.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the ticketManager class which manage the
 * tickets.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "flights.hh"
#include "bookings.hh"

#ifndef TICKET_MANAGER_CLASS
#define TICKET_MANAGER_CLASS

class TicketManager
{
private:
    void createTicket(Flight *flight, Booking *booking, int row, int seat);
public:
    TicketManager(Flights *flightList, Bookings *bookingList);
    ~TicketManager() {}
};

#endif
