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
#include <list>
#include <stdint.h>
// TODO: For testing.
#include <iostream>

#ifndef FLIGHT_CLASS
#define FLIGHT_CLASS

class flight
{
private:
    int flNum;
    std::string dep;
    std::string des;
    std::string date;
    std::string time;
    int fRows;
    std::list<u_int8_t> fSeatFlags;
    int bRows;
    std::list<u_int8_t> bSeatFlags;
    int eRows;
    std::list<u_int8_t> eSeatFlags;
public:
    flight();
    flight(int flNum, std::string dep, std::string des, std::string date,
           std::string time, int fRows, int bRows, int eRows);
    ~flight();
    int getFlNum() { return this->flNum; }
    void setFlNum(int flNum) { this->flNum = flNum; }
    std::string getDep() { return this->dep; }
    void setDep(std::string dep) { this->dep.assign(dep); }
    std::string getDes() { return this->des; }
    void setDes(std::string des) { this->des.assign(des); }
    std::string getDate() { return this->date; }
    void setDate(std::string date) { this->date.assign(date); }
    std::string getTime() { return this->time; }
    void setTime(std::string time) { this->time.assign(time); }
    int getFRows() { return this->fRows; }
    void setFRows(int fRows) { this->fRows = fRows; }
    int getBRows() { return this->bRows; }
    void setBRows(int bRows) { this->bRows = bRows; }
    int getERows() { return this->eRows; }
    void setERows(int eRows) { this->eRows = eRows; }

    // TODO: For testing
    void print() { std::cout << "Flight: \nflNum: " << this->flNum << 
    "\n    dep: " << this->dep << "    des: " << this->des << "    date: " <<
    this->date << "    time: " << this->time << "\n    fRows: " <<
    this->fRows << "    bRows: " << this->bRows << "    eRows: " <<
    this->eRows << "\n"; }
};

#endif
