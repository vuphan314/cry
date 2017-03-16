COMPILER = g++
EXECUTABLE = cry.out
FLAGS = -Ofast -lgmpxx -lgmp
OBJECTS = main.o party.o rsa_cryptosystem.o cryptosystem.o

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) -o $(EXECUTABLE) $(OBJECTS) $(FLAGS)

main.o: main.cc party/party.h
	$(COMPILER) -c main.cc $(FLAGS)

party.o: party/party.h party/party.cc \
cryptosystem/rsa_cryptosystem.h
	$(COMPILER) -c party/party.cc $(FLAGS)

rsa_cryptosystem.o: cryptosystem/rsa_cryptosystem.h \
cryptosystem/rsa_cryptosystem.cc cryptosystem/cryptosystem.h
	$(COMPILER) -c cryptosystem/rsa_cryptosystem.cc $(FLAGS)

cryptosystem.o: cryptosystem/cryptosystem.h \
cryptosystem/cryptosystem.cc
	$(COMPILER) -c cryptosystem/cryptosystem.cc $(FLAGS)

############################################################

clean:
	rm -f *.o $(EXECUTABLE)
