CC = g++
CFLAGS = -g

all: main

main: main.o DoublyLinkedList.o
	$(CC) $(CFLAGS) main.cpp DoublyLinkedList.cpp -o main

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
