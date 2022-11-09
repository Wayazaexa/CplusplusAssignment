/**
 * @file tickets.cpp
 * @author Joakim Englund (joakimenglund@protonmail.com)
 * @brief This is the main cpp-file for the tickets system.
 * @version 0.1
 * @date 2022-11-09
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "flights.hh"

int main(int argc, char **argv)
{
    std::cout << "Ticket system!\n--------------\n";
    flight *test1 = new flight(304, "GOT", "CPH", "2022-10-27", "06:30", 4, 7, 10);
    flight *test2 = new flight(304, "GOT", "CPH", "2022-10-27", "07:30", 4, 7, 10);
    flight *test3 = new flight(304, "GOT", "CPH", "2022-10-27", "08:30", 4, 7, 10);
    //flights *testList = new flights();
    //testList->addFlight(*test1);
    //testList->addFlight(*test2);
    //testList->addFlight(*test3);
    test1->print();
    std::cout << "\n";
    test2->print();
    std::cout << "\n";
    test3->print();
    std::cout << "\n";
    delete test1;
    delete test2;
    delete test3;
    //delete testList;
    return 0;
}
