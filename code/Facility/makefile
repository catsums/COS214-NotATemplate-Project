main: Hospital.o Fortification.o Airfield.o FOB.o Facility.o main.cpp
	g++ Hospital.o Fortification.o Airfield.o FOB.o Facility.o main.cpp -o main

Hospital.o: Hospital.cpp Hospital.h
	g++ -c .Hospital.cpp

Fortification.o: Fortification.cpp Fortification.h
	g++ -c .Fortification.cpp

Airfield.o: Airfield.cpp Airfield.h
	g++ -c .Airfield.cpp

FOB.o: FOB.cpp FOB.h
	g++ -c .FOB.cpp

Facility.o: Facility.cpp Facility.h
	g++ -c .Facility.cpp

run:
	./main

clean:
	rm *.o main