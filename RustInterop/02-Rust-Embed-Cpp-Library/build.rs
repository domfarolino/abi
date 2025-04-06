fn main() {
    // Adds search paths to the compiler, telling it how to find any libraries
    // referenced, for compile-time symbol resolution.
    println!("cargo:rustc-link-search=native=.");

    // This builds into a dynamic dependency entry for `liblibrary` into the
    // final Rust binary. It is used by the dynamic linker to link the binary
    // with shared libraries it was compiled against, at runtime. See
    // https://doc.rust-lang.org/cargo/reference/build-scripts.html#rustc-link-lib,
    // and the README.md for more.
    //
    // You can view the dynamic dependency information on macOS by running
    // `otool -L path/to/rust_binary`.
    println!("cargo:rustc-link-lib=dylib=library");
}
