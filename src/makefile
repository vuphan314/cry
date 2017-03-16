COMPILER = g++
EXECUTABLE = cry.out
FLAGS = -c -Ofast -lgmpxx -lgmp
OBJECTS = main.o party.o rsa_cryptosystem.o cryptosystem.o

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) -o $(EXECUTABLE) $(OBJECTS)

main.o: main.cc party/party.h
	$(COMPILER) main.cc $(FLAGS)

party.o: party/party.h party/party.cc \
cryptosystem/rsa_cryptosystem.h
	$(COMPILER) party/party.cc $(FLAGS)

rsa_cryptosystem.o: cryptosystem/rsa_cryptosystem.h \
cryptosystem/rsa_cryptosystem.cc cryptosystem/cryptosystem.h
	$(COMPILER) cryptosystem/rsa_cryptosystem.cc $(FLAGS)

cryptosystem.o: cryptosystem/cryptosystem.h \
cryptosystem/cryptosystem.cc
	$(COMPILER) cryptosystem/cryptosystem.cc $(FLAGS)

############################################################

clean:
	rm -f *.o $(EXECUTABLE)
