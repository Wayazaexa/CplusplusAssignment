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

/**
 * @brief This is the constructor for the Flight class.
 * 
 * @param [in] flNum - An int representing a flight number.
 * @param [in] dep - A string representing a departure location.
 * @param [in] des - A string representing a destination location.
 * @param [in] date - A string representing a date.
 * @param [in] time - A string representing a time.
 * @param [in] fRows - An int representing the number of first class rows.
 * @param [in] bRows - An int representing the number of business class rows.
 * @param [in] eRows - An int representing the number of economy class rows.
 */
Flight::Flight(int flNum, std::string dep, std::string des, std::string date,
               std::string time, int fRows, int bRows, int eRows)
{
    this->flNum = flNum;
    this->dep = dep;
    this->des = des;
    this->date = date;
    this->time = time;
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

/**
 * @brief This function takes a pointer to a Booking object and compares the
 *        date, time, departure, and destination with the Flight object, and
 *        returns true if they all match and false if they don't match.
 * 
 * @param [in] booking - A pointer to a Booking object.
 * @return true if the Booking object matches with this Flight object.
 * @return false if the Booking object doesn't match with this Flight object.
 */
bool Flight::matchWithBooking(Booking *booking)
{
    return !(this->date.compare(booking->getDate()) || this->time.compare(booking->getTime()) ||
           this->dep.compare(booking->getDep()) || this->des.compare(booking->getDes()));
}

/**
 * @brief This function tries to allocate a seat for the Booking object on this
 *        Flight object, and returns true if it's successful and false if not.
 * 
 * @param [in] booking - A pointer to a Booking object.
 * @param [inout] row - A reference to an int representing the booked row.
 * @param [inout] seat - A reference to an int representing the booked seat.
 * @return true if a seat was successfully allocated.
 * @return false if a seat wasn't successfully allocated.
 */
bool Flight::allocateSeat(Booking *booking, int *row, int *seat)
{
    if (!booking->getSClass().compare("first"))
    {
		// Try to allocate a seat in first class
        for (int i = 0; i < this->fSeatFlags.size(); i++)
        {
            if (this->fSeatFlags[i] == 0)
            {
                this->fSeatFlags[i] = 1;
                *row = (int)(i / 7) + 1;
                *seat = i + 1;
                return true;
            }
        }
    }
    else if (!booking->getSClass().compare("business"))
    {
		// Try to allocate a seat in business class
        for (int i = 0; i < this->bSeatFlags.size(); i++)
        {
            if (this->bSeatFlags[i] == 0)
            {
                this->bSeatFlags[i] = 1;
				*row = this->fRows + (int)(i / 7) + 1;
				*seat = this->fRows * 7 + i + 1;
                return true;
            }
        }
    }
    else
    {
		// Try to allocate a seat in economy class
        for (int i = 0; i < this->eSeatFlags.size(); i++)
        {
            if (this->eSeatFlags[i] == 0)
            {
                this->eSeatFlags[i] = 1;
				*row = this->bRows + this->fRows + (int)(i / 7) + 1;
				*seat = this->bRows * 7 + this->fRows * 7 + i + 1;
                return true;
            }
        }
    }
    return false;
}
