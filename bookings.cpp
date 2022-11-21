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
#include <iostream>
#include <fstream>
#include <sstream>
#include "bookings.hh"


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

Bookings::~Bookings()
{
    // TODO: I really should use smart pointers instead so I don't have to do this.
    while (!this->bookingList.empty())
    {
        delete this->bookingList.front();
        this->bookingList.pop_front();
    }
}

void Bookings::addBooking(Booking *newBooking)
{
    this->bookingList.push_back(newBooking);
}
