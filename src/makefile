COMPILER = g++
EXECUTABLE = cry.out
FLAGS = -Ofast -lgmpxx -lgmp
OBJECTS = main.o party.o rsa_cryptosystem.o cryptosystem.o

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) -o $(EXECUTABLE) $(OBJECTS) $(FLAGS)

main.o: main.cc party/party.h \
cryptosystem/rsa_cryptosystem.h cryptosystem/cryptosystem.h
	$(COMPILER) -c -std=c++11 main.cc

party.o: party/party.h party/party.cc \
cryptosystem/rsa_cryptosystem.h \
cryptosystem/cryptosystem.h
	$(COMPILER) -c -std=c++11 party/party.cc

rsa_cryptosystem.o: cryptosystem/rsa_cryptosystem.h \
cryptosystem/rsa_cryptosystem.cc \
cryptosystem/cryptosystem.h
	$(COMPILER) -c -std=c++11 cryptosystem/rsa_cryptosystem.cc

cryptosystem.o: cryptosystem/cryptosystem.h \
cryptosystem/cryptosystem.cc
	$(COMPILER) -c -std=c++11 cryptosystem/cryptosystem.cc

############################################################

clean:
	rm *.o $(EXECUTABLE)
