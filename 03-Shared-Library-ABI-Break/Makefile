CC=g++
CFLAGS=--std=c++11 -Wall -Werror -I.

all: lib embedder_binary

lib: library/api.cc library/api.h
	# Position-independent code (`-fpic`) is required for shared libraries.
	$(CC) -c -fpic library/api.cc -o library.o $(CFLAGS)
	$(CC) -shared -o liblibrary.so library.o
	rm library.o

embedder_binary: embedder/main.cc
	$(CC) embedder/main.cc -L./ -llibrary -o embedder_binary $(CFLAGS)

clean:
	rm liblibrary.so embedder_binary
