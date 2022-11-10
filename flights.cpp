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
#include "flights.hh"

flights::flights(std::string filename)
{
    std::ifstream inFile(filename);
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
        while (!inFile.eof())
        {
            if (getline(inFile, flNum, ','))
            {
                getline(inFile, dep, ',');
                getline(inFile, des, ',');
                getline(inFile, date, ',');
                getline(inFile, time, ',');
                getline(inFile, fRows, ',');
                getline(inFile, bRows, ',');
                getline(inFile, eRows);
                flight *newFlight = new flight(std::stoi(flNum), dep, des, date, time, std::stoi(fRows), std::stoi(bRows), std::stoi(eRows));
                this->addFlight(newFlight);
            }
        }
        inFile.close();
    }
}

flights::~flights()
{
    while (!this->flightList.empty())
    {
        delete this->flightList.front();
        this->flightList.pop_front();
    }
}

void flights::addFlight(flight *newFlight)
{
    this->flightList.push_back(newFlight);
}
