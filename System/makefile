main: ConcreteCommissioner.o Commissioner.o Battle.o Country.o WarEngine.o Army.o Port.o Hospital.o Fortification.o Depot.o Airfield.o BaseBuilder.o Facility.o FOB.o main.cpp
	g++ ConcreteCommissioner.o Commissioner.o Battle.o Country.o WarEngine.o Army.o Port.o Hospital.o Fortification.o Depot.o Airfield.o BaseBuilder.o Facility.o FOB.o main.cpp -o main

# PhaseManager.o: Phases/PhaseManager.cpp Phases/PhaseManager.h
# 	g++ -c Phases/PhaseManager.cpp

# Phase.o: Phases/Phase.cpp Phases/Phase.h
# 	g++ -c Phases/Phase.cpp

# Peace.o: Phases/Peace.cpp Phases/Peace.h
# 	g++ -c Phases/Peace.cpp

# Negotiations.o: Phases/Negotiations.cpp Phases/Negotiations.h
# 	g++ -c Phases/Negotiations.cpp

# War.o: Phases/War.cpp Phases/War.h
# 	g++ -c Phases/War.cpp

ConcreteCommissioner.o: Commissioner/ConcreteCommissioner.cpp Commissioner/ConcreteCommissioner.h
	g++ -c Commissioner/ConcreteCommissioner.cpp

Commissioner.o: Commissioner/Commissioner.cpp Commissioner/Commissioner.h
	g++ -c Commissioner/Commissioner.cpp

Battle.o: Battle/Battle.cpp Battle/Battle.h
	g++ -c Battle/Battle.cpp

Country.o: Country/Country.cpp Country/Country.h
	g++ -c Country/Country.cpp

WarEngine.o: WarEngine/WarEngine.cpp WarEngine/WarEngine.h
	g++ -c WarEngine/WarEngine.cpp

BaseBuilder.o: BaseBuilder/BaseBuilder.cpp BaseBuilder/BaseBuilder.h
	g++ -c BaseBuilder/BaseBuilder.cpp

Facility.o: Facility/Facility.cpp Facility/Facility.h
	g++ -c Facility/Facility.cpp

FOB.o: Facility/FOB.cpp Facility/FOB.h
	g++ -c Facility/FOB.cpp

Airfield.o: Facility/Airfield.cpp Facility/Airfield.h
	g++ -c Facility/Airfield.cpp

Depot.o: Facility/Depot.cpp Facility/Depot.h
	g++ -c Facility/Depot.cpp

Fortification.o: Facility/Fortification.cpp Facility/Fortification.h
	g++ -c Facility/Fortification.cpp

Hospital.o: Facility/Hospital.cpp Facility/Hospital.h
	g++ -c Facility/Hospital.cpp

Port.o: Facility/Port.cpp Facility/Port.h
	g++ -c Facility/Port.cpp

Army.o: Army/Army.cpp Army/Army.h
	g++ -c Army/Army.cpp

run:
	main

clean:
	del *.o main


