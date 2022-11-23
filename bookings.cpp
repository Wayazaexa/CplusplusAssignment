/**
 * @file bookings.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the cpp-file for the bookings class which manage the bookings.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <fstream>
#include <sstream>
#include "bookings.hh"

/**
 * @brief This is the constructor for the Bookings class.
 * 
 * @param [in] filename - A string containing a filename to read the data for
 *                        the Booking objects from.
 */
Bookings::Bookings(std::string filename)
{
    std::ifstream inFile(filename);
    std::string line;
    std::string bNum;
	std::string date;
	std::string time;
	std::string dep;
	std::string des;
	std::string sClass;
	std::string fName;
	std::string surname;

    if (inFile.is_open())
    {
        while (getline(inFile, line))
        {
            std::stringstream ss(line);

            getline(ss, bNum, ',');
            getline(ss, date, ',');
            getline(ss, time, ',');
            getline(ss, dep, ',');
            getline(ss, des, ',');
            getline(ss, sClass, ',');
            getline(ss, fName, ',');
            getline(ss, surname);
            Booking *newBooking = new Booking(std::stoi(bNum), date, time, dep, des, sClass, fName, surname);
            this->addBooking(newBooking);
        }
        inFile.close();
    }
}

/**
 * @brief This is the destructor for the Bookings class.
 * Since the class contains a list of pointers to Booking objects, these need
 * to be deleted properly here (because I didn't use smart pointers).
 * 
 */
Bookings::~Bookings()
{
    // TODO: I really should use smart pointers instead so I don't have to do this.
    while (!this->bookingsList.empty())
    {
        delete this->bookingsList.front();
        this->bookingsList.pop_front();
    }
}
