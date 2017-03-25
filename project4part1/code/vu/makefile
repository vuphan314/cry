COMPILER = g++
ASSEMBLING_OPTIONS = -c -std=c++11 -Ofast
LINKING_OPTIONS = -o $(EXECUTABLE) -lgmpxx -lgmp

OBJECTS = main.o tutorial.o
EXECUTABLE = vu.out

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(LINKING_OPTIONS)

main.o: main.cc tutorial.h
	$(COMPILER) main.cc $(ASSEMBLING_OPTIONS)

tutorial.o: tutorial.h tutorial.cc
	$(COMPILER) tutorial.cc $(ASSEMBLING_OPTIONS)

############################################################

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
