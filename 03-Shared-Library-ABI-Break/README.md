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

Your output should be:

```
Embedder application booting up; detecting sizeof(library::Point): 8
library::GetPoints() running. sizeof(Point): 8
(x: 0, y: 0)
(x: 1, y: 1)
(x: 2, y: 2)
(x: 3, y: 3)
(x: 4, y: 4)
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

Your output with a broken ABI should be some nonsense like:

```
Embedder application booting up; detecting sizeof(library::Point): 8
library::GetPoints() running. sizeof(Point): 40
(x: 0, y: 0, z: 0)
(x: 0, y: 0, z: 1830990592)
(x: 1830990592, y: 1, z: -69050104)
(x: -69050104, y: 1, z: 45967704)
(x: 45967704, y: 1, z: 1)
(x: 1, y: 1, z: 1)
(x: 1, y: 0, z: 1830990592)
(x: 1830990592, y: 1, z: -69050104)
(x: -69050104, y: 1, z: 45967704)
(x: 45967704, y: 1, z: 2)
(x: 2, y: 2, z: 2)
(x: 2, y: 0, z: 1830990592)
(x: 1830990592, y: 1, z: -69050104)
(x: -69050104, y: 1, z: 45967704)
(x: 45967704, y: 1, z: 3)
(x: 3, y: 3, z: 3)
(x: 3, y: 0, z: 1830990592)
(x: 1830990592, y: 1, z: -69050104)
(x: -69050104, y: 1, z: 45967704)
(x: 45967704, y: 1, z: 4)
(x: 4, y: 4, z: 4)
(x: 4, y: 0, z: 1830990592)
(x: 1830990592, y: 1, z: -69050104)
(x: -69050104, y: 1, z: 45967704)
(x: 45967704, y: 1, z: 0)
```
