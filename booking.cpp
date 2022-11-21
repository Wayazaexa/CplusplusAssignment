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

Booking::Booking(int bNum, std::string date, std::string time, std::string dep,
            std::string des, std::string sClass, std::string fName,
            std::string surname)
{
    this->bNum = bNum;
    this->date.assign(date);
    this->time.assign(time);
    this->dep.assign(dep);
    this->des.assign(des);
    this->sClass.assign(sClass);
    this->fName.assign(fName);
    this->surname.assign(surname);
}
