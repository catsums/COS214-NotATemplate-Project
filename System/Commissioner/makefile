main: Port.o Hospital.o Fortification.o Depot.o Airfield.o ConcreteCommissioner.o Commissioner.o BaseBuilder.o Facility.o FOB.o main.cpp
	g++ Port.o Hospital.o Fortification.o Depot.o Airfield.o ConcreteCommissioner.o Commissioner.o BaseBuilder.o Facility.o FOB.o main.cpp -o main

FOB.o: ../Facility/FOB.cpp ../Facility/FOB.h
	g++ -c ../Facility/FOB.cpp

Facility.o: ../Facility/Facility.cpp ../Facility/Facility.h
	g++ -c ../Facility/Facility.cpp

BaseBuilder.o: ../BaseBuilder/BaseBuilder.cpp ../BaseBuilder/BaseBuilder.h
	g++ -c ../BaseBuilder/BaseBuilder.cpp

Commissioner.o: Commissioner.cpp Commissioner.h
	g++ -c Commissioner.cpp

ConcreteCommissioner.o: ConcreteCommissioner.cpp ConcreteCommissioner.h
	g++ -c ConcreteCommissioner.cpp

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
	rm *.o main