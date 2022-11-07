main: Battle.o Country.o WarEngine.o main.cpp
	g++ Battle.o Country.o WarEngine.o main.cpp -o main

Battle.o: ./Battle/Battle.cpp ./Battle/Battle.h
	g++ -c ./Battle/Battle.cpp

Country.o: ./Country/Country.cpp ./Country/Country.h
	g++ -c ./Country/Country.cpp

WarEngine.o: ./WarEngine/WarEngine.cpp ./WarEngine/WarEngine.h
	g++ -c ./WarEngine/WarEngine.cpp

run:
	./main

clean:
	rm *.o main


# main: Hospital.o Fortification.o Airfield.o Depot.o Port.o FOB.o Facility.o main.cpp
# 	g++ Hospital.o Fortification.o Airfield.o Depot.o Port.o FOB.o Facility.o main.cpp -o main

# Hospital.o: Hospital.cpp Hospital.h
# 	g++ -c Hospital.cpp

# Fortification.o: Fortification.cpp Fortification.h
# 	g++ -c Fortification.cpp

# Airfield.o: Airfield.cpp Airfield.h
# 	g++ -c Airfield.cpp

# Depot.o: Depot.cpp Depot.h
# 	g++ -c Depot.cpp

# Port.o: Port.cpp Port.h
# 	g++ -c Port.cpp

# FOB.o: FOB.cpp FOB.h
# 	g++ -c FOB.cpp

# Facility.o: Facility.cpp Facility.h
# 	g++ -c Facility.cpp

# run:
# 	./main

# clean:
# 	rm *.o main