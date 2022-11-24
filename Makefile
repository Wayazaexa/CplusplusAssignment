ticketSystem: ticketSystem.cpp ticketManager.cpp ticketManager.hh booking.cpp booking.hh bookings.cpp bookings.hh flight.cpp flight.hh flights.cpp flights.hh tripInfo.hh
	@echo "Compiling"
	g++ ticketSystem.cpp ticketManager.cpp booking.cpp bookings.cpp flight.cpp flights.cpp -o ticketSystem

check: ticketSystem
	@echo "Running"
	./ticketSystem -f flights.csv -b bookings.csv -c cancelled-flights.txt -s seat-mapping.txt

documentation:
	@echo "Generating documentation"
	doxygen
	cd latex && make
