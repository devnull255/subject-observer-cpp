# Makefile
CC = g++

observer: observer.cpp
	$(CC) -o $@ $<

test: observer
	./observer
clean:
	rm -f observer
