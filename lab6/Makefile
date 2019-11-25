#Author: Xiaohui Ling/C00212235
#Email: C00212235@itcarlow.ie
#Makefile that is a compile script for lab6
#It will produce the execution file named ProdCon if you run the command 'make Makefile'

CC=g++
CFLAGS= -std=c++11 -pthread -g -O0

#This rule says that each .o file depends on a .cpp file of the same name
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(DEBUGFLAGS)

ALL: main.o
	$(CC) -o ProdCon Semaphore.cpp Message.cpp MessageBuffer.cpp main.cpp $(CFLAGS) $(DEBUGFLAGS)

DEBUG: DEBUGFLAGS = -DDEBUG
DEBUG: ALL

#this is customary and just deletes all .o files
CLEAN:
	rm *.o
