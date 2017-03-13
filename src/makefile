COMPILER = g++
EXECUTABLE = cry.out
FLAGS = -c -lgmp -lgmpxx -Ofast
OBJECTS = main.o party/party.o cryptosystem/rsa_cryptosystem.o

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) -o $(EXECUTABLE) $(OBJECTS)

main.o: main.cc party/party.h
	$(COMPILER) $(FLAGS) main.cc

party.o: party/party.h party/party.cc cryptosystem/rsa_cryptosystem.h
	$(COMPILER) $(FLAGS) party.cc

rsa_cryptosystem.o: cryptosystem/rsa_cryptosystem.h cryptosystem/rsa_cryptosystem.cc
	$(COMPILER) $(FLAGS) rsa_cryptosystem.cc

############################################################

clean:
	rm -f *.o $(EXECUTABLE)
