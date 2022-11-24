# C++ assignment/hand-in

In the assignment (and repository) '4a-files', we were tasked with making a ticket creating system in C.
This assignment consists of remaking that system in C++.

Running 'make' on this code will generate the executable file ticketSystem.
The program takes two parameters; a database of flights and a database of bookings, both in csv-type of files.
The program also have two optional parameters; the name of two text files that will store additional output
from the program, a seating map and a list of cancelled flights.

Example usage: ./ticketSystem -f flights.csv -b bookings.csv

Full example: ./ticketSystem -f flights.csv -b bookings.csv -c cancelled-flights.txt -s seating-map.txt
