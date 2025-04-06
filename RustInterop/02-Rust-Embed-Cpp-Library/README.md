# Rust embedding a C++ shared library

This directory implements is the inverse of
[01-Cpp-Embed-Rust-Library](../01-Cpp-Embed-Rust-Library); in this case, a Rust
program embeds a simple C++ shared library that exposes a C ABI which the Rust
binary interacts with.

To accommodate this more complex scenario where your rust project needs to
integrate with a shared library that will be dynamically linked at runtime, we
can use a mixture of build scripts (**build.rs**) and compiler directives to
teach the compiler and the final binary how to find and link to the shared
library. This is useful when embedding system-level libraries that aren't
intended to be compiled into client applications directly, or a library that
gets updated regularly outside the scope of your project.

This example does not use the [**cc**][cc] crate to compile the shared library,
since you often don't have access to a shared library's source or build process
process. Rather, you're just consuming the library's binary directly.

For the purpose of this example, the shared library's source is in
[**library/api.h**](./library/api.h) and [**library/api.cc**](./library/api.cc),
so we can transparently see its API surface. However, we build and distribute
the resulting shared library binary independent of our Rust build process, with
the provided [**Makefile**](./Makefile), which produces a suitable binary for
our project to consume.

## Rust build process modifications

Before compiling rust source code, the build script [**build.rs**](./build.rs)
runs, which does two things:
  1. **Compile-time**: Enumerates all libraries that our binary depends on, with
     the [`cargo:rustc-link-lib`][rustc-link-lib] directive, and tells
     **rustc** how to find them at compile time, by adding search paths to the
     compile step with the [`cargo:rustc-link-search`][rustc-link-search]
     directive. This aids compile-time symbol resolution, for any `#[link]`
     directives in our Rust source. The [`cargo:rustc-link-lib`][rustc-link-lib]
     directive also tells the compiler **how** to link those libraries with the
     final binary (i.e., static, dynamic/shared, etc.).
  2. Directs the compiler to generate runtime metadata that will get baked into
     the final binary for use by the runtime linker. Specifically,
     [`cargo:rustc-link-lib`][rustc-link-lib] bakes in dynamic dependency
     metadata into the final binary that tells the linker the names of the
     libraries to load at runtime. The runtime linker will search for these
     libraries in default places like `/usr/lib`, but you can also include
     custom runtime path information in the final binary with the
     [`cargo:rustc-link-arg`][rustc-link-arg] directive; this can make your
     binary more portable, but out example does not make use of it.

[rustc-link-arg]: https://doc.rust-lang.org/cargo/reference/build-scripts.html#rustc-link-arg
[rustc-link-lib]: https://doc.rust-lang.org/cargo/reference/build-scripts.html#rustc-link-lib
[rustc-link-search]: https://doc.rust-lang.org/cargo/reference/build-scripts.html#rustc-link-search
