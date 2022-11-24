/**
 * @file booking.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the cpp-file for the booking class which contains data about a
 * single booking.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "booking.hh"

/**
 * @brief This is the constructor for the Booking class.
 * 
 * @param [in] bNum - An int representing a booking number.
 * @param [in] date - A string representing a date.
 * @param [in] time - A string representing a time.
 * @param [in] dep - A string representing a departure location.
 * @param [in] des - A string representing a destination location.
 * @param [in] sClass - A string representing a seating class.
 * @param [in] fName - A string representing a first name.
 * @param [in] surname - A string representing a surname.
 */
Booking::Booking(int bNum, std::string date, std::string time, std::string dep,
            std::string des, std::string sClass, std::string fName,
            std::string surname)
{
    this->bNum = bNum;
    this->setDate(date);
    this->setTime(time);
    this->setDep(dep);
    this->setDes(des);
    this->sClass = sClass;
    this->fName = fName;
    this->surname = surname;
}
