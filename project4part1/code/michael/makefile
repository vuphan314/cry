EXECUTABLE = michael.out
OBJECTS = michael.o

COMPILER = g++
ASSEMBLING_OPTIONS = -c -std=c++11 -Ofast
LINKING_OPTIONS = -o $(EXECUTABLE) -lgmpxx -lgmp

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(LINKING_OPTIONS)

main.o: michael.cc
	$(COMPILER) michael.cc $(ASSEMBLING_OPTIONS)

############################################################

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
