# Static library & static linking

This is example is just like [01-Single-Executable](../01-Single-Executable)
except the library used by the embedder is compiled into a static library (`.a`)
archive separately, and later linked into the embedder binary at *its*
compile-time. This copies the entire static library into the embedder binary.

It's useful to distribute a static library of some large piece of software to
avoid making consumers compile it themselves, however this benefit is not nearly
as useful as it once was given today's compiler technology.

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
