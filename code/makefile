ofiles = main.o 
gpp_o = g++ -c -std=c++11 

main: $(ofiles)
	g++ -std=c++11  $(ofiles) -o main
main.o: main.cpp Citizen.h Soldier.h Medic.h Informant.h Politician.h Entity.h SoldierFactory.h
	$(gpp_o) main.cpp


run: main
	./main

clean:
	rm *.o main