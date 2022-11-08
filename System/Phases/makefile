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