CC=g++
CFLAGS=--std=c++11 -Wall -Werror -I.

all: lib embedder_binary

lib: src/lib.rs
	cargo build

embedder_binary: embedder.cc
	$(CC) embedder.cc -L./target/debug/ -lclibraryinrust -o embedder_binary $(CFLAGS)

clean:
	rm -rf target/ embedder_binary
