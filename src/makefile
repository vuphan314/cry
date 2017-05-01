COMPILER = g++
LINKING_OPTIONS = -o $(EXECUTABLE) -lgmpxx -lgmp
ASSEMBLING_OPTIONS = -c -std=c++11 -Ofast

EXECUTABLE = cry.out
OBJECTS = main.o party.o \
	dummy_tester.o rsa_tester.o tester.o \
	dummy_cryptosystem.o rsa_cryptosystem.o cryptosystem.o \
	../cplusplus/src/timing.o ../cplusplus/src/vectors.o

HEADERS = $(TESTER_HEADERS) $(CRYPTOSYSTEM_HEADERS) \
	$(SUBMODULE_HEADERS)
TESTER_HEADERS = tester/dummy_tester.h tester/rsa_tester.h \
	tester/tester.h
CRYPTOSYSTEM_HEADERS = cryptosystem/dummy_cryptosystem.h \
	cryptosystem/rsa_cryptosystem.h \
	cryptosystem/cryptosystem.h
SUBMODULE_HEADERS = ../cplusplus/src/timing.h \
	../cplusplus/src/vectors.h

############################################################

$(EXECUTABLE): $(OBJECTS)
	$(COMPILER) $(OBJECTS) $(LINKING_OPTIONS)

main.o: main.cc \
		party/party.h $(HEADERS)
	$(COMPILER) main.cc $(ASSEMBLING_OPTIONS)

party.o: party/party.cc \
		party/party.h $(HEADERS)
	$(COMPILER) party/party.cc $(ASSEMBLING_OPTIONS)

############################################################

dummy_tester.o: tester/dummy_tester.cc \
		tester/dummy_tester.h \
		cryptosystem/dummy_cryptosystem.h \
		cryptosystem/rsa_cryptosystem.h \
		tester/tester.h \
		cryptosystem/cryptosystem.h $(SUBMODULE_HEADERS)
	$(COMPILER) tester/dummy_tester.cc $(ASSEMBLING_OPTIONS)

rsa_tester.o: tester/rsa_tester.cc \
		tester/rsa_tester.h \
		cryptosystem/rsa_cryptosystem.h \
		tester/tester.h \
		cryptosystem/cryptosystem.h $(SUBMODULE_HEADERS)
	$(COMPILER) tester/rsa_tester.cc $(ASSEMBLING_OPTIONS)

tester.o: tester/tester.cc \
		tester/tester.h \
		cryptosystem/cryptosystem.h $(SUBMODULE_HEADERS)
	$(COMPILER) tester/tester.cc $(ASSEMBLING_OPTIONS)

############################################################

dummy_cryptosystem.o: cryptosystem/dummy_cryptosystem.cc \
		cryptosystem/dummy_cryptosystem.h \
		cryptosystem/rsa_cryptosystem.h \
		cryptosystem/cryptosystem.h $(SUBMODULE_HEADERS)
	$(COMPILER) cryptosystem/dummy_cryptosystem.cc \
		$(ASSEMBLING_OPTIONS)

rsa_cryptosystem.o: cryptosystem/rsa_cryptosystem.cc \
		cryptosystem/rsa_cryptosystem.h \
		cryptosystem/cryptosystem.h $(SUBMODULE_HEADERS)
	$(COMPILER) cryptosystem/rsa_cryptosystem.cc \
		$(ASSEMBLING_OPTIONS)

cryptosystem.o: cryptosystem/cryptosystem.cc \
		cryptosystem/cryptosystem.h $(SUBMODULE_HEADERS)
	$(COMPILER) cryptosystem/cryptosystem.cc \
		$(ASSEMBLING_OPTIONS)

############################################################

subsystem:
	$(MAKE) -C ../cplusplus/src/

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
