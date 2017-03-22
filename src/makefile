COMPILER = g++
COMPILER_FLAGS = -c -std=c++11 -Ofast
EXECUTABLE = cry.out
LINKER_FLAGS = -lgmpxx -lgmp
OBJECTS = main.o party.o rsa_cryptosystem.o cryptosystem.o

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) -o $(EXECUTABLE) $(OBJECTS) $(LINKER_FLAGS)

main.o: main.cc party/party.h \
cryptosystem/rsa_cryptosystem.h cryptosystem/cryptosystem.h
	$(COMPILER) main.cc $(COMPILER_FLAGS)

party.o: party/party.h party/party.cc \
cryptosystem/rsa_cryptosystem.h \
cryptosystem/cryptosystem.h
	$(COMPILER) party/party.cc $(COMPILER_FLAGS)

rsa_cryptosystem.o: cryptosystem/rsa_cryptosystem.h \
cryptosystem/rsa_cryptosystem.cc \
cryptosystem/cryptosystem.h
	$(COMPILER) cryptosystem/rsa_cryptosystem.cc $(COMPILER_FLAGS)

cryptosystem.o: cryptosystem/cryptosystem.h \
cryptosystem/cryptosystem.cc
	$(COMPILER) cryptosystem/cryptosystem.cc $(COMPILER_FLAGS)

############################################################

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
