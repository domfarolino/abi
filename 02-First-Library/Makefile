CC=g++
CFLAGS=--std=c++11 -Wall -Werror -I.

library.o:
	$(CC) -c -fpic library/api.cc -o library.o $(CFLAGS)
	$(CC) -shared -o liblibrary.so library.o
	rm library.o

binary:
	$(CC) embedder/main.cc -L./ -llibrary -o binary $(CFLAGS)
