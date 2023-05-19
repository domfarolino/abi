CC=g++
CFLAGS=--std=c++11 -I.

all: lib embedder_binary

lib:
	# The `-c` arg only compiles, doesn't link. It allows us to exclude a `main()` definition.
	$(CC) -c library/api.cc -o libmylibrary.o
	# See https://stackoverflow.com/a/51128431/3947332.
	ar rcs libmylibrary.a libmylibrary.o
	rm libmylibrary.o

embedder_binary:
	# The `-l` syntax is weird; it's `-l` and then the library nmae without the `lib` prefix.
	$(CC) embedder/main.cc -L. -lmylibrary -o embedder_binary $(CFLAGS)

clean:
	rm embedder_binary libmylibrary.a
