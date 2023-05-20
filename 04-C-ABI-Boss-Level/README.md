# Shared library building & dynamic linking

Good resource:
 - https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html

This is a basic demonstration of building a shared library and linking it
dynamically (at runtime) with a binary that depends on it. The next example will
demonstrate the problem of binary incompatibility on top of this one.

Run:

```sh
$ make lib
$ make embedder_binary
$ ./embedder_binary
$ make clean
```

Or:

```sh
$ make
$ ./embedder_binary
$ make clean
```
