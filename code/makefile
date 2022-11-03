Main: Country.o WarEngine.o main.cpp
	g++ Country.o WarEngine.o main.cpp -o Main

Country.o: ./Country/Country.cpp ./Country/Country.h
	g++ -c ./Country/Country.cpp

WarEngine.o: ./WarEngine/WarEngine.cpp ./WarEngine/WarEngine.h
	g++ -c ./WarEngine/WarEngine.cpp

run:
	./main

clean:
	rm *.o main