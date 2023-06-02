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
$(BIN) : $(OBJETS)
	$(ECHO) ">>>Edition des liens de <$(EXE)>"
	$(LD) $(LDFLAGS) $^ -o $@

# compilation des fichiers
%.o: %.cpp
	@$(ECHO) ">>>Compilation de" $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(EFFACE) :
	@$(ECHO) ">>>Suppression des fichiers compilés" $<
	$(RM) $(RMFLAGS) $(BIN) $(OBJETS)

# dependances complementaires
AirCleaner.o : Coordinates.h
AppService.o : DataSet.h Coordinates.cpp Measure.h Sensor.h
DataSet.o : Sensor.h Measure.h AirCleaner.h User.h Provider.h FileManager.h PrivIndiv.h
FileManager.o : Sensor.h Coordinates.h Measure.h User.h AirCleaner.h Provider.h
IHM.o : FileManager.h DataSet.h AppService.h Test.h
InitService.o : DataSet.h
MemberGov.o : SuperUser.h
PrivIndiv.o : Sensor.h User.h
Provider.o : AirCleaner.h User.h
Sensor.o : Coordinates.h
Test.o : FileManager.h DataSet.h AppService.h