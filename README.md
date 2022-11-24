# C++ assignment/hand-in

In the assignment (and repository) '4a-files', we were tasked with making a ticket creating system in C.
This assignment consists of remaking that system in C++.

```
Running 'make' on this code will generate the executable file ticketSystem.
Running 'make documentation' on this will use doxygen to generate documentation in the form of
html and latex, and latex will generate a pdf file called refman.pdf.
```

```
The program takes two parameters; a database of flights and a database of bookings, both in csv-type of files.
The csv files must have the following fields:

flights.csv: flightNumber,departure,destination,date,time,numberOfFirstClassRows,numberOfBusinessClassRows,numberOfEconomyClassRows
Ex:
304,GOT,CPH,2022-10-27,09:30,4,7,10
306,CPH,LHR,2022-10-27,06:30,2,4,8

bookings.csv: bookingNumber,date,time,departure,destination,seatClass,firstName,surname
Ex:
1006,2022-10-27,06:30,GOT,LGW,first,Tjatte,Anka
1007,2022-10-27,06:30,GOT,LGW,economy,Kajsa,Stinasson
```

The program also have two optional parameters; the name of two text files that will store additional output
from the program, a seating map and a list of cancelled flights.

```
Example usage: ./ticketSystem -f flights.csv -b bookings.csv
Full example: ./ticketSystem -f flights.csv -b bookings.csv -c cancelled-flights.txt -s seating-map.txt
```
