# C++ assignment/hand-in

In the assignment (and repository) '4a-files', we were tasked with making a ticket creating system in C.
This assignment consists of remaking that system in C++.

Running 'make' on this code will generate the executable file ticketSystem.o (the file extension .o was just chosen to make it easy to add to my gitignore and easy to find when I want to remove it).
The program takes two parameters; a database of flights and a database of bookings, both in csv-type of files.

Example usage: ./ticketSystem.o -f flights.csv -b bookings.csv
