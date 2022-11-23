/**
 * @file flights.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the cpp-file for the flights class which manage the flights.
 * @version 0.1
 * @date 2022-11-09
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include "flights.hh"

/**
 * @brief This is the constructor for the Flights class.
 *
 * @param [in] filename - A string containing a filename.
 */
Flights::Flights(std::string filename)
{
    std::ifstream inFile(filename);
    std::string line;
    std::string flNum;
    std::string dep;
    std::string des;
    std::string date;
    std::string time;
    std::string fRows;
    std::string bRows;
    std::string eRows;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            std::stringstream ss(line);

            getline(ss, flNum, ',');
            getline(ss, dep, ',');
            getline(ss, des, ',');
            getline(ss, date, ',');
            getline(ss, time, ',');
            getline(ss, fRows, ',');
            getline(ss, bRows, ',');
            getline(ss, eRows);
            Flight *newFlight = new Flight(std::stoi(flNum), dep, des, date, time, std::stoi(fRows), std::stoi(bRows), std::stoi(eRows));
            this->addFlight(newFlight);
        }
        inFile.close();
    }
}

/**
 * @brief This function goes through the list of flights for this object, finds
 * nodes that indicate that a flight isn't booked, and puts them in the Flights
 * object it got a pointer to as in-parameter.
 *
 * @param [inout] cancelledFlights - A pointer to a Flights object.
 * @param [in] filename - A string containing a filename.
 */
void Flights::cancelFlights(Flights *cancelledFlights, std::string filename)
{
    for (auto fp : this->flightsList)
    {
        bool isFlightBooked = false;
        int fSeats = fp->getFRows() * 7;

        for (int i = 0; i < fSeats; i++)
        {
            if (fp->getFSeatFlags()[i] == 1)
            {
                isFlightBooked = true;
                break;
            }
        }

        // Just so that we don't do unneccessary work if we already found a booked seat.
        if (!isFlightBooked)
        {
            int bSeats = fp->getBRows() * 7;

            for (int i = 0; i < bSeats; i++)
            {
                if (fp->getBSeatFlags()[i] == 1)
                {
                    isFlightBooked = true;
                    break;
                }
            }

            // Just so that we don't do unneccessary work if we already found a booked seat.
            if (!isFlightBooked)
            {
                int eSeats = fp->getERows() * 7;

                for (int i = 0; i < eSeats; i++)
                {
                    if (fp->getESeatFlags()[i] == 1)
                    {
                        isFlightBooked = true;
                        break;
                    }
                }
            }
        }

        if (!isFlightBooked)
        {
            cancelledFlights->addFlight(fp);
        }
    }

    int counter = 0;
    std::ofstream outFile(filename);
    outFile << "The following flights have no passengers booked and are now cancelled:\n\n";
    outFile.close();

    for (auto cFlight : cancelledFlights->getFlights())
    {
        counter++;
        std::ofstream outFile(filename, std::ios_base::app);

        if (outFile)
        {
            outFile << counter << ") Flight " << cFlight->getFlNum() << ", Departure " << cFlight->getDep() << ", Destination " << cFlight->getDes() << ", Date " << cFlight->getDate() << ", Time " << cFlight->getTime() << "\n";
            outFile.close();
        }
        else
        {
            std::cerr << "Error! Could not open the file containing cancelled flights!\n";
        }

        this->flightsList.remove(cFlight);
    }
    if (counter)
    {
        std::cout << "Cancelled " << counter << " flights as no bookings were found for them.\n";
    }
}

/**
 * @brief This function creates a file containing a seating-map for every
 * flight that has passengers.
 * 
 * @param [in] filename - A string containing a filename.
 * 
 */
void Flights::createSeatingMap(std::string filename)
{
    std::ofstream outFile(filename);

    if (outFile)
    {
        std::cout << "Creating seatmap.\n";
        for (auto fp : this->flightsList)
        {
            //std::cout << "Flight " << fp->getFlNum() << ", Departure " << fp->getDep() << ", Destination " << fp->getDes() << "\n";
            outFile << "Flight " << fp->getFlNum() << ", Departure " << fp->getDep() << ", Destination " << fp->getDes() <<
                       ", Date " << fp->getDate() << ", Time " << fp->getTime() << "\nfirst class\n";
            int offset;
            for (int i = 0; i < fp->getFRows(); i++)
            {
                
                offset = i * 7;
                outFile << "[" << (int)fp->getFSeatFlags()[offset] << "][" << (int)fp->getFSeatFlags()[offset + 1] << "] [" << (int)fp->getFSeatFlags()[offset + 2] << 
                           "][" << (int)fp->getFSeatFlags()[offset + 3] << "][" << (int)fp->getFSeatFlags()[offset + 4] << "] [" << (int)fp->getFSeatFlags()[offset + 5] << 
                           "][" << (int)fp->getFSeatFlags()[offset + 6] << "]\n";
                
            }
            outFile << "business class\n";
            for (int i = 0; i < fp->getBRows(); i++)
            {
                
                offset = i * 7;
                outFile << "[" << (int)fp->getBSeatFlags()[offset] << "][" << (int)fp->getBSeatFlags()[offset + 1] << "] [" << (int)fp->getBSeatFlags()[offset + 2] << 
                           "][" << (int)fp->getBSeatFlags()[offset + 3] << "][" << (int)fp->getBSeatFlags()[offset + 4] << "] [" << (int)fp->getBSeatFlags()[offset + 5] << 
                           "][" << (int)fp->getBSeatFlags()[offset + 6] << "]\n";
                           
            }
            outFile << "ecomony class\n";
            for (int i = 0; i < fp->getERows(); i++)
            {
                
                offset = i * 7;
                outFile << "[" << (int)fp->getESeatFlags()[offset] << "][" << (int)fp->getESeatFlags()[offset + 1] << "] [" << (int)fp->getESeatFlags()[offset + 2] << 
                           "][" << (int)fp->getESeatFlags()[offset + 3] << "][" << (int)fp->getESeatFlags()[offset + 4] << "] [" << (int)fp->getESeatFlags()[offset + 5] << 
                           "][" << (int)fp->getESeatFlags()[offset + 6] << "]\n";
                           
            }
            outFile << "\n";
        }
        outFile.close();
    }
    else
    {
        std::cerr << "Error! Could not create the seat mapping file.";
    }
}

/**
 * @brief This is the destructor for the Flights class.
 * Since the class contains a list of pointers to Flight objects, these need
 * to be deleted properly here (because I didn't use smart pointers).
 *
 */
Flights::~Flights()
{
    // TODO: I really should use smart pointers instead so I don't have to do this.
    while (!this->flightsList.empty())
    {
        delete this->flightsList.front();
        this->flightsList.pop_front();
    }
}
