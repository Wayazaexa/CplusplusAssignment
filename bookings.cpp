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
#include "bookings.hh"


bookings::bookings(std::string filename)
{
    std::ifstream inFile(filename);
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
        while (!inFile.eof())
        {
            if (getline(inFile, bNum, ','))
            {
                getline(inFile, date, ',');
                getline(inFile, time, ',');
                getline(inFile, dep, ',');
                getline(inFile, des, ',');
                getline(inFile, sClass, ',');
                getline(inFile, fName, ',');
                getline(inFile, surname);
                booking *newBooking = new booking(std::stoi(bNum), date, time, dep, des, sClass, fName, surname);
                this->addBooking(newBooking);
            }
        }
        inFile.close();
    }
}

bookings::~bookings()
{
    while (!this->bookingsList.empty())
    {
        delete this->bookingsList.front();
        this->bookingsList.pop_front();
    }
}

void bookings::addBooking(booking *newBooking)
{
    this->bookingsList.push_back(newBooking);
}
