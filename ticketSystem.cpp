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

/**
 * @brief This is the entry point for the Ticket System.
 *
 * @param [in] argc - A integer representing the number of arguments passed
 *                    to the program.
 * @param [in] argv - An array of C-strings containing the argements passed
 *                    to the program.
 * @return int - returns 0 on successful run, -1 otherwise.
 */
int main(int argc, char **argv)
{
    if (argc < 4)
    {
        std::cerr << "Error! Must provide files to read data from!\n"
                  << "Example: ./ticketSystem.o -f flights.csv -b bookings.csv\n"
                  << "To save reports, use the -c and -s flags:\n"
                  << "./ticketSystem.o -f flights.csv -b bookings.csv -c cancelled-flights.txt -s seating-map.txt\n";
        return -1;
    }
    else
    {
        Flights *flightList = NULL;
        Flights *cancelledFlights = NULL;
        Bookings *bookingList = NULL;
        int opt;
        std::string cancelledFilename = "";
        std::string sMapFilename = "";
        std::cout << "Ticket system!\n--------------\n";

        while ((opt = getopt(argc, argv, "f:b:c:s:")) != -1)
        {
            switch (opt)
            {
            case 'f':
                flightList = new Flights(optarg);
                break;
            case 'b':
                bookingList = new Bookings(optarg);
                break;
            case 'c':
                cancelledFilename = optarg;
                break;
            case 's':
                sMapFilename = optarg;
                break;
            default:
                std::cerr << "Unrecognized flag [" << (char)opt << "]! This flag will be ignored!\n";
                break;
            }
        }

        if (flightList && bookingList)
        {
            std::cout << "Generating tickets!\n";
            TicketManager(flightList, bookingList);
            cancelledFlights = new Flights();

            if (!cancelledFilename.empty())
            {
                flightList->cancelFlights(cancelledFlights, cancelledFilename);
            }

            if (!sMapFilename.empty())
            {
                flightList->createSeatingMap(sMapFilename);
            }
        }
        else
        {
            std::cerr << "Error! Flights or bookings were not processed correctly!\n";
        }

        delete flightList;
        delete bookingList;
    }
    return 0;
}
