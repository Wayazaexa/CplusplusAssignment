/**
 * @file flight.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the cpp-file for the flight class which contains data about a
 * single flight.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "flight.hh"

flight::flight()
{
    this->flNum = 0;
    this->dep = "";
    this->des = "";
    this->date = "";
    this->time = "";
    this->fRows = 0;
    this->bRows = 0;
    this->eRows = 0;
}

flight::flight(int flNum, std::string dep, std::string des, std::string date,
               std::string time, int fRows, int bRows, int eRows)
{
    this->flNum = flNum;
    this->dep.assign(dep);
    this->des.assign(des);
    this->date.assign(date);
    this->time.assign(time);
    this->fRows = fRows;
    for (int i = 0; i < this->fRows * 7; i++)
    {
        this->fSeatFlags.push_back(0);
    }
    this->bRows = bRows;
    for (int i = 0; i < this->bRows * 7; i++)
    {
        this->bSeatFlags.push_back(0);
    }
    this->eRows = eRows;
    for (int i = 0; i < this->eRows * 7; i++)
    {
        this->eSeatFlags.push_back(0);
    }
}

flight::~flight()
{
    this->fSeatFlags.clear();
    this->bSeatFlags.clear();
    this->eSeatFlags.clear();
}
