COMPILER = g++
ASSEMBLING_OPTIONS = -c -std=c++11 -Ofast
LINKING_OPTIONS = -o $(EXECUTABLE) -lgmpxx -lgmp

OBJECTS = main.o party.o \
	rsa_cryptosystem.o dummy_cryptosystem.o cryptosystem.o
EXECUTABLE = cry.out

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(LINKING_OPTIONS)

main.o: main.cc party/party.h \
		cryptosystem/rsa_cryptosystem.h \
		cryptosystem/dummy_cryptosystem.h \
		cryptosystem/cryptosystem.h
	$(COMPILER) main.cc $(ASSEMBLING_OPTIONS)

party.o: party/party.h party/party.cc \
		cryptosystem/rsa_cryptosystem.h \
		cryptosystem/cryptosystem.h
	$(COMPILER) party/party.cc $(ASSEMBLING_OPTIONS)

rsa_cryptosystem.o: cryptosystem/rsa_cryptosystem.h \
		cryptosystem/rsa_cryptosystem.cc \
		cryptosystem/cryptosystem.h
	$(COMPILER) cryptosystem/rsa_cryptosystem.cc \
		$(ASSEMBLING_OPTIONS)

dummy_cryptosystem.o: cryptosystem/dummy_cryptosystem.h \
		cryptosystem/dummy_cryptosystem.cc \
		cryptosystem/cryptosystem.h
	$(COMPILER) cryptosystem/dummy_cryptosystem.cc \
		$(ASSEMBLING_OPTIONS)

cryptosystem.o: cryptosystem/cryptosystem.h \
		cryptosystem/cryptosystem.cc
	$(COMPILER) cryptosystem/cryptosystem.cc \
		$(ASSEMBLING_OPTIONS)

############################################################

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
