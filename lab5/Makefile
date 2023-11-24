# Sam Cullen
# C00250093

CC=g++
CPPFILES=main.cpp Semaphore.cpp
HFILES=Semaphore.h
OBJFILES=main.o Semaphore.o
CFLAGS= -std=c++11 -pthread -I. -Wall
EXE=philosophers

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(OBJFILES) $(HFILES)
	$(CC) -o $(EXE) $(OBJFILES) $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm $(OBJFILES)