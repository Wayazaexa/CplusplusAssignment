/**
 * @file booking.hh
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the hh-file for the booking class which contains data about a
 * single booking.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <string>
#include "tripInfo.hh"

#ifndef BOOKING_CLASS
#define BOOKING_CLASS

/**
 * @brief This is the definition of the Booking class.
 * 
 */
class Booking : public TripInfo
{
private:
    int bNum;
	std::string sClass;
	std::string fName;
	std::string surname;
public:
    Booking(int bNum, std::string date, std::string time, std::string dep,
            std::string des, std::string sClass, std::string fName,
            std::string surname);
    ~Booking() {}
	int getBNum() { return this->bNum; }
	std::string getSClass() { return this->sClass; }
	std::string getFName() { return this->fName; }
	std::string getSurname() { return this->surname; }
};

#endif
