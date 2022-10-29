CC=g++
CFLAGS=--std=c++11 -I.

embedder_binary:
	$(CC) embedder/main.cc library/api.cc -o embedder_binary $(CFLAGS)

clean:
	rm embedder_binary
