# Building & dynamically linking our shared library

Good resource:
https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html.

Steps
 - `make library`
 - `make embedder_binary`

# How does an ABI differ from an API?

Since we have both terms "API" and "ABI", they must mean different things. That
is, if all API changes resulted in ABI changes, and ABI changes could only come
about as a result of API changes, then the two terms would be identical and we
wouldn't have a reason to distinguish the two.

However, the two are not equivalent. In particular, it's possible to make
API-breaking changes that are still ABI-compatible, and it's possible to make
API-compatible changes that break ABI-compatibility.
However, the two are not equivalent. In particular, it's possible to make:
 1. **API-breaking changes** (such that a piece of code and its users are no
    longer source-compatible), that are still ABI-compatible with existing
    binaries, and;
 1. **API-compatible changes** (such that a piece of code and its users are
 still source-compatible), that break ABI-compatibility with existing binaries
