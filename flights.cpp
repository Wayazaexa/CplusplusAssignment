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

flights::flights(std::string filename)
{
    std::ifstream ss(filename);
    std::string line;
    std::string flNum;
    std::string dep;
    std::string des;
    std::string date;
    std::string time;
    std::string fRows;
    std::string bRows;
    std::string eRows;

    if (ss.is_open())
    {
        while (getline(ss, line))
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
            flight *newFlight = new flight(std::stoi(flNum), dep, des, date, time, std::stoi(fRows), std::stoi(bRows), std::stoi(eRows));
            this->addFlight(newFlight);
        }
        ss.close();
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
