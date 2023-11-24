# Sam Cullen
# C00250093
CC=g++
CPPFILES=Event.cpp SafeBuffer.cpp main.cpp Semaphore.cpp
HFILES=Event.h SafeBuffer.h Semaphore.h
OBJFILES=Event.o SafeBuffer.o main.o Semaphore.o
CFLAGS= -std=c++11 -pthread -I. -Wall
EXE=safeBuffer


%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: $(OBJFILES) $(HFILES)
	$(CC) -o $(EXE) $(OBJFILES) $(CFLAGS) $(DEBUGFLAGS) 

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

CLEAN:
	rm $(OBJFILES)
