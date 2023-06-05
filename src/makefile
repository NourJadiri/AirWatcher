# makefile plus ou moins générique
# outils
ECHO = @echo
RM = @rm

CXX = g++
LD = g++

# options
CXXFLAGS = -g -Wall -ansi -pedantic -std=c++14
LDFLAGS = -g -Wall -pedantic -std=c++14
RMFLAGS = -rf

# definition des cibles
INTERFACE := $(wildcard *.h)
REALISATION := $(INTERFACE:.h=.cpp)
OBJETS = $(REALISATION:.cpp=.o)
EXE = airwatcher
EFFACE = clean
.PHONY : $(EFFACE)

# edition des liens
$(EXE) : $(OBJETS)
	$(ECHO) ">>>Edition des liens de <$(EXE)>"
	$(LD) $(LDFLAGS) $^ -o $@

# compilation des fichiers
%.o: %.cpp
	@$(ECHO) ">>>Compilation de" $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(EFFACE) :
	@$(ECHO) ">>>Suppression des fichiers compilés" $<
	$(RM) $(RMFLAGS) $(EXE) $(OBJETS)

# dependances complementaires
AirCleaner.o : domain/Coordinates.h
AppService.o : domain/DataSet.h domain/Coordinates.cpp domain/Measure.h domain/Sensor.h
DataSet.o : data/FileManager.h domain/Sensor.h domain/Measure.h domain/AirCleaner.h domain/User.h domain/Provider.h  domain/PrivIndiv.h
FileManager.o : domain/Sensor.h domain/Coordinates.h domain/Measure.h domain/User.h domain/AirCleaner.h domain/Provider.h
IHM.o : data/FileManager.h domain/DataSet.h services/AppService.h application/Test.h
MemberGov.o : domain/SuperUser.h
PrivIndiv.o : domain/Sensor.h domain/User.h
Provider.o : domain/AirCleaner.h domain/SuperUser.h
Sensor.o : domain/Coordinates.h
SuperUser.o : domain/User.h
Test.o : data/FileManager.h domain/DataSet.h services/AppService.h