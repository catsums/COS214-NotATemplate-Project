main: Port.o Hospital.o Fortification.o Depot.o Airfield.o BaseBuilder.o Facility.o FOB.o main.cpp
	g++ Port.o Hospital.o Fortification.o Depot.o Airfield.o BaseBuilder.o Facility.o FOB.o main.cpp -o main

BaseBuilder.o: BaseBuilder.cpp BaseBuilder.h
	g++ -c BaseBuilder.cpp

Facility.o: ../Facility/Facility.cpp ../Facility/Facility.h
	g++ -c ../Facility/Facility.cpp

FOB.o: ../Facility/FOB.cpp ../Facility/FOB.h
	g++ -c ../Facility/FOB.cpp

Airfield.o: ../Facility/Airfield.cpp ../Facility/Airfield.h
	g++ -c ../Facility/Airfield.cpp

Depot.o: ../Facility/Depot.cpp ../Facility/Depot.h
	g++ -c ../Facility/Depot.cpp

Fortification.o: ../Facility/Fortification.cpp ../Facility/Fortification.h
	g++ -c ../Facility/Fortification.cpp

Hospital.o: ../Facility/Hospital.cpp ../Facility/Hospital.h
	g++ -c ../Facility/Hospital.cpp

Port.o: ../Facility/Port.cpp ../Facility/Port.h
	g++ -c ../Facility/Port.cpp

run:
	./main

clean:
	del *.o main