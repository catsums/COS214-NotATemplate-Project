main: BaseBuilder.o main.cpp
	g++ BaseBuilder.o main.cpp -o main

BaseBuilder.o: BaseBuilder.cpp BaseBuilder.h
	g++ -c BaseBuilder.cpp

run:
	./main

clean:
	rm *.o main