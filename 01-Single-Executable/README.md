# Single executable from multiple implementation files

This is your typical example where an embedder application references symbols
that exist in a library, and the embedder & library implementation files
(i.e., `embedder/main.cc` & `library/api.cc`) are compiled together into a
single binary.

There's nothing special about this, it's just a reference application.

Run:

```sh
$ make
```
