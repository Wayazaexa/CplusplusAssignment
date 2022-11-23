/**
 * @file flight.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the flight class which contains data about a
 * single flight.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include <vector>
#include "booking.hh"

#ifndef FLIGHT_CLASS
#define FLIGHT_CLASS

/**
 * @brief This is the definition of the Flight class.
 * 
 */
class Flight
{
private:
    int flNum;
    std::string dep;
    std::string des;
    std::string date;
    std::string time;
    int fRows;
    std::vector<u_int8_t> fSeatFlags;
    int bRows;
    std::vector<u_int8_t> bSeatFlags;
    int eRows;
    std::vector<u_int8_t> eSeatFlags;
public:
    Flight(int flNum, std::string dep, std::string des, std::string date,
           std::string time, int fRows, int bRows, int eRows);
    ~Flight() {}
    int getFlNum() { return this->flNum; }
    std::string getDep() { return this->dep; }
    std::string getDes() { return this->des; }
    std::string getDate() { return this->date; }
    std::string getTime() { return this->time; }
    int getFRows() { return this->fRows; }
    std::vector<u_int8_t> getFSeatFlags() { return this->fSeatFlags; }
    int getBRows() { return this->bRows; }
    std::vector<u_int8_t> getBSeatFlags() { return this->bSeatFlags; }
    int getERows() { return this->eRows; }
    std::vector<u_int8_t> getESeatFlags() { return this->eSeatFlags; }

    bool matchWithBooking(Booking *booking);
    bool allocateSeat(Booking *booking, int *row, int *seat);
};

#endif
