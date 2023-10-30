#Sam Cullen
#Used to contain commands to compile projects
CC=g++
CFLAGS= -std=c++11 -pthread

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

SIMPLE: rendezvous.o Semaphore.o 
	$(CC) $(CFLAGS) -o rendezvous Semaphore.cpp rendezvous.cpp $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
