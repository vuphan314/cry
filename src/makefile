COMPILER = g++
EXECUTABLE = cry.out
FLAGS = -c -lgmpxx -lgmp -Ofast
OBJECTS = main.o party.o rsa_cryptosystem.o cryptosystem.o

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) -o $(EXECUTABLE) $(OBJECTS)

main.o: main.cc party/party.h
	$(COMPILER) $(FLAGS) main.cc

party.o: party/party.h party/party.cc \
cryptosystem/rsa_cryptosystem.h
	$(COMPILER) $(FLAGS) party/party.cc

rsa_cryptosystem.o: cryptosystem/rsa_cryptosystem.h \
cryptosystem/rsa_cryptosystem.cc cryptosystem/cryptosystem.h
	$(COMPILER) $(FLAGS) cryptosystem/rsa_cryptosystem.cc

cryptosystem.o: cryptosystem/cryptosystem.h \
cryptosystem/cryptosystem.cc
	$(COMPILER) $(FLAGS) cryptosystem/cryptosystem.cc

############################################################

clean:
	rm -f *.o $(EXECUTABLE)
