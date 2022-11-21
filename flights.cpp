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

Flights::~Flights()
{
    // TODO: I really should use smart pointers instead so I don't have to do this.
    while (!this->flights.empty())
    {
        delete this->flights.front();
        this->flights.pop_front();
    }
    /*
    while (!this->cancelledFlights.empty())
    {
        delete this->cancelledFlights.front();
        this->cancelledFlights.pop_front();
    }
    */
}
