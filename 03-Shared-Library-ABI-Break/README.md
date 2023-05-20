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

# Break the ABI!

This directory gives you a readymade way to change the code in `library/` to
make `liblibrary.so` suffer an ABI break without changing itse A*P*I.

To experiment with this, run:

```sh
$ git apply abi-break-1.diff
$ make lib
$ ./embedder_binary
```

Just be sure you don't rebuild `embedder_binary` after you update the library,
or else everything will work as expected and you won't be able to observe the
ABI break.
