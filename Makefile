# Makefile
CC = g++

observer: observer.cpp
	$(CC) -o $@ $<

clean:
	rm -f observer
