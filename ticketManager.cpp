/**
 * @file ticketManager.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the cpp-file for the ticket manager class which manage the
 * tickets.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
#include "ticketManager.hh"

/**
 * @brief This is the constructor for the TicketManager class.
 * 
 * @param [in] flightList - A pointer to a Flights object.
 * @param [in] bookingList - A pointer to a Bookings object.
 */
TicketManager::TicketManager(Flights *flightList, Bookings *bookingList)
{
    int ticketAmount = 0;
    for (auto bp : bookingList->getBookings())
    {
        int foundMatch = 0;
        for (auto fp : flightList->getFlights())
        {
            if (fp->matchWithBooking(bp))
            {
                int row = 0, seat = 0;
				// Try to allocate a seat.
                if (fp->allocateSeat(bp, &row, &seat))
                {
					// If successful, create a ticket and flag that we got a match.
                    // TODO: Uncomment so we actually create tickets..
                    //this->createTicket(fp, bp, row, seat);
                    foundMatch = 1;
                    ticketAmount++;
                }
                else
                {	// If unsuccessful, print an error message.
					std::cerr << "Error! Could not find a seat in " << bp->getSClass() << " class for booking #" << bp->getBNum() << "\n";
				}
				break; // Break out of the flights-list loop when we find a match with a booking.
            }
        }
        if (!foundMatch)
        {
			// If we reach this part, there is no matching flight for the current booking.
			std::cerr << "Error! Could not find a matching flight for booking #" << bp->getBNum() << "\n";
        }
    }
    std::cout << "\nCreated " << ticketAmount << " tickets.\n";
}

/**
 * @brief This is a private function used by the constructor to create tickets.
 * 
 * @param [in] flight - A pointer to a Flight object.
 * @param [in] booking - A pointer to a Booking object.
 * @param [in] row - An integer representing what row is booked.
 * @param [in] seat - An integer representing what seat is booked.
 */
void TicketManager::createTicket(Flight *flight, Booking *booking, int row, int seat)
{
    /*
    TODO: Consider whether or not to create a ticket class, with just the data + eventual filename, and an overloaded <<-operator.
            It would make for prettier code, but it does feel wasteful to create objects that will only be used for printing.
    */
    std::string filename = "ticket-" + std::to_string(booking->getBNum()) + ".txt";
    std::ofstream outFile(filename);
    if (outFile)
    {
        outFile << "BOOKING: " << booking->getBNum() << "\n" <<
                   "FLIGHT: " << flight->getFlNum() << " DEPARTURE: " << flight->getDep() << " DESTINATION: " <<
                                 flight->getDes() << " " << flight->getDate() << " " << flight->getTime() << "\n" <<
                   "PASSENGER " << booking->getFName() << " " << booking->getSurname() << "\n"
                   "CLASS: " << booking->getSClass() << "\n" <<
                   "ROW " << row << " SEAT " << seat << "\n";
        outFile.close();
        std::cout << "[" << filename << "] ";
    }
    else
    {
        std::cerr << "Error! Could not create ticket with bookingnumber " << booking->getBNum() << "\n";
    }
}
