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

#ifndef BOOKING_CLASS
#define BOOKING_CLASS

class booking
{
private:
    int bNum;
	std::string date;
	std::string time;
	std::string dep;
	std::string des;
	std::string sClass;
	std::string fName;
	std::string surname;
public:
    booking();
    booking(int bNum, std::string date, std::string time, std::string dep,
            std::string des, std::string sClass, std::string fName,
            std::string surname);
    ~booking();
};

#endif
