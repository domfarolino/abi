CC=g++
CFLAGS=--std=c++11 -Wall -Werror -I.

library: liblibrary.so

liblibrary.so: library/api.cc library/api.h
	$(CC) -c -fpic library/api.cc -o library.o $(CFLAGS)
	$(CC) -shared -o liblibrary.so library.o
	rm library.o

embedder_binary: embedder/main.cc
	$(CC) embedder/main.cc -L./ -llibrary -o embedder_binary $(CFLAGS)

all: library embedder_binary

clean:
	rm liblibrary.so embedder_binary
