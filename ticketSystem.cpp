/**
 * @file ticketSystem.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the main cpp-file for the tickets system.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <unistd.h>
#include "ticketManager.hh"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Error! Must provide files to read data from!\n" <<
                     "Example: ./ticketSystem -f flights.csv -b bookings.csv\n";
        return -1;
    }
    else
    {
        int opt;
        Flights *flightList = NULL;
        Bookings *bookingList = NULL;
        std::cout << "Ticket system!\n--------------\n";

        while ((opt = getopt(argc, argv, "f:b:")) != -1)
        {
            switch (opt)
            {
            case 'f':
                flightList = new Flights(optarg);
                break;
            case 'b':
                bookingList = new Bookings(optarg);
            default:
                std::cerr << "Unrecognized flag [" << opt << "]!\n";
                break;
            }
        }

        TicketManager(flightList, bookingList);

        delete flightList;
        delete bookingList;
    }
    return 0;
}
