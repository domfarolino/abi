CC=g++
CFLAGS=--std=c++11 -Wall -Werror -I.

all: lib

lib: library/api.cc library/api.h
	# Position-independent code (`-fpic`) is required for shared libraries.
	$(CC) -c -fpic library/api.cc -o library.o $(CFLAGS)
	$(CC) -shared -o liblibrary.so library.o
	rm library.o

clean:
	rm -rf liblibrary.so liblibrary.dylib
