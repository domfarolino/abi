CC=g++
CFLAGS=--std=c++11 -Wall -Werror -I.

# Detect OS for library extension.
UNAME := $(shell uname)
ifeq ($(UNAME), Darwin)
    LIB_EXT := .dylib
else
    LIB_EXT := .so
endif

all: lib

lib: library/api.cc library/api.h
	# Position-independent code (`-fpic`) is required for shared libraries.
	$(CC) -c -fpic library/api.cc -o library.o $(CFLAGS)
	$(CC) -shared -o liblibrary.so library.o
	rm library.o

clean:
	rm -rf liblibrary.so liblibrary.dylib
