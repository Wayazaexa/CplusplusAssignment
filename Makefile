ticketSystem.o: ticketSystem.cpp ticketManager.cpp ticketManager.hh booking.cpp booking.hh bookings.cpp bookings.hh flight.cpp flight.hh flights.cpp flights.hh
	g++ ticketSystem.cpp ticketManager.cpp booking.cpp bookings.cpp flight.cpp flights.cpp -o ticketSystem.o
